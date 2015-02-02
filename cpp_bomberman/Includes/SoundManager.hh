//
// SoundManager.hh for  in /home/theron_b/rendu/cpp_bomberman
//
// Made by theron
// Login   <theron_b@epitech.net>
//
// Started on  Tue Jun 10 14:15:09 2014 theron
// Last update Sun Jun 15 17:16:21 2014 theron
//

#ifndef SOUND_MANAGER_HH
# define SOUND_MANAGER_HH

#include "fmod.hpp"
#include <map>
#include <iostream>

# define	MENUMUSIC	"./Res/Music/menu.wav"
# define	GAMEMUSIC	"./Res/Music/smooth_criminal.mp3"

# define        DIE		"./Res/Sound/die.ogg"
# define        BOMBE		"./Res/Sound/bombe.ogg"
# define        BONUS		"./Res/Sound/bonus.ogg"
# define        BOSS		"./Res/Sound/boss.ogg"
# define        INTRO		"./Res/Sound/intro.ogg"
# define        POKEMON		"./Res/Sound/pokemon.ogg"
# define        LOSE		"./Res/Sound/you_lose.ogg"
# define        WIN		"./Res/Sound/you_win.ogg"
# define        CLICK		"./Res/Sound/click.wav"
# define        FANFARE		"./Res/Sound/fanfare.wav"

# define	DOVAN		"./Res/Sound/dovan.ogg"
# define	DURAND		"./Res/Sound/durand.wav"
# define	FONTAI		"./Res/Sound/fontai.wav"
# define	LASTRU		"./Res/Sound/lastru.wav"
# define	NGUYE		"./Res/Sound/nguyen.wav"
# define        PEYROT		"./Res/Sound/peyrot.wav"
# define	THERON		"./Res/Sound/theron.wav"

class					SoundManager
{
  static SoundManager			*_shared;
  FMOD::System				*_sys;
  FMOD::System				*_system;
  FMOD::Sound				*_soundLoop;
  FMOD::Channel				*_channelLoop;
  std::map<std::string, FMOD::Sound*>	_sounds;
  std::map<std::string, FMOD::Sound*>	_streams;
  FMOD::Channel				*_channelSounds;
  FMOD::Channel				*_channelStreams;
  FMOD::Channel				*_channelBombs;
  bool					_init;

  SoundManager&				operator=(const SoundManager&);
  SoundManager(const SoundManager&);
public:
  SoundManager();
  ~SoundManager();

  bool					pauseLoop();
  bool					resumeLoop();
  bool					playSound(const std::string&);
  bool					playLoop(const std::string&);
  void					update();
  static SoundManager			*shared();
};

#endif // SOUND_MANAGER_HH
