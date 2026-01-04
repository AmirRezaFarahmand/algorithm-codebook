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

const int N = 101, K = 11, mod = 1e8;
int n1, n2, k1, k2, dp[N][N][K][K];

void solve()
{

    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 0; k <= k1; k++) {
                for (int t = 0; t <= k2; t++) {
                    if (!i && !j) {
                        dp[i][j][k][t] = 1;
                        continue;
                    }

                    if (k && i)
                        dp[i][j][k][t] = (dp[i][j][k][t] + dp[i - 1][j][k - 1][k2]) % mod;
                    if (t && j) 
                        dp[i][j][k][t] = (dp[i][j][k][t] + dp[i][j - 1][k1][t - 1]) % mod;
                }
            }
        }
    }

    cout << dp[n1][n2][k1][k2];
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