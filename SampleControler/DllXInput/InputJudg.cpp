#include "stdafx.h"
#include "InputJudg.hpp"

InputJudg::InputJudg()
{
}


InputJudg::~InputJudg()
{
}

int InputJudg::GetGamePadState(const DWORD padNum = 0)
{
	ZeroMemory(&gamePadState, sizeof(XINPUT_STATE));

	DWORD dwResult = XInputGetState(padNum, &gamePadState);

	if (dwResult == ERROR_SUCCESS)
	{
		padStateNormal = true;
		lastTimeButton = &lastTimeButtons[padNum];
		return 1;
	}
	else
	{
		padStateNormal = false;
		return 2;
	}
}

bool InputJudg::GetButton(const int judgButton = 0x00)
{
	bool isButton = false;

	if (padStateNormal)
	{
		if (gamePadState.Gamepad.wButtons & judgButton)
		{
			isButton = true;
		}
	}

	return isButton;
}

bool InputJudg::GetButtonDown(const int judgButton = 0x1000)
{
	bool isDownButton = false;
	if (padStateNormal)
	{
		if (gamePadState.Gamepad.wButtons & judgButton)
		{
			if (*lastTimeButton != judgButton)
			{
				isDownButton = true;
				*lastTimeButton = judgButton;
			}
		}
		else
		{
			*lastTimeButton = 0x00;
		}
	}

	return isDownButton;
}

bool InputJudg::GetButtonUp(const int judgButton = 0x00)
{
	bool isUpButton = false;

	if (padStateNormal)
	{
		if (gamePadState.Gamepad.wButtons & judgButton)
		{
			if (*lastTimeButton != judgButton)
			{
				*lastTimeButton = judgButton;
			}
		}
		else if(*lastTimeButton == judgButton)
		{
			isUpButton = true;
			*lastTimeButton = 0x00;
		}
	}

	return isUpButton;
}

bool InputJudg::GetLeftTrigger()
{
	bool isTrigger = false;

	if (padStateNormal)
	{
		if (gamePadState.Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		{
			isTrigger = true;
		}
	}

	return isTrigger;
}

bool InputJudg::GetRightTrigger()
{
	bool isTrigger = false;

	if (padStateNormal)
	{
		if (gamePadState.Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		{
			isTrigger = true;
		}
	}

	return isTrigger;
}

Vector2 InputJudg::GetLeftAxis()
{
	Vector2 input = { 0.0f, 0.0f };

	if (padStateNormal)
	{
		if (gamePadState.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y += 1.0f;
		}
		else if (gamePadState.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y -= 1.0f;
		}

		if (gamePadState.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x += 1.0f;
		}
		else if (gamePadState.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x -= 1.0f;
		}
	}

	return input;
}

Vector2 InputJudg::GetRightAxis()
{
	Vector2 input = { 0.0f, 0.0f };

	if (padStateNormal)
	{
		if (gamePadState.Gamepad.sThumbRY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y += 1.0f;
		}
		else if (gamePadState.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y -= 1.0f;
		}

		if (gamePadState.Gamepad.sThumbRX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x += 1.0f;
		}
		else if (gamePadState.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x -= 1.0f;
		}
	}

	return input;
}