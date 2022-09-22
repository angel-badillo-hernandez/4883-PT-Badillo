/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Rails UVA problem.
 * @date 2022-09-15
 *
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define newl '\n'

/**
 * @brief Determines if the permutation is a valid departing train.
 * 
 * @param trainB The departing train
 * @param station Station to "push" and "pop" coaches
 * @return true if valid arrangement,
 * @return false otherwise
 */
bool isValid(vector<int> trainB, stack<int, vector<int>> station)
{
    // First coach in train A
    int coachA = 1;
    
    // For each coach in departing train, determine if arriving coaches can be
    // rearranged to match departing train
    for(auto coachB: trainB)
    {
        // If coachA is next up to depart, continue
        if (coachA == coachB)
            coachA++;
        // If coachB is in the station, can depart, and is up next to depart,
        // pop coachB from station 
        else if (coachA > coachB && station.size() && station.top() == coachB)
            station.pop();
        // If coachA departs later, push arriving coaches to station until
        // coachA is up to depart
        else if (coachA < coachB)
        {
            while (coachB != coachA)
                station.push(coachA++);
            coachA++;
        }
        // Permutation not possible
        else
            return false;
    }
    // Permutation possible
    return true;
}

int main()
{
    int n;                           // Number of coaches
    int coach;                       // ID # of coach
    vector<int> trainB;              // Departing train
    stack<int, vector<int>> station; // Train station

    // While we can read in # of coaches
    while (cin >> n && n)
    {
        // While we can read in order of coaches
        while (cin >> coach && coach)
        {
            // Push first coach
            trainB.push_back(coach);

            // Read the full line of input (comma operator is cool)
            while (trainB.size() != n)
                cin >> coach, trainB.push_back(coach);

            // Display yes if is valid permutation, no otherwise
            cout << (isValid(trainB, station) ? "Yes" : "No") << newl;

            // Clear containers for next iteration
            trainB.clear();
            while (!station.empty())
                station.pop();
        }
        cout << newl;
    }
    return 0;
}