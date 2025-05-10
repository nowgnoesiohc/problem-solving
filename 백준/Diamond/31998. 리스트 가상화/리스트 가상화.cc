#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll h, sum;
    int sz, pr;
    Node *l, *r;
    Node(ll _h): h(_h), sum(_h), sz(1),
        pr(rand()), l(nullptr), r(nullptr) {}
};

int getSize(Node* t){ return t ? t->sz : 0; }
ll  getSum (Node* t){ return t ? t->sum : 0; }

void upd(Node* t){
    if (!t) return;
    t->sz  = 1 + getSize(t->l) + getSize(t->r);
    t->sum = t->h + getSum(t->l) + getSum(t->r);
}

// split t into [0..k-1] and [k..end]
void split(Node* t, int k, Node*& a, Node*& b){
    if (!t){ a = b = nullptr; return; }
    if (getSize(t->l) >= k){
        // all needed in left
        split(t->l, k, a, t->l);
        b = t;
    } else {
        split(t->r, k - getSize(t->l) - 1, t->r, b);
        a = t;
    }
    upd(t);
}

Node* merge(Node* a, Node* b){
    if (!a || !b) return a ? a : b;
    if (a->pr > b->pr){
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

// find first index k (1-based) in subtree t with prefix_sum(k) > x
int findFirstGreater(Node* t, ll x){
    if (!t || getSum(t) <= x) return getSize(t) + 1;
    if (t->l && getSum(t->l) > x)
        return findFirstGreater(t->l, x);
    ll leftSum = getSum(t->l);
    if (leftSum + t->h > x)
        return getSize(t->l) + 1;
    int sub = findFirstGreater(t->r, x - leftSum - t->h);
    return getSize(t->l) + 1 + sub;
}

// find first index k (1-based) in subtree t with prefix_sum(k) >= x
int findFirstGE(Node* t, ll x){
    if (!t || getSum(t) < x) return getSize(t) + 1;
    if (t->l && getSum(t->l) >= x)
        return findFirstGE(t->l, x);
    ll leftSum = getSum(t->l);
    if (leftSum + t->h >= x)
        return getSize(t->l) + 1;
    int sub = findFirstGE(t->r, x - leftSum - t->h);
    return getSize(t->l) + 1 + sub;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));

    int N, Q;
    cin >> N >> Q;

    Node* root = nullptr;
    // build initial treap
    for (int i = 0; i < N; i++){
        ll h; 
        cin >> h;
        root = merge(root, new Node(h));
    }

    while (Q--){
        int type;
        cin >> type;
        if (type == 1){
            int i; ll h;
            cin >> i >> h;
            // insert at position i
            Node *L, *R;
            split(root, i-1, L, R);
            root = merge( merge(L, new Node(h)), R );
        }
        else if (type == 2){
            int i;
            cin >> i;
            // erase at position i
            Node *L, *M, *R;
            split(root, i-1, L, R);
            split(R, 1, M, R);
            // delete M;
            root = merge(L, R);
        }
        else {
            ll t, b;
            cin >> t >> b;
            int n = getSize(root);
            // k_min = first k with prefix_sum(k) > t
            int k_min = findFirstGreater(root, t);
            // p = first k with prefix_sum(k) >= b
            int p     = findFirstGE(root, b);
            // k_max = min(n, p)
            int k_max = min(n, p);
            int ans = max(0, k_max - k_min + 1);
            cout << ans << "\n";
        }
    }

    return 0;
}
