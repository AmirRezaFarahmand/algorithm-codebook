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

const int N = 5e5 + 10;
ll n, a[N], dp[N], ps[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i];

    if (ps[n] % 3) {
        cout << 0;
        return;
    }

    ll s13 = ps[n] / 3ll;
    ll s23 = 2ll * s13;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        if (ps[i] == s23)
            ans += dp[i];
        if (ps[i] == s13)
            dp[i] ++;
    }
    cout << ans;
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