#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f

const int maxn = 105;
const int maxm = 10005;

vector<ll> cards;
ll d[maxn][maxn];

ll MinScore(ll n) {
    memset(d, 0, sizeof(d));
    ll len;
    for(len = 1;len < n;len++) {
        ll i, j, k;
        for(i = 1, j = len+1;j < n;i++, j++) {
            ll min = inf;
            for(k = i; k < j; k++) {
                ll sss = (ll) cards[i-1]+cards[k]+cards[j];
                ll count = (ll) d[i][k] + d[k+1][j] + sss*sss;
                if(count < min) {
                    min = count;
                }
            }
            d[i][j] = min;
        }
    }
    return d[1][n-1];
}

int main() {
    ll ncards;
    while(scanf("%lld", &ncards) != EOF) {
        ll i, x;
        cards.clear();
        for(i = 0;i < ncards;i++) {
            scanf("%lld", &x);
            cards.push_back(x);
        }
        printf("%lld\n", MinScore(ncards));
    }
    return 0;
}