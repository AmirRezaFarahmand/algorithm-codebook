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

const int N = 2010;
int n;
bool mark[N];
vi g[N];

int dfs(int x) {
    mark[x] = 1;
    int d = 0;
    for (auto u : g[x])
        if (!mark[u])
            d = max(d, dfs(u));

    return d + 1;
}

void solve()
{
    cin >> n;
    queue <int> s;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p != -1)
            g[--p].pb(i);
        else
            s.push(i);
    }

    int ans = 0;
    while (!s.empty()) {
        int u = s.front(); s.pop();
        ans = max(ans, dfs(u));
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