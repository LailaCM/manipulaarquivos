#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"");
	
    FILE *entrada, *saida;
    char caractere;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("arquivo_origem.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        return 1;
    }

    // Abre o arquivo de saída para escrita
    saida = fopen("arquivo_sem_espacos.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.");
        fclose(entrada);
        return 1;
    }

    // Processa o arquivo de entrada
    while ((caractere = fgetc(entrada)) != EOF) {
        if (!isspace(caractere)) { // Verifica se não é espaço em branco
            fputc(caractere, saida);
        }
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Espaços em branco removidos com sucesso.\n");

    return 0;
}

