/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Back to the 8 Queens problem.
 * @date 2022-10-25
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define newl '\n'

// Creating shortcut for an integer pair
using coord = pair<int,int>;

bool sameRow(vector<coord> q)
{
    for (int q0x = 0; q0x < q.size(); q0x++)
    {
        for (int q1x = 0; q1x < q.size(); q1x++)
        {
            /* code */
        }
        
    }
    
}

int main()
{
    vector<coord> queenPos(8);

    while(!cin.eof())
    {
        for(int r = 0; r < 8; ++r)
        cin >> queenPos[r].first;

        for (int c = 0; c < 8; c++)
        cin >> queenPos[c].second;

        // cause eof
        cin >> ws;

        for (auto &&i : queenPos)
        {
            cout << i.first << ' ' << i.second << newl;
        }
    }
    return 0;
}