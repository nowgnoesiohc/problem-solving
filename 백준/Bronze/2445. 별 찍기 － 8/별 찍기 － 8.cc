#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cout << "*";
        for(int j=2*n;j>2*i;j--) cout << " ";
        for(int j=1;j<=i;j++) cout << "*";
        cout << endl;
    }
    for(int i=1;i<n;i++){
        for(int j=n;j>i;j--) cout << "*";
        for(int j=1;j<2*i+1;j++) cout << " ";
        for(int j=n;j>i;j--) cout << "*";

        cout << endl;
    }

    return 0;
}