#pragma once

#include "BitField.h"
#include <iostream>

using namespace std;

class Set
{
private:
	int MaxSet; // Максимальное число элементов множества
	BitField TBitField; // Память для представления множества – битовое поле

public:
	Set(int mp)  :MaxSet(mp), TBitField(mp) {}
	Set(const Set &s) : MaxSet(s.MaxSet), TBitField(s.TBitField){} // конструктор копирования

	Set(const BitField &bf) :MaxSet(bf.GetLength()), TBitField(bf) {} // конструктор преобразования типа

	operator BitField() // преобразование типа
	{
		BitField tmp(this->TBitField);
		return tmp;
	}

	int GetMaxPower(void) const // Максимальное количество битов
	{
		return MaxSet;
	}

	void InsElem(const int );//вставить элемент
	void DelElem(const int );//удалить элемент
	int IsMember(const int n)// наличие элемента в множестве
	{
		return TBitField.GetBit(n);
	}
	
	Set & operator = (const Set &);//присваивание
	bool operator == (const Set &);//сравнение
	Set operator + (const Set &);//объединение
	Set operator * (const Set &);//пересечение
	Set operator ~ (void);//дополнение

	//ввод-вывод
	friend istream & operator >> (istream &istr, Set &s);
	friend ostream & operator << (ostream &ostr, Set &s);
};

