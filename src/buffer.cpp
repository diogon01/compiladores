// buffer.cpp

#include "buffer.h"

// Construtor
Buffer::Buffer(const std::string& codigoFonte) : codigoFonte(codigoFonte), posicao(0), linha(1), coluna(1) {}

// Obtém o próximo caractere do buffer
char Buffer::getProximoChar() {
    if (posicao < codigoFonte.size()) {
        char caractere = codigoFonte[posicao++];
        if (caractere == '\n') {
            linha++;
            coluna = 1;
        } else {
            coluna++;
        }
        return caractere;
    }
    return '\0'; // Retorna nulo ao atingir o final do arquivo
}

// Retorna o próximo caractere sem avançar a posição atual
char Buffer::peekProximoChar() const {
    if (posicao < codigoFonte.size()) {
        return codigoFonte[posicao];
    }
    return '\0'; // Retorna nulo ao atingir o final do arquivo
}

// Obtém a linha atual no código fonte
int Buffer::getLinha() const {
    return linha;
}

// Obtém a coluna atual no código fonte
int Buffer::getColuna() const {
    return coluna;
}
