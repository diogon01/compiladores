// token.cpp
#include "token.h"
#include <iostream>

// Método para obter uma string representando o tipo do token
std::string Token::getTokenTipo() const {
    // Mapeie os tipos de token para strings legíveis
    switch (tipo) {
        case TokenTipo::IDENTIFICADOR:
            return "IDENTIFICADOR";
        case TokenTipo::NUMERO:
            return "NUMERO";
        case TokenTipo::OPERADOR:
            return "OPERADOR";
        case TokenTipo::PALAVRA_CHAVE:
            return "PALAVRA_CHAVE";
        case TokenTipo::FIM_DE_ARQUIVO:
            return "FIM_DE_ARQUIVO";
        default:
            return "DESCONHECIDO";
    }
}

// Método para imprimir informações sobre o token
void Token::imprimir() const {
    std::cout << "Tipo: " << getTokenTipo() << "\n";
    std::cout << "Valor: " << valor << "\n";
    std::cout << "Linha: " << linha << "\n";
    std::cout << "Coluna: " << coluna << "\n";
    std::cout << "----------------\n";
}
