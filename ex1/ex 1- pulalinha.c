#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 100

int main() {
	setlocale(LC_ALL,"");
    FILE *arquivo1, *arquivo2, *arquivo3;
    char linha[MAX_SIZE];

    // Abre os arquivos de entrada
    arquivo1 = fopen("arquivo1.txt", "r");
    arquivo2 = fopen("arquivo2.txt", "r");
    
    // Verifica se os arquivos foram abertos corretamente
    if (arquivo1 == NULL || arquivo2 == NULL) {
        printf("Erro ao abrir os arquivos de entrada.");
        return 1;
    }

    // Abre o arquivo de saída
    arquivo3 = fopen("arquivo3.txt", "w");
    if (arquivo3 == NULL) {
        printf("Erro ao abrir o arquivo de saída.");
        fclose(arquivo1);
        fclose(arquivo2);
        return 1;
    }

    // Mescla os arquivos
    while (!feof(arquivo1) || !feof(arquivo2)) {
        if (fgets(linha, MAX_SIZE, arquivo1) != NULL) {
            fputs(linha, arquivo3);
        }
        if (fgets(linha, MAX_SIZE, arquivo2) != NULL) {
            fputs(linha, arquivo3);
        }
    }

    // Fecha os arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

    printf("Arquivos mesclados com sucesso.\n");

    return 0;
}




