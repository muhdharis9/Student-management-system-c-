#include <iostream>
#include "Student.h"
#include <iomanip>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#define width 30

using namespace std;


Student::Student()
{
	size = 0;
}
void Student::title()
{
	cout << "\n  Welcome to ADZ University\n\n";
}
int Student::getMenu()
{
	int menuChoice;
	cout << "  -" << setw(width) << setfill('-') << "-" << endl;
	cout << "  What would you like to do?\n";
	cout << "\n  [1] Add New Student Info";
	cout << "\n  [2] Delete Students Info";
	cout << "\n  [3] Display All Student";
	cout << "\n  [4] Find Student Info";

	cout << "\n  [5] Sort List Of Student";
	cout << "\n  [6] Exit\n";
	cout << "  -" << setw(width) << setfill('-') << "-" << endl;
	cout << "  Your choice: ";
	cin >> menuChoice;
	while (menuChoice > 6 || menuChoice < 1)
	{
		cout << "  Invalid! Please try again: ";
		cin >> menuChoice;
	}
	return menuChoice;
}

void Student::addStudent()
{
	cout << "\n  Add New Student Info" << endl << endl;
	cout << "  -" << setw(width) << setfill('-') << "-" << endl;
	cout << right << setfill(' ') << "  Please Key-In Name" << setw(10) << ": ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name[size]);
	cout << "  Please Key-In Matric No" << setw(5) << ": ";
	getline(cin, matricNo[size]);
	cout << "  Please Key-In IC Number" << setw(5) << ": ";
	getline(cin, icNo[size]);
	cout << "  Please Key-In Faculty" << setw(7) << ": ";
	getline(cin, faculty[size]);
	system("CLS");
	cout << "\n  Data " << name[size] << " Has Successful Added...\n\n";
	cout << "  Please Wait...\n" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	system("CLS");
	cout << "\n  Welcome to ADZ University\n\n";
	size++;
}

void Student::deleteStudent()
{
	int a;
	if (size <= 0)
	{
		cout << "\n  List Of Student Is Empty !\n\n\n";
	}
	else
	{
		displayStudentList();
		cout << "  Please choose which student to be delete: ";
		cin >> a;
		cout << endl;
		while (size < a || a <= 0)
		{
			cout << "  Invalid! Please choose the number at the list above: ";
			cin >> a;
		}
		system("cls");
		for (int i = 0; i < size; i++)
		{
			name[a - 1] = name[i];
			icNo[a - 1] = icNo[i];
			matricNo[a - 1] = matricNo[i];
			faculty[a - 1] = faculty[i];
			cout << "\n  Succesfully deleted...\n\n";
			cout << "  Please Wait...\n\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			system("CLS");
		}
		size--;
	}
}


void Student::displayStudentList()
{
	if (size > 0)
	{
		cout << "\n  List Of Student:" << endl << endl;
		cout << "  -" << setw(100) << setfill('-') << "-" << endl;
		cout << left << setfill(' ') << setw(8) << "  No." << setfill(' ') << setw(38) << "Student Name" << setfill(' ') << setw(26) << "IC Number" << setfill(' ') << setw(21) << "Matric Number" << "Faculty" << endl;
		cout << "  -" << setw(100) << setfill('-') << "-" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "  " << left << setfill(' ') << setw(6) << i + 1 << left << setfill(' ') << setw(38) << name[i] << left << setfill(' ') << setw(26) << icNo[i] << left << setfill(' ') << setw(21) << matricNo[i] << left << setfill(' ') << setw(0) << faculty[i] << endl;
		}
	}
	if (size == 0)
	{
		cout << "\n  List Of Student Is Empty !\n\n";
	}
	cout << endl;
}

