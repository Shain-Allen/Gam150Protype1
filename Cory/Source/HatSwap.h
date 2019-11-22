//------------------------------------------------------------------------------
//
// File Name:	HatSwap.h
// Author(s):	Cory Carlson
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once

#include "Component.h"

namespace Beta 
{
	class GameObject;
}

class HatSwap : public Beta::Component
{
public:
	HatSwap(float MaskOn = 0);

	void Initialize() override;

	void Update(float dt) override;

	float MaskOn;

private:

	Beta::GameObject* player;
	
	COMPONENT_SUBCLASS_DECLARATION(HatSwap);
};