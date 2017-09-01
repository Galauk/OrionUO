﻿/***********************************************************************************
**
** GameEffectDrag.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GAMEEFFECTDRAG_H
#define GAMEEFFECTDRAG_H
//----------------------------------------------------------------------------------
//Эффект перемещения предмета
class CGameEffectDrag : public CGameEffect
{
	SETGET(int, OffsetX, 0);
	SETGET(int, OffsetY, 0);

	SETGET(uint, LastMoveTime, 0);
	SETGET(uchar, MoveDelay, 20);

public:
	CGameEffectDrag();
	virtual ~CGameEffectDrag();

	/*!
	Обновить эффект
	@return
	*/
	virtual void Update(class CGameObject *parent);
};
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
