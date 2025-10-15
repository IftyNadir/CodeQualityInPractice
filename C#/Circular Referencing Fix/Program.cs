/*
    Solution Example: Avoiding Circular Dependency / Circular Referencing in C#

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
        2. A constructor that accepts a Factory reference (dependency injection).
    - Factory creates a Part and passes itself as a reference.
    - This design breaks the circular creation loop and avoids recursion.

    This is one way to solve circular referencing in C# using dependency injection.
*/

using System;

namespace CircularReferencingFix
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("\n--- Creating Factory (which creates a Part) ---");
            Factory factory = new Factory();

            Console.WriteLine("--- Creating Part without Factory ---");
            Part standalonePart = new Part();
            standalonePart.DoSomething();

            Console.WriteLine("\n\n --- Program finished successfully ---\n\n");
        }
    }
}
