// xboxTEST.cpp : Defines the entry point for the console application.
//



//#include "CXBOXController.h"
#include <iostream>
#include <exception>
#include <time.h>
#include <ctime>
#include <stdlib.h> 


using namespace std;


CXBOXController::CXBOXController(int playerNumber)
{
	// Set the Controller Number
	_controllerNum = playerNumber - 1;
}

XINPUT_STATE CXBOXController::GetState()
{
	// Zeroise the state
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

	// Get the state
	XInputGetState(_controllerNum, &_controllerState);

	return _controllerState;
}

bool CXBOXController::IsConnected()
{
	// Zeroise the state
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

	// Get the state
	DWORD Result = XInputGetState(_controllerNum, &_controllerState);

	if (Result == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}



void CXBOXController::Vibrate(int leftVal, int rightVal)
{
	// Create a Vibraton State
	XINPUT_VIBRATION Vibration;

	// Zeroise the Vibration
	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

	// Set the Vibration Values
	Vibration.wLeftMotorSpeed = leftVal;
	Vibration.wRightMotorSpeed = rightVal;

	// Vibrate the controller
	XInputSetState(_controllerNum, &Vibration);
}

//#define XINPUT_GAMEPAD_DPAD_UP          0x0001
//#define XINPUT_GAMEPAD_DPAD_DOWN        0x0002
//#define XINPUT_GAMEPAD_DPAD_LEFT        0x0004
//#define XINPUT_GAMEPAD_DPAD_RIGHT       0x0008
//#define XINPUT_GAMEPAD_START            0x0010
//#define XINPUT_GAMEPAD_BACK             0x0020
//#define XINPUT_GAMEPAD_LEFT_THUMB       0x0040
//#define XINPUT_GAMEPAD_RIGHT_THUMB      0x0080
//#define XINPUT_GAMEPAD_LEFT_SHOULDER    0x0100
//#define XINPUT_GAMEPAD_RIGHT_SHOULDER   0x0200
//#define XINPUT_GAMEPAD_A                0x1000
//#define XINPUT_GAMEPAD_B                0x2000
//#define XINPUT_GAMEPAD_X                0x4000
//#define XINPUT_GAMEPAD_Y                0x8000


char controller() {
	CXBOXController* Player1;
	Player1 = new CXBOXController(1);
	bool run = true;

	while (run) {
		if (Player1->IsConnected()) {

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) {
				//cout << "A is pressed" << endl;
				Sleep(200);
				return 'i';

			}
			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B) {
				//cout << "B is pressed" << endl;
				Sleep(200);
				return 'q';

			}
			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X) {
				//cout << "X is pressed" << endl;
				Sleep(200);
				return 'x';

			}
			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y) {
				//cout << "Y is pressed" << endl;
				Sleep(200);
				return 'y';

			}
			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START) {
				//cout << "START is pressed" << endl;
				Sleep(200);
				return 'h';

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) {
				//cout << "DPAD UP" << endl;
				Sleep(200);
				return 'w';

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {
				//cout << "DPAD DOWN" << endl;
				Sleep(200);
				return 's';
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) {
				//cout << "DPAD LEFT" << endl;
				Sleep(200);
				return 'a';

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) {
				//cout << "DPAD RIGHT" << endl;
				Sleep(200);
				return 'd';
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) {
				//cout << "LEFT THUMB" << endl;
				Sleep(200);
				return 'l';
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) {
				//cout << "RIGHT THUMB" << endl;
				Sleep(200);
				return 'r';
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) {
				//cout << "LEFT SHOULDER" << endl;
				Sleep(200);
				return 'z';
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {
				//cout << "RIGHT SHOULDER" << endl;
				Sleep(200);
				return 'c';
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK) {
				/*cout << "BACK is pressed" << endl;
				cout << "exiting program" << endl;*/
				run = false;
				return 'q';
			}



		}
		else {
			std::cout << "\n\tERROR! PLAYER 1 - XBOX 360 Controller Not Found!\n";
			std::cout << "Press Any Key To Exit.";
			std::cin.get();

		}

	}

	delete(Player1);
}

void fun() {
	bool haveFUN = true;
	while (haveFUN) {
		char x = controller();
		if (x != 'q') {
			cout << x << " <--" << endl;
		}
		if (x == 'q') {
			cout << x << " <-- have fun!" << endl;
			break;
		}
	}
}



