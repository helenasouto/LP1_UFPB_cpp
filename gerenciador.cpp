#include "gerenciador.h"
#include <iostream>
#include "Pessoa.h"
#include "Fisioterapeuta.h"
#include "Paciente.h"
#include <string>

using namespace std;

gerenciador::gerenciador()
{
}
gerenciador::~gerenciador() {
    for (Pessoa* p : pessoaList) {
        delete p;
    }
}

void gerenciador::cadastrarpaciente(Paciente* paciente){
    pessoaList.push_back(paciente);
}

void gerenciador::cadastrarfisioterapeuta(Fisioterapeuta* fisioterapeuta)
{
    pessoaList.push_back(fisioterapeuta);
}

void gerenciador::mostrarPacientesPorHorario() const {
    int contagem[24][60] = {0};
    for (const auto& pessoa : pessoaList) {
       if (const Paciente* paciente = dynamic_cast<const Paciente*>(pessoa)) {
            contagem[paciente->getHora()][paciente->getMinuto()]++;
    }
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 60; ++j) {
            if (contagem[i][j] > 0) {
                cout << " " << i << ":" << (j < 10 ? "0" : "") << j << " - " << contagem[i][j] << " pessoas" << endl;
            }
        }
    }
}
}
void gerenciador::mostrarFisioPorHorario(const string&nome, vector <pair<int, int>> horarios_livres)const{
    cout << "Horários livres para: " << nome << endl;
    for (const auto& horario : horarios_livres){
        cout << horario.first << " " << horario.second<< endl;
    }
}

void gerenciador::pesquisarPacientePorNome(const string& nome) const {
    for (const auto& paciente : pessoaList) {
        if (paciente->getNome() == nome) {
            cout << "Pessoa: " << paciente->getNome() << " - : " << paciente->getHora() << ":" << (paciente->getMinuto() < 10 ? "0" : "") << paciente->getMinuto() << endl;
            return;
        }
    }
    cout << "Paciente nao encontrado" << endl;
}

void gerenciador::pesquisarFisioPorNome(const string& nome) const {
    for (const auto& fisioterapeuta : pessoaList) {
        if (fisioterapeuta->getNome() == nome) {
            cout << "Pessoa: " << fisioterapeuta->getNome() << " - : " << fisioterapeuta->getHora() << ":" << (fisioterapeuta->getMinuto() < 10 ? "0" : "") << fisioterapeuta->getMinuto() << endl;
            return;
        }
    }
    cout << "Fisio nao encontrado" << endl;
}



