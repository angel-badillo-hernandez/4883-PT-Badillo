'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Hajj-e-Akbar UVA problem.
`date`: 2022-12-02
'''

message: str = input()
caseNum: int = 0

while message != "*":
    caseNum += 1
    if message[0] == "H":
        print(f"Case {caseNum}: Hajj-e-Akbar")
    else:
        print(f"Case {caseNum}: Hajj-e-Asghar")
    message = input()