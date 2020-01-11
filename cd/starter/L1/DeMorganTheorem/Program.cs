using System;
namespace DeMorganTheorem
{
    class Program
    {
        static void Main(string[] args)
        {
            bool A = true, B = false;
            Console.WriteLine("Условие до применения теоремы Де Моргана");
            if (A | B)
                Console.WriteLine("A | B = {0}", A | B);
            else
                Console.WriteLine("A | B = {0}", A | B);

            Console.WriteLine("Условие после применения теоремы Де Моргана");
            if (!(!A & !B))
                Console.WriteLine("!(!A & !B) = {0}", !(!A & !B));
            else
                Console.WriteLine("!(!A & !B) = {0}", !(!A & !B));
            Console.ReadKey();
        }
    }
}
