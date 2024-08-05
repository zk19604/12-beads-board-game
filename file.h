#include <iostream>
#include <fstream>
using namespace std;

void savegame(int circleArray[5][5], int current, int selectedBeadX, int selectedBeadY, int moveplacex, int moveplacey)
{
    ofstream file("save.txt");

    if (file.is_open())
    {
        // Save the contents of the circleArray
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                file << circleArray[i][j] << " ";
            }
            file << endl;
        }

        // Save the current player's turn
        file << current << endl;

        // Save the selected bead and move place coordinates
        file << selectedBeadX << " " << selectedBeadY << endl;
        file << moveplacex << " " << moveplacey;

        file.close();
    }
}
    

bool loadgame(int circleArray[5][5], int &current, int &selectedBeadX, int &selectedBeadY, int &moveplacex, int &moveplacey)
{
    ifstream file("save.txt");

    if (file.is_open())
    {
        // Load the contents of the circleArray
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                file >> circleArray[i][j];
            }
        }

        // Load the current players turn
        file >> current;

        // Load the selected bead and move place coordinates
        file >> selectedBeadX >> selectedBeadY >> moveplacex >> moveplacey;
        file.close();
        return true;
    }
    else
        return false;
    
}

// Function to initialize a new game state
void initializenew_game(int circleArray[5][5], int &current)
{
    current = rand() % 2 + 1;

    // Initialize the circleArray with the new game state
    int newcircleArray[5][5] = {{1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 0, 2, 2},
                                {2, 2, 2, 2, 2},
                                {2, 2, 2, 2, 2}};

    // Copy the new game state to the current game state
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            circleArray[i][j] = newcircleArray[i][j];
        }
    }
}
