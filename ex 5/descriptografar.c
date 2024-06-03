#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SHIFT 3 // Número de deslocamento para a cifra de substituição

int main() {
	setlocale(LC_ALL,"");
    FILE *entrada, *saida;
    char caractere;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("arquivo_criptografado.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        return 1;
    }

    // Abre o arquivo de saída para escrita
    saida = fopen("arquivo_descriptografado.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.");
        fclose(entrada);
        return 1;
    }

    // Descriptografa o arquivo de entrada e escreve no arquivo de saída
    while ((caractere = fgetc(entrada)) != EOF) {
        if (caractere >= 'a' && caractere <= 'z') {
            caractere = 'a' + (caractere - 'a' - SHIFT + 26) % 26;
        } else if (caractere >= 'A' && caractere <= 'Z') {
            caractere = 'A' + (caractere - 'A' - SHIFT + 26) % 26;
        }
        fputc(caractere, saida);
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Arquivo descriptografado com sucesso.\n");

    return 0;
}

