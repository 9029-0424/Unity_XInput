#include "stdafx.h"
#include "InputInterface.hpp"

InputJudg* _stdcall InputJudg_Create()
{
	return new InputJudg();
}

void _stdcall InputJudg_Destroy(InputJudg* instance)
{
	if (instance == nullptr)	return;

	delete instance;
	instance = nullptr;
	return;
}

int _stdcall InputJudg_GetGamePadState(InputJudg* instance, const DWORD padNum = 0)
{
	if (instance == nullptr)	0;

	return	instance->GetGamePadState(padNum);
}

bool _stdcall InputJudg_GetButton(InputJudg* instance, const int judgButton = 0x00)
{
	if (instance == nullptr)	return false;

	return instance->GetButton(judgButton);
}

bool _stdcall InputJudg_GetButtonDown(InputJudg* instance, const int judgButton = 0x00)
{
	if (instance == nullptr)	return false;

	return instance->GetButtonDown(judgButton);
}

bool _stdcall InputJudg_GetButtonUp(InputJudg* instance, const int judgButton = 0x00)
{
	if (instance == nullptr)	return false;

	return instance->GetButtonUp(judgButton);
}

bool _stdcall InputJudg_GetLeftTrigger(InputJudg* instance)
{
	if (instance == nullptr)	return false;

	instance->GetLeftTrigger();
}

bool _stdcall InputJudg_GetRightTrigger(InputJudg* instance)
{
	if (instance == nullptr)	return false;

	instance->GetRightTrigger();
}

Vector2 _stdcall InputJudg_GetLeftAxis(InputJudg* instance)
{
	if (instance == nullptr)	return Vector2{ 0.0f, 0.0f };

	return instance->GetLeftAxis();
}

Vector2 _stdcall InputJudg_GetRightAxis(InputJudg* instance)
{
	if (instance == nullptr)	return Vector2{ 0.0f, 0.0f };

	return instance->GetRightAxis();
}