using namespace std;

const float shoppingTax = 5.5; // for use with the self-service checkout 

/*Temperature conversion functions*/
float convertToCelsius(float numToConvert);
float convertToFahrenheit(float numToConvert);
float convertToKelvin(float numToConvert, string convertingFrom);
float convertFromKelvin(float numToConvert, string convertingFrom);
bool checkUnit(float temp, string inputString);


/*Self-Service checkout functions*/
void calculateTotal(float runningTotal);
bool checkPrice(float &price);

void fahrenheitCentigradeConversion(void)
{
	string inputString;
  float temperature = 0;
  bool validUnit = false;

  do //looping for ease of use
  {
    cout << "\nPlease enter the starting temperature (or type 'quit'): ";
    getline(cin, inputString);

      stringstream tempInput(inputString);
      validUnit = false;

      //check if we can store the stringstream in the temperature (int) variable, and ensure no characters other than numbers are present
      if(tempInput >> temperature && inputString.find_first_not_of("0123456789") == string::npos) 
      {
        while(validUnit == false)
        {
          cout << "Press 'C' to convert from Fahrenheit to Celsius" << endl;
          cout << "Press 'F' to convert from Celsius to Fahrenheit" << endl;
          /*Additional input strings included to push for further functionality*/
          cout << "Press 'FK' to convert from Fahrenheit to Kelvin" << endl;
          cout << "Press 'CK' to convert from Celsius to Kelvin" << endl;
          cout << "Press 'KF' to convert from Kelvin to Fahrenheit" << endl;
          cout << "Press 'KC' to convert from Kelvin to Celsius" << endl;
          cout << "\nYour Choice: ";
          
          getline(cin, inputString);
          validUnit = checkUnit(temperature, inputString);
        }
      }

      else if(inputString != "quit") //only display error message if the user is not trying to quit
      {
        cout << "\nPlease enter a valid temperature" << endl;
      }
  } while (inputString != "quit");
}

float convertToCelsius(float numToConvert)
{
	return (numToConvert - 32) * 5 / 9;
}

float convertToFahrenheit(float numToConvert)
{
	return (numToConvert * 9 / 5) + 32;
}

float convertToKelvin(float numToConvert, string convertingFrom)
{
  //convert to Kelvin from Fahrenheit, if the input string reflects that
  if(convertingFrom[0] == 'f' || convertingFrom[0] == 'F')
  {
    return (numToConvert - 32) * 5/9 + 273.15;
  }
  //convert to Celsius from Fahrenheit, if the input string reflects that
  else if (convertingFrom[0] == 'c' || convertingFrom[0] == 'C')
  {
    return numToConvert + 273.15;
  }

  return -1.0;
}

float convertFromKelvin(float numToConvert, string convertingTo)
{
  //convert from Kelvin to Fahrenheit, if the input string reflects that
  if(convertingTo[1] == 'f' || convertingTo[1] == 'F')
  {
    return (numToConvert - 273.15) * 9/5 + 32;
  }
  
  //convert from Kelvin to Celsius, if the input string reflects that
  else if (convertingTo[1] == 'c' || convertingTo[1] == 'C')
  {
    return numToConvert - 273.15;
  }
  
  return -1.0;
}

