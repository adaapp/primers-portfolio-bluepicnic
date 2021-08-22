struct details
{
	string s_name;
	string s_no;
};

struct salaryIndicies
{
	string s_initial;
	string s_surname;
	string s_salary;
};

void removeLeadTrailSpaces(string &stringToChange);
void phoneDirectory(void);
void findItem(vector<details> items, string itemToFind);
void dataFileParser(void);
void getMaxFieldWidth(int &currentWidth, string field);


void phoneDirectory(void) {
	string line, entry;
	vector<details> directory;
	ifstream fileObject;
	details combinedDetails;

	//check if file exists
	ifstream file("phonebook.csv");
	while (getline(file, line))
	{
		stringstream stream(line);
		int i = 0;
		vector<string> separatedItems;
		while (getline(stream, entry, ','))
		{
			removeLeadTrailSpaces(entry);
			separatedItems.push_back(entry);
			i++;
		}
		if (separatedItems[0][0] != 0 && separatedItems[1][0] != 0)//check that the first character of either separated item is not NULL (ascii code 0) (in the case of a rogue carridge return at the end of the file)
		{
			
			combinedDetails.s_name = separatedItems[0];
			combinedDetails.s_no = separatedItems[1];
			directory.push_back(combinedDetails);
		}
	}
	fileObject.close();

	while (line != "quit")
	{
		cout << "Please enter a name or number to search: ";
		getline(cin, line);
		cout << "\nSearching " << directory.size() << " records" << endl;
		findItem(directory, line);
	}

}

void findItem(vector<details> items, string itemToFind)
{
	int foundCount = 0;
	//refactor to find more than one
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (it->s_name == itemToFind || it->s_no == itemToFind)
		{
			cout << "\nContact details:" << endl;
			cout << it->s_name << ", T: " << it->s_no << endl << endl;
			foundCount++;
		}
	}
	if (foundCount == 0)
	{
		cout << "\nSorry, no contact details found" << endl << endl;
	}
	return;
}

void removeLeadTrailSpaces(string &stringToChange)
{
  //find the first and last instance of anything that generates whitespace
	size_t firstChar = stringToChange.find_first_not_of(" \t\v\r\n"); 
	size_t lastChar = stringToChange.find_last_not_of(" \t\v\r\n");
	stringToChange = stringToChange.substr(firstChar, lastChar - firstChar + 1);
}

void getMaxFieldWidth(int &currentWidth, string field)
{
	if (field.size() > currentWidth)
	{
		currentWidth = field.size() + 1;
	}

}

void dataFileParser(void) {
	string line, entry;
	vector<salaryIndicies> listSalaries; //to store each person's data set
	salaryIndicies combinedSalaryInfo;
	int fieldSizes[3]{ 8, 0, 0 };
	const int initialIndex = 0, surnameIndex = 1, salaryIndex = 2, buffer = 5;

	//if(filename == exists)
	ifstream fileObject("salaryList.csv");
	while (getline(fileObject, line))
	{
		stringstream stream(line);
		int i = 0;
		vector<string> separatedSalaryInfo;
		while (getline(stream, entry, ','))
		{
			getMaxFieldWidth(fieldSizes[i], entry);
			removeLeadTrailSpaces(entry);
			separatedSalaryInfo.push_back(entry);
			i++;
		}
		combinedSalaryInfo.s_initial = separatedSalaryInfo[initialIndex].substr(0, 1) + ".";
		combinedSalaryInfo.s_surname = separatedSalaryInfo[surnameIndex];
		combinedSalaryInfo.s_salary = "£" + separatedSalaryInfo[salaryIndex];
		listSalaries.push_back(combinedSalaryInfo);
	}
	fileObject.close();

	cout << left << setw(fieldSizes[initialIndex]) << "Initial" << setw(fieldSizes[surnameIndex] + buffer) << "Last" << setw(fieldSizes[salaryIndex]) << "Salary" << endl;
	cout << setw(fieldSizes[initialIndex]) << "--------" << setw(fieldSizes[surnameIndex] + buffer) << "----------" << setw(fieldSizes[salaryIndex]) << "--------" << endl;
	for (auto it = listSalaries.begin(); it != listSalaries.end(); ++it)
	{
		cout << setw(fieldSizes[initialIndex]) << it->s_initial;

		cout << setw(fieldSizes[surnameIndex] + buffer) << it->s_surname;

		cout << left << it->s_salary;

		cout << endl;
	}
	//setw function for string fields 
}