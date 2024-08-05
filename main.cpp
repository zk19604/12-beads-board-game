#include <iostream>
#include "sfml.h"
#include "moves.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "file.h"
#include <time.h>
#include <cstdlib>
using namespace sf;
using namespace std;
int sX = 0, sY = 0;
float topLeftX = 0.0, topLeftY = 0.0;
int selectedBeadX = -1;
int selectedBeadY = -1;
int moveplacex = -1, moveplacey = -1;
int current = 1;
bool finish = false;
float x = 35, y = 35;
int gridSize = 400;
int gridOffsetX = (500 - gridSize) / 2;
int gridOffsetY = (500 - gridSize) / 2;
int cellSize = 100;



const int NewGame = 0;
const int ContinueGame = 1;
const int Exit = 2;
int main()
{
    int current = 1;
    srand(time(NULL));
    current = rand() % 2 + 1;
    int circleArray[5][5] = { {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 0, 2, 2},
                             {2, 2, 2, 2, 2},
                             {2, 2, 2, 2, 2} };
    int turn = 1;
    int winner;
    bool success = loadgame(circleArray, current, selectedBeadX, selectedBeadY, moveplacex, moveplacey);
    sf::RenderWindow initial(sf::VideoMode(400, 300), "12 BEADS Menu");

    int selectedOption = NewGame ;
    bool enterinitial = 0;
    while (initial.isOpen()) {
        sf::Event event;
        if (initial.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                initial.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                handleKeyPress(selectedOption, enterinitial, event.key.code);
            }
        }

        render(initial, selectedOption, NewGame, ContinueGame, Exit);

        if (enterinitial == 1) {
            initial.close();
            break;
        }
    }
    if (selectedOption == Exit)
    {
        cout << "You exited the game";
    }
    else
    {
        if (selectedOption == NewGame)
        {
            initializenew_game(circleArray, turn);
            savegame(circleArray, turn, selectedBeadX, selectedBeadY, moveplacex, moveplacey);
        }

        RenderWindow window(VideoMode(800, 800), "12 Beads Game", Style::Titlebar | Style::Resize | Style::Close);

        CircleShape circle1(15.f);

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Button::Left)
                    {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        loction(window, mousePos, cellSize, x, y, selectedBeadX, selectedBeadY);
                        cout << selectedBeadX << selectedBeadY << endl;
                    }
                    else if (event.mouseButton.button == sf::Mouse::Button::Right)
                    {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        loction(window, mousePos, cellSize, x, y, moveplacex, moveplacey);
                        cout << moveplacex << moveplacey << endl;
                        savegame(circleArray, current, selectedBeadX, selectedBeadY, moveplacex, moveplacey);
                    }
                }

                if (circleArray[selectedBeadX][selectedBeadY] == 1)
                    moves(circleArray, selectedBeadX, selectedBeadY, moveplacex, moveplacey, 1, 2, current);

                else if (circleArray[selectedBeadX][selectedBeadY] == 2)
                    moves(circleArray, selectedBeadX, selectedBeadY, moveplacex, moveplacey, 2, 1, current);
            }

            winner = onlyonecolor(circleArray);
            if (winner == 0 || winner == -1)
            {
                finish = true;
                window.close();
                break;
            }

            window.clear(sf::Color::Black);

            drawPlayerIndicators(window, circle1, current, gridOffsetX, gridOffsetY, gridSize);

            // Draw the grid using the function

            drawGrid(window, gridSize, gridOffsetX, gridOffsetY, cellSize);
            drawBeads(window, circle1, x, y, circleArray, cellSize, selectedBeadX, selectedBeadY);

            // Display the content of the window
            window.display();
        }
        if (finish == true)
        {
            RenderWindow win(VideoMode(400, 200), "Winner Window", Style::Titlebar | Style::Close);

            // Text to display the winner

            Font font;
            font.loadFromFile("omega-ruby.ttf");
            Text text;
            text.setFont(font);
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);

            // Set the winner text based on the result
            if (winner == 0)
            {
                text.setString("Player Red wins!");
            }
            else if (winner == -1)
            {
                text.setString("Player Green wins!");
            }

            // Center the text in the winner window
            FloatRect display = text.getLocalBounds();
            text.setPosition((400 - display.width) / 2, (200 - display.height) / 2);

            // Main loop for the winner window
            while (win.isOpen())
            {
                Event event;
                while (win.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                    {
                        win.close();
                    }
                }

                // Clear the winner window
                win.clear(Color::White);

                // Draw the winner text
                win.draw(text);

                // Display the content of the winner window
                win.display();
            }
        }
    }
    return 0;
}