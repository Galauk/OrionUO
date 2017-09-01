﻿/***********************************************************************************
**
** GLShader.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"
//----------------------------------------------------------------------------------
CGLShader *g_CurrentShader = NULL;
CDeathShader *g_DeathShader = NULL;
CColorizerShader *g_ColorizerShader = NULL;
CColorizerShader *g_FontColorizerShader = NULL;
CColorizerShader *g_LightColorizerShader = NULL;
//----------------------------------------------------------------------------------
void UnuseShader()
{
	WISPFUN_DEBUG("c_uns_sdr");
	glUseProgramObjectARB(0);
	ShaderColorTable = 0;
	g_ShaderDrawMode = 0;
	g_CurrentShader = NULL;
}
//----------------------------------------------------------------------------------
//-----------------------------------CGLShader--------------------------------------
//----------------------------------------------------------------------------------
CGLShader::CGLShader(const char *vertexShaderData, const char *fragmentShaderData)
{
	WISPFUN_DEBUG("c32_f1");
	if (vertexShaderData != NULL && fragmentShaderData != NULL)
	{
		m_Shader = glCreateProgramObjectARB();

		m_VertexShader = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
		glShaderSourceARB(m_VertexShader, 1, (const GLcharARB**)&vertexShaderData, NULL);
		glCompileShaderARB(m_VertexShader);
		glAttachObjectARB(m_Shader, m_VertexShader);

		m_FragmentShader = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
		glShaderSourceARB(m_FragmentShader, 1, (const GLcharARB**)&fragmentShaderData, NULL);
		glCompileShaderARB(m_FragmentShader);
		glAttachObjectARB(m_Shader, m_FragmentShader);

		glLinkProgramARB(m_Shader);
		glValidateProgramARB(m_Shader);
	}
}
//----------------------------------------------------------------------------------
CGLShader::~CGLShader()
{
	WISPFUN_DEBUG("c32_f2");
	if (m_Shader != 0)
	{
		glDeleteObjectARB(m_Shader);
		m_Shader = 0;
	}

	if (m_VertexShader != 0)
	{
		glDeleteObjectARB(m_VertexShader);
		m_VertexShader = 0;
	}

	if (m_FragmentShader != 0)
	{
		glDeleteObjectARB(m_FragmentShader);
		m_FragmentShader = 0;
	}

	m_TexturePointer = 0;
}
//----------------------------------------------------------------------------------
bool CGLShader::Use()
{
	WISPFUN_DEBUG("c32_f3");
	CGLShader *oldShader = g_CurrentShader;
	UnuseShader();
	g_CurrentShader = oldShader;

	bool result = false;

	if (m_Shader != 0)
	{
		glUseProgramObjectARB(m_Shader);
		result = true;
	}

	return result;
}
//----------------------------------------------------------------------------------
void CGLShader::Pause()
{
	WISPFUN_DEBUG("c32_f4");
	glUseProgramObjectARB(0);
}
//----------------------------------------------------------------------------------
void CGLShader::Resume()
{
	WISPFUN_DEBUG("c32_f5");
	glUseProgramObjectARB(m_Shader);
}
//----------------------------------------------------------------------------------
//-----------------------------------CDeathShader-----------------------------------
//----------------------------------------------------------------------------------
CDeathShader::CDeathShader(const char *vertexShaderData, const char *fragmentShaderData)
: CGLShader(vertexShaderData, fragmentShaderData)
{
	WISPFUN_DEBUG("c33_f1");
	if (m_Shader != 0)
		m_TexturePointer = glGetUniformLocationARB(m_Shader, "usedTexture");
	else
		LOG("Failed to create DeathShader\n");
}
//----------------------------------------------------------------------------------
//----------------------------------CColorizerShader--------------------------------
//----------------------------------------------------------------------------------
CColorizerShader::CColorizerShader(const char *vertexShaderData, const char *fragmentShaderData)
: CGLShader(vertexShaderData, fragmentShaderData)
{
	WISPFUN_DEBUG("c34_f1");
	if (m_Shader != 0)
	{
		m_TexturePointer = glGetUniformLocationARB(m_Shader, "usedTexture");
		m_ColorTablePointer = glGetUniformLocationARB(m_Shader, "colors");
		m_DrawModePointer = glGetUniformLocationARB(m_Shader, "drawMode");
	}
	else
		LOG("Failed to create ColorizerShader\n");
}
//----------------------------------------------------------------------------------
bool CColorizerShader::Use()
{
	WISPFUN_DEBUG("c34_f2");
	bool result = CGLShader::Use();

	if (result)
	{
		ShaderColorTable = m_ColorTablePointer;
		g_ShaderDrawMode = m_DrawModePointer;
		glUniform1iARB(g_ShaderDrawMode, 0);
	}

	return result;
}
//----------------------------------------------------------------------------------
