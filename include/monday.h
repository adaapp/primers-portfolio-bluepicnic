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
			temperature = stof(inputString); //stof will try to cast to float, but will throw an exception if unable to do so

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
	float subtotal, total, itemPrice;
  int itemQuantity, itemNo = 1;
  const float shoppingTax = 5.5;
  
  do{
    cout << "\nPlease enter a quantity for item " << itemNo << " (or 0 to finish): ";
    cin >> inputString;
    itemQuantity = stoi(inputString); //type cast to int from string, will throw exception if unable to do so (this includes floating point values)
    if (itemQuantity < 1) break;

    cout << "Please enter item " << itemNo << "'s cost: ";
    cin >> inputString;
    itemPrice = stof(inputString);

    itemNo++;
    subtotal += (itemPrice * itemQuantity);
    
  }while(itemQuantity != 0);
  
  cout << "Thank you." << endl;

  cout << "\n Subtotal: " << subtotal << endl;
  cout << "Shopping Tax: " << shoppingTax << endl;

  //calculate total from shopping tax
  total = subtotal * (shoppingTax / 100);
  cout << "\n Total: " << total;
}

