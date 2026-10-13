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

/*
Implementação de uma Classe para grafos denominada TGrafo,
usando Matriz de Adjacência
*/
#ifndef ___GRAFO_MATRIZ_ADJACENCIA___
#define ___GRAFO_MATRIZ_ADJACENCIA___

#include <vector>

/* Funcoes da ordenacao:
O Kruskal precisa ordenar as arestas pelo peso, mas 
sem perder quais vértices cada uma liga - por isso
que a struct é necessária:   
*/
struct Aresta {
    int u, v;
    float peso;
};

void ordenaQuick(std::vector<Aresta>& V, int low, int high);

// definição de uma estrutura para armezanar um grafo
// Também seria possível criar um arquivo grafo.h 
// e fazer a inclusão "#include <grafo.h>"
class TGrafo{
    private:
        int n; // quantidade de vértices
        int m; // quantidade de arestas
        float **adj; //matriz de adjacência
        static const float INF;
    public:
        TGrafo(int n);
        void insertA(int v, int w, int p);
        void rmvA(int v, int w);
        void show();
        std::vector<Aresta> coletarA();
        void callKruskal();
        
        ~TGrafo();
};

#endif
