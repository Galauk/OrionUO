﻿/***********************************************************************************
**
** OrionApplication.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef ORIONAPPLICATION_H
#define ORIONAPPLICATION_H
//----------------------------------------------------------------------------------
class COrionApplication : public WISP_APPLICATION::CApplication
{
protected:
	virtual void OnIDLELoop();

public:
	COrionApplication() : WISP_APPLICATION::CApplication() {}
	virtual ~COrionApplication() {}
};
//----------------------------------------------------------------------------------
extern COrionApplication g_App;
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
