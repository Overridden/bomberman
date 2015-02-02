//
// Time.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sat May 17 16:12:58 2014 Noel DOVAN
// Last update Fri Jun 13 10:33:25 2014 Noel DOVAN
//

#include "Time.hh"

Time::Time()
{
}

Time::~Time()
{
}

time_t			Time::xtime(time_t *t) const
{
  return time(t);
}

void			Time::xstrftime(char *s, size_t max,
					const char *format,
					const struct tm *tm) const
{
  strftime(s, max, format, tm);
}
