/*
	Solution Example: Avoiding Circular Dependency / Circular Referencing in C++

	This code demonstrates a corrected design that avoids a circular reference
	between two classes:
	- Factory
	- Part

	In the original problematic design:
	- The constructor of Factory created an instance of Part.
	- The constructor of Part, in turn, created another instance of Factory.
	- This caused infinite recursion and eventually a stack overflow.

	In this solution:
	- Part has two constructors:
		1. A default constructor that does not involve Factory.
		2. A constructor that accepts a Factory pointer (dependency injection).
	- Factory creates a Part and passes itself as a reference.
	- This design breaks the circular creation loop and avoids recursion.

	This is one way to solve circular referencing in C++ using dependency injection.
*/

#include <iostream>
#include <string>
#include <cstdlib>  // For rand()

using namespace std;

class Factory;  // Forward declaration

// Represents a component or module produced by the factory
class Part
{
public:
	Part();                     // Default constructor — no factory interaction
	Part(Factory* factory);     // Constructor with dependency injection
	void DoSomething();
};

// Represents the factory that creates parts
class Factory
{
public:
	Factory();
	int GetRegNumber();

private:
	int regNumber;
};

// ---------------------------
// Part class implementation
// ---------------------------

Part::Part()
{
	cout << "Default Part constructor — no factory used." << endl;
}

Part::Part(Factory* factory)
{
	cout << "I am a new Part class" << endl;
	if (factory)
		cout << "Using Factory with Reg#: " << factory->GetRegNumber() << endl;
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

	regNumber = rand() % 100 + 1;

	Part* part = new Part(this);
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
	cout << "\n--- Creating Factory (which creates a Part) ---" << endl;
	Factory* factory = new Factory();
	delete factory;


	cout << "--- Creating Part without Factory ---" << endl;
	Part* standalonePart = new Part();  // Uses default constructor
	standalonePart->DoSomething();
	delete standalonePart;

	return 0;
}
