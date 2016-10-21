#ifndef ELEMENT_H
#define ELEMENT_H

#include <QList>
#include <UVF-GA/geneticalgorithm/genotype.h>

class Chromosome{
public:
    Chromosome(int genQty);

    Genotype getFitness();
    Genotype getGen(int i);
    void setGen(Genotype& gen, int position);
    double evaluate();
    int getGenQty();

private:
    int _genQty;
    QList<Genotype> _gen;
    double _fitness;
};

#endif // ELEMENT_H