# include <stdio.h>

int calcula_tamanho(char x, char y, char* entrada, int tamanho){
    int contador = 0;
    char ultima_letra_aceita = ' ';
    for (int i = 0; i < tamanho; ++i) {
        char letra = entrada[i];
        if(letra == x){
            if(ultima_letra_aceita == x){
                return 0;
            }
            contador++;
            ultima_letra_aceita = x;
            continue;
        } else if(letra == y){
            if(ultima_letra_aceita == y){
                return 0;
            }
            contador++;
            ultima_letra_aceita = y;
            continue;
        }
    }
    return contador < 2 ? 0: contador;
}


int main (){

    int tamanho, maiorString=0;
    scanf("%d",&tamanho);
    getchar();

    char entrada[1002];
    for (int i = 0; i < tamanho; ++i) {
        scanf("%c",&entrada[i]);
    }

//    printf("Tamanho: %d - String: %s",tamanho,entrada);

    for (char x = 'a'; x <= 'z'; ++x) {
        for (char y = 'a'; y <= 'z'; ++y) {
            if(x == y){
                continue;
            }
            int tamanho_string = calcula_tamanho(x,y,entrada, tamanho);
            if(maiorString < tamanho_string){
                maiorString = tamanho_string;
            }
        }
    }
    printf("%d",maiorString);
}


//10
//beabeefeab

//a



