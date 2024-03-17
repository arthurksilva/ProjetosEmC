#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct resultjogo
{
    int vit;
    int der;
    int par;
} jogador;

int main()
{
    struct resultjogo jogador;
    int mrand[10][10];
    int vetmat[9] = {2, 0, 2, 1, 2, 0, 0, 4, 2};
    int vetale[3];
    int i, j;
    int q0 = 0, q1 = 0, q2 = 0, q3 = 0, q4 = 0, q5 = 0, q6, q7 = 0, q8 = 0, q9 = 0;
    int opc = 1, qv0 = 0, qv1 = 0, qv2 = 0, nv0 = 0, nv1 = 0, nv2 = 0;
    srand(time(0));

    jogador.vit = 0;
    jogador.der = 0;
    jogador.par = 0;

    while (opc != 0)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                mrand[i][j] = rand() % (9 - 0 + 1) - 0;
            }
        }
        for (i = 0; i < 10; i++)
        {
            printf("\n");
            for (j = 0; j < 10; j++)
            {
                printf("%d ", mrand[i][j]);
            }
        }

        for (i = 0; i < 3; i++)
        {
            vetale[i] = rand() % (4 - 0 + 1) - 0;
            while (vetale[i] != 0 && vetale[i] != 1 && vetale[i] != 2 && vetale[i] != 4)
            {
                vetale[i] = rand() % (4 - 0 + 1) - 0;
            }
        }

        printf("\n\n\n%d %d %d, \nquantas vezes esses numeros aparecem?\n", vetale[0], vetale[1], vetale[2]);
        scanf("%d %d %d", &nv0, &nv1, &nv2);
        jogador.par++;

        for (i = 0; i < 10; i++)
        {

            for (j = 0; j < 10; j++)
            {
                if (mrand[i][j] == vetale[0])
                {
                    qv0++;
                }
                if (mrand[i][j] == vetale[1])
                {
                    qv1++;
                }
                if (mrand[i][j] == vetale[2])
                {
                    qv2++;
                }
            }
        }
        if (nv0 == qv0)
        {
            printf("\nVoce acertou[%d], sua resposta foi= %d e a resposta correta era= %d ", vetale[0], nv0, qv0);
        }
        else
        {
            printf("\nVoce errou [%d], sua resposta foi= %d e a resposta correta era= %d ", vetale[0], nv0, qv0);
        }
        if (nv1 == qv1)
        {
            printf("\nVoce acertou[%d], sua resposta foi= %d e a resposta correta era= %d ", vetale[1], nv1, qv1);
        }
        else
        {
            printf("\nVoce errou[%d], sua resposta foi= %d e a resposta correta era= %d ", vetale[1], nv1, qv1);
        }
        if (nv2 == qv2)
        {
            printf("\nVoce acertou[%d], sua resposta foi= %d e a resposta correta era= %d ", vetale[2], nv2, qv2);
        }
        else
        {
            printf("\nVoce errou[%d], sua resposta foi= %d e a resposta correta era= %d ", vetale[2], nv2, qv2);
            printf("\n==================================//================================");
        }

        if (nv0 == qv0 && nv1 == qv1 && nv2 == qv2)
        {
            printf("\nVITORIA\n");
            jogador.vit++;

            qv0 = 0;
            qv1 = 0;
            qv2 = 0;
        }
        else
        {
            printf("\nDERROTA\n");
            jogador.der++;

            qv0 = 0;
            qv1 = 0;
            qv2 = 0;
        }

        printf("\nDeseja continar: 1-Sim / 2-Nao\n");
        scanf("%d", &opc);
        if (opc == 2)
        {
            opc = 0;
        }
        else
        {
            printf("\n\numero invalido! Sera iniciada uma nova partida.\n\n");
            printf("=========================================================");
        }

        if (opc == 1)
        {
            opc = 1;
        }
    }
    printf("\n|-_-_-_-_-_-_-_---===---_-_-_-_-_-_-_-|\n");
    printf("      vitorias=%d\n        derrotas=%d\n          partidas=%d\n", jogador.vit, jogador.der, jogador.par);
    printf("\n|-_-_-_-_-_-_-_---===---_-_-_-_-_-_-_-|\n");
}