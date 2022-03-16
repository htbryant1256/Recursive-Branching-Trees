#include "line.h"
#include<cstdlib>

void Line::recursiveTree(float length, int angle, int xCord, int yCord, sf::RenderWindow* window, int angleMod)
{
    if (length <= 3)
    {
        return;
    }

    vectorLine.setPosition(xCord, yCord);
    vectorLine.setSize(sf::Vector2f(length, 1));
    vectorLine.setRotation(-angle);

    if (length <= 10)
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

void Line::serpinskiTriangle(float radius, int xCord, int yCord, sf::RenderWindow* window)
{
    if (radius <= 10)
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
