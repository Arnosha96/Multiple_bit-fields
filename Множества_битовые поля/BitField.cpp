#include <iostream>
#include "Bitfield.h"


using namespace std;

void BitField::SetBit(const int n)
{
	if ((n >= 0) && (n < Max))
		arr[GetMemIndex(n)] |= GetMemMask(n);
}

int BitField::GetBit(const int n)
{
	if ((n >= 0) && (n < Max))
		return arr[GetMemIndex(n)] & GetMemMask(n);
	return 0;
}

void BitField::ClrBit(const int n)
{
	if ((n >= 0) && (n < Max))
		arr[GetMemIndex(n)] &= ~GetMemMask(n);
}

BitField & BitField::operator = (const BitField &bf)
{
	Max = bf.Max;
	if (Size != bf.Size)
	{
		Size = bf.Size;
		if (arr != NULL)
			delete arr;
		arr = new int[Size];
	}
	if (arr != NULL)
	for (int i(0); i<Size; i++)
		arr[i] = bf.arr[i];
	return *this;
}

bool BitField :: operator == (const BitField &bf)
{
	bool res = true;
	if (Max != bf.Max) res = false;
	else
	{
		for (int i(0); i<Size; i++)
		{
			if (arr[i] != bf.arr[i])
			{
				res = false;
				break;
			}
		}
	}

	return res;
}

BitField BitField:: operator |(const BitField &bf)
{
	int len = Max;

	if (bf.Max>len) len = bf.Max;

	BitField temp(len);
	for (int i(0); i<Size; i++) temp.arr[i] = arr[i];
	for (int i(0); i<bf.Size; i++) temp.arr[i] |= bf.arr[i];

	return temp;
}

BitField BitField:: operator &(const BitField &bf)
{
	
	int len = Max;

	if (bf.Max>len) len = bf.Max;

	BitField temp(len);
	memcpy(temp.arr, arr, sizeof(temp.arr));
	for (int i(0); i<Size; i++) temp.arr[i] = arr[i];
	for (int i(0); i<bf.Size; i++) temp.arr[i] &= bf.arr[i];

	return temp;
}

BitField BitField:: operator ~(void)
{
	int len = Max;
	BitField temp(len);
	for (int i(0); i<Size; i++) temp.arr[i] = ~arr[i];
	return temp;
}

istream &operator>>(istream &istr, BitField &bf)
{
	char ch;
	int i(0);
	
	
		while (true)
		{
			istr >> ch;
			if (ch == '0') bf.ClrBit(i++); 
			
			else if (ch == '1') bf.SetBit(i++); else break;

		}
	
	return istr;
}

ostream & operator<<(ostream &ostr, BitField &bf)
{
	int len = bf.GetLength();
	for (int i=len; i>=0; i--)
	
	if (bf.GetBit(i)) ostr << '1'; else ostr << '0';
	
	return ostr;
}


