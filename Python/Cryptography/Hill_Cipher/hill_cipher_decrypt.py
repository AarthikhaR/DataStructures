import numpy as np
import math

KeyMatrix = [[0]*3 for i in range(3)]
KeyInverse = [[0]*3 for i in range(3)]
CipherMatrix = [[0] for i in range(3)]
MsgMatrix = [[0] for i in range(3)]

def getKeyMatrix(key):
    k=0
    for i in range(3):
        for j in range(3):
            KeyMatrix[i][j] = ord(key[k])%65
            k+=1

def decrypt(CipherMatrix):
    # A = np.array(KeyMatrix)
    KeyInverse = np.linalg.inv(KeyMatrix)
    for i in range(3):
        for j in range(1):
            for x in range(3):
                MsgMatrix[i][j] = MsgMatrix[i][j] + (KeyInverse[i][x] * CipherMatrix[x][j])
            MsgMatrix[i][j] = math.floor(abs(MsgMatrix[i][j]%26))

def hill_cipher(CiT,key):
    getKeyMatrix(key)

    for i in range(3):
        CipherMatrix[i][0] = ord(CiT[i])%65

    decrypt(CipherMatrix)

    plText = []
    for i in range(3):
        plText.append(chr(int(MsgMatrix[i][0]+65.0)))
    print("Plain Text = ","".join(plText))

    
key = input("Enter a 3X3 Key Matrix : ")
key = key.upper()
Cipher_Text = input("Enter a 3 letter Cipher Text = ")
Cipher_Text.upper()
hill_cipher(Cipher_Text , key)
