using System;

namespace CurrencyConversionApp
{
    class Program
    {
        static float Input()
        {
            float Num;
            while (!float.TryParse(Console.ReadLine(), out Num))
            {
                Console.WriteLine("Error!Enter number");
            }
            return Num;
        }

        static void converter(float amounth, float exchangeRate)
        {
            Console.WriteLine(amounth * exchangeRate);
        }
        static void Main(string[] args)
        {
            float amounth, exchangeRate;
            Console.WriteLine("Enter the amount of money you need to transfer: ");
            amounth = Input();
            Console.WriteLine("Enter exchange rate: ");
            exchangeRate = Input();
            converter(amounth,exchangeRate);
            Console.ReadKey();
        }
    }
}
