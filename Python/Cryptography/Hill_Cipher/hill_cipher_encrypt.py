KeyMatrix = [[0]*3 for i in range(3)]
MsgMatrix = [[0] for i in range(3)]
CipherMatrix = [[0] for i in range(3)]


def getKeyMatrix(key):
    k=0
    for i in range(3):
        for j in range(3):
            KeyMatrix[i][j] = ord(key[k])%65
            k+=1

def encrypt(MsgMatrix):
    for i in range(3):
        for j in range(1):
            CipherMatrix[i][j]=0
            for x in range(3):
                CipherMatrix[i][j] = CipherMatrix[i][j] + (KeyMatrix[i][x] * MsgMatrix[x][j])
            CipherMatrix[i][j] = CipherMatrix[i][j] % 26
    
def hill_cipher(msg,key):
    getKeyMatrix(key)

    for i in range(3):
        MsgMatrix [i][0] = ord(msg[i])%65

    encrypt(MsgMatrix)

    cipherText = []
    for i in range(3):
        cipherText.append(chr(CipherMatrix[i][0]+65))

    print("Cipher Text = ", "".join(cipherText))

    
key = input("Enter 3x3 Key Matrix = ")
key = key.upper()
plain_Text = input("Enter 3 character PlainText = ")
plain_Text = plain_Text.upper()
hill_cipher(plain_Text,key)
