//------------------------------------------------------------------------------
//
// File Name: GameObjecs.cpp
// Author(s): Shain Allen
// Project: BetaHighLevelTemplate
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "GameObjecs.h"

using namespace Beta;

Beta::GameObject* OBJECTS::CreatePlayer()
{
	GameObject* player = new GameObject("Player");

	Transform* transfrom = new Transform(0.0f, 0.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.5f, 0.5f));
	player->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Player"));
	player->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(player);

	return player;
}

Beta::GameObject* OBJECTS::CreateMaskDisplay()
{
	GameObject* MaskDisplay = new GameObject("MaskDisplay");

	Transform* transfrom = new Transform(0.0f, 0.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.8f, 0.5f));
	MaskDisplay->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Masks"));
	MaskDisplay->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(MaskDisplay);	

	return MaskDisplay;
}

Beta::GameObject* OBJECTS::MakeDoor()
{
	GameObject* door = new GameObject("Door");

	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.5, 0.5));
	door->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Door"));
	door->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(door);

	return door;
}

Beta::GameObject* OBJECTS::CreateDoorCue()
{
	GameObject* doorCue = new GameObject("DoorCue");

	Transform* transform = new Transform(0.5f, 0.5f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.5f, 0.0f));
	doorCue->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("DoorCue"));
	doorCue->AddComponent(sprite);

	return doorCue;
}

Beta::GameObject* OBJECTS::CreateNumbers()
{
	GameObject* numbers = new GameObject("Numbers");

	Transform* transform = new Transform(0.5f, 0.5f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.5f, 0.0f));
	numbers->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Numbers"));
	numbers->AddComponent(sprite);

	return numbers;
}

Beta::Archetype OBJECTS::CreateMonster()
{
	GameObject* Monster = new GameObject("Monster");

	Transform* transfrom = new Transform(0.0f, 0.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.5f, 0.5f));
	Monster->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Monsters"));
	Monster->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(Monster);

	return Archetype(Monster);
}
