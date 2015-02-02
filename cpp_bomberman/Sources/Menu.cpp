//
// Menu.cpp for  in /home/peyrot_m/Restart_bomber/Sources
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Fri Jun  6 00:52:34 2014 peyrot_m
// Last update Sun Jun 15 21:52:45 2014 theron
// Last update Sun Jun 15 17:14:43 2014 theron
//

#include "Menu.hh"
#include "SoundManager.hh"

Menu::Menu(std::vector<gdl::Texture*> const &_text)
{
  this->_texture = _text;
  this->name = "AAA";
  this->_play = false;
  this->_credit = false;
  this->_score = false;
  this->_load = false;
  this->_end = false;
  this->_start = false;
  this->_reset = false;
  this->_delete = false;
  this->saveIndex = 0;
  this->_objs.push_back(1);
  this->_objs.push_back(0);
  this->_objs.push_back(50);
  this->_objs.push_back(20);
  this->_objs.push_back(20);
  this->_objs.push_back(1);
  this->_objs.push_back(1);
  this->_objs.push_back(0);
  this->_objs.push_back(0);
  this->_objs.push_back(0);
}

Menu::~Menu()
{
}

bool	Menu::initialize(float x, float y, float z,
			 float size_x, float size_y, __attribute__((unused)) float size_z)
{
  _geometry.pushVertex(glm::vec3(x, y, z));
  _geometry.pushVertex(glm::vec3(x, y + size_y, z));
  _geometry.pushVertex(glm::vec3(x + -size_x, y + size_y, z));
  _geometry.pushVertex(glm::vec3(x + -size_x, y, z));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.build();
  return (true);
}


/*
 * application des differents par rapport au menu correspondant
 */
void	Menu::update(__attribute__((unused))gdl::Clock const &clock,
		      __attribute__((unused))gdl::Input &input)
{
  if (_objs[8] == 0)
    {
      if (!this->_play && !this->_load && !this->_score && !this->_credit)
	this->UpdateMenuMenu(clock,input);
      if (this->_play)
	this->UpdateMenuPlay(clock,input);
      if (this->_load)
	this->UpdateMenuLoad(clock,input);
      if (this->_score)
	this->UpdateMenuScore(clock,input);
      if (this->_credit)
	this->UpdateMenuCredit(clock,input);
    }
  else if (_objs[8] == 1)
    this->UpdateMenuPause(clock,input);
  else if (_objs[8] == 3)
    this->UpdateMenuLose(clock,input);
  else if (_objs[8] == 2)
    this->UpdateMenuWin(clock,input);
}

void                    Menu::UpdateMenuMenu(__attribute__((unused))gdl::Clock const &clock,
					     __attribute__((unused))gdl::Input &input)
{
  _objs[9] = 0;
  this->pos = input.getMousePosition();
  takescore = false;
  SaveGet = false;
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      if (pos[0] > 154 && pos[0] < 400 && pos[1] > 274 && pos[1] < 354)
        _play = true;
      if (pos[0] > 15 && pos[0] < 552 && pos[1] > 399 && pos[1] < 481)
        _load = true;
      if (pos[0] > 84 && pos[0] < 456 && pos[1] > 531 && pos[1] < 612)
        _score = true;
      if (pos[0] > 20 && pos[0] < 249 && pos[1] > 855 && pos[1] < 945)
	_objs[7] = 1;
      if (pos[0] > 1041 && pos[0] < 1279 && pos[1] > 890 && pos[1] < 950)
	{
	  _credit = true;
	  SoundManager::shared()->playSound(FANFARE);
	}
      this->sleep.xusleep(250000);
    }
  if (input.getKey(SDLK_ESCAPE))
    _objs[7] = 1;
}

