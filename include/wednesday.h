struct details
{
	string s_name;
	string s_no;
};

details splitString(string textToSplit);
void findItem(vector<details> items, string itemToFind);


void phoneDirectory(void) 
{
  string line;
	vector<details> directory;
	ifstream fileObject;

	fileObject.open("phonebook.csv");
	while (!fileObject.eof())
	{
		getline(fileObject, line);
		directory.push_back(splitDirectoryString(line));
	}
	fileObject.close();

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

details splitString(string textToSplit)
{
	details entry;
	string delimiter = ",";

	entry.s_name = textToSplit.substr(0, textToSplit.find(delimiter));
	entry.s_no = textToSplit.substr(textToSplit.find(delimiter) + 1, textToSplit.size());
	cout << entry.s_name << " " << entry.s_no << endl;

	return entry;
}



void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
  //setw function for string fields 
}