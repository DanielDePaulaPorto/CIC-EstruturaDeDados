#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int dataSize;
    char input[100];  // Set an appropriate size for input
    int bytes;

    float contadorBytes = 0;
    int contadorBytesTotais = 0;
    int contadorInputs = 0;
    int contadorZeros = 0;

    float veloMedia;
    float tempoFalta;

    scanf("%i", &dataSize);
    printf("Data size of %i bytes:\n", dataSize);

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "F") == 0) {
            break;
        }

        bytes = atoi(input);
        contadorBytesTotais += bytes;
        contadorBytes += bytes;

        if (bytes == 0) {
            contadorZeros++;
        }

        contadorInputs++;
        if (contadorInputs % 5 == 0) {
            if (contadorZeros == 5) {
                printf("Time remaining: stalled\n");
            } else {
                if (dataSize > contadorBytesTotais) {  // Avoid division by zero
                    veloMedia = contadorBytes / 5;
                    tempoFalta = (dataSize - contadorBytesTotais) / veloMedia;
                    tempoFalta = ceil(tempoFalta);
                    printf("Time remaining: %i seconds\n", (int)tempoFalta);
                } else {
                    printf("Time remaining: 0 seconds\n");  // If completed
                }
            }
            contadorBytes = 0;
            contadorZeros = 0;
        }
    }
    printf("Total time: %d seconds\n", contadorInputs);

    return 0;
}
