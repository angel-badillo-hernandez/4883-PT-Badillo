/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Traffic Lights UVA problem.
 * @date 2022-09-08
 * 
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cycleTime = 0;
    int elapsedTime = 0;
    bool isLightsGreen = false;
    vector<int> cycleTimes;

    // While a cycle time exists and the first cycle time in the scenario is
    // not 0, keep the program going
    while (cin >> cycleTime && cycleTime)
    {
        cycleTimes.push_back(cycleTime);
        // Stop reading cycle times for scenario once we read in a 0
        while (cycleTime)
        {
            cycleTimes.push_back(cycleTime);
            cin >> cycleTime;
        }

        // Start at double the minimum cycle time
        elapsedTime = *min_element(cycleTimes.begin(), cycleTimes.end()) * 2;

        // Test if lights are all green until elapsed time is found, or
        // until we run out of time (i.e time hits 5 hrs)
        do
        {
            isLightsGreen = true;
            for (auto &&cTime : cycleTimes)
            {
                if (!(elapsedTime % (cTime * 2) < (cTime - 5)))
                {
                    isLightsGreen = false;
                    break;
                }
            }
        } while (!(isLightsGreen) && ++elapsedTime <= 18000);

        // If all are green, print elapsed time it took to reach all green
        if (isLightsGreen)
        {
            int hr = elapsedTime / 3600;
            int min = (elapsedTime % 3600) / 60;
            int s = (elapsedTime % 3600) % 60;
            cout << setfill('0') << setw(2) << hr << ':'
                 << setw(2) << min << ':' << setw(2) << s << '\n';
        }
        else
        {
            cout << "Signals fail to synchronise in 5 hours\n";
        }

        // Reset vector and flag
        cycleTimes.clear();
        isLightsGreen = false;
    }

    return 0;
}