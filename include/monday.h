using namespace std;

void fahrenheitCentigradeConversion(void) {
	string inputString;

	while (inputString != "quit")
	{
		int temperature;

		cout << "Please enter the starting temperature" << endl;
		cin >> inputString;
		temperature = stof(inputString);

		cout << "\nPress C to convert from Fahrenheit to Celcius" << endl;
		cout << "Press F to convert from Celcius to Fahrenheit" << endl;
		cin >> inputString;

		cout << temperature;
	}
}


void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

