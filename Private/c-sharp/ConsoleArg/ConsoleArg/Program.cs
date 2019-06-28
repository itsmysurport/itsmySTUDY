using System;

namespace ConsoleArg
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0)
            {
                Console.WriteLine("Usgae : Helloworld.exe <NAME>.");
                return;
            }
            Console.WriteLine("Hello, {0}!", args[0]);
        }
    }
}
