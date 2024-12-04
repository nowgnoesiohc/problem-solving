#include <stdio.h>
int main(){
    int arr[101][101] = {};
    
    int n, m, x = 1, y = 1, x1 = 1, y1 = 1;
    scanf("%d %d", &n, &m);
    int i, j, num = 1;
    for(i = 1; i <= n*m; i++){
        arr[x][y] = num++;
        if(x - 1 >= 1 && y + 1 <= m){
            x--;
            y++;
        }
        else if(x1 + 1 <= n){
            x1++;
            x = x1;
            y = y1;
        }
        else{
            y1++;
            x = x1;
            y = y1;
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
