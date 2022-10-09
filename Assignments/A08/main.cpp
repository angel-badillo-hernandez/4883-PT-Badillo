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
using ipair = pair<int, int>;

// Enum for different "lifeforms"
enum Lifeforms
{
    ROCK = 'R',
    PAPER = 'P',
    SCISSORS = 'S'
};

// 4 directions
array<pair<int, int>, 4> Directions = {ipair(-1, 0), ipair(1, 0), ipair(0, -1), ipair(0, 1)};

// Checks if indice are not out of bounds
bool isInBound(int r, int c, int i, int j)
{
    return (i > -1 && j > -1 && i < r && j < c);
}

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
            // Make a copy of original matrix
            currentDay = G;

            for (int r = 0; r < G.size(); r++)
            {
                for (int c = 0; c < G[r].size(); c++)
                {
                    for (auto &&dir : Directions)
                    {
                        int i = r + dir.first;
                        int j = c + dir.second;

                        if (isInBound(G.size(), G[r].size(), i, j))
                            if (doesWin(currentDay[r][c], currentDay[i][j]))
                                G[i][j] = currentDay[r][c];
                    }
                }
            }
        }

        // Print the whole final matrix
        for (auto &&s : G)
        {
            cout << s << newl;
        }

        numCases--;
        if (numCases)
            cout << newl;
    }

    return 0;
}