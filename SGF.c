// Daniel 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct CadUsuarios
    {
        char usuario[15];
        char senha[8];

    }CadUsuario;


typedef struct contas{
    char data[11];
    char descricao[100];
    char categoria[50];
    float valor;
} Conta;

typedef struct  usuarios{
    char nome[100];
    char login[20];
    char senha[20];
    Conta* contasReceber;
    int numContasReceber;
    Conta* contasPagar;
    int numContasPagar;
} Usuario;

typedef struct sistema{
    Usuario* usuarios;
    int numUsuarios;
    int usuarioLogado;
} Sistema;

int login(Sistema* sistema);
void cadastrarUsuario(Sistema* sistema);
void adicionarContaReceber(Sistema* sistema);
void adicionarContaPagar(Sistema* sistema);
void relatorioContas(Sistema* sistema);
void relatorioSaldo(Sistema* sistema);
void relatorioGastosPorCategoria(Sistema* sistema);
void limparBuffer();
CadUsuario cadastro;
char usuario2 [15];
    char senha2 [8];
int main() {

    Sistema sistema;
    sistema.numUsuarios = 0;
    sistema.usuarioLogado = -1;
    sistema.usuarios = NULL;

    int opcao;

    while (3) {
        printf("\t\n------Sistema Gerenciador Financeiro ------\n");
        printf("1. login \n");
        printf("2. Cadastrar Usuario \n");
        printf("3. Sair\n");
        printf("escolha a Opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                if (login(&sistema)) {
                    int opcaoLogado;
                    do {
                        printf("\n--- Menu ---\n");
                        printf("1. Adicionar Conta para Receber\n");
                        printf("2. Adicionar Conta para Pagar\n");
                        printf("3. Relatorio de Contas\n");
                        printf("4. Relatorio de Saldo\n");
                        printf("5. Relatorio de Gastos por Categoria\n");
                        printf("6. Sair \n");
                        printf("esolha a Opcao: ");
                        scanf("%d", &opcaoLogado);
                        fflush(stdin);

                        switch (opcaoLogado) {
                            case 1:
                                adicionarContaReceber(&sistema);
                                break;
                            case 2:
                                adicionarContaPagar(&sistema);
                                break;
                            case 3:
                                relatorioContas(&sistema);
                                break;
                            case 4:
                                relatorioSaldo(&sistema);
                                break;
                            case 5:
                                relatorioGastosPorCategoria(&sistema);
                                break;
                            case 6:
                                printf("Usuario deslogado.\n");
                                break;
                            default:
                                printf("Opcao invalida.\n");
                                break;
                        }
                    } while (opcaoLogado != 6);
                }
                break;
            case 2:
                cadastrarUsuario(&sistema);
                break;
            case 3:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }
}
//area de fazer login
int login(Sistema* sistema) {
    char login[20];
    char senha[20];

    if (sistema->numUsuarios == 0)
    {
        printf("Nenhum usuario cadastrado.");
        return 0;
    }
    
    printf("\n---Login ---\n");
    printf("Login: ");
    fgets(login, sizeof(login), stdin);
    login[strcspn(login, "\n")] = '\0';

    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';


    for (int i = 0; i < sistema->numUsuarios; i++) {
        if (strcmp(login, sistema->usuarios[i].login) == 0 && strcmp(senha, sistema->usuarios[i].senha) == 0) {
            sistema->usuarioLogado = i;
            printf("Login realizado com sucesso.\n");
            return 1;
        }
    }

    printf("Usuario ou senha invalidos.\n");
    return 0;
}

