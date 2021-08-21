class Car
{
public:
	Car();
	~Car();
	void set_colour(string colourToSet) { mColour = colourToSet; }
	string get_colour(void) { return mColour; }
	void set_make(string makeToSet) { mMake = makeToSet; }
	string get_make(void) { return mMake; }
	void engine_on(void);
	void engine_off(void);
	void locked(bool isLocked);
	void status(void);

private:
	string mColour;
	string mMake;
	string mEngine;
	bool mLocked;

};

Car::Car()
{
	mColour = " ";
	mMake = " ";
	mEngine = "off";
	mLocked = false;
}

Car::~Car()
{
}

void Car::engine_on(void)
{
	if (mEngine == "off")
	{
		mEngine = "on";
		cout << "Turning the engine " << mEngine << endl;
	}
	else 
	{
		cout << "Sorry, the engine is already " << mEngine<< endl;
	}
}

void Car::engine_off(void)
{
	if (mEngine == "on")
	{
		mEngine = "off";
		cout << "Turning the engine " << mEngine << endl;
	}
	else
	{
		cout << "Sorry, the engine is already " << mEngine << endl;
	}
}

void Car::locked(bool isLocked)
{
	string lockedStatus = (mLocked == 0) ? "Unlocked" : "Locked";
	if (mLocked == isLocked)
	{
		cout << "Sorry, the car is already " << lockedStatus << endl;
	}
	else
	{
		mLocked = isLocked;
		lockedStatus = (mLocked == 0) ? "Unlocking the car" : "Locking the car";
		cout << lockedStatus << endl;
	}
}

void Car::status(void) 
{ 
	string lockedStatus = (mLocked == 0) ? "Unlocked" : "Locked";
	cout << "\nCar Status: " << "colour: " << mColour << ", make: " << mMake << ", engine: " << mEngine << ", " << lockedStatus << endl;
}

void carClass(void) {
		string line;
	int menuSelection = -1;
	
	Car sportsCar;
	sportsCar.set_make("Ford");
	sportsCar.set_colour("Blue");

	while (menuSelection != 0)
	{
		sportsCar.status();
		cout << "1. Turn Engine On" << endl;
		cout << "2. Turn Engine Off" << endl;
		cout << "3. Lock Car" << endl;
		cout << "4. Unlock Car" << endl;
		cout << "Please select an option (1-4, or 0 to finish): ";

		getline(cin, line);
		stringstream input(line);
		if (input >> menuSelection && line.find_first_not_of("0123456789") == string::npos) //can the stringstream extract any input and place it into the int variable? & can anything other than a number be found??
		{
			switch (menuSelection)
			{
			case 1: //turn engine on
				sportsCar.engine_on();
				break;
			case 2: //turn engine off
				sportsCar.engine_off();
				break;
			case 3: //lock car
				sportsCar.locked(1);
				break;
			case 4: //unlock car
				sportsCar.locked(0);
				break;
			case 0:
				break;
			default:
				cout << "Please enter a valid value" << endl;
				break;
			}
		}
		else
		{
			menuSelection = -1;
			cout << "Please enter a valid value" << endl;
		}
	}
}

class AreaOf
{
  public:
  float size(float radius) { return PI * (radius * radius); } //Area of a circle
  float size(float width, float length) { return width * length; } //area of a rectangle
  float size(float base, float height, float baseTop) { return ((base + baseTop) / bases) * height;} //area of a trapezoid

  private:
  const float PI = 3.14159;
  const int bases = 2;

};

void areaOf(void) {
	  AreaOf circle;
    AreaOf rectangle;
    AreaOf trapezoid;

    float radius = 4.5;
    float width = 4, length = 5.9;
    float baseB = 14, height = 7.5, baseA = 6;
    
    cout << "Area of Circle (r = " << radius << "): " <<  circle.size(radius) << endl;
    cout << "Area of Rectangle (w = " << width << ", l = " <<  length << "): " << rectangle.size(width, length) << endl;
    cout << "Area of Rectangle (b = " << baseB << ", h = " <<  height << ", a = " << baseA << "): " << trapezoid.size(baseB, height, baseA) << endl;
}