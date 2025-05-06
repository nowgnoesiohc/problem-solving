#include <stdio.h>
#include <string.h>

int main() {
    char name[32];
    int count;
    char best_name[32] = "";
    int best_count = -1;

    for (int i = 0; i < 7; i++) {
        scanf("%31s %d", name, &count);
        if (count > best_count) {
            best_count = count;
            strcpy(best_name, name);
        }
    }

    printf("%s\n", best_name);
    return 0;
}
