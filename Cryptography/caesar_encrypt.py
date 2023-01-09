def encrypt(str,key):
    cipher = ''
    for char in str:
        if(str == ''):
            cipher = cipher + char
        elif(cipher.isupper()):
            cipher = cipher + chr((ord(char)+key-65)%26+65)

        else:
            cipher = cipher + chr((ord(char)+key-97)%26+97)
    return cipher
str = input("Enter String = ")
key = int(input("Enter Key = "))
print("Cipher text = " , encrypt(str,key))
          
