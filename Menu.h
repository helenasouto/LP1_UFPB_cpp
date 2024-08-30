#ifndef MENU_H
#define MENU_H

#include "gerenciador.h"
#include "Pessoa.h"
#include "Paciente.h"
#include "Fisioterapeuta.h"
#include "Pacote.h"

class Menu
{
public:
    Menu();
    void exibirMenuPrincipal();
    void cadastrarPaciente();
    void cadastrarFisioterapeuta();
    void pesquisarPaciente();
    void pesquisarFisioterapeuta();
    void mostrarPacientesPorHorario();
    void mostrarFisioPorHorario();
    void atualizarDadosPessoa();
    void atualizarDadosPaciente();
    void atualizarDadosFisioterapeuta();
    void mudarHorarioPaciente();
    void removerPaciente();
    void removerFisioterapeuta();
    void adicionarHorarioLivre();
    void removerHorarioLivre();
    void listarHorariosLivres();

private:
    gerenciador Gerenciador;
    void limparTela() const;
    int lerOpcao() const;

};

#endif