// lexico.h

#ifndef LEXICO_H
#define LEXICO_H

#include "buffer.h"
#include "token.h"

class Lexico {
public:
    // Construtores
    Lexico(Buffer& buffer);                    // Construtor com buffer

    // Obtém o próximo token do código fonte
    Token obterProximoToken();

private:
    // Métodos internos para análise léxica
    Token processaIdentificador();      // Processa identificadores
    Token processaNumero();             // Processa números
    Token processaOperador();           // Processa operadores
    Token processaOperador(char atualChar); 
    Token processaPalavraChave();       // Processa palavras-chave

    // Outros métodos auxiliares, se necessário

    // Atributos
    Buffer& buffer;                     // Referência ao buffer de entrada
    int atualLinha;                    // Número da linha atual
    int atualColuna;                  // Número da coluna atual
};

#endif // LEXICO_H
