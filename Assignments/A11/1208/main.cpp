/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Oreon problem.
 * @date 2022-10-13
 *
 */
#include <iostream>
using namespace std;
#define newl '\n'

int main()
{
    int numCases;   // # of test cases
    int numTunnels; // # of tunnels (vertices)
    int weight;
    cin >> numCases;

    for(int c = 1; c <= numCases; c++)
    {
        cin >> numTunnels;
        for (int i = 0; i < numTunnels; i++)
        {
            for (int j = 0; j < numTunnels; j++)
            {
                cin >> weight;
            }
            
        }
        
        cout << "Case " << c << ':' << newl;
    }
    
    return 0;       
}
