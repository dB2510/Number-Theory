// It is a problem at https://www.hackerrank.com/challenges/twins/problem

#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define fi(i,a,n) for(lli i = a; i < n; i++)
#define fd(i,a,n) for(lli i = a; i > n; i--)
#define fv(i,a) for(auto i:a)
#define pb push_back
#define mp make_pair

lli binpower(lli base, lli e, lli mod) {
    lli result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(lli n, lli a, lli d, lli s) {
    lli x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (lli r = 1; r < s; r++) {
        x = (x * x) % n;
        if (x == n - 1)
            return false;
    }
    return true;
}
 
bool MillerRabin(lli n) {
    if (n < 2)
        return false;

    lli r = 0;
    lli d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (lli a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout<<fixed<<setprecision(10);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
lli t=1;
//cin>>t;
while(t--)
{
    lli l,r;
    cin>>l>>r;
    lli ans=0;
    for(lli i=l;i<=r;i++)
    {
        if(i%6==1)
        {
            if((i-2>=l) && MillerRabin(i) && MillerRabin(i-2))
                ans++;
        }
    }
    if(l<=3 && r>=5)
        ans++;
    cout<<ans;
}
return 0;
}