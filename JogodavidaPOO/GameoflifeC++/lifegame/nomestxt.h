#ifndef NOMESTXT_H
#define NOMESTXT_H
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

enum{Homem = 1, Mulher = 2};
class Nomestxt{
private:


public:

    Nomestxt(){

    }




    static std::string Nomes(int genero){

        static int numerodenomes;
        static std::string nome;
        static std::string sobrenome;
        static std::string nomecompleto;
        int value = 1;
        char a[100], b[100];
        FILE *f;
        FILE *f2;
        if(genero== Homem){
            numerodenomes = 1390;
            f = fopen("../nomesmasculinos.txt", "r");
        }
        else if(genero==Mulher){
            numerodenomes = 293;
            f = fopen("../nomesfemininos.txt", "r");
        }
        //srand (time(NULL));
        int nrand = rand()% numerodenomes;

        if (f == 0) {
            std::cerr<<"Erro: nao foi possivel abrir arquivo!"<<std::endl;
            return NULL;
        }
        while (fscanf(f, " %s\n",a) == 1){
            if(value == nrand){
                nome = a;
                break;
            }
            value ++;
        }
        value=1;
        //srand (time(NULL));
        numerodenomes = 461;
        nrand = rand()% numerodenomes;
        f2 = fopen("../sobrenomes.txt", "r");
        if (f2 == 0) {
            std::cerr<<"Erro: nao foi possivel abrir arquivo!"<<std::endl;
            //     return NULL;
        }
        nrand = rand() % numerodenomes;
        while (fscanf(f2, " %s\n",b) == 1){
            if(value == nrand){
                sobrenome = b;
                break;
            }
            value++;

        }
        fcloseall();

        nomecompleto = nome+ " " + sobrenome;
        return nomecompleto;
    }

};

#endif // NOMESTXT_H
