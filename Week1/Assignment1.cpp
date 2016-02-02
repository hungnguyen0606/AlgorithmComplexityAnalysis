#include <bits/stdc++.h>

using namespace std;

#define maxn 1111111
//#define maxtry 100000000

typedef long long ll;

ll a[maxn];
int n, maxtry;

double Try(int n, int times)
{
    ll ans = 0;
    int old = times;
    while(times--)
    {
        a[0] = (ll)rand()*rand()%n;
        for(int i = 1; i < n; ++i)
        {
            a[i] = (ll)rand()*rand()%n;
            if (i == n-1 || a[i] <= a[i-1])
            {
                ans += i;
                break;
            }
        }
    }

    return 1.0*ans/old;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    srand(time(0));
    cin >> maxtry;
    while (cin >> n)
    {

        cout << Try(n, maxtry) << endl;
    }

    
    /* code */
    
    return 0;
}