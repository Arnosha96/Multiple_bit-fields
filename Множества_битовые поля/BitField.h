#pragma once
#include <iostream>

using namespace std;

class BitField
{
private:
	int Max; // Максимальное количество битов
	int *arr; // память для представления поля (массив-хранилище)
	int Size; // число элементов в массиве хранилище

public:
	BitField(int len) :Max(len)
	{
		Size = (len + 15) >> 4;
		arr = new int[Size];

		if (arr != NULL)
		{
			for (int i(0); i < Size; i++) arr[i] = 0;
		}
	}

	BitField(const BitField &bf) // конструктор копирования
	{
		Max = bf.Max;
		Size = bf.Size;
		arr = new int[Size];

		if (arr != NULL)
		{
			for (int i(0); i < Size; i++)  arr[i] = bf.arr[i];
		}
	}

	~BitField() //деструтор 
	{
		delete[]arr;
		arr = NULL;
	}

	void SetBit(const int); // установить бит
	int GetBit(const int);  // получить значение бита
	void ClrBit(const int); // очистить бит

	int GetLength(void) const // количество битов
	{
		return Max;
	}

	int GetMemIndex(const int n) const //индекс Mem для бита n
	{
		return n >> 4;
	}

	int GetMemMask(const int n) const // битовая маска для бита
	{
		return 1 << (n & 15);
	}

	BitField & operator = (const BitField &); // присваивание
	bool operator == (const BitField &); // сравнение
	BitField operator | (const BitField &); // операция "или" 
	BitField operator & (const BitField &); // операция "и"
	BitField operator ~(void); // отрицание

	// ввод-вывод
	friend istream & operator >> (istream &istr, BitField &bf);
	friend ostream & operator << (ostream &ostr, BitField &bf);
	
};