bool checkUnit(float temp, string inputString)
{
  float result;
  if (inputString.compare("c") == 0 || inputString.compare("C") == 0) 
  //"compare" string function returns an integer. If 0, the strings match.
  {
    result = convertToCelsius(temp);
    cout << temp << " degrees Fahrenheit is " << result << endl;
      return true;
  }

  //Convert starting temperature to Fahrenheit if input is 'f' or 'F'
  else if (inputString.compare("f") == 0 || inputString.compare("F") == 0) 
  { 
    result = convertToFahrenheit(temp);
    cout << temp << " degrees Celsius is " << result << endl;
    return true;
  }

  //convert Fahrenheit to Kelvin if FK or fk is selected
  else if (inputString.compare("fk") == 0 || inputString.compare("FK") == 0)
  { 
    result = convertToKelvin(temp, inputString);
    cout << temp << " degrees Fahrenheit is " << result << endl;
    return true;
  }

  //convert Celsius to Kelvin if CK or ck is selected
  else if (inputString.compare("ck") == 0 || inputString.compare("CK") == 0)
  {
    result = convertToKelvin(temp, inputString);
    cout << temp << " degrees Celsius is " << result << endl;
    return true;
  }

  //convert Kelvin to either Celsius or Fahrenheit, depending on input
  else if ((inputString.compare("kf") == 0 || inputString.compare("kf") == 0) ||(inputString.compare("kc") == 0 || inputString.compare("KC") == 0))
  { 
    result = convertFromKelvin(temp, inputString);
    cout << temp << " degrees Kelvin is " << result << endl;
    return true;
  }

  //if any of the above strings are not found, then the user is not requesting a valid coversion
  else
  {
    cout << "\nPlease enter a valid unit to convert" << endl;
    return false;
  }
}

void selfServiceCheckout(void) {
	string inputString;
	float subtotal = 0, itemPrice = 0;
	int itemQuantity = 1, itemNo = 1;
	vector<float> previousPrices; //For extra functionality, track previous item prices to remove from the subtotal
  bool validPrice;

	while (itemQuantity > 0)
	{
    validPrice = false; //set this variable's value here to ensure that it is reset for each item to check that the price input is valid
		cout << "\nPlease enter a quantity for item " << itemNo << " (enter 0 to finish, or 'R' to remove the cost of the previous item(s) from the subtotal): ";
		getline(cin, inputString);
		stringstream quantityInput(inputString); //use stringstream to safely pass a string into the item quantity variable

		if (inputString.find_first_not_of("0123456789.-") == string::npos)
		{
      quantityInput >> itemQuantity;
			if (itemQuantity > 0) 
			{
        while (validPrice == false)
        {
          cout << "Please enter item " << itemNo << "'s cost: ";
          validPrice = checkPrice(itemPrice);
        }
        previousPrices.push_back(itemPrice * itemQuantity);
        itemNo++;
        subtotal += (itemPrice * itemQuantity);
        
			}
		}

		else if (inputString.compare("r") == 0 || inputString.compare("R") == 0)
		{
			if (previousPrices.size() == 0)
			{
				cout << "\nNo items have been recorded yet" << endl;
				itemQuantity = 1; //make sure the loop does not exit, an invalid stringstream will still set an int variable to 0
			}

			else
			{
				subtotal -= previousPrices.back(); //remove the most recently added item from the previous item list, and subtract it from the subtotal
				previousPrices.pop_back();

				cout << "Item " << itemNo - 1 << " removed." << endl;
				itemNo--; //minus one from the current item number to reflect the removal of the most recently added item
				itemQuantity = 1; //make sure the loop does not exit, an invalid stringstream will still set an int variable to 0
			}
		}

		else
		{
      cout << "Please enter a valid item quantity" << endl;
      itemQuantity = 1; //make sure the loop does not exit, an invalid stringstream will still set an int variable to 0
		}
	}
  cout << "Thank you." << endl;
	cout << "\nSubtotal: " << subtotal << endl;
  calculateTotal(subtotal);
}

void calculateTotal(float runningTotal)
{
  float total = 0.0, tax = 0.0;

  //calculate tax from current subtotal
	tax = runningTotal * (shoppingTax / 100);
	cout << "Shopping Tax: ";
  cout << fixed << setprecision(2) << "£" << tax << endl;

	//calculate total from shopping tax and subtotal
	total = runningTotal + tax;
	cout << "\nTotal: ";
	cout << fixed << setprecision(2) << "£" << total; //used from iomanip library
}


  bool checkPrice(float &price)
  {
    string input = "";
    getline(cin, input);
    stringstream priceInput(input);

    if (input.find_first_not_of("0123456789.") == string::npos)
    {
      priceInput >> price;
      return true;
    }

    else
    {
      cout << "\nPlease enter a valid price" << endl;
      return false;
    }
  }
  