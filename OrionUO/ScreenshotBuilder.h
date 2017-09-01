﻿/***********************************************************************************
**
** ScreenshotBuilder.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef SCREENSHOTBUILDER_H
#define SCREENSHOTBUILDER_H
//----------------------------------------------------------------------------------
class CScreenshotBuilder
{
public:
	CScreenshotBuilder();
	virtual ~CScreenshotBuilder();

	void SaveScreen();

	void SaveScreen(const int &x, const int &y, const int &width, const int &height);

	UINT_LIST GetScenePixels(const int &x, const int &y, const int &width, const int &height);
};
//----------------------------------------------------------------------------------
extern CScreenshotBuilder g_ScreenshotBuilder;
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
