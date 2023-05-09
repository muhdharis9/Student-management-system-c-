
#include <iostream>
#include "Student.h";
#include <iomanip>
using namespace std;
#define width 30

int main()
{
	Student student;

	int studentFound = 0, menuChoice = 0;
	char searchChoice;
	string x;

	student.title();
	do
	{
		menuChoice = student.getMenu();
		system("cls");
		switch (menuChoice)
		{
		case 1:
			student.addStudent();
			break;
		case 2:
			student.deleteStudent();

			break;
		case 3:
			student.displayStudentList();
			break;
		case 4:
			if (student.size > 0)
			{
				searchChoice = student.getChoiceFindStudent();
				system("cls");
				if (searchChoice == 'A' || searchChoice == 'a')
				{
					student.QuickSort(0, student.size - 1);
					studentFound = student.binarySearch();
				}
				else
				{
					if (searchChoice == 'B' || searchChoice == 'b')
					{
						studentFound = student.probabilitySearch();
					}
				}
				if (studentFound == -1)
				{
					student.noData();
				}
				else
				{
					student.displaySearch(studentFound);
				}
			}
			else
			{
				student.Empty();
			}
			break;
		case 5:
			student.QuickSort(0, student.size - 1);
			student.displayStudentList();
			break;

		default:
			student.getMenu();
		}
	} while (menuChoice >= 1 && menuChoice <= 5);
	student.Exit();
	return 0;
}

