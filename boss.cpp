#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <clocale>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

// TODO Fazer uma forma do jogador ou jogadora escolher sua raça
// TODO Sendo que cada raça tem a possibilidade de  ter mais ou menos atributos que as outras

struct Personagem{
    std::string nome;

    unsigned int energia;
    unsigned int altura;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
};

float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

struct Personagem boasVindasDoJogo(){
    std::cout << "Boas vindas ao nosso mundo!\n";
    std::cout << "Um sentimento de obscuridade tomou conta de nossa terra, \n";
    std::cout << "o rei Demônio dominou as principais forças de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanças decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e não conseguimos nos defender\n";
    std::cout << "precisamos de alguém que nos lidere para a derrocada deste maldito!\n";
    std::cout << "Você é nossa escolha!! E... a propósito... qual é mesmo o seu nome?\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sir " << nome << "!\n";

    struct Personagem eu;

    eu.nome = nome;
    eu.energia = (geraAleatorio() * 90) + 10;
    eu.altura = geraAleatorio() * 300;
    eu.forcaFisica = geraAleatorio() * 100;
    eu.forcaMagica = geraAleatorio() * 50;
    eu.creditos = 26;

    return eu;
}
    struct InimigosGelidos{
        std::string nome;
        unsigned int dano;
        unsigned int vidaFofo;
        unsigned int danoFofo;
        unsigned int dinheiro;
        unsigned int vidaP;
    };

    struct InimigosGelidos faseFlorestaGelida(){

        struct InimigosGelidos g;
        g.danoFofo = (geraAleatorio() * 20) + 1000;
        g.dano = geraAleatorio() * 80;
        g.dinheiro = geraAleatorio() * 80;
        g.vidaFofo = (geraAleatorio() * 50) + 1000;
        g.vidaP = (geraAleatorio()*80) + 10;
        return g;
    };


void mostraStatusDoJogador(struct Personagem &p, struct InimigosGelidos &g){

    if(p.energia == 0){
        std::cout << "Você morreu!!!" << std::endl;
        return;
    }
    std::cout << "Você agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia << " de energia com uma força de intensidade " <<
                p.forcaFisica << " e um poder mágico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}
void faseFlorestaGelida(struct Personagem &p, struct InimigosGelidos &g)
{
    std::cout << "a vida do inimigo é: " << g.vidaP << " e o dano dele é de " << g.dano << std::endl;
    int opcao=0;
    std::cout << "Deseja atacar novamente? \n1 - sim\n2 - nao \n" << std::endl;
    std::cin >> opcao;
    do{
    std::cout << "Deseja atacar novamente? \n1 - sim\n2 - nao \n" << std::endl;
        std::cin >> opcao;
        switch(opcao){
            case 1:
                if(g.vidaP < p.forcaFisica){
                g.vidaP = 0;
                }else{
                    g.vidaP = g.vidaP - p.forcaFisica; 
                std::cout << g.vidaP << std::endl;
                }
                
                break;
            case 2:
                if(p.energia < g.dano){
                    p.energia = 0;
                }else{
                    p.energia = p.energia - g.dano;
                    std::cout << p.energia << std::endl;
                }
                break;
            default:
            std::cout << "ola" << std::endl;
            }
    }while(g.vidaP != 0 && p.energia !=0);
        if(g.vidaP == 0){
            std::cout << "O inimigo morreu, vamos continura nossa jornada" << std::endl;
            p.creditos = p.creditos + g.dinheiro;
            p.forcaFisica = p.forcaFisica + 50;
            mostraStatusDoJogador(p, g);
        }
        if(p.energia == 0){
            std::cout << "Voce morreu, sua jornada acabou" << std::endl;
        }
}
    
    int main(int argc, char** argv){
    setlocale(LC_ALL,"");
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();
    struct InimigosGelidos g = faseFlorestaGelida();

    std::cout << "Você recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j, g);
    faseFlorestaGelida(j, g);
}