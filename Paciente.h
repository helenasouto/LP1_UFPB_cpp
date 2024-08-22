#ifndef PACIENTE_H
#define PACIENTE_H
#include "Pessoa.h"

#include <string>

using namespace std;

class Paciente {

public:
    Paciente(const string& nome, int hora, int minuto,const string& cpf, int idade, const string& telefone, bool pagamento, const string& responsavel);
    string getResponsavel() const;
    bool verificarpagamento() const;
    void setPagamento(bool pagamento);
    void mostrarPacientesPorHorario() const;

protected:
    string responsavel;

private:
    bool pagamento;
};

#endif