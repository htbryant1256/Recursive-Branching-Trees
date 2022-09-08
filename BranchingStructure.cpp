#include "BranchingStructure.h"
#include<cstdlib>
#include <Windows.h>

//Public Functions----------------------------------------------------------------------------------

void BranchingStructure::drawTreeOneNode(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod)
{
    if (length <= 7)
    {
        return;  
    }
    vectorLine.setPosition(xCord, yCord);
    vectorLine.setSize(sf::Vector2f(length, 1));
    vectorLine.setRotation(-angle);

    window->draw(vectorLine);

    //Recursivly draw a new vectorLine, starting from the end point of the previous vectorLine.
    drawTreeOneNode(length / 1.4, angle - angleMod, xCord + ( vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
        / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
            / 180)), window, angleMod);
}

void BranchingStructure::drawTreeTwoNode(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod)
{
    if (length <= 7)
    {
        return;
    }
    vectorLine.setPosition(xCord, yCord);
    vectorLine.setSize(sf::Vector2f(length, 1));
    vectorLine.setRotation(-angle);

    window->draw(vectorLine);

    //Recursivly draw a new vectorLine, starting from the end point of the previous vectorLine.
    drawTreeTwoNode(length / 1.4, angle - angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod);
    drawTreeTwoNode(length / 1.4, angle + angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod); 
}

void BranchingStructure::drawTreeThreeNode(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod)
{
    if (length <= 7)
    {
        return;
    }
    vectorLine.setPosition(xCord, yCord);
    vectorLine.setSize(sf::Vector2f(length, 1));
    vectorLine.setRotation(-angle);

    window->draw(vectorLine);

    //Recursivly draw a new vectorLine, starting from the end point of the previous vectorLine.
    drawTreeThreeNode(length / 1.4, angle - angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
        / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
            / 180)), window, angleMod);
    drawTreeThreeNode(length / 1.4, angle + angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
        / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
            / 180)), window, angleMod);
    drawTreeThreeNode(length / 1.4, angle, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
        / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
            / 180)), window, angleMod);
}

BranchingStructure::BranchingStructure()
{
    srand((unsigned int)time(NULL));
}



