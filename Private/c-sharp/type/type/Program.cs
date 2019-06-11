// 자료형을 알아본다.

using System;

namespace type
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 10;
            Console.WriteLine(a);
            Console.WriteLine("Max of int : {0} ~ Min of int : {1} size : {2}byte", int.MaxValue, int.MinValue, sizeof(int));

            bool b = false;
            Console.WriteLine(b);
            b = true;
            Console.WriteLine("It's that {0}", b);

            String s = "HELLO,";
            Console.WriteLine(s);
            s = s.ToLower();
            Console.WriteLine(s);
            s += s.ToUpper();
            Console.WriteLine(s);
        }
    }
}
