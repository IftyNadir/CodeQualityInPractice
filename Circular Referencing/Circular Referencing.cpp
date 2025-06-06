/*
	Example: Circular Dependency / Circular Referencing in C++

	This code demonstrates a circular reference between two classes:
	- Factory
	- Part

	In this example:
	- The constructor of Factory creates an instance of Part.
	- The constructor of Part, in turn, creates an instance of Factory.

	Can you identify what is wrong with the following code?
	What do you expect will happen when this program is run?
	
*/

#include <iostream>
#include <string>
#include <cstdlib>  // For rand()


using namespace std;

// Forward declaration
class Factory;

// Represents a component or module produced by the factory
class Part 
{
	public:
		Part();                        // Constructor
		void        DoSomething();     // Simulate some action
};

// Represents the factory that creates parts
class Factory 
{
	public:
		Factory();                     // Constructor
		int         GetRegNumber();    // Retrieve factory's registration number

	private:
		int         regNumber;         // Unique factory registration number
};

// ---------------------------
// Part class implementation
// ---------------------------

Part::Part()
{
	cout << "I am a new Part class" << endl;
		
	// Create a new Factory object inside the Part constructor
	Factory* factory = new Factory();

	cout << factory->GetRegNumber() << endl;

	delete factory;
}

void Part::DoSomething()
{
	cout << "Part class doing something" << endl;
}

// -----------------------------
// Factory class implementation
// -----------------------------

Factory::Factory()
{
	cout << "I am a new Factory class" << endl;

	// Generate random registration number in range 1 to 100
	regNumber = rand() % 100 + 1;

	// Create a new Part object inside the Factory constructor
	Part* part = new Part();

	part->DoSomething();

	delete part;
}

int Factory::GetRegNumber()
{
	return regNumber;
}

// ----------------
// Main application
// ----------------

int main()
{
	Factory* factory = new Factory();

	delete factory;

	return 0;
}
