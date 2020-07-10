/* Programa: Lab 9
Autor: Felipe Baz Mitsuishi
Versao: 1.0 - 09/12/2019
*/
// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################
// ###################### Funcoes e Procedimentos do programa ##############
int profundidade(int v, int teste, int g[v][v], int objetivo, int inicio, int visitado[v])
{
    int i;
    visitado[inicio] = 1;
    for (i = 0; i < v; i++)
    {
        if (g[inicio][i] == 1)
        {
            if (i == objetivo)
            {
                visitado[inicio] = 0;
                teste += 1;
                return teste;
            }
            if (visitado[i] == 0)
            {
                teste = profundidade(v, teste, g, objetivo, i, visitado);
            }
        }
    }
    visitado[inicio] = 0;
    return teste;
}

void dfs(int v, int g[v][v], int objetivo, int inicio)
{
    int visitado[v], i, teste = 0;
    for (i = 0; i < v; i++)
    {
        visitado[i] = 0;
    }
    teste = profundidade(v, teste, g, objetivo, inicio, visitado);
    printf("%d\n", teste);
}
// ############################ Principal ###################################

int main()
{
    int i, j, V, E;      //E = aresta(caminho), V = vertices (ilhas).
    int Origem, destino; //tomaremos 1 = começo e -1 igual a fim.
    int inicio, fim;
    scanf("%d %d", &V, &E);
    int Grafo[V][V];
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            Grafo[i][j] = 0;
        }
    }
    for (i = 0; i < E; i++) //leitura e configuração do grafo.
    {
        scanf("%d %d", &Origem, &destino);
        Grafo[Origem][destino] = 1;
    }
    scanf("%d %d", &inicio, &fim);
    dfs(V, Grafo, destino, inicio);
    return 0;
}
