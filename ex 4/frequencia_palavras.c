#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_SIZE 100

// Estrutura para armazenar a palavra e sua frequência
typedef struct {
    char palavra[MAX_SIZE];
    int frequencia;
} Registro;

// Função para normalizar uma palavra (remover pontuações e tornar minúscula)
void normalizarPalavra(char *palavra) {
    int i, j = 0;
    char novaPalavra[MAX_SIZE];

    for (i = 0; palavra[i] != '\0'; i++) {
        if (isalpha(palavra[i])) {
            novaPalavra[j++] = tolower(palavra[i]);
        }
    }
    novaPalavra[j] = '\0';
    strcpy(palavra, novaPalavra);
}

int main() {
	setlocale(LC_ALL,"");
	
    FILE *entrada, *saida;
    char palavra[MAX_SIZE];
    Registro registros[MAX_SIZE];
    int numRegistros = 0;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("arquivo_entrada.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        return 1;
    }

    // Processa o arquivo de entrada
    while (fscanf(entrada, "%s", palavra) != EOF) {
        normalizarPalavra(palavra);

        // Verifica se a palavra já foi registrada
        int i, encontrada = 0;
        for (i = 0; i < numRegistros; i++) {
            if (strcmp(registros[i].palavra, palavra) == 0) {
                registros[i].frequencia++;
                encontrada = 1;
                break;
            }
        }
        // Se a palavra não foi encontrada, adiciona ao registro
        if (!encontrada) {
            strcpy(registros[numRegistros].palavra, palavra);
            registros[numRegistros].frequencia = 1;
            numRegistros++;
        }
    }

    // Fecha o arquivo de entrada
    fclose(entrada);

    // Abre o arquivo de saída para escrita
    saida = fopen("frequencia_palavras.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.");
        return 1;
    }

    // Escreve a frequência das palavras no arquivo de saída
    int i;
    for (i = 0; i < numRegistros; i++) {
        fprintf(saida, "%s: %d\n", registros[i].palavra, registros[i].frequencia);
    }

    // Fecha o arquivo de saída
    fclose(saida);

    printf("Frequência das palavras salva com sucesso.\n");

    return 0;
}
