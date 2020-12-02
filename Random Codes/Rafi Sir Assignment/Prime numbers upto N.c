/*
    Name : Md. Mehrajul Islam
    Reg. Number: 2019831074
    Problem Number : 2
    Problem : Write a code to print the prime numbers within a given of 1 to n
*/

#include <stdio.h>
#include <stdbool.h>

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
    if (1)
        printf("\tPrime found :: %d\n\n", nPrime); // how many prime we got
}

int main()
{
    int n, i;
    printf("\n\n\tEnter the value of N to see the prime numbers upto N\n\n\tN = ");
    scanf("%d", &n);

    printf("\n");
    sieve(n);

    for (i = 0; i < nPrime; i++)
    {
        printf("\t>>> %d th prime is = %d\n", i + 1, Prime[i]);
    }
    return 0;
}
