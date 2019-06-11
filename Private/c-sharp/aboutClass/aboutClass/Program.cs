using System;

namespace aboutClass
{
    class hero
    {
        public string sName;
        public int nHP;
        public int nPower;

        public hero(string name, int hp, int power)
        {
            sName = name;
            nHP = hp;
            nPower = power;
        }
        public void Attack(string target)
        {
            Console.WriteLine("You damaged to {0}! Damage : {1}", target, nPower);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            hero newHero = new hero("Maxx", 10, 2);

            Console.WriteLine("Name : {0}, HP : {1}, Power : {2}", newHero.sName, newHero.nHP, newHero.nPower);
            newHero.Attack("Normal Zombie");
        }

    }
}