using System;

namespace StringVariables
{
    class Program
    {
        static void Main(string[] args)
        {
            String a = "\nмоя строка 1";
            String b = "\tмоя строка 2";
            String c = "\aмоя строка 3";
            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(c);
            Console.ReadKey();
        }
    }
}
