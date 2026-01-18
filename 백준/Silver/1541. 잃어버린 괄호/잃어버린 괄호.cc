#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char arr[100];
    scanf("%s", arr);
    
    int result = 0, tmp = 0, num=0, minusFlag=0;
    
    for(int i=0;i<=strlen(arr);i++){
        if(arr[i]>='0' && arr[i]<='9'){
            num = num * 10 + (arr[i] - '0');
        }
        else{
            tmp = tmp + num;
            num = 0;
            
            if(arr[i]=='-' || arr[i]=='\0'){
                if(minusFlag==1) result = result - tmp;
                else result = result + tmp;
                
                tmp = 0;
                minusFlag = 1;
            }
        }
    }
    
    printf("%d", result);

    return 0;
}