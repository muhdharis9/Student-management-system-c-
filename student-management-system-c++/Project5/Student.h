#pragma once
#ifndef Student_H
#define Student_H
using namespace std;

#include<iostream>
#include<iomanip>
const int maxSize = 100;

class Student
{
public:
	Student();
	~Student() {};
	int size;
	int getMenu();
	void title();
	void displayStudentList();
	int binarySearch();
	int probabilitySearch();
	void addStudent();
	void deleteStudent();
	void displaySearch(int location);
	int Partition(int s, int e);
	void QuickSort(int s, int e);
	char getChoiceFindStudent();
	void BinarySelected();
	void noData();
	void Empty();
	void Exit();

private:
	string name[maxSize];
	string icNo[maxSize];
	string matricNo[maxSize];
	string faculty[maxSize];
};

#endif Student_H


