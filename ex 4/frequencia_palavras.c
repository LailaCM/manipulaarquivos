#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_SIZE 100

// Estrutura para armazenar a palavra e sua frequ�ncia
typedef struct {
    char palavra[MAX_SIZE];
    int frequencia;
} Registro;

// Fun��o para normalizar uma palavra (remover pontua��es e tornar min�scula)
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

        // Verifica se a palavra j� foi registrada
        int i, encontrada = 0;
        for (i = 0; i < numRegistros; i++) {
            if (strcmp(registros[i].palavra, palavra) == 0) {
                registros[i].frequencia++;
                encontrada = 1;
                break;
            }
        }
        // Se a palavra n�o foi encontrada, adiciona ao registro
        if (!encontrada) {
            strcpy(registros[numRegistros].palavra, palavra);
            registros[numRegistros].frequencia = 1;
            numRegistros++;
        }
    }

    // Fecha o arquivo de entrada
    fclose(entrada);

    // Abre o arquivo de sa�da para escrita
    saida = fopen("frequencia_palavras.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de sa�da.");
        return 1;
    }

    // Escreve a frequ�ncia das palavras no arquivo de sa�da
    int i;
    for (i = 0; i < numRegistros; i++) {
        fprintf(saida, "%s: %d\n", registros[i].palavra, registros[i].frequencia);
    }

    // Fecha o arquivo de sa�da
    fclose(saida);

    printf("Frequ�ncia das palavras salva com sucesso.\n");

    return 0;
}
