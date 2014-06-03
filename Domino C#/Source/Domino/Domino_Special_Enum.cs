namespace DominoGame
{
    enum rotate  //postion domino, is useful when domino is on board
    {
        no_rotate=0,
        vertical=1,
        horizonta_left=2,
        horizontal_right=3
    };

    enum status //this enum struct remember status of game
    {
        stop,
        start,
        pause
    };

    enum pool // this enum is for keep information of what pool we are actual using
    {
        noone = -1,
        jackpot = 0,
        player1 = 1,
        player2 = 2,
        onboard = 3
    }
}