void                    Menu::UpdateMenuPlay(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
  this->pos = input.getMousePosition();
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      SoundManager::shared()->playSound(CLICK);
      if (_objs[0] == 0)
	++_objs[0];
      if (pos[0] > 0 && pos[0] < 209 && pos[1] > 0 && pos[1] < 69)
        _play = false;
      if (pos[0] > 57 && pos[0] < 88 && pos[1] > 175 && pos[1] < 208)
        if (_objs[0] > 1 && _objs[0] <= 15)
	  _objs[0] -= 1;
      if (pos[0] > 242 && pos[0] < 273 && pos[1] > 175 && pos[1] < 208)
        {
	  if (_objs[0] >= 1 &&  _objs[0] <= 15)
	    _objs[0] += 1;
	  if (_objs[0] > 2)
	    {
	      if (_objs[3] > 20)
		_objs[3] = 20;
	      if (_objs[4] > 20)
		_objs[4] = 20;
	    }
	}
      if (pos[0] > 555 && pos[0] < 589 && pos[1] > 175 && pos[1] < 208)
        {
          if (_objs[1] > 0)
            _objs[1] -= 1;
        }
      if (pos[0] > 695 && pos[0] < 728 && pos[1] > 175 && pos[1] < 208)
        {
          if (_objs[1] < 500)
            _objs[1] += 1;
        }
      if (pos[0] > 950 && pos[0] < 980 && pos[1] > 108 && pos[1] < 143)
        {
          if (_objs[2] > 0)
            _objs[2] -= 1;
        }
      if (pos[0] > 1158 && pos[0] < 1190 &&  pos[1] > 108 && pos[1] < 143)
        {
          if (_objs[2] < 100)
	    _objs[2] += 1;
        }
      if (pos[0] > 950 && pos[0] < 980 && pos[1] > 231 && pos[1] < 263)
        {
          if (_objs[3] > 10)
            _objs[3] -= 1;
        }
      if (pos[0] > 1158 && pos[0] < 1190 && pos[1] > 231 && pos[1] < 263)
        {
	  if (_objs[0] <= 2)
	    {
	      if (_objs[3] < 1000)
		_objs[3] += 1;
	    }
	  else
	    {
	      _objs[3] += 1;
	      if (_objs[3] > 20)
		_objs[3] = 20;
	    }

        }
      if (pos[0] > 950 && pos[0] < 980 && pos[1] > 351 && pos[1] < 381)
        {
          if (_objs[4] > 10)
            _objs[4] -= 1;
        }
      if (pos[0] > 1158 && pos[0] < 1190 && pos[1] > 351 && pos[1] < 381)
        {
	  if (_objs[0] <= 2)
	    {
	      if (_objs[4] < 1000)
		_objs[4] += 1;
	    }
	  else
	    {
	      _objs[4] += 1;
	      if (_objs[4] > 20)
		_objs[4] = 20;
	    }
        }
      if (pos[0] > 169 && pos[0] < 370 && pos[1] > 469 && pos[1] < 673)
        _objs[5] = 1;
      if (pos[0] > 410 && pos[0] < 611 && pos[1] > 469 && pos[1] < 673)
	_objs[5] = 2;
      if (pos[0] > 644 && pos[0] < 847 && pos[1] > 469 && pos[1] < 673)
        _objs[5] = 3;
      if (pos[0] > 895 && pos[0] < 1096 && pos[1] > 469 && pos[1] < 673)
        _objs[5] = 4;
      if (pos[0] > 570 && pos[0] < 712 && pos[1] > 804 && pos[1] < 915)
        _objs[6] = 2;
      this->sleep.xusleep(250000);
    }
}

void                    Menu::UpdateMenuLoad(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
  this->pos = input.getMousePosition();
  if (!SaveGet)
    {
      this->Saves = this->save.GetSaves();
      this->maxIndex = this->save.getMax();
      SaveGet = true;
    }
 if (input.getKey(SDL_BUTTON_LEFT))
    {
      SoundManager::shared()->playSound(CLICK);
      if (pos[0] > 0 && pos[0] < 209 && pos[1] > 0 && pos[1] < 69)
        _load = false;
      if (pos[0] > 494 && pos[0] < 794 && pos[1] > 819 && pos[1] < 866 && this->maxIndex != 0)
        _objs[7] = 2;
      if ((pos[0] > 93 && pos[0] < 205 && pos[1] > 457 && pos[1] < 508) && this->maxIndex != 0)
        {
          --saveIndex;
          if (saveIndex == -1)
            saveIndex = maxIndex - 1;
        }
      if ((pos[0] > 1080 && pos[0] < 1201 && pos[1] > 457 && pos[1] < 508)
	  && this->maxIndex != 0)
        {
	  ++saveIndex;
	  if (saveIndex == maxIndex)
	    saveIndex = 0;
	}
      if (pos[0] > 579 && pos[0] < 705 && pos[1] > 627 && pos[1] < 659)
        _delete = true;
      this->sleep.xusleep(250000);
    }
}


