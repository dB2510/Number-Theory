#include<bits/stdc++.h>

// To find the number of primes in a given range 1 to n

int main()
{
    int n;
    std :: cin >> n;
    bool is_prime[n+1];
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false; // 0 & 1 are not prime, so excluding them
    is_prime[1] = false;
    for(int i = 4;i <= n;i += 2) // Excluding all the even numbers except 2
    is_prime[i] = false;
    for(int i = 3;i <= n;i += 2) // Checking only for the odd ones
    {
        if(is_prime[i])
        {
            for(int j = i*i;j <= n;j+=i)
            is_prime[j] = false;
        }
    }
    int no_of_primes = 0;
    for(int i = 2;i <= n;i++)
    {
        if(is_prime[i])
        {
            std :: cout << i << " ";
            no_of_primes++;
        }
    }
    std :: cout  << std :: endl << no_of_primes << std :: endl;
    return 0;
}