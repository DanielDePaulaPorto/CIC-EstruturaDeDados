#include <stdio.h>

double fibonacci(int n, double* calculados){
    if(calculados[n]>0){
        return calculados[n];
    }
    calculados[n] = fibonacci(n-1,calculados) + fibonacci(n-2,calculados);
    return calculados[n];
}

int main (){

    int n;
    scanf("%d",&n);
    double calculados[n+1];
    for (int i = 0; i <=n ; ++i) {
        calculados[i] = -1;
    }
    calculados[0] = 1;
    calculados[1] = 1;

    printf("%.f",fibonacci(n,calculados));

    return 0;
}