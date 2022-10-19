/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the One-Two-Three UVA problem.
 * @date 2022-12-02
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define newl '\n'

int main()
{
    int numCases;                                                            // # test cases
    string num;                                                              // Misspelled word
    vector<pair<string, int>> nums = {{"one", 1}, {"two", 2}, {"three", 3}}; // Words to compare with
    int numMatches;
    int output;
    cin >> numCases;

    while (numCases--)
    {
        numMatches = 0;
        cin >> num;
        for (auto &&p : nums)
        {
            if (num.size() == p.first.size())
            {
                for (int i = 0; i < num.size(); i++)
                    if (num[i] == p.first[i])
                        numMatches++;

                if (numMatches == p.first.size() || numMatches == p.first.size() - 1)
                {
                    output = p.second;
                    break;
                }
            }
        }
        cout << output << newl;
    }
}