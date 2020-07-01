#pragma once
#include "TRoot.h"
using namespace System::Drawing;

class TPoint : public TRoot
{
protected:
	int x, y;

public:
	TPoint(int _x, int _y);
	void Show(Graphics^ gr);
	void Hide(Graphics^ gr);
	int GetX();
	int GetY();
};