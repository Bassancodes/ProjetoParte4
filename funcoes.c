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

