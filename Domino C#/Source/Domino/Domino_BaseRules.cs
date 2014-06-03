using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DominoGame
{
    class Domino_BaseRules
        : ManagementDomino
    {
        protected status status;
        protected int block_of_every_player; //count of how much block has one player on start

        protected int game_time; //game time in seconds
        protected int who_plays; //number of actual player;

        public Domino_BaseRules(int game_time,
            int who_plays,
            int block_of_every_player)
        {
            this.status = status.stop;
            this.game_time = game_time;
            this.who_plays = who_plays;
            this.block_of_every_player = block_of_every_player;
        }
        public Domino_BaseRules(): base(){ }
        protected void change_player()
        {
            if (who_plays == 0)
                who_plays = 1;
            else
                who_plays = 0;
        }


        ///////////////////////
        //Setters and Getters//
        protected status Status
        {
            get
            { 
                return status;
            }
            set
            { 
                status = value;
            }
        }
        protected int Block_Of_Every_Player
        {
            get
            {
                return block_of_every_player;
            }
            set
            {
                block_of_every_player = value;
            }
        }
        protected int GameTime
        {
            get
            {
                return game_time;
            }
            set
            {
                game_time = value;
            }
        }
        protected int WhoPlays
        {
            get
            {
                return who_plays;
            }
            set
            {
                who_plays = value;
            }
        }



    }
}
