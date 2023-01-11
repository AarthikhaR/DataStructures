def decrypt(cipher,key):
    plText = ''
    for char in cipher:
        if(char == ''):
            plText = plText + char
        elif(char.isupper()):
            plText = plText + chr((ord(char)-key-65)%26+65)
        else:
            plText = plText + chr((ord(char)-key-97)%26+97)
    return plText
cipher = input("Enter Cipher Text = ")
key = int(input("Enter key value = "))
print("PlainText = ",decrypt(cipher,key))
