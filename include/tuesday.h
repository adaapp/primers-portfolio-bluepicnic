using namespace std;

/*Function definitions for the password complexity checker*/
int checkPassword(string password);
void countCharTypes(int &letters, int &numbers, int &specials, string password);

/*Function definitions for the employee list*/
int findEmployeeIndex(vector <string> listEmployees, string employeeToFind);
void addNewEmployee(vector<string> &listEmployees);



void countCharTypes(int &letters, int &numbers, int &specials, string password)
{
  for (auto it = password.cbegin(); it != password.cend(); ++it)
  {
      if((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122))//check for letters (capital and lower case) using their respective ASCII codes
      {
        letters++;
      } 

      else if(*it >= 48 && *it <= 57)//check for numbers using ASCII codes
      {
        numbers++;
      } 
      else if((*it >= 32 && *it <= 47) || (*it >= 58 && *it <= 64) || (*it >= 91 && *it <= 96)) //check for special characters (including spaces) using ASCII codes
      {
        specials++;
      }
      
  }
}

int checkPassword(string password)
{
  int passStrengthScore = 0;
  int letterCount = 0, numCount = 0, specialCount = 0;

  countCharTypes(letterCount, numCount, specialCount, password); //pass character counts by reference to change original values

  if((password.size() == letterCount || password.size() == numCount || password.size() == specialCount) && password.size() != 0) //check if count of characters OF EACH TYPE is equal to length of password
  {
    passStrengthScore = 1; //weak password
  }
  else if(password.length() >= 8 && letterCount >= 4 && numCount >= 2 && specialCount >= 1) //check if password is long enough and has enough of each character time
  {
    passStrengthScore = 4; //very strong password
  }
  else if(password.length() >= 8 && letterCount >= 4 && numCount >= 2)
  {
    passStrengthScore = 3; //strong password
  }
  else if(password.length() >= 4 && passStrengthScore != 1 && passStrengthScore < 3)
  { //so long as the password is long enough, and none of the other criteria are met
    passStrengthScore = 2; //Moderate password
  }

  return passStrengthScore;
}

void passwordComplexityChecker(void) 
{
	string inputString, passwordStrength;
  
  getline(cin, inputString); //get the whole line, including spaces
  
  int score = checkPassword(inputString);
  
  //Don't return string values from function, assign values from returned int
  switch (score)
  {
    case 1:
      passwordStrength = "Weak";
      break;
    case 2:
      passwordStrength = "Moderate";
      break;
    case 3:
      passwordStrength = "Strong";
      break;
    case 4: 
      passwordStrength = "Very Strong";
      break;
		default: //this should only happen if password length is less than 3 and all characters are not of the same type, otherwise it will be a Moderate password
      passwordStrength = "Too Short";
			break;
	}
  cout << "\nThe password '" << inputString << "' is " << passwordStrength << endl;

  if (passwordStrength == "Too Short") 
  {
    cout << "Please input a password with more than 3 characters" << endl;
  }
}


void employeeListRemoval(void) 
{
  string inputString;
	vector <string> employeeNames = {"John Smith", "Jaelynn Stuart", "Kaley Barajas", "Walter Collier", "Cale Myers"}; //do we want to add to the array?
  int index = 0;

  while(inputString != "0")
  {
    cout << "\nThere are " << employeeNames.size() << " employees." << endl;

    for (auto it = employeeNames.begin(); it != employeeNames.end(); ++it) //go through the list and display all the names currently inside 
    {
      cout << *it << endl;
    }

    cout << "\nEnter an employee name to remove ('+1' to add a new employee, or 0 to quit): ";
    getline(cin, inputString);

    if(inputString == "+1")
    {
      addNewEmployee(employeeNames);
    }
    else if(inputString != "0")
    {
      vector<string>::iterator it; //define an iterator to search the input string, has direct access to the memory of the object, rather than accessing single elements
      it = find(employeeNames.begin(), employeeNames.end(), inputString); //search for input
      if (it == employeeNames.end()) //find function returns the last searched element if the supplied item is not found
      {
        cout << "\nEmployee not found" << endl;
      }
      else
      {
        employeeNames.erase(it); //can erase directly using "it" since it has the memory address of the found element stored
      }
    }
  }
}

void addNewEmployee(vector <string> &listEmployees)
{
  string newEmployee;

  do
  {
      cout << "\nPlease enter a name to add" << endl;
      getline(cin, newEmployee);

      if(newEmployee == "+1" || newEmployee.find_first_not_of(" \t\v\r\n") == string::npos) //We don't want the user to enter a name they cannot remove, and +1 is reserved for this scenario where employees are added
      {
        cout << "That name is not valid, please enter a valid name" << endl;
      }
  } while(newEmployee == "+1" || newEmployee.find_first_not_of(" \t\v\r\n") == string::npos);
  listEmployees.push_back(newEmployee);
  
}
