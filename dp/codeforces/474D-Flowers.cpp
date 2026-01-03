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

const int N = 1e5 + 10, mod = 1e9 + 7;
int q, k, dp[N];

void solve()
{
    cin >> q >> k;
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1];
        if (i >= k)
            dp[i] = (1ll * dp[i] + dp[i - k]) % mod;
    }

    for (int i = 1; i < N; i++)
        dp[i] = (1ll * dp[i - 1] + 1ll * dp[i]) % mod;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + mod) % mod << '\n';
    }
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