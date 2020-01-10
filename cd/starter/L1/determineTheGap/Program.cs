using System;
namespace determineTheGap
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            Console.WriteLine("Введите целое число a");
            while (!int.TryParse(Console.ReadLine(), out n))
            {
                Console.WriteLine("Ошибка ввода! Введите целое число a");
            }
            if (n > 0 && n < 14)
            {
                Console.WriteLine("Число попадает в числовой промежуток [0 - 14]");
            }
            else if (n > 15 && n < 35)
            {
                Console.WriteLine("Число попадает в числовой промежуток [15 - 35]");
            }
            else if (n > 36 && n < 50)
            {
                Console.WriteLine("Число попадает в числовой промежуток  [36 - 50]");
            }
            else if (n >= 50 && n <= 100)
            {
                Console.WriteLine("Число попадает в числовой промежуток [50 - 100]");
            }
            else
            {
                Console.WriteLine("Число не попадает в промежуток от 0 до 100 ");
            }
            Console.ReadKey();
        }
    }
}
