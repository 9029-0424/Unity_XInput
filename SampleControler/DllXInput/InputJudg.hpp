#ifndef InputJudg_hpp
#define INputJudg_hpp

#define PADCOUNTMAX 4

struct Vector2
{
	float x;
	float y;
};

class InputJudg
{
	vector<XINPUT_STATE> gamePadStates;
	vector<bool> padStateNormals;
	vector<WORD> lastTimeButtons;
	WORD* lastTimeButton;
	vector<int> padNumbers;

public:
	InputJudg();
	~InputJudg();

	int GetGamePadState();

	bool GetButton(const WORD,const int);
	bool GetButtonDown(const WORD, const int);
	bool GetButtonUp(const WORD, const int);

	bool GetLeftTrigger(const WORD);
	bool GetRightTrigger(const WORD);

	Vector2 GetLeftAxis(const WORD);
	Vector2 GetRightAxis(const WORD);
};

#endif /* InputJudg_hpp */