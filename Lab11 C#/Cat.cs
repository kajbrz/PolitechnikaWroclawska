using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zolnierz
{
    class Cat
        : Animal
    {
        private string rase;


        public Cat(int age, string rase="unknown")
            : base(age)
        {
            Rase = rase;
        }

        public Cat(Cat cat)
        {
            this.Age = cat.Age;
            this.Rase = cat.Rase;
        }

        public string Rase
        {
            get 
            {
                return rase;    
            }
            set
            {
                rase = value;
            }
        }

        public override string attack()
        {
            return "Cut, cut...meow";
        }
    }
}
