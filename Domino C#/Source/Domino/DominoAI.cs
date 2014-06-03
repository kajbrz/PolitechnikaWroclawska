using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dominoAi
{
    class DominoAI
    {
        private DominoGame.InterfaceDomino pointer;
        private int stack;
        Random generate = new Random((int)DateTime.Now.Ticks);
        private int left;
        private DominoGame.rotate left_rotate;
        private int right;
        private DominoGame.rotate right_rotate;

        private struct dominos
        {
            public int side;
            public int index;
        };

        public DominoAI()
        {
            pointer = null;
            left = new int();
            left_rotate = new DominoGame.rotate();
            
            right = new int();
            right_rotate = new DominoGame.rotate();

            stack = new int();
            stack = 0;
        }

        public void set_game(DominoGame.InterfaceDomino pointer)
        {
            this.pointer = pointer;
        }

        public bool play()
        {
            if (pointer == null)
                return false;
            if (pointer.get_who_play() == DominoGame.pool.player1)
            {
                return false;
            }

            if (pointer.get_status_game() != DominoGame.status.start)
                return false;

            if (pointer.get_list_of_blockdomino_onboard().Count == 0)
            {
                pointer.send_block(generate.Next(pointer.get_list_of_blockdomino_player2().Count), 0, 1);
            }


            if (stack++ > 30)
                throw new Exception("StackOverflowExceptions");

            switch (pointer.get_list_of_blockdomino_onboard()[0].Rotate)
            {
                case DominoGame.rotate.vertical:
                    {
                        left = pointer.get_list_of_blockdomino_onboard()[0].Value_Down;
                        left_rotate = DominoGame.rotate.vertical;
                        break;
                    }
                case DominoGame.rotate.horizontal_right:
                    {
                        left = pointer.get_list_of_blockdomino_onboard()[0].Value_Down;
                        left_rotate = DominoGame.rotate.horizontal_right;
                        break;
                    }
                case DominoGame.rotate.horizonta_left:
                    {
                        left = pointer.get_list_of_blockdomino_onboard()[0].Value_Up;
                        left_rotate = DominoGame.rotate.horizonta_left;
                        break;
                    }
            }

            int n = pointer.get_list_of_blockdomino_onboard().Count -1;
            switch (pointer.get_list_of_blockdomino_onboard()[n].Rotate)
            {
                case DominoGame.rotate.vertical:
                    {
                        right = pointer.get_list_of_blockdomino_onboard()[n].Value_Down;
                        right_rotate = DominoGame.rotate.vertical;
                        break;
                    }
                case DominoGame.rotate.horizontal_right:
                    {
                        right = pointer.get_list_of_blockdomino_onboard()[n].Value_Up;
                        right_rotate = DominoGame.rotate.horizontal_right;
                        break;
                    }
                case DominoGame.rotate.horizonta_left:
                    {
                        right = pointer.get_list_of_blockdomino_onboard()[n].Value_Down;
                        right_rotate = DominoGame.rotate.horizonta_left;
                        break;
                    }
            } 

            dominos domino = find_domino();
            if (pointer.send_block(domino.index, domino.side) == -2)
            {
                pointer.draw_domino(1);
                play();                
            }
            stack = 0;
            return true;
        }

        /// <summary>
        /// search the best domino
        /// </summary>
        /// <returns></returns>
        private dominos find_domino() 
        {
            dominos dominos = new dominos();
            
            var index_left = new List<int>();
            var index_right = new List<int>();

            int i=0;
            foreach (DominoGame.BlockDomino bd in pointer.get_list_of_blockdomino_player2().ToArray())
            {
                if (left == bd.Value_Up || left == bd.Value_Down)
                {
                    index_left.Add(i);
                }
                
                if (right == bd.Value_Up || right == bd.Value_Down)
                {
                    index_left.Add(i);
                }
                i++;
            }


            if (generate.Next(2) == 0)
            {
                dominos.side = 0;
                dominos.index = generate.Next(index_left.Count);
            }
            else
            {
                dominos.side = 1;
                dominos.index = generate.Next(index_right.Count);
            }

            return dominos;
        }

    }

}
