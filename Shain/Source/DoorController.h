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
	DoorController(float Timer = 6, float Open = 0, float MaskReq = 1);

	void Initialize() override;

	void Update(float dt) override;

	void DoorOpen();

	void GameOver();

	float MaskReq;

private:

	float Timer;
	float Open;
	int Death;

	COMPONENT_SUBCLASS_DECLARATION(DoorController);
};