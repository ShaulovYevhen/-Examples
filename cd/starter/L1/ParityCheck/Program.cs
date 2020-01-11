using System;
namespace ParityCheck
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            Console.WriteLine("Введите целое число");
            while (!int.TryParse(Console.ReadLine(), out n))
            {
                Console.WriteLine("Ошибка ввода! Введите целое число");
            }
            if ((n % 2) == 0)
            {
                Console.WriteLine("Число четное (проверка способом деления с остатком на 2)");
            }
            else
            {
                Console.WriteLine("Число не четное (проверка способом деления с остатком на 2)");
            }
            if ((n & 1) == 0)
            {
                Console.WriteLine("Число четное (проверка способом побитового «И»)");
            }
            else
            {
                Console.WriteLine("Число не четное (проверка способом побитового «И»)");
            }
            Console.ReadKey();
        }
    }
}
