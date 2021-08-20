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
		std::cout << " - carClass: not yet implemented\n\n";
}


void areaOf(void) {
		std::cout << " - areaOf: not yet implemented\n\n";
}