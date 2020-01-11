using System;
namespace powersOfTwo
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
            if ((n & (n - 1)) == 0)
            {
                Console.WriteLine("является");
            }
            else
            {
                Console.WriteLine("не является");
            }
            Console.ReadKey();
        }
    }
}
