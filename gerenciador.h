#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "Pessoa.h"
#include "Fisioterapeuta.h"
#include "Paciente.h"
#include <vector>

using namespace std;


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
     void atualizarPessoa(const string& cpf, const string& novoNome, int novaHora, int novoMinuto, int novaIdade, const string& novoTelefone);
     void atualizarPaciente(const string& cpf, const string& novoResponsavel, const string& novoTipoPacote, bool novoPagamento);
     void atualizarFisioterapeuta(const string& cpf, const string& novoDRF);
     void mudarHorarioPaciente(const string& cpf, int novaHora, int novoMinuto);
     void removerPaciente(const string& cpf);
     void removerFisioterapeuta(const string& cpf);
     void adicionarHorarioLivre(const string& cpf, int hora, int minuto);
     void removerHorarioLivre(const string& cpf, int hora, int minuto);
     void listarHorariosLivres(const string& cpf) const;


private:
    vector<Pessoa*> pessoaList;
    vector <Paciente> pacienteList;
    vector <Fisioterapeuta> fisioList;

};

#endif