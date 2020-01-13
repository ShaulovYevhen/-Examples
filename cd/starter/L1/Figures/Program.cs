using System;

namespace Figures
{
    class Program
    {
        static void Main(string[] args)
        {
            //прямоугольник
            int lenght = 10, width = 5;
            for (int a = 0; a < width; a++)
            {
                for (int b = 0; b < lenght; b++)
                {
                    if (a == 0 || a == width - 1) Console.Write("*");
                    else if (b == 0 || b == lenght - 1) Console.Write("*");
                    else Console.Write(" ");
                }
                Console.WriteLine();
            }
            //прямоугольный треугольник  
            for (int a = 0; a < 10; a++)
            {
                for (int b = 0; b < a; b++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            //равносторонний треугольник  
            int n = 7;
            int p = 7;
            for (int i = 0; i < n; i++, p--)
            {
                for (int j = 0; j < p; j++)
                {
                    Console.Write(" ");
                }
                Console.Write("*");
                for (int m = 0; m < i * 2; m++)
                {
                    Console.Write(" ");
                }
                Console.WriteLine("*");
            }
            for (int i = 0; i <= n; i++)
            {
                Console.Write("**");
            }
            Console.WriteLine();
            //ромб 
            int d = 0;
            for (int y = 0; y < 9; y++)
            {
                for (int x = 0; x < 9; x++)
                {
                    if (x <= 4 + d && x >= 4 - d)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
                d = y >= 4 ? --d : ++d;
            }
            Console.ReadKey();
        }
    }
}