void Student::displaySearch(int location)
{
	cout << "  -" << setw(width) << setfill('-') << "-" << endl;
	cout << left << setfill(' ') << setw(20) << "  Matric No" << setw(5) << ":" << matricNo[location] << endl;
	cout << left << setfill(' ') << setw(20) << "  Student Name" << setw(5) << ":" << name[location] << endl;
	cout << left << setfill(' ') << setw(20) << "  IC No" << setw(5) << ":" << icNo[location] << endl;
	cout << left << setfill(' ') << setw(20) << "  Faculty" << setw(5) << ":" << faculty[location] << endl << endl;
}



int Student::binarySearch()
{
	string x;
	cout << "\n  Search Student By Name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, x);
	int lower = 0;
	int upper = size - 1;
	int res = -1;
	while (lower <= upper)
	{
		int mid = lower + (upper - lower) / 2;
		if (x == (name[mid]))
		{
			res = 0;
		}
		if (res == 0)
		{
			return mid;
		}
		if (x > (name[mid]))
		{
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}
	return -1;
}

int Student::probabilitySearch()
{
	string x;
	cout << "  Your Choice: PROBABILITY(B)\n" << endl;
	cout << "  Search Student By Matric Number: ";
	cin >> x;
	int index = 0;
	while (index < size)
	{
		if (matricNo[index] != x)
		{
			index++;
		}
		else
		{
			return index;
			if (index != 0)
			{
				matricNo[index - 1] = matricNo[index];

				name[index - 1] = name[index];

				icNo[index - 1] = icNo[index];

				faculty[index - 1] = faculty[index];
			}
			break;
		}
	}
	return -1;
}


int Student::Partition(int s, int e)
{
	string pivot = name[e];
	int pIndex = s;

	for (int i = s; i < e; i++)
	{
		if (name[i] < pivot)
		{
			string temp = name[i];
			name[i] = name[pIndex];
			name[pIndex] = temp;

			string temp1 = icNo[i];
			icNo[i] = icNo[pIndex];
			icNo[pIndex] = temp1;

			string temp2 = matricNo[i];
			matricNo[i] = matricNo[pIndex];
			matricNo[pIndex] = temp2;

			string temp3 = faculty[i];
			faculty[i] = faculty[pIndex];
			faculty[pIndex] = temp3;
			pIndex++;
		}
	}

	string temp = name[e];
	name[e] = name[pIndex];
	name[pIndex] = temp;

	string temp2 = icNo[e];
	icNo[e] = icNo[pIndex];
	icNo[pIndex] = temp2;

	string temp3 = matricNo[e];
	matricNo[e] = matricNo[pIndex];
	matricNo[pIndex] = temp3;

	string temp4 = faculty[e];
	faculty[e] = faculty[pIndex];
	faculty[pIndex] = temp4;



	return pIndex;
}

void Student::QuickSort(int s, int e)
{
	if (s < e)
	{
		int p = Partition(s, e);
		QuickSort(s, (p - 1));
		QuickSort((p + 1), e);
	}
}
char Student::getChoiceFindStudent()
{
	char searchChoice;
	cout << "\n  Key-in (A) For BINARY or (B) For PROBABILITY : " << endl << endl;
	cout << "  -" << setw(45) << setfill('-') << "-" << endl;
	cout << "  Your choice: ";
	cin >> searchChoice;
	cout << endl;
	while ((searchChoice != 'A' && searchChoice != 'a') && (searchChoice != 'B' && searchChoice != 'b'))
	{
		cout << "  Invalid input! Please try again:  ";
		cin >> searchChoice;
	}
	return searchChoice;
	cout << endl;
}
void Student::BinarySelected()
{
	string sort;
	cout << "\n  Your choice: BINARY(A)\n" << endl;
	cout << "  Please Key-in (Y) to sort the name first : ";
	cin >> sort;
	cout << endl;
	while (sort != "Y" && sort != "y") {
		cout << "  Invalid input! Please try again: ";
		cin >> sort;
	}
}
void Student::Exit()
{
	cout << "\n  Thank You For Using Our  System." << endl;
}
void Student::Empty()
{
	cout << "\n  List Of Student Is Empty !\n\n\n";
}
void Student::noData()
{
	cout << "\n  Student Data Not Found\n" << endl;
}