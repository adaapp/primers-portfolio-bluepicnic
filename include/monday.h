using namespace std;

float convertToCelcius(float numToConvert)
{
	return (numToConvert - 32) * 5 / 9;
}

float convertToFahrenheit(float numToConvert)
{
	return (numToConvert * 9 / 5) + 32;
}

void fahrenheitCentigradeConversion(void)
{
	
	string inputString;

	while (inputString != "quit")
	{
		string inputString;
		float temperature, result;

		do //looping for ease of use
		{
			cout << "\nPlease enter the starting temperature ";
			cin >> inputString;
			temperature = stof(inputString); //stof will try to cast to float, but will throw an exception if unable to do

			cout << "Press 'C' to convert from Fahrenheit to Celcius" << endl;
			cout << "Press 'F' to convert from Celcius to Fahrenheit" << endl;
			cout << "\nYour Choice: ";
      cin >> inputString;

			if (inputString.compare("c") == 0 || inputString.compare("C") == 0) {//"compare" string function returns an integer. If 0, the strings match.
				result = convertToCelcius(temperature);
				cout << temperature << " degrees Fahrenheit is " << result << endl;
			}
			else if (inputString.compare("f") == 0 || inputString.compare("F") == 0) { //"compare" string function returns an integer. If 0, the strings match.
				result = convertToFahrenheit(temperature);
				cout << temperature << " degrees Celcius is " << result << endl;
			}
		} while (inputString != "quit");
	}
}


void selfServiceCheckout(void) {
  string inputString;
	float subtotal, itemPrice;
  int itemQuantity, itemNo = 1;
  const float shoppingTax = 5.5;
  
  do{
    cout << "Please enter a quantity for item " itemNo << " (or 0 to finish): ";
    cin >> inputString;
    itemQuantity = stoi(inputString);

    cout << "Please enter item " << itemNo << "'s cost:";
    cin >>inputString;
    itemPrice = stof(inputString);

  }while(itemQuantity >= 0)
  
}

