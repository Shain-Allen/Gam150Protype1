//------------------------------------------------------------------------------
//
// File Name: DoorController.cpp
// Author(s): Shain Allen
// Project: Miscellaneous Files
// Course: wanic GP2
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "DoorController.h"
#include "HatSwap.h"

using namespace Beta;

DoorController::DoorController(float Timer, float Open, float MaskReq)
	: Component("DoorController"), Timer(Timer), Open(Open), MaskReq(MaskReq)
{
	Random::Range(1, 3);
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
		Timer = 3;
		Open = 1;
		if (GetSpace()->GetObjectManager().GetObjectByName("Player")->GetComponent<HatSwap>()->MaskOn != MaskReq)
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