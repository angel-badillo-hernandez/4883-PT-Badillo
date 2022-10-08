/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Scissors Rock Paper UVA problem.
 * @date 2022-09-15
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;
#define newl '\n'

// Enum for different "lifeforms"
enum Lifeforms
{
    ROCK = 'R',
    PAPER = 'P',
    SCISSORS = 'S'
};

// Returns true if i beats j, false otherwise.
bool doesWin(char i, char j)
{
    bool isVictory;

    // Determine what lifeform i is, then see if it beats j.
    switch (i)
    {
    case ROCK:
        isVictory = (j == SCISSORS) ? true : false;
        break;
    case SCISSORS:
        isVictory = (j == PAPER) ? true : false;
        break;
    case PAPER:
        isVictory = (j == ROCK) ? true : false;
    default:
        break;
    }
    return isVictory;
}

array<array<int, 2>,4> 

int main()
{
    int numCases;              // # test cases
    int r;                     // # rows
    int c;                     // # cols
    int n;                     // # n-th day
    vector<string> G;          // Grid
    vector<string> currentDay; // Original grid
    cin >> numCases;

    while (numCases)
    {
        cin >> r >> c >> n;
        G.resize(r);

        // Read each row of the grid
        for (auto &&r : G)
        {
            cin >> r;
        }

        for (int day = 0; day < n; day++)
        {
            currentDay = G;

            for (int r = 0; r < G.size(); r++)
            {
                for (int c = 0; c < G[r].size(); c++)
                {

                }
            }
        }

        // TODO: Process fighting here

        if (numCases > 1)
            cout << newl;
        numCases--;
    }

    return 0;
}