#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int h[10]={0}, total=0;
    for(int i=1;i<=9;i++){
        cin >> h[i];
        total += h[i];
    }
    sort(h, h+10);
    for(int i=1;i<=9;i++){
        for(int j=i;j<=9;j++){
            if(total - h[i] - h[j] == 100){
                for(int k=1;k<=9;k++){
                    if(k!=i && k!=j) cout << h[k] << endl;
                }
                return 0;
            }
        }
    }
    return 0;
}