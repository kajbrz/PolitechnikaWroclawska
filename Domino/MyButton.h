#pragma once
#include <SFML/Graphics.hpp>
class MyButton
{
private:
	sf::Vector2f position;
	sf::Vector2f size;

	sf::String label;
	bool is_clicked;
	bool is_render;
	
	sf::Text labelT;

	sf::Clock start;
	
	sf::Texture buttonT;
	
	sf::Sprite buttonS;

	sf::RenderTexture buttonR;

	void update();
public:
	MyButton(void);
	~MyButton(void);

	bool is_clickedf(sf::Vector2f mouseclickposition);
	
	void set_Texture_button(sf::Texture);

	sf::Sprite get_button();

	void set_font(sf::Font &font){labelT.setFont(font);}

	sf::Vector2f get_posistion(){return position;}
	void set_posistion(sf::Vector2f position){this->position = position;}
	sf::Vector2f get_size(){return size;}

	void set_label(sf::String label);

};

