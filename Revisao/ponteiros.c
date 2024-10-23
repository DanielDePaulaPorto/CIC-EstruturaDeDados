#include "stdio.h"
int main(){
    int a = 10;
    int* x = &a;
    int** y= &x;

    printf("a - Valor: %d - End: %d\n",a,&a);
    printf("x - Valor: %d - End: %d - *x:%d\n",x,&x,*x);
    printf("y - Valor: %d - End: %d - *y:%d - **y:%d\n",y,&y,*y,**y);

}