
//Declara que Ponto é um sinônimo para a estrutura struct implementacaoPonto.
//Isso cria um tipo chamado Ponto, mas não expõe a implementação interna da estrutura implementacaoPonto para quem incluir o arquivo ponto.h.
//Assim, quem incluir ponto.h saberá que existe um tipo Ponto, mas não terá informações sobre os campos da estrutura (coordenada_x e coordenada_y).
typedef struct implementacaoPonto Ponto;

//Abaixo eu listo as operações com o uso do Ponto
Ponto* cria_ponto(double x, double y);

void liberaPonto(Ponto* ponto);

void printPonto(Ponto* ponto);

void alteraPonto(Ponto* ponto, double novo_x, double novo_y);

Ponto* produto(Ponto* ponto, int valor);

double distancia(Ponto* p1, Ponto* p2);
