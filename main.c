#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

int main() {
  setlocale(LC_ALL, "pt_PT");
  srand(time(NULL));
  FILE *fp;
  char f_name[2056];
  int flag = 1;

  printf("Insira o nome do ficheiro: ");
  scanf("%s", &f_name);

  while(flag) {
    fp = fopen(f_name, "a+");
    int escolha, t_flag_s;
    printf("  ___   __  __ ______ _   _ _    _   ___ \n |  _| |  \\/  |  ____| \\ | | |  | | |_  |\n | |   | \\  / | |__  |  \\| | |  | |   | |\n | |   | |\\/| |  __| | . ` | |  | |   | |\n | |   | |  | | |____| |\\  | |__| |   | |\n | |_  |_|  |_|______|_| \\_|\\____/   _| |\n |___|                              |___|\n                                         \n(1) Inserir dados de um aluno\n(2) Pesquisar dados de um aluno\n(3) Eliminar dados de um aluno\n(4) Listar todos os dados\n(0) Sair\n\nEscolha: ");
    scanf("%d", &escolha);
    system("cls");

    switch(escolha) {
    case 1:
      char nome_aluno[2056], temp;
      int n_aluno, np_aluno;
      printf("[Inserir dados de um aluno]\n\n");
      printf("Insira o nome do aluno: ");
      scanf("%c", &temp); // Limpar o Buffer
      scanf("%[^\n]", nome_aluno);
      
      printf("Insira o número do aluno: ");
      scanf("%d", &n_aluno);

      np_aluno = rand() % 99999 + 10000;

      fprintf(fp, "%s (Nº%d) - Número de processo: %d\n", nome_aluno, n_aluno, np_aluno);
      printf("\n[Aluno inserido com sucesso!]\n[%s (Nº%d) - Número de processo: %d]\n\n", nome_aluno, n_aluno, np_aluno);
      break;
    case 2:
      char fen[2056], s2s[2056];
      t_flag_s = 1;
      printf("[Pesquisar dados de um aluno]\n\n");
      printf("Insira o número do aluno: ");
      scanf("%d", &n_aluno);
      sprintf(s2s, "(Nº%d)", n_aluno);
      do {
        if(strstr(fen, s2s) != NULL) {
          printf("[ %s ]\n", fen);
          t_flag_s = 0;
          break;
        }
      } while(fscanf(fp, "%[^\n]\n", fen) != EOF);
      if(t_flag_s) {
        printf("[Aluno não encontrado!!]\n [Tente novamente]\n\n");
      }
      break;
    case 3:
      char fend[2056], s2sd[2056];
      t_flag_s = 1;
      int pingor = 0;
      printf("[Eliminar dados de um aluno]\n\n");
      printf("Insira o número do aluno: ");
      scanf("%d", &n_aluno);
      sprintf(s2sd, "(Nº%d)", n_aluno);
      fend[0] = '\0'; // Limpar String
      FILE *jinx;
      jinx = fopen("tmp_file.txt", "w");
      do {
        if(pingor == 0) {
          pingor++;
        } else {
          if(strstr(fend, s2sd) != NULL) {
            t_flag_s = 0;
          } else {
            fprintf(jinx, "%s\n", fend);
          }
        }
      } while(fscanf(fp, "%[^\n]\n", fend) != EOF);
      fclose(fp);
      fclose(jinx);
      system("del /f %s", f_name);
      system("ren tmp_file.txt %s", f_name);
      if(t_flag_s) {
        printf("[Aluno não encontrado!!]\n [Tente novamente]\n\n");
      } else {
        printf("[O Aluno Nº%d foi eliminado com sucesso!]\n\n", n_aluno);
      }
      break;
    case 4:
      printf("[Listar todos os dados]\n\n");
      char c = fgetc(fp);
      do {
        printf ("%c", c);
        c = fgetc(fp);
      } while(c != EOF);
      break;
    case 0:
      flag = 0;
      printf("[Goodbye!!]\n\n");
      break;
    
    default:
      printf("[Opção não encontrada!!]\n [Tente novamente]\n\n");
    }

    system("PAUSE");
    fclose(fp);
    system("cls");
  }

  return 0;
}
