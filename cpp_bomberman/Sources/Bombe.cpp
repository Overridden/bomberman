//
// Bombe.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sat May 17 15:52:10 2014 Noel DOVAN
// Last update Thu Jun 12 19:57:51 2014 theron
//

#include "Bombe.hh"
#include "SoundManager.hh"

Bombe::Bombe(int const force, int const x, int const y, std::string const& name, bool const frisbee) : Force(force), X(x), Y(y), Name(name), Etime(0), Exploded(false),Frisbee(frisbee)
{
}

Bombe::~Bombe()
{
}

bool			Bombe::CheckBombe(double const& etime)
{
  this->Etime += etime;
  if (this->Etime >= TIMEBEFORE)
    {
      SoundManager::shared()->playSound(BOMBE);
      this->Exploded = true;
      this->Etime = 0;
      return true;
    }
  return false;
}

bool			Bombe::CheckExplosion(double const& etime)
{
  this->Etime += etime;
  if (this->Etime >= TIMEAFTER)
    return true;
  return false;
}

int			Bombe::getForce() const
{
   return this->Force;
}

int			Bombe::getX() const
{
  return this->X;
}

int			Bombe::getY() const
{
  return this->Y;
}

std::string const&	Bombe::getName() const
{
  return this->Name;
}

bool			Bombe::getExploded() const
{
  return this->Exploded;
}

bool			Bombe::getFrisbee() const
{
  return this->Frisbee;
}

void			Bombe::doExplode()
{
  this->Etime = TIMEBEFORE;
}
