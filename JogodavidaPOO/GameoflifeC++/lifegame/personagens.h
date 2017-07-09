#ifndef PERSONAGENS_H
#define PERSONAGENS_H
#include <map>
#include "personagem.h"

class Personagens
{
private:
    static std::map<int, Personagem> _Personagens;


public:
    Personagens(std::map<int, Personagem> _Personagens)
    {
        this->_Personagens = _Personagens;
    }
    void AdicionarPersonagem(int identificador, Personagem novopersonagem){
        _Personagens.insert(std::pair<int, Personagem>(identificador, novopersonagem));
        }

};

#endif // PERSONAGENS_H
