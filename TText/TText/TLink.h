#pragma once
#include <string.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class TLink;
class TText;

struct TMem
{
	TLink *pFree, *pFirst, *pLast;
};




class TLink
{
public:

	char str[100];

	TLink* pNext;
	TLink* pDown;

	static TMem mem;
	bool status;
	TLink(char *ch = NULL, TLink *pn = NULL, TLink *pd= NULL);
	~TLink();

	void* operator new(size_t s);

	void operator delete (void* p);

	static void InitMem(int size);
	static void MemClr(TText& txt);
	static void PrintFreeTLinks();
};