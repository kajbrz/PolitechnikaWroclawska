using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DominoGame
{
    class Domino_NormalRules
        :Domino_BaseRules, InterfaceDomino 
    {
        private bool change;

        private float start_time_game;

        public String Type_Winner()
        {
            return String.Format("The winner is: player {0}", new object[] { who_won});
        }

        private int left_value;
        private bool left_vertical;

        private int right_value;
        private bool right_vertical;

        private int points_player1;
        private int points_player2;
        private int points_minimum;

        private int who_won;
        public Domino_NormalRules()
            :base(10, 1, 6)
        {
            ///Change the points to win
            points_minimum = 20;
            points_player1 = points_player2 = 0;
            start_time_game = DateTime.Now.Ticks;
        }
        private void get_points_each_block(int player1, int player2)
        {

        }
	    private void set_rotate(pool pool, int index, rotate rotate) // set  rotate in correct place	
        {
            switch(pool)
            {
                case pool.jackpot:
                    {
                        // blockdomino_jackpot[index].Rotate = rotate;
                        break;
                    }
                case pool.player1:
                    {
                        blockdomino_player1[index].Rotate = rotate;
                        break;
                    }
                case pool.player2:
                    {
                        blockdomino_player2[index].Rotate = rotate;
                        break;
                    }
                case pool.onboard:
                    {
                        blockdomino_onboard[index].Rotate = rotate;
                        break;
                    }
            }
        }
        private void draw_dominos()
        {

        }
        public int Winner {
            get
            {
                return who_won;
            }
        }



        ////////////////////////////////
        ////  A INTERFACE////////
        public   int start_game()
        {
            change = false;
            if (status == status.stop)
            {
                clear_board();
                draw_pulls();
                status = status.start;
                who_won = points_player1 = points_player2 = 0;
                left_value = right_value = -1;
                return 0;
            }
            else if(status == status.pause)
            {
                status = status.start;
                return 0;
            }
            else 
                return -1;
        }
        public int stop_game()
        {
            status = status.stop;

            return 0;
        }
        public   int pause_game()
        {
            if (status == status.start)
                status = status.pause;
            return 0;
        }
        private void draw_pulls()
        {
            Random generator = new Random((int)DateTime.Now.Ticks);

	        who_plays = generator.Next(2); //random who move first

	        //set when players start a game
	        start_time_game = DateTime.Now.Ticks;

	        draw_pull(28, pool.jackpot);  //add to jackpot 28 blocks of domino

            Int32[] pierwsze_liczby = new int[block_of_every_player];

            for (int i = 0; i < block_of_every_player; i++)
                pierwsze_liczby[i] = i;

            transferdomino(pool.jackpot, pool.player1, pierwsze_liczby, block_of_every_player, false);
            transferdomino(pool.jackpot, pool.player2, pierwsze_liczby, block_of_every_player, false);

	        left_value = -1; // -1 it's means without start value
	        right_value = -1; // as above
        }
       public  int send_block(int index, int side)
        {
            Console.WriteLine(change);
            if (change == true)
                return -1;
            change = true; //You can not do now anything
            pool pool = new pool();
            pool = get_who_play();

            BlockDomino temporary = new BlockDomino();
            if (pool == pool.player1)
            {
                if (index < 0 || index >= blockdomino_player1.Count)
                    return -1;
                temporary = blockdomino_player1[index];
            }
            else
            {
                if (index < 0 || index >= blockdomino_player2.Count)
                    return -1;
                temporary = blockdomino_player2[index];
            }

            bool no_move_error = true;

            if (left_value == -1)
            {
                if (temporary.Value_Up == temporary.Value_Down)
                {
                    set_rotate(pool, index, rotate.vertical);
                    left_vertical = false;
                    left_value = right_value = temporary.Value_Down;
                }
                else
                {
                    set_rotate(pool, index, rotate.horizonta_left);
                    left_vertical = false;
                    left_value = temporary.Value_Up;
                    right_value = temporary.Value_Down;
                }
                transferdomino(pool, pool.onboard, new int[] { index }, 1, false);
                no_move_error = false;
            }

            if (no_move_error == true)
            {
                if (side == 0)
                {
                    if (left_value == temporary.Value_Down || left_value == temporary.Value_Up)
                    {
                        if (temporary.Value_Down == temporary.Value_Up)
                        {
                            set_rotate(pool, index, rotate.vertical);
                            left_value = temporary.Value_Down;
                            left_vertical = true;
                        }
                        else if (left_value == temporary.Value_Down)
                        {
                            set_rotate(pool, index, rotate.horizonta_left);
                            left_value = temporary.Value_Up;
                            left_vertical = false;
                        }
                        else
                        {
                            set_rotate(pool, index, rotate.horizontal_right);
                            left_value = temporary.Value_Down;
                            left_vertical = false;
                        }
                        transferdomino(pool, pool.onboard, new int[] { index }, 1, false);
                        no_move_error = false;
                    }
                }
                else
                {
                    if (right_value == temporary.Value_Down || right_value == temporary.Value_Up)
                    {
                        if (temporary.Value_Down == temporary.Value_Up)
                        {
                            set_rotate(pool, index, rotate.vertical);
                            right_value = temporary.Value_Down;
                            right_vertical = true;
                        }
                        else if (right_value == temporary.Value_Down)
                        {
                            set_rotate(pool, index, rotate.horizontal_right);
                            right_value = temporary.Value_Up;
                            right_vertical = false;
                        }
                        else
                        {
                            set_rotate(pool, index, rotate.horizonta_left);
                            right_value = temporary.Value_Down;
                            right_vertical = false;
                        }
                        transferdomino(pool, pool.onboard, new int[] { index }, 1, true);
                        no_move_error = false;
                    }
                }
            }

            if (no_move_error == false)
            {
                return 0;
            }
            else
            {
                change = false;
                return -2;
            }


        }
        public  int send_block(int index, int side, int player)
        {
            if (player == who_plays)
                return send_block(index, side);
            else
                return -1;
        }

        public int draw_domino(int player = -1)
        {
            if (player != -1)
                if (player != who_plays)
                    return -1;
            if (blockdomino_jackpot.Count == 0)
                return -1;
            else
            {
                pool playerr;
                if (who_plays == 0)
                    playerr = pool.player1;
                else
                    playerr = pool.player2;

                transferdomino(pool.jackpot, playerr, new int[] { 0 }, 1, true);
            }
            return 0;
        }



        public int get_points_player1()
        {
            return points_player1;            
        } 
        public int get_points_player2()
        {
            return points_player2;            
        }

        


        public  status get_status_game()
        {
            return status;
        }
        public  pool get_who_play()
        {
            switch (who_plays)
            {
                case 0:
                    {
                        return pool.player1;
                    }
                case 1:
                    {
                        return pool.player2;
                    }
                default:
                    {
                        return pool.noone;
                    }
            }
        }
        public  int test_game()
        {
            if (change == true)
            {
                int l_val = left_value;
                int r_val = right_value;

                if (left_vertical == true)
                    l_val *= 2;
                if (right_vertical == true)
                    r_val *= 2;

                int sum = l_val + r_val;
                if (sum % 5 == 0)
                {
                    if (who_plays == 0)
                        points_player1 += sum;
                    else
                        points_player2 += sum;
                }
                change_player();
                change = false;
                if (blockdomino_jackpot.Count == 0
                    || blockdomino_player1.Count == 0
                    || blockdomino_player2.Count==0)
                {
                    pause_game();
                    clear_board();
                    draw_pulls();
                    start_game();
                }
            }


            if (points_player1 >= points_minimum)
            {
                who_won = 1;
                status = status.stop;
                return -2;
            } 
            if (points_player2 >= points_minimum)
            {
                who_won = 2;
                status = status.stop;
                return -2;
            } 
            //if(get_global_time_end() <= 0 )
            //{
            //    count_points();
            //    status = status.stop;
            //    clear_board();
            //    return -2;
            //}
            return 0;
        }

        private void count_points()
        {
            int sum_block_point_player1 = 0;
            int sum_block_point_player2 = 0;

            get_points_each_block(sum_block_point_player1, sum_block_point_player2);


            if (sum_block_point_player1 != sum_block_point_player2)
            {
                if (sum_block_point_player1 < sum_block_point_player2)
                {

                    sum_block_point_player2 += -sum_block_point_player1;

                    sum_block_point_player2 += sum_block_point_player2 % 5;

                    points_player1 += sum_block_point_player2;
                }
                else
                {
                    sum_block_point_player1 += -sum_block_point_player2;

                    sum_block_point_player1 += (sum_block_point_player1 % 5);

                    points_player2 += -sum_block_point_player1;
                }
            }
            points_player1 += points_player1 % 5;
            points_player2 += points_player2 % 5;
        }

        public   float get_global_time_end()
        {
            return (DateTime.Now.Ticks - start_time_game)/1000;
        }

        public   IReadOnlyList<BlockDomino> get_list_of_blockdomino_jackpot()
        {
            return blockdomino_jackpot.AsReadOnly();
        }
        public   IReadOnlyList<BlockDomino> get_list_of_blockdomino_player1()
        {
            return blockdomino_player1.AsReadOnly();
        }
        public   IReadOnlyList<BlockDomino> get_list_of_blockdomino_player2()
        {
            return blockdomino_player2.AsReadOnly();
        }
        public   IReadOnlyList<BlockDomino> get_list_of_blockdomino_onboard()
        {
            return blockdomino_onboard.AsReadOnly();
        }
    
    }
}
