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
This version of sieve is very memeory efficient as well as it is also faster than the normal one. So I reccomand to use this version of the sieve. This will use each bit to store the information about marking primes. Here is the code
```cpp
// Bitwise Sieve Implementation
#define MAX 100000000
int marked[MAX / 64 + 2]; // each index will have 64 bits for marking
vector<int> prime;        // used to store the primes

#define on(x) (marked[x / 64] & (1 << ((x % 64) / 2)))
// To check if x number's bit is 1 or 0
#define mark(x) marked[x / 64] |= (1 << ((x % 64) / 2))
// to mark x number's bit

// Function to check if a certain number is prime or not
bool isPrime(int num)
{
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

// The main sieve function
void sieve(int n)
{
    // we will avoid storing the even numbers
    // so we will go from 3 to sqrt(N)
    int lim = sqrt(n);
    for (int i = 3; i <= lim; i += 2)
    {
        if (!on(i))
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                mark(j);
            }
        }
    }
    prime.push_back(2);
    for (int i = 3; i < n; i += 2)
    {
        if (isPrime(i))
            prime.push_back(i);
    }
}
```
## 4.3 ~ Segmentive sieve
Sometimes we need to get primes which are more than `10^8` and that can not be done faster even using efficient bitwise sieve. If we need to get primes on a `specific range [L:R]`, such that `R-L < 10^8` and `R < 10^16` then we can use the _**segmentive sieve**_. See the code :
```cpp
// Returns list of primes in the range [L:R]
vector<bool> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)

    long long lim = sqrt(R) + 2, i, j, x;
    vector<bool> mark(lim + 1, 0);
    vector<long long> primes;

    primes.push_back(2);

    for (i = 3; i <= lim; i += 2)
        if (mark[i] == 0)
        {
            primes.push_back(i);

            for (j = i * i; j <= lim; j = j + (i + i))
            {
                mark[j] = 1;
            }
        }

    // sieve in the range [L:R] using primes upto Root(R)a
    vector<bool> isPrime(R - L + 1, 1);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = 0;
    if (L == 1)
        isPrime[0] = 0;
    
    // Prinitng the primes
    if (1)
    {
        x = L;
        for (auto lol : isPrime)
        {
            if (lol)
                cout << x << endl;
            x++;
        }
    }
    return isPrime;
}
```
## 4.4 ~ Linier Sieve
To know about linier sieve [click here](https://codeforces.com/blog/entry/54090). I am just adding the function here :
```cpp
#define MAXN 100000000

vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	fill (is_composite, is_composite + n, 0);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
```
# 5 >> List of Divisors
Maybe you will need this... Don't know why! btw, Code : 
```cpp
// Function to get the divisors
vector<int> getDivisors(int n)
{
    // up to root n
    int lim = sqrt(n);
    vector<int> divisors;

    for (int i = 1; i <= lim; i++)
    {
        if (n % i == 0)
        {
            // divisors are equal, take one
            if (n / i == i)
                divisors.push_back(i);

            // Otherwise take both
            else
            {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
```
# 6 >> PPF ~ Prime Factorization
This one is very much important for many many things as it is an unique representation of the numbers and it has a ton of applications too... Jump into the code :
```cpp
// Bitwise Sieve Implementation
#define MAX 100000000
int marked[MAX / 64 + 2]; // each index will have 64 bits for marking
vector<int> prime;        // used to store the primes

#define on(x) (marked[x / 64] & (1 << ((x % 64) / 2)))
// To check if x number's bit is 1 or 0
#define mark(x) marked[x / 64] |= (1 << ((x % 64) / 2))
// to mark x number's bit

// Function to check if a certain number is prime or not
bool isPrime(int num)
{
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

// The main sieve function
void sieve(int n)
{
    // we will avoid storing the even numbers
    // so we will go from 3 to sqrt(N)
    int lim = sqrt(n);
    for (int i = 3; i <= lim; i += 2)
    {
        if (!on(i))
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                mark(j);
            }
        }
    }
    prime.push_back(2);
    for (int i = 3; i < n; i += 2)
    {
        if (isPrime(i))
            prime.push_back(i);
    }
}

// returns the prime factiorization of a number n
map < int , int > PrimeFactorize(long long n){

    map < int , int > ppf;
    int lim = sqrt(n);
    sieve(lim + 2);
    for(auto num : prime){
        while(n % num == 0){
            n /= num;
            ppf[num]++;
        }
    }
    if(n > 1) ppf[n]++;
    return ppf;
}
```

# 7 >> NOD ~ Number Of Divisors
There is a formula of calculating NOD(x) using the PPF. Lets see that implementation :
```cpp
// Use the PPF function from above
// Function to get the number of divisors
int NOD(long long n){
    int ans = 1;
    map < int , int > ppf ;
    ppf = PrimeFactorize(n);
    for(auto PRIME : ppf) ans *= (PRIME.second + 1);
    return ans;
}
```

# 8 >> SOD ~ Sum Of Divisors
There is a formula of calculating SOD(x) using the PPF. Lets see that implementation :
```cpp
// Use the PPF function from above
// Function to get the sum of divisors
int SOD(long long n){
    long long temp,  ans = 1;
    map < int , int > ppf ;
    ppf = PrimeFactorize(n);
    for(auto PRIME : ppf) {
        temp = 0;
        for(int i = 0 ; i <= PRIME.second ; i++) temp += pow(PRIME.first,i);
        ans *= temp;
    }
    return ans;
}
```
Function of SOD without PPF function is given below :
```cpp
// Use the sieve function from above
// Function to get the sum of divisors
int SOD(long long n){
    //sieve(MAX);
    int temp,  ans = 1, i;
    for(auto num : Prime){
        if(num > n) break;
        i = temp = 1;
        while(n % num == 0){
            n /= num;
            temp += pow(num,i++);
        }
        ans *= temp;
    }
    if(n > 1) ans *= (1+n);
    return ans;
}
```
# 9 >> Extended GCD using Extended Eucledian Algorithm
We produce use Bezout's Identity for any integer (a,b) where ax+by = gcd(a,b); here we need to calculate (x,y). See this link to see the algorithom's explanation. For now lets jump into the code :
```cpp
// Function to calculate egcd of (a,b) as Bezout's Identity (x,y)
int egcd(int a, int b, int &x , int &y){
	
	int r, q, r1=min(a,b), r2=max(a,b), x2=(a>b), x1=(b>a), y1=(!(x1)), y2=(!(x2));
	
	while(1){
		q = r2/r1;
		r = r2 - (q * r1);
		if(r == 0) break;
		x = x2 - (q * x1);
		y = y2 - (q * y1);
		r2 = r1; r1 = r;
		x2 = x1; x1 = x;
		y2 = y1; y1 = y;
	}

	//cout << a << "*(" << x << ") + " << b << "*(" << y << ") = " << r1 << endl;
	
	return r1;
}
```

# 10 >> Multiplicative Mod [ (a*b)%m ] :
This function can calculate (a*b)%m by ignoring overflow : 
```cpp
// To compute (a * b) % MOD
long long int mulmod(long long int a, long long int b,
                     long long int mod)
{
    long long int res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {

        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}
```
