/*
//MADE BY KAJETAN KACPER BRZUSZCZAK
//for to the final grade in OOPS
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <ctime>

#include "Domino\Domino_NormalRules.h"
#include "DominoAI.h"
#include "MyButton.h"

int GameWidth = 800;
int GameHeight = 600;

void render_pool_p1(sf::RenderTexture &pool, const sf::Image blockdomino, InterfaceDomino *game, int index);
bool event_p1(sf::Sprite &blockdominoP1S, InterfaceDomino *newGame, sf::Image &blockdomino_image, sf::RenderWindow &window);


void wyswietl(InterfaceDomino *NewGame);
void wys(BlockDomino bd, ::rotate rotate);
void wys(BlockDomino bd);

sf::Font font;


void show_p1_block(sf::RenderTexture &blockdominoP1, sf::Image &blockdomino_image, InterfaceDomino *newGame, int& length, int many);
void show_p2_block(sf::RenderTexture &blockdominoP2, sf::Image &blockdomino_image, InterfaceDomino *newGame, int& length, int many);

sf::Sprite blockdominoBoardf(sf::RenderTexture &blockdominoBoard, sf::Image &blockdomino_image, InterfaceDomino *newGame);
int INDEKS = -1;
int memoryplayer = 0;
bool changep1 = true;
bool changep2 = true;
bool changeboard = true;

int main()
{
	//std::cerr.rdbuf(NULL);
	srand((int)time(NULL));
	sf::RenderTexture blockdominoP1;
	sf::RenderTexture blockdominoP2;
	sf::RenderTexture blockdominoBoard;

	blockdominoBoard.create(GameWidth - 100, GameHeight - 200);

	sf::Sprite blockdominoP1S;
	sf::Sprite blockdominoP2S;

	std::stringstream tempstring;


	InterfaceDomino *newGame;
	newGame = new Domino_NormalRules;

	sf::RenderWindow window(sf::VideoMode(GameWidth, GameHeight), "Domino!", sf::Style::Close);


    window.setVerticalSyncEnabled(true);
	window.setActive(true);
	sf::Image blockdomino_image;
	if(!blockdomino_image.loadFromFile("resources\\blockDomino.png"))
	{
		//std::cerr << "Error: can not load block of domino";
		return EXIT_FAILURE;
	}

	sf::Image button_image;
	if(!button_image.loadFromFile("resources\\button151x54.png"))
	{
		//std::cerr << "Error: can not load button_image";
		return EXIT_FAILURE;
	}

	sf::Image background_image;
	if(!background_image.loadFromFile("resources\\background.png"))
	{
		//std::cerr << "Error: can not load background";
		return EXIT_FAILURE;
	}

	sf::Image icon_image;
	if(!icon_image.loadFromFile("resources\\icon.png"))
	{
		//std::cerr << "Error: can not load background";
		return EXIT_FAILURE;
	}
	window.setIcon(32,32,icon_image.getPixelsPtr());

	if(!font.loadFromFile("resources\\font.ttf"))
	{
		//std::cerr << "Error: can not load font";
		return EXIT_FAILURE;
	}

	sf::Texture buttonT;
	buttonT.loadFromImage(button_image);


	sf::Texture background;
	background.setRepeated(true);
	background.loadFromImage(background_image);
	sf::Sprite backgroundS;
	backgroundS.setTexture(background);
	backgroundS.setTextureRect(sf::IntRect(0, 0, GameWidth, GameHeight));


	newGame->start_game();

	std::stringstream streamstrin;


	sf::Text text;
	text.setColor(sf::Color::Green);
	text.setCharacterSize(30);
	text.setFont(font);

	sf::Texture texture;
	texture.loadFromImage(blockdomino_image);

//	int i = 0;


	sf::Clock start;

	start.restart();
	bool done = true;

	//std::vector<sf::Vector2f> vec_p1; ///postion od blocks player1
	//std::vector<sf::Vector2f> vec_p2; ///postion od blocks player2

	sf::Sprite domino(texture);


	std::stringstream streamstring;

	MyButton b_LEFT;
	b_LEFT.set_Texture_button(buttonT);
	b_LEFT.set_label("Left");
	b_LEFT.set_font(font);
	b_LEFT.set_posistion(sf::Vector2f(GameWidth - 170.f, GameHeight/2.f));

	MyButton b_RIGHT;
	b_RIGHT.set_Texture_button(buttonT);
	b_RIGHT.set_label("Right");
	b_RIGHT.set_font(font);
	b_RIGHT.set_posistion(sf::Vector2f(GameWidth - 170.f, GameHeight/2.f + 75));

	MyButton b_DRAW;
	b_DRAW.set_Texture_button(buttonT);
	b_DRAW.set_label("Draw");
	b_DRAW.set_font(font);
	b_DRAW.set_posistion(sf::Vector2f(GameWidth - 170.f, GameHeight/2.f + 150));


	DominoAI computer(newGame,level::random, 1);

	memoryplayer = newGame->get_who_play();

	sf::Thread thread_console(wyswietl, newGame);

	while(window.isOpen())
	{


		if(memoryplayer!= newGame->get_who_play() || newGame->test_game()==-1)
		{
			thread_console.launch();
			changeboard = true;
			changep1 = true;
			changep2 = true;
			memoryplayer = newGame->get_who_play();
		}
		if(computer.play())
			changep2 = true;
		//thread_console.launch();

		//wyswietl(newGame);
		///////////////////
		///////////////////


		//int a = 4 ;
		//////////////////////////////
		sf::Event event;
		if(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					if(event_p1(blockdominoP1S, newGame, blockdomino_image, window))
					{//is clicked a domino?
						changep1 = true;
					}

					if(b_LEFT.is_clickedf((sf::Vector2f)sf::Mouse::getPosition(window)))
					{
						if(INDEKS!=-1 && newGame->get_who_play()==0)
						{
							newGame->send_block(INDEKS,0, 0);
						}
					}
					if(b_RIGHT.is_clickedf((sf::Vector2f)sf::Mouse::getPosition(window)))
					{
						if(INDEKS!=-1 && newGame->get_who_play()==0)
						{
							newGame->send_block(INDEKS,1, 0);
						}
					}
					if(b_DRAW.is_clickedf((sf::Vector2f)sf::Mouse::getPosition(window)))
					{
						newGame->draw_domino(0);
						std:: cerr << "DUpa";
						changep1 = true;

					}
				}

			}
		}



		//////////////////////////////////////




		text.setPosition(GameWidth - 200.f, 100.f);



		//////////////DRAWING/////////
		//vec_p1.clear();

		window.clear(sf::Color::Blue);
		window.draw(backgroundS);




		//alghoritym when domino have to be start to be on center
		int many = newGame->get_count_player1I();


		int length2;

		int length = (int)((blockdomino_image.getSize().x)*many)/2;


		if(changep1==true)
			show_p1_block(blockdominoP1, blockdomino_image, newGame, length, newGame->get_count_player1I() );

		int many2 = newGame->get_count_player2I();
		if(changep2==true)
			show_p2_block(blockdominoP2, blockdomino_image, newGame, length2, many2);

		float widthcalc = GameWidth/2 - length + 0.f;
		float widthcalc2 = GameWidth/2 - length2 + 0.f;

		blockdominoP1S.setPosition(widthcalc-100, GameHeight - blockdomino_image.getSize().y - 40.f);
		blockdominoP1S.setTexture(blockdominoP1.getTexture());
		window.draw(blockdominoP1S);

		blockdominoP2S.setPosition(widthcalc2-100, 40.f);
		blockdominoP2S.setTexture(blockdominoP2.getTexture());
		window.draw(blockdominoP2S);

		window.draw(text);


		/////////////////////////////

		////////////////////////////
		streamstring.clear();
		streamstring.str("");
		streamstring << "Jackpot(" << newGame->get_count_jackpotI() << ")";
		streamstring << "\n\n Player 1:\t" << newGame->get_points_player1();
		streamstring << "\nPlayer 2:\t" << newGame->get_points_player2();
		int czas = (int)(start.getElapsedTime().asSeconds());

		if(( czas % 2 == 0) && done==true)
		{
				/*
				TESTING
				*/
				////std::cerr << "\nVec1(" << vec_p1[0].x << ";" << vec_p1[0].y << ")";
				//std::cerr << "\nclick domino: " << INDEKS ;
			///	//std::cerr << "\nPosition : " << blockdominoP1S.getPosition().x << "x" << blockdominoP1S.getPosition().y;
				done = false;
		}
		else if(czas % 2 == 1)
			done = true;
		text.setString(streamstring.str());
		/////////////////////////////////

		///////////////////////
		//sf::Sprite test(buttonT);
		//test.setTextureRect(sf::IntRect(0,54,151,54));
		//window.draw(test);
		/////////////////////////
		//sf::Sprite blockdominoBoardS =
		//blockdominoBoardS.move(0,0);
		sf::Sprite boarddominoS;
		if(changeboard==true)
		{
			changeboard = false;
			boarddominoS = blockdominoBoardf(blockdominoBoard,blockdomino_image, newGame);
		}
		else
		{
			boarddominoS.setTexture(blockdominoBoard.getTexture());
		}
		boarddominoS.setPosition(0,200);
		window.draw(boarddominoS);
		window.draw(b_LEFT.get_button());
		window.draw(b_RIGHT.get_button());
		window.draw(b_DRAW.get_button());

		window.display();
	}

	delete newGame;
    return 0;
}



