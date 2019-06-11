using System;

namespace aboutClass1
{
    class TestClass
    {
        private string sName;
        public TestClass(string name)
        {
            sName = name;
            Console.WriteLine("Constructor {0}!", sName);
        }
        ~TestClass()
        {

            Console.WriteLine("Deconstructor {0}!", sName);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TestClass testA = new TestClass("A class");
            TestClass testB = new TestClass("B class");
            TestClass testC = new TestClass("C class");
        }
    }
}
