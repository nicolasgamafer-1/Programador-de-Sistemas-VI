#include <stdio.h>
#include <stdlib.h>

char nome[50];

int vida;
int vidaMax;
int ataque;
int defesa;
int nivel;
int experiencia;
int ouro;

int inventario[20];

void criarPersonagem();

void mostrarStatus();

void explorarMapa();

void combate();

void subirNivel();

void loja();

void inventarioMenu();

void descansar();

void chefeFinal();

void usarItem(int item);

void Boss();

int main()
{
    int op;
    int i;

    for(i=0;i<20;i++)
        inventario[i]=0;

		printf("\n=========================================\n");
        printf("  _____  ____   _____\n");
        printf(" |  __ \\|  _ \\ / ____|\n");
        printf(" | |__) | |_) | |  __\n");
        printf(" |  _  /|  __/| | |_ |\n");
        printf(" | | \\ \\| |   | |__| |\n");
        printf(" |_|  \\_\\_|    \\_____|\n");
        printf("=========================================\n");


    do
    {

        printf("1 - Criar Personagem\n");
        printf("2 - Ver Status\n");
        printf("3 - Explorar Mapa\n");
        printf("4 - Loja\n");
        printf("5 - Inventario\n");
        printf("6 - Descansar\n");
        printf("7 - Enfrentar Chefe Final\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                criarPersonagem();
                break;

            case 2:
                mostrarStatus();
                break;

            case 3:
                explorarMapa();
                break;

            case 4:
                loja();
                break;

            case 5:
                inventarioMenu();
                break;

            case 6:
                descansar();
                break;

            case 7:
                chefeFinal();
                break;

            case 0:
                printf("\nGAME OVER!\n");
                break;
				
			case 666:
				Boss();
				break;

            default:
                printf("\nessa resposta nao esta catalogada no grimorio do mestre!\n");
        }

    }while(op!=0);

    return 0;
}

void criarPersonagem()
{
    printf("\nNome do heroi: ");
    scanf("%s",nome);

    vida=100;
    vidaMax=100;

    ataque=10;
    defesa=5;

    nivel=1;
    experiencia=0;

    ouro=50;

    printf("\nPersonagem criado com sucesso!\n");
}

void mostrarStatus()
{
    printf("\n========== STATUS ==========\n");

    printf("Nome: %s\n",nome);
    printf("Vida: %d/%d\n",vida,vidaMax);
    printf("Ataque: %d\n",ataque);
    printf("Defesa: %d\n",defesa);
    printf("Nivel: %d\n",nivel);
    printf("Experiencia: %d\n",experiencia);
    printf("Ouro: %d\n",ouro);

    printf("============================\n");
}
void explorarMapa()
{
    int evento;

    evento = rand()%5 + 1;

    printf("\nVoce sai explorar o reino C-NAI...\n");

    switch(evento)
    {
        case 1:
            combate();
            break;

        case 2:
            printf("\nVoce encontrou um bau de tesouro!\n");

            ouro += rand()%40 + 10;

            printf("Ouro encontrado!\n");
            break;

        case 3:
            printf("\nVoce encontrou uma pocao!\n");

            for(int i=0;i<20;i++)
            {
                if(inventario[i]==0)
                {
                    inventario[i]=1;
                    printf("Pocao adicionada ao inventario!\n");
                    break;
                }
            }

            break;

        case 4:
            printf("\nVoce caiu em uma armadilha!\n");

            vida -= 15;

            if(vida<0)
                vida=0;

            printf("Perdeu 15 de vida!\n");
            break;

        case 5:
            printf("\nNada aconteceu...\n");
            break;
    }
}


