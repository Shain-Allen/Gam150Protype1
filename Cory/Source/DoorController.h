//------------------------------------------------------------------------------
//
// File Name:	DoorController.h
// Author(s):	Cory Carlson
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

#include "Component.h"

class DoorController : public Beta::Component
{
public:
	DoorController(float Timer = 30, float Open = 0, float MaskOn = 0, float MaskReq = 1);

	void Initialize() override;
private:

	float Timer;
	float Open;
	float MaskOn;
	float MaskReq;
}