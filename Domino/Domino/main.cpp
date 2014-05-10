// GraWDominoCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <conio.h>

#include "Domino_NormalRules.h"


using namespace std;


void wys(BlockDomino bd)
{
	cout << "[" << bd.get_value_up() << " : " << bd.get_value_down() << "]";
}

void wys(BlockDomino bd, ::rotate rotate)
{
	if(rotate == rotate::vertical)
		cout << "[" << bd.get_value_up() << "]";
	else if(rotate == rotate::horizontal_left)
		cout << "[" << bd.get_value_up() << " : " << bd.get_value_down() << "]";
	else
		cout << "[" << bd.get_value_down() << " : " << bd.get_value_up() << "]";
}

int _tmain(int argc, _TCHAR* argv[])
{
	InterfaceDomino *NewGame = new Domino_NormalRules;

	

	NewGame->start_game();


	do{		
		NewGame->test_game();
		system("CLS");

		//
		for(int i=0; i<NewGame->get_count_jackpotI(); i++)
		{
			cout << " ";
			wys(NewGame->get_blockdomino_jackpotI(i));
		}
		//

		
		cout << "\n";
		for(int i=0; i<NewGame->get_count_player1I(); i++)
		{
			cout << "\n" << i << "." ;
			wys(NewGame->get_blockdomino_player1I(i));
		}
		cout << "\n";

		for(int i=0; i<NewGame->get_count_player2I(); i++)
		{
			cout << "\n" << i << "." ;
			wys(NewGame->get_blockdomino_player2I(i));
		}
		
		cout << "\nOnboard:\n";
		for(int i=0; i<NewGame->get_count_onboardI(); i++)
		{
			wys(NewGame->get_blockdomino_onboardI(i),NewGame->get_blockdomino_onboardI(i).get_rotate());
		}

		//cout << "\n\nTime:" << NewGame->get_global_time_end();

		int time = NewGame->get_player_time_end();
		cout << "\n\nTime:" << time;

		char wyb;
		cout << "\nPoints P1: " << NewGame->get_points_player1();
		cout << "\nPoints P2: " << NewGame->get_points_player2();
		cout << "\nGracz:"<< NewGame->get_who_play() << "\nWybierz koœæ: ";
		cin >> wyb;
		if(wyb>='0' && wyb<='9')
		{
			wyb+=-48;
			if(NewGame->send_block(wyb,0)!=0)
			{
				cout << "Error przy wysy³aniu";
			}else
				cout <<"\nwys³ano\n";
			Sleep(1000);
		}
		else if(wyb=='d')
		{
			NewGame->draw_domino();			
			Sleep(600);
		}
		else
		{
			Sleep(600);
		}
	}while(NewGame->get_who_won()==0);

	cout << "\n\nWin is player" << NewGame->get_who_won() << "!!!!!\n\n";
	
	delete NewGame;
	return 0;
}

