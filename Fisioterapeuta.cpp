#include "Fisioterapeuta.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Fisioterapeuta::Fisioterapeuta(const string& nome, int hora, int minuto,const string& cpf, int idade, const string& telefone, const string& drf)
: Pessoa (nome, hora, minuto, cpf, idade, telefone), drf(){}

void Fisioterapeuta::atualizarFisioterapeuta(const string& cpf, const string& novoDRF) {
    for (auto& fisioterapeuta : fisioList) {
        if (fisioterapeuta.getCPF() == cpf) {
            fisioterapeuta.atualizarDRF(novoDRF);
            return;
        }
    }
    
    cout << "Fisioterapeuta não encontrado" << endl;
}

string Fisioterapeuta:: getDRF () const{
    return drf;
}
void Fisioterapeuta::adicionarHorarioLivre(int hora, int minuto){
    horarios_livres.push_back(make_pair(hora , minuto));
}
void Fisioterapeuta::removerHorarioLivre(int hora, int minuto){
    for(size_t i = 0; i < horarios_livres.size(); i++){
            if (horarios_livres[i].first == hora && horarios_livres[i].second == minuto){
                horarios_livres.erase((horarios_livres.begin())+i);
                break;
            }
    }
}

void Fisioterapeuta:: adicionarpaciente(const string& nome_paciente){
    pacientes.push_back(nome_paciente);
}
void Fisioterapeuta::mostrarpacientes() const{
    cout << "Pacientes do(a) fisioterapeuta: " << nome << endl;
    for (const auto& paciente : pacientes){
        cout<<paciente<< endl;
    }
}

vector<pair<int, int>> Fisioterapeuta::getHorariosLivres() const {
    return horarios_livres;
}

void Fisioterapeuta::atualizarDados(const string& nome, int hora, int minuto, int idade, const string& telefone) {
    this->nome = nome;
    this->hora = hora;
    this->minuto = minuto;
    this->idade = idade;
    this->telefone = telefone;
}

void Fisioterapeuta::atualizarDRF(const string& novoDRF) {
    this->drf = novoDRF;
}