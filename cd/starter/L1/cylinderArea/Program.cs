using System;
namespace cylinderArea
{
    class Program
    {
        static void Main(string[] args)
        {
            int R = 25, h = 33;
            Console.WriteLine("Объем цилиндра = {0}", Math.PI * R * R * h);
            Console.WriteLine("Площадь поверхности цилиндра = {0}", 2 * Math.PI * R * (h + R));
            Console.ReadKey();
        }
    }
}
