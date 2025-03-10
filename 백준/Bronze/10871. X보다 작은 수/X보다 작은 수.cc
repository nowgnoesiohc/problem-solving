#include <iostream>
using namespace std;
int main()
{
    int N, X;
    cin >> N >> X;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(num<X) cout << num << " ";
    }
    return 0;
}