using System;

namespace ArrayApp
{
    class Program
    {
        static int Input()
        {
            int number;
            Console.WriteLine("Введите размер массива");
            while (!int.TryParse(Console.ReadLine(), out number))
            {
                Console.WriteLine("Error!Enter number");
            }
            return number;
        }
        
        static void Main(string[] args)
        {
            int n = Input();
            int[] array = new int[n];
            Random rand = new Random();
          
            
            for (int i = 0; i < array.Length; i++)
            {
                array[i] = rand.Next(1 , 100);
            } 

            int max = array[0], min = array[0], sum = 0;
            Console.WriteLine("Нечётные значения : \n");
            for (int i = 0; i < array.Length; i++)
            {
                max = Math.Max(array[i], max);
                min = Math.Min(array[i], min);
                if (array[i] % 2 != 0)
                {
                    Console.Write(array[i] + " ");
                }

                Console.Write(array[i] + " ");
                sum += array[i];
            }

            Console.WriteLine("\nСреднее арифметическое : " + sum/n);
            Console.WriteLine("Сумма всех елементов : " + sum);
            Console.WriteLine("Минимальный елемент : " + min);
            Console.WriteLine("Максимальный елемент : " + max);
            Console.ReadKey();
        }
    }
}
