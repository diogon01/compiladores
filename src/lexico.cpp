// lexico.cpp

#include "lexico.h"
#include <cctype>

// Construtor com buffer
Lexico::Lexico(Buffer& buffer) : buffer(buffer), atualLinha(1), atualColuna(1) {
    // Inicialize outros membros, se necessário
}

// Obtém o próximo token do código fonte
Token Lexico::obterProximoToken() {
    // Implemente a lógica para obter o próximo token
    char currentChar = buffer.getProximoChar();

    // Pular espaços em branco e caracteres de nova linha
    while (isspace(currentChar)) {
        if (currentChar == '\n') {
            ++atualLinha;
            atualColuna = 1;  // Reinicia a contagem de colunas para a nova linha
        } else {
            ++atualColuna;
        }
        currentChar = buffer.getProximoChar();
    }

    // Exemplo simples: Identificadores
    if (isalpha(currentChar) || currentChar == '_') {
        return processaIdentificador();
    }

    // Exemplo simples: Números
    if (isdigit(currentChar)) {
        return processaNumero();
    }

    // Exemplo simples: Operadores e pontuações
    switch (currentChar) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case '<':
        case '>':
        case '!':
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
        case ';':
        case ',':
            return processaOperador(currentChar);

        default:
            // Adicione lógica para outros tipos de tokens, como palavras-chave, strings, etc.

            // Exemplo: Se atingir o final do arquivo, retorne um token de fim de arquivo
            if (currentChar == '\0') {
                return Token(TokenTipo::FIM_DE_ARQUIVO, "", atualLinha, atualColuna);
            }

            // Se nenhum padrão correspondente for encontrado, retorne um token inválido
            return Token(TokenTipo::DESCONHECIDO, "INVALIDO", atualLinha, atualColuna);
    }
}


// Processa identificadores
Token Lexico::processaIdentificador() {
    // Implemente a lógica para processar identificadores
    // Exemplo simples: Continue lendo caracteres alfanuméricos até encontrar um não-alfanumérico
    std::string identifierValue;
    char currentChar = buffer.peekProximoChar();
    while (isalnum(currentChar) || currentChar == '_') {
        identifierValue += buffer.getProximoChar();
        currentChar = buffer.peekProximoChar();
    }

    // Adapte conforme necessário e retorne o token correspondente
    return Token(TokenTipo::IDENTIFICADOR, identifierValue, atualLinha, atualColuna);
}

// Processa números
Token Lexico::processaNumero() {
    // Implemente a lógica para processar números
    // Exemplo simples: Continue lendo dígitos até encontrar um não-dígito
    std::string numberValue;
    char currentChar = buffer.peekProximoChar();
    while (isdigit(currentChar)) {
        numberValue += buffer.getProximoChar();
        currentChar = buffer.peekProximoChar();
    }

    // Adapte conforme necessário e retorne o token correspondente
    return Token(TokenTipo::NUMERO, numberValue, atualLinha, atualColuna);
}

// Processa operadores e pontuações
Token Lexico::processaOperador(char currentChar) {
    // Implemente a lógica para processar operadores e pontuações
    // Pode ser necessário usar o caractere passado como argumento (currentChar)

    // Adicione lógica para operadores de um único caractere

    switch (currentChar) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
        case ';':
        case ',':
            return Token(TokenTipo::OPERADOR, std::string(1, currentChar), atualLinha, atualColuna);

        case '=': {
            char nextChar = buffer.peekProximoChar();
            if (nextChar == '=') {
                buffer.getProximoChar(); // Consome o segundo '='
                return Token(TokenTipo::OPERADOR, "==", atualLinha, atualColuna);
            } else {
                return Token(TokenTipo::OPERADOR, "=", atualLinha, atualColuna);
            }
        }

        case '<':
        case '>':
        case '!': {
            // Adicione lógica para outros operadores de um caractere

            // Exemplo simples: Operadores de dois caracteres, como "<=", ">=", "!="
            char nextChar = buffer.peekProximoChar();
            if (nextChar == '=') {
                buffer.getProximoChar(); // Consome o segundo caractere
                return Token(TokenTipo::OPERADOR, std::string(1, currentChar) + '=', atualLinha, atualColuna);
            } else {
                // Se for apenas um caractere, retorne o token correspondente
                return Token(TokenTipo::OPERADOR, std::string(1, currentChar), atualLinha, atualColuna);
            }
        }

        default:
            // Se nenhum padrão correspondente for encontrado, retorne um token inválido
            return Token(TokenTipo::DESCONHECIDO, "INVALIDO", atualLinha, atualColuna);
    }
}

// ... (restante do código)
