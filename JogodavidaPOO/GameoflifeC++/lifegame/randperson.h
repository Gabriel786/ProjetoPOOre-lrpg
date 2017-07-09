#ifndef RANDPERSON_H
#define RANDPERSON_H
#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include "personagem.h"

class randperson : public Personagem{
private:
//int id;
//std::string nome;
//int opsex;
//int idade;
//bool  Morto;
//int genero;
public:
    randperson(int id, std::string nome = ""):
    Personagem(id, nome, rand() % 2 + 1, rand() % 2 + 1, rand() % 40){
        gostos a;
        setGosto(a.sorteioGosto());

     }



};
#endif // RANDPERSON_H
