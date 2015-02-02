//
// GetGameForSave.cpp for  in /home/peyrot_m/Restart_bomber
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Sat Jun 14 02:28:01 2014 peyrot_m
// Last update Sun Jun 15 22:31:02 2014 Noel DOVAN
//

#include "GameEngine.hh"

Map const&              GameEngine::getMap() const
{
  return *this->map;
}

Map&	             GameEngine::getMap2()
{
  return *this->map;
}

int                    GameEngine::getPlayer() const
{
  return this->_joueur;
}

int                    GameEngine::getPlayerFix() const
{
  return this->_joueurFix;
}

int                     GameEngine::getIA() const
{
  return this->_ia;
}

int                     GameEngine::getGameScore() const
{
  return this->GameScore;
}

std::list<Character*> const&    GameEngine::getPlayers() const
{
  return this->Players;
}

double                  GameEngine::getTime() const
{
  return this->_time;
}

void			GameEngine::setPlayer(int const player)
{
  this->_joueur = player;
}

void			GameEngine::setPlayerFix(int const player)
{
  this->_joueurFix = player;
}

void			GameEngine::setIA(int const ia)
{
  this->_ia = ia;
}

void			GameEngine::setGameScore(int const gameScore)
{
  this->GameScore = gameScore;
}

void			GameEngine::setWidth(int const width)
{
  this->_width = width;
}
void			GameEngine::setHeight(int const height)
{
  this->_height = height;
}

void			GameEngine::setMadness(int const madness)
{
  this->_madness = madness;
}

void			GameEngine::createMap()
{
  this->map = new Map();
}

void                    GameEngine::AddPlayer(int const id, std::string const& name,
                                          int const life, int const force, float const& speed,
                                          int const max, int const used, int const x,
                                          int const y, float const& __x, float const& __y,
                                          bool const frisbee, int const type)
{
  this->Players.push_back(new Character(id, name, life, force, speed, max, used, x, y, __x, __y, frisbee, type));
}