void wys(BlockDomino bd)
{
	cerr << "[" << bd.get_value_up() << " : " << bd.get_value_down() << "]";
}

void wys(BlockDomino bd, ::rotate rotate)
{
	if(rotate ==  vertical)
		cerr << "[" << bd.get_value_up() << "]";
	else if(rotate ==  horizontal_left)
		cerr << "[" << bd.get_value_up() << " : " << bd.get_value_down() << "]";
	else
		cerr << "[" << bd.get_value_down() << " : " << bd.get_value_up() << "]";
}

void wyswietl(InterfaceDomino *NewGame)
{
		system("CLS");

		for(int i=0; i<NewGame->get_count_jackpotI(); i++)
		{
			cerr << " ";
			wys(NewGame->get_blockdomino_jackpotI(i));
		}
		//


		cerr << "\n";
		for(int i=0; i<NewGame->get_count_player1I(); i++)
		{
			cerr << "\n" << i << "." ;
			wys(NewGame->get_blockdomino_player1I(i));
		}
		cerr << "\n";

		for(int i=0; i<NewGame->get_count_player2I(); i++)
		{
			cerr << "\n" << i << "." ;
			wys(NewGame->get_blockdomino_player2I(i));
		}

		cerr << "\nOnboard:\n";
		for(int i=0; i<NewGame->get_count_onboardI(); i++)
		{
			wys(NewGame->get_blockdomino_onboardI(i),NewGame->get_blockdomino_onboardI(i).get_rotate());
		}

		//cerr << "\n\nTime:" << NewGame->get_global_time_end();

		int time = NewGame->get_player_time_end();
		cerr << "\n\nTime:" << time;

		cerr << "\nPoints P1: " << NewGame->get_points_player1();
		cerr << "\nPoints P2: " << NewGame->get_points_player2();
		cerr << "\nGracz:"<< NewGame->get_who_play() << "\nWybierz koœæ: ";
		/*
		if(wyb>='0' && wyb<='9')
		{
			wyb+=-48;
			if(NewGame->send_block(wyb,0)!=0)
			{
				cerr << "Error przy wysy³aniu";
			}else
				cerr <<"\nwys³ano\n";
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
		}*/
}

