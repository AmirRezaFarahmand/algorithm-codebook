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

const int N = 5010;
int n;
vi g[N];

bool bfs(int s) {
    for (auto u : g[s]) {
        for (auto v : g[u]) {
            for (auto x : g[v]) {
                if (x == s)
                    return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        g[i].pb(--f);
    }

    for (int i = 0; i < n; i++) {
        if (bfs(i)) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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