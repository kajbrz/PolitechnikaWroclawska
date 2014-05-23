using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zolnierz
{
    partial class Animal
    {
        private int age;


        public Animal(int age = 0)
        {
            Age = age;
        }
        public Animal(Animal animal)
        {
            this.age = animal.Age;
        }
        public virtual string attack()
        {
            return "No attack!";
        }
        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                age = value;
            }
        }

    }
}
