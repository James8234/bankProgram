#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct studentType
{
	char name[26];
	double gpa;
	int sID;
	char grade;

};

struct NodeType
{
	int num;
	int *numptr;

};

//void testFunction();

#endif
