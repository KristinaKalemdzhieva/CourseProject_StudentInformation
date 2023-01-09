#include <iostream>
#include <fstream>
#include <string>

void mainMenu();

void groupMenu(const int group);

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

	std::cout << "Total count of student's disciplines: ";
	int n;
	std::cin >> n;
	std::cout << std::endl;
	char **disciplines = new char*[10];
	double marks[10];
	for (int i = 0; i < n; ++i)
	{
		disciplines[i] = new char[10];
		char discipline[10];

		std::cout << "Discipline: ";
		std::cin >> discipline;
		disciplines[i] = discipline;
		std::cout << std::endl;

		std::cout << "Mark: ";
		std::cin >> marks[i];
		std::cout << std::endl;
	}

	std::string fileName;
	switch (group)
	{
	case 1:
		fileName = "firstGroup.txt";
		break;
	case 2:
		fileName = "secondGroup.txt";
		break;
	case 3:
		fileName = "thirdGroup.txt";
		break;
	case 4:
		fileName = "fourthGroup.txt";
		break;
	case 5:
		fileName = "fifthGroup.txt";
		break;
	case 6:
		fileName = "sixthGroup.txt";
		break;
	case 7:
		fileName = "seventhGroup.txt";
		break;
	case 8:
		fileName = "eighthGroup.txt";
		break;
	}

	std::fstream groupFile;
	groupFile.open(fileName, std::ios::app);
	if (groupFile.is_open())
	{
		groupFile << firstName << " " << secondName << " " << lastName << " " << facultyNumber << " ";
		for (int i = 0; i < n; ++i)
		{	
			groupFile << disciplines[i] << " " << marks[i] << " ";
		}
		groupFile << std::endl;
		groupFile.close();
	}
	delete[] disciplines;

	groupMenu(group);
}

void unsubscribeStudent(const int group)
{
	std::cout << "Enter student's faculty number: ";
	char facultyNumber;
	std::cin >> facultyNumber;
	std::cout << std::endl;

	groupMenu(group);
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

	groupMenu(group);
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

	groupMenu(group);
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

	mainMenu();
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
		std::cout << "Have a nice day! :)" << std::endl;
		return;
		break;
	}
}


int main()
{
	mainMenu();
}