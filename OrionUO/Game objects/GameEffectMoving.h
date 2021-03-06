﻿/***********************************************************************************
**
** GameEffectMoving.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GAMEEFFECTMOVING_H
#define GAMEEFFECTMOVING_H
//----------------------------------------------------------------------------------
//Движущийся эффект
class CGameEffectMoving : public CGameEffectDrag
{
	//!Угол поворота эффекта
	SETGET(float, Angle, 0.0f);
	SETGET(int, OffsetZ, 0);

public:
	CGameEffectMoving();
	virtual ~CGameEffectMoving();

	/*!
	Обновить эффект
	@return
	*/
	virtual void Update(class CGameObject *parent);
};
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
