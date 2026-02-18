#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "ClassA.h"
using namespace std;


ClassA::ClassA()
{
	cout << "A default constructor\n";
}
ClassA::ClassA(string s_name)
{
	cout << "A parameter constructor\n";
}
ClassA::~ClassA()
{
	cout << "A destructor\n";
}