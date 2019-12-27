#ifndef InputInterface_hpp
#define InputInterface_hpp

#include "InputJudg.hpp"

extern "C"
{
	InputJudg* _stdcall InputJudg_Create();

	void _stdcall InputJudg_Destroy(InputJudg*);

	int _stdcall InputJudg_GetGamePadState(InputJudg*, const DWORD);

	bool _stdcall InputJudg_GetButton(InputJudg*, const int);
	bool _stdcall InputJudg_GetButtonDown(InputJudg*, const  int);
	bool _stdcall InputJudg_GetButtonUp(InputJudg*, const int);

	bool _stdcall InputJudg_GetLeftTrigger(InputJudg*);
	bool _stdcall InputJudg_GetRightTrigger(InputJudg*);

	Vector2 _stdcall InputJudg_GetLeftAxis(InputJudg*);
	Vector2 _stdcall InputJudg_GetRightAxis(InputJudg*);
}

#endif /* InpurInterface_hpp */