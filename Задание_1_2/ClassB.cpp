#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "ClassB.h"
using namespace std;


ClassB::ClassB()
{
	cout << "B default constructor\n";
}
ClassB::ClassB(string s_name)
{
	cout << "B parameter constructor\n";
}
ClassB::~ClassB()
{
	cout << "B destructor\n";
}