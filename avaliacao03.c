#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 30

typedef struct
{
    char nome[TAM_NOME];
    float nota;
} Aluno;

void selectionSort(Aluno *boletim, int tamanho)
{
    int menor;
    Aluno aux;

    for (int i = 0; i < tamanho - 1; i++)
    {
        menor = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (boletim[j].nota < boletim[menor].nota)
            {
                menor = j;
            }
        }

        aux = boletim[i];
        boletim[i] = boletim[menor];
        boletim[menor] = aux;
    }
}

void renderizarBoletim(Aluno *boletim, int tamanho)
{
    printf("=================================================\n");
    printf("|                Notas do boletim               |\n");
    printf("=================================================\n");
    printf("|            Alunos            |      Notas     |\n");
    printf("=================================================\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("| %-29s | %13.2f |\n", boletim[i].nome, boletim[i].nota);

        printf("=================================================\n");
    }
}

int main()
{
    int qtdNotas = 0;
    printf("Qtd de notas a serem inseridas: ");
    scanf("%d", &qtdNotas);

    Aluno boletim[qtdNotas];

    for (int i = 0; i < qtdNotas; i++)
    {
        printf("Digite o nome do aluno: ");
        scanf("%s", boletim[i].nome);

        printf("Digite a nota do %s: ", boletim[i].nome);
        scanf("%f", &boletim[i].nota);
    }

    selectionSort(boletim, qtdNotas);
    renderizarBoletim(boletim, qtdNotas);

    return 0;
}
