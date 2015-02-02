//
// Rand.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Thu May 15 16:28:23 2014 Noel DOVAN
// Last update Sun Jun  1 17:45:22 2014 Noel DOVAN
//

#include "Rand.hh"
#include "Timeval.hh"

Rand::Rand()
{
  srand(this->time.xtime(NULL));
}

Rand::~Rand()
{
}

int   Rand::randVal() const
{
  return (rand());
}

int   Rand::randVal(unsigned const max) const
{
  return (rand() % max);
}

int   Rand::randVal(int const min, int const max) const
{
  return (rand() % (max - min) + min);
}
