//
// Sleep.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Thu May 15 16:46:32 2014 Noel DOVAN
// Last update Thu May 15 16:53:55 2014 Noel DOVAN
//

#include "Sleep.hh"

Sleep::Sleep()
{
}

Sleep::~Sleep()
{
}

void			Sleep::xsleep(unsigned int const seconds) const
{
  sleep(seconds);
}

void			Sleep::xusleep(useconds_t const usec) const
{
  if (usleep(usec) == -1)
    throw MyException("usleep failed");
}
