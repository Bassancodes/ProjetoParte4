#ifndef BANCO_H
#define BANCO_H
typedef struct {
    char nome[100];
    char cpf[10];
    char tipoConta[10];
    float saldo;
    char senha[20];
} Cliente;
void novo();
void debitocomsenha();
void deposito();
void extrato();
void transferencia();
void sair();
void listarcliente();
void apagacliente();
void salvarClientes();
void debitoapossenha(Cliente *cliente, double valor);
#endif