#include "Input.h"
#include <iostream>
#include <conio.h>

Input::Input()
{
	
}

int Input::X()
{
	char x = _getch();
	switch (x) {
	case 'a':
		return -1;
	case 'd':
		return 1;
	default:
		return 0;
	}
}

int Input::Y()
{
	char y = _getch();
	switch (y) {
	case 'w':
		return 1;
	case 's':
		return -1;
	default:
		return 0;
	}
}

bool Input::Save() {
	char s = _getch();
	switch (s)
	{
	case 'o':
		return true;
	default:
		return false;
	}
}

