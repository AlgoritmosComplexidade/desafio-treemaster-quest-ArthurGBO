#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct No {
    int id;
    char titulo[100];
    char autor[50];
    int ano;
    struct No* esquerdo;
    struct No* direito;
} No;

// Função para criar um novo nó da árvore binária
No* criar_no(int id, const char* titulo, const char* autor, int ano) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    
    novo_no->id = id;
    strcpy(novo_no->titulo, titulo);
    strcpy(novo_no->autor, autor);
    novo_no->ano = ano;
    novo_no->esquerdo = NULL;
    novo_no->direito = NULL;
    
    return novo_no;
}

// Inserção na Árvore Binária de Busca (Recursiva)
No* inserir_bst(No* raiz, No* novo_no) {
    if (raiz == NULL) {
        return novo_no;
    }
    
    if (novo_no->id < raiz->id) {
        raiz->esquerdo = inserir_bst(raiz->esquerdo, novo_no);
    } else if (novo_no->id > raiz->id) {
        raiz->direito = inserir_bst(raiz->direito, novo_no);
    } else {
        // ID já existe (não inserir duplicado)
        printf("ID %d já existe! Nó não inserido.\n", novo_no->id);
        free(novo_no);
    }
    
    return raiz;
}

// Percurso Em-Ordem (In-Order) para listar os documentos
void exibir_em_ordem(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem(raiz->esquerdo);
        printf("ID: %d | Título: %s | Autor: %s | Ano: %d\n", 
               raiz->id, raiz->titulo, raiz->autor, raiz->ano);
        exibir_em_ordem(raiz->direito);
    }
}

int main() {
    printf("=== CODEFOREST SOLUTIONS - TREEMASTER QUEST ===\n\n");

    No* raiz = NULL;

    No* doc1 = criar_no(1001, "Introducao a programacao", "Joao Silva", 2020);
    No* doc2 = criar_no(1002, "Estruturas de dados avancadas", "Maria Oliveira", 2023);

    raiz = inserir_bst(raiz, doc1);
    raiz = inserir_bst(raiz, doc2);

    printf("=== Documentos cadastrados ===\n");
    exibir_em_ordem(raiz);

    return 0;
}
