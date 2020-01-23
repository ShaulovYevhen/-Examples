using System;

namespace ConsoleApp3
{
    class Program
    {
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
        static void ArrayPrint(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }

            Console.WriteLine();
        }

        static int[] ArrayIncrease(int[] array)
        {
            int[] biggerArray = new int[array.Length+1];
            for (int i = 0; i < array.Length; i++)
            {
                biggerArray[i] = array[i];
            }
            return biggerArray;
        }

        static int[] ArrayAddElement(int[] array, int newElement)
        {
            int[] biggerArray = new int[array.Length + 1];
            biggerArray[0] = newElement;
            for (int i = 1, j = 0; i < biggerArray.Length; i++, j++)
            {
                biggerArray[i] = array[j];
            }
            return biggerArray;
        }

        static void Main(string[] args)
        {
            int[] array = ArrayCreate(21);
            ArrayPrint(array);
            ArrayPrint(ArrayIncrease(array));
            ArrayPrint(ArrayAddElement(array, 22));
            Console.ReadKey();
        }
    }
}
