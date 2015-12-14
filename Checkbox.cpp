#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"

#include "Checkbox.h"

using namespace std;

Checkbox::Checkbox()
{
	hit = pressed = false;
}

Checkbox::Checkbox(int locX, int locY, int width, int height)
: MyButton(locX, locY, width, height)
{
	hit = pressed = false;
}

Checkbox::~Checkbox()
{
	delete unchecked;
	delete checked;
}

void Checkbox::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X + Width && y>Y && y < Y + Height)
		hit = true;
	else
	{
		hit = false;
	}
}

void Checkbox::OnPaint()
{
	if (pressed)
		DrawBitmap(*checked, X, Y, Width, Height);
	else
		DrawBitmap(*unchecked, X, Y, Width, Height);

}

void Checkbox::OnLoaded()
{
	unchecked = new Bitmap("CheckboxUnmarked.bmp");
	checked = new Bitmap("CheckboxMarked.bmp");
}

void Checkbox::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
	{
		if (pressed)
			pressed = false;
		else
		{
			pressed = true;
		}
	}
}
