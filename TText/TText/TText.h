#pragma once
#include "TStack.h"
#include "TLink.h"
#include <string.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class TText
{
private:
	TLink *pFirst;
	TStack <TLink*> stc;

public:
	TLink *pCurr;
	TText(TLink *tl = NULL);
	~TText();
	
	void InsNextLine(char *ch);
	void InsNextSection(char *ch);
	void InsDownLine(char *ch);
	void InsDownSection(char *ch);
	void DelNext();
	void DelDown();
	TLink* ReadRec(istream& ifs, int level);
	void Read(char *ch);
	void PrintRec(TLink *p,int level);
	void Print();
	void Reset();
	bool IsEnd();
	void GoNext();
	TLink* CopyRec(TLink *tl);
	TLink* Copy();
	void SaveRec(TLink *temp, ofstream &of);
	void Save(char* fn);
	void ToNext();
	void ToDown();
	void ToPrev();
	void ToFirst();
	
};