'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Automating the Relational Operators UVA problem.
`date`: 2022-12-02
'''

numTestCases: int = int(input())

for t in range(0, numTestCases):
    # read in input as 2 ints
    a,b = tuple(map(int,input().split()))
    res: int = a - b
    if not res:
        print('=')
    if res < 0:
        print('<')
    if res > 0:
        print('>')