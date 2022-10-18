/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Odd Sum UVA problem.
 * @date 2022-12-02
 *
 */
#include <cstdio>

int main()
{
    int testCases; // # test cases
    int a;         // [a,b]
    int b;
    int oddSum;   // sum of odds

    // Read # cases
    std::scanf("%d", &testCases);

    // Compute sum of odds in given range
    for (int t = 1; t <= testCases; t++)
    {
        oddSum = 0;
        std::scanf("%d%d",&a,&b);
        for(int i = a; i <= b; i++)
            // If odd, add to sum
            if(i%2)
            oddSum += i;
        // Print result
        std::printf("Case %d: %d\n", t, oddSum);
    }
    return 0;
}