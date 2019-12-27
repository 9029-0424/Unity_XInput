#ifndef InputJudg_hpp
#define INputJudg_hpp

struct Vector2
{
	float x;
	float y;
};

class InputJudg
{
	XINPUT_STATE gamePadState;
	bool padStateNormal = false;
	int lastTimeButtons[4] = {0x00, 0x00, 0x00, 0x00};
	int* lastTimeButton = &lastTimeButtons[0];

public:
	InputJudg();
	~InputJudg();

	int GetGamePadState(const DWORD);

	bool GetButton(const int);
	bool GetButtonDown(const int);
	bool GetButtonUp(const int);

	bool GetLeftTrigger();
	bool GetRightTrigger();

	Vector2 GetLeftAxis();
	Vector2 GetRightAxis();
};

#endif /* InputJudg_hpp */