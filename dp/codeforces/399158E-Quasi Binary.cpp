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

const int N = 1e6 + 10;
int n, dp[N], ans[N];
vector <ll> qb;

void quasi_binary(ll m)
{
    if (m > n)
        return;
    ll t = m * 10LL;
    qb.push_back(t);
    quasi_binary(t);
    qb.push_back(t + 1);
    quasi_binary(t + 1);
}

void solve()
{
    memset(dp, 1e9 + 7, sizeof(dp));
    cin >> n;
    dp[0] = 0;
    qb.push_back(1);
    quasi_binary(1);
    sort(all(qb));

    for (int i = 1; i <= n; i++)
    {
        for (auto q : qb)
        {
            if (i >= q && dp[i - q] + 1 < dp[i])
            {
                dp[i] = dp[i - q] + 1;
                ans[i] = i - q;
            }
        }
    }
    cout << dp[n] << endl;
    while (n)
    {
        cout << n - ans[n] << " ";
        n = ans[n];
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