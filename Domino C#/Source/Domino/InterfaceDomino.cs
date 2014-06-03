using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DominoGame
{
    interface InterfaceDomino
    {
        int start_game();
        int stop_game();
        int pause_game();
        int send_block(int index, int side);
        int send_block(int index, int side, int player);

        int draw_domino(int player);

        status get_status_game();
        float get_global_time_end();
        pool get_who_play();
        int test_game();


        int get_points_player1();
        int get_points_player2();

        IReadOnlyList<BlockDomino> get_list_of_blockdomino_jackpot();
        IReadOnlyList<BlockDomino> get_list_of_blockdomino_player1();
        IReadOnlyList<BlockDomino> get_list_of_blockdomino_player2();
        IReadOnlyList<BlockDomino> get_list_of_blockdomino_onboard();


        String Type_Winner();
    }
}
