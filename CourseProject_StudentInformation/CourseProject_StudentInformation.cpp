#include <iostream>
#include <fstream>
#include <clocale>

void mainMenu();

//ima nqkakvyv problem i ne raboti zaradi nego!
void enterStudent(const int group)
{
	std::cout << "First name: ";
	char firstName[20];
	std::cin >> firstName;
	std::cout << std::endl;

	std::cout << "Second name: ";
	char secondName[25];
	std::cin >> secondName;
	std::cout << std::endl;

	std::cout << "Last name: ";
	char lastName[25];
	std::cin >> lastName;
	std::cout << std::endl;

	std::cout << "Faculty number: ";
	char facultyNumber[7];
	std::cin >> facultyNumber;
	std::cout << std::endl;

	std::cout << "Тotal count of student's disciplines: ";
	int n;
	std::cin >> n;
	std::cout << std::endl;
	char disciplines[10];
	double marks[10];
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Discipline - mark: ";
		std::cin >> disciplines[i];
		std::cin >> marks[i];
		std::cout << std::endl;
	}

	if (group == 1)
	{
		std::fstream firstGroup;
		firstGroup.open("firstGroup.txt", std::ios::app);
		if (firstGroup.is_open())
		{
			firstGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				firstGroup << disciplines[i] << " " << marks[i] << " ";
			}
			firstGroup << std::endl;

			firstGroup.close();
		}
	}
	else if (group == 2)
	{
		std::fstream secondGroup;
		secondGroup.open("secondGroup.txt", std::ios::app);
		if (secondGroup.is_open())
		{
			secondGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				secondGroup << disciplines[i] << " " << marks[i] << " ";
			}
			secondGroup << std::endl;

			secondGroup.close();
		}
	}
	else if (group == 3)
	{
		std::fstream thirdGroup;
		thirdGroup.open("thirdGroup.txt", std::ios::app);
		if (thirdGroup.is_open())
		{
			thirdGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				thirdGroup << disciplines[i] << " " << marks[i] << " ";
			}
			thirdGroup << std::endl;

			thirdGroup.close();
		}
	}
	else if (group == 4)
	{
		std::fstream fourthGroup;
		fourthGroup.open("fourthGroup.txt", std::ios::app);
		if (fourthGroup.is_open())
		{
			fourthGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				fourthGroup << disciplines[i] << " " << marks[i] << " ";
			}
			fourthGroup << std::endl;

			fourthGroup.close();
		}
	}
	else if (group == 5)
	{
		std::fstream fifthGroup;
		fifthGroup.open("fifthGroup.txt", std::ios::app);
		if (fifthGroup.is_open())
		{
			fifthGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				fifthGroup << disciplines[i] << " " << marks[i] << " ";
			}
			fifthGroup << std::endl;

			fifthGroup.close();
		}
	}
	else if (group == 6)
	{
		std::fstream sixthGroup;
		sixthGroup.open("sixthGroup.txt", std::ios::app);
		if (sixthGroup.is_open())
		{
			sixthGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				sixthGroup << disciplines[i] << " " << marks[i] << " ";
			}
			sixthGroup << std::endl;

			sixthGroup.close();
		}
	}
	else if (group == 7)
	{
		std::fstream seventhGroup;
		seventhGroup.open("seventhGroup.txt", std::ios::app);
		if (seventhGroup.is_open())
		{
			seventhGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				seventhGroup << disciplines[i] << " " << marks[i] << " ";
			}
			seventhGroup << std::endl;

			seventhGroup.close();
		}
	}
	else if (group == 8)
	{
		std::fstream eighthGroup;
		eighthGroup.open("eighthGroup.txt", std::ios::app);
		if (eighthGroup.is_open())
		{
			eighthGroup << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
			for (int i = 0; i < n; ++i)
			{
				eighthGroup << disciplines[i] << " " << marks[i] << " ";
			}
			eighthGroup << std::endl;

			eighthGroup.close();
		}
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
	std::cout << "Sort by average success or faculty number (please write 'a' for average success and 'f' for faculty number): ";
	char sortBy;
	std::cin >> sortBy;
	std::cout << std::endl;

	std::cout << "Sort in ascending/descending order (please write 'a' for ASC and 'd' for DESC): ";
	char wayToSort;
	std::cin >> wayToSort;
	std::cout << std::endl;

	switch (sortBy)
	{
	case 'a':
		switch (wayToSort)
		{
		case 'a':
			break;
		case 'd':
			break;
		}
		break;
	case 'f':
		switch (wayToSort)
		{
		case 'a':
			break;
		case 'd':
			break;
		}
		break;
	}
}

//poradi neznaina prichina ne otpechatva
void printStudents(const int group)
{
	if (group == 1)
	{
		std::fstream firstGroup;
		firstGroup.open("firstGroup.txt", std::ios::in);	
		if (firstGroup.is_open())
		{		
			char line[50];
			while (firstGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			firstGroup.close();
		}
	}
	else if (group == 2)
	{
		std::fstream secondGroup;
		secondGroup.open("secondGroup.txt", std::ios::in);
		if (secondGroup.is_open())
		{
			char line[50];
			while (secondGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			secondGroup.close();
		}
	}
	else if (group == 3)
	{
		std::fstream thirdGroup;
		thirdGroup.open("thirdGroup.txt", std::ios::in);
		if (thirdGroup.is_open())
		{
			char line[50];
			while (thirdGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			thirdGroup.close();
		}
	}
	else if (group == 4)
	{
		std::fstream fourthGroup;
		fourthGroup.open("fourthGroup.txt", std::ios::in);
		if (fourthGroup.is_open())
		{
			char line[50];
			while (fourthGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			fourthGroup.close();
		}
	}
	else if (group == 5)
	{
		std::fstream fifthGroup;
		fifthGroup.open("fifthGroup.txt", std::ios::in);
		if (fifthGroup.is_open())
		{
			char line[50];
			while (fifthGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			fifthGroup.close();
		}
	}
	else if (group == 6)
	{
		std::fstream sixthGroup;
		sixthGroup.open("sixthGroup.txt", std::ios::in);
		if (sixthGroup.is_open())
		{
			char line[50];
			while (sixthGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			sixthGroup.close();
		}
	}
	else if (group == 7)
	{
		std::fstream seventhGroup;
		seventhGroup.open("seventhGroup.txt", std::ios::in);
		if (seventhGroup.is_open())
		{
			char line[50];
			while (seventhGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			seventhGroup.close();
		}
	}
	else if (group == 8)
	{
		std::fstream eighthGroup;
		eighthGroup.open("eighthGroup.txt", std::ios::in);
		if (eighthGroup.is_open())
		{
			char line[50];
			while (eighthGroup.getline(line, 50))
			{
				std::cout << line << std::endl;
			}
			eighthGroup.close();
		}
	}
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
	std::cout << std::endl;

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
	std::cout << "Enter groups (please enter the numbers of the groups separated by spaces): ";
	char groups[15];
	std::cin.getline(groups, 15);
	std::cout << std::endl;

	for (int i = 0; groups[i] != '\0'; ++i)
	{
		switch (groups[i])
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		}
	}
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
	setlocale(LC_ALL, "bulgarian");
	mainMenu();
}