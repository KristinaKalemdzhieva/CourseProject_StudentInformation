#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void mainMenu();

void groupMenu(const int group);

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

void getFacultyNumber(const char line[], char facultyNumber[])
{
	for (int i = 0; line[i] != '\0'; ++i)
	{
		if (line[i] == '0')
		{
			for (int j = 0; j < 7; ++j)
			{
				facultyNumber[j] = line[i];
				++i;
			}
			break;
		}
	}
}

void unsubscribeStudent(const int group)
{
	std::cout << "Enter student's faculty number: ";
	char facultyNumber[7];
	std::cin >> facultyNumber;
	std::cout << std::endl;

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
	groupFile.open(fileName, std::ios::in);

	std::fstream tempFile;
	tempFile.open("temp.txt", std::ios::out);

	if (groupFile.is_open() && tempFile.is_open())
	{
		char line[100];
		while (groupFile.getline(line, 100))
		{
			char facultyNumberCurrentLine[7];
			getFacultyNumber(line, facultyNumberCurrentLine);

			bool flag = true;
			for (int i = 0; facultyNumber[i] != '\0'; ++i)
			{
				if (facultyNumberCurrentLine[i] == facultyNumber[i])
				{
					continue;
				}
				else
				{
					flag = false;
					break;
				}
			}

			if (flag == false)
			{
				tempFile << line << std::endl;
			}
		}	

		tempFile.close();
		groupFile.close();
	    const char* directoryToFile = fileName.c_str();
		remove(directoryToFile);
		rename("temp.txt", directoryToFile);
	}

	groupMenu(group);
}

int getLinesCount(const std::string fileName)
{
	std::fstream myFile;
	myFile.open(fileName, std::ios::in);
	int count = 0;
	if (myFile.is_open())
	{
		char line[100];
		while (myFile.getline(line, 100))
		{
			++count;
		}
		myFile.close();
	}	
	return count;
}

void myStrCpy(char* a, char* b)
{
	int index = 0;
	while (a[index] != '\0')
	{
		b[index] = a[index];
		++index;
	}
	b[index] = '\0';
}

void mySwapCharArrays(char* a, char* b)
{
	char temp[7];
	myStrCpy(a, temp);
	myStrCpy(b, a);
	myStrCpy(temp, b);
}

