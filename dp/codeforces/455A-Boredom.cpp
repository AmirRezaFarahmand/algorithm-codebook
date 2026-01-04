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

const int N = 1e5 + 10;
int n, a[N], cnt[N];
ll dp[N][2];

void solve()
{
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]] ++;
        mx = max(mx, a[i]);
    }

    for (int i = 1; i <= mx; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = 1ll * cnt[i] * i + dp[i - 1][0];
    }

    cout << max(dp[mx][0], dp[mx][1]);
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