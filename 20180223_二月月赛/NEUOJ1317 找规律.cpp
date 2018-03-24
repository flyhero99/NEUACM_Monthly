#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int mod = 1000000007;

int a[20] = {1, 2, 3, 5, 7, 11, 13, 17, 23, 31, 37, 53, 71, 73, 113, 131, 137, 173, 311, 317};

int t;
int n;
int cas;

ll mypow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans = (ans*a) % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    cin >> t;
    for(int cas = 1;cas <= t;cas++) {
        cin >> n;
        int ans;
        if(n >= 317)
            ans = 317;
        else if(n == 1)
            ans = 1;
        else {
            for(int i = 0;i < 20;i++) {
                if(a[i] > n) {
                    continue;
                }
                else {
                    ans = a[i];
                }
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}