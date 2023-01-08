#include <iostream>

void mainMenu();

void enterStudent(const int group)
{
	std::cout << "First name: ";
	char firstName;
	std::cin >> firstName;
	std::cout << std::endl;

	std::cout << "Second name: ";
	char secondName;
	std::cin >> secondName;
	std::cout << std::endl;

	std::cout << "Last name: ";
	char lastName;
	std::cin >> lastName;
	std::cout << std::endl;

	std::cout << "Faculty number: ";
	char facultyNumber;
	std::cin >> facultyNumber;
	std::cout << std::endl;

	std::cout << "Тotal count of student's disciplines: ";
	int n;
	std::cin >> n;
	std::cout << std::endl;
	char disciplines[10][2];
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Discipline - mark: ";
		for (int j = 0; j < 2; ++j)
		{
			std::cin >> disciplines[i][j];
		}
		std::cout << std::endl;
	}
}

void unsubscribeStudent(const int group)
{
	std::cout << "Enter student's faculty number: ";
	char facultyNumber;
	std::cin >> facultyNumber;
	std::cout << std::endl;
}

void sortStudents(const int group)
{

}

void printStudents(const int group)
{

}

void groupMenu(const int group)
{
	std::cout << "1. Enter student" << std::endl;
	std::cout << "2. Unsubscribe student" << std::endl;
	std::cout << "3. Sort Students" << std::endl;
	std::cout << "4. Print list of the students" << std::endl;
	std::cout << "5. Back" << std::endl << std::endl;

	std::cout << "Choose a number: ";
	int n;
	std::cin >> n;

	switch (n)
	{
	case 1:
		enterStudent(group);
		break;
	case 2:
		unsubscribeStudent(group);
		break;
	case 3:
		sortStudents(group);
		break;
	case 4:
		printStudents(group);
		break;
	case 5:
		mainMenu();
		break;
	}
}

void printStudentsFromVariousGroups()
{

}

void mainMenu()
{
	std::cout << "1. First Group Menu" << std::endl;
	std::cout << "2. Second Group Menu" << std::endl;
	std::cout << "3. Third Group Menu" << std::endl;
	std::cout << "4. Fourth Group Menu" << std::endl;
	std::cout << "5. Fifth Group Menu" << std::endl;
	std::cout << "6. Sixth Group Menu" << std::endl;
	std::cout << "7. Seventh Group Menu" << std::endl;
	std::cout << "8. Eigth Group Menu" << std::endl;
	std::cout << "9. Print student information for more than one group" << std::endl;
	std::cout << "10. Exit" << std::endl << std::endl;
	std::cout << std::endl;

	std::cout << "Choose a number: ";
	int n;
	std::cin >> n;
	std::cout << std::endl;

	switch (n)
	{
	case 1:
		groupMenu(1);
		break;
	case 2:
		groupMenu(2);
		break;
	case 3:
		groupMenu(3);
		break;
	case 4:
		groupMenu(4);
		break;
	case 5:
		groupMenu(5);
		break;
	case 6:
		groupMenu(6);
		break;
	case 7:
		groupMenu(7);
		break;
	case 8:
		groupMenu(8);
		break;
	case 9:
		printStudentsFromVariousGroups();
		break;
	case 10:
		return;
		break;
	}
}


int main()
{
	mainMenu();
}