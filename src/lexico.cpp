// lexico.cpp

#include "lexico.h"
#include <cctype> // Para a função isalpha e isdigit

// Construtor com buffer
Lexico::Lexico(Buffer& buffer) : buffer(buffer), currentLine(1), currentColumn(1) {
    // Inicialize outros membros, se necessário
}


// Obtém o próximo token do código fonte
Token Lexico::obterProximoToken() {
    // Implemente a lógica para obter o próximo token
    char currentChar = buffer.getProximoChar();

    // Exemplo simples: Identificadores
    if (isalpha(currentChar)) {
        return processIdentificador();
    }

    // Exemplo simples: Números
    if (isdigit(currentChar)) {
        return processNumero();
    }

    // Adicione lógica para outros tipos de tokens, como operadores, palavras-chave, etc.

    // Exemplo: Se atingir o final do arquivo, retorne um token de fim de arquivo
    if (currentChar == '\0') {
        return Token(TokenTipo::FIM_DE_ARQUIVO, "", currentLine, currentColumn);
    }

    // Se nenhum padrão correspondente for encontrado, retorne um token inválido
    return Token(TokenTipo::DESCONHECIDO, "INVALIDO", currentLine, currentColumn);
}

// Processa identificadores
Token Lexico::processIdentificador() {
    // Implemente a lógica para processar identificadores
    // Exemplo simples: Continue lendo caracteres alfanuméricos até encontrar um não-alfanumérico
    std::string identifierValue;
    char currentChar = buffer.peekProximoChar();
    while (isalnum(currentChar) || currentChar == '_') {
        identifierValue += buffer.getProximoChar();
        currentChar = buffer.peekProximoChar();
    }

    // Adapte conforme necessário e retorne o token correspondente
    return Token(TokenTipo::IDENTIFICADOR, identifierValue, currentLine, currentColumn);
}

// Processa números
Token Lexico::processNumero() {
    // Implemente a lógica para processar números
    // Exemplo simples: Continue lendo dígitos até encontrar um não-dígito
    std::string numberValue;
    char currentChar = buffer.peekProximoChar();
    while (isdigit(currentChar)) {
        numberValue += buffer.getProximoChar();
        currentChar = buffer.peekProximoChar();
    }

    // Adapte conforme necessário e retorne o token correspondente
    return Token(TokenTipo::NUMERO, numberValue, currentLine, currentColumn);
}

// Implemente outros métodos de processamento de tokens conforme necessário
