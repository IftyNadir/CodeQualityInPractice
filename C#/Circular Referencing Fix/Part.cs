using System;

namespace CircularReferencingFix
{
    public class Part
    {
        public Part()
        {
            Console.WriteLine("Default Part constructor — no factory used.");
        }

        public Part(Factory factory)
        {
            Console.WriteLine("I am a new Part class");
            if (factory != null)
                Console.WriteLine("Using Factory with Reg#: " + factory.GetRegNumber());
        }

        public void DoSomething()
        {
            Console.WriteLine("Part class doing something");
        }
    }
}
