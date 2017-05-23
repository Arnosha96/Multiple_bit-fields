#include "Set.h"
#include "BitField.h"
#include <iostream>

using namespace std;


void Set::InsElem(const int n)
{
	TBitField.SetBit(n);
}

void Set::DelElem(const int n)
{
	TBitField.ClrBit(n);
}

Set & Set :: operator=(const Set &s)
{
	TBitField = s.TBitField;
	MaxSet = s.GetMaxPower();
	return *this;
}

bool Set::operator==(const Set&s)
{
	return TBitField == s.TBitField;
}

Set Set :: operator+(const Set &s)
{
	Set tmp(TBitField | s.TBitField);
	return tmp;
}

Set Set :: operator*(const Set &s)
{
	Set tmp(TBitField & s.TBitField);
	return tmp;
}

Set Set :: operator~(void)
{
	Set tmp(~TBitField);
	return tmp;
}

istream & operator >> (istream &istr, Set &s)
{
	int tmp; char ch;
	do
	{
		istr >> ch;
		
	} while (ch != '{');

	do
	{
		istr >> tmp;
		s.InsElem(tmp);
		do
		{
			istr >> ch;
		} while ((ch != ',') && (ch != '}'));

	}
	while (ch != '}');
	return istr;
}
ostream & operator << (ostream &ostr, Set &s)
{
	char ch= ' ';
	ostr << "{";
	int n = s.GetMaxPower();
	for (int i(0); i < n; i++)
	{
		if (s.IsMember(i))
		{
			ostr << ch << ' ' << i;
			ch = ',';
		}
	}
	ostr << " }";
	return ostr;
}
