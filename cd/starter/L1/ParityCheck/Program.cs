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

        }
    }
}
