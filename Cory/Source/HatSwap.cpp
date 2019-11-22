#include "stdafx.h"
#include "HatSwap.h"

using namespace Beta;

HatSwap::HatSwap(float MaskOn)
	: Component("HatSwap"), MaskOn(MaskOn)
{
}

void HatSwap::Initialize()
{
}

void HatSwap::Update(float dt)
{
	Input* input = EngineGetModule(Input);

	if (input->CheckTriggered('1'))
		MaskOn = 1;
	if (input->CheckTriggered('2'))
		MaskOn = 2;
	if (input->CheckTriggered('3'))
		MaskOn = 3;
	//Change Player Subimage to Mask On

}
