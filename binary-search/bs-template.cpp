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

void solve()
{
    // Classic first true
    int l = L, r = R; // [L, R]
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }

    // last true
    int l = L, r = R; // [L, R]
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (ok(mid))
            r = mid - 1;
        else
            l = mid;
    }

    // lower bound
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
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