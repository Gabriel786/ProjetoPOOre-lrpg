#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <vector>
#include <iostream>
#include "gostos.h"
class Personagem
{
protected:
    std::string nome;
    float idade;
    int id;
    int genero;
    int opsex;
    int renda = 0;
    int PV = 100;
    int Dinheiro =0;
    int humor = 100;
    std::string _gosto;
    std::vector<std::string> _gostos;
    bool Envenenado = false;
    bool verificadorEnvenenado = false;
    bool  Morto = false;
    bool verificadorMorto = false;
    bool  Ferido = false;
    bool verificadorFerido = false;
    bool Surdo = false;
    bool verificadorSurdo = false;
    bool Cego = false;
    bool verificadorCego= false;
    bool Doente= false;
    bool verificadorDoente= false;
    bool SaudeDeAco= false;
    bool verificadorSaudavel= false;
    std::vector<Personagem> amigos;

public:

    enum{Homem = 1, Mulher = 2, Outro = 3};

    Personagem(int id, std::string nome, int genero, int opsex, int idade){
        this->id = id;
        this->nome = nome;
        this->idade = idade;
        this->opsex = opsex;
        this->genero = genero;
        this->PV = 100;
        Morto = false;
    }
    ~Personagem(){
    }

    //    int idupdate(){
    //        id++;
    //        return id;
    //    }
    //    int getId(){
    //        return id;
    //    }


    virtual void UpdaterPrincipal(){

        if(Cego != verificadorCego && Cego == 1){
            std::cout <<"Parece que " << nome <<" não foi tão cuidadoso(a) com seus olhos, e agora esta cego(a)"<< std::endl;
            verificadorCego = 1;
        }
        if(Cego != verificadorCego && Cego == 0){
            std::cout <<"Algo surpreendente aconteceu, e "<< nome << " passou a enchergar novamente"<< std::endl;
            verificadorCego = 0;
        }
        if(Surdo != verificadorSurdo && Surdo == 1){
            std::cout <<"Parece que "<< nome <<" não foi tão cuidadoso com sua audição, e agora esta surdo(a)"
                     << std::endl;
            verificadorCego = 1;

        }
        if(Surdo != verificadorSurdo && Surdo == 0){
            std::cout <<"Algo surpreendente aconteceu, e "<< nome<< " passou a escutar novamente"<< std::endl;
            verificadorCego = 0;
        }
        if(Doente != verificadorDoente && Doente == 1){
            std::cout <<"Parece que "<< nome << " não foi tão cuidadoso(a) com sua saude, e agora esta doente"
                     << std::endl;
            verificadorDoente = 1;

        }
        if(Doente != verificadorDoente && Doente == 0){
            std::cout << nome << " antes estava doente, e agora esta saldavel"<< std::endl;
            verificadorDoente = 0;
        }
        if(Envenenado != verificadorEnvenenado && Envenenado == 1){
            std::cout <<"Parece que "<< nome << " não foi tão cuidadoso(a), e agora esta envenenado"
                     << std::endl;
            verificadorEnvenenado = 1;

        }
        if(Envenenado != verificadorEnvenenado && Envenenado == 0){
            std::cout << nome << " antes estava envenenado, e agora esta bem novamente."<< std::endl;
            verificadorEnvenenado = 0;
        }

        if(Ferido != verificadorFerido && Ferido == 1){
            std::cout <<"Parece que "<< nome << " não foi tão cuidadoso(a), e agora esta ferido."
                     << std::endl;
            verificadorFerido = 1;

        }
        if(Ferido != verificadorFerido && Ferido == 0){
            std::cout << nome << " antes estava envenenado, e agora esta bem novamente"<< std::endl;
            verificadorEnvenenado = 0;
        }





        if(SaudeDeAco!= verificadorSaudavel && SaudeDeAco == 1){
            std::cout <<"Parece que "<<nome << " faz algo que aumentou em grande escala a sua resistencia fisica, parabens"
                     << std::endl;
            verificadorSaudavel= 1;
        }
        if(SaudeDeAco != verificadorSaudavel && SaudeDeAco == 0){
            std::cout << nome <<" antes estava estremamente saldavel,"
                      << " e agora parece que seu corpo voltou ao normal, tome cuidado."<< std::endl;
            verificadorSaudavel = 0;
        }


    }





    void atualizador(){
        int NovoPV = 0;
        idade +=0.25;
        humor -= 2;
        if(idade > 90) NovoPV -=2;
        if(humor < 50) NovoPV -= 1;
        if(humor < 40) NovoPV -= 1;
        if(humor < 30) NovoPV -= 1;
        if (idade > 80) NovoPV -= 4;
        if(Cego == true) NovoPV += - 3;
        if(Doente == true) NovoPV += -4;
        if(SaudeDeAco == true) NovoPV += 2;
        if(Surdo == true) NovoPV += -2;
        if(Envenenado == true) NovoPV -= 5;
        if(Ferido == true) NovoPV -= 3;
        NovoPV += 3;
        if((NovoPV + PV) < 100) PV += NovoPV;
        if((NovoPV + PV)< 0) PV = 0;


    }







