#ifndef GOSTOS_H
#define GOSTOS_H
#include <vector>
#include <time.h>
#include <stdio.h>
class gostos
{
    int value1, value2, value3, tamanho;
    std::vector<std::string> gosto {
        "Ouvir rock",
        "Assistir anime",
        "Surfar",
        "Andar de patins",
        "Andar de bicicleta",
        "Andar de skate",
        "Costurar",
        "Cozinhar",
        "Fazer Yoga",
        "Dançar Funk",
        "Sambar",
        "Eletronica",
        "Filmes de terror",
        "Filmes de comédia",
        "Filmes românticos",
        "Ler",
        "Andar de patins",
        "Andar de bicicleta",
        "Andar de skate",
        "Costurar",
        "Meditação",
        "Jardinagem",
        "Escrever um blog",
        "Fazer vídeos",
        "Correr (ou caminhar)",
        "Dança",
        "Praticar um esporte",
        "Passear",
        "Fotografar",
        "Ir ao cinema",
        "Ir ao teatro",
        "Planejar festas",
        "Decoração",
        "Ler",
        "Degustar",
        "Fazer hidroginástica",
        "Birdwatching (observar pássaros)",
        "Fazer artesanato",
        "Ler histórias em quadrinhos",
        "Empinar pipa",
        "Fazer DIY’s",
        "Assistir séries ou filmes",
        "Fazer aulas de circo",
        "Customizar roupas",
        "Assistir ao pôr ou nascer do sol",
        "Pintar ou desenhar",
        "Jogar",
        "Acompanhar sua banda favorita",
        "Escrever um diário",
        "Cuidar de animais",
        "Treinar artes marciais",
        "Estudar",
        "Tocar um instrumento",
        "Montar quebra-cabeças",
        "Cantar",
        "Descobrir novas músicas e bandas",
        "Pescar",
        "Praticar um esporte radical",
        "Fazer trabalho voluntário",
        "Explorar novos lugares",
        "Estudar",
        "Participar de um grupo de teatro",
        "Ter uma coleção",
        "Bartending (preparar drinks)",
        "Pole dancing",
        "Programar",
    };
public:

    gostos()
    {
    }
    std::string sorteioGosto(){
        tamanho = gosto.size();
        value1= rand() % tamanho;
        return gosto[value1];
    }
    std::string gostosiniciais(){
        int choice;
        tamanho = gosto.size();
        std::cout << "Durante o seu crescimento voce teve contato com 3 diferentes coisas,"
                     "qual dessas coisas marcou mais voce durante sua infancia(1, 2, 3):" << std::endl;
        value1 = rand() % tamanho;
        value2 = rand() % tamanho;
        while (value2 == value1){
            value2 = rand() % tamanho;
        }
        value3 = rand() % tamanho;
        while ((value3 == value1) ||(value3 == value2)){
            value3 = rand() % tamanho;
        }
        std::cout <<"1." << gosto[value1] << std::endl<< "2." << gosto[value2]<< std::endl<< "3." << gosto[value3]<< std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            return gosto[value1];
            break;
        case 2:
            return gosto[value2];
            break;
        case 3:
            return gosto[value3];
            break;

        default:

            return gosto[rand() % tamanho];
            break;
        }


    }

};

#endif // GOSTOS_H
