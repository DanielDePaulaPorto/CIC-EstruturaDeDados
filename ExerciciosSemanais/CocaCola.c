#include <stdio.h>

int bebe_garrafas(int garrafas_vazias){
    if(garrafas_vazias < 2){
        return 0;
    } else if (garrafas_vazias == 2){
        return 1;
    }
    return 1 + bebe_garrafas(garrafas_vazias-2);
}

int main(){
    int garrafas_vazias;

    scanf("%d",&garrafas_vazias);
    do{
        printf("%d\n",bebe_garrafas(garrafas_vazias));
        scanf("%d",&garrafas_vazias);
    } while (garrafas_vazias>0);

    return 0;
}