void                    Menu::UpdateMenuScore(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
  this->pos = input.getMousePosition();
  if (!takescore)
    {
      this->Scores = this->score.GetScores();
      takescore = true;
    }
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      SoundManager::shared()->playSound(CLICK);
      if (pos[0] > 0 && pos[0] < 209 && pos[1] > 0 && pos[1] < 69)
        _score = false;
      if (pos[0] > 1141 && pos[0] < 1251 && pos[1] > 909 && pos[1] < 943)
        _reset = true;
      this->sleep.xusleep(250000);
    }
}
void                    Menu::UpdateMenuCredit(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
  this->pos = input.getMousePosition();
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      SoundManager::shared()->playSound(CLICK);
      if (pos[0] > 0 && pos[0] < 209 && pos[1] > 0 && pos[1] < 69)
        _credit = false;
      if (pos[0] > 14 && pos[0] < 188 && pos[1] > 378 && pos[1] < 584)
	SoundManager::shared()->playSound(DOVAN);
      if (pos[0] > 194 && pos[0] < 371 && pos[1] > 378 && pos[1] < 584)
	SoundManager::shared()->playSound(DURAND);
      if (pos[0] > 374 && pos[0] < 546 && pos[1] > 378 && pos[1] < 584)
	SoundManager::shared()->playSound(FONTAI);
      if (pos[0] > 554 && pos[0] < 728 && pos[1] > 378 && pos[1] < 584)
	SoundManager::shared()->playSound(LASTRU);
      if (pos[0] > 731 && pos[0] < 906 && pos[1] > 378 && pos[1] < 584)
	SoundManager::shared()->playSound(NGUYE);
      if (pos[0] > 914 && pos[0] < 1088 && pos[1] > 378 && pos[1] < 584)
	SoundManager::shared()->playSound(PEYROT);
      if (pos[0] > 1094 && pos[0] < 1265 && pos[1] > 378 && pos[1] < 584)
	SoundManager::shared()->playSound(THERON);
      this->sleep.xusleep(250000);
    }
}

void                    Menu::UpdateMenuPause(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
  this->pos = input.getMousePosition();
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      SoundManager::shared()->playSound(CLICK);
      if (pos[0] > 529 && pos[0] < 753 && pos[1] > 203 && pos[1] < 263)
	_objs[9] = 1;
      if (pos[0] > 555 && pos[0] < 726 && pos[1] > 451 && pos[1] < 510)
	_objs[9] = 2;
      if (pos[0] > 567 && pos[0] < 714 && pos[1] > 710 && pos[1] < 771)
	{
	  _objs[0] = 1;
	  _objs[1] = 0;
	  _objs[2] = 50;
	  _objs[3] = 20;
	  _objs[4] = 20;
	  _objs[5] = 1;
	  _objs[6] = 1;
	  _objs[7] = 0;
	  _objs[8] = 0;
	  _objs[9] = 3;
	  _play = false;
	  this->_play = false;
	  this->_credit = false;
	  this->_score = false;
	  this->_load = false;
	}
      this->sleep.xusleep(250000);
    }
}

void                    Menu::UpdateMenuLose(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
  this->pos = input.getMousePosition();
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      SoundManager::shared()->playSound(CLICK);
      if (input.getKey(SDL_BUTTON_LEFT))
	{
	  if (pos[0] > 0 && pos[0] < 1280 && pos[1] > 0 && pos[1] < 960)
	    _objs[7] = 3;
	}
      this->sleep.xusleep(250000);
    }
}

void                    Menu::UpdateMenuWin(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
  this->pos = input.getMousePosition();
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      SoundManager::shared()->playSound(CLICK);
      if (pos[0] > 565 && pos[0] < 721 && pos[1] > 653 && pos[1] < 725)
	{
	  _objs[7] = 3;
	  this->setString(this->name);
	}
      if (pos[0] > 582 && pos[0] < 604 && pos[1] > 545 && pos[1] < 567)
        {
          if (this->name[0] >= 'A' && this->name[0] < 'Z')
            this->name[0] += 1;
          else
            this->name[0] = 'A';
        }
      if (pos[0] > 632 && pos[0] < 654 && pos[1] > 545 && pos[1] < 567)
        {
          if (this->name[1] >= 'A' && this->name[1] < 'Z')
            this->name[1] += 1;
          else
            this->name[1] = 'A';
        }
      if (pos[0] > 682 && pos[0] < 704 && pos[1] > 545 && pos[1] < 567)
        {
          if (this->name[2] >= 'A' && this->name[2] < 'Z')
            this->name[2] += 1;
          else
            this->name[2] = 'A';
        }
      if (pos[0] > 582 && pos[0] < 604 && pos[1] > 601 && pos[1] < 623)
        {
          if (this->name[0] > 'A' && this->name[0] <= 'Z')
            this->name[0] -= 1;
          else
            this->name[0] = 'Z';
        }
      if (pos[0] > 632 && pos[0] < 654 && pos[1] > 601 && pos[1] < 623)
        {
          if (this->name[1] > 'A' && this->name[1] <= 'Z')
            this->name[1] -= 1;
          else
            this->name[1] = 'Z';
        }
      if (pos[0] > 682 && pos[0] < 704 && pos[1] > 601 && pos[1] < 623)
        {
          if (this->name[2] > 'A' && this->name[2] <= 'Z')
            this->name[2] -= 1;
          else
            this->name[2] = 'Z';
        }
      this->sleep.xusleep(250000);
    }
}



