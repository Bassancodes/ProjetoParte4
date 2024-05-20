#include <stdio.h>
#include "funcoes.h"
//o menu tem como funcao printar todas as opcoes e logo em seguida dependendo da escolha do usuario aplicar e colocar na tela a funcao desejada pelo cliente, uma funcao simples igual fizemos no banco de phyton porem a base para o banco funcionar 
int main(){
  int e;
  printf("\nBem vindo ao Bancon");
  printf("1 - novo cliente\n");
  printf("2 - Apaga cliente\n");
  printf("3 - listar cliente\n");
  printf("4 - debito\n");
  printf("5 - deposito\n");
  printf("6 - extrato\n");
  printf("7 - transferência entre contas\n");
  printf("0 - sair\n");
  scanf("%d", &e);
  if (e == 1){
          novo();
          main();
      }
      else if (e ==2 ){
          apagacliente();
          main();
      }
      else if (e == 3){
          listarcliente();

          main();
      }
      else if (e == 4){
          deposito();
          main();
      }
      else if (e == 5){

    debitoapossenha();
          main();
      }
      else if (e == 6){
    extrato();   
          main();

      }
      else if (e == 7){
    transferencia();
          main();

      }
      else if (e == 0){
          sair();
          printf("Obrigado por usar o Banco ");
      }
  }