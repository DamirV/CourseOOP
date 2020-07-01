#include "TChart.h"

TChart::TChart()
{
	pFirst = pLast = NULL;
}

void TChart::SetFirst(TRoot *p)
{
	pFirst = dynamic_cast<TPoint*>(p);
}

void TChart::SetLast(TRoot *p)
{
	pLast = dynamic_cast<TPoint*>(p);
}

TRoot* TChart:: Show(Graphics ^gr, TRoot *p)
{
	TPoint *pointF, *pointL;
	TChart *tc;
	pointF = dynamic_cast<TPoint*>(p);
	if (pointF != NULL)
	{
		return p;
	}
	else
	{
		tc = dynamic_cast<TChart*>(p);
		pointF = dynamic_cast<TPoint*>(Show(gr, tc->pFirst));
		pointL = dynamic_cast<TPoint*>(Show(gr, tc->pLast));
		gr->DrawLine(Pens::Black, pointF->GetX() , pointF->GetY(), pointL->GetX(), pointL->GetY());
	}
	return (TRoot*)pointF;
}

void TChart:: Show(Graphics^ gr)
{
	TChartLine curr;
	TRoot *temp;
	curr.tc = this;
	TPoint *tp;
	curr.tf = curr.tl=NULL;
	stc.Clr();
	stc.Push(curr);

	while (!stc.IsEmpty())
	{
		curr = stc.Pop();

		while (curr.tf == NULL)
		{
			temp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*>(temp);

			if (tp != NULL)
				curr.tf = tp;

			stc.Push(curr);

			curr.tc = dynamic_cast<TChart*>(temp);
		}
	}
	if (curr.tl == NULL)
	{
		temp = curr.tc->pLast;
		tp = dynamic_cast<TPoint*>(temp);
		if (tp != NULL)
			curr.tl = tp;
		else
		{
			stc.Push(curr);
			curr = dynamic_cast<TChart*>(temp);
			curr.tf = NULL;
			stc.Push(curr);
		}
	}
	if (curr.tf && curr.tl)
	{
		gr->DrawLine(Pens::Black, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			tp = curr.tl;
			if (!stc.IsEmpty())
			{
				curr = stc.Pop();
			}
			if (curr.tf = NULL)
				curr.tf = tp;
			else
				stc.Push(curr);
	}
}


//void TChart:: Setx(int _x)
//{
//	x = _x;
//}
//
//void TChart::Sety(int _y)
//{
//	y = _y;
//}
//
//int TChart::Getx()
//{
//	return x;
//}
//
//int TChart::Gety()
//{
//	return y;
//}