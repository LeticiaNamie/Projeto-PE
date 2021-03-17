#include "biblioteca.h"

void troca(char p1[100][20], int palavra){ //troca a palavra X com a palavra X+1
    char temp[20];
    strcpy(temp, p1[palavra]);
    strcpy(p1[palavra], p1[palavra+1]);
    strcpy(p1[palavra+1], temp);

}

char converte_maiuscula(char letra){ // converte uma letra maiuscula em minuscula
    if (letra>=65 && letra<=90)
    {
        letra= letra+32;
    }

    return letra;
}

  void ordenar_livros(int livros[100][6], char nome_livros[100][20],int qtde){
    char ordenado[qtde][20];  //vetor tempor�rio para receber livros em ordem, ser� apagado no fim da fun��o
    int count = 0;

    for (int i = 0 ; i < qtde; i++)
    {
        for(int n=0; n<=strlen(nome_livros[i]); n++){
                ordenado[i][n] = nome_livros[i][n];
        }
    }


    while(count!=qtde-1) //o count � quantidade de vezes que um dupla de palavras est� na ordem certa, em um vetor de comprimento "qtde" a quatidade de duplas � "qtde-1"
    {
        count=0;

        for (int x = 0; x < qtde-1; x++) //como � verificado n e n+1, � necess�rio -1 para n�o comparar com um valor n�o determinado
        {
            int comp;
            if(strlen(ordenado[x])<strlen(ordenado[x+1])) { // achar o menor comprimento
                comp=strlen(ordenado[x]);
            }else{  comp=strlen(ordenado[x+1]); }
                int n=0;
            while (converte_maiuscula(ordenado[x][n])==converte_maiuscula(ordenado[x+1][n]) && n<comp) // como � verificado n e n+1, � necess�rio -1 para n�o comparar com um valor n�o determinado
                {
                    n++;
                }

            if (converte_maiuscula(ordenado[x][n]) >converte_maiuscula(ordenado[x+1][n]) ) // troca
            {
                troca(ordenado,x);

            }else
            {
                count++;
            }

        }

    }

    for (int i = 0; i < qtde; i++)
    {
        printf("%s\n", ordenado[i]);
    }

}