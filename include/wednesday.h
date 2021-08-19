struct details
{
	string s_name;
	string s_no;
};

vector<string> splitString(string textToSplit);
void findItem(vector<details> items, string itemToFind);


void phoneDirectory(void) 
{
  string line;
	vector<details> directory;
	vector<string> separatedItems;
	ifstream fileObject;
	details combinedDetails;

	fileObject.open("phonebook.csv");
	while (!fileObject.eof())
	{
		getline(fileObject, line);
		separatedItems = splitString(line);

		combinedDetails.s_name = separatedItems[0];
		combinedDetails.s_no = separatedItems[1];
		directory.push_back(combinedDetails);
	}

	while (line != "quit")
	{
		cout << "\nPlease enter a name or number to search: ";
		getline(cin, line);
		cout << "\nSearching " << directory.size() << " records" << endl;
		findItem(directory, line);
	}

	//open file 
	//read data -> string line in the format xxxx, yyyyy
	//close file

	//function - takes a string
	//split into two separate strings
	//return both

	//watch for whitespace at start and end
	//find first instance of a letter or number depending on the string

	//get string from user, search xxxx or yyyy based on input
}

vector<string> splitString(string textToSplit)
{
	vector<string> entry;
	string delimiter = ",";
	size_t found = textToSplit.find(delimiter); 
	
	//for first delimeter do found - found 
	//then go from delimiter to delimiter as necessary
	//then once found is npos go from last delimiter (found) to string size
	entry.push_back(textToSplit.substr(found - found, textToSplit.find(delimiter)));
	while (found != string::npos)
	{
		entry.push_back(textToSplit.substr(found + 1, textToSplit.find(delimiter, found + 1) - found - 1)); //extract from the string, starting at the last recorded delimiter location, every character found before another delimiter 
		//minus 1 to not include the delimiter itself.
		found = textToSplit.find(delimiter, found + 1); 
	}
	entry.push_back(textToSplit.substr(textToSplit.find(delimiter, found + 1), textToSplit.size())); //find final delimiter 
	return entry;
}

void findItem(vector<details> items, string itemToFind)
{
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (it->s_name == itemToFind || it->s_no == itemToFind)
		{
			cout << "\nContact details:" << endl;
			cout << it->s_name << ", T: " << it->s_no << endl;
			return;
		}
	}
	cout << "\nSorry, no contact details found" << endl;
	return;
}

struct salaryIndicies
{
	string s_initial;
	string s_surname;
  string s_salary;
};

void dataFileParser(void) {
	string line;
	vector<salaryIndicies> listSalaries;
	vector<string> separatedSalaryInfo;
	ifstream fileObject;
	salaryIndicies combinedSalaryInfo;

	fileObject.open("salaryList.csv");
	while (!fileObject.eof())
	{
		getline(fileObject, line);
		separatedSalaryInfo = splitString(line);

		combinedSalaryInfo.s_initial = separatedSalaryInfo[0].substr(0, 1) + ".";
		combinedSalaryInfo.s_surname = separatedSalaryInfo[1];
		combinedSalaryInfo.s_salary = separatedSalaryInfo[2];
		listSalaries.push_back(combinedSalaryInfo);
	}

	for (auto it = listSalaries.begin(); it != listSalaries.end(); ++it)
	{
		cout << it->s_initial << " " << it->s_surname << " " << it->s_salary << endl;
	}
	//setw function for string fields 
}