//area de cadastrar um novo usuario
void cadastrarUsuario(Sistema* sistema) {
    printf("\n--- Cadastro de Usuario ---\n");

    Usuario novoUsuario;

        strcpy(cadastro.usuario,"admin");
        strcpy(cadastro.senha,"123");

        printf("\nDigite o nome do usuario administrador: ");
        scanf("%s",usuario2);
        getchar();
        printf("\ndigite a senha do usuario administrador: ");
        scanf("%s",senha2);
         getchar();
         if ((strcmp (usuario2,cadastro.usuario)==0 ) && (strcmp (senha2,cadastro.senha)==0))
         {
            printf("usuario logado");
         }

         else
         {
            printf("\n\nUsuario ou senha invalido");
            return ;
         }

    printf("\nNome do novo usuario: ");
    fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';
getchar();
    printf("Login: ");
    fgets(novoUsuario.login, sizeof(novoUsuario.login), stdin);
    novoUsuario.login[strcspn(novoUsuario.login, "\n")] = '\0';
getchar();
    printf("Senha: ");
    fgets(novoUsuario.senha, sizeof(novoUsuario.senha), stdin);
    novoUsuario.senha[strcspn(novoUsuario.senha, "\n")] = '\0';
getchar();
    novoUsuario.numContasReceber = 0;
    novoUsuario.numContasPagar = 0;

    sistema->numUsuarios++;
    sistema->usuarios = realloc(sistema->usuarios, sistema->numUsuarios * sizeof(Usuario));
    sistema->usuarios[sistema->numUsuarios - 1] = novoUsuario;

    printf("Usuario cadastrado com sucesso.\n");
}
//daniel
//cadastrar conta a receber
void adicionarContaReceber(Sistema* sistema) {
    Usuario* usuario = &(sistema->usuarios[sistema->usuarioLogado]);

    Conta novaConta;

    printf("\n--- Adicionar Conta a Receber ---\n");
    printf("Data (dd/mm/aaaa): ");
    fgets(novaConta.data, sizeof(novaConta.data), stdin);
    novaConta.data[strcspn(novaConta.data, "\n")] = '\0';
    getchar();
    printf("Descricao: ");
    fgets(novaConta.descricao, sizeof(novaConta.descricao), stdin);
    novaConta.descricao[strcspn(novaConta.descricao, "\n")] = '\0';
    getchar();
    printf("Categoria do Provento: ");
    fgets(novaConta.categoria, sizeof(novaConta.categoria), stdin);
    novaConta.categoria[strcspn(novaConta.categoria, "\n")] = '\0';
    getchar();
    printf("Valor Recebido: ");
    scanf("%f", &novaConta.valor);
    getchar();

    usuario->numContasReceber++;
    usuario->contasReceber = malloc(usuario->numContasReceber * sizeof(Conta));
    usuario->contasReceber[usuario->numContasReceber - 1] = novaConta;

    printf("Conta para receber adicionada com sucesso.\n");
}
//cadastrar contas a pagar
void adicionarContaPagar(Sistema* sistema) {
   
       Usuario* usuario = &(sistema->usuarios[sistema->usuarioLogado]);

    Conta novaConta;

    printf("\n--- Adicionar Conta a Apagar ---\n");
    printf("Data (dd/mm/aaaa): ");
    fgets(novaConta.data, sizeof(novaConta.data), stdin);
    novaConta.data[strcspn(novaConta.data, "\n")] = '\0';
    getchar();
    printf("Descricao: ");
    fgets(novaConta.descricao, sizeof(novaConta.descricao), stdin);
    novaConta.descricao[strcspn(novaConta.descricao, "\n")] = '\0';
    getchar();
    printf("Categoria do Provento: ");
    fgets(novaConta.categoria, sizeof(novaConta.categoria), stdin);
    novaConta.categoria[strcspn(novaConta.categoria, "\n")] = '\0';
    getchar();
    printf("Valor a Pagar: ");
    scanf("%f", &novaConta.valor);
    getchar();

    usuario->numContasPagar++;
    usuario->contasPagar = malloc(usuario->numContasPagar * sizeof(Conta));
    usuario->contasPagar[usuario->numContasPagar- 1] = novaConta;

    printf("Conta para pagar adicionada com sucesso.\n");
}
//relatorio de contas a pagar e receber
void relatorioContas(Sistema* sistema) {
    Usuario* usuario = &(sistema->usuarios[sistema->usuarioLogado]);

    printf("\n--- Relatório de Contas ---\n");
    printf("Quantidade total de contas a receber: %d\n", usuario->numContasReceber);
    printf("Quantidade total de contas a pagar: %d\n", usuario->numContasPagar);
}
//saldo final que sobrou
void relatorioSaldo(Sistema* sistema) {
    Usuario* usuario = &(sistema->usuarios[sistema->usuarioLogado]);

    printf("\n--- Relatorio de Saldo ---\n");
    float saldo = 0.0;

    for (int i = 0; i < usuario->numContasReceber; i++) {
        saldo += usuario->contasReceber[i].valor;
    }

    for (int i = 0; i < usuario->numContasPagar; i++) {
        saldo -= usuario->contasPagar[i].valor;
    }

    printf("Saldo de Contas: %.2f\n", saldo);
}
//relatorio de casto por categoria cadastra
void relatorioGastosPorCategoria(Sistema* sistema) {
    Usuario* usuario = &(sistema->usuarios[sistema->usuarioLogado]);

    printf("\n--- Relatorio de Gastos por Categoria ---\n");

    float* totalGastosPorCategoria = malloc(50 * sizeof(float));
    for (int i = 0; i < 50; i++) {
        totalGastosPorCategoria[i] = 0.0;
    }

    for (int i = 0; i < usuario->numContasPagar; i++) {
        for (int j = 0; j < 50; j++) {
            if (strcmp(usuario->contasPagar[i].categoria, usuario->contasPagar[j].categoria) == 0) {
                totalGastosPorCategoria[j] += usuario->contasPagar[i].valor;
                break;
            }
        }
    }

    for (int i = 0; i < 50; i++) {
        if (totalGastosPorCategoria[i] > 0) {
            printf("Categoria: %s\n", usuario->contasPagar[i].categoria);
            printf("Total de Gastos: %.2f\n", totalGastosPorCategoria[i]);
            printf("\n");
        }
    }
}