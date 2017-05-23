#pragma once
#include <iostream>

using namespace std;

class BitField
{
private:
	int Max; // ������������ ���������� �����
	int *arr; // ������ ��� ������������� ���� (������-���������)
	int Size; // ����� ��������� � ������� ���������

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

	BitField(const BitField &bf) // ����������� �����������
	{
		Max = bf.Max;
		Size = bf.Size;
		arr = new int[Size];

		if (arr != NULL)
		{
			for (int i(0); i < Size; i++)  arr[i] = bf.arr[i];
		}
	}

	~BitField() //��������� 
	{
		delete[]arr;
		arr = NULL;
	}

	void SetBit(const int); // ���������� ���
	int GetBit(const int);  // �������� �������� ����
	void ClrBit(const int); // �������� ���

	int GetLength(void) const // ���������� �����
	{
		return Max;
	}

	int GetMemIndex(const int n) const //������ Mem ��� ���� n
	{
		return n >> 4;
	}

	int GetMemMask(const int n) const // ������� ����� ��� ����
	{
		return 1 << (n & 15);
	}

	BitField & operator = (const BitField &); // ������������
	bool operator == (const BitField &); // ���������
	BitField operator | (const BitField &); // �������� "���" 
	BitField operator & (const BitField &); // �������� "�"
	BitField operator ~(void); // ���������

	// ����-�����
	friend istream & operator >> (istream &istr, BitField &bf);
	friend ostream & operator << (ostream &ostr, BitField &bf);
	
};
