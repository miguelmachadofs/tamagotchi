#include <iostream>
using namespace std;

int main() 
{
  string nome;
  int idade = 0, num, op; //idade em dias
  int fome, higiene, inteligencia, ativo, energia, felicidade, saude; //de 0 a 100
  char sexo;
  bool vivo = true;

  srand(time(0));

  cout << "Digite um nome para seu Tamagotchi: \n";
  cin >> nome;

  cout << "Deseja adotar um macho (digite 'm'), uma fêmea (digite 'f') ou que a escolha seja aleatória (digite 'a')? \n";
  cin >> sexo;

  switch(sexo)
  {
    case 'm':
    case 'M':
      sexo = 'M';
    break;
    case 'f':
    case 'F':
      sexo = 'F';
    break;
    case 'a':
    case 'A':
      num = rand() % 100 +1;
      if(num % 2 != 0)
        sexo = 'F';
      if(num % 2 == 0)
        sexo = 'M';
    break;
    default:
      cout << "Opção indisponível!\n";
    break;
  }

  fome = rand() % 50 + 50;
  higiene = rand() % 50 + 50;
  inteligencia = rand() % 50 + 50;
  ativo = rand() % 50 + 50;
  energia = rand() % 50 + 50;
  felicidade = rand() % 50 + 50;
  saude = rand() % 50 + 50;

  cout << "\nSeu tama está pronto, dê uma olhada!\n\n";
  cout << "Nome: " << nome << endl;
  cout << "Sexo: " << sexo << endl;
  cout << "Idade: " << idade << endl << endl;

  cout << "Fome: " << fome << endl;
  cout << "Higiene: " << higiene << endl;
  cout << "Inteligência: " << inteligencia << endl;
  cout << "Ativo: " << ativo << endl;
  cout << "Energia: " << energia << endl;
  cout << "Felicidade: " << felicidade << endl;
  cout << "Saúde: " << saude << endl << endl;

  cout << "Agora cuide de seu tama e interaja com ele!!\n\n";

  while(!(op == 8 || vivo == false))
  {
    cout << "1 - COMER\n";
    cout << "2 - PRATICAR ESPORTE\n";
    cout << "3 - LER\n";
    cout << "4 - JOGAR\n";
    cout << "5 - TOMAR BANHO\n";
    cout << "6 - TOMAR REMÉDIO\n";
    cout << "7 - DORMIR\n";
    cout << "8 - SAIR\n";

    cout << "\nO que seu tama deve fazer??\n";
    cin >> op;

    switch(op)
    {
      case 1:
        if((fome < 100 && saude > 50) || felicidade > 50)
        {
          fome += 30;
          felicidade += 5;
          saude += 10;
          higiene -= 10;
          energia += 20;
        }
        else if((fome == 100 && felicidade > 70) || felicidade < 30)
        {
          saude -= 10;
          felicidade += 10;
        }
        else
        {
          cout << "\nMe recuso a comer!\n";
        }
      break;
      case 2:
        if(energia > 40 && saude > 50)
        {
          fome -= 20;
          energia -=30;
          saude += 20;
          felicidade += 10;
          ativo += 10;
          higiene = 0;
        }
        else
        {
          cout << "\nNão quero me exercitar!!\n";
        }
      break;
      case 3:
        if(fome > 30 && energia > 30)
        {
          inteligencia += 10;
          energia -= 5;
        }
        else
        {
          cout << "\nLer agora? Ah não!!\n";
        }
      break;
      case 4:
        if(energia > 10 || felicidade > 50)
        {
          felicidade += 10;
          inteligencia += 5;
          higiene -= 5;
        }
        else
        {
          cout << "\nNão estou disposto a jogar...\n";
        }
      break;
      case 5:
        if(higiene < 30 && felicidade > 10)
        {
          higiene = 100;
          felicidade += 10;
          saude += 10;
        }
        else
        {
          cout << "\nBanho não, pô!!\n";
        }
      break;
      case 6:
        if(saude < 30)
        {
          saude += 10;
        }
        else
        {
          cout << "\nNão preciso de remédio!\n";
        }
      break;
      case 7:
        if((energia < 30 && saude > 50) || saude < 30)
        {
          if(saude > 50) //saudável
          {
            energia = 100;
          }
          else if(saude < 30) //doente
          {
            energia += 30;
            saude += 10;
          }
        }
        else
        {
          cout << "\nMe recuso a dormir!!\n";
        }
        idade++;
      break;
      case 8:
      break;
      default:
        cout << "\nOpção indisponível!!\n";
      break;
    }

    if(fome > 100)
      fome = 100;
    if(higiene > 100)
      higiene = 100;
    if(inteligencia > 100)
      inteligencia = 100;
    if(ativo > 100)
      ativo = 100;
    if(energia > 100)
      energia = 100;
    if(felicidade > 100)
      felicidade = 100;
    if(saude > 100)
      saude = 100;

    if(fome < 0)
      fome = 0;
    if(higiene < 0)
      higiene = 0;
    if(inteligencia < 0)
      inteligencia = 0;
    if(ativo < 0)
      ativo = 0;
    if(energia < 0)
      energia = 0;
    if(felicidade < 0)
      felicidade = 0;
    if(saude < 0)
      saude = 0;

    cout << "\nEstado atual do seu tama: \n\n";
    cout << "Fome: " << fome << endl;
    cout << "Higiene: " << higiene << endl;
    cout << "Inteligência: " << inteligencia << endl;
    cout << "Ativo: " << ativo << endl;
    cout << "Energia: " << energia << endl;
    cout << "Felicidade: " << felicidade << endl;
    cout << "Saúde: " << saude << endl << endl;

    if(saude == 0 || energia == 0 || ativo < 5 || fome < 5)
    {
      vivo = false;
      cout << "\nInfelizmente trago a notícia de que seu Tamagotchi acabou morrendo, meus sentimentos!!\n";
    }
  }

  return 0;
}