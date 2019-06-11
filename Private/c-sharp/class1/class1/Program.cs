using System;

namespace class1
{
    class Program
    {
        static float Plus(float a, float b)
        {
            float result = a + b;
            Console.WriteLine("Overloading to float ...");
            return result;
        }
        static int Plus(int a, int b)
        {
            int result = a + b;
            return result;
        }
        static void Main(string[] args)
        {
            int a = Plus(3, 9);
            Console.WriteLine(a);
            float b = Plus(2.3f, 3.3f);
            Console.WriteLine(b);
        }
    }
}
