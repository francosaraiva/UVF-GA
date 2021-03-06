#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <UVF-GA/geneticalgorithm/population.h>
#include <time.h>
#include <QList>
#include <QThread>

#include <UVF-GA/simulation/entity/player/player.h>

#include <3rdparty/sslworld/sslworld.h>

#pragma GCC diagnostic ignored "-Wunused-parameter"

#define POPSIZE 10

int main(int argc, char *argv[]){
    int iteration = 0;

    Population *P = new Population(POPSIZE);
    QList<Population> popList;
    srand(time(NULL));

    while(iteration < 2){
        cout << ">>> ITERATION " << iteration << " <<<" << endl;
        cout << "Inital population of Iteration" << endl;
        P->print();
        Population crossPop = P->crossOver();
        Population mutPop = P->mutation(0.5);
        popList.clear();
        popList.append(crossPop);
        popList.append(mutPop);
        popList.append(*P);
        P = P->selection(popList);
        iteration++;
        cout << "\n\n\n\n";
    }

//    seleciona(inicial) => selecionados (x elementos)

//    crossover(selecionados) => pop_atual1

//    mutação(pop_atual1)   => pop_atual2

//    evaluation()

//    seleciona(selecionados, pop_atual2) (x elementos)





//    // SSL World testing
//    RobotsFomation *form = new RobotsFomation(2);
//    FieldConfig *cfg = new FieldConfig();
//    SSLWorld *ssl = new SSLWorld(cfg, form, form);

//    Player *player = new Player(0, ssl);

//    ssl->robots[0]->setXY(0, 0);
//    ssl->robots[0]->setDir(0.0);

//    // Remove all other robots from field
//    for(int i=1; i<2*ROBOT_COUNT; i++)
//        ssl->robots[i]->setXY(0.3*i, -10);

//    forever {
//        player->goToLookTo(Position(-1.0, 0.0), 0, false);

//        float ori = player->orientation();

//        dReal x, y;
//        ssl->robots[0]->getXY(x, y);
//        std::cout << "Robot #0: X=" << x << ", Y=" << y << ", Ori=" << ori << "\n";

//        ssl->step(0.0050);
//        QThread::msleep(10);
//    }

//    delete ssl;
//    delete cfg;
//    delete form;


    return 0;
}
