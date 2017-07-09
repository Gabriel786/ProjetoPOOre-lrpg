#ifndef GAMEBEGIN_H
#define GAMEBEGIN_H
#include <iostream>
#include "personagem.h"
#include "personagens.h"

//enum{Homem = 1, Mulher = 2, Outro = 3};
enum{Hetero = 1, Bissexual = 2, Homossexual = 3, assexuado = 4};
class Eventos
{
public:
    Eventos(){

    }

    static void gameintro(){
        std::cout<< "Bem vindo ao projeto Re:L, um rpg que simula a vida real,"<<
                    " neste jogo não ha decisoes certas ou erradas, as respostas que o jogo"<<
                    " te da são sempre aleatorias,sintasse livre para"<<
                    " jogar da maneira que voce bem entender." << std::endl;
    }

    static Personagem Inicio(int id){
        char nome[30];
        char opsex;
        char genero;
        int nopsex, ngenero;
        int idade = 8;
        std::cout << "Insira o nome do personagem!" << std::endl;
        std::cin.getline(nome, 30);
        std::cout << "Insira h se você for homem, ou m se voce for mulher:" << std::endl;
        std::cin >> genero;
        if(genero == 'h') ngenero = Homem;
        else if(genero == 'm') ngenero = Mulher;
        else
            std::cerr <<"algo errado nao esta certo em genero" << std::endl;

        std::cout << "Insira h se você for hetero, ou b se voce for bissexual, ou o se voce for homossexual:" << std::endl;
        std::cin >> opsex;
        if(opsex == 'h') nopsex = Hetero;
        else if(opsex == 'b') nopsex = Bissexual;
        else if(opsex == 'o') nopsex = Homossexual;
        else
            std::cerr <<"algo errado nao esta certo em opsexual" << std::endl;

        Personagem *Principal = new Personagem(id, nome, ngenero, nopsex, idade);

        return *Principal;
    }



    void status(Personagem Principal){
        std::string gen;
        std::cout<<"Nome"<< Principal.getNome();
        if(Principal.getGenero() == 1)
            gen = "Masculino";
        else
            std::cout<<"Genero:"<< gen <<std::endl;
        std::cout<< "PV:"<<Principal.getPV();

    }





    static Personagem eventosaleatorios(Personagem &Principal, Personagem &Ladrao, Personagem &Policial, Personagem &amiga){
        int a =rand()%20;
        std::string aux;
        int auxiliar;
        std::cout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
        if (a < 2){
            if(Principal.getSick() == 0){
                std::cout<<Principal.getNome()<<" estava com bastante frio, apesar do seu corpo estar muito quente, voce está doente"<< std::endl;
                Principal.Issick(1);
            }
        }
        else if (a < 5){//encontrar amiga.
            std::cout<<Principal.getNome()<<" estava de bobeira, e encontrou "<< amiga.getNome()<<std::endl;
            //int passeio = rand() % 6;
            //                    if(passeio == 0 && Principal.getDinheiro() > 20){
            //                         std::cout<<Principal.getNome()<< " e " <<amiga.getNome << "resolveram fazer compras"<<std::endl;
            //                    }

        }
        else if(a < 6){
            auxiliar = rand() % 800;
            std::cout<<Principal.getNome()<<" encontrou" << auxiliar<< "reais"<< std::endl;
            Principal.updateMoney(auxiliar);
        }
        else if(a < 7){
            std::cout<<"Um triste acidente aconteceu e " << Principal.getNome() << "ficou parcialmente cego"<<std::endl;
            Principal.Isblind(1);

        }
        else if(a < 10){
            std::cout<< Principal.getNome() << " recebeu dinheiro de uma pessoa inesperada" <<std::endl;
            auxiliar = rand() % 100 *(Principal.getIdade() %10);
            Principal.updateMoney(auxiliar);
            std::cout<< "-- "<< auxiliar<< " reais adicionado ao seu inventario"<< "--" << std::endl;
        }
        else if(a < 11){
            std::cout<<"Voce foi abordado por um bandido"<<std::endl;
            int R = rand() % 12;
            if((Principal.getDinheiro() > 0) && R < 10)std::cout<<", algo triste aconteceu, um ladrão roubou todo seu dinheiro."<<std::endl;
            Principal.setMoney(0);
            if(R == 10){
                std::cout<<"porém voce se assutou muito, comecou a gritar, ele ficou irritado e ";
                int bandido = rand() % 5;
                if(bandido < 3){
                    std::cout << "te baleou, e agora voce esta ferido"<< std::endl;
                    Principal.Isinjured(1);
                    if(bandido < 2 && Principal.getDinheiro() > 0){
                        std::cout <<"ele também levou parte do seu dinheiro" << std::endl;
                        float dinheiroPerdido = Principal.getDinheiro() * ( 1  /  (rand() % 4 + 1));
                        std::cout<< "ele levou"<<dinheiroPerdido << " reais"<< std::endl;
                        Principal.updateMoney(-dinheiroPerdido);

                    }

                }
                if(bandido >=3) std::cout<<"te deixou ir embora"<<std::endl;
            }
            if(R == 12)std::cout<<"O(a) policial"<< Policial.getNome()<< " pegou o bandito que etava com a arma apontada para voce, antes que algo grave acontecese"<<std::endl
                               << "O(a), Criminoso(a)"<< Ladrao.getNome()<< " foi preso";

        }
        else if(a ==11){
            if(Principal.getPoisoned() == 0){
                std::cout<<"Voce foi picado por uma cobra e agora esta envenenado"<<std::endl;
                Principal.Ispoisoned(1);
            }
            else{
                std::cout<< "Voce estava brincando, se machucou e perdeu 15 de vida."<< std::endl;
                Principal.updatePV(-15);
            }
        }
        //else if(){}

        else{
            std::cout<< "Parece que nada aconteceu hoje"<<std::endl;
        }





        return Principal;
    }

};

#endif // GAMEBEGIN_H
