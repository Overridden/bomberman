//
// Bombe.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sat May 17 15:51:39 2014 Noel DOVAN
// Last update Thu Jun 12 16:21:15 2014 Noel DOVAN
//

#ifndef		BOMBE_HH_
# define	BOMBE_HH_

# define TIMEBEFORE	2.0
# define TIMEAFTER	0.5

# include "Map.hh"
# include "fmod.h"

class Map;

class Bombe
{

private:

  int const		Force;
  int const		X;
  int const		Y;
  std::string		Name;
  double		Etime;
  bool			Exploded;
  bool			Frisbee;

  // FMOD_SYSTEM			*SoundSystem;
  // FMOD_SOUND			*SoundBombe;

public:

  Bombe(int const force, int const x, int const y, std::string const& name, bool const frisbee);
  ~Bombe();

  bool			CheckBombe(double const& etime);
  bool			CheckExplosion(double const& etime);

  int			getForce() const;
  int			getX() const;
  int			getY() const;
  std::string const&	getName() const;
  bool			getExploded() const;
  bool			getFrisbee() const;
  void			doExplode();

};

#endif