/*
 * Dessine les different menu principale
 */
void	Menu::draw(__attribute__((unused))gdl::AShader &shader,
		   __attribute__((unused)) gdl::Clock const &clock)
{
  glm::mat4	trans;

  trans = glm::rotate(glm::rotate(glm::translate(glm::mat4(1),glm::vec3(-3.6,4.45,0)),
				  180.0f,glm::vec3(1,0,0)),180.0f,glm::vec3(0,1,0));

  shader.bind();
  (void)clock;
  if (_objs[8] < 4)
    {
      glEnable (GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      if (_objs[8] == 0)
	{
	  if (!this->_play && !this->_load && !this->_score && !this->_credit)
	    _texture[0]->bind();
	  if (this->_play)
	    _texture[1]->bind();
	  if (this->_load)
	    _texture[2]->bind();
	  if (this->_score)
	    _texture[3]->bind();
	  if (this->_credit)
	    _texture[4]->bind();
	}
      else if (_objs[8] == 1)
      	_texture[5]->bind();
      else if (_objs[8] == 3)
      	_texture[6]->bind();
      else if (_objs[8] == 2)
      	_texture[7]->bind();

      shader.setUniform("color", glm::vec4(0, 0, 0, 1));
      _geometry.draw(shader, trans, GL_QUADS);
      if (_objs[8] == 0 && this->_play)
	this->DrawMenuPlay(shader, clock);
      if (_objs[8] == 0 && this->_score)
	this->DrawMenuScore(shader, clock);
      if (_objs[8] == 0 && this->_load)
	this->DrawMenuLoad(shader, clock);
      if (_objs[8] == 2)
	this->DrawMenuWin(shader, clock);
    }
}


void	Menu::DrawMenuPlay(__attribute__((unused))gdl::AShader &shader,
			   __attribute__((unused)) gdl::Clock const &clock)
{
  this->DrawNumber(shader, clock, _objs[0],220 * (9.2/1280),260 * (6.89/980));
  this->DrawNumber(shader, clock, _objs[1],640 * (9.2/1280),260 * (6.89/980));
  this->DrawNumber(shader, clock, _objs[2],1100 * (9.2/1280),200 * (6.89/980));
  this->DrawNumber(shader, clock, _objs[3],1100 * (9.2/1280),320 * (6.89/980));
  this->DrawNumber(shader, clock, _objs[4],1100 * (9.2/1280),420 * (6.89/980));
}

void	Menu::DrawMenuWin(__attribute__((unused))gdl::AShader &shader,
			   __attribute__((unused)) gdl::Clock const &clock)
{
  this->DrawLetter(shader, clock, name[0], 590 * (9.2/1280), 580 * (6.89/980));
  this->DrawLetter(shader, clock, name[1], 640 * (9.2/1280), 580 * (6.89/980));
  this->DrawLetter(shader, clock, name[2], 690 * (9.2/1280), 580 * (6.89/980));
}



void	Menu::DrawMenuScore(__attribute__((unused))gdl::AShader &shader,
			    __attribute__((unused)) gdl::Clock const &clock)
{
  std::list<ScoreElem*>::const_iterator itScore(Scores.begin());
  float                                 yMove = 260;
  int                                   i = 0;

  while (itScore != Scores.end() && i < 10)
    {
      this->DrawNumber(shader, clock,(*itScore)->getScoreInt(),
      		       420 * (9.2/1280),yMove * (6.89/980));

      this->DrawString(shader, clock, (*itScore)->getDate(),
      		       800 * (9.2/1280),yMove * (6.89/980));
      yMove += 70;
      ++itScore;
      ++i;
    }
  if (_reset == true)
    {
      this->save.xUnlink("./Res/Scores");
      _reset = false;
      this->sleep.xusleep(500000);
      this->Scores = this->score.GetScores();
    }
}

void	Menu::DrawMenuLoad(__attribute__((unused))gdl::AShader &shader,
			   __attribute__((unused)) gdl::Clock const &clock)
{
  std::stringstream     ss;

  this->my_string = this->Saves[this->saveIndex];
  if (this->my_string.compare("end") != 0)
    {
      std::istringstream stream(this->my_string);
      time_t timestamp;
      stream >> timestamp;
      struct tm *tm = localtime(&timestamp);
      char date[20];
      this->time.xstrftime(date, sizeof(date), "%a %d %b %R", tm);
      this->DrawString(shader, clock, date, 200 * (9.2/1280), 490 * (6.89/980));
    }
  else
    this->DrawString(shader, clock, "VOID",200 * (9.2/1280), 490 * (6.89/980));
  if (_delete == true)
    {
      std::string Path("./Res/Saves/");
      Path += this->my_string;
      this->save.xUnlink(Path);
      _delete = false;
      this->sleep.xusleep(500000);
      this->Saves = this->save.GetSaves();
    }
}


void	Menu::DrawNumber(__attribute__((unused))gdl::AShader &shader,
			 __attribute__((unused)) gdl::Clock const &clock,
			 int nb, float x, float y)
{
  AObject		*cube1 = new Carre();
  std::string		image = "./Res/textures/number/number_.tga";
  std::stringstream	ss;

  if (nb > 9)
    {
      this->DrawNumber(shader, clock, nb % 10, x, y);
      this->DrawNumber(shader, clock, nb / 10, x - (50 * (9.2/1280)), y);
    }
  else if (nb <= 9 && nb >= 0)
    {
      ss << nb;
      image.insert(image.size() - 4, ss.str());
      if (!cube1->initialize(-x,-y,0,9.2/30,6.89/30,0, image))
	throw MyException("initialize draw number");
      cube1->draw(shader, clock);
    }
  delete cube1;
}

void			Menu::DrawCursor(__attribute__((unused))gdl::AShader &shader,
					 __attribute__((unused)) gdl::Clock const &clock)
{
  AObject		*cube1 = new Carre();
  std::string		image = "./Res/textures/cursor.tga";
  if (!cube1->initialize(1.22 - ((float)pos[0] * (2.45/1280.00)),
			 3.9 - ((float)pos[1] * (1.85/960.00)),
			 -1.0001,0.09,0.09,0.8, image))
    throw MyException("initialize draw number");
  cube1->draw(shader, clock);
  delete cube1;
}


void			Menu::DrawLetter(__attribute__((unused))gdl::AShader &shader,
					 __attribute__((unused)) gdl::Clock const &clock,
					 char c, float x, float y)
{
  AObject               *cube1 = new Carre();
  std::string           image = "./Res/textures/letter/Letter_.tga";
  std::stringstream     ss;

  ss << c;
  image.insert(image.size() - 4, ss.str());
  if (image[image.size() - 5] >= '0' && image[image.size() - 5] <= '9')
    {
      DrawNumber(shader, clock, image[image.size() - 5] - 48, x, y);
      delete cube1;
      return ;
    }
  if (image[image.size() - 5] == ':')
    image[image.size() - 5] = 'h';
  if (image[image.size() - 5] != ' ')
    {
      if (image[image.size() - 5] >= 'a' && image[image.size() - 5] <= 'z')
        image[image.size() - 5] -= 32;
      if (!cube1->initialize(-x,-y,0,9.2/30,6.89/30,0, image))
	throw MyException("initialize draw number");
      cube1->draw(shader, clock);
    }
  delete cube1;

}


void                    Menu::DrawString(__attribute__((unused))gdl::AShader &shader, __attribute__((unused)) gdl::Clock const &clock, std::string const& c, float x, float y)
{
  unsigned int          i = 0;
  float                 to = 50 * (9.2/1280);

  while (i < c.size())
    {
      if (c[i] != ' ')
        {
          this->DrawLetter(shader,clock, c[i], x + to, y);
          to += 50 * (9.2/1280);
        }
      ++i;
    }
}


std::vector<int>	Menu::getObjs() const
{
  return (this->_objs);
}

void			Menu::setObjs(int const i)
{
  if (i == 4)
    this->_objs[9] = 0;
  else if (i < 4)
    this->_objs[8] = i;
  else if (i == 5)
    {
      _objs[0] = 1;
      _objs[1] = 0;
      _objs[2] = 50;
      _objs[3] = 20;
      _objs[4] = 20;
      _objs[5] = 1;
      _objs[6] = 1;
      _objs[7] = 0;
      _objs[8] = 0;
      _objs[9] = 3;
      _play = false;
      this->_play = false;
      this->_credit = false;
      this->_score = false;
      this->_load = false;
    }
}

bool		Menu::getCredit() const
{
  return (this->_credit);
}
