/*
** GameEngine.cpp for GameEngine in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 20 15:51:01 2014 teddy fontaine
// Last update Sun Jun 15 23:33:41 2014 Noel DOVAN
*/

#include <iostream>
#include <string>
#include "GameEngine.hh"

GameEngine::GameEngine()
{
  this->WinGame = false;
  this->Option = false;
  this->LoseGame = false;
  this->_boss = false;
  this->end = true;
  this->GameScore = 0;
  this->_part = 0;
  this->_chrono = 0;
  FMOD_System_Create(&this->SoundSystem);
  FMOD_System_Init(this->SoundSystem, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(this->SoundSystem, "Res/Music/smooth_criminal.mp3",
                          FMOD_CREATESAMPLE | FMOD_LOOP_NORMAL, 0,
                          &this->SoundGame);
  FMOD_System_CreateSound(this->SoundSystem, "Res/Music/bossmusic.wav",
                          FMOD_CREATESAMPLE | FMOD_LOOP_NORMAL, 0,
                          &this->SoundBoss);
  FMOD_System_CreateSound(this->SoundSystem, "Res/Sound/you_win.ogg",
                          FMOD_CREATESAMPLE, 0,
                          &this->SoundWin);
  FMOD_System_CreateSound(this->SoundSystem, "Res/Sound/you_lose.ogg",
                          FMOD_CREATESAMPLE, 0,
                          &this->SoundLose);
 FMOD_System_CreateSound(this->SoundSystem, "Res/Music/menu.wav",
                          FMOD_CREATESAMPLE | FMOD_LOOP_NORMAL, 0,
                          &this->SoundMenu);
 }

/*
 * Initialisation de la fenetre
 * Initialisation de la camera
 * Draw de 3 cubes par SceneDraw::scene()
 */
bool		GameEngine::initialize()
{
  if (!start(1280, 960, "Bomberbobby"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./Res/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./Res/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  glm::mat4 projection;
  glm::mat4 transformation;
  projection = glm::perspective(60.0f, 1280.0f / 960.0f, 0.1f, 30.0f);
  transformation = glm::lookAt(glm::vec3(1, 1, 6), glm::vec3(1, 1, 5), glm::vec3(0, 1, 0));
  _shader.bind();
  this->InitLoadOne();
  this->InitModelOne();
  this->InitGeoOne();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  _shader.setUniform("color", glm::vec4(1, 1, 1, 1));
  if (scene() == false)
    return (false);
  return (true);
}

/*
 * Retourne la fenetre courante
 */
SDL_Window	*GameEngine::getWindow()
{
  return (_window);
}

/*
 * update des objets
 * gestion des events
 */
bool			GameEngine::update()
{
  size_t		i;
  std::vector<int>	objs;

  i = 3;
  updateClock(_clock);
  updateInputs(_input);
  this->_chrono += this->_clock.getElapsed();
  if (this->_part == 0)
    {
      FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE, this->SoundMenu,
			    0, NULL);
      this->UpdateIntro(_clock,_input);
    }
  else if (this->_part == 1)
    {
      objs =  _objects[2]->getObjs();
      this->_joueur = objs[0];
      this->_ia = objs[1];
      this->_madness = objs[2];
      this->_width = objs[3];
      this->_height = objs[4];
      this->_map = objs[5];
      if (objs[7] == 1 || _input.getInput(SDL_QUIT))
      	return false;
      this->_part = objs[6];
      if (objs[7] == 2)
      	{
      	  this->IsDoLoad();
      	  if (this->scene_for_game() == false)
      	    return (false);
      	  this->_part = 4;
	  FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE,
	  			this->SoundMenu,
	  			1, NULL);
	  SoundManager::shared()->playSound(POKEMON);
	  FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE,
				this->SoundGame,
				0, NULL);
      	}
      _objects[2]->update(_clock, _input);
      objs.clear();
      if (this->_part == 2)
	{
	  FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE,
	  			this->SoundMenu,
	  			1, NULL);
	  SoundManager::shared()->playSound(POKEMON);
	  FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE,
				this->SoundGame,
				0, NULL);
	}

    }
  else if (this->_part == 2)
    {

      _objects[3]->update(_clock, _input);
      objs =  _objects[3]->getObjs();
      this->_part = objs[1];
      objs.clear();
    }
  else if (this->_part == 3)
    {
      _objects[3]->setObjs(0);
      this->Init_map();
      if (this->scene_for_game() == false)
	return (false);
      this->_part = 4;
    }

  else if (this->_part == 4)
    {
      if ((this->_boss && this->_chrono >= 30)
          || (!this->_boss && this->_chrono >= 60))
	this->map->closeMap(this->_clock);
      if (!this->WinGame && !this->LoseGame && !this->Option)
        {
	  this->UpdateCubeBombe();
	  i = 3;
	  while (++i < _objects.size())
	    {
	      objs =  _objects[i]->getObjs();
	      Character*    player1 = this->GetPlayerByID(objs[1]);
	      if (player1)
	  	{
	  	  if (objs[0] == 3 || objs[0] == 4)
	  	    this->UpdateAI(i);
	  	  _objects[i]->update(_clock, _input);
	  	  if (objs[0] == 5)
	  	    this->UpdatePlayers(i);
	  	}
	      objs.clear();
	    }
	  i = ((this->_width * this->_height) * 2) + 4;
	  this->map->UpdateBombes(this->GameScore, this->_clock, this->Players);
	  while (++i < _objects.size()) // update player et ia
	    this->UpdateCharacters(i);
	  this->IsFinish();
	  if (_input.getKey(SDLK_ESCAPE))
	    this->Option = true;
	}
      else if (this->Option)
	{
	  _objects[2]->setObjs(1);
	  _objects[2]->update(_clock, _input);
	  objs =  _objects[2]->getObjs();
	  if (objs[9] == 1)
	    {
	      _objects[2]->setObjs(4);
	      this->Option = false;
	    }
	  if (objs[9] == 2)
	    {
	      this->IsDoSave();
	      _objects[2]->setObjs(4);
	    }
	  else if (objs[9] == 3)
	    {
	      _objects[2]->setObjs(0);
	      this->CleanTheGame();
	      this->_part = 1;
	    }
	  objs.clear();
	}
      else if (this->WinGame)
	{
	  glViewport(0, 0, 1280, 960);
	  _objects[2]->setObjs(2);
	  _objects[2]->update(_clock, _input);
	  objs =  _objects[2]->getObjs();
	  if (objs[7] == 3)
	    {
	      _objects[2]->setObjs(5);
	      this->WriteScore(_objects[2]->getString());
	      this->CleanTheGame();
	      this->_part = 1;
	    }
	}
      else if (this->LoseGame)
	{
	  glViewport(0, 0, 1280, 960);
	  _objects[2]->setObjs(3);
	  _objects[2]->update(_clock, _input);
	  objs =  _objects[2]->getObjs();
	  if (objs[7] == 3)
	    {
	      _objects[2]->setObjs(5);;
	      this->CleanTheGame();
	      this->_part = 1;
	    }
	}
      if (this->Option == 1)
	{
	  glViewport(0, 0, 1280, 960);
	  _shader.setUniform("projection", glm::perspective
	  		     (30.0f, (1280.0f) / 960.0f, 0.1f, 30.0f));
	}

    }
  objs.clear();
  return (true);
}

