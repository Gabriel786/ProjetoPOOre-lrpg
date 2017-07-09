#include <iostream>
#include "time.h"
#include <stdio.h>
#include <vector>
#include <fstream>
#include <map>
#include "personagem.h"
#include "id.h"
#include "gostos.h"
#include <locale.h>
#include "randperson.h"
#include "nomestxt.h"
#include "Eventos.h"
#include "Gerador.h"
#include "menu.h"



int main(){
    id ids;
    gostos gosto;
    gerador Npcs;
    //std::string nome = gerador.gerarNome(HOMEM);

    //        Eventos::eventosaleatorios(Principal, Ladrao, Policial, Amiga);
    std::map<int, Personagem> Personagens;
    srand(time(NULL));
    //std::cout<< Mulheres.nomeslista()<<std::endl;
    //randperson Policial(ids.getid(), Mulheres.nomeslista());
    //Policial.setGenero(Mulher);
    //std::cout << Policial.getNome()<<std::endl;
    //std::cout<<Policial.getIdade()<<std::endl;
    Eventos::gameintro();
    Personagem Principal = Eventos ::Inicio(ids.getid());
    Principal.setGosto(gosto.gostosiniciais());
    Personagem Ladrao= Npcs.gerarNpc(ids.getid(), ladrao);
    ids.updateid();
    Personagem Policial = Npcs.gerarNpc(ids.getid(), policial);
    ids.updateid();
    Personagem Amiga = Npcs.gerarNpc(ids.getid(), amiga);
    ids.updateid();
    Personagem Amigo = Npcs.gerarNpc(ids.getid(), amigo);
    ids.updateid();
    while (Principal.getMorto() == 0) {
//        for(int i =0; i < 4; i++){
            Eventos::eventosaleatorios(Principal, Ladrao, Policial, Amiga);
            Menu::menu(Principal);
            Principal.atualizador();
//        }


    }
    Personagens.insert(std::pair<int, Personagem>(ids.getid(), Principal));
    //Personagem Principal = Eventos ::Inicio(ids.getid());
    ids.updateid();
    return 0;
}


//for(auto it = lista.begin(); it < lista.end(); it++){
//        auto a = *it;
//        a.morrer;
//    }

