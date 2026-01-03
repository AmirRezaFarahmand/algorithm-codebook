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

const int MAXn = 1e5 + 10, INF = 2e9 + 10;
int n, x[MAXn], h[MAXn], dp[MAXn][3];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> h[i];
    h[0] = -INF, h[n + 1] = INF;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1]});
        if (x[i] > x[i - 1] + h[i - 1])
            dp[i][0] = max(dp[i][0], dp[i - 1][2]);

        if (x[i] - h[i] > x[i - 1])
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        if (x[i] - h[i] > x[i - 1] + h[i - 1])
            dp[i][1] = max(dp[i][1] - 1, dp[i - 1][2]) + 1;

        dp[i][2] = dp[i][0] + 1;
    }
    cout << max(dp[n][1], dp[n][2]);
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