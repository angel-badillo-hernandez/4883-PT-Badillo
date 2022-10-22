'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Jumping Mario UVA problem.
`date`: 2022-12-02
'''

numCases: int = int(input())  # of test cases

for t in range(1,numCases+1):
    numWalls: int = int(input())  # of walls
    wallHeights: list = []        # list of heights
    highJump: int = 0
    shortJump: int = 0

    # Read full line of input and split on spaces
    wallHeights = input().split(' ')
    wallHeights = list(map(int,wallHeights))

    # keep track of prev
    prev: int = wallHeights[0]

    # loop through list to test jumps
    for j in range(1, numWalls):
        # if current is greater than prev, high jump
        if wallHeights[j] > prev:
            highJump += 1
        # if current is less than prev, low jump
        elif wallHeights[j] < prev:
            shortJump += 1
        # update prev
        prev = wallHeights[j]
    # print results
    print(f"Case {t}: {highJump} {shortJump}")