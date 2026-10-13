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

#include <iostream>
#include <vector>
#include "kruskalHeader.hpp"
#include "utilsKruskal.hpp"

void preencher_grafos(TGrafo& g1, TGrafo& g2) {
    // Criando vertices para G1
    g1.insertA(0, 1, 4);   
    g1.insertA(0, 5, 5);   
    g1.insertA(1, 5, 3);   
    g1.insertA(1, 2, 7);   
    g1.insertA(2, 3, 5);   
    g1.insertA(2, 6, 6);   
    g1.insertA(3, 4, 3);   
    g1.insertA(4, 6, 2);   
    g1.insertA(4, 7, 4); 
    g1.insertA(5, 6, 7);   
    g1.insertA(5, 8, 5);   
    g1.insertA(6, 7, 6);   
    g1.insertA(7, 8, 8);    

    // G2: grafo da atividade solicitada
    g2.insertA(0, 1, 6);   // a-b
    g2.insertA(0, 2, 15);  // a-c
    g2.insertA(0, 4, 8);   // a-e
    g2.insertA(1, 2, 20);  // b-c
    g2.insertA(1, 4, 10);  // b-e
    g2.insertA(1, 5, 8);   // b-f
    g2.insertA(2, 3, 9);   // c-d
    g2.insertA(3, 5, 7);   // d-f
    g2.insertA(4, 5, 5);   // e-f
}