void mySwapDoubleArrays(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

int myStrCmp(const char* a, const char* b)
{
	int index = 0;
	while (a[index] != '\0' && a[index] == b[index])
	{
		++index;
	}

	return a[index] - b[index];
}

void selectionSortFacultyNumbers(char** facultyNumbers, char** studentsInformation, const int size, const char wayToSort)
{
	if (wayToSort == 'a') 
	{
		for (int i = 0; i < size - 1; ++i)
		{
			int indexOfMaxElement = i;
			for (int j = i + 1; j < size; ++j)
			{
				if (myStrCmp(facultyNumbers[indexOfMaxElement], facultyNumbers[j]) > 0)
				{
					indexOfMaxElement = j;
				}
			}
			mySwapCharArrays(facultyNumbers[i], facultyNumbers[indexOfMaxElement]);
			mySwapCharArrays(studentsInformation[i], studentsInformation[indexOfMaxElement]);
		}
	}
	else
	{
		for (int i = 0; i < size - 1; ++i)
		{
			int indexOfMinElement = i;
			for (int j = i + 1; j < size; ++j)
			{
				if (myStrCmp(facultyNumbers[indexOfMinElement], facultyNumbers[j]) < 0)
				{
					indexOfMinElement = j;
				}
			}
			mySwapCharArrays(facultyNumbers[i], facultyNumbers[indexOfMinElement]);
			mySwapCharArrays(studentsInformation[i], studentsInformation[indexOfMinElement]);
		}
	}
}

void getAverageSuccess(const std::string fileName, double* averageSuccesses, const int linesCount)
{
	std::fstream groupFile;
	groupFile.open(fileName, std::ios::in);
	if (groupFile.is_open())
	{
		for (int i = 0; i < linesCount; ++i)
		{
			char name[25];
			char secondName[30];
			char lastName[35];
			char facultyNumber[7];
			groupFile >> name >> secondName >> lastName >> facultyNumber;

			std::string line;
			getline(groupFile, line);
			std::stringstream helper(line);

			char discipline[15];
			double sum = 0;
			double count = 0;
			double grade = 0;
			while (helper >> discipline >> grade)
			{
				sum += grade;
				++count;
			}
			averageSuccesses[i] = sum / count;
		}
		groupFile.close();
	}
}

void rememberInformationFromFile(const std::string fileName, char** studentsInformation, const int linesCount)
{
	std::fstream groupFile;
	groupFile.open(fileName, std::ios::in);
	if (groupFile.is_open())
	{
		for (int i = 0; i < linesCount; ++i)
		{
			groupFile.getline(studentsInformation[i], 200);
		}
		groupFile.close();
	}
}

void rememberFacultyNumbersAndInformationFromFile(const std::string fileName, char** studentsInformation, char** facultyNumbers, const int linesCount)
{
	std::fstream groupFile;
	groupFile.open(fileName, std::ios::in);
	if (groupFile.is_open())
	{
		for (int i = 0; i < linesCount; ++i)
		{
			groupFile.getline(studentsInformation[i], 200);
			getFacultyNumber(studentsInformation[i], facultyNumbers[i]);
		}
		groupFile.close();
	}
}

void sortInformationByAverageSuccesses(double* averageSuccesses, char** studentsInformation, const int size, const char wayToSort)
{
	if (wayToSort == 'a')
	{
		for (int i = 0; i < size - 1; ++i)
		{
			int indexOfMinElement = i;
			for (int j = i + 1; j < size; ++j)
			{
				if (averageSuccesses[j] < averageSuccesses[indexOfMinElement])
				{
					indexOfMinElement = j;
				}
			}
			mySwapDoubleArrays(averageSuccesses[i], averageSuccesses[indexOfMinElement]);
			mySwapCharArrays(studentsInformation[i], studentsInformation[indexOfMinElement]);
		}
	}
	else
	{
		for (int i = 0; i < size - 1; ++i)
		{
			int indexOfMaxElement = i;
			for (int j = i + 1; j < size; ++j)
			{
				if (averageSuccesses[j] > averageSuccesses[indexOfMaxElement])
				{
					indexOfMaxElement = j;
				}
			}
			mySwapDoubleArrays(averageSuccesses[i], averageSuccesses[indexOfMaxElement]);
			mySwapCharArrays(studentsInformation[i], studentsInformation[indexOfMaxElement]);
		}
	}
}


void sortByAverageSuccess(const int group, const char wayToSort)
{
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

	int linesCount = getLinesCount(fileName);
	char** studentsInformation = new char* [linesCount];
	double* averageSuccesses = new double[linesCount];
	for (int i = 0; i < linesCount; ++i)
	{
		studentsInformation[i] = new char[200];
	}

	getAverageSuccess(fileName, averageSuccesses, linesCount);
	rememberInformationFromFile(fileName, studentsInformation, linesCount);
	sortInformationByAverageSuccesses(averageSuccesses, studentsInformation, linesCount, wayToSort);

	std::fstream groupFile;
	groupFile.open(fileName, std::ios::out);
	if (groupFile.is_open())
	{
		for (int i = 0; i < linesCount; ++i)
		{
			for (int j = 0; studentsInformation[i][j] != '\0'; ++j)
			{
				groupFile << studentsInformation[i][j];
			}
			groupFile << std::endl;
		}
		groupFile.close();
	}

	for (int i = 0; i < linesCount; ++i)
	{
		delete[]studentsInformation[i];
	}
	delete[]studentsInformation;
	delete[]averageSuccesses;
}

void sortByFacultyNumber(const int group, const char wayToSort)
{
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

	int linesCount = getLinesCount(fileName);
	char** studentsInformation = new char* [linesCount];
	char** facultyNumbers = new char* [linesCount];
	for (int i = 0; i < linesCount; ++i)
	{
		studentsInformation[i] = new char[200];
		facultyNumbers[i] = new char[7];
	}

	rememberFacultyNumbersAndInformationFromFile(fileName, studentsInformation, facultyNumbers, linesCount);
	selectionSortFacultyNumbers(facultyNumbers, studentsInformation, linesCount, wayToSort);

	std::fstream groupFile;
	groupFile.open(fileName, std::ios::out);
	if (groupFile.is_open())
	{
		for (int i = 0; i < linesCount; ++i)
		{
			for (int j = 0; studentsInformation[i][j] != '\0'; ++j)
			{
				groupFile << studentsInformation[i][j];
			}
			groupFile << std::endl;
		}
		groupFile.close();
	}

	for (int i = 0; i < linesCount; ++i)
	{
		delete[]studentsInformation[i];
		delete[]facultyNumbers[i];
	}
	delete[]studentsInformation;
	delete[]facultyNumbers;
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
		sortByAverageSuccess(group, wayToSort);
		break;
	case 'f':
		sortByFacultyNumber(group, wayToSort);
		break;
	}

	groupMenu(group);
}

