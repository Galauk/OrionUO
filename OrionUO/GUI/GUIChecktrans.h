﻿/***********************************************************************************
**
** GUIChecktrans.h
**
** Компонента применения трафарета на указанную зону
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GUICHECKTRANS_H
#define GUICHECKTRANS_H
//----------------------------------------------------------------------------------
class CGUIChecktrans : public CGUIPolygonal
{
public:
	CGUIChecktrans(const int &x, const int &y, const int &width, const int &height);
	virtual ~CGUIChecktrans();

	virtual void Draw(const bool &checktrans = false);
	virtual bool Select() { return false; }
};
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
