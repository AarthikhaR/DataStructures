def encrypt(PT,key):
    cipher = ""
    col = len(key)
    row = ( len(PT)//col ) + 1
    msg_lst = list(PT)
    key_lst = sorted(list(key))
    fill_null = int((row*col) - len(msg_lst))
    msg_lst.extend( "x" * fill_null)
    cipher_mat = [ [ 0 for i in range(col) ] for j in range(row) ]
    k=0
    for i in range(row):
        for j in range(col):
            cipher_mat[i][j] = msg_lst[k]
            k+=1
    key_index = 0
    for b in range(col):
        curr = key.index(key_lst[key_index])
        for g in range(row):
            cipher = cipher + ''.join(cipher_mat[g][curr])
        key_index+=1
    return cipher
PT = input("Enter PlainText = ")
PT = PT.replace(" ","")
key = input("Enter key value = ")
cipherText = encrypt(PT,key)
print("Cipher Text = ",cipherText)
