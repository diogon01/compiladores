// buffer.h

#ifndef BUFFER_H
#define BUFFER_H

#include <string>

class Buffer {
public:
    // Construtor
    Buffer(const std::string& codigoFonte);

    // Obtém o próximo caractere do buffer
    char getProximoChar();

    // Retorna o próximo caractere sem avançar a posição atual
    char peekProximoChar() const;

    // Obtém a linha atual no código fonte
    int getLinha() const;

    // Obtém a coluna atual no código fonte
    int getColuna() const;

private:
    // Outros métodos auxiliares, se necessário

    // Atributos
    std::string codigoFonte;
    std::size_t posicao;
    int linha;
    int coluna;
};

#endif // BUFFER_H
