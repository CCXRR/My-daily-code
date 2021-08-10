//辗转相除法求最大公约数
#include <stdio.h>

int main() {
    int i,j,t;
    int tmp;
    
    scanf("%d%d", &i, &j);
    if(i < j) {
        tmp = i;
        i = j;
        j = tmp;
    }
    for (;i % j;) {
        t = i % j;
        i = j;
        j = t;
    }
    printf("最大公约数为:%d\n", j);
    
    return 0;
}
