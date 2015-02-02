//
// Time.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sat May 17 16:11:58 2014 Noel DOVAN
// Last update Fri Jun 13 10:33:22 2014 Noel DOVAN
//

#ifndef		TIME_HH_
# define	TIME_HH_

# include <time.h>

class Time
{

public:

  Time();
  ~Time();

  time_t			xtime(time_t *t) const;
  void				xstrftime(char *s, size_t max,
					  const char *format,
					  const struct tm *tm) const;
};

#endif
