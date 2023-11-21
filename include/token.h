// token.h
#pragma once

#include <string>

// Enumeração para representar os diferentes tipos de tokens
enum class TokenTipo {
    IDENTIFICADOR,   // Tokens para identificadores (nomes de variáveis, funções, etc.)
    NUMERO,          // Tokens para números (inteiros ou decimais)
    OPERADOR,        // Tokens para operadores (+, -, *, /, etc.)
    PALAVRA_CHAVE,   // Tokens para palavras-chave (if, else, return, etc.)
    FIM_DE_ARQUIVO,  // Token indicando o final do arquivo
    DESCONHECIDO     // Token para tipos desconhecidos ou inválidos
    // Adicione mais tipos conforme necessário para o seu projeto
};

class Token {
public:
    // Construtor padrão
    Token() : tipo(TokenTipo::DESCONHECIDO), valor("") {}

    // Construtor com tipo e valor
    Token(TokenTipo type, const std::string& value) : tipo(type), valor(value) {}

    // Construtor com tipo, valor, linha e coluna (adicionado)
    Token(TokenTipo type, const std::string& value, int linha, int coluna)
        : tipo(type), valor(value), linha(linha), coluna(coluna) {}

    // Métodos para obter informações sobre o token
    TokenTipo getTipo() const { return tipo; }
    const std::string& getValor() const { return valor; }

    // Métodos para obter informações sobre a posição do token no código fonte
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }

    // Método para obter uma string representando o tipo do token
    std::string getTokenTipo() const;

    // Método para imprimir informações sobre o token (adicionado)
    void imprimir() const;

private:
    TokenTipo tipo;     // Variável para armazenar o tipo do token no código fonte
    std::string valor;  // Variável para armazenar o valor do token no código fonte
    int linha;          // Variável para armazenar a linha do token no código fonte
    int coluna;         // Variável para armazenar a coluna do token no código fonte
};
