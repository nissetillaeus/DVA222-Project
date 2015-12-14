#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"

#include "RadioButton.h"

using namespace std;

RadioButton::RadioButton()
{
	hit = pressed = false;
}

RadioButton::RadioButton(int locX, int locY, int width, int height)
: MyButton(locX, locY, width, height)
{
	hit = pressed = false;
}

RadioButton::~RadioButton()
{
	delete unchecked;
	delete checked;
}

void RadioButton::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X + Width && y>Y && y < Y + Height)
		hit = true;
	else
	{
		hit = false;
	}
}

void RadioButton::OnPaint()
{
	if (pressed)
		DrawBitmap(*checked, X, Y, Width, Height);
	else
		DrawBitmap(*unchecked, X, Y, Width, Height);

}

void RadioButton::OnLoaded()
{
	unchecked = new Bitmap("RadioButtonUnmarked.bmp");
	checked = new Bitmap("RadioButtonMarked.bmp");
}

void RadioButton::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
		pressed = true;
}
