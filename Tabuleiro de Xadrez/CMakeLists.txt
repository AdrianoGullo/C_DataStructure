cmake_minimum_required(VERSION 3.27)
project(Tabuleiro_de_Xadrez C)

set(CMAKE_C_STANDARD 11)

add_executable(Tabuleiro_de_Xadrez
        posicaoCavalo.c)

#add_executable(Tabuleiro_de_Xadrez
#        cavalosEmGuerra.c)

#trocar add_executable para rodar o outro arquivo