using System;

namespace aboutParameter
{
    class Program
    {
        //call by value
        static void Plus(int a)
        {
            Console.Write("Call by value : ");
            a += 200;
        }

        //call by reference
        static void Plus(ref int a)
        {
            Console.Write("Call by reference : ");
            a += 300;
        }
        static void outPlus(out int a)
        {
            Console.Write("'out' parameter can use without variable declaration >> ");
            a = 777;
        }
        static void Main(string[] args)
        {
            int nTestnum = 17;
            int outNum;
            Plus(nTestnum);
            Console.WriteLine(nTestnum);
            Plus(ref nTestnum);
            Console.WriteLine(nTestnum);
            outPlus(out outNum);
            Console.WriteLine(outNum);
        }
    }
}
