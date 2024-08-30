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

void gerenciador::atualizarPessoa(const string& cpf, const string& novoNome, int novaHora, int novoMinuto, int novaIdade, const string& novoTelefone) {
    for (auto& paciente : pacienteList) {
        if (paciente.getCPF() == cpf) {
            paciente.atualizarDados(novoNome, novaHora, novoMinuto, novaIdade, novoTelefone);
            return;
        }
    }
    
    for (auto& fisioterapeuta : fisioList) {
        if (fisioterapeuta.getCPF() == cpf) {
            fisioterapeuta.atualizarDados(novoNome, novaHora, novoMinuto, novaIdade, novoTelefone);
            return;
        }
    }
    
    cout << "Pessoa não encontrada" << endl;
}

void gerenciador::atualizarPaciente(const string& cpf, const string& novoResponsavel, const string& novoTipoPacote, bool novoPagamento) {
    for (auto& paciente : pacienteList) {
        if (paciente.getCPF() == cpf) {
            paciente.atualizarResponsavel(novoResponsavel);
            paciente.atualizarTipoPacote(novoTipoPacote);
            paciente.atualizarPagamento(novoPagamento);
            return;
        }
    }
    
    cout << "Paciente não encontrado" << endl;
}

void gerenciador::atualizarFisioterapeuta(const string& cpf, const string& novoDRF) {
    for (auto& fisioterapeuta : fisioList) {
        if (fisioterapeuta.getCPF() == cpf) {
            fisioterapeuta.atualizarDRF(novoDRF);
            return;
        }
    }
    
    cout << "Fisioterapeuta não encontrado" << endl;
}

void gerenciador::mudarHorarioPaciente(const string& cpf, int novaHora, int novoMinuto) {
    for (auto& paciente : pacienteList) {
        if (paciente.getCPF() == cpf) {
            paciente = Paciente(paciente.getNome(), novaHora, novoMinuto, cpf, paciente.getIdade(), paciente.getTelefone(), paciente.verificarpagamento(), paciente.getResponsavel(), paciente.getTipoPacote());
            return;
        }
    }
    cout << "Paciente não encontrado" << endl;
}

void gerenciador::removerPaciente(const string& cpf) {
    for (auto it = pacienteList.begin(); it != pacienteList.end(); ++it) {
        if (it->getCPF() == cpf) {
            pacienteList.erase(it);
            return;
        }
    }
    cout << "Paciente não encontrado" << endl;
}

void gerenciador::removerFisioterapeuta(const string& cpf) {
    for (auto it = fisioList.begin(); it != fisioList.end(); ++it) {
        if (it->getCPF() == cpf) {
            fisioList.erase(it);
            return;
        }
    }
    cout << "Fisioterapeuta não encontrado" << endl;
}

void gerenciador::adicionarHorarioLivre(const string& cpf, int hora, int minuto) {
    for (auto& fisioterapeuta : fisioList) {
        if (fisioterapeuta.getCPF() == cpf) {
            fisioterapeuta.adicionarHorarioLivre(hora, minuto);
            return;
        }
    }
    cout << "Fisioterapeuta não encontrado" << endl;
}

void gerenciador::removerHorarioLivre(const string& cpf, int hora, int minuto) {
    for (auto& fisioterapeuta : fisioList) {
        if (fisioterapeuta.getCPF() == cpf) {
            fisioterapeuta.removerHorarioLivre(hora, minuto);
            return;
        }
    }
    cout << "Fisioterapeuta não encontrado" << endl;
}

void gerenciador::listarHorariosLivres(const string& cpf) const {
    for (const auto& fisioterapeuta : fisioList) {
        if (fisioterapeuta.getCPF() == cpf) {
            auto horarios = fisioterapeuta.getHorariosLivres();
            cout << "Horários livres para " << fisioterapeuta.getNome() << ":" << endl;
            for (const auto& horario : horarios) {
                cout << horario.first << ":" << (horario.second < 10 ? "0" : "") << horario.second << endl;
            }
            return;
        }
    }
    cout << "Fisioterapeuta não encontrado" << endl;
}

