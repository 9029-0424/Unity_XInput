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

int _stdcall InputJudg_GetGamePadState(InputJudg* instance)
{
	if (instance == nullptr)	0;

	return	instance->GetGamePadState();
}

bool _stdcall InputJudg_GetButton(InputJudg* instance, const DWORD padNum = 0, const int judgButton = 0x00)
{
	if (instance == nullptr)	return false;

	return instance->GetButton(padNum, judgButton);
}

bool _stdcall InputJudg_GetButtonDown(InputJudg* instance, const DWORD padNum = 0, const int judgButton = 0x00)
{
	if (instance == nullptr)	return false;

	return instance->GetButtonDown(padNum, judgButton);
}

bool _stdcall InputJudg_GetButtonUp(InputJudg* instance, const DWORD padNum = 0, const int judgButton = 0x00)
{
	if (instance == nullptr)	return false;

	return instance->GetButtonUp(padNum, judgButton);
}

bool _stdcall InputJudg_GetLeftTrigger(InputJudg* instance, const DWORD padNum = 0)
{
	if (instance == nullptr)	return false;

	return instance->GetLeftTrigger(padNum);
}

bool _stdcall InputJudg_GetRightTrigger(InputJudg* instance, const DWORD padNum = 0)
{
	if (instance == nullptr)	return false;

	return instance->GetRightTrigger(padNum);
}

Vector2 _stdcall InputJudg_GetLeftAxis(InputJudg* instance, const DWORD padNum = 0)
{
	if (instance == nullptr)	return Vector2{ 0.0f, 0.0f };

	return instance->GetLeftAxis(padNum);
}

Vector2 _stdcall InputJudg_GetRightAxis(InputJudg* instance, const DWORD padNum = 0)
{
	if (instance == nullptr)	return Vector2{ 0.0f, 0.0f };

	return instance->GetRightAxis(padNum);
}