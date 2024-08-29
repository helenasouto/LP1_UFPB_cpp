#include "Paciente.h"
#include "Pessoa.h"
#include "Fisioterapeuta.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Paciente::Paciente(const string& nome, int hora, int minuto, const string& cpf, int idade, const string& telefone, bool pagamento, const string& responsavel, const string& tpacote)
: Pessoa(nome, hora, minuto, cpf, idade, telefone) {
    this->pagamento = pagamento;
    this->responsavel = responsavel;
    this->tpacote = tpacote; 
}

string Paciente::getResponsavel() const {
    return responsavel;
}

string Paciente::getTipoPacote() const {
    return tpacote;
}

bool Paciente::verificarpagamento() const {
    return pagamento;
}

void Paciente::setPagamento(bool pagamento) {
    this->pagamento = pagamento;
}



