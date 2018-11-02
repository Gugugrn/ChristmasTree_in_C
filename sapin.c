# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void  my_putchar(char c)
{
  write (1, &c, 1);
}

void  my_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i]  != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int etoile_derniere_ligne (int size)
{
  int x;
  int y;
  int nb_etoile;
  int niveau;
  int etoile_retirees;

  int ligne;
  x = 0;
  y = 0;

  ligne = 4;
  nb_etoile = 0;
  niveau = 0;
  etoile_retirees = 2; // etoiles en moins à chaque niveau

  while (y < size)
    {
      while (x < ligne )
	{
	  if (y == 0 && x == 0)
	    {
	      nb_etoile = nb_etoile + 1;
	    }
	  else if (x != 0)
	    nb_etoile = nb_etoile + 2;
	  x++;
	}

      x = 0;
      ligne++;

      if(niveau == 2)
	{
	  niveau = 0;
	  etoile_retirees = etoile_retirees + 2;
	}
      if (y != (size - 1))
	{
	  nb_etoile = (nb_etoile - etoile_retirees);
	}
      niveau++;
      y++;
    }
  return(nb_etoile);
}

int print_line (int nb_etoile, int nb_espace)
{
  int x = 0;
  int espace = 0;
  while (x < nb_etoile)
    {
      while(espace < nb_espace)
	{
	  my_putchar(32);
	  espace++;
	}
      my_putchar(42);
      x++;
    }
  return(espace - 1);
}


void struct_sapin (int size, int nb_espace)
{
  int x;
  int y;
  int nb_etoile;
  int niveau;
  int etoile_retirees;
  int espaces_ajoutes;

  int ligne;
  x = 0;
  y = 0;

  ligne = 4; 
  nb_etoile = 0;
  niveau = 0;
  etoile_retirees = 2; // etoiles en moins à chaque niveau
  espaces_ajoutes = 2; // etoiles ajoutees à chaque niveau

  while (y < size)
    {
      while (x < ligne )
	{
	  if (y == 0 && x == 0)
	    {
	      nb_etoile = nb_etoile + 1;
	    }
	  else if (x != 0)
	    {
	      nb_etoile = nb_etoile + 2;
	    }

	  nb_espace = print_line(nb_etoile, nb_espace);
	  my_putchar('\n');
	  x++;
	}

      x = 0;
      ligne++;

      if(niveau == 2)
	{
	  niveau = 0;
	  etoile_retirees = etoile_retirees + 2;
	  espaces_ajoutes++;
	}

      nb_etoile = (nb_etoile - etoile_retirees);
      nb_espace = nb_espace + espaces_ajoutes;
      niveau++;
      y++;
    }
}

void struct_tronc(int size, int nb_etoile_max)
{
  int x = 0;
  int y = 0;
  int branches;
  int nb_espace;
  int espace;
  espace = 0;

  if (size % 2 == 0)
    {
      branches = size + 1;
    }
  else
    {
      branches = size;
    }

  nb_espace = (nb_etoile_max - branches) / 2;

  while (y < size)
    {
      while (x < branches)
	{
	  while (espace < (nb_espace))
	    {
	      my_putchar(32);
	      espace++;
	    }
	  my_putchar('|');
	  x++;
	}
      my_putchar('\n');
      espace = 0;
      x = 0;
      y++;
    }
}

void sapin(int size)
{
  int nb_etoile_max;
  int nb_espace;

  nb_etoile_max = etoile_derniere_ligne(size);
  nb_espace = (nb_etoile_max / 2);
  struct_sapin(size, nb_espace);
  struct_tronc(size, nb_etoile_max);
}

int main(int argc, char const *argv[])
{
  if (argc != 2)
    {
      my_putstr("Impossible, il faut une valeur !\n");
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

