//o arquivo programa que esta aberto eh a compilacao(./programa no terminal)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//define a quantidade maxima do array
#define QTD_CLIENTES 65
//paramentros do cliente
typedef struct {
    char nome[100];
    char cpf[10];
    char tipoConta[10];
    float saldo;
    char senha[20];
} Cliente;
//definicoes das operacoes
typedef struct {
    char data[20];
    char descricao[100];
    float valor;
} Operacao;
//clientes armazenando o valor de QTD_CLIENTES
Cliente clientes[QTD_CLIENTES];
int numClientes = 0;
//funcao para salvar clientes em um arq binario
void salvarClientes() {  
  FILE *arquivo = fopen("clientes.bin", "wb");
  //se o arquivo nao estiver apontando valor para a memoria da em erro    
  if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
  /*escrevendo dados no arquivo com clientes sendo o array de Clientes e o num de clientes para o num de clientes no arq binario*/
      fwrite(clientes, sizeof(Cliente), numClientes, arquivo);
  //fecha o arquivo
      fclose(arquivo);
  }
void novo() {
    printf("Novo cliente");//coloca na tela oque deve ser feito
    char cpf[10];//pede para o cliente informar o cpf
    printf("Seu CPF: ");//coloca na tela oque deve ser feito
    scanf("%s", cpf);//le o cpf
    char filename[40];//formata e armazena
    sprintf(filename, "%s.bin", cpf);//print no arquivo
    FILE *arquivosnomes; //arquivo com as informacoes
    arquivosnomes = fopen(filename, "r");//abre o arquivo para leitura
    if (!arquivosnomes) { //optei por nao usar o = NULL 
        char nome[50], senha[20], tipooo[2];//as informacoes em seus numeros combinados
        float valor;
        printf("Seu nome: ");//coloca na tela oque deve ser feito
        scanf("%s", nome);//le
        printf("Coloque sua senha: ");//coloca na tela oque deve ser feito
        scanf("%s", senha);//le
        printf("escolha um tipo de conta: 1-Comum 2-Plus. ");//coloca na tela oque deve ser feito
        scanf("%s", tipooo);//le
        printf("Valor inicial da conta: ");//coloca na tela oque deve ser feito
        scanf("%f", &valor);//le
        char tipo[6];
        if (strcmp(tipooo, "1") == 0) {
            strcpy(tipo, "comum");//caso a escolha for 1 tipo commum
        }
        else {//caso contrario tipo plus
            strcpy(tipo, "plus");
        }
        arquivosnomes = fopen(filename, "w");//abre o arquivo para escrita
        fprintf(arquivosnomes, "Nome: %s Seu CPF: %s Senha: %s Tipo: %s", nome, cpf, senha, tipo);//coloca os dados
        fprintf(arquivosnomes, "Tarifa:     0.00   "; //coloca valores
        fclose(arquivosnomes);// fecha o arquivo
      printf("Conta cadastrada.\n");//informa

    }
}
//a funcao tem como objetivo apagar uma conta ja existente no "arquivonomes", arquivo onde sao inseridas todas as informações digitadas pelo usuário, a funcao printa todas as informações necessárias, pedindo cpf e senha da conta, logo em seguida confere se ambos os dados batem com o arquivo onde as informações estao guardadas, caso as informações nao corresponderem o arquivo informa o erro e te leva ao menu novamente, caso esteje tudo certo, o codigo exclui do arquivo e informa a acao para o cliente.
void apagacliente() {
    char cpf[10];
    printf("Seu CPF: ");//coloca na tela oque deve ser feito
    scanf("%s", cpf);
    char apagacliente[30];
    sprintf(apagacliente, "%s.bin", cpf);
    FILE *arquivonomes;
    arquivonomes = fopen(apagacliente, "r");
    if (arquivonomes == NULL) {
        printf("Erro, tente novamente \n");//informa

    }
    else {
        fclose(arquivonomes);
        char senha[20];
        printf("Sua Senha: ");//pede informacao
        scanf("%s", senha);
        FILE *arquivo = fopen(apagacliente, "r");//abre o arquivo para leitura e para conferir
        char choice[2][20];
        int i = 0;
        while (fgets(choice[i], 20, arquivo)) { //confere
            choice[i][strlen(choice[i]) - 1] = '\0';
            i++;
        }
        fclose(arquivo);
        if (strcmp(senha, choice[1]) == 0) { //confere
            remove(apagacliente);
            printf("Conta apagada com sucesso\n");

        }
        else {
            printf("Erro, tente novamente\n");

        }
    }
}

void debito() {
  printf("Voce selecionou debito!\n");
  char cpf[10], senha[20];
  float valor;
  //imputs
  printf("CPF: ");
  scanf("%s", cpf);

  printf("Senha: ");
  scanf("%s", senha);
  //comparando strings e retorna 0 se as duas forem iguais
  int x = -1;
  for (int i = 0; i < numClientes; i++) {
      if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
          x = i;
          break;
      }
  }
//se a condicao do laco for nao for cumprido ele executa a linha de baixo e nao muda o valor de x
  if (x == -1) {
      printf("Cliente nao encontrado ou senha incorreta.'-'\n");
      return;
  }

  printf("Valor: ");
  scanf("%f", &valor);
  //comparando strings e retorna 0 se as duas forem iguais
  if (strcmp(clientes[x].tipoConta, "comum") == 0) {
    //verifica o saldo    
    if (valor > clientes[x].saldo + 1000) {
          printf("Saldo insuficiente. :/ \n");
          return;
      }
//aplicando a taxa de 5% de débito
      clientes[x].saldo -= valor * 0.05;  
  } else if (strcmp(clientes[x].tipoConta, "plus") == 0) {
   //verifica o saldo  
    if (valor > clientes[x].saldo + 5000) {
          printf("Saldo insuficiente.:/ \n");
          return;
      }
//aplicando a taxa de 3% de débito
      clientes[x].saldo -= valor * 0.03;  
  } 
  //se a condicao do laco for nao for cumprido ele executa a linha de       baixo e nao muda o valor de x 
else{
      printf("Tipo de conta invalido.'-'\n");
      return;
  }
//volta para a funcao de amazenar no binario, adicionando no saldo
  salvarClientes();

  printf("Debito realizado com sucesso =).\n");
}

void extrato() {
    printf("Voce selecionou extrato!\n");
    char cpf[10];
    char senha[20];
    //imputs
    printf("CPF: ");
    scanf("%s", cpf);

    printf("Senha: ");
    scanf("%s", senha);
    //comparando strings e retorna 0 se as duas forem iguais
    int x = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            x = i;
            break;
        }
    }
    //se a condicao do laco for nao for cumprido ele executa a linha de       baixo e nao muda o valor de x
    if (x == -1) {
        printf("Cliente nao encontrado ou senha incorreta.'-'\n");
        return;
    }

    printf("Extrato:\n");
    printf("Saldo atual: R$ %.2f =) \n,", clientes[x].saldo);
}