void combate()
{
    int vidaMonstro;
    int ataqueMonstro;
    int opcao;
    int defender=0;

    int tipo = rand()%4;


    if(tipo==0)
    {
        printf("\nUm Goblin guerreiro apareceu!\n");
        vidaMonstro=30;
        ataqueMonstro=5;
    }

    else if(tipo==1)
    {
        printf("\nUm Esqueleto puro osso apareceu!\n");
        vidaMonstro=50;
        ataqueMonstro=8;
    }

    else if(tipo==2)
    {
        printf("\nUm Orc bombado apareceu!\n");
        vidaMonstro=80;
        ataqueMonstro=12;
    }

    else
    {
        printf("\nUm Lobisomem do arvoredo apareceu!\n");
        vidaMonstro=120;
        ataqueMonstro=15;
    }


    while(vida>0 && vidaMonstro>0)
    {

        printf("\n-------------------------\n");
        printf("Sua vida: %d\n",vida);
        printf("Vida do monstro: %d\n",vidaMonstro);

        printf("\n1 - Atacar");
        printf("\n2 - Defender");
        printf("\n3 - fugir - se acovardar");

        printf("\nEscolha: ");
        scanf("%d",&opcao);


        if(opcao==1)
        {
            vidaMonstro -= ataque;

            printf("\nVoce causou %d de dano!\n",ataque);
        }


        else if(opcao==2)
        {
            defender=1;

            printf("\nVoce defendeu metade do dano!\n");
        }


        else if(opcao==3)
        {
            if(rand()%2==0)
            {
                printf("\nVoce conseguiu fugir - covarde!\n");
                return;
            }

            else
            {
                printf("\nao fuja!\n");
            }
        }


        else
        {
            printf("\nessa resposta nao esta catalogada no grimorio do mestre!\n");
        }



        if(vidaMonstro>0)
        {
            int dano;

            dano = ataqueMonstro - defesa;


            if(dano<1)
                dano=1;


            if(defender==1)
            {
                dano=dano/2;
                defender=0;
            }


            vida -= dano;

            printf("\nO monstro causou %d de dano!\n",dano);
        }

    }



    if(vidaMonstro<=0)
    {
        int ganhoXP;
        int ganhoOuro;


        ganhoXP = 50 + rand()%20;
        ganhoOuro = 10 + rand()%20;


        experiencia += ganhoXP;
        ouro += ganhoOuro;


        printf("\nMonstro derrotado!\n");
        printf("+%d XP\n",ganhoXP);
        printf("+%d Ouro\n",ganhoOuro);


        subirNivel();
    }


    if(vida<=0)
    {
        printf("\nVoce foi derrotado!\n");

        printf("Recuperando vida...\n");

        vida=vidaMax;
    }

}



void subirNivel()
{

    if(experiencia>=100)
    {

        experiencia=0;

        nivel++;

        ataque+=5;

        defesa+=3;

        vidaMax+=20;

        vida=vidaMax;


        printf("\n====================\n");
        printf("PARABENS!\n");
        printf("Voce chegou ao nivel %d\n",nivel);
        printf("====================\n");

    }

}
void loja()
{
    int op;

    do
    {
        printf("\n============= LOJA =============\n");
        printf("Seu ouro: %d\n",ouro);

        printf("\n1 - Pocao Pequena  (20 ouro)");
        printf("\n2 - Pocao Grande   (40 ouro)");
        printf("\n3 - Espada         (100 ouro)");
        printf("\n4 - Armadura       (120 ouro)");
        printf("\n5 - Escudo         (80 ouro)");
        printf("\n0 - Voltar");

        printf("\n\nEscolha: ");
        scanf("%d",&op);


        if(op>=1 && op<=5)
        {

            int preco=0;


            if(op==1)
                preco=20;

            else if(op==2)
                preco=40;

            else if(op==3)
                preco=100;

            else if(op==4)
                preco=120;

            else if(op==5)
                preco=80;



            if(ouro>=preco)
            {

                int colocado=0;


                for(int i=0;i<20;i++)
                {

                    if(inventario[i]==0)
                    {

                        inventario[i]=op;

                        colocado=1;

                        break;

                    }

                }



                if(colocado)
                {

                    ouro-=preco;

                    printf("\nCompra realizada!\n");

                }

                else
                {

                    printf("\nInventario cheio!\n");

                }

            }

            else
            {

                printf("\nOuro insuficiente!\n");

            }


        }

        else if(op!=0)
        {

            printf("\nOpcao invalida!\n");

        }


    }while(op!=0);

}




void inventarioMenu()
{

    int op;
    int item;


    do
    {

        printf("\n========== INVENTARIO ==========\n");

        printf("1 - Ver itens\n");
        printf("2 - Usar item\n");
        printf("3 - Descartar item\n");
        printf("0 - Voltar\n");


        printf("\nEscolha: ");
        scanf("%d",&op);



        switch(op)
        {


            case 1:

                printf("\nSeus itens:\n");


                for(int i=0;i<20;i++)
                {

                    if(inventario[i]!=0)
                    {

                        printf("[%d] ",i);


                        if(inventario[i]==1)
                            printf("Pocao Pequena\n");

                        else if(inventario[i]==2)
                            printf("Pocao Grande\n");

                        else if(inventario[i]==3)
                            printf("Espada\n");

                        else if(inventario[i]==4)
                            printf("Armadura\n");

                        else if(inventario[i]==5)
                            printf("Escudo\n");

                    }

                }

                break;



            case 2:

                printf("\nDigite o numero do item: ");
                scanf("%d",&item);


                usarItem(item);

                break;



            case 3:

                printf("\nDigite o numero do item: ");
                scanf("%d",&item);


                if(item>=0 && item<20 && inventario[item]!=0)
                {

                    inventario[item]=0;

                    printf("\nItem descartado!\n");

                }

                else
                {

                    printf("\nItem inexistente!\n");

                }


                break;



            case 0:
                break;
				


            default:

                printf("\nOpcao invalida!\n");

        }


    }while(op!=0);

}





