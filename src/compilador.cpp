#include <iostream>
#include <fstream>
#include <string>

#include "lexico.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <nome_do_arquivo.lcc>\n";
        return 1;
    }

    const std::string nomeArquivo = argv[1];
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << "\n";
        return 1;
    }

    // Ler o conteúdo do arquivo para uma string
    std::string conteudo((std::istreambuf_iterator<char>(arquivo)), std::istreambuf_iterator<char>());

    // Criar um objeto Buffer com o conteúdo do arquivo
    Buffer buffer(conteudo);

    // Inicializar o analisador léxico
    Lexico analisadorLexico(buffer);

    // Loop para obter os tokens do analisador léxico
    Token token;
    do {
        token = analisadorLexico.obterProximoToken();
        token.imprimir();
    } while (token.getTipo() != TokenTipo::FIM_DE_ARQUIVO);

    return 0;
}
