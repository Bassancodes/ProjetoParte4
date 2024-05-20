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