void show_p1_block(sf::RenderTexture &blockdominoP1, sf::Image &blockdomino_image, InterfaceDomino *newGame, int& length, int many)
{
		changep1 = false;
		std::stringstream tempstring;
		blockdominoP1.create(GameWidth,blockdomino_image.getSize().y+20);
		blockdominoP1.clear(sf::Color::Transparent);

		////std::cerr << "\nSize: ("  <<  blockdominoP1.getSize().x << ";"<<  blockdominoP1.getSize().y << ")";

		sf::Texture dominoT;
		dominoT.loadFromImage(blockdomino_image);
		sf::Sprite domino;
		domino.setTexture(dominoT);


//		bool change=false;
		for(int i = 0 ; i < many; i++)
		{
			tempstring.str("");
			tempstring << newGame->get_blockdomino_player1I(i).get_value_up();
			sf::String upS(tempstring.str());

			tempstring.str("");
			tempstring << newGame->get_blockdomino_player1I(i).get_value_down();
			sf::String downS(tempstring.str());

			//save posistion block

			sf::Text upt(upS,font, (UINT32)GameHeight/40);

			upt.move(20,2);
			upt.setColor(sf::Color::Black);
			sf::Text downt(downS,font, (UINT32)GameHeight/40);

			downt.move( 20.f, blockdomino_image.getSize().y/2.f);
			downt.setColor(sf::Color::Black);


			sf::RenderTexture klocek;
			klocek.create(blockdomino_image.getSize().x,blockdomino_image.getSize().y);

			klocek.clear(sf::Color::White);
			klocek.draw(domino);
			klocek.draw	(upt);
			klocek.draw(downt);
			klocek.display();

			sf::Sprite klocekS(klocek.getTexture());

			if(i != INDEKS)
			{
				klocekS.move(blockdomino_image.getSize().x*i+0.f, +20.f );
			}
			else
			{
				klocekS.move(blockdomino_image.getSize().x*i+0.f, 0.f );
			}
			blockdominoP1.draw(klocekS);

			//vec_p1.push_back(sf::Vector2f(klocekS.getPosition()));

		}
		blockdominoP1.display();
}




