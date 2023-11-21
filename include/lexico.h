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
    Token processIdentificador();      // Processa identificadores
    Token processNumero();             // Processa números
    Token processOperador();           // Processa operadores
    Token processPalavraChave();       // Processa palavras-chave

    // Outros métodos auxiliares, se necessário

    // Atributos
    Buffer& buffer;                     // Referência ao buffer de entrada
    int currentLine;                    // Número da linha atual
    int currentColumn;                  // Número da coluna atual
};

#endif // LEXICO_H
