//
// Character.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Tue May 13 17:15:12 2014 Noel DOVAN
// Last update Sun Jun 15 13:27:58 2014 theron
//

#ifndef		CHARACTER_HH_
# define	CHARACTER_HH_

# define SPEED	0.1

# include <SdlContext.hh>
# include <iostream>
# include <boost/random/mersenne_twister.hpp>
# include <boost/random/uniform_int.hpp>
# include <boost/random/variate_generator.hpp>
# include <boost/random/ranlux.hpp>
# include <Model.hh>
# include "AObject.hh"
# include "Map.hh"
# include "Bombe.hh"
# include "fmod.h"
# include "Rand.hh"

class Map;

class Character
{

private:

  int			ID;
  std::string		Name;
  int			Life;
  int			Force;
  float			Speed;
  int			Max;
  int			Used;
  int			X;
  int			Y;
  float			_x;
  float			_y;
  bool			OnBomb;
  int			BombX;
  int			BombY;
  int			cmp;
  int			_type;
  bool			Frisbee;

  FMOD_SYSTEM*          SoundSystem;
  FMOD_SOUND*           SoundBoss;

public:

  Character(int const id, Map& map, Rand& rand, std::string const& name, int const type);
  Character(int const id, std::string const& name, int const life, int const force, float const& speed, int const max, int const used, int const x, int const y, float const& __x, float const& __y, bool const frisbee, int const type);
  ~Character();

  void		moveIA(Map &_map, gdl::Clock &clock);

  int			getID() const;
  std::string const&	getName() const;
  int			getLife() const;
  int			getForce() const;
  float			getSpeed() const;
  int			getMax() const;
  int			getUsed() const;
  float			getX() const;
  float			getY() const;
  int			getType() const;
  bool			getFrisbee() const;
  void			setType(int const type);


  void		setPos(float const x, float const y,
		       float const x2, float const y2, Map& map);
  void		DoBombe(Map& map);
  void		RemoveBombe();
  void		RemoveLife();

private:

  void		InitCharacterPos(Map& map, Rand& rand);

  int		checkMapValue(Map &_map, int i, int x, int y, int state);
  int		checkPreValue(Map &_map, int i, int x, int y, int state);
  int		checkObjValue(Map &_map, int i, int x, int y, int state);
  int		checkPlaValue(Map &_map, int i, int x, int y, int state);
  void		chooseWhereToGo(Map &_map, int u, int d, int l, int r,
				  gdl::Clock &clock);
  void		doMoveIA(Map &_map, int dir, int cas, gdl::Clock &clock);
  void		doWhatIA(Map &_map, int dir, int cas, gdl::Clock &clock);
  void		putBombIA(Map &_map);

};

#endif
