# Number Theory

My code collection on Number theory

## 1 >> GCD ~ Greatest Common Divisor
There are two versions of this one is the recursive ones which is based on **gcd(a,b) = gcd(b,a%b)**. The other one is Iterative version. The recursive one is very common which I will not add here. You can also use **`__gcd(a,b)`** (_Built in function to get the gcd of tow numbers_) Lets see the code of the iterative one :
```cpp
int gcd(int a, int b)
{
    // loops until last a%b or next b becomes 0
    while (b)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
```

## 2 >> LCM ~ Least Common Multiple 
Using the formula **`lcm(a,b) * gcd(a,b) = a * b`** . See the code :
```cpp
int lcm(int a, int b)
{
    // formula : a*b = gcd(a,b) * lcm(a,b)
    return (a / __gcd(a, b)) * b;
}
```

## 3 >> Primality Check
There are some ways to check primality. Such as : **Tipical Sqrt(N)**, **Fermat's Little theorem**, **Miller-Rabin** etc. _I prefer to use the tipical sqrt(N) one_. So I am adding that function only.
```cpp
// Returns 1 if prime and 0 if not prime
bool isPrime(int n)
{
    if (n <= 1)
        return 0;
    int lim = sqrt(n); // As it is enough to check upto root N
    for (int i = 2; i <= lim; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
```

# 4 >> Sieve of Eratosthenes 
First of all there are several types of sieve. I will add the **`optimized version of the typical sieve, Memory efficient Bitwise sieve, Segmentive sive and the linier sieve`**. Lets see the codes one by one. 
## 4.1 ~ Optimized Version of the typical Sieve : 
This one is the most common one that we use regularly. Here we will use some optimizations. Lets see the code : 
```cpp
#define MAX 300000   // Used to have the numbers of prime that we want to store
#define MAX1 1000002 // Used as the max range where we want to run the sieve

int Prime[MAX], nPrime; // list of prime and number of prime
bool mark[MAX1];        // for marking sieve approach

// for prime 0
// for not prime 1

void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.0) + 2;

    mark[1] = 1; // as 1 is not a prime
    for (i = 4; i <= n; i += 2)
        mark[i] = 1;
    //almost all of the even number is not prime

    Prime[nPrime++] = 2;
    for (i = 3; i <= n; i += 2)
        // start marking if i is a prime
        // and a is a prime if it is not marked yet
        if (mark[i] == 0)
        {
            Prime[nPrime++] = i; // i is a prime as it is unmarked
            if (i <= limit)
            {
                // all the factors of i before i*i is already marked
                // so we will start marking from i*i
                // we know that odd + odd = even and here i is an odd
                // so we will advance twice in each iteration of the loop (j = j + (i * 2))
                for (j = i * i; j <= n; j = j + (i * 2))
                {
                    mark[j] = 1; // j is a composit because it is a factor of i
                }
            }
        }
    if (0)
        printf("Prime found :: %d\n", nPrime); // how many prime we got
}
```
## 4.2 ~ Memory Efficient Bitwise Sive (Reccomanded)
## 4.3 ~ Segmentive sieve
## 4.4 ~ Linier Sieve
