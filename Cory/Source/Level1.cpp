//------------------------------------------------------------------------------
//
// File Name:	Level1.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"
#include "DoorController.h"
#include "GameObjecs.h"

//------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Creates an instance of Level 1.
Level1::Level1()
	: Level("Level 1"), testObject(nullptr)
{
}

void Level1::Load()
{
	doorCueSprite = ResourceGetSpriteSource("DoorCue");
	playerSprite = ResourceGetSpriteSource("Player");
}

// Initialize the memory associated with the Level1 game state.
void Level1::Initialize()
{
	std::cout << "Level1: Initialize" << std::endl;

	// Create a new game object
	testObject = new GameObject("TestObject");

	// Create a transform component at 0,0 with scale 300,300
	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(1.0f, 0.5f));
	testObject->AddComponent(transform);

	// Create a sprite component and set its mesh and sprite source
	Sprite* sprite = new Sprite();
	sprite->SetSpriteSource(doorCueSprite);
	sprite->SetAlpha(0);
	testObject->AddComponent(sprite);
	testObject->AddComponent(new DoorController());

	//GameObject* door = Archtypes::MakeDoor();

	// Add object to object manager
	GetSpace()->GetObjectManager().AddObject(*testObject);
	//
	testObject = new GameObject("TestObject");

	// Create a transform component at 0,0 with scale 300,300
	transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(1.0f, 0.5f));
	testObject->AddComponent(transform);

	// Create a sprite component and set its mesh and sprite source
	sprite = new Sprite();
	sprite->SetSpriteSource(playerSprite);
	sprite->SetAlpha(0);
	testObject->AddComponent(sprite);
	testObject->AddComponent(new DoorController());

	//GameObject* door = Archtypes::MakeDoor();

	// Add object to object manager
	GetSpace()->GetObjectManager().AddObject(*testObject);
}

// Update the Level1 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	Input* input = EngineGetModule(Input);

	// If the user presses the '1' key, restart the current level
	if (input->CheckTriggered('1'))
		GetSpace()->RestartLevel();

	// If the user presses the 'D' key, delete the object
	if (testObject != nullptr && input->CheckTriggered('D'))
	{
		testObject->Destroy();
		testObject = nullptr;
	}
}

// Shutdown any memory associated with the Level1 game state.
void Level1::Shutdown()
{
	std::cout << "Level1::Shutdown" << std::endl;
}
