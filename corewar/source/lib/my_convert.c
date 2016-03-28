/*
** my_convert.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:50:32 2016 Jakob Kellendonk
** Last update Mon Mar 28 14:35:23 2016 Jakob Kellendonk
*/

int	char_to_int(unsigned char *src)
{
  if (src[0] >> 7)
    return (-(int)((~(((src[0]) << 24u) + (src[1] << 16u)
		 + (src[2] << 8u) + src[3]) + 1u)));
  return ((src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3]);
}

int	char_to_short(unsigned char *src)
{
  if (src[0] >> 7)
    return (-(int)((~(((src[0]) << 8u) + src[1]) + 1u) & 0xFFFFu));
  return ((src[0] << 8u) + src[1]);
}

void		int_to_char(int nb, unsigned char *str)
{
  unsigned int	abs;

  if (nb < 0)
    abs = ~(unsigned int)((nb + (nb < 0)) * ((nb > 0) * 2 - 1));
  else
    abs = nb;
  str[0] = (abs >> 24u);
  str[1] = (abs >> 16u) & 255u;
  str[2] = (abs >> 8u) & 255u;
  str[3] = (abs & 255u);
}

void		short_to_char(int nb, unsigned char *str)
{
  unsigned int	abs;

  if (nb < 0)
    abs = ~(unsigned int)((nb + (nb < 0)) * ((nb > 0) * 2 - 1));
  else
    abs = nb;
  str[0] = (abs >> 8u) & 255u;
  str[1] = (abs & 255u);
}
