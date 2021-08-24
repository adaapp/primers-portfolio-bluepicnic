/*Definition of the Car class*/
class Car
{
public:
  /*Definition of Car class member functions + implementation of pure functions*/
	Car();
	~Car();
	void set_colour(string colourToSet); 
	string get_colour(void) { return mColour; } 
	void set_make(string makeToSet); 
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

/*Definition of the AreaOf class + implementation of pure functions*/
class AreaOf
{
  public:
  void size(float radius) { mArea = PI * (radius * radius); } //Area of a circle
  void size(float width, float length) { mArea = width * length; } //area of a rectangle
  void size(float base, float height, float baseTop) { mArea = ((base + baseTop) / BASES) * height;} //area of a trapezoid

  void displaySize(float radius); //Display function for circle size
  void displaySize(float width, float length); //Display function for rectangle size
  void displaySize(float baseB, float height, float baseA); //display function for trapezoid size

  private:
  const float PI = 3.14159;
  const int BASES = 2;
  float mArea; 

};

/*Non-Class member function definitions for primer 9 */
void displayMenu();
void menuChoice(int choice, Car &vehicle);



/*Car class member function implementation, where implementation requires more than one line (for readability)*/
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

void Car::set_colour(string colourToSet) 
{ 
  //car colour could be anything from an obscure name of a colour to its value in hexidecimal, so we only need to check if the string is blank
  if(colourToSet.find_first_not_of(" \t\v\r\n") != string::npos) 
  {
    mColour = colourToSet;
  }
  else
  {
    cout << "Invalid Input" << endl;
  }
}

void Car::set_make(string makeToSet) 
{ 
  //Car make could also be anything, so no input validation required here either
  if(makeToSet.find_first_not_of(" \t\v\r\n") != string::npos) 
  {
    mMake = makeToSet; 
  }
  else
  {
    cout << "Invalid Input" << endl;
  }
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
	string lockedStatus = (mLocked == 0) ? "Unlocked" : "Locked"; //interchangeable string that represents the locked/unlocked state of the car. If the class variable is 0 the string will equal Unlocked, otherwise, it will equal locked
	if (mLocked == isLocked)
	{
		cout << "Sorry, the car is already " << lockedStatus << endl;
	}
	else
	{
		mLocked = isLocked; //change value based on value passed into function
		lockedStatus = (mLocked == 0) ? "Unlocking the car" : "Locking the car";
		cout << lockedStatus << endl;
	}
}

void Car::status(void) 
{ 
	string lockedStatus = (mLocked == 0) ? "Unlocked" : "Locked"; //interchangeable string that represents the locked/unlocked state of the car. If the class variable is 0 the string will equal Unlocked, otherwise, it will equal locked
	cout << "\nCar Status: " << "colour: " << get_colour() << ", make: " << get_make() << ", engine: " << mEngine << ", " << lockedStatus << endl;
}

/*---------------------END OF CAR CLASS FUNCTION IMPLEMENATIONS----------------------*/

/*AreaOf Class output function implementations*/
void AreaOf::displaySize(float radius) //circle
{
  cout << "Area of Circle (r = " << radius << "): " <<  mArea << endl;
} 

void AreaOf::displaySize(float width, float length) //rectangle
{
  cout << "Area of Rectangle (w = " << width << ", l = " <<  length << "): " << mArea << endl;
}

void AreaOf::displaySize(float baseB, float height, float baseA)
{
  cout << "Area of Rectangle (b = " << baseB << ", h = " <<  height << ", a = " << baseA << "): " << mArea << endl;
}

/*------------------END OF AREAOF CLASS FUNCTION IMPLEMENATIONS--------------------*/

void carClass(void) 
{
	int menuSelection = -1;
	string line;

	Car sportsCar;
	sportsCar.set_make("Ford");
	sportsCar.set_colour("Blue");

	while (menuSelection != 0)
	{
     //string for getline function to use
    
		sportsCar.status();
		displayMenu();

		getline(cin, line); //get input
    stringstream input(line);
		if (input >> menuSelection && line.find_first_not_of("0123456789") == string::npos) //can anything other than a number be found??
		{
      stringstream input(line);
			menuChoice(menuSelection, sportsCar);
		}
		else
		{
			menuSelection = -1; //make sure program does not quit, since setting this variable to 0 would quite the program
			cout << "Please enter a valid value" << endl;
		}
	}
}

void displayMenu()
{
  cout << "1. Turn Engine On" << endl;
  cout << "2. Turn Engine Off" << endl;
  cout << "3. Lock Car" << endl;
  cout << "4. Unlock Car" << endl;
  cout << "5. Set Car Colour" << endl;
  cout << "6. Set Car Make" << endl;
  cout << "Please select an option (1-6, or 0 to finish): ";
}

void menuChoice(int choice, Car &vehicle)
{
  string inputLine;
  switch (choice)
  {
    case 1: //turn engine on
      vehicle.engine_on();
      break;
    case 2: //turn engine off
      vehicle.engine_off();
      break;
    case 3: //lock car
      vehicle.locked(1);
      break;
    case 4: //unlock car
      vehicle.locked(0);
      break;
    case 5: //set colour
      cout << "\nPlease enter a new car colour" << endl;
      getline(cin, inputLine);
      vehicle.set_colour(inputLine);
      break;
    case 6: //set make
      cout << "\nPlease enter a new car make" << endl;
      getline(cin, inputLine);
      vehicle.set_make(inputLine);
      break;
    case 0:
      break;
    default:
      cout << "Please enter a valid value" << endl;
      break;
  }
}

void areaOf(void) {
    //Instances of AreaOf class
	  AreaOf circle;
    AreaOf rectangle;
    AreaOf trapezoid;

    //each of the sizes
    float radius = 4.5;
    float width = 4, length = 5.9;
    float baseB = 14, height = 7.5, baseA = 6;

    //Calculate sizes for each shape
    circle.size(radius);
    rectangle.size(width, length);
    trapezoid.size(baseB, height, baseA);

    //Display size alongside specific formatted output  
    circle.displaySize(radius);
    rectangle.displaySize(width, length);
    trapezoid.displaySize(baseB, height, baseA);
}