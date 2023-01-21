from random import randint

q = int(input("Enter a prime number : "))
alpha = int(input("Enter the primitive root of q : " ))
Xa = randint(1,q-1)
Ya = int(pow(alpha,Xa,q))
Xb = randint(1,q-1)
Yb = int(pow(alpha,Xb,q))
Ka = int(pow(Yb,Xa,q))
Kb = int(pow(Ya,Xb,q))
print("Key generated by A is ",Ka,"and that by B is ",Kb)
