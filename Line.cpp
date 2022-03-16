#include "line.h"
#include<cstdlib>
//Private Functions---------------------------------------------------------------------------------

void Line::recursiveTree(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod)
{
    /*
    int color1 = rand() % 255 + 1;
    int color2 = rand() % 255 + 1;
    int color3 = rand() % 255 + 1;
    vectorLine.setFillColor(sf::Color(color1, color2, color3));
    */

    if (length <= 3)
    {
        return;

    }
    vectorLine.setPosition(xCord, yCord);
    vectorLine.setSize(sf::Vector2f(length, 1));
    vectorLine.setRotation(-angle);
    if (length <= 20)
    {
        vectorLine.setFillColor(sf::Color::Green);
    }
    else {
        vectorLine.setFillColor(sf::Color::White);
    }
    window->draw(vectorLine);

    recursiveTree(length / 1.4, angle - angleMod, xCord + length * cos(angle * (3.14159265359 / 180)), yCord - length * sin(angle * (3.14159265359 / 180)), window, angleMod);
    recursiveTree(length / 1.4, angle + angleMod, xCord + length * cos(angle * (3.14159265359 / 180)), yCord - length * sin(angle * (3.14159265359 / 180)), window, angleMod);

}



    /*
    std::cout << " test length = " << length <<"\n";
    std::cout << " Origin = " << xCord <<" "<< yCord << "\n";
    std::cout << " endPoint = " << xCord + length * cos(angle * (3.14 / 180)) << " " << yCord - length * sin(angle * (3.14 / 180)) << "\n";


    origin.setSize(sf::Vector2f(5, 5));
    origin.setPosition(xCord, yCord );
    origin.setFillColor(sf::Color::Red);


    endPoint.setSize(sf::Vector2f(10, 10));
    endPoint.setPosition(xCord + length * cos(angle * (3.14 / 180)), yCord - length * sin(angle * (3.14 / 180)));
    endPoint.setFillColor(sf::Color::Blue);
 

    */