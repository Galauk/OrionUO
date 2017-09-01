﻿/***********************************************************************************
**
** PartyObject.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"
//----------------------------------------------------------------------------------
CPartyObject::CPartyObject()
{
}
//----------------------------------------------------------------------------------
string CPartyObject::GetName(const int &index)
{
	WISPFUN_DEBUG("c197_f1");
	if (m_Serial)
	{
		if (Character == NULL)
			Character = g_World->FindWorldCharacter(m_Serial);
		if (Character != NULL)
			return Character->Name;
	}

	char buf[10] = {0};
	sprintf_s(buf, "[%i]", index);

	return string(buf);
}
//----------------------------------------------------------------------------------
