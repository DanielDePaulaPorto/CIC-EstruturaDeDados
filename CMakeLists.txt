cmake_minimum_required(VERSION 3.30)
project(CIC_ED C)

#add_compile_options(-std=c++11)

set(CMAKE_C_STANDARD 11)


#add_executable(Ponto TAD/Ponto/Main.c TAD/Ponto/ponto.c)
#add_executable(Lista TAD/Lista/Main.c TAD/Lista/Lista.c)
#add_executable(Fila TAD/Fila/Main.c TAD/Fila/Fila.c)
#add_executable(FilaPrioridades TAD/FilaPrioridades/Main.c TAD/FilaPrioridades/FilaPrioridades.c TAD/Fila/Fila.c)
add_executable(Pilha TAD/Pilha/Main.c TAD/Pilha/Pilha.c)
add_executable(Base TAD/Pilha/MudancaBase.c TAD/Pilha/Pilha.c)
add_executable(Calculadora TAD/Pilha/Calculadora.c TAD/Pilha/Pilha.c)
add_executable(Ordenacao ComplexidadeOrdenacao/Corrida.c TAD/Lista/Lista.c)
add_executable(Hash TAD/TabelaHash/TabelaHash.c TAD/TabelaHash/main.c)
add_executable(Grafo TAD/Grafo/Grafo.c TAD/Grafo/main.c)
add_executable(ArvoreBinaria TAD/ArvoreBinaria/ArvoreBinaria.c TAD/ArvoreBinaria/Main.c)
add_executable(Huffman TAD/Huffman/Huffman.c TAD/Huffman/Main.c)