#include <iostream>
#include <conio.h> 
#include "BitField.h"
#include "Set.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");


	Set m1(10);
	Set m2(20);
	Set m3(20);

	m1.InsElem(0); 
	m1.InsElem(5);
	m1.InsElem(7);

	m2.InsElem(2);
	m2.InsElem(5);
	m2.InsElem(15);
	
	cout << "Множество 1: "<< m1 << endl;
	cout << "Множество 2: " << m2 << endl;
	
	m2.DelElem(2); 
	cout << "Множество 2, после удаления элемента: " << m2 << endl;
     
	int c = 0;
	if (m1.IsMember(5))
	{
		c = 1;
		cout << "Наличие элемента в множестве: " << c << endl;
	}
		

	m3 = m2;

	cout << "Присваивание: "<<m3 << endl;


	if (m3 == m2) c = 1;
	cout <<"Сравнение множеств: "<< c << endl;

	cout << "Объединение множеств: "<< m1 + m2 << endl;
	cout << "Пересечение множеств: " << m1 * m2 << endl;
	
	cout << "Дополнение множества: " << ~m2 << endl;

	_getch();
	return 0;
}