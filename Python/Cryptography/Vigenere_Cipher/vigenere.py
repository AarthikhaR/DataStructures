def generateKey(PT,keyword):
    key = list(keyword)
    if(len(PT) == len(key)):
        return(key)
    else:
        for i in range( len(PT) - len(key) ):
            key.append( key[i % len(key)] )
        return("".join(key))

def cipher_text(PT,key):
    cipher_text = []
    for i in range(len(PT)):
        x = ( ord(PT[i]) + ord(key[i]) ) % 26 
        x = x + 65
        cipher_text.append( chr(x) )
    return("".join(cipher_text))

def plain_text(cipherText , key):
    plain_text = []
    for i in range(len(cipherText)):
        x = ( (ord(cipherText[i]) - ord(key[i])) + 26 )  % 26
        x = x + 65
        plain_text.append( chr(x) )
    return("".join(plain_text))
    
PT = input("Enter Plain Text = ")
PT = PT.replace(" ","")
PT = PT.upper()
keyword = input("Enter key = ")
keyword = keyword.replace(" ","")
keyword = keyword.upper()
key = generateKey(PT,keyword)
cipherText = cipher_text(PT,key)
print("Cipher Text = ",cipherText)
print("Plain Text = ",plain_text(cipherText,key))
