#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	
	setlocale(LC_ALL,"");
	
    FILE *entrada, *saida;
    char caractere, proximo;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("codigofonte.c", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        return 1;
    }

    // Abre o arquivo de sa�da para escrita
    saida = fopen("codigo_sem_comentarios.c", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de sa�da.");
        fclose(entrada);
        return 1;
    }

    // Processa o arquivo de entrada
    while ((caractere = fgetc(entrada)) != EOF) {
        if (caractere == '/') {
            proximo = fgetc(entrada);
            if (proximo == '/') { // Coment�rio de linha
                while ((caractere = fgetc(entrada)) != '\n' && caractere != EOF);
            } else if (proximo == '*') { // Coment�rio de bloco
                do {
                    while ((caractere = fgetc(entrada)) != '*') {
                        if (caractere == EOF) {
                            printf("Erro: Coment�rio de bloco n�o fechado.\n");
                            fclose(entrada);
                            fclose(saida);
                            return 1;
                        }
                    }
                    proximo = fgetc(entrada);
                } while (proximo != '/');
            } else {
                fputc(caractere, saida);
                fputc(proximo, saida);
            }
        } else {
            fputc(caractere, saida);
        }
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Coment�rios removidos com sucesso.\n");

    return 0;
}

