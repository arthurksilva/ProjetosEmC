#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct informacoes_da_conta
{
    char nome[50];
    int numero_da_agencia;
    int numero_da_conta_correte;
    int saldo;
    int ativo;
};
struct informacoes_da_conta conta[10];

void abrir_conta()
{

    int i;
    i = 0;

    int max, min, cont;
    max = 5000;
    min = 1000;

    do
    {
        if (conta[i].ativo == 1)
        {
            while (conta[i].ativo == 1)
            {
                i = rand() % 10;
            }
        }
        printf("\n Nome...: \n");
        gets(conta[i].nome);

        conta[i].numero_da_agencia = (rand() % (max - min + 1) + min);
        conta[i].numero_da_conta_correte = (rand() % (max - min + 1) + min);

        conta[i].saldo = 0;
        conta[i].ativo = 1;

        printf("\n--------------------------------\n");
        printf(" \nNome da conta...: %s \n", conta[i].nome);
        printf(" \nNumero da agencia...: %d \n", conta[i].numero_da_agencia);
        printf(" \nNumero da conta...: %d \n", conta[i].numero_da_conta_correte);
        printf(" \nSua conta foi aberta agora, Saldo ...: %d \n", conta[i].saldo);
        printf("\n--------------------------------\n");
        printf("\n Aperte para qlq tecla para continuar\n");
        getchar();
        fflush(stdin);

        printf("Deseja fazer outra conta..: 1-Sim / 2-Not ");
        scanf(" %d", &cont);
        fflush(stdin);

        if (cont == 1)
        {
            cont = 1;
            i++;
            system("cls");
        }
        if (cont == 2)
        {
            cont = 0;
            i++;
            system("cls");
        }

    } while (cont != 0);
}

void encerrar_conta()
{
    int cont, i, aux;
    int agencia_verificar, conta_verificar;
    printf("Qual o numero da agencia..:");
    scanf(" %d", &agencia_verificar);
    fflush(stdin);

    printf("Qual o numero da conta..:");
    scanf(" %d", &conta_verificar);
    fflush(stdin);

    for (cont = 0; cont <= 10; cont++)
    {

        if (agencia_verificar == conta[cont].numero_da_agencia &&
            conta_verificar == conta[cont].numero_da_conta_correte &&
            conta[cont].saldo == 0)
        {

            conta[cont].numero_da_agencia = 0;
            conta[cont].numero_da_conta_correte = 0;
            conta[cont].ativo = 0;
            printf("\n Sua conta foi encerrada \n");
        }
    }
}

void consultar_conta()
{
    int cont;
    int agencia_verificar, conta_verificar;
    printf("Qual o numero da agencia..:");
    scanf(" %d", &agencia_verificar);
    fflush(stdin);

    printf("Qual o numero da conta..:");
    scanf(" %d", &conta_verificar);
    fflush(stdin);

    for (cont = 0; cont <= 10; cont++)
    {

        if (agencia_verificar == conta[cont].numero_da_agencia &&
            conta_verificar == conta[cont].numero_da_conta_correte)
        {
            printf("\nO nome..: %s \n", conta[cont].nome);
            printf(" \nO numero da agencia..: %d\n ", conta[cont].numero_da_agencia);
            printf(" \nO numero da agencia..: %d\n ", conta[cont].numero_da_conta_correte);
            printf(" \nSaldo da conta..: %d\n ", conta[cont].saldo);
        }
    }

    if (agencia_verificar != conta[cont].numero_da_agencia &&
        conta_verificar != conta[cont].numero_da_conta_correte)
    {
        printf("Esse conta nao existe");
    }
}

void depositar_conta()
{
    int cont;
    int agencia_verificar, conta_verificar;
    int deposito_na_conta;

    printf("Qual o numero da agencia..:");
    scanf(" %d", &agencia_verificar);
    fflush(stdin);

    printf("Qual o numero da conta..:");
    scanf(" %d", &conta_verificar);
    fflush(stdin);

    for (cont = 0; cont <= 10; cont++)
    {

        if (agencia_verificar == conta[cont].numero_da_agencia &&
            conta_verificar == conta[cont].numero_da_conta_correte)
        {
            printf("Qtd vc desejar depositar...:");
            scanf(" %d", &deposito_na_conta);
            fflush(stdin);

            printf("Saldo atual...: %d", conta[cont].saldo = conta[cont].saldo + deposito_na_conta);
            printf("\n Depositor feito com sucesso.\n");
        }
    }
    getchar();
}

void encerrar()
{
    printf("Muito obrigado por usuar nosso sistema.");
    printf("Aperte qlq tecla para finalizar o sistema");
    getchar();
    end(0);
}