/*
 * Affiche la scene a l'ecran
 */
void		GameEngine::draw()
{
  size_t		i;
  size_t		x;
  size_t		z;
  std::vector<int>      objs;
  float			p1x;
  float			p1z;
  float			p2x;
  float			p2z;

  i = 3;
  z = ((this->_width * this->_height) * 2) + 3;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  if (this->_part < 4)
    {
      if (this->_part == 0)
	_objects[1]->draw(_shader, _clock);
      else if (this->_part == 1)
	_objects[2]->draw(_shader, _clock);
      else if (this->_part == 2)
	_objects[3]->draw(_shader, _clock);
    }
  else if (this->_part == 4)
    {
      if (!this->WinGame && !this->LoseGame && !this->Option)
        {
	  glDisable (GL_BLEND);
	  i = 3;
	  while (++i < _objects.size())
	    {
	      x = -1;
	      objs = _objects[i]->getObjs();
	      while (++x < objs.size())
		{
		  if (objs[0] == 5)
		    {
		      if (this->_joueurFix == 2 && this->_joueur == 2)
			{
			  if (objs[1] == 0)
			    {
			      p1x = _objects[i]->getX();
			      p1z = _objects[i]->getZ();
			    }
			  else if (objs[1] == 1)
			    {
			      p2x = _objects[i]->getX();
			      p2z = _objects[i]->getZ();
			    }
			}
		      else if (this->_joueur < this->_joueurFix || this->_joueur == 1)
			{
			  p1x = _objects[i]->getX();
			  p1z = _objects[i]->getZ();
			}
		    }
		}
	      objs.clear();
	    }
	  if (this->_joueur == 2 && this->_joueurFix < 3)
	    {
	      i = z;
	      _shader.setUniform("view", glm::lookAt
				 ( glm::vec3(p1x + 8, 10, p1z),
				   glm::vec3(p1x, 0, p1z),
				   glm::vec3(0, 1, 0)));
	      glViewport(0, 0, 1280 / 2, 960);
	      _objects[4]->draw(_shader, _clock);

	      i = 4;
	      while (++i < z + 1)
		{
		  if (_objects[i]->getX() <= p1x + 8 && _objects[i]->getX() >= p1x - 20 &&
		      _objects[i]->getZ() <= p1z + 19 && _objects[i]->getZ() >= p1z - 19)
		    _objects[i]->draw(_shader, _clock);
		}
	      i = z;
	      while (++i < _objects.size())
		_objects[i]->draw(_shader, _clock);
	      _shader.setUniform("view", glm::lookAt
				 (glm::vec3(p2x + 8, 10, p2z),
				  glm::vec3(p2x, 0, p2z),
				  glm::vec3(0, 1, 0)));
	      glViewport(1280 / 2, 0, 1280 / 2, 960);
	      _objects[4]->draw(_shader, _clock);
	      i = 4;
	      while (++i < z + 1)
		{
		  if (_objects[i]->getX() <= p2x + 8 && _objects[i]->getX() >= p2x - 20 &&
		      _objects[i]->getZ() <= p2z + 19 && _objects[i]->getZ() >= p2z - 19)
		    _objects[i]->draw(_shader, _clock);
		}
	      i = z;
	      while (++i < _objects.size())
		_objects[i]->draw(_shader, _clock);
	      _shader.setUniform("projection", glm::perspective
				 (60.0f, (1280.0f / 2) / 960.0f, 0.1f, 30.0f));
	    }
	  else if (this->_joueur == 1 && this->_joueurFix < 3)
	    {
	      i = z;
	      _shader.setUniform("view", glm::lookAt
				 (glm::vec3(p1x + 8, 10, p1z),
				  glm::vec3(p1x, 0, p1z),
				  glm::vec3(0, 1, 0)));
	      glViewport(0, 0, 1280, 960);
	      _objects[4]->draw(_shader, _clock);
	      i = 4;
	      while (++i < z + 1)
		{
		  if (_objects[i]->getX() <= p1x + 8 && _objects[i]->getX() >= p1x - 20 &&
		      _objects[i]->getZ() <= p1z + 19 && _objects[i]->getZ() >= p1z - 19)
		    _objects[i]->draw(_shader, _clock);
		}
	      i = z;
	      while (++i < _objects.size())
		_objects[i]->draw(_shader, _clock);
	      _shader.setUniform("projection", glm::perspective
				 (60.0f, 1280.0f / 960.0f, 0.1f, 30.0f));
	    }
	  else
	    {
	      i = 3;
	      _shader.setUniform("view", glm::lookAt
				 (glm::vec3(11, 18, 10),
				  glm::vec3(10, 0, 10),
				  glm::vec3(0, 1, 0)));
	      glViewport(0, 0, 1280, 960);
	      while (++i < _objects.size())
		_objects[i]->draw(_shader, _clock);
	      _shader.setUniform("projection",
				 glm::perspective
				 (60.0f, 1280.0f / 960.0f, 0.1f, 70.0f));
	    }
	}
      else if (this->WinGame || this->LoseGame || this->Option)
	{
	  _shader.setUniform("projection",
			     glm::perspective
			     (60.0f, 1280.0f / 960.0f, 0.1f, 30.0f));
	  _shader.setUniform("view", glm::lookAt
			     ( glm::vec3(1, 1 , 6),
			       glm::vec3(1, 1, 5),
			       glm::vec3(0, 1, 0)));
	  _objects[2]->draw(_shader, _clock);
	}
    }
  this->flush();
}

