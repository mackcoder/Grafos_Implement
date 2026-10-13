/**
 * Implementação:
 * Algoritmo Kruskal (Grupo do Projeto)
 * 
 * Integrantes:
 * |=================================|==========|
 * |               Nome              |    RA    |
 * |---------------------------------|----------|
 * | André Doerner Duarte            | 10427938 |
 * | Matheus Leonardo Cardoso Kroeff | 10426434 |
 * | Naoto Ushizaki                  | 10437445 |
 * |=================================|==========|
 */

// |!| Como compilar: g++ -Wall -o programa kruskalMain.cpp kruskalFuntions.cpp kruskalUtils.cpp
// Executar (cmd): programa.exe
// Executar (powershell): ./programa.exe

#include <stdio.h>
#include "kruskalHeader.hpp"
#include "utilsKruskal.hpp"
int main(){
    TGrafo g1(9);   // grafo do material da aula
    TGrafo g2(6);   // grafo da atividade anterior
    preencher_grafos(g1, g2);

    // operacao sendo feita para G1:
    std::cout << "=== IMPLEMENTAÇÃO KRUSKAL ===\n" << std::endl;
    std::cout << "G1 -> grafo do material da aula \n" << std::endl;
    std::cout << "G2 -> grafo da atividade solicitada anteriormente \n" << std::endl;

    std::cout << "G1:" << std::endl;
    g1.callKruskal();

    // operacao sendo feita para G2:
    std::cout << "\nG2:" << std::endl;
    g2.callKruskal();

    std::vector<Aresta> todas = g1.coletarA();

    return 0;
}
