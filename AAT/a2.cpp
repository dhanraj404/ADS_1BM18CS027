#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

#define next next___

int x[200000], y[200000];
int u[200000], v[200000];
int next[200000];
int pr[200000];
int ti;
int a1[200000];
int a2[200000];
int h[200000];
int pred[200000][18];
int us[200000];

void dfs(int v, int p) {
    a1[v] = ti++;
    h[v] = h[p] + 1;
    pred[v][0] = p;
    if (p == 0) {
        pred[v][0] = 1;
    }
    for (int i = 1; i <= 17; i++) {
        pred[v][i] = pred[pred[v][i - 1]][i - 1];
    }
    for (int i = pr[v]; i; i = next[i]) {
        if (y[i] != p) {
            dfs(y[i], v);
        } 
    }
    a2[v] = ti++;
}

int isp(int a, int b) {
    return a1[a] <= a1[b] && a2[b] <= a2[a];
}

int lca(int a, int b) {
    if (isp(a, b)) {
        return a;
    }
    if (isp(b, a)) {
        return b;
    }
    for (int i = 17; i >= 0; i--) {
        if (!isp(pred[a][i], b)) {
            a = pred[a][i];
        } 
    }
    return pred[a][0];
}

int dist(int a, int b) {
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

int Uu[100000];
int Uv[100000];
int Mu[100000];
int Mv[100000];

void dfs_u(int v, int p, int cdist, int &u_max, int &u_ver) {
    if (Uu[v]) {
        if (cdist > u_max) {
            u_max = cdist;
            u_ver = v;
        }
    }
    for (int i = pr[v]; i; i = next[i]) {
        if (y[i] != p) {
            dfs_u(y[i], v, cdist + 1, u_max, u_ver);
        }
    }
}

void dfs_v(int v, int p, int cdist, int &u_max, int &u_ver) {
    if (Uv[v]) {
        if (cdist > u_max) {
            u_max = cdist;
            u_ver = v;
        }
    }
    for (int i = pr[v]; i; i = next[i]) {
        if (y[i] != p) {
            dfs_u(y[i], v, cdist + 1, u_max, u_ver);
        }
    }
}

int main() {   
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x[i] >> y[i];
        x[i + n - 1] = y[i];
        y[i + n - 1] = x[i];
    }
    for (int i = 1; i <= n + n - 2; i++) {
        next[i] = pr[x[i]];
        pr[x[i]] = i;
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
        Uu[u[i]] = 1;
        Uv[v[i]] = 1;
    }
    int u1 = 1, u2 = 1, u_max = 0, v1 = 1, v2 = 1, v_max = 0;        
    dfs_u(1, 0, 0, u_max, u1);
    dfs_u(u1, 0, 0, u_max, u2);
    dfs_v(1, 0, 0, v_max, v1);
    dfs_v(v1, 0, 0, v_max, v2);
    int aMax = 0;
    for (int it = 1; it <= 25; it++) {
        int T1 = rand() % m + 1, Max = 0;
        int T2 = T1;
        for (int i = 1; i <= m; i++) {
            int cur = dist(u[T1], u[i]) + dist(v[T1], v[i]); 
            if (cur > Max && !us[i]) {
                Max = cur;
                T2 = i;
            }
        }
        us[T2] = 1;
        for (int i = 1; i <= m; i++) {
            int cur = dist(u[T2], u[i]) + dist(v[T2], v[i]); 
            if (cur > Max) {
                Max = cur;
                T1 = i;
            }
        }
        aMax = max(aMax, Max);        
    }       
    vector<pair<int,int> > E;
    for (int i = 1; i <= m; i++) {
        int d = max(dist(u[i], u1), dist(u[i], u2)) +
                max(dist(v[i], v1), dist(v[i], v2));
        for (int j = 0; j < 5; j++) {
            int t = rand() % m + 1;
            d = max(d, dist(u[i], u[t]) + dist(v[i], v[t]));
        }
        E.push_back(make_pair(-d, i));        
    }   
    sort(E.begin(), E.end());
    for (int p = 0; p < E.size(); p++) {
        if (p > 25) {
            break;
        }
        int i = E[p].second;
        int d = -E[p].first;

        if (d + 10 > aMax) {
            for (int j = 1; j <= m; j++) {
                int cur = dist(u[j], u[i]) + dist(v[j], v[i]); 
                if (cur > aMax) {
                    aMax = cur;                
                }
            }
        }
    }   
    cout << aMax << endl;
	return 0;    
}