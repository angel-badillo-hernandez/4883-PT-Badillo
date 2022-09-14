/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Rails UVA problem.
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define newl '\n'

int main()
{
    int n;              // Number of coaches
    int coach;          // ID of coach
    vector<int> trains; // Vector to hold coaches
    stack<int> station; // Train station

    // While we can read in # of coaches
    while (cin >> n && n){
        // While we can read in order of coaches
        while (cin >> coach && coach)
        {
            trains.push_back(coach);

            // Read the full line of input
            while(trains.size() != n)
            {
                cin >> coach;
                trains.push_back(coach);
            }

            //TODO: INPUT IS HANDLED CORRECTLY. WORK ON LOGIC NOW!
            

            // Clear vector and stack
            trains.clear();
            while(!station.empty())
            station.pop();
        }
        cout << newl;
    }
    return 0;
}