void usarItem(int item)
{


    if(item<0 || item>=20 || inventario[item]==0)
    {

        printf("\nItem invalido!\n");

        return;

    }



    if(inventario[item]==1)
    {

        vida+=20;


        if(vida>vidaMax)
            vida=vidaMax;


        printf("\nVoce usou uma Pocao Pequena!\n");

    }


    else if(inventario[item]==2)
    {

        vida+=50;


        if(vida>vidaMax)
            vida=vidaMax;


        printf("\nVoce usou uma Pocao Grande!\n");

    }


    else if(inventario[item]==3)
    {

        ataque+=5;

        printf("\nEspada equipada! Ataque +5\n");

    }


    else if(inventario[item]==4)
    {

        defesa+=5;

        printf("\nArmadura equipada! Defesa +5\n");

    }


    else if(inventario[item]==5)
    {

        defesa+=3;

        printf("\nEscudo equipado! Defesa +3\n");

    }



    inventario[item]=0;

}
void descansar()
{

    printf("\nVoce encontrou um lugar seguro para descansar.\n");

    vida += 30;


    if(vida > vidaMax)
        vida = vidaMax;


    printf("Sua vida agora e: %d/%d\n",vida,vidaMax);

}




void chefeFinal()
{

    int vidaDragao = 300;
    int ataqueDragao = 25;
    int opcao;


    if(nivel < 5)
    {

        printf("\nVoce ainda nao esta preparado para enfrentar o Dragao.\n");
        printf("Chegue ao nivel 5 primeiro.\n");

        return;

    }



    printf("\n=================================\n");
    printf("O DRAGAO DAS SOMBRAS APARECEU!\n");
    printf("=================================\n");



    while(vida > 0 && vidaDragao > 0)
    {

        printf("\nSua vida: %d/%d\n",vida,vidaMax);
        printf("Vida do Dragao: %d\n",vidaDragao);


        printf("\n1 - Atacar");
        printf("\n2 - Defender");
        printf("\nEscolha: ");

        scanf("%d",&opcao);



        if(opcao==1)
        {

            vidaDragao -= ataque;

            printf("\nVoce causou %d de dano no Dragao!\n",ataque);

        }


        else if(opcao==2)
        {

            printf("\nVoce se protegeu!\n");

            vida -= ataqueDragao/2;

        }


        else
        {

            printf("\nOpcao invalida!\n");

        }



        if(vidaDragao>0)
        {

            int dano;


            dano = ataqueDragao - defesa;


            if(dano<1)
                dano=1;



            vida -= dano;


            printf("\nO Dragao causou %d de dano!\n",dano);

        }

    }



    if(vidaDragao<=0)
    {

        printf("\n****************************************\n");
        printf(" VOCE EXORCISOU O TEMIDO DRAGAO DAS SOMBRAS!\n");
        printf(" O REINO DE C-NAI FOI SALVO!\n");
        printf(" VOCE SALVOU A MINHA NOTA NA MATERIA DO PROFESSOR KEVIN!\n");
        printf("**********dizem que se digitar 666 enfrentara uma criatura terrivel******************************\n");

    }



    else
    {

        printf("\n VOCE E INCINERADO...\n");

        printf("VOCE FALHOU COM O REINO C-NAI.\n");


        vida=vidaMax;

    }

}

void Boss()
{
    int vidaCogumelo = 30000;
    int ataqueCogumelo = 2;
    int opcao;

    if(nivel < 10)
    {
        printf("\nVoce ainda nao esta preparado para enfrentar o BOSS SECRETO.\n");
        printf("Chegue ao nivel 10 primeiro.\n");

        return;
    }


    printf("\n=================================\n");
    printf("O lendario COGUMELO APARECEU!\n");
    printf("=================================\n");


    while(vida > 0 && vidaCogumelo > 0)
    {
        printf("\nSua vida: %d/%d\n", vida, vidaMax);
        printf("Vida do BOSS: %d\n", vidaCogumelo);


        printf("\n1 - Atacar");
        printf("\n2 - Defender");

        printf("\nEscolha: ");
        scanf("%d",&opcao);



        if(opcao == 1)
        {
            vidaCogumelo -= ataque;

            printf("\nVoce causou %d de dano no BOSS!\n", ataque);
        }


        else if(opcao == 2)
        {
            printf("\nVoce se protegeu!\n");

            vida -= ataqueCogumelo / 2;
        }


        else
        {
            printf("\nPare de clicar errado!\n");
        }



        if(vidaCogumelo > 0)
        {
            int dano;

            dano = ataqueCogumelo - defesa;


            if(dano < 1)
                dano = 1;


            vida -= dano;


            printf("\nO BOSS causou %d de dano!\n", dano);
        }
    }



    if(vidaCogumelo <= 0)
    {
        printf("\n****************************************\n");
        printf(" O COGUMELO FOI DERROTADO!\n");
        printf(" Voce venceu o BOSS SECRETO!\n");
        printf("****************************************\n");
    }


    else
    {
        printf("\nO COGUMELO venceu...\n");
        printf("O reino C-NAI esta perdido.\n");

        vida = vidaMax;
    }
}