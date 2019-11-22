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

using namespace Beta;

DoorController::DoorController(float Timer, float Open, float MaskReq)
	: Component("DoorController"), Timer(Timer), Open(Open), MaskReq(MaskReq)
{
}

void DoorController::Initialize()
{
}

void DoorController::Update(float dt)
{
	Timer -= dt;
	if (AlmostEqual(Timer,3,0.1f))
	{
		//Display Sprite DoorCue
		GetOwner()->GetComponent<Sprite>()->SetAlpha(1);
	}
	DoorOpen();
}

void DoorController::DoorOpen()
{
	if (Timer <= 0)
	{
		//Undisplay Sprite DoorCue
		GetOwner()->GetComponent<Sprite>()->SetAlpha(0);
		Timer = 10;
		Open = 1;
		if (MaskOn != MaskReq)
		{
			GameOver();
		}
	}
}

void DoorController::GameOver()
{
	GetSpace()->RestartLevel();
}

COMPONENT_SUBCLASS_DEFINITION(DoorController);