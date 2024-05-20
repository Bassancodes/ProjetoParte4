#ifndef BANCO_H
#define BANCO_H
typedef struct {
    char nome[100];
    char cpf[10];
    char tipoConta[10];
    float saldo;
    char senha[20];
} Cliente;
