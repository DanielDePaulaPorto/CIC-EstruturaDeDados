cmake_minimum_required(VERSION 3.30)
project(CIC_ED C)

set(CMAKE_C_STANDARD 11)


add_executable(Ponto TAD/Ponto/mainPonto.c TAD/Ponto/ponto.c)
add_executable(Ponteiro TAD/Ponteiros/ponteiro.c)
add_executable(Fila TAD/Fila/Fila.c TAD/Fila/MainFila.c)
add_executable(Pilha TAD/Pilha/Pilha.c TAD/Pilha/MainPilha.c)