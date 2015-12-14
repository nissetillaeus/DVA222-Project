#pragma once

#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"

#include "MyButton.h"

using namespace std;

class Checkbox : public MyButton
{
public:
	/*
		Bitmaps
	*/
	Bitmap *unchecked;
	Bitmap *checked;

	/*
		States
	*/
	bool hit;
	bool pressed;

	/*
		Constructors
	*/
	Checkbox();
	Checkbox(int locX, int locY, int width, int height);

	/*
		Destructor
	*/
	~Checkbox();

	/*
		Overrides
	*/
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnPaint();
	virtual void OnLoaded();
	void OnMouseDown(int button, int x, int y);
};
