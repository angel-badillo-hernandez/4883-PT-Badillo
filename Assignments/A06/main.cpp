/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Hardwood Species UVA problem.
 * @date 2022-09-04
 * 
 */
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string,int> treeMap;
    string treeName;
    double treeTotal = 0;
    int T = 0;
    
    // # Test cases
    cin >> T;

    // Resolve the newline error that happens when switching from cin to getline
    cin.ignore();
    
    // Read the empty line in the file
    getline(cin, treeName);

    // Set output to have fixed-point notation with 4 decimal places
    cout << setprecision(4) << fixed;
    while (T)
    {
        // Read tree name if available, add name to map if needed, increment
        // count of that tree species and of total trees
        while (getline(cin, treeName) && !treeName.empty())
        {
            if (treeMap.find(treeName) == treeMap.end())
            {
                treeMap.insert(pair<string, int>(treeName, 1));
                treeTotal++;
            }
            else
            {
                treeMap.at(treeName)++;
                treeTotal++;
            }
        }
        
        // Print all the percentages of each tree species to total trees
        for (auto it : treeMap)
        {
            cout << it.first << ' ' << it.second/treeTotal*100 << '\n';
        }
        
        // Decrement T and print newline if another test case exists
        if((--T) != 0)
        cout << '\n';

        // Clear map for next test case
        treeMap.clear();
        treeTotal = 0;
    }
    return 0;
}