void show_p2_block(sf::RenderTexture &blockdominoP2, sf::Image &blockdomino_image, InterfaceDomino *newGame, int& length, int many)
{
		length = (int)((blockdomino_image.getSize().x)*many)/2;

		std::stringstream tempstring;

		blockdominoP2.create(GameWidth,blockdomino_image.getSize().y+20);

		blockdominoP2.clear(sf::Color::Transparent);

		sf::Texture dominoT;
		dominoT.loadFromImage(blockdomino_image);
		sf::Sprite domino;
		domino.setTexture(dominoT);

//		bool change=false;
		for(int i = 0 ; i < many; i++)
		{
			tempstring.str("");
			//tempstring << newGame->get_blockdomino_player2I(i).get_value_up();
			sf::String upS(tempstring.str());

			tempstring.str("");
			//tempstring << newGame->get_blockdomino_player2I(i).get_value_down();
			sf::String downS(tempstring.str());

			//save posistion block

			sf::Text upt(upS,font, (UINT32)GameHeight/40);

			upt.move(20,2);
			upt.setColor(sf::Color::Black);
			sf::Text downt(downS,font, (UINT32)GameHeight/40);

			downt.move( 20.f, blockdomino_image.getSize().y/2.f);
			downt.setColor(sf::Color::Black);


			sf::RenderTexture klocek;
			klocek.create(blockdomino_image.getSize().x,blockdomino_image.getSize().y);

			klocek.clear(sf::Color::White);
			klocek.draw(domino);
			klocek.draw	(upt);
			klocek.draw(downt);
			klocek.display();

			sf::Sprite klocekS(klocek.getTexture());

			klocekS.move(blockdomino_image.getSize().x*i+0.f, 0.f );

			blockdominoP2.draw(klocekS);

			//vec_p1.push_back(sf::Vector2f(klocekS.getPosition()));

		}
		blockdominoP2.display();
}


