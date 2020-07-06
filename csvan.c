#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char campo[128], delim[4];
    int  n = 0;
    int campos = 1;
    int registros = 1;
    int sentinel = 1;

    FILE* ent = fopen("target.csv", "r");
    // agora le os campos da primeira linha

    setlocale(LC_ALL, "pt_BR.utf8");
    SetConsoleCP(850);
    SetConsoleOutputCP(850);

    while ((n = fscanf(ent, "%[^,\n]%c",
        campo, delim)) > 0)
    {
        printf("[%3d,%3d  %3d] '%s'\n", registros, ((campos - 1) % 8), campos, campo);
        campos += 1;
        if (delim[0] == 10) break;
    };
    printf("\nLidos %d campos\n", campos);
    fclose(ent);

    printf("Tecle ENTER para ler os registros de dados, Control-C para cancelar\n");
    char c = getc(stdin);
    ent = fopen("target.csv", "r");
    while ((n = fscanf(ent, "%[^,\n]%c",
        campo, delim)) > 0)
    {
        printf("[%3d,%3d  %3d] '%s'\n", registros, ((campos - 1) % 8), campos, campo);
        campos += 1;
        if (delim[0] == 10) registros += 1;
    };   //while()
    printf("\n\nLidos %d campos em %d registros\n",
        campos - 1, registros);
    fclose(ent);
    return 0;
};

//  fim ch 1465219