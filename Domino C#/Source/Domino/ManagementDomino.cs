using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DominoGame
{
    class ManagementDomino
        :BoardDomino
    {
        protected void draw_pull(int howmanyblocks, pool where) // is for draw a some block domino to play
        {
            Random generator = new Random(DateTime.Now.Second); // set srand 

            if (howmanyblocks < 2)
                howmanyblocks = 2;

            for (int i = 0; i < howmanyblocks; i++) //Generate block of domino in 'where'
            {
                int a = generator.Next(7);
                int b = generator.Next(7);

                switch (where)
                {
                    case pool.jackpot:
                        {
                            blockdomino_jackpot.Add(new BlockDomino(a, b));
                            break;
                        }
                    case pool.player1:
                        {
                            blockdomino_player1.Add(new BlockDomino(a, b));
                            break;
                        }
                    case pool.player2:
                        {
                            blockdomino_player2.Add(new BlockDomino(a, b));
                            break;
                        }
                    case pool.onboard:
                        {
                            blockdomino_onboard.Add(new BlockDomino(a, b));
                            break;
                        }
                }

            }

        }

        protected int transferdomino(pool from, pool to, int[] arrayindex, int howmuch, bool isend)  //This is a most important function to sending blocks from anywhere to anywhere
        {
            List<BlockDomino> temporary = new List<BlockDomino>(); //initializate a temporary list of blocks of domino
            
            for(int i =0; i < howmuch; i++)
            {
                int currentindex = arrayindex[howmuch - i -1];  // get index from end to begin
                
                switch (from)
                {
                    case pool.jackpot:
                        {
                            temporary.Add(blockdomino_jackpot[currentindex]);  //save domino to temporary list
                            blockdomino_jackpot.RemoveAt(currentindex);         //remove saved domino from list
                            break;
                        }
                    case pool.player1:
                        {
                            temporary.Add(blockdomino_player1[currentindex]);
                            blockdomino_player1.RemoveAt(currentindex);
                            break;
                        }
                    case pool.player2:
                        {
                            temporary.Add(blockdomino_player2[currentindex]);
                            blockdomino_player2.RemoveAt(currentindex);
                            break;
                        }
                    case pool.onboard:
                        {
                            temporary.Add(blockdomino_onboard[currentindex]);
                            blockdomino_onboard.RemoveAt(currentindex);
                            break;
                        }
                }
            }
            if (isend == true) //if block you have to send to END
            {
                switch (to)
                {
                    case pool.jackpot:
                        {
                            blockdomino_jackpot.AddRange(temporary);
                            break;
                        }
                    case pool.player1:
                        {
                            blockdomino_player1.AddRange(temporary);
                            break;
                        }
                    case pool.player2:
                        {
                            blockdomino_player2.AddRange(temporary);
                            break;
                        }
                    case pool.onboard:
                        {
                            blockdomino_onboard.AddRange(temporary);
                            break;
                        }
                }
            }
            else //if block you have to send to BEGIN
            {
                switch (to)
                {
                    case pool.jackpot:
                        {
                            blockdomino_jackpot.InsertRange(0, temporary);
                            break;
                        }
                    case pool.player1:
                        {
                            blockdomino_player1.InsertRange(0, temporary);
                            break;
                        }
                    case pool.player2:
                        {
                            blockdomino_player2.InsertRange(0, temporary);
                            break;
                        }
                    case pool.onboard:
                        {
                            blockdomino_onboard.InsertRange(0, temporary);
                            break;
                        }
                }

            }

            return 0;
        }

        protected void clear_board()  //remove all blocks from table;
        {
            blockdomino_jackpot.Clear();
            blockdomino_onboard.Clear();
            blockdomino_player1.Clear();
            blockdomino_player2.Clear();
            
        }
        
        public ManagementDomino()
            :base()
        {
            ;
        }


    }
}
