#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <windons.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


#define TAM 5
typedef struct{
  int aviões;
  int lugares;
  char nomes[20];
}sistema;

void nullfcn(){

}

void sleep2(int secs){
  if (signal(SIGALRM, nullfcn)){
    perror("error: reception signal");
    exit(-1);
  }
  alarm(secs);
  pause();
}

#define REV 30
typedef struct{
  int reservado;

} reserva;

void gotoxy (int x, int y){
  SetConsoleCursorPosintio(GetStdHadle(STD_OUTPUT_HADLE),(COORD){x - 1, y -1})
}

void passageiros(){
  char str1[10] = "Ivan";
  char str2[10] = "Daniel";
  char str3[10] = "Pedro";
  char str4[10] = "Fernanda";
  char str5[10] = "Pris";
  char str6[10] = "Marcos";
  char str7[10] = "Marcia";
  char str8[10] = "Maria";
  char str9[10] = "João";
  char str10[10] = "Edmilson";

  printf("\n1. %s", str1);
  printf("\n2. %s", str2);
  printf("\n3. %s", str3);
  printf("\n4. %s", str4);
  printf("\n5. %s", str5);
  printf("\n6. %s", str6);
  printf("\n7. %s", str7);
  printf("\n8. %s", str8);
  printf("\n9. %s", str9);
  printf("\n10. %s", str10);


  }

int desejo(){
  int opt;
    printf("\nTem certeza sobre esse lugar?\n");
    printf("\n1.Sim\n");
    printf("\n2.Não\n");
    scanf("%d", &opt);

    return opt;
}

int menu(){
  int opção;
    gotoxy(3,7);
    printf("\n\n***MENU DE RESERVAS***\n\n");
    printf("\n1. Cadastrar os números dos aviões\n");
    printf("\n2. Cadastra os números dos lugares disponíveis\n");
    printf("\n3. Reservar passagem\n");
    printf("\n4. Consultar por passageiro\n");
    printf("\n5. Consultar por avião\n");
    printf("\n0. Sair do programa\n");

    printf("\n\nEscolha uma das opções: ");
    scanf("%d", &opção);

    return opção;
}
void pausar(){
  printf("\n\nPressione qualquer tecla para continuar\n\n");

}

int main() {
  setlocale(LC_ALL," ");
  sistema sistema[TAM];
  reserva re[REV];
  int escolha;
  int opc, i;
  opc = menu();
  int aeronaves[5] = {2040, 3090, 6050, 2030, 8005};

while ( opc != 0){
  switch(opc){
    case 1:
      for (i = 0; i < 4; i++){
          printf("\nInforme o número dos aviões [%d]:\n", i);
          scanf("%d", &sistema[i].aviões);
          fflush(stdin);
        }
      printf("\n\nCadastrando...\n\n");
      sleep(2);
      printf("\n\nCadastro realizado com sucesso. \n\n");
      pausar();
      break;

    case 2:
      for(i = 0; i < 4; i++){
      printf("\nInforme os números dos lugares disponíveis [%d]:\n", i);
      scanf("%d", &sistema[i].lugares);
      fflush(stdin);
        }
      printf("\n\nCadastrando...\n\n");
      sleep(2);
      printf("\n\nCadastro realizado com sucesso. \n\n");
      pausar();
      break;

    case 3:
      printf("\nReserve agora\n");
      printf("\nLugares disponíveis:\n");
      for(i = 0; i < 4; i++){
        printf("%d\n", sistema[i].lugares);
      }
        printf("\nEscolha um dos lugares: \n");
        scanf("%d", &re[i].reservado);
        escolha = desejo();

        if (escolha == 1){
          printf("\n\n*****Parabéns, você escolheu um ótimo lugar para a sua viagem!*****\n\n");
        }else{
          printf("\nPor favor, refaça o processo!");
        }

        pausar();
        break;
    case 4:
      printf("\n\n****** Consultado nomes de passageiros... ******\n\n");
      sleep(3);
      passageiros();
      printf("\n\n_______________************______________\n\n");
      pausar();
      break;
    case 5:
        printf("\nConsultando os aviões: \n");
        sleep(3);
        for (i = 0; i <= 4; i++){
        printf("\nAviões [%d]: %d", i, aeronaves[i]);
        }
      break;

    default:
      printf("\nErro: Opção Inválida\n");
      pausar();
      break;
  }
  opc = menu();
}


  return 0;
}