void printStudents(const int group)
{
	std::cout << "List of students in " << group << " group: " << std::endl << std::endl;

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
	groupFile.open(fileName, std::ios::in);
	if (groupFile.is_open())
	{
		char line[100];
		while (groupFile.getline(line, 100))
		{
			std::cout << line << std::endl;
		}
		std::cout << std::endl;

		groupFile.close();
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

int getLinesCountFromVariousGroupsAndRememberInformation(const int groupsCount, const int* groups, char** studentsInformation, char** facultyNumbers, double* averageSuccesses)
{
	int index = 0;
	for (int i = 0; i < groupsCount; ++i)
	{
		std::string fileName;
		switch (groups[i])
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

		int linesCount = getLinesCount(fileName);
		char** tempStudentsInformation = new char* [linesCount];
		double* tempAverageSuccesses = new double[linesCount];
		for (int i = 0; i < linesCount; ++i)
		{
			tempStudentsInformation[i] = new char[250];
		}

		getAverageSuccess(fileName, tempAverageSuccesses, linesCount);
		rememberInformationFromFile(fileName, tempStudentsInformation, linesCount);

		for (int i = 0; i < linesCount; ++i)
		{
			getFacultyNumber(tempStudentsInformation[i], facultyNumbers[index]);
			averageSuccesses[index] = tempAverageSuccesses[i];

			int j = 0;
			for (; tempStudentsInformation[i][j] != '\0'; ++j)
			{
				studentsInformation[index][j] = tempStudentsInformation[i][j];
			}
			studentsInformation[index][j] = '\0';
			++index;
		}

		for (int i = 0; i < linesCount; ++i)
		{
			delete[]tempStudentsInformation[i];
		}
		delete[]tempStudentsInformation;
		delete[]tempAverageSuccesses;
	}
	return index;
}

void printStudentsFromVariousGroups()
{
	std::cout << "Please, enter the count of the groups: ";
	int n;
	std::cin >> n;
	std::cout << std::endl;

	std::cout << "Enter groups (please enter the numbers of the groups separated by spaces): ";
	int* groups = new int[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> groups[i];
	}
	std::cout << std::endl;

	std::cout << "Sort by average success or faculty number (please write 'a' for average success and 'f' for faculty number): ";
	char sortBy;
	std::cin >> sortBy;
	std::cout << std::endl;

	std::cout << "Sort in ascending/descending order (please write 'a' for ASC and 'd' for DESC): ";
	char wayToSort;
	std::cin >> wayToSort;
	std::cout << std::endl;

	char** studentsInformation = new char* [200];
	char** facultyNumbers = new char* [200];
	double* averageSuccesses = new double[200];
	for (int i = 0; i < 200; ++i)
	{
		studentsInformation[i] = new char[250];
		facultyNumbers[i] = new char[7];
	}

	int allFilesLinesCount = getLinesCountFromVariousGroupsAndRememberInformation(n, groups, studentsInformation, facultyNumbers, averageSuccesses);

	switch (sortBy)
	{
	case 'a':
		sortInformationByAverageSuccesses(averageSuccesses, studentsInformation, allFilesLinesCount, wayToSort);
		break;
	case 'f':
		selectionSortFacultyNumbers(facultyNumbers, studentsInformation, allFilesLinesCount, wayToSort);
		break;
	}

	for (int i = 0; i < allFilesLinesCount; ++i)
	{
		for (int j = 0; studentsInformation[i][j] != '\0'; ++j)
		{
			std::cout << studentsInformation[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < allFilesLinesCount; ++i)
	{
		delete[]studentsInformation[i];

		if (i < 7)
		{
			delete[]facultyNumbers[i];
		}
	}
	delete[]studentsInformation;
	delete[]facultyNumbers;
	delete[]averageSuccesses;
	delete[]groups;

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