#include <Windows.h>
#include <iostream>
using namespace std;


bool is_key_down(char key_char)
	{
	return GetKeyState(key_char) & 0x8000;
	}

void mouseClick() 
	{
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    // Simulate a left mouse button up event
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
    }
	
void do_the_thing()
	{
	POINT current_mouse_pos;
	GetCursorPos(&current_mouse_pos);
	SetCursorPos(200,200);
	mouseClick();
	SetCursorPos(current_mouse_pos.x,current_mouse_pos.y);
	}

int main()
	{

	while (true)
		{
		if (is_key_down('Q') and is_key_down('W'))
			{
			do_the_thing();
			}
		}
	return 0; 
	}