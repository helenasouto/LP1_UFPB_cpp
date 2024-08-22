#include "Horario.h"
#include <iostream>

using namespace std;

void Horario::cadastrarPessoa(const Pessoa& pessoa) {
    pessoas.push_back(pessoa);
}

void Horario::mostrarPacientesPorHorario() const {
    int contagem[24][60] = {0};
    for (const auto& pessoa : pessoas) {
        contagem[pessoa.getHora()][pessoa.getMinuto()]++;
    }
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 60; ++j) {
            if (contagem[i][j] > 0) {
                cout << "Horario " << i << ":" << (j < 10 ? "0" : "") << j << " - " << contagem[i][j] << " pessoas" << endl;
            }
        }
    }
}

void Horario::mostrarFisioPorHorario() const {
    
}

void Horario::pesquisarPessoaPorNome(const std::string& nome) const {
    for (const auto& pessoa : pessoas) {
        if (pessoa.getNome() == nome) {
            cout << "Pessoa: " << pessoa.getNome() << " - Horario: " << pessoa.getHora() << ":" << (pessoa.getMinuto() < 10 ? "0" : "") << pessoa.getMinuto() << endl;
            return;
        }
    }
    cout << "Pessoa nao encontrada" << endl;
}