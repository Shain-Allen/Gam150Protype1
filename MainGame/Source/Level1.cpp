//------------------------------------------------------------------------------
//
// File Name:	Level1.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"
#include "GameObjectsMaker.h"

//------------------------------------------------------------------------------

using namespace Beta;
using std::cout;
using std::endl;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Creates an instance of Level 1.
Level1::Level1()
	: Level("Level 1"), player(nullptr), maskDisplay(nullptr), door(nullptr), number1(nullptr), number2(nullptr), number3(nullptr), enemy(nullptr), doorCue(nullptr)
{
}

void Level1::Load()
{
	cout << "level 1::load" << endl;

	//get graphics engine
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);

	graphics.SetBackgroundColor(Colors::Black);
}

// Initialize the memory associated with the Level1 game state.
void Level1::Initialize()
{
	std::cout << "Level1: Initialize" << std::endl;

	player = Objects::CreatePlayer();
	maskDisplay = Objects::CreateMaskDisplay();
	door = Objects::CreateDoor();
	number1 = Objects::CreateNumbers();
	number1->GetComponent<Transform>()->SetTranslation(Vector2D(-1.3f, 0.6f));
	number2 = Objects::CreateNumbers();
	number2->GetComponent<Transform>()->SetTranslation(Vector2D(-1.03f, 0.6f));
	number2->GetComponent<Sprite>()->SetFrame(1);
	number3 = Objects::CreateNumbers();
	number3->GetComponent<Transform>()->SetTranslation(Vector2D(-0.75f, 0.6f));
	number3->GetComponent<Sprite>()->SetFrame(2);


	GetSpace()->GetObjectManager().AddObject(*player);
	GetSpace()->GetObjectManager().AddObject(*maskDisplay);
	GetSpace()->GetObjectManager().AddObject(*door);
	GetSpace()->GetObjectManager().AddObject(*number1);
	GetSpace()->GetObjectManager().AddObject(*number2);
	GetSpace()->GetObjectManager().AddObject(*number3);
}

// Update the Level1 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
}

// Shutdown any memory associated with the Level1 game state.
void Level1::Shutdown()
{
	std::cout << "Level1::Shutdown" << std::endl;
}
