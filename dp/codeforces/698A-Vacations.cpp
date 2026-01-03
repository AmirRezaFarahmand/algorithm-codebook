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

const int MAXn = 110, INF = 2e9 + 10;
int n, a[MAXn], dp[MAXn][3];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < MAXn; i++)
        dp[i][0] = INF, dp[i][1] = INF, dp[i][2] = INF, dp[i][3] = INF;

    dp[0][0] = 1;
    if (a[0] == 1 || a[0] == 3)
        dp[0][1] = 0;
    if (a[0] == 2 || a[0] == 3)
        dp[0][2] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        if (a[i] == 1 || a[i] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        if (a[i] == 2 || a[i] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
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