    void mostrarstatus(){
        if(((Morto != verificadorMorto) && verificadorMorto == false) || PV <= 0 ){
            Morto = true;
            std::cout <<"Sua vida acabou, voce viveu por " << idade<< "anos."<< std::endl;
            verificadorMorto = 1;

        }
        std::string Gener;
        std::cout<<"Nome:"<< nome <<std::endl;
        if(genero== 1) Gener = "Masculino";
        if(genero==2) Gener = "Feminino";
        std::cout<<"Genero:"<< Gener << std::endl;
        std::cout<<"Pv:"<< PV<< std::endl;
        std::cout<<"Humor:" << humor<< std::endl;
        std::cout<< "Idade:"<< idade << std::endl;
        if(humor < 51 && Morto == false){
            std::cout<<nome << "esta ficando triste, cuidado com isso"<<std::endl;
        }
        if(Cego == true && Morto == false)
            std::cout<< "Possui problemas para enchergar."<< std::endl;

        if(Doente == true && Morto == false)
            std::cout<<"Esta com alguma doenca."<<std::endl;

        if(SaudeDeAco == true && Morto == false)
            std::cout<<"Esta estremamente saudavel"<< std::endl;

        if(Surdo == true && Morto == false)
            std::cout<<"Possui problemas de audição"<<std::endl;
        if(Envenenado == true && Morto == false)
            std::cout<< "Esta envenenado"<< std::endl;
        if(Ferido == true && Morto == false)
            std::cout<<"Esta ferido" << std::endl;
    }


    virtual bool getBlind(){
        return Cego;
    }
    virtual bool getDeaf(){
        return Surdo;
    }
    virtual bool getSick(){
        return Doente;
    }
    virtual bool getInjured(){
        return Ferido;
    }
    virtual bool getPoisoned(){
        return Envenenado;
    }






    virtual void Isinjured(int value){
        if (value == 1)
            this->Ferido = true;
        if (value == 0)
           this-> Ferido = false;

    }
    virtual void Ispoisoned(int value){
        if (value == 1)
            this->Envenenado = true;
        if (value == 0)
            this->Envenenado = false;

    }
    virtual void Isdead(int value){
        if(value == 1)
            this->Morto = true;
    }
    virtual void Isblind(int value){
        if(value == 1)
            this->Cego = true;
        if(value == 0)
            this->Cego = false;
    }
    virtual void Isdeaf(int value){
        if(value == 1)
            this->Surdo = true;
        if(value == 0)
            this->Surdo = false;

    }
    virtual void Issick(int value){
        if(value == 1)
            Doente = true;
        if(value == 0){
            Doente = false;
        }

    }
    virtual void isSteelhealth(int value){
        if(value == 1)
            SaudeDeAco = true;
        if(value == 0)
            SaudeDeAco = false;
    }


    virtual int getGenero(){
        return genero;
    }
    virtual int getIdade(){
        return idade;

    }
    void setIdade(int idade){
        this->idade = idade;
    }

    void setGenero(int value){
        this->genero = value;
    }

    int getOpsex(){
        return opsex;
    }

    void setOpsex(int value){
        this->opsex = value;
    }

    std::string getNome(){
        return nome;
    }
    void setnome(std::string nome){
        this->nome = nome;
    }
    int getPV(){
        return PV;
    }
    void setPV(int value){
        this->PV =value;
    }
    void updatePV(int value){
        if(PV + value < 1)
            PV = 0;
        else if(PV + value > 99)
            PV = 100;
        else if (value + PV > 0 && value + PV <=100)
            PV += value;

}
    int getRenda(){
        return renda;
    }
    void setRenda(int value){
        this->renda = value;
    }
    void updateRenda(int value){
        this->renda += value;
    }



    bool getMorto(){
        return Morto;
    }

    void setGosto(std::string gosto){
        this->_gosto = gosto;
        _gostos.push_back(gosto);
    }
    void setMoney(int Dinheiro){
        this->Dinheiro = Dinheiro;
    }
    void updateMoney(int Dinheiro){

        this->Dinheiro += Dinheiro;
    }
    int getDinheiro(){
        return Dinheiro;
    }
    std::string getGosto(){
        return _gosto;
    }
    int getHumor(){
        return humor;
    }
    void updateHumor(int value){
        humor+= value;
    }

    //    std::string todososgostos(){
    //        std::string Gostos;
    //        for (_gostos.size())
    //    }
};

#endif // PERSONAGEM_H
