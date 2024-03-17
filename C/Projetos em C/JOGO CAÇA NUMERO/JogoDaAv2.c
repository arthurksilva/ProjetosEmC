// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
    // declaração das variáveis

    // Matirz
    //  A matriz principal via ser onde os números serão gerados
    int MatrizPrincipal[10][10];
    // Para rodar a matriz onde i é o número de linhas e j o número de colunas
    int i, j;

    // Relacionado a matrícula
    //  O usuário coloca sua matricula e vai tentar advinha o que tem dentro da matriz
    int MatriculaDoAluno[8] = {2, 0, 2, 1, 2, 0, 0, 6, 2};
    // Para contar dentro de um vetor
    int cont;
    int Menor_Valor_Matricula, Maior_Valor_Matricula;
    int Numeros_Gerados_Da_Matricula[3], contar_aleatorio;

    // Variáveis relacionadas a tentativa de acahar o número
    // Números procurados em cada tentativa
    int Numero_procurado_UM, Numero_procurado_DOIS, Numero_procurado_TRES;
    // Qtd de números dentro da matirz
    int Qtd_Numero_Procurado_UM, Qtd_Numero_Procurado_DOIS;
    int Qtd_Numero_ZERO, Qtd_Numero_UM, Qtd_Numero_DOIS, Qtd_Numero_TRES, Qtd_Numero_QUARTO, Qtd_Numero_CINCO, Qtd_Numero_SEIS, Qtd_Numero_SETE;
    int Qtd_Numero_OITO, Qtd_Numero_NOVE;
    // Qtd de vitórias ou derrotas por tentativa
    int QTD_ACERTO_POR_PARTIDA, QTD_ERROS_POR_PARTIDA;

    // Struc
    struct QUANTIDADE
    {
        // Resultado da partida
        int QTD_VITORIA, QTD_DERROTAS;
        // Qtd de partidas
        int QTD_PARTIDAS;
    };

    // Laço para saber se o usuário deseja jogar novamente
    int opcao = 1;

    // Iniciação das váriaveis de qtd de vezes que o número aparece dentro da matriz
    Qtd_Numero_ZERO = Qtd_Numero_UM = Qtd_Numero_DOIS = 0;
    Qtd_Numero_TRES = Qtd_Numero_QUARTO = 0;
    Qtd_Numero_CINCO = Qtd_Numero_SEIS = 0;
    Qtd_Numero_SETE = 0;
    Qtd_Numero_OITO = Qtd_Numero_NOVE = 0;

    // Iniciação das váriaveis de qtd de acerto ou erro por tentativa
    QTD_ACERTO_POR_PARTIDA = QTD_ERROS_POR_PARTIDA = 0;

    /* Iniciação das váriaveis de qtd de vitoria e derros.Nesse contexto,
    uma vitória só acontece se o QTD_ACERTO_POR_PARTIDA for maior que três caso
    contrario vai se uma derrota */

    // STRUC
    struct QUANTIDADE QTD_GERAL;
    QTD_GERAL.QTD_PARTIDAS = QTD_GERAL.QTD_VITORIA = QTD_GERAL.QTD_DERROTAS = 0;

    int DESEJAR_CONTIBUAR = 0;

    // Para mostra os volores dentro do vetor
    printf("Matricula..:");
    for (i = 0; i < 8; i++)
    {
        printf("%d", MatriculaDoAluno[i]);
    }

    while (opcao != 0)
    {

        // Para os volores dentro da matriz não se repetir
        srand(time(0));
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            { // Gerar os volores alatórios
                MatrizPrincipal[i][j] = rand() % 10;
                // Vai testar para ver os valores realmente são menores que dez

                // Caso não for vai ficar dentro do while até sair um valor menor que dez
                while (MatrizPrincipal[i][j] > 10)
                {
                    MatrizPrincipal[i][j] = rand() % 10;
                }
            }
        }
        // Gerar Matriz Principal
        printf("\nMatriz..:\n");

        // Para a matriz sair de forma organizada
        for (j = 0; j < 10; j++)
        {

            printf(" %d ", MatrizPrincipal[0][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[1][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[2][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[3][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[4][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[5][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[6][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[7][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[8][j]);
        }
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", MatrizPrincipal[9][j]);
        }

        printf("\n-----------------------------------------\n");
        // Para pegar o menor valor e maior valor da matrícula
        Menor_Valor_Matricula = Maior_Valor_Matricula = MatriculaDoAluno[0];
        for (cont = 0; cont < 8; cont++)
        {
            if (MatriculaDoAluno[cont] > Maior_Valor_Matricula)
            {
                Maior_Valor_Matricula = MatriculaDoAluno[cont];
            }
            if (MatriculaDoAluno[cont] < Menor_Valor_Matricula)
            {
                Menor_Valor_Matricula = MatriculaDoAluno[cont];
            }
            for (contar_aleatorio = 0; contar_aleatorio < 3; contar_aleatorio++)
            {
                Numeros_Gerados_Da_Matricula[contar_aleatorio] = (rand() % (Maior_Valor_Matricula - Menor_Valor_Matricula + 1) + Menor_Valor_Matricula);

                // Testa para saber se o número gerado pertece a matrícula
                while (Numeros_Gerados_Da_Matricula[contar_aleatorio] % 2 != 0 ||
                       Numeros_Gerados_Da_Matricula[contar_aleatorio] == 8 ||
                       Numeros_Gerados_Da_Matricula[contar_aleatorio] == 4)
                {
                    Numeros_Gerados_Da_Matricula[contar_aleatorio] = (rand() % (Maior_Valor_Matricula - Menor_Valor_Matricula + 1) + Menor_Valor_Matricula);
                }
            }
        }

        // Inicilização do jogo para o usuário perguntado a Qtd de vezes que o número apareceu dentro da matriz
        printf("\nQunatos numeros desses tem na matriz....:( %d  )\n", Numeros_Gerados_Da_Matricula[0]);
        scanf("%d", &Numero_procurado_UM);
        fflush(stdin);
        printf("\nQunatos numeros desses tem na matriz....:( %d  )\n", Numeros_Gerados_Da_Matricula[1]);
        scanf("%d", &Numero_procurado_DOIS);
        fflush(stdin);
        printf("\nQunatos numeros desses tem na matriz....:( %d  )\n", Numeros_Gerados_Da_Matricula[2]);
        scanf("%d", &Numero_procurado_TRES);
        fflush(stdin);

        // Vai contar a Qtd de vezes que o número apareceu na matriz
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                switch (MatrizPrincipal[i][j])
                {
                case 0:
                    Qtd_Numero_ZERO++;
                    break;
                case 1:
                    Qtd_Numero_UM++;
                    break;
                case 2:
                    Qtd_Numero_DOIS++;
                    break;
                case 3:
                    Qtd_Numero_TRES++;
                    break;
                case 4:
                    Qtd_Numero_QUARTO++;
                    break;
                case 5:
                    Qtd_Numero_CINCO++;
                    break;
                case 6:
                    Qtd_Numero_SEIS++;
                    break;
                case 7:
                    Qtd_Numero_SETE++;
                    break;
                case 8:
                    Qtd_Numero_OITO++;
                    break;
                case 9:
                    Qtd_Numero_NOVE++;
                    break;
                }
            }
        }
        // Mostra a QTD de números da matriz
        printf("QTD DE 0 NA MATRIZ..: %d \n", Qtd_Numero_ZERO);
        printf("QTD DE 1 NA MATRIZ..: %d \n", Qtd_Numero_ZERO);
        printf("QTD DE 2 NA MATRIZ..: %d \n", Qtd_Numero_DOIS);
        printf("QTD DE 3 NA MATRIZ..: %d \n", Qtd_Numero_TRES);
        printf("QTD DE 4 NA MATRIZ..: %d \n", Qtd_Numero_QUARTO);
        printf("QTD DE 5 NA MATRIZ..: %d \n", Qtd_Numero_CINCO);
        printf("QTD DE 6 NA MATRIZ..: %d \n", Qtd_Numero_SEIS);
        printf("QTD DE 7 NA MATRIZ..: %d \n", Qtd_Numero_SETE);
        printf("QTD DE 8 NA MATRIZ..: %d \n", Qtd_Numero_OITO);
        printf("QTD DE 9 NA MATRIZ..: %d \n", Qtd_Numero_OITO);

        // Verificação da PRIMEIRA Tentativa
        /*Foi colocado um if antes da verificação da tentativa, pois só vai verificar o palpite
        se o Numeros_Gerados_Da_Matricula for igual ao número que o usuário está tentado,ou seja,
        vai acertar.*/
        /* Foi colocado esse if para mostrar apenas o número que corresponde ao da matrícula.
        E para o teste não entrar em outro if.*/
        if (Numeros_Gerados_Da_Matricula[0] == 0)
        {
            if (Numero_procurado_UM == Qtd_Numero_ZERO)
            {
                printf("\nVc acertou a QTD de 1\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 1)
        {
            if (Numero_procurado_UM == Qtd_Numero_UM)
            {
                printf("\nVc acertou a QTD de 1\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 2)
        {
            if (Numero_procurado_UM == Qtd_Numero_DOIS)
            {
                printf("\nVc acertou a QTD de 2\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 3)
        {
            if (Numero_procurado_UM == Qtd_Numero_TRES)
            {
                printf("\nVc acertou a QTD de 3\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 4)
        {
            if (Numero_procurado_UM == Qtd_Numero_QUARTO)
            {
                printf("\nVc acertou a QTD de 4\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 5)
        {
            if (Numero_procurado_UM == Qtd_Numero_CINCO)
            {
                printf("\nVc acertou a QTD de 5\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 6)
        {
            if (Numero_procurado_UM == Qtd_Numero_SEIS)
            {
                printf("\nVc acertou a QTD de 6\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 7)
        {
            if (Numero_procurado_UM == Qtd_Numero_SETE)
            {
                printf("\nVc acertou a QTD de 7\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 8)
        {
            if (Numero_procurado_UM == Qtd_Numero_OITO)
            {
                printf("\nVc acertou a QTD de 8\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[0] == 9)
        {
            if (Numero_procurado_UM == Qtd_Numero_NOVE)
            {
                printf("\nVc acertou a QTD de 9\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua PRIMEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }

        // Segunda Tentativa
        if (Numeros_Gerados_Da_Matricula[1] == 0)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_ZERO)
            {
                printf("\nVc acertou a QTD de 1\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 1)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_UM)
            {
                printf("\nVc acertou a QTD de 1\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 2)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_DOIS)
            {
                printf("\nVc acertou a QTD de 2\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 3)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_TRES)
            {
                printf("\nVc acertou a QTD de 3\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 4)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_QUARTO)
            {
                printf("\nVc acertou a QTD de 4\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 5)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_CINCO)
            {
                printf("\nVc acertou a QTD de 5\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 6)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_SEIS)
            {
                printf("\nVc acertou a QTD de 6\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 7)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_SETE)
            {
                printf("\nVc acertou a QTD de 7\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 8)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_OITO)
            {
                printf("\nVc acertou a QTD de 8\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[1] == 9)
        {
            if (Numero_procurado_DOIS == Qtd_Numero_NOVE)
            {
                printf("\nVc acertou a QTD de 9\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua SEGUNDA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }

        // Terceira Tentativa
        if (Numeros_Gerados_Da_Matricula[2] == 0)
        {
            if (Numero_procurado_TRES == Qtd_Numero_ZERO)
            {
                printf("\nVc acertou a QTD de 1\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 1)
        {
            if (Numero_procurado_TRES == Qtd_Numero_UM)
            {
                printf("\nVc acertou a QTD de 1\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 2)
        {
            if (Numero_procurado_TRES == Qtd_Numero_DOIS)
            {
                printf("\nVc acertou a QTD de 2\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 3)
        {
            if (Numero_procurado_TRES == Qtd_Numero_TRES)
            {
                printf("\nVc acertou a QTD de 3\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 4)
        {
            if (Numero_procurado_TRES == Qtd_Numero_QUARTO)
            {
                printf("\nVc acertou a QTD de 4\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 5)
        {
            if (Numero_procurado_TRES == Qtd_Numero_CINCO)
            {
                printf("\nVc acertou a QTD de 5\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 6)
        {
            if (Numero_procurado_TRES == Qtd_Numero_SEIS)
            {
                printf("\nVc acertou a QTD de 6\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 7)
        {
            if (Numero_procurado_TRES == Qtd_Numero_SETE)
            {
                printf("\nVc acertou a QTD de 7\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 8)
        {
            if (Numero_procurado_TRES == Qtd_Numero_OITO)
            {
                printf("\nVc acertou a QTD de 8\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }
        if (Numeros_Gerados_Da_Matricula[2] == 9)
        {
            if (Numero_procurado_TRES == Qtd_Numero_NOVE)
            {
                printf("\nVc acertou a QTD de 9\n");
                QTD_ACERTO_POR_PARTIDA++;
            }
            else
            {
                printf("\nNa sua TERCEIRA tentativa errou!\n");
                QTD_ERROS_POR_PARTIDA--;
            }
        }

        // Para saber se o usuário venceu ou perdeu
        if (QTD_ACERTO_POR_PARTIDA == 3)
        {
            printf("\nVc acertou TUDO , VECENDOR !\n ");
            QTD_GERAL.QTD_PARTIDAS++;
            QTD_GERAL.QTD_VITORIA++;
        }
        else
        {
            printf("\nVc ERROU , DERROTA !\n ");
            QTD_GERAL.QTD_DERROTAS++;
            QTD_GERAL.QTD_PARTIDAS++;
        }

        printf("\nVc deseja continuar...: (1-SIM / 2-NOT) \n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            opcao = 1;
            system("cls");
        }
        else
        {
            opcao = 0;
        }

        // Teste para saber o maior e o menor valor
        /*printf("Maior.:%d\n", Maior_Valor_Matricula);
        printf("Menor.:%d\n", Menor_Valor_Matricula);*/
    }
    printf("\n------------------------------------------------------------------------------\n");
    printf("\nQTD de PARTIDAS..: %d \n", QTD_GERAL.QTD_PARTIDAS);
    printf("\nQTD de ACERTOS..: %d \n", QTD_GERAL.QTD_VITORIA);
    printf("\nQTD de ERROS..: %d \n", QTD_GERAL.QTD_DERROTAS);
}