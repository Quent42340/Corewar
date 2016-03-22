/*
** my_convert.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:50:32 2016 Jakob Kellendonk
** Last update Tue Mar 22 18:37:41 2016 Jakob Kellendonk
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
	  * (((src[0] & 127) << 24)
	     + (src[1] << 8) + (src[0] >> 7)));
}
