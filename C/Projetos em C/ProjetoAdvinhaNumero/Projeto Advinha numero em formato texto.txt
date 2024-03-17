// As bibliotecas que o programa chamou
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
    // Declaração das variáreis que seram usadas pelo programa
    int numeroAleatoria, numeroDaTentativaDoUsuario, opcao;

    int QTDvitoria, QTDempate, QTDderrota, QTDpartidas;

    int resultadoParaSaberDistancia;

    // Inicializção das variáreis
    QTDderrota = 0;
    QTDvitoria = 0;
    QTDpartidas = 0;
    QTDempate = 0;

    // Explicação do jogo
    printf("O jogo consiste em o usuário (no caso você) tentar advinhar o número que foi gerando aleatoriamente pelo algoritmo\n");

    // Inicialização da variável opção para entrar no loop
    opcao = 0;
    printf("\nEscolha a opcao do jogo..: 1-Facil / 2-Difil");
    scanf("%d", &opcao);

    // Essa parte vai pegar o número que o usuário digiotu para tentar advinhar
    printf("\nDigite um numero...:\n");
    scanf("%d", &numeroDaTentativaDoUsuario);

    // Vai limpar o buffer do teclado
    fflush(stdin);

    // Jogo fácil
    while (opcao == 1)
    {
        // Vai gerar o número aleatório
        srand(time(0));
        numeroAleatoria = rand();

        // Para saber se o usuário acertou
        if (numeroAleatoria == numeroDaTentativaDoUsuario)
        {
            printf("\nAcertou!, numero que voce digitou - %d - numero que o programa gerou - %d \n", numeroDaTentativaDoUsuario, numeroAleatoria);
            QTDvitoria = QTDvitoria + 1;
            QTDpartidas = QTDpartidas + 1;
        }
        // Para saber se o usuário errou
        else
        {
            printf("\nErrou!, numero que voce digitou - %d - numero que o programa gerou - %d \n", numeroDaTentativaDoUsuario, numeroAleatoria);
            QTDderrota = QTDderrota + 1;
            QTDpartidas = QTDpartidas + 1;
        }

        printf("\nDeseja continuar? .....: 1-Sim // 2-Nao\n");
        scanf("%d", &opcao);

        // Vai limpar o buffer do teclado
        fflush(stdin);

        // Para voltar para o inicio do programa
        if (opcao == 1)
        {
            printf("\nDigite um número...:\n");
            scanf("%d", &numeroDaTentativaDoUsuario);

            // Vai limpar o buffer do teclado
            fflush(stdin);
        }
        else
        {
            printf("\n------------ Saida -------------------\n");
            opcao = 0;
        }
    }

    // Mudar o opção do jogo
    printf("\nDejesa jogar no modo dificil...: 2-Sim / 3-Nao\n");
    scanf("%d", &opcao);
    if (opcao == 2)
    {
        printf("Digite um numero...:");
        scanf("%d", &numeroDaTentativaDoUsuario);
    }

    // Jogo com desafio
    if (opcao == 2)
    {
        opcao = 0;
        while (opcao != 2)
        {
            // Vai gerar um número aleatório
            srand(time(0));
            numeroAleatoria = rand();

            // Se o usuário acerta o número
            if (numeroDaTentativaDoUsuario == numeroAleatoria)
            {
                printf("\nAcertou!, numero que voce digitou - %d - numero que o programa gerou - %d \n", numeroDaTentativaDoUsuario, numeroAleatoria);
                QTDvitoria = QTDvitoria + 1;
                QTDpartidas = QTDpartidas + 1;
            }

            /*Caso ele erre vai mostra se é menor ou maior e qual a distancia
            entre o número que o usuiário digitou e o número que o sistema gerou
            aletoriamente*/
            else
            {
                resultadoParaSaberDistancia = numeroAleatoria - numeroDaTentativaDoUsuario;
                QTDderrota = QTDderrota + 1;
                QTDpartidas = QTDpartidas + 1;

                if (resultadoParaSaberDistancia < 0)
                {
                    resultadoParaSaberDistancia = -(resultadoParaSaberDistancia);
                }

                if (numeroDaTentativaDoUsuario > numeroAleatoria)
                {
                    printf("\n O numero que voce digitou e %d MAIOR \n", resultadoParaSaberDistancia);
                }
                else if (numeroDaTentativaDoUsuario < numeroAleatoria)
                {
                    printf("\nO numero que voce digitou e %d MENOR\n", resultadoParaSaberDistancia);
                }
            }

            printf("\nDejesa continuar...: 1-SIM / 2-NAO\n");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                printf("\nDigite um numero...:\n");
                scanf("%d", &numeroDaTentativaDoUsuario);
            }
            else
            {
                printf("\n------------ Saida -------------------\n");
            }
        }
    }

    // Resultado das partidas
    printf("\nQuantidade de partidas.....: %d \n", QTDpartidas);

    if (QTDvitoria == QTDderrota)
    {
        printf("\n O jogo terminou em empate \n");
    }
    else
    {
        printf("\nQuantidade de partidas com vitoria %d \n", QTDvitoria);
        printf("\nQuantidade de partidas com derrota  %d \n", QTDderrota);
    }
}
