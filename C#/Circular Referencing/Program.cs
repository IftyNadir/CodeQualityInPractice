/*
    This code demonstrates a circular reference between two classes:

    Factory
    Part

    In this example:

    The constructor of Factory creates an instance of Part.
    The constructor of Part in turn creates an instance of Factory.

    Can you identify what is wrong with the following code?
    What do you expect will happen when this program runs?
*/

using System;

namespace CircularReferencing
{
    class Program
    {
        static void Main()
        {
            Factory factory = new Factory();
        }
    }
}




/*
    As you can see, running the program will cause infinite recursion because:

    1. The Factory constructor creates a new Part object.
    2. The Part constructor creates another Factory object.
    3. That new Factory object creates another Part object.
    4. This cycle repeats endlessly, consuming stack memory.

    Eventually, the program crashes with a stack overflow error.

    The issue is fixed in the project "Circular Referencing Fix".
*/
