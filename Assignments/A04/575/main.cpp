/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Skew Binary UVA problem.
 * @date 2022-12-02
 *
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define newl '\n'

int main()
{
    string skewBin; // # in Skew binary
    int actBin;     // # in actual binary

    while(cin >> skewBin && skewBin != "0")
    {
        actBin = 0;
        for (int i = 0; i < skewBin.size(); i++)
        {
            actBin += ((int)skewBin[i]-48)*(pow(2,skewBin.size()-i)-1);
        }
        
        cout << actBin << newl;
    }
}