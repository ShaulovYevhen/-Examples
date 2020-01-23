using System;

namespace ArrayApp2
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

        static int[] MyReverse(int[] array)
        {
            int[] invertedArray = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                invertedArray[i] = array[array.Length - i - 1];
            }

            return invertedArray;
        }

        static void ArrayPrint(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }

            Console.WriteLine();
        }

        static int[] SubArray(int[] array, int index, int count)
        {
            int[] subArray = new int[count];
            for (int i = 0; i < subArray.Length; i++)
            {
                if (index < array.Length)
                {
                    subArray[i] = array[index];
                }
                else
                {
                    subArray[i] = 1;
                }
                index++;
            }

            return subArray;
        }

        static void Main(string[] args)
        {
            int[] array = ArrayCreate(21);
            ArrayPrint(array);
            ArrayPrint(MyReverse(array));
            ArrayPrint(SubArray(array, 10, 30));

            Console.ReadKey();
        }
    }
}