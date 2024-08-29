#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>

using namespace std;

class Pessoa {
public:
    Pessoa(const string& nome, int hora, int minuto,const string& cpf, int idade, const string& telefone);
    virtual ~Pessoa() {} 
    virtual void cadastrar() const = 0; 
    string getNome() const;
    int getHora() const;
    int getMinuto() const;
    string getCPF() const;
    int getIdade() const;
    string getTelefone() const;

protected:
    string nome;
    int hora;
    int minuto;
    string cpf;
    int idade;
    string telefone;
    vector<Pessoa> pessoas;
};

#endif