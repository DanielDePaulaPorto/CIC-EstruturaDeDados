#include <stdio.h>

void converteAM(int h,int m,int s);
void convertePM(int h,int m,int s);

int main() {
  int h, m, s;
  char ampm[3];

  scanf("%d:%d:%d", &h, &m, &s);
  scanf("%s", ampm);

  if(ampm[0] == 'A') {
    converteAM(h,m,s);
  }
  else {
    convertePM(h,m,s);
  }
}

void converteAM(int h,int m,int s){
  if(h == 12){
    h = 0;
  }
  printf("%02d:%02d:%02d", h, m, s);
}
void convertePM(int h,int m,int s){
  if(h < 12){
    h +=12;
  }
  printf("%02d:%02d:%02d", h, m, s);
}





