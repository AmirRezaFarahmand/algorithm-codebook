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

const int N = 1010, INF = 2e9;
int n, m, x, y, cnt[N][2], dp[N][2];

void solve()
{
    for (int i = 0; i < N; i++)
        dp[i][0] = INF, dp[i][1] = INF;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '#')
                cnt[j][1]++;
            else
                cnt[j][0]++;
        }
    }

    for (int i = 2; i <= m; i++)
        cnt[i][0] += cnt[i - 1][0], cnt[i][1] += cnt[i - 1][1];

    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = x; j <= y; j++) {
            if (i - j < 0)
                continue;
            dp[i][0] = min(dp[i][0], dp[i - j][1] + cnt[i][1] - cnt[i - j][1]);
            dp[i][1] = min(dp[i][1], dp[i - j][0] + cnt[i][0] - cnt[i - j][0]);
        }
    }
    cout << min(dp[m][0], dp[m][1]);
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