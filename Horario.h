#ifndef HORARIO_H
#define HORARIO_H

#include <vector>
#include "Pessoa.h"

class Horario {
public:
    void cadastrarPessoa(const Pessoa& pessoa);
    void mostrarPacientesPorHorario() const;
    void pesquisarPessoaPorNome(const std::string& nome) const;
    void mostrarFisioPorHorario() const;

private:
    std::vector<Pessoa> pessoas;
};

#endif