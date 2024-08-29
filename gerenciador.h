#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "Pessoa.h"
#include "Fisioterapeuta.h"
#include "Paciente.h"
#include <vector>


class gerenciador 
{
public:
    gerenciador();
    ~gerenciador();
     void cadastrarpaciente(Paciente* paciente);
     void cadastrarfisioterapeuta(Fisioterapeuta* fisioterapeuta);
     void pesquisarPacientePorNome(const string& nome) const;
     void pesquisarFisioPorNome(const string& nome) const;
     void mostrarPacientesPorHorario() const;
     void mostrarFisioPorHorario(const string&nome, vector <pair<int, int>> horarios_livres) const;

private:
    vector<Pessoa*> pessoaList;
 //   vector <Paciente> pacienteList;
  //  vector <Fisioterapeuta> fisioList;

};

#endif