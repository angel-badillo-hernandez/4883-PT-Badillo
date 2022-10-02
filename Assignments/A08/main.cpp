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
using namespace std;
#define newl '\n'
int main()
{
    int numCases;           // # test cases
    int r;                  // # rows
    int c;                  // # cols
    int n;                  // # n-th day
    vector<string> G;       // Grid

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
        

        //TODO: Process fighting here

        if(numCases > 1)
        cout << newl;
        numCases--;
    }

    return 0;
}