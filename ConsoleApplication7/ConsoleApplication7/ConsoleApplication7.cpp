// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <time.h>

using namespace std;

double func(double x) {
	return x*x + x + 5;
}

double integralOMP(double start, double end, int n) {
	double result = 0;
	double dx = (end - start) / n;

	

	#pragma omp parallel for
	for (int i = 1; i < n; i++) {
		result += func(start + dx * i);
	}

	result = (result + (func(start) + func(end)) / 2) * dx;
	return result;
}


double integralSEQ(double start, double end, int n) {
	double result = 0;
	double dx = (end - start) / n;

	for (int i = 1; i < n; i++) {
		result += func(start + dx * i);
	}

	result = (result + (func(start) + func(end)) / 2) * dx;
	return result;
}

int main()
{
	double start, end, resultOMP, timeResultOMP, resultSEQ, timeResultSEQ;
	int n;
	cout << "Poczatek przedzialu calkowania\n";
	cin >> start;
	cout << "\nKoniec przedzialu calkowania\n";
	cin >> end;
	cout << "\nLiczba iteracji\n";
	cin >> n;
	clock_t tStartOMP = clock();
	resultOMP = integralOMP(start, end, n);
	timeResultOMP = (double)(clock() - tStartOMP) / CLOCKS_PER_SEC;
	cout << "\nWynik calkowania równolegle: " << resultOMP << endl;
	cout << "Czas wykonania równolegle: " << timeResultOMP << endl;

	clock_t tStartSEQ = clock();
	resultSEQ = integralSEQ(start, end, n);
	timeResultSEQ = (double)(clock() - tStartSEQ) / CLOCKS_PER_SEC ;
	cout << "\nWynik calkowania sekwencyjnie: " << resultSEQ << endl;
	cout << "Czas wykonania sekwencyjnie: " << timeResultSEQ << endl;

    return 0;
}

