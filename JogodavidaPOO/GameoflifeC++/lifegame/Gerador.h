#ifndef CRIATURASRANDOMINICIO_H
#define CRIATURASRANDOMINICIO_H
#include "randperson.h"
#include <vector>
#include "id.h"
#include "gostos.h"
#include <nomestxt.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {policial = 1, ladrao = 2, amiga = 3, amigo = 4, crianca = 5};
class gerador
{ private:




public:
    gerador(){
    }

    randperson gerarNpc(int id, int escolha){
        if(escolha == policial){
        randperson *Policial = new randperson(id, Nomestxt::Nomes(Mulher));
        if(Policial->getGenero() == Homem)
            Policial->setnome(Nomestxt::Nomes(Homem));
        int idade = Policial->getIdade();
        Policial->setIdade(idade + 15);
        return *Policial;
    }

        else if(escolha == ladrao) {
        randperson *Ladrao = new randperson(id, Nomestxt::Nomes(Mulher));
        int idade = Ladrao->getIdade();
        Ladrao->setIdade(idade + 5);
        if(Ladrao->getGenero() == 1)
            Ladrao->setnome(Nomestxt::Nomes(Homem));
        return *Ladrao;
    }


        else if(escolha == amiga){
        randperson *Amiga = new randperson(id, Nomestxt::Nomes(Mulher));
        int idade = Amiga->getIdade();
        Amiga->setIdade(idade + 5);
        Amiga->setGenero(Mulher);
        return *Amiga;
    }

    else if(escolha == amigo){
        randperson *Amigo = new randperson(id, Nomestxt::Nomes(Homem));
        int idade = Amigo->getIdade();
        Amigo->setIdade(idade + 5);
        Amigo->setGenero(Homem);
        return *Amigo;
    }

    else if(escolha == crianca){

        randperson *Crianca = new randperson(id, Nomestxt::Nomes(rand() % 2 + 1));
        Crianca->setIdade(rand()% 15);
        if(Crianca->getGenero() == Homem)
            Crianca->setnome(Nomestxt::Nomes(Homem));
        return *Crianca;
     }
        randperson *retornodefault = new randperson(id, Nomestxt::Nomes(Homem));
        return *retornodefault;
    }


};

#endif // CRIATURASRANDOMINICIO_H
