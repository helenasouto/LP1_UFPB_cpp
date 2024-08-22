#include <iostream>
#include "Horario.h"
#include "Pessoa.h"

using namespace std;

int main() {
    Horario horario;
    int opcao;
    do {
        cout << "1. Cadastrar Pessoa" << endl << "2. Mostrar por Horario" << endl << "3. Pesquisar por Nome" << endl << "4. Sair" << endl << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();
        if (opcao == 1) {
            string nome;
            int hora, minuto;
            cout << "Digite o nome da pessoa: ";
            getline(cin, nome);
            cout << "Digite o horario (hora minuto): ";
            cin >> hora >> minuto;
            cin.ignore();
            if (hora >= 0 && hora < 24 && minuto >= 0 && minuto < 60) {
                Pessoa pessoa(nome, hora, minuto);
                horario.cadastrarPessoa(pessoa);
            } else {
                cout << "Horario invalido" << endl;
            }
        } else if (opcao == 2) {
            horario.mostrarPessoasPorHorario();
        } else if (opcao == 3) {
            string nome;
            cout << "Digite o nome da pessoa: ";
            getline(cin, nome);
            horario.pesquisarPessoaPorNome(nome);
        }
    } while (opcao != 4);
}