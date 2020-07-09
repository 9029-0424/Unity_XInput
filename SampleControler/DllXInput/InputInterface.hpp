#ifndef InputInterface_hpp
#define InputInterface_hpp

#include "InputJudg.hpp"

extern "C"
{
	InputJudg* _stdcall InputJudg_Create();

	void _stdcall InputJudg_Destroy(InputJudg*);

	int _stdcall InputJudg_GetGamePadState(InputJudg*);

	bool _stdcall InputJudg_GetButton(InputJudg*, const DWORD, const int);
	bool _stdcall InputJudg_GetButtonDown(InputJudg*, const DWORD, const  int);
	bool _stdcall InputJudg_GetButtonUp(InputJudg*, const DWORD, const int);

	bool _stdcall InputJudg_GetLeftTrigger(InputJudg*, const DWORD);
	bool _stdcall InputJudg_GetRightTrigger(InputJudg*, const DWORD);

	Vector2 _stdcall InputJudg_GetLeftAxis(InputJudg*, const DWORD);
	Vector2 _stdcall InputJudg_GetRightAxis(InputJudg*, const DWORD);
}

#endif /* InpurInterface_hpp */