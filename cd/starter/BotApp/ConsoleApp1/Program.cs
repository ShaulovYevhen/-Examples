using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

                ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls12;
                TelegraBotHelper hlp = new TelegraBotHelper(token: "910959073:AAFgxjCY30dodobTKjSXeFQeF3gWFrlvsVE");
                hlp.GetUpdates();

            Console.ReadKey();
        }
    }
}
