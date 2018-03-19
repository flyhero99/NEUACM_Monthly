#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define mem(a, b) memset(a, b, sizeof(a))
#define mod 15498

const int maxn = 200010;

int t, n;

void factor(int n, int a[maxn], int b[maxn], int &tot) {
    int temp, i, now;
    temp = (int) ((double)sqrt(n)+1);
    tot = 0;
    now = n;
    for(i = 2;i <= temp;++i) {
        if(now%i == 0) {
            a[++tot] = i;
            b[tot] = 0;
            while(now%i == 0) {
                ++b[tot];
                now /= i;
            }
        }
        if(now != 1) {
            a[++tot] = now;
            b[tot] = 1;
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int cnt = 0;
        for(int i = 1;i*i <= n;i++) {
            if(n%i == 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}