#include "Menu.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Menu::Menu()
{
}

gerenciador Gerenciador;

void Menu::limparTela() const {
    // Limpa a tela (funciona no terminal, mas pode variar conforme o sistema operacional)
    system("clear"); // Para Linux/Mac
    system("cls");
    
}

int Menu::lerOpcao() const {
    int opcao;
    cin >> opcao;
    while (cin.fail()) {
        cin.clear(); // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora entradas inválidas
        cout << "Entrada inválida. Por favor, insira um número: ";
        cin >> opcao;
    }
    return opcao;
}

void Menu::exibirMenuPrincipal() {
    int opcao;
    do {
        limparTela();
        cout << "=== Menu Principal ===" << endl;
        cout << "1. Cadastrar Paciente" << endl;
        cout << "2. Cadastrar Fisioterapeuta" << endl;
        cout << "3. Pesquisar Paciente por Nome" << endl;
        cout << "4. Pesquisar Fisioterapeuta por Nome" << endl;
        cout << "5. Mostrar Pacientes por Horário" << endl;
        cout << "6. Atualizar Dados de Pessoa" << endl;
        cout << "7. Atualizar Dados de Paciente" << endl;
        cout << "8. Atualizar Dados de Fisioterapeuta" << endl;
        cout << "9. Mudar Horário de Paciente" << endl;
        cout << "10. Remover Paciente" << endl;
        cout << "11. Remover Fisioterapeuta" << endl;
        cout << "12. Adicionar Horário Livre para Fisioterapeuta" << endl;
        cout << "13. Remover Horário Livre de Fisioterapeuta" << endl;
        cout << "14. Listar Horários Livres de Fisioterapeuta" << endl;
        cout << "15. Sair" << endl;
        cout << "Escolha uma opção: ";
        opcao = lerOpcao();

        switch (opcao) {
            case 1: cadastrarPaciente(); break;
            case 2: cadastrarFisioterapeuta(); break;
            case 3: pesquisarPaciente(); break;
            case 4: pesquisarFisioterapeuta(); break;
            case 5: mostrarPacientesPorHorario(); break;
            case 6: atualizarDadosPessoa(); break;
            case 7: atualizarDadosPaciente(); break;
            case 8: atualizarDadosFisioterapeuta(); break;
            case 9: mudarHorarioPaciente(); break;
            case 10: removerPaciente(); break;
            case 11: removerFisioterapeuta(); break;
            case 12: adicionarHorarioLivre(); break;
            case 13: removerHorarioLivre(); break;
            case 14: listarHorariosLivres(); break;
            case 15: cout << "Saindo..." << endl; break;
            default: cout << "Opção inválida!"; break;
        }

        if (opcao != 15) {
            cout << "Pressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcao != 15);
}

void Menu::cadastrarPaciente() {
    string nome, cpf, telefone, responsavel, tipoPacote;
    int hora, minuto, idade;
    bool pagamento;
    
    cout << "=== Cadastrar Paciente ===" << endl;
    cout << "Nome: "; cin >> nome;
    cout << "CPF: "; cin >> cpf;
    cout << "Telefone: "; cin >> telefone;
    cout << "Idade: "; cin >> idade;
    cout << "Responsável: "; cin >> responsavel;
    cout << "Tipo de Pacote: "; cin >> tipoPacote;
    cout << "Pagamento (1 para pago, 0 para não): "; cin >> pagamento;
    cout << "Hora: "; cin >> hora;
    cout << "Minuto: "; cin >> minuto;

    Paciente* paciente = new Paciente(nome, hora, minuto, cpf, idade, telefone, pagamento, responsavel, tipoPacote);
    Gerenciador.cadastrarpaciente(paciente);

    cout << "Paciente cadastrado com sucesso!" << endl;
}

void Menu::cadastrarFisioterapeuta() {
    string nome, cpf, telefone, drf;
    int hora, minuto, idade;

    cout << "=== Cadastrar Fisioterapeuta ===" << endl;
    cout << "Nome: "; cin >> nome;
    cout << "CPF: "; cin >> cpf;
    cout << "Telefone: "; cin >> telefone;
    cout << "Idade: "; cin >> idade;
    cout << "DRF: "; cin >> drf;
    cout << "Hora: "; cin >> hora;
    cout << "Minuto: "; cin >> minuto;

    Fisioterapeuta* fisioterapeuta = new Fisioterapeuta(nome, hora, minuto, cpf, idade, telefone, drf);
    Gerenciador.cadastrarfisioterapeuta(fisioterapeuta);

    cout << "Fisioterapeuta cadastrado com sucesso!" << endl;
}

void Menu::pesquisarPaciente() {
    string nome;
    cout << "=== Pesquisar Paciente ===" << endl;
    cout << "Nome: "; cin >> nome;
    Gerenciador.pesquisarPacientePorNome(nome);
}

void Menu::pesquisarFisioterapeuta() {
    string nome;
    cout << "=== Pesquisar Fisioterapeuta ===" << endl;
    cout << "Nome: "; cin >> nome;
    Gerenciador.pesquisarFisioPorNome(nome);
}

void Menu::mostrarPacientesPorHorario(){
    cout << "=== Mostrar Pacientes por Horário ===" << endl;
    Gerenciador.mostrarPacientesPorHorario();
}

void Menu::atualizarDadosPessoa() {
    string cpf, novoNome, novoTelefone;
    int novaHora, novoMinuto, novaIdade;

    cout << "=== Atualizar Dados de Pessoa ===" << endl;
    cout << "CPF: "; cin >> cpf;
    cout << "Novo Nome: "; cin >> novoNome;
    cout << "Nova Hora: "; cin >> novaHora;
    cout << "Novo Minuto: "; cin >> novoMinuto;
    cout << "Nova Idade: "; cin >> novaIdade;
    cout << "Novo Telefone: "; cin >> novoTelefone;

    Gerenciador.atualizarPessoa(cpf, novoNome, novaHora, novoMinuto, novaIdade, novoTelefone);
}

void Menu::atualizarDadosPaciente() {
    string cpf, novoResponsavel, novoTipoPacote;
    bool novoPagamento;

    cout << "=== Atualizar Dados de Paciente ===" << endl;
    cout << "CPF: "; cin >> cpf;
    cout << "Novo Responsável: "; cin >> novoResponsavel;
    cout << "Novo Tipo de Pacote: "; cin >> novoTipoPacote;
    cout << "Novo Pagamento (1 para pago, 0 para não): "; cin >> novoPagamento;

    Gerenciador.atualizarPaciente(cpf, novoResponsavel, novoTipoPacote, novoPagamento);
}

void Menu::atualizarDadosFisioterapeuta() {
    string cpf, novoDRF;

    cout << "=== Atualizar Dados de Fisioterapeuta ===" << endl;
    cout << "CPF: "; cin >> cpf;
    cout << "Novo DRF: "; cin >> novoDRF;

    Gerenciador.atualizarFisioterapeuta(cpf, novoDRF);
}

void Menu::mudarHorarioPaciente() {
    string cpf;
    int novaHora, novoMinuto;

    cout << "=== Mudar Horário de Paciente ===" << endl;
    cout << "CPF: "; cin >> cpf;
    cout << "Nova Hora: "; cin >> novaHora;
    cout << "Novo Minuto: "; cin >> novoMinuto;

    Gerenciador.mudarHorarioPaciente(cpf, novaHora, novoMinuto);
}

void Menu::removerPaciente() {
    string cpf;
    cout << "=== Remover Paciente ===" << endl;
    cout << "CPF: "; cin >> cpf;

    Gerenciador.removerPaciente(cpf);
    cout << "Paciente removido com sucesso!" << endl;
}

void Menu::removerFisioterapeuta() {
    string cpf;
    cout << "=== Remover Fisioterapeuta ===" << endl;
    cout << "CPF: "; cin >> cpf;

    Gerenciador.removerFisioterapeuta(cpf);
    cout << "Fisioterapeuta removido com sucesso!" << endl;
}

void Menu::adicionarHorarioLivre() {
    string cpf;
    int hora, minuto;

    cout << "=== Adicionar Horário Livre ===" << endl;
    cout << "CPF do Fisioterapeuta: "; cin >> cpf;
    cout << "Hora: "; cin >> hora;
    cout << "Minuto: "; cin >> minuto;

    Gerenciador.adicionarHorarioLivre(cpf, hora, minuto);
}

void Menu::removerHorarioLivre() {
    string cpf;
    int hora, minuto;

    cout << "=== Remover Horário Livre ===" << endl;
    cout << "CPF do Fisioterapeuta: "; cin >> cpf;
    cout << "Hora: "; cin >> hora;
    cout << "Minuto: "; cin >> minuto;

    Gerenciador.removerHorarioLivre(cpf, hora, minuto);
}

void Menu::listarHorariosLivres() {
    string cpf;
    cout << "=== Listar Horários Livres ===" << endl;
    Gerenciador.listarHorariosLivres(cpf);
}
