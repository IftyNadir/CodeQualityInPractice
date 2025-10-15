using System;

namespace CircularReferencing
{
    public class Part
    {
        public Part()
        {
            Console.WriteLine("I am a new Part class");

            Factory factory = new Factory();
            Console.WriteLine(factory.GetRegNumber());
        }

        public void DoSomething()
        {
            Console.WriteLine("Part class doing something");
        }
    }
}
