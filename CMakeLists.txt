cmake_minimum_required(VERSION 3.30)
project(CIC_ED C)

set(CMAKE_C_STANDARD 11)

add_executable(Ponto TAD/Ponto/Main.c TAD/Ponto/ponto.c)
add_executable(Lista TAD/Lista/Main.c TAD/Lista/Lista.c)
