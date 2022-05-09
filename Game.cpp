#include "Game.h"
#include "line.h"
#include <iostream>
#include <Windows.h>
//private Functions---------------------------------------------------------------------------------
void Game::initVariables()
{
	window = nullptr;
    windowWidth = 1000;
    windowHeight = 1000;
    
}

void Game::initWindow()
{
    videoMode.width = windowWidth;
	videoMode.height = windowHeight;
    window = new sf::RenderWindow(videoMode, "Random Tree Generation", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);

    view.setCenter(500, 500);
    view.setSize(sf::Vector2f(1500,1500));

    window->setView(view);


}
//event polling 
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

//public Functions---------------------------------------------------------------------------------
//updates game logic
void Game::update()
{
    pollEvents();

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

//essentially display
void Game::render()
{
  //  window->clear(sf::Color::Cyan);
    window->clear();
   // srand((unsigned int)time(NULL));

   // line.recursiveTree(400, 90, 500, 800, window, 30, 2);
    line.recursiveRandTree(200, 90, 500, 1000, window);
    Sleep(1000);
    //line.recursiveRandTree(180, 90, 300, 800, window, 30, 3);

  //  line.recursiveRandTree(150, 90, 500, 600, window, 30, 3);
  //  line.recursiveRandTree(150, -90, 500, 450, window, 30, 3);



   // std::cin >> x;
  //  line.recursiveCircle(500, 0, 0, window);

   // line.serpinskiTriangle(500, 500, 500, window);




    //x++;

    window->display();
   // Sleep(10000);

}

void Game::renderOnce()
{
    //  window->clear(sf::Color::Cyan);
    window->clear();
    // srand((unsigned int)time(NULL));

     //line.recursiveTree(400, 90, 500, 800, window, 30, 3);
    line.recursiveRandTree(200, 90, 500, 1000, window);
    Sleep(1000);
    //line.recursiveRandTree(180, 90, 300, 800, window, 30, 3);

  //  line.recursiveRandTree(150, 90, 500, 600, window, 30, 3);
  //  line.recursiveRandTree(150, -90, 500, 450, window, 30, 3);



   // std::cin >> x;
   // line.recursiveCircle(500, 0, 0, window);

   // line.serpinskiTriangle(500, 500, 500, window);




    //x++;

    window->display();
    // Sleep(10000);
}

//constructors / destructors
Game::Game()
{
	initVariables();
	initWindow();

}

Game::~Game()
{
	delete window;
}

const bool Game::running() const
{
	return window->isOpen();
}
/*


Treenode * BinarySearchTree::buildTree(int input[], int start, int end)
{
    int middle;
    
    if (start > end) 
    {
        return...
    }

    middle = (start + end) / 2;

    create new treenode

    new treenode -> info = ....

    treenode ->left = buildTree(...;
    treenode ->right = buildTree(...;
    
    return ...;
}





*/