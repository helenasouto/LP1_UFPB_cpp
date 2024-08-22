#ifndef FISIOTERAPEUTA_H
#define FISIOTERAPEUTA_H
#include "Pessoa.h"
#include <vector>
#include <string>

using namespace std;

class Fisioterapeuta : public Pessoa 
{
public:
    Fisioterapeuta(const string& nome, int hora, int minuto,const string& cpf, int idade, const string& telefone, const string& drf);
    string getDRF() const;
    void adicionarHorarioLivre(int hora, int minuto);
    void removerHorarioLivre (int hora, int minuto);
    void mostrarFisioPorHorario() const;
    void adicionarpaciente(const string& nome_paciente);
    void mostrarpacientes() const;
    vector <pair<int, int>> getHorariosLivres () const;
private:
    string drf;
    vector <pair<int, int>> horarios_livres;
    vector <string>pacientes;
};

#endif