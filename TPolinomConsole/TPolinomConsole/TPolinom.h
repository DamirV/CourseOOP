#pragma once
#include <iostream>
#include "THeadList.h"

using namespace std;

struct TMonom
{
	double coeff;
	int x, y, z;

public:

	void SetValue(double _coeff, int _x, int _y, int _z)
	{
		coeff = _coeff;
		x = _x;
		y = _y;
		z = _z;
	}

	void operator=(const TMonom& tm)
	{
		x = tm.x;
		y = tm.y;
		z = tm.z;
		coeff = tm.coeff;
	}

	bool operator>(const TMonom& tm)
	{
		if (x <= tm.x)
		{
			return false;
		}

		if (y <= tm.y)
		{
			return false;
		}

		if (z <= tm.z)
			return false;

		return true;
    }

	bool operator<(const TMonom& tm)
	{
			if (x >= tm.x)
		{
			return false;
		}

		if (y >= tm.y)
		{
			return false;
		}

		if (z >= tm.z)
			return false;

		return true;
	}

	bool operator==(const TMonom& tm)
	{
		if (x == tm.x && y == tm.y && z == tm.z)
			return true;

		return false;
	}

	bool operator>=(const TMonom& tm)
	{
			if (x < tm.x)
		{
			return false;
		}

		if (y < tm.y)
		{
			return false;
		}

		if (z < tm.z)
			return false;

		return true;
	}

	bool operator<=(const TMonom& tm)
	{
			if (x > tm.x)
		{
			return false;
		}

		if (y > tm.y)
		{
			return false;
		}

		if (z > tm.z)
			return false;

		return true;
	}

	bool operator!=(const TMonom& tm)
	{
		return !operator==(tm);
	}

	friend TMonom operator+(TMonom& tm1, TMonom& tm2)
	{
		TMonom temp;

		temp.coeff = tm1.coeff + tm2.coeff;

		temp.x = tm1.x;
		temp.y = tm1.y;
		temp.z = tm1.z;

		return temp;
	}

	friend TMonom operator-(TMonom& tm1, TMonom& tm2)
	{
		TMonom temp;

		temp.coeff = tm1.coeff - tm2.coeff;

		temp.x = tm1.x;
		temp.y = tm1.y;
		temp.z = tm1.z;

		return temp;
	}

	friend TMonom operator*(TMonom& tm, double elem)
	{
		TMonom temp;

		temp.x = tm.x;
		temp.y = tm.y;
		temp.z = tm.z;

		temp.coeff *= elem;

		return temp;
	}

	void operator*=( double elem)
	{
		coeff *= elem;
	}

	friend TMonom operator*(double elem, TMonom& tm)
	{
		TMonom temp;

		temp.x = tm.x;
		temp.y = tm.y;
		temp.z = tm.z;

		temp.coeff = tm.coeff * elem;

		return temp;
	}

	void operator*=(const TMonom& tm)
	{
		x += tm.x;
		y += tm.y;
		z += tm.z;


		coeff *= tm.coeff;
	}


	friend TMonom operator*(TMonom& tm1, TMonom& tm2 )
	{
		TMonom temp;

		temp.x = tm1.x + tm2.x;
		temp.y = tm1.y + tm2.y;
		temp.z = tm1.z + tm2.z;

		temp.coeff = tm1.coeff * tm2.coeff;

		return temp;
	}

	void operator+=(TMonom& tm)
	{
		coeff += tm.coeff;
	}

	friend ostream& operator<<(ostream& os, const TMonom& tm) 
	{
		if(tm.coeff > 0)
		{
			os<<"+";
		}

		os << tm.coeff << "x^" << tm.x << "y^" << tm.y << "z^" << tm.z << " ";
		return os;
	}

	friend istream& operator>>(istream& is, TMonom& tm)
	{
		

		is >> tm.coeff >> tm.x >> tm.y >> tm.z;

	

		return is;
	}

};

class TPolinom :public THeadList<TMonom>
{
public:
	TPolinom() : THeadList<TMonom>()
	{

		pHead->val.coeff = 0;
		pHead->val.x = 0;
		pHead->val.y = 0;
		pHead->val.z = -1;

	}
	~TPolinom()
	{

	}

	void operator+=(TMonom& tm)
	{
		if (tm.coeff == 0)
		{
			return;
		}

		for (Reset(); !IsEnd(); GoNext())
		{
			if (tm > pCurr->val)
			{
				InsCurr(tm);
				return;
			}

			if (tm == pCurr->val)
			{
				pCurr->val += tm;

				if (pCurr->val.coeff == 0)
				{
					DelCurr();
				}
				return;
			}
		}
		InsCurr(tm);

	}

	TPolinom& operator=(TPolinom& tp)
	{
		TList<TMonom>::~TList();

		for (tp.Reset(); !tp.IsEnd(); tp.GoNext())
		{
			*this += tp.pCurr->val;
		}

		return *this;
	}

	friend TPolinom operator+(TPolinom& tp1, TPolinom& tp2)
	{

		TPolinom temp = tp1;

		for (tp2.Reset(); !tp2.IsEnd(); tp2.GoNext())
		{
			temp += tp2.pCurr->val;
		}

		return temp;
	}

	TPolinom(TPolinom& p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			this->operator+=( p.pCurr->val );
		}
	}

	friend TPolinom operator*(TPolinom& tp1, TPolinom& tp2)
	{
		TPolinom temp;// = new TPolinom();

		for (tp1.Reset(); !tp1.IsEnd(); tp1.GoNext())
		{
			for (tp2.Reset(); !tp2.IsEnd(); tp2.GoNext())
			{
				temp += tp1.pCurr->val * tp2.pCurr->val;

			}

		}

		return temp;

	}

	friend TPolinom operator*(TPolinom& tp, TMonom& tm)
	{
		TPolinom temp = tp;

		for (temp.Reset(); !temp.IsEnd(); temp.GoNext())
		{
			temp.pCurr->val *= tm;
		}

		return temp;

	}

	friend TPolinom& operator*(TPolinom& tp, double d)
	{
		TPolinom temp = tp;

		for ( temp.Reset(); !temp.IsEnd(); temp.GoNext())
		{
			temp.pCurr->val *= d;
		}

		return temp;
	}

	friend TPolinom& operator*(double d, TPolinom& tp)
	{
		TPolinom temp  = tp;

		for (temp.Reset(); !temp.IsEnd(); temp.GoNext())
		{
			temp.pCurr->val *= d;
		}

		return temp;
	}


	friend TPolinom operator-(TPolinom tp1, TPolinom tp2)
	{
		TPolinom temp  = tp2;
		temp = temp * -1.0;

		temp = temp + tp1;

		return temp;

	}

	friend ostream& operator<<(ostream& os, TPolinom& tp)
	{
		if (tp.size == 0)
		{
			os << 0 << " ";
			return os;
		}

		for (tp.Reset(); !tp.IsEnd(); tp.GoNext())
		{
			os << tp.pCurr->val;
		}

		return os;
	}

	void ClrTPolinom()
	{
		TList<TMonom>:: ~TList();
	}





};