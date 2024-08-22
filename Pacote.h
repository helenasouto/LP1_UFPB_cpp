#ifndef PACOTE_H
#define PACOTE_H

class Pacote {
public:
    Pacote(int quantidadeAulas, double valorPorAula);
    
    int getQuantidadeAulas() const;
    double getValorPorAula() const;
    double calcularValorTotal() const;

private:
    int quantidadeAulas;
    double valorPorAula;
};

#endif
