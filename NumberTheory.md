# Number Theory

My code collection on Number theory

## 1 >> Primality Check
There are some ways to check primality. Such as : Tipical Sqrt(N), Fermat's Little theorem, Miller-Rabin etc. I prefer to use the tipical sqrt(N) one. So I am adding that function only.
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
