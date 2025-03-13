#include <iostream>
using namespace std;
int main()
{
    int n, s[10]={0}, res=0;
    cin >> n;
    while(n>0){
        if(n % 10 == 9) s[6]++;
        else s[n % 10]++;
        n = n / 10;
    }
    s[6] = (s[6] + 1) / 2;
    for(int i=0;i<9;i++){
        if(s[i]>res) res = s[i];
    }
    cout << res;
    return 0;
}