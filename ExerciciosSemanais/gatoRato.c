#include "stdio.h"
#include "stdlib.h"

void verificaQuemPegaORato(int disX, int disY);

int main(){
    int q,x,y,z;

    scanf("%d",&q);

    for (int i = 0; i < q; ++i) {

        scanf("%d %d %d",&x,&y,&z);

        int disX,disY;
        disX = abs(z-x);
        disY = abs(z-y);

        verificaQuemPegaORato(disX,disY);
    }


}


void verificaQuemPegaORato(int disX, int disY){
    if( disX == disY){
        printf("Mouse C\n");
        return;
    }

    char *gato = disX < disY ? "Cat A\n":"Cat B\n";
    printf("%s",gato);
}