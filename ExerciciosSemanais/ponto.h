typedef struct {
    double coordenada_x;
    double coordenada_y;
} Ponto_R2;

Ponto_R2 cria_ponto(double x, double y);

void print(Ponto_R2 ponto);

Ponto_R2 produto(Ponto_R2 ponto, int valor);