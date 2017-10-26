// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int main()
{
	int fib[50];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2;i < 50;i++) {
		fib[i] = fib[i - 1] = fib[i - 2];
	}

    return 0;
}

