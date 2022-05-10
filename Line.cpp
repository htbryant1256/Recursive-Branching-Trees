#include "line.h"
#include<cstdlib>
#include <Windows.h>

void Line::recursiveTree(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod, int branchNum)
{
    if (length <= 5)
    {
        return;  
    }
    vectorLine.setPosition(xCord, yCord);
    vectorLine.setSize(sf::Vector2f(length, 1));
    vectorLine.setRotation(-angle);


    if (length >= 30) {
        vectorLine.setFillColor(sf::Color::White);
    }
    else if (length >= 15)
    {
        vectorLine.setFillColor(sf::Color::Green);
    }
    else 
    {
        vectorLine.setFillColor(sf::Color::Magenta);
    }

    window->draw(vectorLine);
    switch(branchNum)
    {
    case 1:
        recursiveTree(length / 1.4, angle - angleMod, xCord + ( vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod, branchNum);
        break;
    case 2:
        recursiveTree(length / 1.4, angle - angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod, branchNum);
        recursiveTree(length / 1.4, angle + angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod, branchNum);
        break;

    case 3:
        recursiveTree(length / 1.4, angle - angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod, branchNum);
        recursiveTree(length / 1.4, angle + angleMod, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod, branchNum);
        recursiveTree(length / 1.4, angle, xCord + (vectorLine.getSize().y / 2) + length * cos(angle * (3.14159265358979323846
            / 180)), yCord + (vectorLine.getSize().y / 2) - length * sin(angle * (3.14159265358979323846
                / 180)), window, angleMod, branchNum);
        break;

    }
}

void Line::serpinskiTriangle(float radius, int xCord, int yCord, sf::RenderWindow* window)
{
    if (radius <= 5)
    {
        return;
    }

    triangle.setRadius(radius);
    triangle.setPosition(xCord - triangle.getRadius(), yCord - triangle.getRadius());
    triangle.setPointCount(3);
    triangle.setFillColor(sf::Color::Black);
    triangle.setOutlineColor(sf::Color::White);
    triangle.setOutlineThickness(1);

    window->draw(triangle);
    serpinskiTriangle(radius / 2, xCord - (radius * 0.43), yCord + (radius / 4), window);
    serpinskiTriangle(radius / 2, xCord + (radius * 0.43), yCord + (radius / 4), window);
    serpinskiTriangle(radius / 2, xCord, yCord - (radius / 2), window);
}

void Line::recursiveCircle(float radius, int xCord, int yCord, sf::RenderWindow* window)
{

    if (radius <= 15)
    {
        return;
    }
    /*
    int color1 = rand() % 255 + 1;
    int color2 = rand() % 255 + 1;
    int color3 = rand() % 255 + 1;
    **/
    circle.setRadius(radius);
    circle.setPosition(xCord, yCord);
    circle.setFillColor(sf::Color::Transparent);
    int modifier = 1.3;
    circle.setOutlineColor(sf::Color(radius / modifier, radius / modifier, radius / modifier));
    //circle.setOutlineColor(sf::Color(color1, color2, color3));
    //circle.setOutlineColor(sf::Color::White);
    /*
    if (radius <= 200)
    {
        circle.setOutlineColor(sf::Color::Green);
    }
    if (radius <= 20)
    {
        circle.setOutlineColor(sf::Color::Magenta);
        
    }
    **/
    circle.setOutlineThickness(radius / 20);

    window->draw(circle);



   

    recursiveCircle(radius / 2, xCord, yCord + radius / 2, window);
    recursiveCircle(radius / 2, xCord + radius / 2, yCord, window);
    recursiveCircle(radius / 2, xCord + radius / 2, yCord + radius, window);
    recursiveCircle(radius / 2, xCord + radius, yCord + radius / 2, window);
  
}

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
