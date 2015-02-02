/*
** GameEngine.hpp for partie graphique bomberman in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Thu May 15 15:55:43 2014 Alexandre NGUYEN
// Last update Sun Jun 15 23:34:22 2014 Noel DOVAN
*/

#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hh"
#include "Bonus.hh"
#include "Cube.hh"
#include "Carre.hh"
#include "Character.hh"
#include "Save.hh"
#include "Menu.hh"
#include "Intro.hh"
#include "Map.hh"
#include "Player.hh"
#include "MyException.hh"
#include "Pokemon.hh"
#include "Player.hh"
#include "SoundManager.hh"
#include "Cam.hh"
#include "Skybox.hh"
#include "Sleep.hh"

#define TIME_CLOCK	1

class GameEngine : public gdl::Game, public gdl::SdlContext
{
private:
  gdl::Clock			_clock;
  gdl::Input			_input;
  gdl::BasicShader		_shader;
  std::vector<gdl::Geometry*>	_geometry;
  std::vector<gdl::Texture*>    _texture; // liste des geometrie
  std::vector<gdl::Model*>    	_model; // liste des Model
  std::vector<AObject*>		_objects; // tout les objet
  std::list<Character*>		Players; // liste player
  Rand				rand;
  Sleep				sleep;
  Score				score;
  Time				time;

  int				_time;
  int				_type;

  int				_part; // definie partie du jeu
  Map*				map; //map

  int			_joueur; // nb j
  int			_joueurFix;
  int			_ia; // nb ia
  int			_madness; // nb mad
  int			_height; // hauteur
  int			_width; // largeur
  int			_map; // num map

  double		_chrono;

  bool			end; // déja fini :(
  bool			_boss; // y a t'il un boss dans le game
  bool			WinGame; // si gagné
  bool			LoseGame; // si perdu
  bool			Option; //
  int                   GameScore; // score du jeu;

  FMOD_SYSTEM*          SoundSystem;
  FMOD_SOUND*           SoundGame;
  FMOD_SOUND*           SoundWin;
  FMOD_SOUND*           SoundLose;
  FMOD_SOUND*           SoundBoss;
  FMOD_SOUND*           SoundMenu;

  // Thread		thread;

  SDL_Surface			*loadImage(std::string filepath);
  void			applySurface(int x,int y, SDL_Surface* source,
						 SDL_Window* destination, SDL_Rect *clip);


public:
  GameEngine();
  ~GameEngine();
  bool			initialize();
  bool			update();
  void			draw();
  SDL_Window		*getWindow();
  void			CleanTheGame();
  void                  IsDoSave();
  void                  IsDoLoad();
  void                  WriteScore(std::string const &i);

  // Scene.cpp
  bool			scene();
  bool			scene_for_game();
  bool			Init_map();
  bool			Initplayer(Map &map);
  void			InitLoadOne();
  void			InitModelOne();
  void			InitGeoOne();


  // Updatall.cpp
  void                  UpdateIntro(__attribute__((unused))
				    gdl::Clock const &clock,
				    __attribute__((unused))
				    gdl::Input &input);
  void                  UpdateMenu(__attribute__((unused))
				   gdl::Clock const &clock,
				   __attribute__((unused))
				   gdl::Input &input);


  void			UpdateWinGame();
  void			UpdateLoseGame();
  void                  UpdatePlayers(int const i);
  void                  UpdateAI(int const i);
  void                  UpdateCharacters(int const i);
  void                  UpdateCubeBombe();
  void                  IsFinish();
  Character*            GetPlayerByID(int const id) const;
  Character*		GetPlayerByName(std::string const& name) const;
  void                  StopMusic() const;

  //GetSetForSave.cpp

  Map const&		getMap() const;
  Map&			getMap2();
  int			getPlayer() const;
  int			getPlayerFix() const;
  int                   getIA() const;
  int                   getGameScore() const;
  std::list<Character*> const&    getPlayers() const;
  double                getTime() const;

  void			setPlayer(int const player);
  void			setPlayerFix(int const player);
  void			setIA(int const ia);
  void			setGameScore(int const gameScore);
  void			setWidth(int const width);
  void			setHeight(int const height);
  void			setMadness(int const madness);
  void			createMap();
  void			AddPlayer(int const id, std::string const& name,
				  int const life, int const force, float const& speed,
				  int const max, int const used, int const x,
				  int const y, float const& __x, float const& __y,
				  bool const frisbee, int const type);

public:

  friend std::ostream&  operator<<(std::ostream& os, GameEngine const& o);
  friend std::istream&  operator>>(std::istream& is, GameEngine& o);

};



#endif /* !GAMEENGINE_HH_ */
