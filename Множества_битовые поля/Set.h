#pragma once

#include "BitField.h"
#include <iostream>

using namespace std;

class Set
{
private:
	int MaxSet; // ������������ ����� ��������� ���������
	BitField TBitField; // ������ ��� ������������� ��������� � ������� ����

public:
	Set(int mp)  :MaxSet(mp), TBitField(mp) {}
	Set(const Set &s) : MaxSet(s.MaxSet), TBitField(s.TBitField){} // ����������� �����������

	Set(const BitField &bf) :MaxSet(bf.GetLength()), TBitField(bf) {} // ����������� �������������� ����

	operator BitField() // �������������� ����
	{
		BitField tmp(this->TBitField);
		return tmp;
	}

	int GetMaxPower(void) const // ������������ ���������� �����
	{
		return MaxSet;
	}

	void InsElem(const int );//�������� �������
	void DelElem(const int );//������� �������
	int IsMember(const int n)// ������� �������� � ���������
	{
		return TBitField.GetBit(n);
	}
	
	Set & operator = (const Set &);//������������
	bool operator == (const Set &);//���������
	Set operator + (const Set &);//�����������
	Set operator * (const Set &);//�����������
	Set operator ~ (void);//����������

	//����-�����
	friend istream & operator >> (istream &istr, Set &s);
	friend ostream & operator << (ostream &ostr, Set &s);
};

