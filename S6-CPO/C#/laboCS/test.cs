using System;
using System.Text;

namespace OverrideAndNew{
    class Program{
        static void Main(){
            BaseClass bcdc = new DerivedClass();
            bcdc.Method1();
            bcdc.Method2();
        }
    }

    class BaseClass{
        public virtual void Method1(){
            Console.WriteLine("1");

        }
        public virtual void Method2(){
            Console.WriteLine("2");
        }
    }

    class DerivedClass : BaseClass {
        public override void Method1(){
            Console.WriteLine("3");

        }
        public new void Method2(){
            Console.WriteLine("4");
        }
    }
}