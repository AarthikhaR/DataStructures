def rail_fence(PT,depth):
    pattern = [[ "\n" for i in range(len(PT)) ] for j in range(depth)]
    row , col = 0,0
    flag = False
    for i in range( len(PT) ):
        if row==0 or row==depth-1:
            flag = not flag
        pattern [row] [col] = PT[i]
        col += 1
        if(flag):
            row += 1
        else:
            row -= 1
    result = []
    for i in range(depth):
        for j in range(len(PT)):
            if(pattern[i][j]!= "\n"):
                result.append(pattern[i][j])
    return("".join(result))
PT = input("Enter Plain Text = ")
PT = PT.replace(" ","")
Pt = PT.lower()
depth = int(input("Enter depth= "))
print("Cipher Text = ",rail_fence(PT,depth))
