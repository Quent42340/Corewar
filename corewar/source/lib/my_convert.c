/*
** my_convert.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:50:32 2016 Jakob Kellendonk
** Last update Sat Mar 26 19:44:35 2016 Jakob Kellendonk
*/

int	char_to_int(unsigned char *src)
{
  return (((src[0] >> 7) * -2 + 1)
	  * (((src[0] & 127) << 24)
	     + (src[1] << 16)
	     + (src[2] << 8)
	     + src[3] + (src[0] >> 7)));
}

int	char_to_short(unsigned char *src)
{
  return (((src[0] >> 7) * -2 + 1)
	  * (((src[0] & 127) << 8)
	     + src[1] + (src[0] >> 7)));
}

void		int_to_char(int nb, unsigned char *str)
{
  unsigned int	abs;

  abs = (nb + (nb < 0)) * ((nb > 0) * 2 - 1);
  str[0] = ((nb < 0) * 128u) | (abs >> 24u);
  str[1] = (abs >> 16u) & 255u;
  str[2] = (abs >> 8u) & 255u;
  str[3] = (abs & 255u);
}

void		short_to_char(int nb, unsigned char *str)
{
  unsigned int	abs;

  abs = (nb + (nb < 0)) * ((nb > 0) * 2 - 1);
  str[0] = ((nb < 0) * 128u) | (abs >> 8u);
  str[1] = (abs & 255u);
}
