using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace DominoGame
{
    class BlockDomino
    {
        private int value_up;   //The value of up domino
        private int value_down; //the value of down domino
        private rotate rotate; //the position of domino
        
        public BlockDomino() //default -> not use!
        {
            value_down = 0;  
            value_up = 0;
        }

        public BlockDomino(int value_up, int value_down) //make a block
        {
            if (value_down >= 0 && value_down <= 6)   //value have to be in <0;6> -> like DOMINO :D
                this.value_down = value_down;
            else
                this.value_down = 0;

            if (value_up >= 0 && value_up <= 6)
                this.value_up = value_up;
            else
                this.value_up = 0;

            rotate = rotate.no_rotate;   //at start rotate is needless
        }
        
        //Setters And Getters
        public int Value_Up
        {
            get
            {
                return value_up;
            }
            set
            {
                value_up = value;
            }
        }

        public int Value_Down
        {
            get
            {
                return value_down;
            }
            set
            {
                value_down = value;
            }
        }

        public rotate Rotate
        {
            get
            {
                return rotate;
            }
            set
            {
                rotate = value;
            }
        }

    }
}
