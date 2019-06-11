using System;

namespace foreach1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nArr = { 1, 3, 5, 7, 9, 11, 13, 15 };
            int nIndex = 0;
            foreach(int i in nArr)
            {
                Console.WriteLine("nArr[{0}] = {1}", nIndex++, i);
            }
        }
    }
}
