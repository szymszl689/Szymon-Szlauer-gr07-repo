// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	float tab[6];
	float suma = 0;
	for (int i = 0; i < 6; i++) {
		cin >> tab[i];
		suma = suma + tab[i];
	}
	for (int i = 0;i < 6;i++) {
		cout << "Element " << i << "wynosi " << tab[i] << endl;
	}
	cout << "Œrednia=" << suma / 6;
    return 0;
}

