#include "line.h"
#include<cstdlib>
#include <Windows.h>


Line::Line()
{
    srand((unsigned int)time(NULL));
}



void Line::recursiveRandTree(float length, int angle, int xCord, int yCord, sf::RenderWindow* window)
{
    if (length <= 5)
    {
        int fruitChance = rand() % 10000 + 1;

        if (fruitChance == 1)
        {
            vectorLine.setPosition(-5 + xCord + length * cos(angle * (3.14159265358979323846
                / 180)), -5 + yCord + length * sin(angle * (3.14159265358979323846
                    / 180)));
            vectorLine.setSize(sf::Vector2f(200, 2));
            vectorLine.setFillColor(sf::Color(1, 50, 32));
            vectorLine.setRotation(90);
            circle.setRadius(10);
            circle.setPosition(sf::Vector2f(vectorLine.getPosition().x - circle.getRadius() ,vectorLine.getPosition().y - circle.getRadius() + 200));
            circle.setFillColor(sf::Color::Yellow);

            window->draw(vectorLine);
            window->draw(circle);
        }
        return;
    }

    vectorLine.setPosition(xCord, yCord);
    vectorLine.setSize(sf::Vector2f(length, length / 15));
    vectorLine.setRotation(-angle);

    if (length >= 30) {
        vectorLine.setFillColor(sf::Color(150,70,0));
    }
    else if (length >= 15)
    {
        vectorLine.setFillColor(sf::Color(1, 50, 32));
    }
    else
    {
        vectorLine.setFillColor(sf::Color(2, 100, 64));
    }
    //----------------------------------------------------------------------------

    float lengthModifer = rand() % 70 + 1;
    lengthModifer /= 100;
    lengthModifer += 1.1;

    float randAngleOne = rand() % 40 + 1;
    randAngleOne += 10;

    float randAngleTwo = rand() % 40 + 1;
    randAngleTwo += 10;
   // std::cout << lengthModifer << " \n";

    int spawnChanceOne = rand() % 100 + 1;
    int spawnChanceTwo = rand() % 100 + 1;
    int spawnChanceThree = rand() % 300 + 1;
    int spawnThreshold = 20;

    //----------------------------------------------------------------------------

    window->draw(vectorLine);
    
    if (spawnChanceOne >= spawnThreshold)
    {
        recursiveRandTree(length / lengthModifer, angle - randAngleOne, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window);
    }
    if (spawnChanceTwo >= spawnThreshold)
    {
        recursiveRandTree(length / lengthModifer, angle + randAngleTwo, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window);
    }
    if (spawnChanceThree >= spawnThreshold)
    {
        recursiveRandTree(length / lengthModifer, angle, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window);
    }

}