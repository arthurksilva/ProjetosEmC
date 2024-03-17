#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

main()
{
    // Decleração das váriaes do tipo char(caractere)
    char TropaDoUsuario, TropasDaAleatorias;

    // Declaração da váriavel para escolher a tropa do computador(rand)
    int EscolhaDasTropasDaAleatorias = 0;

    // Declaração das váriaveis de quantidade
    int QTDpartidas, QTDvitorias, QTDempate, QTDderrota;

    // Iniciação das váriaveis de quantidade
    QTDpartidas = 0;
    QTDvitorias = 0;
    QTDempate = 0;
    QTDderrota = 0;

    // Declaração da váriavel de opção e sua inicialização
    int opcao = 0;

    // Explicação do jogo
    printf("\nMeu rei, o governante do sul,o rei Kratos, vem usando tropas para tentar dorminar o nosso reino.\n");

    // Inicio do jogo
    printf("\nQual tropa vamos usuar para atacar...:(Digite a primera letra da tropa)\n 1- Guerreio, 2- Arqueiro, 3- Cavaleiro\n");
    // Leitura das tropas do usuário
    scanf("%c", &TropaDoUsuario);
    // Vai conveter todo caracte em minúsculo
    TropaDoUsuario = tolower(TropaDoUsuario);

    // Inicio do laço
    while (opcao != 2)
    {

        // Tropas do sul(algoritmo) vão ser escolhidas pela função aleatótio(rand);
        srand(time(0));
        EscolhaDasTropasDaAleatorias = rand() % 4;
        if (EscolhaDasTropasDaAleatorias <= 1)
        {
            TropasDaAleatorias = 'g';
        }
        if (EscolhaDasTropasDaAleatorias == 2)
        {
            TropasDaAleatorias = 'a';
        }
        if (EscolhaDasTropasDaAleatorias == 3)
        {
            TropasDaAleatorias = 'c';
        }

        /*O if corresponde respectivamente a emparte, derrota e vitória da tropa nessa ordem  */
        // Tropa do usuário sendo guerreios
        if (TropaDoUsuario == 'g')
        {
            if (TropasDaAleatorias == 'g')
            {
                printf("EMPATE, o rei Kratos usou o mesmo tipo de tropa");
                QTDpartidas = QTDpartidas + 1;
                QTDempate = QTDempate + 1;
            }
            if (TropasDaAleatorias == 'c')
            {
                printf("Derrota, as tropas de cavaleiros do sul venceram");
                QTDpartidas = QTDpartidas + 1;
                QTDderrota = QTDderrota + 1;
            }
            if (TropasDaAleatorias == 'a')
            {
                printf("Conseguimos vencer as tropas do sul de arqueiros");
                QTDpartidas = QTDpartidas + 1;
                QTDvitorias = QTDvitorias + 1;
            }
        }

        // Tropa do usuário sendo arqueiros
        if (TropaDoUsuario == 'a')
        {
            if (TropasDaAleatorias == 'a')
            {
                printf("EMPATE, o rei Kratos usou o mesmo tipo de tropa");
                QTDpartidas = QTDpartidas + 1;
                QTDempate = QTDempate + 1;
            }
            if (TropasDaAleatorias == 'g')
            {
                printf("Derrota, Tropas do sul de guerreios venceram");
                QTDpartidas = QTDpartidas + 1;
                QTDderrota = QTDderrota + 1;
            }
            if (TropasDaAleatorias == 'c')
            {
                printf("Conseguimos vencer a Tropas de cavaleiros do sul");
                QTDpartidas = QTDpartidas + 1;
                QTDvitorias = QTDvitorias + 1;
            }
        }

        // Tropa do usuário sendo cavaleiro
        if (TropaDoUsuario == 'c')
        {
            if (TropasDaAleatorias == 'c')
            {
                printf("EMPATE, o rei Kratos usou o mesmo tipo de tropa");
                QTDpartidas = QTDpartidas + 1;
                QTDempate = QTDempate + 1;
            }
            if (TropasDaAleatorias == 'a')
            {
                printf("Derrota, Tropas do sul de arqueiros venceram");
                QTDpartidas = QTDpartidas + 1;
                QTDderrota = QTDderrota + 1;
            }
            if (TropasDaAleatorias == 'g')
            {
                printf("Conseguimos vencer a Tropas de guerreios do suç");
                QTDpartidas = QTDpartidas + 1;
                QTDvitorias = QTDvitorias + 1;
            }
        }

        // Para saber se o usuário desejar continuar o jogo
        printf("\n-----------------------------------------------------------------\n");
        printf("\nDejesar jogar novamente....: 1-SIM , 2-NAO\n");
        scanf("%d", &opcao);
        // Vai limpar o buffer do teclado
        fflush(stdin);
        if (opcao == 1)
        {
            printf("\nQual tropa vamos usuar para atacar...:(Digite a primera letra da tropa)\n 1- Guerreio, 2- Arqueiro, 3- Cavaleiro\n");
            scanf("%c", &TropaDoUsuario);
            // Vai conveter todo caracte em minúsculo
            TropaDoUsuario = tolower(TropaDoUsuario);
        }
    }

    // Resultados de todas as partidas
    printf("\nA quantidade de partidas..: %d\n", QTDpartidas);
    printf("\nA quantidade de partidas vencidas..: %d\n", QTDvitorias);
    printf("\nA quantidade de partidas com emparte..: %d\n", QTDempate);
    printf("\nA quantidade de partidas com derrota..: %d\n", QTDderrota);
}
