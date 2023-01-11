key = input("Enter Key = ") #Input Key value
key = key.replace(" ","") #Remove empty space in key
key = key.upper()#Convert all characters of key into uppercase


def matrix(x,y,initial): #Function for creating matrix with x rows and y columns where each value is initialised to value passed to variable initial.
    return [[initial for i in range(x)] for j in range(y)]

result = list() #Empty list

for c in key: #append all characters of key into result
    if c not in result:
        if c == 'J':
            result.append('I')
        else:
            result.append(c)

flag = 0

for i in range(65,91): #Initialise all alphabets into result except key
    if chr(i) not in result:
        if i==73 and chr(74) not in result:
            result.append('I')
            flag=1
        elif flag==0 and i==73 or i==74:
            pass
        else:
            result.append(chr(i))

my_matrix = matrix(5,5,0) # Call function matrix to create matrix with 5 rows and 5 columns where all values are 0

k=0 

for i in range(0,5):
    for j in range(0,5):
        my_matrix[i][j] = result[k]
        k=k+1


def loc_index(c):
    loc = list()
    if c == 'J':
        c='I'
    else:
        for i,j in enumerate (my_matrix):
            for k,l in enumerate (j):
                if c == l:
                    loc.append(i)
                    loc.append(k)
                    return loc
            
def encrypt():
    msg = str(input("Enter Plain Text = "))
    msg = msg.replace(" ","")
    msg = msg.upper()
    i = 0
    for s in range( 0 , len(msg)+1 , 2):
        if s < len(msg)-1 :
            if(msg[s] == msg[s+1]):
                msg = msg[:s+1] + 'X' + msg[s+1:]
        if len(msg)%2 != 0 :
            msg = msg[:] + 'X'
    print("CIPHER TEXT = ")
    while(i<len(msg)):
        loc = list()
        loc = loc_index(msg[i])
        loc1 = list()
        loc1 = loc_index(msg[i+1])
        if loc[1] == loc1[1]:
            print("{}{}".format(my_matrix [(loc[0]+1)%5][loc[1]],
                                my_matrix [(loc1[0]+1)%5][loc1[1]],end=''))
        elif( loc[0] == loc1[0]):
            print("{}{}".format(my_matrix [loc[0]][(loc[1]+1)%5],
                                my_matrix [loc1[0]][(loc1[1]+1)%5],end=''))
        else:
            print("{}{}".format(my_matrix [loc[0]][loc1[1]],
                                my_matrix [loc1[0]][loc[1]],end=''))
            i = i+2

encrypt()
                
