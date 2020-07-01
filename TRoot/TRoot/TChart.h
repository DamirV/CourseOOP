#pragma once

#include "TRoot.h"
#include "TPoint.h"
#include <string.h>

class TPoint;
class TChart;

struct TChartLine
{
	TChart *tc;
	TPoint *tf, *tl;
};

class TChart : public TRoot
{
private:

	TStack<TChartLine> stc;

protected:
	TRoot *pFirst, *pLast;
		
public:
	TChart();
	void SetFirst(TRoot *p);
	void SetLast(TRoot *p);
	TRoot* Show(Graphics ^gr, TRoot *p);
	void Show(Graphics^ gr);
	/*void Setx(int _x);
	void Sety(int _y);
	int Getx();
	int Gety();*/
};