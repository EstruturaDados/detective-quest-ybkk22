#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

//🌱 Nível Novato: Mapa da Mansão com Árvore Binária

struct Sala {
    char nome[50];              // Nome da sala
    struct Sala* esquerda;      // Ponteiro para a sala à esquerda
    struct Sala* direita;       // Ponteiro para a sala à direita
};

// - Função para criar uma sala
struct Sala* criarSala(char* nome) {
    struct Sala* nova = (struct Sala*) malloc(sizeof(struct Sala)); // Aloca memória
    strcpy(nova->nome, nome); // Copia o nome
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// - Função para conectar as salas
struct Sala* conectarSalas(struct Sala* salaPai, struct Sala* salaEsquerda, struct Sala* salaDireita) {
    salaPai->esquerda = salaEsquerda;
    salaPai->direita = salaDireita;
    return salaPai;
}

// - Função para explorar as salas
void explorarSalas(struct Sala* salaAtual) {
    char escolha;
    while (1) {
        printf("\n📍 Você está na sala: %s\n", salaAtual->nome); // Exibe o nome da sala atual
        printf("Escolha uma direção (e: esquerda, d: direita, s: sair): "); // Opções de movimento
        scanf(" %c", &escolha);

        if (escolha == 'e' && salaAtual->esquerda != NULL) { // Move para a sala à esquerda
            salaAtual = salaAtual->esquerda;
        } 
        else if (escolha == 'd' && salaAtual->direita != NULL) { // Move para a sala à direita
            salaAtual = salaAtual->direita;
        } 
        else if (escolha == 's') {
            printf("\n👋 Você saiu da mansão!\n");
            break;
        } 
        else {
            printf("🚫 Direção inválida ou sala inexistente!\n");
        }
    }
}

// 🏠 Função principal
int main() {
    // Criação das salas
    struct Sala* hall = criarSala("Hall de Entrada"); // Sala raiz
    struct Sala* biblioteca = criarSala("Biblioteca"); // Sala à esquerda do hall
    struct Sala* cozinha = criarSala("Cozinha"); // Sala à direita do hall
    struct Sala* sotao = criarSala("Sótão"); // Sala à esquerda da biblioteca

    // Conectando as salas
    conectarSalas(hall, biblioteca, cozinha); // Hall conecta Biblioteca e Cozinha
    conectarSalas(biblioteca, sotao, NULL); // Biblioteca conecta Sótão

    // Começa a exploração
    explorarSalas(hall);

    // Libera a memória usada
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);

    return 0;
}







    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

 

