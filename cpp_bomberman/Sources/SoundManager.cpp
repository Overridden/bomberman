//
// SoundManager.cpp for  in /home/theron_b/rendu/cpp_bomberman
//
// Made by theron
// Login   <theron_b@epitech.net>
//
// Started on  Tue Jun 10 14:30:38 2014 theron
// Last update Wed Jun 11 16:23:14 2014 theron
//

#include "SoundManager.hh"

SoundManager			*SoundManager::_shared = NULL;

SoundManager		        *SoundManager::shared()
{
  if (!_shared)
    _shared = new SoundManager();
  return (_shared);
}

SoundManager::SoundManager()
{
  this->_init = false;
  if (FMOD::System_Create(&(this->_sys)) != FMOD_OK)
    std::cerr << "Can't create FMOD" << std::endl;
  else if (this->_sys->init(1024, FMOD_INIT_NORMAL, NULL) != FMOD_OK)
    std::cerr << "Can't init FMOD" << std::endl;
  else
    this->_init = true;
  _shared = NULL;
}

SoundManager::~SoundManager()
{
  this->_sys->release();
  this->_soundLoop->release();
}

bool            SoundManager::pauseLoop()
{
  if (!this->_init)
    return (false);
  if (this->_sys->playSound(FMOD_CHANNEL_FREE, this->_soundLoop,
                            true, &this->_channelLoop) != FMOD_OK)
    {
      std::cerr << "SoundManager: Can't pause loop" << std::endl;
      return (false);
    }
  return (true);
}

bool            SoundManager::resumeLoop()
{
  if (!this->_init)
    return (false);
  if (this->_sys->playSound(FMOD_CHANNEL_FREE, this->_soundLoop,
                            false, &this->_channelLoop) != FMOD_OK)
    {
      std::cerr << "SoundManager: Can't play loop" << std::endl;
      return (false);
    }
  return (true);
}

bool		SoundManager::playSound(const std::string& filename)
{
  std::map<std::string, FMOD::Sound*>::iterator it;
  FMOD::Sound*                                  sound;

  it = this->_sounds.find(filename);
  if (it == this->_sounds.end())
    {
      if (this->_sys->createStream(filename.c_str(), FMOD_SOFTWARE,
				   0, &sound) == FMOD_OK)
	{
	  this->_sounds[filename] = sound;
	  return (this->_sys->playSound(FMOD_CHANNEL_FREE, sound, false,
					&this->_channelSounds)
		  == FMOD_OK ? true : false);
	}
    }
  else
    return (this->_sys->playSound(FMOD_CHANNEL_FREE, it->second, false,
				  &this->_channelSounds)
	    == FMOD_OK ? true : false);
  return (false);
}

bool		SoundManager::playLoop(const std::string& filename)
{
  if (!this->_init)
    return (false);
  this->_channelLoop->stop();
  if (this->_sys->createSound(filename.c_str(), FMOD_SOFTWARE | FMOD_LOOP_NORMAL,
			      0, &this->_soundLoop) != FMOD_OK)
    {
      std::cerr << "SoundManager: Can't load sound : " << filename << std::endl;
      return (false);
    }
  if (this->_sys->playSound(FMOD_CHANNEL_FREE, this->_soundLoop,
			    false, &this->_channelLoop) != FMOD_OK)
    {
      std::cerr << "SoundManager: Can't play loop" << std::endl;
      return (false);
    }
  this->_channelLoop->setVolume(0.40);
  return (true);
}

void                                            SoundManager::update()
{
  this->_sys->update();
}
