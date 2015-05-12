//Author: Christopher Humm
#pragma once
#include "Controls.h"

class Button : public Controls
{
public:
	Button();
	Button(char* button_name, int control_msg, HWND* parentWindow);
	~Button();

	bool onClickAction();
	bool createControl(int x, int y, int height, int width);
private:
	bool button_pressed;
protected:
};