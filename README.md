## Simple implementation of  public-key cryptosystem, based of RSA algorithm.
there is three programs, the first generate the Keys and the second crypt a message and the last decrypt it .

To compile the three programes : Run the command [make all]

To crypt a message , write it in a file then Run this command using the message file and the chosen public_key : [./crypt message_file key_file]

To decrypt a message , Run this command using the crypted file and the chosen private key : [./decrypt message_file key_file]

## the Key program :
the key programme generate 3 numbers (e and n and d), represent them in two files of size 16 bytes, key_rsa and key_rsa.pub , key_rsa contain d and n (private key), key_rsa.pub contain e and n (public key).

How I did it ?

I generate two prime numbers of 5 digits using Rand function and change the argument seed using Srand function with time as parameter , so every second the rand generate a different number.

then I calculate [n = p * q] and [f = (p - 1)*(q - 1)]

e is coprime with f. To find e and d I initialize e with max(p,q) , why max(p,q)? to stay in the same range and keep it hard to reverse. I iterate e till GCD(e,f) = 1 and d > 0,  using Extended Euclidean algorithm.

finally lets put the keys in their files (accordingly). 
                              
                              public key file (16bytes) contain e and n [8bytes = e][8bytes = n],

                              privat key file (16bytes) contain d and n [8bytes = d][8bytes = n].

## crypt and decrypt programs : 
lets say me and Jim want to start a conversation, first we need to generate our keys then send our public key to each other.

Jim opened a file, wrote a message and crypted it using my public key then he send it to me.

I receive it and decrypt it using my own private key.

m is the bytes's range of n. For example 2 is the bytes's range of 257 because it occupies 2 bytes in memory.

how Jim crypted the message? , first he gets e and n from my public key file, he reads the message from the end and gets the value M of every m - 1 byte, and computes M power of e modulo n and gets the crypted value then store it in m byte in the crypted message .

                    [m - 1 bytes of the message] -----------> [m bytes of the crypted message]

why exactly m - 1 bytes become m bytes? because the result of the calculation give as a number of range of n whitch is m .

i get d and n from my privat key file . and start decrypting it, i read read the crypted message from the end and get the value of every m bytes, and calculate the value power of d modulo n, and storet in m - 1 bytes in the decrypted message .

[m bytes of the crypted message] -----------> [m - 1 bytes of the decrypted message]

the calculation give as a number of range n (m bytes) so why we can storet in m - 1 bytes? because the decryption give as the original value that can be stored in m - 1.

## Ressources to more understand the maths behind it:

what is a prime number ? https://en.wikipedia.org/wiki/Prime_number 

GCD(a,b), what does it mean? https://en.wikipedia.org/wiki/Greatest_common_divisor

two integers a and b are coprime, what does it mean ? https://en.wikipedia.org/wiki/Coprime_integers

The Bézout's identity  https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity

about the extended Euclidean Algorithm : video : https://www.youtube.com/watch?v=IwRtISxAHY4 , Documentation :https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm

to read about the modular exponentiation and understand how to calculate exponentiation performed over a modulus efficiently : https://en.wikipedia.org/wiki/Modular_exponentiation



