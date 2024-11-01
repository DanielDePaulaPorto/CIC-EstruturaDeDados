#include <stdio.h>
#include <math.h>

int main() {
    int file_size, total_transferido = 0, seg = 1, transferido_intervalo = 0;

    scanf("%d", &file_size);
    printf("Data size of %d bytes:\n", file_size);
    while(total_transferido < file_size){
        int bytes_tranferidos_nesse_segundo;
        scanf("%d", &bytes_tranferidos_nesse_segundo);
        getchar();
        transferido_intervalo += bytes_tranferidos_nesse_segundo;
        total_transferido += bytes_tranferidos_nesse_segundo;

        if(seg%5 == 0){
            if(transferido_intervalo == 0) printf("Time remaining: stalled\n");
            else{
                float taxa_transferecia = (float)total_transferido/seg;
                float remaining = ceil((file_size-total_transferido)/taxa_transferecia);
                printf("Time remaining: %d seconds\n", (int)remaining);
                transferido_intervalo = 0;
            }
        }

        seg++;
    }
    printf("Total time: %d seconds\n", seg-1);
    return 0;
}