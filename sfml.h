#include <SFML/Graphics.hpp>
using namespace sf;

void drawBeads(RenderWindow& window, CircleShape& beadShape, float startX, float startY, int beadGrid[5][5], int cellSize, int selectedBeadX, int selectedBeadY)
{
    beadShape.setPointCount(100);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (beadGrid[i][j] == 1)
            {
                if (i == selectedBeadX && j == selectedBeadY)
                {
                    beadShape.setFillColor(Color::Yellow);
                }
                else
                {
                    beadShape.setFillColor(Color::Red);
                }
            }
            else if (beadGrid[i][j] == 2)
            {
                if (i == selectedBeadX && j == selectedBeadY)
                {
                    beadShape.setFillColor(Color::Yellow);
                }
                else
                {
                    beadShape.setFillColor(Color::Green);
                }
            }
            else
            {
                startX += cellSize;
                continue;
            }
            beadShape.setPosition(Vector2f(startX, startY));
            window.draw(beadShape);
            startX += cellSize;
        }

        startX = 35;
        startY += cellSize;
    }
}

void drawGrid(RenderWindow& window, int gridSize, int gridOffsetX, int gridOffsetY, int cellSize)
{
    for (int i = 0; i <= gridSize; i += cellSize)
    {
        // Vertical lines
        Vertex verticalLine[] = {
            Vertex(Vector2f(i + gridOffsetX, gridOffsetY)),
            Vertex(Vector2f(i + gridOffsetX, gridSize + gridOffsetY)) };
        for (int k = 0; k < 2; ++k)
            verticalLine[k].color = Color::White;
        window.draw(verticalLine, 2, Lines);

        // Horizontal lines
        Vertex horizontalLine[] = {
            Vertex(Vector2f(gridOffsetX, i + gridOffsetY)),
            Vertex(Vector2f(gridSize + gridOffsetX, i + gridOffsetY)) };
        for (int k = 0; k < 2; ++k)
            horizontalLine[k].color = Color::White;
        window.draw(horizontalLine, 2, Lines);
    }

    // Draw diagonal lines
    cellSize = 200;
    for (int i = 0; i < gridSize; i += cellSize)
    {
        for (int j = 0; j < gridSize; j += cellSize)
        {
            Vertex diagonalLine1[] = {
                Vertex(Vector2f(i + gridOffsetX, gridOffsetY + j)),
                Vertex(Vector2f(i + cellSize + gridOffsetX, gridOffsetY + cellSize + j)) };
            for (int k = 0; k < 2; ++k)
                diagonalLine1[k].color = Color::White;
            window.draw(diagonalLine1, 2, Lines);

            Vertex diagonalLine2[] = {
                Vertex(Vector2f(i + cellSize + gridOffsetX, gridOffsetY + j)),
                Vertex(Vector2f(i + gridOffsetX, gridOffsetY + cellSize + j)) };
            for (int k = 0; k < 2; ++k)
                diagonalLine2[k].color = Color::White;
            window.draw(diagonalLine2, 2, Lines);
        }
    }
}
void loction(RenderWindow& window, Vector2i mousePos, int cellsize, int x, int y, int& indexofi, int& indexofj)
{
    int dia = 30;
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mousePos.x >= x && mousePos.x <= x + dia && mousePos.y >= y && mousePos.y <= y + dia)
            {
                indexofi = i;
                indexofj = j;
                flag = true;
                break;
            }
            x += cellsize;
        }
        x = 35;
        y = y + cellsize;
        if (flag == true)
            break;
    }
}
void drawPlayerIndicators(RenderWindow& window, CircleShape& beadShape, int current, int gridOffsetX, int gridOffsetY, int gridSize)
{
    Font font;
    font.loadFromFile("omega-ruby.ttf");
    int xOffset = 80;

    Text player1Text;
    player1Text.setFont(font);
    player1Text.setCharacterSize(40);
    player1Text.setFillColor(sf::Color::Red);
    player1Text.setString("Player 1");
    player1Text.setPosition(gridOffsetX + gridSize + xOffset, gridOffsetY + 10);

    Text player2Text;
    player2Text.setFont(font);
    player2Text.setCharacterSize(40);
    player2Text.setFillColor(sf::Color::Green);
    player2Text.setString("Player 2");
    player2Text.setPosition(gridOffsetX + gridSize + xOffset, player1Text.getPosition().y + player1Text.getLocalBounds().height + 80);

    window.draw(player1Text);
    window.draw(player2Text);

    CircleShape player1Bead(15.f);
    if (current == 1)
    {
        player1Bead.setFillColor(Color::Yellow);
    }
    else
    {
        player1Bead.setFillColor(Color::Red);
    }
    player1Bead.setPosition(player1Text.getPosition().x - 25, player1Text.getPosition().y + 50);
    window.draw(player1Bead);

    CircleShape player2Bead(15.f);
    if (current == 2)
    {
        player2Bead.setFillColor(Color::Yellow);
    }
    else
    {
        player2Bead.setFillColor(Color::Green);
    }
    player2Bead.setPosition(player2Text.getPosition().x - 25, player2Text.getPosition().y + 50);
    window.draw(player2Bead);
}

void handleKeyPress(int& selectedOption,bool &enterinitial, sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Up) {
        selectedOption = (selectedOption - 1 + 2) % (2 + 1);
    }
    else if (key == sf::Keyboard::Down) {
        selectedOption = (selectedOption + 1) % (2 + 1);
    }
    else if (key == sf::Keyboard::Return) {
        enterinitial = 1;
        // Handle option selected
        if (selectedOption == 0) {
            std::cout << "Starting a new game...\n";
        }
        else if (selectedOption == 1) {
            std::cout << "Continuing the game...\n";
        }
        else if (selectedOption == 2) {
            std::cout << "Exiting the game...\n";
        }
    }
}

void drawText(sf::RenderWindow& window, const std::string& text, float yPos, int option, int selectedOption, const sf::Font& font) {
    sf::Text menuText;
    menuText.setString(text);
    menuText.setFont(font);
    menuText.setCharacterSize(20);
    menuText.setFillColor((selectedOption == option) ? sf::Color::Red : sf::Color::White);
    menuText.setPosition(100, yPos);

    window.draw(menuText);
}
void render(sf::RenderWindow& window, int selectedOption, int NewGame, int ContinueGame, int Exit) {
    window.clear();

    sf::Font font;
    if (!font.loadFromFile("omega-ruby.ttf")) {
        // Handle font loading error
        return;
    }

    drawText(window, "Start New Game", 100, NewGame, selectedOption, font);
    drawText(window, "Continue Game", 150, ContinueGame, selectedOption, font);
    drawText(window, "Exit", 200, Exit, selectedOption, font);

    window.display();
}