void sacar()
{
    int cont;
    int agencia_verificar, conta_verificar;
    int sacar_da_conta, qtd;
    sacar_da_conta = qtd = 0;
    printf("Qual o numero da agencia..:");
    scanf(" %d", &agencia_verificar);
    fflush(stdin);

    printf("Qual o numero da conta..:");
    scanf(" %d", &conta_verificar);
    fflush(stdin);

    for (cont = 0; cont <= 10; cont++)
    {

        if (agencia_verificar == conta[cont].numero_da_agencia &&
            conta_verificar == conta[cont].numero_da_conta_correte)
        {
            printf("\n Qtd vc desejar sacar...: \n");
            scanf(" %d", &sacar_da_conta);
            fflush(stdin);

            if (sacar_da_conta <= conta[cont].saldo)
            {
                conta[cont].saldo = conta[cont].saldo - sacar_da_conta;
                printf("\n Vc sacou %d . Seu saldo atual eh %d \n ", sacar_da_conta, conta[cont].saldo);
            }
            else
            {
                printf("\nVc n tem saldo suficiente\n");
            }
        }
    }
}

void transferencia_entre_contas()
{
    int cont;
    int agencia_verificar, conta_verificar;
    int agencia_para_transferir, conta_para_transferir;
    int saldo_para_transferir, saldo;
    int sucesso = 0;
    int aux;

    printf("Qual o numero da agencia..:");
    scanf(" %d", &agencia_verificar);
    fflush(stdin);

    printf("Qual o numero da conta..:");
    scanf(" %d", &conta_verificar);
    fflush(stdin);

    printf("\nQual o numero da agencia para transferir..:");
    scanf(" %d", &agencia_para_transferir);
    fflush(stdin);

    printf("Qual o numero da conta para transferir..:");
    scanf(" %d", &conta_para_transferir);
    fflush(stdin);

    for (cont = 0; cont <= 10; cont++)
    {
        if (agencia_verificar == conta[cont].numero_da_agencia &&
            conta_verificar == conta[cont].numero_da_conta_correte)
        {
            printf("\nQuanto vc deseja transferir..:\n");
            scanf(" %d", &saldo);
            fflush(stdin);

            saldo_para_transferir = conta[cont].saldo - saldo;
            conta[cont].saldo = conta[cont].saldo - saldo;
        }
    }

    for (cont = 0; cont <= 10; cont++)
    {
        if (agencia_para_transferir == conta[cont].numero_da_agencia &&
            conta_para_transferir == conta[cont].numero_da_conta_correte)
        {
            aux = 2 + (saldo_para_transferir / 9);
            conta[cont].saldo = conta[cont].saldo + aux;
            sucesso++;
        }
    }

    if (sucesso == 1)
    {
        printf("\n Sucesso na transferencia.\n");
    }
    else
    {
        printf("\nConta para onde dejesa transferir errada.\n");
    }
}

void listagem_das_contas()
{
    int cont;
    for (cont = 0; cont <= 10; cont++)
    {
        if (conta[cont].ativo == 1)
        {
            printf("\n---------------------------------------------------\n");
            printf("\nO nome da conta...: %s", conta[cont].nome);
            printf("\nO numero da agencia...: %d", conta[cont].numero_da_agencia);
            printf("\nO numero da conta...: %d", conta[cont].numero_da_conta_correte);
            printf("\nO numero da saldo...: %d", conta[cont].saldo);
            printf("\n---------------------------------------------------\n");
        }
    }
}
main()
{
    srand(time(0));
    int op = 1;
    while (op != 0)
    {
        int opcao_menu;
        printf("Qual opcoa do menu ?...: \n");
        printf("\n 1-Abrir conta corrente \n 2-Encerrar Conta \n 3-Deposita na contas"
               "\n 4-Sacar \n 5-Consultar Conta \n 6-transferencia \n 7-Listagem de contas abertas"
               "\n 8-Encerrar(Sair)");
        scanf("%d", &opcao_menu);
        fflush(stdin);
        switch (opcao_menu)
        {
        case 1:
            abrir_conta();
            break;
        case 2:
            encerrar_conta();
            break;
        case 3:
            depositar_conta();
            break;
        case 4:
            sacar();
            break;
        case 5:
            consultar_conta();
            break;
        case 6:
            transferencia_entre_contas();
            break;
        case 7:
            listagem_das_contas();
            break;
        case 8:
            encerrar();
            break;
        }
        // system("cls");
        /*      TESTA O  ABRIR_CONTA
        printf(" %s ", conta[0].nome);
        printf(" N %d ", conta[0].numero_da_conta_correte);
        printf(" A %d ", conta[0].numero_da_agencia);
        printf(" S %d ", conta[0].saldo);*/
    }
}