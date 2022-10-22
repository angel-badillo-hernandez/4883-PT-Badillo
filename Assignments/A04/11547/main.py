'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Automating the Automatic Answer UVA problem.
`date`: 2022-12-02
'''

# read # of cases
numTestCases: int = int(input())

for t in range(0, numTestCases):
    n: int = int(input())
    # performs ops and discard negative sign
    result: int = abs((((n * 567 // 9) + 7492) *235 // 47) -498)
    # convert int to list of digits
    res: list[int] = list(map(int, str(result)))
    # print tens place digit
    print(f"{res[len(res)-2]}")
