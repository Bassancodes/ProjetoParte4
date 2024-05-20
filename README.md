Sistema Bancário Quem Poupa Tem
Bem-vindo ao sistema bancário Quem Poupa Tem! Este projeto foi desenvolvido para gerenciar as operações bancárias dos clientes do banco QuemPoupaTem, que trabalha com dois tipos de contas: Comum e Plus. Este sistema foi desenvolvido em C e pode ser utilizado para adicionar, remover e gerenciar clientes e suas contas bancárias.

Requisitos
O banco possui dois tipos de conta, cada uma com suas características específicas:

Conta Comum:

Cobra uma taxa de 5% a cada débito realizado.
Permite um saldo negativo de até R$ 1.000,00.
Conta Plus:

Cobra uma taxa de 3% a cada débito realizado.
Permite um saldo negativo de até R$ 5.000,00.
Funcionalidades do Sistema
O sistema funciona em um loop infinito até que o operador deseje sair. Um menu de opções é sempre apresentado ao operador, contendo as seguintes operações:

Novo cliente: Adiciona um novo cliente ao sistema.
Apaga cliente: Remove um cliente do sistema.
Listar clientes: Lista todos os clientes cadastrados no sistema.
Débito: Realiza uma operação de débito em uma conta específica.
Depósito: Realiza uma operação de depósito em uma conta específica.
Extrato: Exibe o extrato de uma conta específica.
Transferência Entre Contas: Realiza uma transferência de fundos entre duas contas.
Sair: Encerra o sistema.
O código está estruturado de forma a facilitar a manutenção e a adição de novas funcionalidades. Aqui está uma visão geral dos principais componentes:

main.c: Contém a função principal que inicializa o sistema e apresenta o menu de opções ao operador.
funcoes.h e funcoes.c: Definem a estrutura de dados para os clientes e implementam as funções para gerenciar clientes.
funcoes.h e funcoes.c: Definem a estrutura de dados para as contas e implementam as funções para gerenciar operações de conta (débito, depósito, transferência, etc.).
