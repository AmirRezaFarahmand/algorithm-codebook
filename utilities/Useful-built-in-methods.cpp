#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define all(s) s.begin(), s.end()
#define pb(s) push_back(s)
typedef long long int ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <long long int> vll;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve()
{
    // Usefull built-in

    // Find lower bound -> x
    lower_bound(begin, end, x);

    // Remove an element
    v.erase(remove(v.begin(), v.end(), x), v.end());
    v.erase(remove_if(v.begin(), v.end(), pred), v.end());
    
    // Fill Array
    memset(arr, init_val, sizeof(arr)); // dont use for "1" | good for -1, 0

    fill(a, a + N, init_val);
    fill(v.begin(), v.end(), init_val);


    // Math buit-in
    min({a, b, c})
    gcd(a, b), lcm(a, b) // __gcd(a, b) 
    abs(x) && llabs(x) && fabs(x)
}   

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //cout << fixed << setprecision(3);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //fflush(stdout);
    int ntc = 1;
    //cin >> ntc;
    while (ntc --)
        solve();
}