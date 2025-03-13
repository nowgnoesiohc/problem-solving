#include <iostream>
using namespace std;
int main()
{
    int n, m=0, idx;
    for(int i=1;i<=9;i++){
        cin >> n;
        if(m<n){
            m = n;
            idx = i;
        }
    }
    cout << m << endl << idx;
    return 0;
}