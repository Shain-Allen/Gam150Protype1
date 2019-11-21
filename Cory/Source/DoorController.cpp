//------------------------------------------------------------------------------
//
// File Name:	DoorController.cpp
// Author(s):	Cory Carlson
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "DoorController.h"

DoorController::DoorController(float Timer, float Open, float MaskOn, float MaskReq)
	: Component("DoorController"), Timer(Timer), Open(Open), MaskOn(MaskOn), MaskReq(MaskReq)
{
}

void DoorController::Initialize()
{
}

DoorOpen()
{
	if (Timer <= 0)
	{
		Timer = 30;
		Open = 1;
		if (MaskOn != MaskReq)
		{
			GameOver();
		}
	}
}

GameOver()
{
	GetSpace()->RestartLevel();
}