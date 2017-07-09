#include "nomestxt.h"

nomestxt::nomestxt(int genero)
{
  std::string nome1 , nome2 , nomecompleto;
  int cont = 1;
  std::string lelinha;
    if(genero == 1)
    {
      std::ifstream myfile;
      int line = rand()%200+1;
      myfile.open("../nomesfemininos.txt");
      if(myfile.is_open())
      {
        while(getline(myfile , lelinha))
        {
          if(cont == line)
          {
            nome1 = lelinha;
          }
          cont++;
        }
      }
    }

    if(genero == 2)
    {
      std::ifstream myfile;
      int line = rand()%200+1;
      myfile.open("../nomesmasculinos.txt");
      if(myfile.is_open())
      {
        while(getline(myfile , lelinha))
        {
          if(cont == line)
          {
            nome1 = lelinha;
          }
          cont++;
        }
      }
      myfile.close();
    }

    std::ifstream myfile;
    myfile.open("../sobrenomes.txt");
    int line = rand()%200+1;
    cont = 1;
    if(myfile.is_open())
    {
      while(getline(myfile , lelinha))
      {
        if(cont == line)
        {
          nome2 = lelinha;
        }
        cont++;
      }
    }
    myfile.close();

  std::cout << "nome 1: " << nome1 << "aqui tb??" << std::endl;
  std::cout << "nome 2: " << nome2 << std::endl;
  nomecompleto = nome1 + " " + nome2;
  std::cout << nome1 << std::endl;
  std::cout << "nome completo: " << nomecompleto << "<< isso era pra ser: 'nome completo: nomecompleto'" << std::endl;
  set_nome(nomecompleto);
}

void nomestxt::set_nome(std::string s_nome)
{
  nome = s_nome;
}
std::string nomestxt::get_nome()
{
  return nome;
}
