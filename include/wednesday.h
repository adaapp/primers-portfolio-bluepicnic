/*Definition of details structure for use in the phone directory primer*/
struct details
{
	string s_name;
	string s_no;
};

/*Definition of the salaryIndicies structure for use in the phoneDirectory primer*/
struct salaryIndicies
{
	string s_initial;
	string s_surname;
	string s_salary;
};

/*definition of constant variables for the date file parser*/
const int initialIndex = 0, surnameIndex = 1, salaryIndex = 2, buffer = 5; //variables are global to avoid having to pass them as parameters to functions

/*defintiion of functions for the phone directory*/
void findItem(vector<details> items, string itemToFind);

/*defintiion of functions for the data file parser*/
void getMaxFieldWidth(int &currentWidth, string field);
void saveToFile(int sizes[], vector<salaryIndicies> list);
void displayRecords(int sizes[], vector<salaryIndicies> list);

/*Definition of generic functions*/
void removeLeadTrailSpaces(string &stringToChange);
bool fileExists(string file);

void phoneDirectory(void) {
	string line, entry;
	vector<details> directory;
	ifstream fileObject;
	details combinedDetails;
  string fileName = "phonebook.csv";

	//check if file exists
  bool isFile = fileExists(fileName);
  if(isFile == true)
  {
    ifstream file(fileName);
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
      cout << "Please enter a name or number to search (or type 'quit'): ";
      getline(cin, line);
      cout << "\nSearching " << directory.size() << " records" << endl;
      findItem(directory, line);
    }
  }

  else
  {
    cout << "\nFile not found :(" << endl;
  }
	
}

void findItem(vector<details> items, string itemToFind)
{
	int foundCount = 0;
	//this function will find and display more than one item per the input, if it exists
  //the find function from <algorithm> will only find the first instance, so unsuitable for this
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

void dataFileParser(void) {
	string line, entry;
	vector<salaryIndicies> listSalaries; //to store each person's data set
	salaryIndicies combinedSalaryInfo;
	int fieldSizes[3]{ 8, 0, 0 };
  string inFile = "salaryList.csv";
	
	//if(filename == exists)
  bool isFile = fileExists(inFile); 
  if (isFile == true)
  {
    ifstream fileObject(inFile);
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

    displayRecords(fieldSizes, listSalaries);
    saveToFile(fieldSizes, listSalaries);
  }

  else
  {
    cout << "\nFile not found :(" << endl;
  }
}

/*Function implementations for dataFileParser*/

void getMaxFieldWidth(int &currentWidth, string field)
{
	if (field.size() > currentWidth)
	{
		currentWidth = field.size() + 1;
	}

}

void saveToFile(int sizes[], vector<salaryIndicies> list)
{
  string outFile  = "salaryList.txt";
  ofstream salaryFile (outFile);
  if (salaryFile.is_open())
  {
    //repeated to ensure that file output is identical to that displayed in the console
    salaryFile << left << setw(sizes[initialIndex]) << "Initial" << setw(sizes[surnameIndex] + buffer) << "Last" << setw(sizes[salaryIndex]) << "Salary" << endl;

	  salaryFile << setw(sizes[initialIndex]) << "--------" << setw(sizes[surnameIndex] + buffer) << "----------" << setw(sizes[salaryIndex]) << "-------" << endl;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
      salaryFile << setw(sizes[initialIndex]) << it->s_initial;
      salaryFile << setw(sizes[surnameIndex] + buffer) << it->s_surname;
      salaryFile << left << it->s_salary;
      salaryFile << endl;
    }

    salaryFile.close();
  }
  else cout << "Unable to open file";
}

void displayRecords(int widths[], vector<salaryIndicies> records)
{
  cout << left << setw(widths[initialIndex]) << "Initial" << setw(widths[surnameIndex] + buffer) << "Last" << setw(widths[salaryIndex]) << "Salary" << endl;

	cout << setw(widths[initialIndex]) << "--------" << setw(widths[surnameIndex] + buffer) << "----------" << setw(widths[salaryIndex]) << "-------" << endl;

	for (auto it = records.begin(); it != records.end(); ++it)
	{
    //setw function for string fields 
		cout << setw(widths[initialIndex]) << it->s_initial;
		cout << setw(widths[surnameIndex] + buffer) << it->s_surname;
		cout << left << it->s_salary;
		cout << endl;
	}
}

/*Generic function implementation*/
void removeLeadTrailSpaces(string &stringToChange)
{
  //find the first and last instance of anything that generates whitespace
	size_t firstChar = stringToChange.find_first_not_of(" \t\v\r\n"); 
	size_t lastChar = stringToChange.find_last_not_of(" \t\v\r\n");
	stringToChange = stringToChange.substr(firstChar, lastChar - firstChar + 1);
}

bool fileExists(string file)
{
  struct stat buf;
  if(stat(file.c_str(), &buf) == 0)
  {
    return true; 
  }
  return false;
}

