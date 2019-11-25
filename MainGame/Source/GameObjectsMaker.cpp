//------------------------------------------------------------------------------
//
// File Name: GameObjectsMaker.cpp
// Author(s): Shain Allen
// Project: Miscellaneous Files
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "GameObjectsMaker.h"
#include "DoorController.h"
#include "HatSwap.h"

using namespace Beta;

Beta::GameObject* Objects::CreatePlayer()
{
	GameObject* player = new GameObject("Player");

	Transform* transfrom = new Transform(-1.0f, 0.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.5f, 0.8f));
	player->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Player"));
	player->AddComponent(sprite);
	player->AddComponent(new HatSwap);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(player);

	return player;
}

Beta::GameObject* Objects::CreateMaskDisplay()
{
	GameObject* MaskDisplay = new GameObject("MaskDisplay");

	Transform* transfrom = new Transform(-1.0f, 1.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.8f, 0.5f));
	MaskDisplay->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Masks"));
	MaskDisplay->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(MaskDisplay);	

	return MaskDisplay;
}

Beta::GameObject* Objects::CreateDoor()
{
	GameObject* door = new GameObject("Door");

	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.2f, 1.0f));
	door->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Door"));
	door->AddComponent(sprite);
	
	DoorController* doorController = new DoorController;
	door->AddComponent(doorController);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(door);

	return door;
}

Beta::GameObject* Objects::CreateDoorCue()
{
	GameObject* doorCue = new GameObject("DoorCue");

	Transform* transform = new Transform(0.5f, 0.5f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.5f, 0.5f));
	doorCue->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("DoorCue"));
	doorCue->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(doorCue);

	return doorCue;
}

Beta::GameObject* Objects::CreateNumbers()
{
	GameObject* numbers = new GameObject("Numbers");

	Transform* transform = new Transform(0.5f, 0.5f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.15f, 0.15f));
	numbers->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Numbers"));
	numbers->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(numbers);

	return numbers;
}

Beta::Archetype Objects::CreateMonster()
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
