#ifndef BRANCHINGSTRUCTURE_H
#define BRANCHINGSTRUCTURE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include <iostream>
#include<cstdlib>

class BranchingStructure
{
public:
	
//Public Functions
	void drawTreeOneNode(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod);
	void drawTreeTwoNode(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod);
	void drawTreeThreeNode(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod);
//Constructors

	BranchingStructure();

private:
	sf::RectangleShape vectorLine;
};

#endif