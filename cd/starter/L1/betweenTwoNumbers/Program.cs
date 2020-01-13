using System;

namespace betweenTwoNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 1, b = 100, sum=0;
            Console.WriteLine("Нечетные значения между " + a + " и " + b +" : " );
            for (int i = a; i <= b; i++)
            {
                sum += i;
                if (i % 2 != 0)
                {
                    Console.Write(i+" ");
                }
            }
            Console.WriteLine();
            Console.WriteLine("Сумма чисел между "+a+" и "+b+" = {0}", sum);
            Console.ReadKey();
        }
    } 
}
