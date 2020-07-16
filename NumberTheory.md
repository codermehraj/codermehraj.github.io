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
