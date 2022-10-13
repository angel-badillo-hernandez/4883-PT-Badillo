/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Parity UVA problem.
 * @date 2022-12-02
 *
 */
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
#define newl '\n'

int main()
{
    ios_base::sync_with_stdio(false); // Speed up for iostream
    bitset<32> val_bin;
    int val;

    while(cin >> val && val)
    {
        val_bin = val;
        string str_bin = val_bin.to_string();
        int i = str_bin.find("1");
        str_bin = str_bin.substr(i);
        cout << "The parity of " << str_bin << " is " << val_bin.count() << " (mod 2).\n";
    }
}