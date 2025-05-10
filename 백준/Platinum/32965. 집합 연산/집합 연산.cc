#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) 입력
    int N;
    cin >> N;

    unordered_set<ll> S;
    S.reserve(N * 2);        // 대략적인 리저브
    ll sum = 0;

    for(int i = 0; i < N; i++){
        ll x;
        cin >> x;
        S.insert(x);
        sum += x;
    }

    int Q;
    cin >> Q;

    // 2) 질의 처리 (연산은 누적)
    //    각 질의마다 K_i번 시뮬레이션하고, 그 시점의 합을 출력
    while(Q--){
        ll K;
        cin >> K;
        // K번 반복
        for(ll i = 0; i < K; i++){
            ll m = (ll)S.size();
            auto it = S.find(m);
            if(it != S.end()){
                // m이 이미 있으면 제거
                S.erase(it);
                sum -= m;
            } else {
                // m이 없으면 추가
                S.insert(m);
                sum += m;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
