using System;

namespace DetermineWhatNumberApp
{
    class Program
    {
        static int Input()
        {
            int num;
            while (!int.TryParse(Console.ReadLine(), out num))
            {
                Console.WriteLine("Error!Enter whole number");
            }
            return num;
        }

        static void SignDeterminer(int num)
        {
            if (num > 0)
            {
                Console.WriteLine(num + " > 0");
            }
            else if (num < 0)
            {
                Console.WriteLine(num + " < 0");
            }
            else
            {
                Console.WriteLine(num + " = 0");
            }
        }

        static bool IsPrimeNum(int num)
        {
            bool prime = true;
            for (int i = 1; i < num - 1; i++)
            {
                if (num % i == 0)
                {
                    prime = false;
                    break;
                }
            }

            if (prime)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        static bool IsDivined(int num)
        {
            if ((num % 2 == 0) && (num % 5 == 0) && (num % 3 == 0) && (num % 6 == 0) && (num % 9 == 0))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Enter number");
            var num = Input();
            SignDeterminer(num);
            if (IsPrimeNum(num))
            {
                Console.WriteLine(num + " is prime");
            }
            else
            {
                Console.WriteLine(num + " is compound");
            }

            if (IsDivined(num))
            {
                Console.WriteLine(num + " divided by 2, 5, 3, 6, 9 without remainder");
            }
            else
            {
                Console.WriteLine(num + " divided by 2, 5, 3, 6, 9 with remainder");
            }

            Console.ReadKey();
        }
    }
}