void		GameEngine::CleanTheGame()
{
  std::vector<AObject*>::iterator       it2(this->_objects.begin());
  size_t	i;

  i = 0;
  while (it2 != this->_objects.end())
    {
      if (i > 3)
	it2 = this->_objects.erase(it2);
      else
	++it2;
      ++i;
    }
  this->WinGame = false;
  this->Option = false;
  this->LoseGame = false;
  this->_boss = false;
  this->GameScore = 0;
  this->_part = 0;
  FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE, this->SoundGame,
                        1, NULL);
  FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE, this->SoundBoss,
                        1, NULL);
  FMOD_System_PlaySound(this->SoundSystem, FMOD_CHANNEL_FREE, this->SoundMenu,
                        0, NULL);
  while (!this->Players.empty())
    {
      delete this->Players.back();
      this->Players.pop_back();
    }
  this->_time = 0;
  this->_chrono = 0;
  this->map->Reset();
  delete this->map;
}

/*
 * Detruit les objets
 */
GameEngine::~GameEngine()
{
  size_t	i;

  i = -1;
  while (++i < _objects.size())
    delete _objects[i];
  FMOD_System_Close(this->SoundSystem);
  FMOD_System_Release(this->SoundSystem);
  FMOD_Sound_Release(this->SoundGame);
  FMOD_Sound_Release(this->SoundWin);
  FMOD_Sound_Release(this->SoundLose);
  FMOD_Sound_Release(this->SoundBoss);

}

void                    GameEngine::IsDoSave()
{
  time_t            t = this->time.xtime(NULL);
  std::stringstream ss;
  ss << t;
  std::string       SaveName = "Res/Saves/" + ss.str();
  std::fstream      file;
  file.open(SaveName.c_str(), std::fstream::out | std::fstream::trunc);
  if (!file.is_open())
    throw MyException("open file failed");
  file << *this;
  file.close();
  this->sleep.xusleep(500000);
}

void                    GameEngine::IsDoLoad()
{

  std::fstream		file;
  std::string		str = this->_objects[2]->getString();
  str.insert(0, "Res/Saves/");
  file.open(str.c_str(), std::fstream::in);
  if (!file.is_open())
    std::cerr << "open file failed" << std::endl;
  file >> *this;
  file.close();
}

void                    GameEngine::WriteScore(std::string const& i)
{
  this->score.AddScore(this->GameScore, i);
}


std::ostream&		operator<<(std::ostream& os, GameEngine const& s)
{
  Save                  save;
  save.ToFile(os, s);
  return os;
}

std::istream&		operator>>(std::istream& is, GameEngine& s)
{
  Save                  save;
  save.FromFile(is, s);
  return is;
}
