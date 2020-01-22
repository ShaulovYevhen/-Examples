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

        static int[] ArrayCreate(int arrayLenght)
        {
            int[] array = new int[arrayLenght];
            Random rand = new Random();
            for (int i = 0; i < array.Length; i++)
            {
                array[i] = rand.Next(1, 100);
            }
            return array;
        }

        static int SumArray(int[] array)
        {
            int sum = 0;
            for (int i = 0; i < array.Length; i++)
            {
                sum += array[i];
            }
            return sum;
        }

        static int MaxInArray(int[] array)
        {
            int max = array[0];
            for (int i = 0; i < array.Length; i++)
            {
                max = Math.Max(array[i], max);
            }

            return max;
        }
        static int MinInArray(int[] array)
        {
            int min = array[0];
            for (int i = 0; i < array.Length; i++)
            {
                min = Math.Min(array[i], min);
            }

            return min;
        }

        static void OddValues(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] % 2 != 0)
                {
                    Console.Write(array[i] + " ");
                }
            }
        }

        static void Main(string[] args)
        {
            int[] array = ArrayCreate(Input());
            Console.WriteLine("Нечётные значения : \n");
            OddValues(array);
            Console.WriteLine("\nСреднее арифметическое : " + (SumArray(array)/array.Length));
            Console.WriteLine("Сумма всех елементов : " + SumArray(array));
            Console.WriteLine("Минимальный елемент : " + MinInArray(array));
            Console.WriteLine("Максимальный елемент : " + MaxInArray(array));
            Console.ReadKey();
        }
    }
}
