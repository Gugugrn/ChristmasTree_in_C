#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sapin (int size);

int main(int argc, char const *argv[])
{
  if (argc != 2)
    {
      my_putstr("Impossible, doit comporter une valeur s'il vous plait !\n");
      return 1;
    }

  if (atoi(argv[1]) > 15)
    {
      my_putstr("Allons, soyez raisonnable, pas trop, on dit souvent que plus c'est long plus c'est bon mais doucement !\n");
      return 1;
    }

  if (atoi(argv[1]) < 0)
    {
      my_putstr("Impossible, doit être > 0\n");
    }


  int size;
  size = atoi(argv[1]);
  sapin(size);
  return (0);
}
