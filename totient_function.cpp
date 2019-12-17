#include <iostream>

// We have to find the numbers which are coprime with n and less than equal to n
// For that we use formula of totient function which is
// phi(n) = n * (1 - 1/p1) * (1 - 1/p2) .... * (1 - 1/pk)
// where p1, p2,...,pk are prime divisors of n

int totient(int n)
{
    int result = n;
    for(int i = 2;i * i <= n;i++)
    {
        if(n % i == 0)
        {
            while (n%i==0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
    result -= result / n;
    return result;
}

int main()
{
    int n;
    std :: cin >> n;
    std :: cout << totient(n) << std :: endl;
}