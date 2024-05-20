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