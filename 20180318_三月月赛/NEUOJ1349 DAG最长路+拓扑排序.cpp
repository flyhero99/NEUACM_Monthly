#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 20005;
const int maxm = 121111;

struct node {
    int v, w, next;
}edge[maxm];

int no, head[maxn];
int t, n, m;
int deg[maxn], val[maxn];
queue<int> q;

void init() {
    no = 0;
    memset(head, -1, sizeof head);
    memset(deg, 0, sizeof deg);
    memset(val, 0, sizeof val);
}

inline void addEdge(int u, int v, int w) {
    edge[no].v = v; edge[no].w = w;
    edge[no].next = head[u];
    head[u] = no++;
}

int topsort() { // 拓扑排序
    while(!q.empty()) q.pop();
    for(int i = 1;i <= n;++i)
        if(!deg[i]) q.push(i);
    int ans = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int k = head[u];k+1;k = edge[k].next) {
            int v = edge[k].v;
            val[v] = max(val[v], edge[k].w+val[u]);
            if(--deg[v] == 0) q.push(v);
        }
    }
    int aaa = 0;
    for(int i = 1;i <= n;i++) {
        aaa = max(val[i], aaa);
    }
    return aaa+1;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m); init();
        for(int i = 1;i <= m;++i) {
            int u, v, w;
            scanf("%d %d", &u, &v);
            addEdge(u+1, v+1, 1);
            ++deg[v+1];
        }
        int ans = topsort();
        printf("%d\n", ans);
    }
    return 0;
}