#include "stdafx.h"
#include "InputJudg.hpp"

InputJudg::InputJudg()
{
	XINPUT_STATE gamePadState;
	for (int i = 0; i < PADCOUNTMAX; ++i)
	{
		ZeroMemory(&gamePadState, sizeof(XINPUT_STATE));
		DWORD dwResult = XInputGetState(i, &gamePadState);

		if (dwResult == ERROR_SUCCESS)
		{
			gamePadStates.push_back(gamePadState);
			padNumbers.push_back(i);
			padStateNormals.push_back(false);
			lastTimeButtons.push_back(0x0000);
		}
	}
	ShowCursor(false);
}


InputJudg::~InputJudg()
{
}

int InputJudg::GetGamePadState()
{
	XINPUT_STATE gamePadState;
	for (int i = 0; i < padNumbers.size(); ++i)
	{
		ZeroMemory(&gamePadState, sizeof(XINPUT_STATE));

		DWORD dwResult = XInputGetState(padNumbers[i], &gamePadState);

		if (dwResult == ERROR_SUCCESS)
		{
			gamePadStates[i] = gamePadState;
			padStateNormals[i] = true;
		}
		else
		{
			ShowCursor(true);
			gamePadStates[i] = gamePadState;
			padStateNormals[i] = false;
			int id = MessageBox(0, L"コントローラーの接続が切れました。ゲームを終了しますか？", NULL, MB_OKCANCEL | MB_ICONQUESTION);
			switch (id)
			{
				case IDOK:
					MessageBox(0, L"ゲームを終了します。", NULL, MB_ICONEXCLAMATION);
					return 0;

				default:
					ShowCursor(false);
					--i;
			}
		}
	}
	return 1;
}

bool InputJudg::GetButton(const WORD padNum = 0, const int judgButton = 0x00)
{
	bool isButton = false;

	if (padStateNormals[padNum])
	{
		if (gamePadStates[padNum].Gamepad.wButtons & judgButton)
		{
			isButton = true;
		}
	}

	return isButton;
}

bool InputJudg::GetButtonDown(const WORD padNum = 0, const int judgButton = 0x1000)
{
	bool isDownButton = false;
	if (padStateNormals[padNum])
	{
		if (gamePadStates[padNum].Gamepad.wButtons & judgButton)
		{
			if (lastTimeButtons[padNum] != judgButton)
			{
				isDownButton = true;
				lastTimeButtons[padNum] |= judgButton;
			}
		}
		else
		{
			lastTimeButtons[padNum] &= ~judgButton;
		}
	}

	return isDownButton;
}

bool InputJudg::GetButtonUp(const WORD padNum = 0, const int judgButton = 0x00)
{
	bool isUpButton = false;

	if (padStateNormals[padNum])
	{
		if (gamePadStates[padNum].Gamepad.wButtons & judgButton)
		{
			if (lastTimeButtons[padNum] != judgButton)
			{
				lastTimeButtons[padNum] |= judgButton;
			}
		}
		else if (lastTimeButtons[padNum] == judgButton)
		{
			isUpButton = true;
			lastTimeButtons[padNum] &= ~judgButton;
		}
	}

	return isUpButton;
}

bool InputJudg::GetLeftTrigger(const WORD padNum = 0)
{
	bool isTrigger = false;

	if (padStateNormals[padNum])
	{
		if (gamePadStates[padNum].Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		{
			isTrigger = true;
		}
	}

	return isTrigger;
}

bool InputJudg::GetRightTrigger(const WORD padNum = 0)
{
	bool isTrigger = false;

	if (padStateNormals[padNum])
	{
		if (gamePadStates[padNum].Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		{
			isTrigger = true;
		}
	}

	return isTrigger;
}

Vector2 InputJudg::GetLeftAxis(const WORD padNum = 0)
{
	Vector2 input = { 0.0f, 0.0f };

	if (padStateNormals[padNum])
	{
		if (gamePadStates[padNum].Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y += 1.0f;
		}
		if (gamePadStates[padNum].Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y -= 1.0f;
		}

		if (gamePadStates[padNum].Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x += 1.0f;
		}
		if (gamePadStates[padNum].Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x -= 1.0f;
		}
	}

	return input;
}

Vector2 InputJudg::GetRightAxis(const WORD padNum = 0)
{
	Vector2 input = { 0.0f, 0.0f };

	if (padStateNormals[padNum])
	{
		if (gamePadStates[padNum].Gamepad.sThumbRY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y += 1.0f;
		}
		if (gamePadStates[padNum].Gamepad.sThumbRY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.y -= 1.0f;
		}

		if (gamePadStates[padNum].Gamepad.sThumbRX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x += 1.0f;
		}
		if (gamePadStates[padNum].Gamepad.sThumbRX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			input.x -= 1.0f;
		}
	}

	return input;
}