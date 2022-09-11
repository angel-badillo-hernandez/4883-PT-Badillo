#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define newl '\n'
int main()
{
    int n;
    int train;
    vector<int> trains;
    stack<int> station;

    while (cin >> n && n){
        cout << n << newl;
        while (cin >> train && train)
        {
            cout << train << ' ';
        }
        cout << newl;
        return 0;
    }
}