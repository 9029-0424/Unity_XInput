using System;
using System.Runtime.InteropServices;
using UnityEngine;

// --------------------------------------------
// GamePadのKeyCode指定用クラス
// --------------------------------------------
static class Code
{
    public const int pad_Dpad_Up = 0x0001;
    public const int pad_Dpad_Down = 0x0002;
    public const int pad_Dpad_Left = 0x0004;
    public const int pad_Dpad_Right = 0x0008;
    public const int pad_Start = 0x0010;
    public const int pad_Back = 0x0020;
    public const int pad_A = 0x1000;
    public const int pad_B = 0x2000;
    public const int pad_X = 0x4000;
    public const int pad_Y = 0x8000;
    public const int pad_LB = 0x0100;
    public const int pad_RB = 0x0200;
    public const int pad_LStick = 0x0040;
    public const int pad_RStick = 0x0080;
};

// --------------------------------------------
// 外部のInputを使ってコントローラーの入力を判定する
// --------------------------------------------
public class InputControler
{
    private IntPtr _instance;

    [DllImport("DllXInput", EntryPoint = "InputJudg_Create")]
    private static extern IntPtr _Create();

    [DllImport("DllXInput", EntryPoint = "InputJudg_Destroy")]
    private static extern void _Destroy(IntPtr instance);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetGamePadState")]
    private static extern int _GetGamePadState(IntPtr instance, long padNum = 0);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetButton")]
    private static extern bool _GetButton(IntPtr instance, int judgButton = 0x00);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetButtonDown")]
    private static extern bool _GetButtonDown(IntPtr instance, int judgButton = 0x1000);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetButtonUp")]
    private static extern bool _GetButtonUp(IntPtr instance, int judgButton = 0x00);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetLeftTrigger")]
    private static extern bool _GetLeftTrigger(IntPtr instance);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetRightTrigger")]
    private static extern bool _GetRightTrigger(IntPtr instance);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetLeftAxis")]
    private static extern Vector2 _GetLeftAxis(IntPtr instance);

    [DllImport("DllXInput", EntryPoint = "InputJudg_GetRightAxis")]
    private static extern Vector2 _GetRightAxis(IntPtr instance);

    // 外部クラスの作成
    public InputControler()
    {
        _instance = _Create();
        if (!IsDestroyed()) Debug.Log("作成完了");
    }

    // 外部クラスの解放
    private bool IsDestroyed()
    {
        return _instance == IntPtr.Zero;
    }

    // デストラクタ（外部クラスの解放）
    ~InputControler()
    {
        if (IsDestroyed())
        {
            return;
        }

        _Destroy(_instance);
        _instance = IntPtr.Zero;
    }

    // コントローラーの状態を取得
    public int GetGamePadState(long padNum = 0)
    {
        if (IsDestroyed())
        {
            return 0;
        }

        if (1 != _GetGamePadState(_instance, padNum)) return 0;

        return 1;
    }

    // 指定したボタンが押されているかの判定
    public bool GetButton(int judgButton = 0x1000)
    {
        if (IsDestroyed())
        {
            return false;
        }

        return _GetButton(_instance, judgButton);
    }

    // 指定したボタンが押されたかの判定
    public bool GetButtonDown(int judgButton = 0x1000)
    {
        if (IsDestroyed())
        {
            return false;
        }

        return _GetButtonDown(_instance, judgButton);
    }

    // 指定したボタンが放されたかの判定
    public bool GetButtonUp(int judgButton = 0x1000)
    {
        if (IsDestroyed())
        {
            return false;
        }

        return _GetButtonUp(_instance, judgButton);
    }

    // 左トリガーの判定
    public bool GetLeftTrigger()
    {
        if (IsDestroyed())
        {
            return false;
        }

        return _GetLeftTrigger(_instance);
    }

    // 右トリガーの判定
    public bool GetRightTrigger()
    {
        if (IsDestroyed())
        {
            return false;
        }

        return _GetRightTrigger(_instance);
    }

    // 左スティックの判定
    public Vector2 GetLeftAxis()
    {
        if (IsDestroyed())
        {
            return new Vector2(0.0f, 0.0f);
        }

        return _GetLeftAxis(_instance);
    }

    // 右スティックの判定
    public Vector2 GetRightAxis()
    {
        if (IsDestroyed())
        {
            return new Vector2(0.0f, 0.0f);
        }

        return _GetRightAxis(_instance);
    }
}