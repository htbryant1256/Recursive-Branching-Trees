#include "Game.h"
#include <iostream>
#include <Windows.h>

//Private Functions---------------------------------------------------------------------------------
void Game::initVariables()
{
	window = nullptr;
    windowWidth = 1000;
    windowHeight = 1000;
    videoMode.width = windowWidth;
    videoMode.height = windowHeight;
}

void Game::initWindow()
{
    window = new sf::RenderWindow(videoMode, "Recursive Branching Structures", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
    view.setCenter(500, 500);
    view.setSize(sf::Vector2f(1500,1500));
    window->setView(view);
}

void Game::pollEvents()
{    
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
            {
                window->close();
                break;
            }
        }
    }
}

//Public Functions----------------------------------------------------------------------------------
void Game::update()
{
    pollEvents();
    //User Controls for Window Navigation-----------------------------------------------------------

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        view.move(sf::Vector2f(-10,0));
        window->setView(view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        view.move(sf::Vector2f(10, 0));
        window->setView(view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        view.move(sf::Vector2f(0, -10));
        window->setView(view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        view.move(sf::Vector2f(0, 10));
        window->setView(view);
    }

    //User Controls for Window Zooming---------------------------------------------------------------
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        windowHeight -= 10;
        windowWidth -= 10;
        view.setSize(windowHeight, windowWidth);
        window->setView(view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        windowHeight += 10;
        windowWidth += 10;
        view.setSize(windowHeight, windowWidth);
        window->setView(view);
    }
}

void Game::render()
{
    window->clear();

    branchingStructure.drawTreeTwoNode(400, 90, 500, 800, window, 30);

    window->display();
}

bool Game::isRunning()
{
    return window->isOpen();
}

//Constructors--------------------------------------------------------------------------------------
Game::Game()
{
	initVariables();
	initWindow();
}

