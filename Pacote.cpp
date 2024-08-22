#include "Pacote.h"

Pacote::Pacote(int quantidadeAulas, double valorPorAula)
    : quantidadeAulas(quantidadeAulas), valorPorAula(valorPorAula) {}

int Pacote::getQuantidadeAulas() const {
     return quantidadeAulas; 
     }

double Pacote::getValorPorAula() const {
     return valorPorAula; 
     }

double Pacote::calcularValorTotal() const {
     return quantidadeAulas * valorPorAula; 
     }
