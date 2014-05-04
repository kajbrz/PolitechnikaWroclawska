#include "MyButton.h"

#include <iostream>

MyButton::MyButton(void)
{
	label = "button";
	position = sf::Vector2f(0.,0.);
	size = sf::Vector2f(0.,0.);
	

	is_clicked = false;
	is_render = false;
	/*nonclicked.create(0,0);
	clicked.create(0,0);
	*/
	}
MyButton::~MyButton(void)
{

}

bool MyButton::is_clickedf(sf::Vector2f mouseclickposition)
{
	sf::Vector2f right_bottom(position.x + size.x, position.y + size.y);

	if(mouseclickposition.x > position.x &&
		mouseclickposition.y > position.y &&
		mouseclickposition.x < right_bottom.x &&
		mouseclickposition.y < right_bottom.y)
	{
		is_clicked = true;		
	}	
	else
	{
		is_clicked = false;
	}	
	return is_clicked;
}
	

void MyButton::set_Texture_button(sf::Texture texture)
{
	buttonT = texture;
	size = sf::Vector2f(texture.getSize().x + 0.f,texture.getSize().y/2.f);
}
sf::Sprite MyButton::get_button()
{
	if(is_render==false)
	{
		update();
		is_render=true;
	}
	
	/*
	if(is_clicked == true)
	{
		labelT.move(0,20);
		buttonR.draw(buttonSclicked);
		is_clicked = false;
	}
	else
	{		
		labelT.setPosition(20,20);
		buttonR.draw(buttonSnonclicked);
	}
	buttonR.draw(labelT);
	buttonR.display();

	sf::Sprite tempSprite(buttonR.getTexture());
	tempSprite.setPosition(position);
*/
	//sf::Sprite tempsprite;
	if(is_clicked == true)
	{
		buttonS.setTextureRect(sf::IntRect(sf::Vector2i(0,(int)size.y),(sf::Vector2i)size));
		is_clicked = false;
	}
	else
	{
		buttonS.setTextureRect(sf::IntRect(sf::Vector2i(0,0),(sf::Vector2i)size));
	}
	return buttonS;
}


void MyButton::update()	
{	
	labelT.setString(label);	
	/*
	buttonSnonclicked.setTextureRect(sf::IntRect(0,0,size.x,size.y));
	buttonSclicked.setTextureRect(sf::IntRect(0,size.y,size.x,size.y));
	*/
	buttonR.create((int)size.x,(int)size.y*2);
	buttonR.draw(sf::Sprite(buttonT));
	
	labelT.setPosition(20,5);
	buttonR.draw(labelT);

	labelT.move(-2, size.y+5);
	buttonR.draw(labelT);
	

	buttonR.display();

	buttonS.setTexture(buttonR.getTexture());	
	buttonS.setPosition(position);	
}

void  MyButton::set_label(sf::String label)
{
	this->label = label;	
}