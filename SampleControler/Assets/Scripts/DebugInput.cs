using UnityEngine;
using UnityEngine.UI;

public class DebugInput : MonoBehaviour
{
    private InputControler input = null;
    public Text[] inputScore = new Text[4];

    // Start is called before the first frame update
    void Start()
    {
        input = new InputControler();
    }

    // Update is called once per frame
    void Update()
    {
        for (int i = 0; i < 4; ++i)
        {
            input.GetGamePadState(i);

            inputScore[i].text = "\n\n";

            if (input.GetButton(Code.pad_A)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_B)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FLASE\n\n";

            if (input.GetButton(Code.pad_X)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_Y)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_LB)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_RB)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetLeftTrigger()) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetRightTrigger()) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_Back)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_Start)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_LStick)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            if (input.GetButton(Code.pad_RStick)) inputScore[i].text += "  TRUE\n\n";
            else inputScore[i].text += "FALSE\n\n";

            Vector2 inputAxis = input.GetLeftAxis();

            inputScore[i].text += inputAxis.x + "\n\n";
            inputScore[i].text += inputAxis.y + "\n\n";

            inputAxis = input.GetRightAxis();

            inputScore[i].text += inputAxis.x + "\n\n";
            inputScore[i].text += inputAxis.y + "\n\n";

            if(input.GetButton(Code.pad_Dpad_Up))
            {
                if (input.GetButton(Code.pad_Dpad_Down)) inputScore[i].text += 0 + "\n\n";
                else inputScore[i].text += 1 + "\n\n";
            }
            else if (input.GetButton(Code.pad_Dpad_Down)) inputScore[i].text += -1 + "\n\n";
            else inputScore[i].text += 0 + "\n\n";

            if (input.GetButton(Code.pad_Dpad_Right))
            {
                if (input.GetButton(Code.pad_Dpad_Left)) inputScore[i].text += 0 + "\n\n";
                else inputScore[i].text += 1 + "\n\n";
            }
            else if (input.GetButton(Code.pad_Dpad_Left)) inputScore[i].text += -1 + "\n\n";
            else inputScore[i].text += 0 + "\n\n";
        }
    }
}