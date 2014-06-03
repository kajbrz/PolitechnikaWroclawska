using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace DominoGame
{
    class BoardDomino
    {
        protected List<BlockDomino> blockdomino_jackpot;
        protected List<BlockDomino> blockdomino_player1;
        protected List<BlockDomino> blockdomino_player2;
        protected List<BlockDomino> blockdomino_onboard;

        public BoardDomino()
        {
            blockdomino_jackpot = new List<BlockDomino>();
            blockdomino_player1 = new List<BlockDomino>();
            blockdomino_player2 = new List<BlockDomino>();
            blockdomino_onboard = new List<BlockDomino>();

            
        }
    }
}
