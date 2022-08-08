## Simple implementation of  public-key cryptosystem, based of RSA algorithme.
there is three programes, the first generate the Keys and the second crypte a message and the last decrypte it .

To compile the three binary programes : Run the commande [make key ; make crypt ; make decrypt]

To crypt a message , write it in a file then Run this commande using the message file and the shosen public_key : [./crypt message_file key_file]

To decrypt a message , Run this commande using the crypted file and the shosen privat key : [./decrypt message_file key_file]

## the Key programme :
the key programme generate 3 numbers (e and n and d), represent them in two files of size 16 bytes, key_rsa and key_rsa.pub , key_rsa containe d and n (private key), key_rsa.pub containe e and n (public key).

How i did it ?

I generate two prime number of 5 digits using Rand function and change the argument seed using Srand function with time as parametre , so every second the rand generate a different number.

then calculate [n = p * q] and [f = (p - 1)*(q - 1)]

e is coprime with f . To find e and d i initialize e with max(p,q) , why max(p,q)? to stay in the same range and keep it hard to reverse. I iterate e tel GCD(e,f) = 1 and d > 0,  using Extended Euclidean algorithm.

the simple Euclidean algorithme used to compute only GCD(e, f) = GCD(f, e % f), to find the GCD of two numbers. to compute it We run two sequences A and B untel that B(n) == 0 , at the end A(n) = GCD(e, f).

A(0) = a , A(n + 1) = B(n) and  B(0) = b , B(n + 1) = A(n) % B(n) .

example: lets calculate GCD(1234, 124)

GCD(1234, 124) = GCD(124, 118) = GCD(118, 6) = GCD(6, 4) = GCD(4, 2) = 2 .

another approach to see it :

1234 = 9 * 124 + 118

124 = 1 * 118 + 6

118 = 19 * 6 + 4

6 = 1 * 4 + 2

4 = 2 * 2 + 0

GCD is the last no null reminder , GCD(a,b) = 2

the Extended Euclidean algorithm includes the simple one that only computes the GCD(e, f) and calculate the Bézout's identity of e whitch is d .
example :

to find the Bézout's identity (u,v). 1234 * u + 124 * v = GCD(1234, 124) manually , lets take the previous approche of the Euclidean algorithm and  go back from the last no null reminder expression replace the quotient by his expression before and that gives as an outher quotient to replace ..., at the end we get the expression with 1234 and 124 and Bezout identity.

2 = 6 - 1 * 4

2 = 6 - (118 - 19 * 6)

2 = - 118 + 20 * 6

2 = - 118 + 20 * (124 - 118)

2 = 20 * 124 - 21 * 118

2 = 20 * 124 - 21 * (1234 - 9 * 124)

2 = 124 * (21 * 9 + 20) - 21 * 1234

2 = 124 * 209 - 21 * 1234

for this example (u,v) = (-21, 209).

to compute that we use the simple Euclidean Algorithm and three Sequences U and V and Q , U and V gets the Bezout identity at the end of the computation of two sequences A and B :

A(0) = a , A(n + 1) = B(n)

B(0) = b , B(n + 1) = A(n) % B(n)

Q(n) = A(n) / B(n)

U(0) = 1 , U(1) = 0 and U(n + 1) =  U(n - 1) - U(n) * Q(n)

V(0) = 0 , U(1) = 1 and V(n + 1) =  V(n - 1) - V(n) * Q(n)

finally lets prepare the keys, public key file (16bytes) containe e and n [8bytes = e][8bytes = n], 
                              privat key file (16bytes) containe d and n [8bytes = d][8bytes = n].

## crypt and decrypt programmes : 
lets say me and Aimad we want to start a conversation , first we need to generate our keys then send our public key to each other. 
Now Aimad open a file using text editeur and write a message and crypt it using my public key and send it to me.

I receive it and decrypt it using my own private key.

m is the bytes range of n in this example . 257 byte range is 2 because he occupate and can be stored in 2 bytes .

how Aimad crypt the message? , first gets e and n from my public key file, , i read the message from the end and get the value of every m - 1 bytes , and calculate the value power of e modulo[n], and storet in m bytes in the encrypted message.

[m - 1 bytes of the message] -----------> [m bytes of the crypted message]

why exactly m - 1 bytes become m bytes? because the result of the calculation give as a number of range of n whitch is m .

i get d and n from my privat key file . and start decrypting it, i read read the crypted message from the end and get the value of every m bytes, and calculate the value power of d modulo n, and storet in m - 1 bytes in the decrypted message .

[m bytes of the crypted message] -----------> [m - 1 bytes of the decrypted message]

the calculation give as a number of range n (m bytes) so why we can storet in m - 1 bytes? because the decryption give as the original value that can be stored in m - 1.
## how to calculate exponentiation performed over a modulus efficiently :


## Ressources to more understand the maths behind it:
what is a prime number ? https://en.wikipedia.org/wiki/Prime_number.

GCD(a,b), what does it mean? https://en.wikipedia.org/wiki/Greatest_common_divisor

two integers a and b are coprime, what does it mean ? https://en.wikipedia.org/wiki/Coprime_integers

The Bézout's identity  https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity

to read more about the simple Euclidean Algorithm and the extended : https://en.wikipedia.org/wiki/Euclidean_algorithm - https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm

to read about the modular exponentiation and understand how to calculate exponentiation performed over a modulus efficiently : https://en.wikipedia.org/wiki/Modular_exponentiation



