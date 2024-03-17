#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct resultado
{
    int partida, vit, der;
};

int main(void)
{
    struct resultado endgame;
    int m[10][10], i, j, op, v0, v1, v2, v3;
    int vet[9], mat[3], n1, n2, n3;
    srand(time(0));
    endgame.vit = endgame.der = endgame.partida = 0;

    printf("============\n");
    printf("[Caça Numero]\n");
    printf("\n");
    printf("1-[Jogar]\n");
    printf("2-[Sair]\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\n");
        break;
    case 2:
        printf("Fim de Jogo!");
        abort();
        break;
    }
    do
    {
        printf("\nIniciando......\n\n");
        endgame.partida++;
        printf("====== Partida %d ======\n\n", endgame.partida);
        printf("Matricula do Aluno:\n");
        for (i = 0; i <= 8; i++)
        {
            vet[0] = 2;
            vet[1] = 0;
            vet[2] = 2;
            vet[3] = 1;
            vet[4] = 2;
            vet[5] = 0;
            vet[6] = 0;
            vet[7] = 7;
            vet[8] = 2;
            printf("%d ", vet[i]);
        }
        printf("\n\nMatricula Gerada:\n");
        for (i = 0; i < 3; i++)
        {
            do
            {
                mat[i] = rand() % (7 - 0 + 1) + 0;
            } while (mat[i] != 2 && mat[i] != 1 && mat[i] != 0 && mat[i] != 7);
            printf("%d ", mat[i]);
        }
        printf("\n\nMatriz:\n");
        v0 = v1 = v2 = v3 = 0;
        for (i = 0; i < 10; i++)
        {
            printf("\n");
            for (j = 0; j < 10; j++)
            {
                m[i][j] = (rand() % (9 - 0 + 1) + 0);
                printf("%d ", m[i][j]);
                if (m[i][j] == mat[0])
                {
                    v0++;
                }
                if (m[i][j] == mat[1])
                {
                    v1++;
                }
                if (m[i][j] == mat[2])
                {
                    v2++;
                }
            }
        }
        printf("\n\n1 - Quantas vezes o numero [%d] aparece na Matriz?\n", mat[0]);
        scanf("%d", &n1);

        printf("\n2 - Quantas vezes o numero [%d] aparece na Matriz?\n", mat[1]);
        scanf("%d", &n2);

        printf("\n3 - Quantas vezes o numero [%d] aparece na Matriz?\n", mat[2]);
        scanf("%d", &n3);
        printf("\n\n\n");

        if (v0 == n1)
        {
            printf("\n\n[O Numero %d se repete %d vezes]", mat[0], v0);
            printf("\n1 - ACERTOU\n");
        }
        else
        {
            printf("1 - ERROU\n");
        }
        if (v1 == n2)
        {
            printf("\n[O Numero %d se repete %d vezes]", mat[1], v1);
            printf("\n2 - ACERTOU\n");
        }
        else
        {
            printf("2 - ERROU\n");
        }
        if (v2 == n3)
        {
            printf("\n[O Numero %d se repete %d vezes]", mat[2], v2);
            printf("\n3 - ACERTOU\n");
        }
        else
        {
            printf("3 - ERROU\n");
        }

        printf("\n\nO Numero %d se repete %d vezes", mat[0], v0);
        printf("\nO Numero %d se repete %d vezes", mat[1], v1);
        printf("\nO Numero %d se repete %d vezes", mat[2], v2);
        printf("\n\n");

        if (v0 == n1 && v1 == n2 && v2 == n3)
        {
            printf("GANHOU\n");
            endgame.vit++;
        }
        else
        {
            printf("\nPERDEU\n");
            endgame.der++;
        }

        do
        {
            printf("\nJogar novamente?\n1-SIM\n2-NÃO\n");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                printf("\nRECOMEÇANDO.........\n\n");
                break;
            case 2:
                printf("===============================");
                printf("\n\t[FIM DE JOGO]");
                printf("\n\tResultados:\n");
                printf("\n\t Partidas %d", endgame.partida);
                printf("\n\t Vitorias %d", endgame.vit);
                printf("\n\t Derrotas %d", endgame.der);
                printf("\n");
                printf("===============================");
                printf("\n");
                abort();
                break;

            default:
                printf("\nOpcao Incorreta\n");
                printf("\n");
            }
        } while (op != 1 && op != 2);
    } while (op == 1);
}