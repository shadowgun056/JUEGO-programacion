#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include <time.h>
#define TAM 60


#define UP w     //salto vertical
#define DOWN s
#define RIGHT d
#define LEFT a
#define FJUMP e   //salto adelante
#define BJUMP q   //salto atras

   // ---------VERSION  2-----------------

void gotoxy(short x, short y)
{
   COORD pos = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(WORD col)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
}
//PISO , TUBERIAS Y OBSTACULOS--------------------------
int tuberia_o_guion_al_azar ()
{
 int numeroRandom;
 numeroRandom=rand()%10;
 return numeroRandom;
}

// Llenar el vector  con un número
void azar_vector_T(char lista[TAM])
{
       int pos=TAM;int aux;
  // Llenar valores
        aux=tuberia_o_guion_al_azar();
        if(aux==1 &&
           lista[pos-1]=='_' &&
            lista[pos-2]=='_'  &&
             lista[pos-3]=='_'  &&
              lista[pos-4]=='_'  && lista[pos-5]=='_'  &&
               lista[pos-6]=='_'  && lista[pos-7]=='_' &&
                lista[pos-8]=='_' && lista[pos-9]=='_' &&
                lista[pos-10]=='_' && lista[pos-11]=='_' &&
                 lista[pos-12]=='_' && lista[pos-13]=='_')
          {
           lista[pos-1]='T';
          }
        else
           {

            lista[pos-1]='_';
           }

}

void llenar_vector_de_lineas(char lista[TAM])  //para generar el piso entero
{
       int pos;
  // Llenar valores
    for(pos=0; pos<TAM; pos++)   //pos=2;pos<TAM;pos=pos-1
    {
        lista[pos]='_';
    }

}

void avanzar (char lista[TAM])
{
    int cont;
    for (cont=0;cont<TAM-1;cont=cont+1)
    {
        lista[cont]=lista[cont+1];
    }
}
void avanzar_salto (char lista[TAM])
{
   avanzar(lista);
   avanzar(lista);
   avanzar(lista);
}
// Mostrar el vector  (también se puede sin el tamaño)
void mostrar(char lista[TAM])
{
    int pos;
  // Mostrar valores
    gotoxy(5,20);
    for(pos=0; pos<TAM; pos++)
    {
         printf("%c",lista[pos]);
    }
}


//---------PISOOOO------------

void piso(char tecla)
{
    char la_lista[TAM];
    int pos=0;

        gotoxy(20,20);
            mostrar(la_lista);
            avanzar(la_lista);
            azar_vector_T(la_lista);
            Sleep(300);
            pos=pos+1;
}

//-------PERSONAJE Y OBJETOS------
void personaje()
{
    char cabeza,cuerpo;

        color(5);
        cabeza='o';
        cuerpo='O';
        gotoxy(10,19);
        printf("%c",cabeza);
        gotoxy(10,20);
printf("%c",cuerpo);
}

char paisaje(char fondo)
{


        fondo='=';
        printf("%c",fondo);
        return fondo;
}

//----------------------------JUEGO      PRINCIPAL  -----------------------------------

void juego()
{
    int cont_x=1;
    char tecla,fondo;
int pos=0;//para el avanzar
char la_lista[TAM];
llenar_vector_de_lineas(la_lista);
    while (tecla!='p')
    {
        fflush(stdin);
        tecla=getch();
        personaje();

        switch (tecla)
        {
           case 'd':                        //PARA MOVER EL FONDO A LA IZQUIERDA  CUANDO EL PERSONAJE AVANZA
            gotoxy(20,20);
                        if (la_lista[6]!='T')
            {
            mostrar(la_lista);
            personaje();


            avanzar(la_lista);
            azar_vector_T(la_lista);
                        //mostrar(la_lista);
                        personaje();
            Sleep(200);
            pos=pos+1;
            }

           // cont_x=cont_x-1;
            break;

            case 'w':  //saltp vertical

                break;

            case 'e':   //salto adelante

            gotoxy(20,20);
            mostrar(la_lista);
            personaje();
            //if (la_lista[8]!='T')
            //{

  avanzar_salto  (la_lista);
            azar_vector_T(la_lista);
                        //mostrar(la_lista);

                        personaje();
            Sleep(200);
            pos=pos+1;
           // }
                break;

        }
    }
}
int main()
{
    //piso();
    //poner la contrasenha
     juego();
}
