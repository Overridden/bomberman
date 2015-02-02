//
// Map.hh for bomberman in /home/dovan_n/bomberman
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Tue May 13 14:23:31 2014 Noel DOVAN
// Last update Sun Jun 15 21:41:28 2014 peyrot_m
//

#ifndef		MAP_HH_
# define	MAP_HH_

# define BONUS_PERCENTAGE	40
# define FRISBEE_PERCENTAGE	1
# define HARD_WALL		10

# include <SdlContext.hh>
# include <fstream>
# include <iostream>
# include <list>
# include <map>
# include <string>
# include "Bombe.hh"
# include "Rand.hh"
# include "Character.hh"

class Bombe;
class Character;

class Map
{
private:

  int                   _width;
  int                   _height;
  int			_madness;
  char			_name;
  std::list<Bombe*>	Bombes;

  std::list<std::string>        map;
  std::list<std::string>        map_prediction;
  std::list<std::string>        map_object;
  std::list<std::string>        map_player;

  Rand			rand;

  int                   _x;
  int                   _y;
  int                   _coeff;

  double                _time;

public:
  Map();
  Map(int const width, int const height, int const madness);
  Map(char const id);
  Map&				operator=(Map const& o);
  ~Map();

  void				AddBombe(int const force, int const x, int const y, std::string const& name, bool const frisbee);
  void				UpdateBombes(int& gameScore, gdl::Clock& clock,
					     std::list<Character*>& players);

  int				GetMapWidth() const;
  int				GetMapHeight() const;

  void				initPrediction();
  void				initObject();
  void				initPlayer();

  std::list<std::string> const &getMap() const;
  std::list<std::string> const &getPrediction() const;
  std::list<std::string> const &getObject() const;
  std::list<std::string> const &getPlayer() const;

  void				ShowMap() const;
  void				ShowPrediction() const;
  void				ShowObject() const;
  void				ShowPlayer() const;

  void				updateMap(unsigned int const x, unsigned int const y);
  void				updatePrediction(unsigned int const x,
						 unsigned int const y);
  void				updateObject(unsigned int const x, unsigned int const y);
  void				updatePlayer(unsigned int const x, unsigned int const y);

  char				mapGetValueAt(int const x, int const y) const;
  char			        predictionGetValueAt(int const x, int const y) const;
  char				objectGetValueAt(int const x, int const y) const;
  char				playerGetValueAt(int const x, int const y) const;

  void				closeMap(gdl::Clock& clock);

  void				mapSetValueAt(char const value, int const x, int const y);
  void				predictionSetValueAt(char const value, int const x,
						     int const y);
  void				objectSetValueAt(char const value, int const x,
						 int const y);
  void				playerSetValueAt(char const value, int const x,
						 int const y);

  int				getWidth() const;
  int				getHeight() const;
  int				getMadness() const;
  char				getName() const;

  void				setWidth(int const width);
  void				setHeight(int const height);
  void				setMadness(int const madness);
  void				setName(char const name);

  void				Reset();
  void				SetMapList(std::list<std::string> const& map,
					   std::list<std::string> const& mapObj,
					   std::list<std::string> const& mapPla);

private:

  void				parseMap(char* const name);

  void				AddBombeDir(bool& w, int const x, int const y, bool const frisbee);
  void				ExplodeBombe(Bombe* bombe, std::list<Character*>& players,
					     int& gameScore);
  void				ExplodeBombeDir(bool& w, int const x, int const y,
						std::list<Character*>& players,
						int& gameScore, Bombe* bombe);
  void				ExplodeBombAt(int const x, int const y);
  void				ExplodePlayerAt(int const x, int const y,
						std::list<Character*>& players,
						int& gameScore);
  void				RemoveBombe(Bombe* bombe, int& gameScore);
  void				RemoveBombeDir(int& gameScore, int const x, int const y);
  void				SpawnBonus(int const x, int const y);
  void				SpawnBonusFrisbee(char const value, int const x, int const y);

  void				RemoveBombByName(std::list<Character*>& players,
						 std::string const& name) const;

};

#endif