bool event_p1(sf::Sprite &blockdominoP1S, InterfaceDomino *newGame, sf::Image &blockdomino_image, sf::RenderWindow &window)
{
	sf::Vector2f left_top_point = blockdominoP1S.getPosition();

	sf::Vector2f right_bottom_point(sf::Vector2f(blockdominoP1S.getPosition().x
		+ blockdomino_image.getSize().x * newGame->get_count_player1I(),
		blockdominoP1S.getPosition().y + blockdomino_image.getSize().y));

	////std::cerr << endl << right_bottom_point.x << "x"<< right_bottom_point.y;
	right_bottom_point.x+= blockdomino_image.getSize().x;
	right_bottom_point.y+= blockdomino_image.getSize().y;

	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

	if(mouse_position.x > left_top_point.x
		&& mouse_position.y > left_top_point.y
		&& mouse_position.x < right_bottom_point.x
		&& mouse_position.y < right_bottom_point.y)
	{

		//std::cerr << "\nclick domino";
		int xD = (int)blockdomino_image.getSize().x;
		int xM = (int)(mouse_position.x - left_top_point.x);

		for(int i=1; i <= newGame->get_count_player1I(); i++)
		{
			if(xD*i > xM)
			{
				if(i-1==INDEKS)
				{
					INDEKS = -1;
				}
				else
				{
					INDEKS = i-1;
				}
				return true;
			}
		}
	}
	return false;
}


sf::Sprite blockdominoBoardf(sf::RenderTexture &blockdominoBoard, sf::Image &blockdomino_image, InterfaceDomino *newGame)
{
	std::stringstream textbuffer;
	blockdominoBoard.clear(sf::Color::Transparent);
	blockdominoBoard.setSmooth(true);

	sf::RenderTexture dominobuffer;
	dominobuffer.create(blockdomino_image.getSize().x,blockdomino_image.getSize().y);

	sf::Texture dominobufferT;
	dominobufferT.loadFromImage(blockdomino_image);

	int many = newGame->get_count_onboardI();
	float sum_of_x = 0.f;
	for(int i = 0; i < many; i++)
	{
			BlockDomino dominoblock = newGame->get_blockdomino_onboardI(i);
			textbuffer.str("");
			textbuffer << dominoblock.get_value_up();
			sf::String upS(textbuffer.str());

			textbuffer.str("");
			textbuffer << dominoblock.get_value_down();
			sf::String downS(textbuffer.str());

			//save posistion block

			sf::Text upt(upS,font, (UINT32)GameHeight/40);

			upt.move(20,2);
			upt.setColor(sf::Color::Black);
			sf::Text downt(downS,font, (UINT32)GameHeight/40);

			downt.move( 20.f, blockdomino_image.getSize().y/2.f);
			downt.setColor(sf::Color::Black);


			dominobuffer.clear(sf::Color::White);
			dominobuffer.draw(sf::Sprite(dominobufferT));
			dominobuffer.draw(upt);
			dominobuffer.draw(downt);
			dominobuffer.display();

			sf::Sprite domino(dominobuffer.getTexture());

			domino.setColor(sf::Color::Yellow);
			domino.setPosition(0,0);
			if(dominoblock.get_rotate() ==  horizontal_left)
			{
				//domino.setRotation(270);
				/*domino.move(sum_of_x+0.f, 50.f );
				*/sum_of_x+=blockdomino_image.getSize().y;
			}
			else if(dominoblock.get_rotate() ==  horizontal_right)
			{
				//domino.setRotation(90);
				/*domino.move(sum_of_x+0.f, 50.f );
				*/sum_of_x+=blockdomino_image.getSize().y;
			}
			else
			{
				//domino.setRotation(0);

				//domino.move(sum_of_x+0.f, 0.f );
				//sum_of_x+=blockdomino_image.getSize().x;
			}
			domino.move(i * blockdomino_image.getSize().x + 0.f,  0.f );


			blockdominoBoard.draw(domino);
	}

	blockdominoBoard.display();

	float size;
	if(many*blockdomino_image.getSize().x > blockdominoBoard.getSize().x)
	{
		size = blockdominoBoard.getSize().x / many*blockdomino_image.getSize().x;
	}
	else
		size = 1.f;
	sf::Sprite blockdominoBoardS = sf::Sprite(blockdominoBoard.getTexture());
	blockdominoBoardS.scale(size,size);
	return blockdominoBoardS;
}
