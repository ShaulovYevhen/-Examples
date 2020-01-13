using System;
namespace factorial
{
    class Program
    {
        static void Main(string[] args)
        {
            int counter = 8;
            int factorial = 1;
            Console.Write("Количество маршрутов для : {0} ", counter+" клиентов = ");
            do
            {
                factorial *= counter--;
            }
            while (counter > 0);
            Console.WriteLine(factorial);
            Console.ReadKey();
        }
    }
}
