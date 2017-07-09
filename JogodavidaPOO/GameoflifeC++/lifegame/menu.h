#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "personagem.h"


class Menu
{ private:



public:
    Menu(){

    }
    static void menu(Personagem &Principal){
        int Opc;
        static int pagamento;
        char aux;
        std::cout<<"###################"<< std::endl
                <<"Menu de personagem:"<<std::endl;

        if(Principal.getIdade() > 10)
            std::cout<<"0. Passear na rua"<<std::endl;
        std::cout<<"1. Ver seus status"<<std::endl;
        std::cout<<"2. Ir no hospital"<<std::endl;
        std::cout<<"3. Verificar dinheiro"<<std::endl;
        std::cout<<"4. Fazer algo que voce gosta"<<std::endl;
        if(Principal.getIdade() > 18){
            std::cout<<"5.Procurar emprego/trabalhar"<<std::endl;
            if(pagamento % 4 != 0) pagamento++;
        }
        std::cin >> Opc;


        switch (Opc) {
        case 1:
            Principal.UpdaterPrincipal();
            Principal.mostrarstatus();


            break;
        case 2:
            Principal.updateHumor(- (rand () %  5 ));
            std::cout<<"O preço de sua consulta é 100 reais"<< std::endl;
            if(Principal.getDinheiro() < 100)
                std::cout << Principal.getNome()<<" não tem dinheiro suficiente para esse tipo de tratamento"<< std::endl;
            else if(Principal.getPV() == 100){
                std::cout<<Principal.getNome() <<" não precisa desse tipo de tratamento(pf), essa consulta nao custou nada"<< std::endl;
            }
            else{
                if(Principal.getPV() < 100){
                    std::cout<<"Tem certeza que quer pagar"<< (100)<< "pelo tratamento(cura pv)?(y,n)";
                    std::cin>> aux;
                    if (aux == 'y'){
                        std::cout<< "O dinheiro foi descontato da sua conta e agora voce ficara curado" <<std::endl;

                        Principal.updateMoney(-100);
                        Principal.setPV(100);
                    }
                }
            }

            if(Principal.getBlind() == 1){
                std::cout<< "Percebemos também que voce tem problemas de visão, o tratamento custa 300 rais."<<std::endl;
                if(Principal.getDinheiro() < 300){
                    std::cout<<"Mas parece que voce não tem dinheiro para isso."<<std::endl;
                }

                else{
                    std::cout <<"Gostaria de pagar 300 reais para tratar sua visão?(y, n)"<<std::endl;
                    char choice;
                    std::cin >> choice;
                    if(choice == 'y'){
                        Principal.updateMoney(-300);
                        std::cout<< "O dinheiro foi descontato da sua conta e agora voce voltara a enchergar" <<std::endl;
                        Principal.Isblind(0);
                    }

                }
            }

            if(Principal.getDeaf() == 1){
                std::cout<< "Percebemos também que voce tem problemas auditivos, o tratamento custa 300 rais."<<std::endl;
                if(Principal.getDinheiro() < 300){
                    std::cout<<"Mas parece que voce não tem dinheiro para isso."<<std::endl;
                }

                else{
                    std::cout <<"Gostaria de pagar 300 reais para tratar sua audição?(y, n)"<<std::endl;
                    char choice;
                    std::cin >> choice;
                    if(choice == 'y'){
                        Principal.updateMoney(-300);
                        std::cout<< "O dinheiro foi descontato da sua conta e agora voce voltara a escutar normalmente" <<std::endl;
                        Principal.Isdeaf(0);
                    }

                }
            }
            if(Principal.getSick() == 1){
                std::cout<< "Percebemos também que voce esta doente, o tratamento custa 300 rais."<<std::endl;
                if(Principal.getDinheiro() < 300){
                    std::cout<<"Mas parece que voce não tem dinheiro para isso."<<std::endl;
                }

                else{
                    std::cout <<"Gostaria de pagar 300 reais para tratar sua doença?(y, n)"<<std::endl;
                    char choice;
                    std::cin >> choice;
                    if(choice == 'y'){
                        Principal.updateMoney(-300);
                        std::cout<< "O dinheiro foi descontato da sua conta e agora voce facara melhor de sua doença" <<std::endl;
                        Principal.Issick(0);
                    }

                }

            }
            if(Principal.getInjured() == 1){
                std::cout<< "Percebemos também que voce esta ferido, o tratamento custa 300 rais."<<std::endl;
                if(Principal.getDinheiro() < 300){
                    std::cout<<"Mas parece que voce não tem dinheiro para isso."<<std::endl;
                }

                else{
                    std::cout <<"Gostaria de pagar 300 reais para tratar seus ferimentos(y, n)"<<std::endl;
                    char choice;
                    std::cin >> choice;
                    if(choice == 'y'){
                        Principal.updateMoney(-300);
                        std::cout<< "O dinheiro foi descontato da sua conta e agora voce ficara bem novamente" <<std::endl;
                        Principal.Isinjured(0);
                    }

                }


            }


            break;

        case 3:
            std::cout<<"Dinheiro: "<< Principal.getDinheiro() << " Reais" << std::endl;
            break;
        case 4:
        {
            Principal.updateHumor(+5);
            std::cout<<Principal.getNome()<< " comecou a " <<Principal.getGosto()<< std::endl;
            int T = rand() % 6;
            if(T== 0)std::cout<< "E agora está muito cansado para fazer qualquer outra coisa." << std::endl;
            else if (T == 1){
                std::cout<<"Algumas pessoas que passavam perto achavam "<< Principal.getGosto()<< " algo ridiculo e alguns garotos de rua bateram em"<<
                            Principal.getNome()<<" por causa disso"<<std::endl<<Principal.getNome() << "---- Perdeu 20 de vida"<< std::endl;
                Principal.updatePV(-20);
            }
            else if (T == 2){

                std::cout<< "algumas pessoas gostaram muito de ver " <<Principal.getNome()<< " "<< Principal.getGosto()<< ". E voce recebeu dinheiro por isso"<<std::endl;
                int a = (rand() % 15  + 1)* Principal.getIdade();
                std::cout<< " ----  +" << a << "reais" << std::endl;
                Principal.updateMoney(a);
            }
            else{
                std::cout<<"Nada aconteceu diferente aconteceu..."<< std::endl;
            }
            break;
         }
        case 5:
            if(Principal.getIdade() < 18){
                std::cout<<Principal.getNome() <<" ainda não pode realizar esse tipo de ação"<< std::endl;
                break;
            }
            else if(Principal.getRenda() > 0){
                if(pagamento % 4 == 0){
                    std::cout<<Principal.getNome() << " acabou de receber" << Principal.getRenda() << "Reais";
                    Principal.updateMoney(Principal.getRenda());
                }
                else{
                    std::cout<<"voce so pode receber em " <<(pagamento % 4 )- 4<< " turnos.";
                }
            }
            else if(Principal.getRenda() == 0){
                char tentar;
                std::cout<<Principal.getNome() <<"Pode tentar arrumar um imprego, gostaria de tentar (y,n)?"<<std::endl;
                std::cin>>tentar;
                if (tentar == 'y'){
                    int chance = 98;
                    if(Principal.getIdade() > 60) chance-= 20;
                    if(Principal.getIdade() < 20) chance-= 10;
                    if(Principal.getBlind() == true) chance -= 5;
                    if(Principal.getHumor() < 50) chance -= 10;
                    if(Principal.getDeaf() == true) chance -= 5;
                    if(Principal.getSick() == true) chance -= 5;
                    int T = rand() % 100 + 1;


                    if(T <= chance){
                        pagamento = 1;
                        int salario = rand() %1000 +1000;
                        std::cout<<"Parabens, voce foi contratado, seu novo salario é de " << salario << std::endl;
                        Principal.setRenda(salario);
                    }
                    else{
                        std::cout<<" Parece que voce não conseguiu o trabalho"<<std::endl;
                    }

                }

            }





        }
    }

};
#endif // MENU_H
