using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Myclass;

namespace xiaozhi_c_
{
    public internal class Test
    {
        public Test() 
        {
            a = 10;
            b = 20;
            c = 30;
            Console.WriteLine($"{a}  {b} {c}");
        }
        public int a;
        public int b;
    }


    internal class Program
    {
        static int Main(string[] args)
        {
            Test test = new Test();
            Test test1 = new Test();
            return 0;
        }
    }




}


