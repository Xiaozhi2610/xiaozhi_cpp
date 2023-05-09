using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace xiaozhi_c_
{
    internal class Program
    {
        static int Main(string[] args)
        {
            string str1 = "xiazohi";
            string str2 = str1;
            str1 = "asdlk";
            Console.WriteLine(str2);
            Console.Read();
            return 0;
        }
    }


    class card
    {
        public string Money { get; set; }
    }

    class Consume
    {
        public void Record ()
        {
            Console.WriteLine("信用卡消费记录\n");
            card pCard = new card() {Money = "8000" };
            Console.WriteLine("信用卡总额度: " + pCard.Money);
            card pCard2 = pCard;
            pCard.Money = "3000";
            Console.WriteLine("信用卡消费记录: " + pCard.Money);

        }
    }



}


