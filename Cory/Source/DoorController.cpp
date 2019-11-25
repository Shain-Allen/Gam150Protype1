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
#include "HatSwap.h"

using namespace Beta;

DoorController::DoorController(float Timer, float Open, float MaskReq_)
	: Component("DoorController"), Timer(Timer), Open(Open), MaskReq(MaskReq_)
{
	MaskReq = Random::Range(0, 2);
}

void DoorController::Initialize()
{
}

void DoorController::Update(float dt)
{
	Timer -= dt;
	if (AlmostEqual(Timer, 6, 0.1f))
	{
		GetOwner()->GetComponent<Sprite>()->SetAlpha(1);
	}
	if (AlmostEqual(Timer,4,0.1f))
	{
		//Display Sprite DoorCue
		GetSpace()->GetObjectManager().GetObjectByName("DoorCue")->GetComponent<Sprite>()->SetAlpha(1);
	}
	DoorOpen();
}

void DoorController::DoorOpen()
{

	if (AlmostEqual(Timer, 2, 0.1f))
	{
		//Undisplay Sprite DoorCue
		GetSpace()->GetObjectManager().GetObjectByName("DoorCue")->GetComponent<Sprite>()->SetAlpha(0);

		GetOwner()->GetComponent<Sprite>()->SetAlpha(0);
		
		//Open = 1;
		if (GetSpace()->GetObjectManager().GetObjectByName("Player")->GetComponent<HatSwap>()->MaskOn != MaskReq+1)
		{
			GetSpace()->GetObjectManager().GetObjectByName("Player")->GetComponent<Sprite>()->SetColor(Colors::Red);
			Death = 1;
		}
	}
	if (AlmostEqual(Timer, 0, 0.1f))
	{
		MaskReq = Random::Range(0, 2);
		
		GameObject* monster = GetSpace()->GetObjectManager().GetObjectByName("Monster");
		monster->GetComponent<Sprite>()->SetFrame(MaskReq);

		Timer = 6;
		if (Death == 1)
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