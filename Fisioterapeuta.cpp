#include "Fisioterapeuta.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Fisioterapeuta::Fisioterapeuta(const string& nome, int hora, int minuto,const string& cpf, int idade, const string& telefone, const string& drf)
: Pessoa (nome, hora, minuto, cpf, idade, telefone), drf(){}

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
void Fisioterapeuta::mostrarFisioPorHorario()const{
    cout << "Horários livres para: " << nome << endl;
    for (const auto& horario : horarios_livres){
        cout << horario.first << " " << horario.second<< endl;
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