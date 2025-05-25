#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

// Fenwick Tree (1-indexed)
struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int _n): n(_n), f(n+1, 0) {}
    // add v at position i (0-based)
    void update(int i, ll v) {
        for(int x = i+1; x <= n; x += x & -x)
            f[x] += v;
    }
    // sum of [0..i] (0-based)
    ll query(int i) const {
        ll s = 0;
        for(int x = i+1; x > 0; x -= x & -x)
            s += f[x];
        return s;
    }
    // sum of [l..r], 0-based
    ll rangeQuery(int l, int r) const {
        if(l > r) return 0;
        return query(r) - (l>0 ? query(l-1) : 0);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> centers(M);
    for(int i = 0; i < M; i++){
        cin >> centers[i];
    }

    // graph & m[v]: min incident edge weight
    vector<vector<pair<int,ll>>> adj(N+1);
    vector<ll> m(N+1, INF);
    struct Edge { int u,v; ll w; };
    vector<Edge> edges;
    edges.reserve(K);

    for(int i = 0; i < K; i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
        m[u] = min(m[u], w);
        m[v] = min(m[v], w);
        edges.push_back({u,v,w});
    }

    // multi-source Dijkstra with "id" propagation (0 = ambiguous)
    vector<ll> dist(N+1, INF);
    vector<int> id(N+1, 0);
    // min-heap of (d, node, source_id)
    struct Node { ll d; int v, src; };
    struct Cmp { bool operator()(Node const&a, Node const&b) const {
        return a.d > b.d;
    }};
    priority_queue<Node, vector<Node>, Cmp> pq;
    // init
    for(int c: centers){
        pq.push({0, c, c});
    }

    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        ll d = top.d;
        int u = top.v;
        int sid = top.src;
        // relax logic
        bool propagate = false;
        if(d < dist[u]){
            dist[u] = d;
            id[u] = sid;
            propagate = true;
        }
        else if(d == dist[u] && id[u] != sid){
            id[u] = 0;
            sid = 0; 
            propagate = true;
        }
        else {
            continue;
        }
        // propagate to neighbors
        for(auto &pr: adj[u]){
            int v = pr.first;
            ll w = pr.second;
            ll nd = d + w;
            if(nd < dist[v] || (nd == dist[v] && id[v] != 0)){
                // even if nd>dist[v], we still want to push if nd==dist[v] and id[v] would change to 0 via sid==0
                pq.push({nd, v, sid});
            }
        }
    }

    // compress dist[]
    vector<ll> allD(N);
    for(int i = 1; i <= N; i++){
        allD[i-1] = dist[i];
    }
    sort(allD.begin(), allD.end());
    allD.erase(unique(allD.begin(), allD.end()), allD.end());
    auto getDidx = [&](ll d){
        return int(lower_bound(allD.begin(), allD.end(), d) - allD.begin());
    };

    // prepare Fenwick over dist
    Fenwick fw((int)allD.size());
    // we'll build a list sorted by (m[u], u)
    vector<pair<ll,int>> vs(N);
    for(int i = 1; i <= N; i++){
        vs[i-1] = {m[i], i};
        fw.update(getDidx(dist[i]), 1);
    }
    sort(vs.begin(), vs.end(), [&](auto &a, auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    // count total qualifying pairs S
    ll S = 0;
    for(int i = 0; i < N; i++){
        ll mu = vs[i].first;
        int u  = vs[i].second;
        ll du = dist[u];
        // dist range [du-mu, du+mu]
        ll L = du - mu, R = du + mu;
        // find indices in allD
        int li = int(lower_bound(allD.begin(), allD.end(), L) - allD.begin());
        int ri = int(upper_bound(allD.begin(), allD.end(), R) - allD.begin()) - 1;
        if(li < 0) li = 0;
        if(ri >= (int)allD.size()) ri = (int)allD.size() - 1;
        if(li <= ri){
            ll cnt = fw.rangeQuery(li, ri);
            // subtract self
            cnt -= 1;
            if(cnt > 0) S += cnt;
        }
        // remove u
        fw.update(getDidx(du), -1);
    }

    // subtract existing edges that also satisfy threshold>=|du-dv|
    ll exist_ok = 0;
    for(auto &e: edges){
        ll d1 = dist[e.u], d2 = dist[e.v];
        ll diff = d1 > d2 ? d1 - d2 : d2 - d1;
        ll thr = min(m[e.u], m[e.v]);
        if(thr >= diff) exist_ok++;
    }

    ll answer = S - exist_ok;
    cout << answer << "\n";
    return 0;
}
