using System;

namespace CircularReferencing
{
    public class Factory
    {
        private int regNumber;

        public Factory()
        {
            Console.WriteLine("I am a new Factory class");

            Random random = new Random();
            regNumber = random.Next(1, 101);

            Part part = new Part();
            part.DoSomething();
        }

        public int GetRegNumber()
        {
            return regNumber;
        }
    }
}
