def encrypt(str,key):
    cipher = ''
    for char in str:
        if(char == ''):
            cipher = cipher + char
        elif(char.isupper()):
            cipher = cipher + chr((ord(char)+key-65)%26+65)
        else:
            cipher = cipher + chr((ord(char)+key-97)%26+97)
    return cipher
str = input("Enter String = ")
key = int(input("Enter Key = "))
print("Cipher text = " , encrypt(str,key))
          
