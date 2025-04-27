#include <stdio.h>
#include <string.h>


char* remove_dupla_letras(char * str, int tamanho) {
  int removeu = 0;
  for (int i = 0; i < tamanho-1; ++i) {
    char letra = str[i];
    char proxima_letra = str[i+1];
    if(letra == proxima_letra){
      removeu = 1;
      for (int j = i; j < tamanho-1; ++j) {
        str[j] = str[j+2];
      }
    }
  }
  if(removeu == 0) {
    return str;
  }
  return remove_dupla_letras(str,tamanho-2);
}

int main() {
  char string[100] = "aaa";

  int tamanho = strlen(string);

  char* nova_String = remove_dupla_letras(string,tamanho);
  printf("%s",nova_String);

  return 0;
}
