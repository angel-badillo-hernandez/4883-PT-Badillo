'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Automating the Grades UVA problem.
`date`: 2022-12-02
'''

def getLetterGrade(grade: int) -> str:
    """
    Calculate the letter grade based on 0-100 scale.

    Args:
    grade: integer representing grade on 0-100 scale.

    Returns:
    string representation of grade on 0-100 scale.
    """
    letterGrade: str = ""

    if grade >= 90:
        letterGrade = "A"
    elif grade < 90 and grade >= 80:
        letterGrade = "B"
    elif grade < 80 and grade >= 70:
        letterGrade = "C"
    elif grade < 70 and grade >= 60:
        letterGrade = "D"
    else:
        letterGrade = "F"
    return letterGrade

# read # of test case
numCases: int = int(input())

for t in range(1,numCases+1):
    # read grades and convert into list of int
    grades:list = input().split(' ')
    grades = list(map(int,grades))

    # get test grades and find and remove min,
    # and calc average
    testGrades:list[int] =[]
    avgTestGrade: int = 0
    for i in range(0,3):
        testGrades.append(grades.pop())
    minTestGrade:int = min(testGrades)
    testGrades.remove(minTestGrade)
    avgTestGrade = sum(testGrades)//2

    # calc final grade on 0-100 scale, then
    # determine letter grade
    finalGrade:int = avgTestGrade + sum(grades)
    letterGrade: str = getLetterGrade(finalGrade)
    print(f"Case {t}: {letterGrade}")