using System;

namespace circleArea
{
    class Program
    {
        static void Main(string[] args)
        {
            double pi = Math.PI;
            int r = 25;
            double area = pi * Math.Pow(r, 2);
            Console.WriteLine("Площадь круга = " + area);
            Console.ReadKey();
        }
    }
}
