'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Automating the Above Average UVA problem.
`date`: 2022-12-02
'''

# read # of cases
numTestCases:int = int(input())

for t in range(0, numTestCases):
    # read in data and separate # of scores from actual scores
    scores:list[int] = list(map(int,input().split()))
    numScores:float = scores.pop(0)
    # calc avg
    avgScore:float = sum(scores)/numScores

    # count # of above avg scores
    aboveAvgCount: int = 0
    for score in scores:
        if score > avgScore:
            aboveAvgCount+=1

    # print % of above avg scores
    print(f"{aboveAvgCount/numScores*100:.3f}%")