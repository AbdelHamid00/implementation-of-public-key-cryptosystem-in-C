# RSA-implemented-in-C
simple RSA implementation .

## some arithmetiques knowledge to read and understand before start reading the RSA implementation :
A prime number is a natural number that has exactly two distinct natural number divisors: 1 and itself. All prime numbers are grater than 1 and impair .

the fundamental theorem of arithmetic states that every integer larger than 1 can be written as a product of one or more primes. Writing a number as a product of prime numbers is called a prime factorization of the number. For example: 34866 = 2 * 3 * 3 * 13 * 149.

The greatest common divisor (GCD) of two nonzero integers a and b is the greatest positive integer d such that d is a divisor of both a and b; that is, there are integers e and f such that a = de and b = df, and d is the largest such integer. The GCD of a and b is generally denoted gcd(a, b).example :
54 = 2 * 3 * 3 * 3 and 24 = 2 * 2 * 2 * 3 so the gcd(54, 24) = 2 * 3 = 6
another approach to see it :
Thus the complete list of divisors of 54 is {1,2,3,6,9,18,27,54} Similarly, the divisors of 24 are 1,2,3,4,6,8,12,24}. The numbers that these two lists have in common are the common divisors of 54 and 24, that is, {1,2,3,6}.
Of these, the greatest is 6, so it is the greatest common divisor: gcd(54,24) = 6.

In mathematics, two integers a and b are coprime, relatively prime or mutually prime if the only positive integer that is a divisor of both of them is 1. Consequently, any prime number that divides a does not divide b, and vice versa. This is equivalent to their greatest common divisor (GCD) being 1. One says also a is prime to b or a is coprime with b. example :
3 and 5 , two prime numbers and GCD(3,5) = 1.

Bézout's identity — Let a and b be integers with greatest common divisor d. Then there exist integers x and y such that ax + by = d. Moreover, the integers of the form az + bt are exactly the multiples of d.

## the Key programme :
the key programme generate 3 numbers (e and n and d), represent them in two files of size 16 bytes, key_rsa and key_rsa.pub , key_rsa containe d and n (private key), key_rsa.pub containe e and n (public key). 
How i did it ?
I generate two prime number using Rand function and change the argument seed using Srand function with time as parametre , so every second the rand generate a different number.
then calculate [n = p * q] and [f = (p - 1)*(q - 1)]
e is coprime with f . To find e and d i initialize e with max(p,q) , why max(p,q)? to stay in the same range and keep it hard to reverse. I iterate e tel GCD(e,f) = 1 and d > 0,  using Euclidean algorithme proceeds
the simple Euclidean algorithme used to compute only GCD(a, b) = GCD(b, a % b), to find the GCD of two numbers example:
GCD(1234, 124) = GCD(124, 118) = GCD(118, 6) = GCD(6, 4) = GCD(4, 2) = 2 .
but the Euclidean algoorithem proceeds, go back and calculate the 


finally lets prepare the keys, public key file (16bytes) containe e and n [8bytes = e][8bytes = n], 
                              privat key file (16bytes) containe d and n [8bytes = d][8bytes = n].

## crypt and decrypt programme : 
lets say me and Aimad we want to start a conversation , first we need to generate our keys then send our public key to each other. 
Now Aimad open a file using text editeur and write a message and crypt it using my public key and send it to me.
I receive it and decrypt it using my own private key.

to crypt a message i need to know one thing before starting, how many bytes n is occupating because all the calculation are modulo n (whitch means tha every crypted value is of range 0 to n -1). lets say that n occupate m bytes.

how Aimad crypt the message? , first gets e and n from my public key, , i read the message from the end and get the value of every m - 1 bytes , and calculate the value power of e modulo[n], and storet in m bytes in the encrypted message.

i get d and n from my privat key. and start decrypting it, i read read the crypted message from the end and get the value of every m bytes, and calculate the value power of d modulo n, and storet in m - 1 bytes in the decrypted message .

## The maths behind it:
  we 


## how i calculate a power of e or d modulo n efficiently :




