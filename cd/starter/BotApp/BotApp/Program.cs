using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using Telegram.Bot;
namespace BotApp
{
    class Program
    {
        static void Main(string[] args)
        {
            TelegramBotClient bot = new TelegramBotClient("1458789244:AAG8qosl8YgHH5kx1cZvKNlGl-rlGsFzkqI");
            System.Net.ServicePointManager.SecurityProtocol = System.Net.SecurityProtocolType.Tls12;
            var me = bot.GetMeAsync().Result;
            Console.WriteLine(me.Id);
            Console.ReadKey();
        }
    }
}
