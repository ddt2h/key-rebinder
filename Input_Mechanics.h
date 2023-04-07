#pragma once
#include <dinput.h>
#include <iostream>
void advanced_mouse_down(std::string mouse_button = "left")
{
	DWORD mouse_down;

	if (mouse_button == "left")
	{
		mouse_down = MOUSEEVENTF_LEFTDOWN;

	}
	if (mouse_button == "right")
	{
		mouse_down = MOUSEEVENTF_RIGHTDOWN;

	}

	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = mouse_down;
	::SendInput(1, &Input, sizeof(INPUT));
}
void advanced_mouse_up(std::string mouse_button = "left")
{
	DWORD mouse_up;
	if (mouse_button == "left")
	{

		mouse_up = MOUSEEVENTF_LEFTUP;
	}
	if (mouse_button == "right")
	{

		mouse_up = MOUSEEVENTF_RIGHTUP;
	}
	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = mouse_up;
	::SendInput(1, &Input, sizeof(INPUT));
}
void keyboard_act(int key_code, int holdtime_ms) //mb set a minimum interval
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.wVk = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.dwFlags = KEYEVENTF_SCANCODE;
	ip.ki.wScan = key_code;

	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	Sleep(holdtime_ms);
	SendInput(1, &ip, sizeof(INPUT));
}
void LeftClick(int hold_time_ms = 30)
{
	INPUT    Input = { 0 };
	// left down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));


	Sleep(hold_time_ms);
	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}
void RightClick(int hold_time_ms = 30)
{
	INPUT    Input = { 0 };
	// left down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));


	Sleep(hold_time_ms);
	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}
void MouseScroll(int RY)
{
	INPUT in;
	in.type = INPUT_MOUSE;
	in.mi.dwFlags = MOUSEEVENTF_WHEEL;
	in.mi.mouseData = RY;
	in.mi.time = 0;
	SendInput(1, &in, sizeof(in));
}