
#include <cstring>
#include <string>
#include "randoms.hpp"
using namespace std;

struct pedido {
    long long id_pedido;        // identificador único do pedido
    char codigo_cliente[20];    // código do cliente (string curta)
    char nome_cliente[100];     // nome do cliente
    double valor_total;         // valor total do pedido
    int quantidade_itens;       // número de itens no pedido
    char status[16];            // "PENDENTE", "FATURADO", "CANCELADO"
    bool pago;                  // indica se o pedido foi pago
    char forma_pagamento[20];   // "PIX", "CARTAO", "BOLETO"
    int prioridade;             // 1 (baixa), 2 (média), 3 (alta)
    char uf[3];                 // estado do cliente (ex: "RS", "SP")
    char categoria_cliente;     // 'A', 'B' ou 'C'

    bool operator<(const pedido& other) const {
        if (prioridade != other.prioridade)
            return prioridade < other.prioridade;
        if (valor_total != other.valor_total)
            return valor_total < other.valor_total;
        if (quantidade_itens != other.quantidade_itens)
            return quantidade_itens < other.quantidade_itens;
        int cmp_status = strcmp(status, other.status);
        if (cmp_status != 0)
            return cmp_status < 0;
        if (pago != other.pago)
            return !pago && other.pago;
        int cmp_forma = strcmp(forma_pagamento, other.forma_pagamento);
        if (cmp_forma != 0)
            return cmp_forma < 0;
        if (categoria_cliente != other.categoria_cliente)
            return categoria_cliente < other.categoria_cliente;
        int cmp_uf = strcmp(uf, other.uf);
        if (cmp_uf != 0)
            return cmp_uf < 0;
        int cmp_nome = strcmp(nome_cliente, other.nome_cliente);
        if (cmp_nome != 0)
            return cmp_nome < 0;
        int cmp_codigo = strcmp(codigo_cliente, other.codigo_cliente);
        if (cmp_codigo != 0)
            return cmp_codigo < 0;
        return id_pedido < other.id_pedido;
    }

    bool operator==(const pedido& other) const {
        return id_pedido == other.id_pedido &&
            strcmp(codigo_cliente, other.codigo_cliente) == 0 &&
            strcmp(nome_cliente, other.nome_cliente) == 0 &&
            valor_total == other.valor_total &&
            quantidade_itens == other.quantidade_itens &&
            strcmp(status, other.status) == 0 &&
            pago == other.pago &&
            strcmp(forma_pagamento, other.forma_pagamento) == 0 &&
            prioridade == other.prioridade &&
            strcmp(uf, other.uf) == 0 &&
            categoria_cliente == other.categoria_cliente;
    }

    bool operator<=(const pedido& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const pedido& other) const {
        return other < *this;
    }

    bool operator>=(const pedido& other) const {
        return other > *this || other == *this;
    }

    // construtor padrão
    pedido()
        : id_pedido(0),
          valor_total(0.0),
          quantidade_itens(0),
          pago(false),
          prioridade(1),
          categoria_cliente('C') {
        strcpy(codigo_cliente, "");
        strcpy(nome_cliente, "");
        strcpy(status, "PENDENTE");
        strcpy(forma_pagamento, "PIX");
        strcpy(uf, "RS");
    }

    // -------------------------------------
    // construtor aleatório coerente
    // -------------------------------------
    static pedido aleatorio() {
        static long long id_cnt = 0;
        pedido p;
        p.id_pedido = id_cnt++;

        // código e nome
        string cod = randomString(20);
        string nome = randomString(100);
        strncpy(p.codigo_cliente, cod.c_str(), sizeof(p.codigo_cliente) - 1);
        strncpy(p.nome_cliente, nome.c_str(), sizeof(p.nome_cliente) - 1);

        // quantidade e valor total
        p.quantidade_itens = randomValue<int>() % 10 + 1; // 1 a 10 itens
        p.valor_total = p.quantidade_itens * (10.0 + randomValue<double>() / 100.0);

        // status
        static const char* status_opts[] = {
            "PENDENTE", "FATURADO", "CANCELADO"
        };
        int sidx = randomValue<int>() % 3;
        strcpy(p.status, status_opts[sidx]);

        // coerência: se cancelado → não pago
        // se faturado → pago
        // se pendente → pago pode ser aleatório
        if (strcmp(p.status, "CANCELADO") == 0)
            p.pago = false;
        else if (strcmp(p.status, "FATURADO") == 0)
            p.pago = true;
        else
            p.pago = randomValue<int>() % 2;

        // forma de pagamento
        static const char* formas[] = {"PIX", "CARTAO", "BOLETO"};
        strcpy(p.forma_pagamento, formas[randomValue<int>() % 3]);

        // prioridade e categoria
        p.prioridade = (randomValue<int>() % 3) + 1;
        p.categoria_cliente = static_cast<char>('A' + (randomValue<int>() % 3));

        // estado (UF)
        static const char* estados[] = {
            "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA",
            "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN",
            "RS", "RO", "RR", "SC", "SP", "SE", "TO"
        };
        strcpy(p.uf, estados[randomValue<int>() % 8]);

        return p;
    }
};
