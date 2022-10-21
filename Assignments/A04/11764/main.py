'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Jumping UVA problem.
`date`: 2022-12-02
'''

numCases: int = int(input())  # of test cases

for t in range(1,numCases+1):
                  # decrement # of test case
    numWalls: int = int(input())  # of walls
    wallHeights: list[int] = []   # list of heights
    highJump: int = 0
    shortJump: int = 0

    for i in range(0, numWalls):
        wallHeights.append(int(input()))
        
    prev: int = wallHeights[0]
    for j in range(0, numWalls):
        if wallHeights[j] > prev:
            highJump += 1
        elif wallHeights[j] < prev:
            shortJump += 1
    
    print(f"Case {t}: {highJump} {shortJump}\n")
