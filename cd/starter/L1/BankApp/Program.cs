using System;

namespace BankApp
{
    class Program
    {
        static double Input()
        {
            double number;
            Console.WriteLine("Enter number");
            while (!double.TryParse(Console.ReadLine(), out number))
            {
                Console.WriteLine("Error!Enter number");
            }
            return number;
        }
        static void CreditOperation(double number)
        {
            if (number == 700)
            {
                Console.WriteLine("Долг погашен.");
            }
            else if (number < 700)
            {
                Console.WriteLine("Задолженость составляет {0} у.е.", number - 700);
            }
            else
            {
                Console.WriteLine("Долг погашен.");
                Console.WriteLine("Переплата составляет {0} у.е.", number - 700);
            }
        }

        static void Main(string[] args)
        {
            var number = Input();
            CreditOperation(number);
            Console.ReadKey();
        }
    }
}
