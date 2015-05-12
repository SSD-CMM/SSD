//Author: Christopher Humm
#pragma once
#include "Controls.h"

class Title : public Controls
{
public:
	Title();
	Title(char* title_name, int control_msg, HWND* parentWindow, int font_size);
	~Title();

	virtual bool createControl(int x, int y, int height, int width);
	void setFont(HFONT font_name);
private:
	HFONT custom_font;
	int font_size;
protected:
};