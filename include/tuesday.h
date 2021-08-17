using namespace std;

void countCharTypes(int &letters, int &numbers, int &specials, string password)
{
  for (auto it = password.cbegin(); it != password.cend(); ++it)
  {
      if((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122))//check for letters using ASCII codes
      {
        letters++;
      } 

      else if(*it >= 48 && *it <= 57)//check for numbers using ASCII codes
      {
        numbers++;
      } 
      else if((*it >= 33 && *it <= 47) || (*it >= 58 && *it <= 64) || (*it >= 91 && *it <= 96)) //check for special characters using ASCII codes
      {
        specials++;
      }
      
  }
}

int checkPassword(string password)
{
  int passStrengthScore = 0;
  int letterCount = 0, numCount = 0, specialCount = 0;

  size_t numbersFound = password.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
  size_t lettersFound = password.find_first_not_of("1234567890 ");

  countCharTypes(letterCount, numCount, specialCount, password); //pass character counts by reference to change original values

  if(numbersFound == string::npos || lettersFound == string::npos) //What if length < 3?
  {
    passStrengthScore = 1;
  }
  else if(password.length() >= 8 && letterCount >= 4 && numCount >= 2 && specialCount >= 1) 
  {
    passStrengthScore = 4;
  }
  else if(password.length() >= 8 && letterCount >= 4 && numCount >= 2)
  {
    passStrengthScore = 3;
  }
  else if(password.length() >= 4 && passStrengthScore != 1 && passStrengthScore < 3)
  {
    passStrengthScore = 2;
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
		default:
			break;
	}
  cout << "\nThe password '" << inputString << "' is " << passwordStrength << endl;
}




void employeeListRemoval(void) 
{
	string employeeNames [20];
  
}
