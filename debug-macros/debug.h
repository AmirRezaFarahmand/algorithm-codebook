#pragma once
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", _print(__VA_ARGS__), cerr << "\n"
#else
#define debug(...) ((void)0)
#endif

void __print(int x) { cerr << x; }
void __print(long long int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename U>
void __print(const pair<T, U> &p)
{
    cerr << '{';
    __print(p.first);
    cerr << ", ";
    __print(p.second);
    cerr << '}';
}

template <typename T>
void __print(const T &x)
{
    cerr << '{';
    bool first = true;
    for (auto &i : x)
    {
        if (!first) cerr << ", ";
        first = false;
        __print(i);
    }
    cerr << '}';
}

void _print() {}

template <typename T, typename... Ts>
void _print(const T &t, const Ts &...ts)
{
    __print(t);
    if (sizeof...(ts)) cerr << ", ";
    _print(ts...);
}