#include <windows.h>
#include <Xinput.h>
#include <map>
#include <iostream>

#pragma comment(lib, "XInput.lib")

const std::map<WORD, const char*> buttons = {
    { XINPUT_GAMEPAD_A, "A" },
    { XINPUT_GAMEPAD_B, "B" },
    { XINPUT_GAMEPAD_X, "X" },
    { XINPUT_GAMEPAD_Y, "Y" },
    { XINPUT_GAMEPAD_DPAD_UP, "D-pad Up" },
    { XINPUT_GAMEPAD_DPAD_DOWN, "D-pad Down" },
    { XINPUT_GAMEPAD_DPAD_LEFT, "D-pad Left" },
    { XINPUT_GAMEPAD_DPAD_RIGHT, "D-pad Right" },
    { XINPUT_GAMEPAD_LEFT_SHOULDER, "LB" },
    { XINPUT_GAMEPAD_RIGHT_SHOULDER, "RB" },
    { XINPUT_GAMEPAD_START, "Start" },
    { XINPUT_GAMEPAD_BACK, "Back" },
    { XINPUT_GAMEPAD_LEFT_THUMB, "Left Thumb Button" },
    { XINPUT_GAMEPAD_RIGHT_THUMB, "Right Thumb Button" }
};

int main() {
    while (true) {
        XINPUT_STATE state;
        ZeroMemory(&state, sizeof(XINPUT_STATE));
        XInputGetState(0, &state);
        for (const auto& button : buttons) {
            if (state.Gamepad.wButtons & button.first) {
                std::cout << button.second << " pressed" << std::endl;
            }
        }
        if (state.Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) {
            std::cout << "L2/LT pressed" << std::endl;
        }
        if (state.Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) {
            std::cout << "R2/RT pressed" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
