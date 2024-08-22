#include "Paciente.h"
#include "Pessoa.h"
#include "Fisioterapeuta.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Paciente::Paciente(const string& nome, int hora, int minuto,const string& cpf, int idade, const string& telefone, bool pagamento, const string& responsavel)
: Pessoa (nome, hora, minuto, cpf, idade, telefone) {}


