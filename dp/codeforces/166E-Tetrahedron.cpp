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

const int N = 1e7 + 10, mod = 1e9 + 7;
int n, dp[N][4];

void solve()
{
    cin >> n;
    dp[0][0] = 1;
    dp[0][1] = 0, dp[0][2] = 0, dp[0][3] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (k == j)
                    continue;
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][0];
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