'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Automating the Automatic Answer UVA problem.
`date`: 2022-12-02
'''

# read # of cases
numTestCases:int = int(input())

for t in range(0, numTestCases):
    n:int = int(input())
    result:list[int] = list(map(int, str(1)))
