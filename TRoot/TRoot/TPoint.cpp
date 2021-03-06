#include "TPoint.h"
TPoint::TPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}

void TPoint::Show(Graphics^ gr)
{
	gr->DrawEllipse(Pens::Black, x - 2, y - 2, x + 2, y + 2);
	visible = true;
}

void TPoint::Hide(Graphics^ gr)
{
	gr->DrawEllipse(Pens::White, x - 2, y - 2, x + 2, y + 2);
	visible = false;
}

int TPoint::GetX()
{
	return x;
}

int TPoint::GetY()
{
	return y;
}