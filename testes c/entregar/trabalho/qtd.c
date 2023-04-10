#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palavras(char *line)
{
  int p = 0;
  char *delim = " \t\r\n\v\f";

  char *str = strtok(line, delim);
  for (; str != NULL; ++p)
    str = strtok(NULL, delim);

  return p;
}

int main(int argc, char *argv[])
{ 
  FILE * fp;
  size_t n = 0;

  int nlinhas = 0, p = 0, ncar = 0;
  char * line = NULL;

  fp = fopen("qtd.txt", "r");

  while ((n = getline(&line, &n, fp)) != -1)
  {
    line[strlen(line) - 1] = '\0';

    p = p + palavras(line);
    nlinhas++;
  }

  printf("Numero de Linhas: %i\n",nlinhas);
  printf("Numero de Palavras: %i\n",p);
  printf("Numero de caracteres:%i\n", ncar);

  if (line)
    free(line);

  fclose(fp);
  return 0;
}