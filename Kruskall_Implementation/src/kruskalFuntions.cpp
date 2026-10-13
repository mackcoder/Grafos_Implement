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
#include <limits>
#include <algorithm>
#include "kruskalHeader.hpp"
#include "utilsKruskal.hpp"

const float TGrafo::INF = std::numeric_limits<float>::infinity();

/*
    Construtor do TGrafo, responsável por 
    Criar a matriz de adjacência v x v do Grafo
*/
TGrafo::TGrafo( int n ){
    this->n = n;

    // No início dos tempos não há arestas
    this->m = 0; 

    // aloca da matriz do TGrafo
    float **adjac = new float*[n];

    for(int i = 0; i < n; i++)
        adjac[i]= new float[n];

    adj = adjac;

    // Inicia a matriz com zeros
    for(int i = 0; i< n; i++)
        for(int j = 0; j< n; j++)
            adj[i][j]=INF;    
}

/*
    Destructor, responsável por
    liberar a memória alocada para a matriz
*/
TGrafo::~TGrafo(){
    for(int a = 0; a < n; a++){
        delete[] adj[a];
    }
    delete [] adj;
    
    n = 0;
    m = 0;

    std::cout << "Espaco -> free" << std::endl;
}

/*
    Insere uma aresta no Grafo tal que
    v é adjacente a w com peso p
*/
void TGrafo::insertA( int v, int w, int p){
    if(v < 0 || v >= n || w < 0 || w >= n) return;

    // testa se nao temos a aresta
    if(adj[v][w] == INF && adj[w][v] == INF){
        m++; // atualiza qtd arestas
    }
    adj[v][w] = p;
    adj[w][v] = p;
}

// Remove uma aresta v->w do Grafo e libera dando valor de INF

void TGrafo::rmvA(int v, int w){
    // testa se temos a aresta
    if(adj[v][w] == 1){
        adj[v][w] = INF;
        m--; // atualiza qtd arestas
    }
}


// Apresenta a matriz de adjacencia em formato tabular
void TGrafo::show(){
    std::cout << "   ";

    for(int w = 0; w < n; w++){
        if(w > 0)
            std::cout << " ";
        std::cout << w;
    }

    std::cout << std::endl;

    for(int i = 0; i < n; i++){
        std::cout << i << " [";

        for(int w = 0; w < n; w++){
            if(w > 0){
                std::cout << " ";
                if(adj[i][w] == INF){
                    std::cout << "inf";
                } else {
                    std::cout << adj[i][w];
                }
            }
        }
        std::cout << "]" << std::endl;
    }
}


int part(std::vector<Aresta>& V, int low, int high){
    // Pivô -> é o peso da última da aresta do trecho
    float pivot = V[high].peso;
    int k = low - 1; // representa a regiao de elementos menores ou iguais ao pivo

    // Percorre todas as arestas, exceto o pivo
    // Procura as arestas com peso menor que a do pivo
    // Ao encontrar = traz a aresta inteira para dentro da regiao/vetor.
    for(int a = low; a < high; a++){
        if(V[a].peso <= pivot){
            k++;
            std::swap(V[k], V[a]);
        }
    }

    std::swap(V[k + 1], V[high]); // coloca o pivô logo depois dos menores

    return k + 1;
}

void ordenaQuick(std::vector<Aresta>& V, int low, int high){
    if(low < high){
        int pi = part(V, low, high); // posciona o pivo

        ordenaQuick(V, low, pi - 1); // ordena a parte à esquerda do pivo

        ordenaQuick(V, pi + 1, high); // ordena a parte à direita do pivo
    }
}

// Insere as arestas e seus pesos no vetor:
// Como visto na prova, percorre-se somente da diagonal para cima (não-direcionado)
std::vector<Aresta> TGrafo::coletarA(){
    std::vector<Aresta> aux;
    for(int idx1 = 0; idx1 < n; idx1++){
        for(int idx2 = idx1 + 1; idx2 < n; idx2++){
            if(adj[idx1][idx2] != INF){
                aux.push_back({idx1, idx2, adj[idx1][idx2]});
            }
        }
    }
    return aux;
}


void TGrafo::callKruskal(){
    std::vector<int> v(n);
    // inserindo todos os vértices no vetor (v(i) <- i)
    for(int h = 0; h < n; h++) v[h] = h;

    // k para índice da próxima aresta a ser examinada
    // t para quant de arestas já aceitas 
    int k = 0; 
    int t = 0;
    std::vector<Aresta> T; // conj de arestas

    std::vector<Aresta> aux = coletarA();
    ordenaQuick(aux, 0, (int)aux.size() - 1); // ordena por peso não decrescente

    while(t < n - 1 && (int)aux.size()){
        int i = aux[k].u;
        int j = aux[k].v;
        k++;

        if(v[i] != v[j]){
            // Pega val
            // low_val -> rótulo da uniao
            int value = std::max(v[i], v[j]);
            int low_val = std::min(v[i], v[j]);

            // Une as duas componentes: todo vértice com o rótulo maior passa ao menor
            for(int cont = 0; cont < n; cont++){
                if(v[cont] == value)
                    v[cont] = low_val;
            }

            T.push_back(aux[k - 1]); // T <- T U {(i,j)}: guarda a aresta
            t++;
        }
        
    }

    // Printando resultado:
    float total = 0;
    
    for(size_t b = 0; b < T.size(); b++){   
        std::cout << T[b].u  + 1 << " - " << T[b].v + 1 << " (peso " << T[b].peso << ")" << std::endl;
        total += T[b].peso;
    }
        
    std::cout << "\nCusto total: " << total << std::endl;

}



