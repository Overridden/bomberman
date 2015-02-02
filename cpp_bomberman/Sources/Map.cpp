//
// Map.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Tue May 13 14:29:49 2014 Noel DOVAN
// Last update Sun Jun 15 20:49:51 2014 theron
//

#include "Map.hh"
#include "SoundManager.hh"

Map::Map() : _x(1), _y(1),
	     _coeff(1), _time(0)
{
}

Map::Map(int const width, int const height, int const madness)
  : _width(width), _height(height), _madness(madness), _name('R'), _x(1), _y(1),
    _coeff(1), _time(0)
{
  int           i(-1), j(-1);
  std::string   str, str2;
  while (++i < this->_width)
    str += "2";
  str += "\0";
  i = -1;
  this->map.push_back(str);
  while (++i < this->_height - 2)
    {
      j = -1;
      str2.clear();
      str2 += "2";
      while (++j < this->_width - 2)
	if (this->rand.randVal(100) < this->_madness)
	  {
	    if (this->rand.randVal(100) < HARD_WALL)
	      str2 += "2";
	    else
	      str2 += "1";
	  }
	else
	  str2 += "0";
      str2 += "2";
      str2 += "\0";
      this->map.push_back(str2);
    }
  this->map.push_back(str);
  this->_width = this->GetMapWidth();
  this->_height = this->GetMapHeight();
  this->initPrediction();
  this->initObject();
  this->initPlayer();
}

Map::Map(char const id):  _x(1), _y(1),
                          _coeff(1), _time(0)
{
  if (id == 'A')
    {
      parseMap((char*)"./Res/Map/map_A.map");
      this->_name = 'A';
    }
  if (id == 'B')
    {
      parseMap((char*)"./Res/Map/map_B.map");
      this->_name = 'B';
    }
  if (id == 'C')
    {
      parseMap((char*)"./Res/Map/map_C.map");
      this->_name = 'C';
    }
  this->_width = this->GetMapWidth();
  this->_height = this->GetMapHeight();
  this->_madness = 0;
  this->initPrediction();
  this->initObject();
  this->initPlayer();
}

Map&			Map::operator=(Map const& o)
{
  this->_width = o.getWidth();
  this->_height = o.getHeight();
  this->_madness = o.getMadness();
  this->_name = o.getName();
  this->map = o.getMap();
  this->map_prediction = o.getPrediction();
  this->map_object = o.getObject();
  this->map_player = o.getPlayer();
  return *this;
}

Map::~Map()
{
  while (!this->map.empty())
    this->map.pop_back();
  while (!this->map_prediction.empty())
    this->map_prediction.pop_back();
  while (!this->map_object.empty())
    this->map_object.pop_back();
  while (!this->map_player.empty())
    this->map_player.pop_back();
  while (!this->Bombes.empty())
    this->Bombes.pop_back();
}

void			Map::AddBombe(int const force, int const x, int const y, std::string const& name, bool const frisbee)
{
  int			i = 0;
  bool			w1 = false, w2 = false, w3 = false, w4 = false;

  this->Bombes.push_back(new Bombe(force, x, y, name, frisbee));
  if (frisbee)
    this->objectSetValueAt('7', x, y);
  else
    this->objectSetValueAt('4', x, y);
  this->predictionSetValueAt('1', x, y);
  while (++i < force)
    {
      this->AddBombeDir(w1, x, y - i, frisbee);
      this->AddBombeDir(w2, x + i, y, frisbee);
      this->AddBombeDir(w3, x, y + i, frisbee);
      this->AddBombeDir(w4, x - i, y, frisbee);
    }
}

void			Map::AddBombeDir(bool& w, int const x, int const y, bool const frisbee)
{
  char			v;

  if (!w)
    {
      if ((v = this->mapGetValueAt(x, y)) != '2')
	this->predictionSetValueAt('1', x, y);
      if ((!frisbee && v == '1') || v == '2')
	w = true;
    }
}

void			Map::ExplodeBombe(Bombe* bombe, std::list<Character*>& players, int& gameScore)
{
  int			i = 0;
  bool			w1 = false, w2 = false, w3 = false, w4 = false;
  int			x = bombe->getX(), y = bombe->getY();

  if (this->playerGetValueAt(x, y) != '0')
    this->ExplodePlayerAt(x, y, players, gameScore);
  if (bombe->getFrisbee())
    this->objectSetValueAt('8', x, y);
  else
    this->objectSetValueAt('5', x, y);
  this->predictionSetValueAt('0', x, y);
  while (++i < bombe->getForce())
    {
      this->ExplodeBombeDir(w1, x, y - i, players, gameScore, bombe);
      this->ExplodeBombeDir(w2, x + i, y, players, gameScore, bombe);
      this->ExplodeBombeDir(w3, x, y + i, players, gameScore, bombe);
      this->ExplodeBombeDir(w4, x - i, y, players, gameScore, bombe);
    }
}

void			Map::ExplodeBombeDir(bool& w, int const x, int const y,
					     std::list<Character*>& players,
					     int& gameScore, Bombe* bombe)
{
  char			v;
  char			val;

  if (!w)
    {
      if ((v = this->mapGetValueAt(x, y)) != '2')
	{
      	  if ((val = this->objectGetValueAt(x, y)) == '4' ||
	      val == '7')
      	    this->ExplodeBombAt(x, y);
	  if (this->playerGetValueAt(x, y) != '0')
            this->ExplodePlayerAt(x, y, players, gameScore);
	  if (bombe->getFrisbee())
	    this->objectSetValueAt('8', x, y);
	  else
	    this->objectSetValueAt('5', x, y);
      	  this->predictionSetValueAt('0', x, y);
	}
      if ((!bombe->getFrisbee() && v == '1') || v == '2')
	w = true;
    }
}

void			Map::ExplodeBombAt(int const x, int const y)
{
  std::list<Bombe*>::iterator	it(this->Bombes.begin());

  while (it != this->Bombes.end())
    {
      if ((*it)->getX() == x && (*it)->getY() == y)
	{
	  (*it)->doExplode();
	  return ;
	}
      ++it;
    }
}

void			Map::ExplodePlayerAt(int const x, int const y, std::list<Character*>& players, int& gameScore)
{
  std::list<Character*>::iterator       it(players.begin());
  while (it != players.end())
    {
      if ((int)(*it)->getX() == x && (int)(*it)->getY() == y)
        {
	  SoundManager::shared()->playSound(DIE);
	  (*it)->RemoveLife();
	  if ((*it)->getID() == 4)
	    gameScore += 500;
	  else
	    gameScore += 100;
	}
      ++it;
    }
}

void			Map::RemoveBombe(Bombe* bombe, int& gameScore)
{
  int			i = 0;
  int			x = bombe->getX(), y = bombe->getY();

  this->objectSetValueAt('0', x, y);
  while (++i < bombe->getForce())
    {
      this->RemoveBombeDir(gameScore, x, y - i);
      this->RemoveBombeDir(gameScore, x + i, y);
      this->RemoveBombeDir(gameScore, x, y + i);
      this->RemoveBombeDir(gameScore, x - i, y);
    }
}

void			Map::RemoveBombeDir(int& gameScore, int const x, int const y)
{
  char			ret;

  if ((ret = this->objectGetValueAt(x, y)) == '5' || ret == '8')
    {
      this->objectSetValueAt('0', x, y);
      if (this->mapGetValueAt(x, y) == '1')
	{
	  gameScore += 10;
	  this->mapSetValueAt('0', x, y);
	  if (this->rand.randVal(100) < BONUS_PERCENTAGE)
	    this->SpawnBonus(x, y);
	}
    }
}

void			Map::SpawnBonus(int const x, int const y)
{
  int			r = this->rand.randVal(3);
  if (r == 0)
    this->SpawnBonusFrisbee('1', x, y);
  else if (r == 1)
    this->SpawnBonusFrisbee('2', x, y);
  else
    this->SpawnBonusFrisbee('3', x, y);
}

void			Map::SpawnBonusFrisbee(char const value, int const x, int const y)
{
  if (this->rand.randVal(100) > FRISBEE_PERCENTAGE)
    this->objectSetValueAt(value, x, y);
  else
    this->objectSetValueAt('6', x, y);
}

void			Map::UpdateBombes(int& gameScore, gdl::Clock& clock,
					  std::list<Character*>& players)
{
  std::list<Bombe*>::iterator	it(this->Bombes.begin());

  while (it != this->Bombes.end())
    {
      if (!(*it)->getExploded())
	{
	  if ((*it)->CheckBombe(clock.getElapsed()))
	    {
	      this->ExplodeBombe(*it, players, gameScore);
	      this->RemoveBombByName(players, (*it)->getName());
	    }
	  ++it;
	}
      else
	{
	  if ((*it)->CheckExplosion(clock.getElapsed()))
	    {
	      this->RemoveBombe(*it, gameScore);
	      it = this->Bombes.erase(it);
	    }
	  else
	    ++it;
	}
    }
}

void			Map::RemoveBombByName(std::list<Character*>& players,
					      std::string const& name) const
{
  std::list<Character*>::const_iterator it(players.begin());

  while (it != players.end())
    {
      if ((*it)->getName() == name)
        {
	  (*it)->RemoveBombe();
	  return ;
	}
      ++it;
    }
}

void			Map::parseMap(char* const name)
{
  std::ifstream		file(name);
  std::string		line;
  std::string		str;

  if (file.is_open())
    {
      int		end(0);
      int		back(0);
      int		j(0);

      while (getline(file, line))
	{
	  if (j == 0)
	    back = line.length();
	  ++j;
	}
      end = j;
      file.clear();
      line.clear();
      j = 0;
      if (file.seekg(0, std::ios::beg))
        while (getline(file, line))
	  {
	    str.clear();
	    if (j == 0 || j == end - 1)
	      {
	        for (int i(-1) ; i < back - 1 ; ++i)
		  str += '2';
	      }
	    else
	      {
		unsigned int x(0);

		if (line.length() == (unsigned)back)
		  while (x < line.length())
		    {
		      if (x == 0 || x == line.length() - 1 || line.at(x) == '2')
			str += '2';
		      else if (line.at(x) == '1')
			str += '1';
		      else
			str += '0';
		      ++x;
		    }
		else
		  {
		    while (x < (unsigned)back)
		      {
			if (x == 0 || x == (unsigned)back - 1)
			  str += '2';
			else
			  str += '0';
			++x;
		      }
		  }
	      }
	    this->map.push_back(str);
	    ++j;
	  }
      file.close();
    }
}

void                    Map::closeMap(gdl::Clock& clock)
{
  this->_time += clock.getElapsed();
  if (this->_time >= 0.5)
    {
      if (this->_x < this->getWidth() - this->_coeff
          && this->_y == this->_coeff)
        {
          this->mapSetValueAt('2', this->_x, this->_y);
          ++this->_x;
        }
      if (this->_y < this->getHeight() - this->_coeff
          && this->_x == this->getWidth() - this->_coeff)
        {
          this->mapSetValueAt('2', this->_x - 1, this->_y);
          ++this->_y;
        }

      if (this->_x >= this->_coeff && this->_y == this->getHeight() - this->_coeff)
        {
          this->mapSetValueAt('2', this->_x, this->_y - 1);
          --this->_x;
        }
      if (this->_y >= this->_coeff && this->_x == this->_coeff)
        {
          this->mapSetValueAt('2', this->_x, this->_y);
          --this->_y;
        }
      if (this->_y == this->_coeff && this->_x == this->_coeff)
        {
          this->_y += 1;
          this->_x += 1;
          ++this->_coeff;
        }
      this->_time = 0;
    }
}

int			Map::GetMapWidth() const
{
  std::list<std::string>::const_iterator	itMap(this->map.begin());
  return (*itMap).size();
}

int			Map::GetMapHeight() const
{
  std::list<std::string>::const_iterator	itMap(this->map.begin());
  int						line = 0;
  while (itMap != this->map.end())
    {
      ++line;
      ++itMap;
    }
  return line;
}

std::list<std::string> const &	Map::getMap() const
{
  return (this->map);
}

void			Map::ShowMap() const
{
  std::list<std::string>::const_iterator	itMap(this->map.begin());
  while (itMap != this->map.end())
    {
      std::cout << *itMap << std::endl;
      ++itMap;
    }
}

void			Map::updateMap(unsigned int const x, unsigned int const y)
{
  if (mapGetValueAt(x, y) == 1)
    mapSetValueAt(0, x, y);
}

char			Map::mapGetValueAt(int const x, int const y) const
{
  std::list<std::string>::const_iterator	itMap(this->map.begin());
  int						i(0);
  char						ret;

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ('Z');
  while (itMap != this->map.end())
    {
      if (i == y)
        {
          ret = (*itMap)[x];
          break;
        }
      ++i;
      ++itMap;
    }
  return (ret);
}

void			Map::mapSetValueAt(char const value, int const x, int const y)
{
  std::list<std::string>::iterator      itMap(this->map.begin());
  int                                   i(0);

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ;
  while (itMap != this->map.end())
    {
      if (i == y)
        {
          (*itMap)[x] = value;
          break;
        }
      ++i;
      ++itMap;
    }
}

/*	Prediction	*/

void			Map::initPrediction()
{
  int			i(-1);
  std::string		str;

  while (++i < this->_width)
    str += "0";
  str += "\0";
  i = -1;
  while (++i < this->_height)
    this->map_prediction.push_back(str);
}

std::list<std::string> const &	Map::getPrediction() const
{
  return (this->map_prediction);
}

void			Map::ShowPrediction() const
{
  std::list<std::string>::const_iterator itPrediction(this->map_prediction.begin());
  while (itPrediction != this->map_prediction.end())
    {
      std::cout << *itPrediction << std::endl;
      ++itPrediction;
    }
}

void			Map::updatePrediction(unsigned int const x, unsigned int const y)
{
  if (predictionGetValueAt(x, y) == 1)
    predictionSetValueAt(0, x, y);
}

char			Map::predictionGetValueAt(int const x, int const y) const
{
  std::list<std::string>::const_iterator	itPrediction(this->map_prediction.begin());
  int						i(0);
  char						ret;

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ('Z');
  while (itPrediction != this->map_prediction.end())
    {
      if (i == y)
        {
          ret = (*itPrediction)[x];
          break;
        }
      ++i;
      ++itPrediction;
    }
  return (ret);
}

void			Map::predictionSetValueAt(char const value, int const x, int const y)
{
  std::list<std::string>::iterator      itPrediction(this->map_prediction.begin());
  int                                   i(0);

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ;
  while (itPrediction != this->map_prediction.end())
    {
      if (i == y)
        {
          (*itPrediction)[x] = value;
          break;
        }
      ++i;
      ++itPrediction;
    }
}

/*	player	*/

void			Map::initPlayer()
{
  int			i(-1);
  std::string		str;

  while (++i < this->_width)
    str += "0";
  str += "\0";
  i = -1;
  while (++i < this->_height)
    this->map_player.push_back(str);
}

std::list<std::string> const &	Map::getPlayer() const
{
  return (this->map_player);
}

void			Map::ShowPlayer() const
{
  std::list<std::string>::const_iterator itPlayer(this->map_player.begin());
  while (itPlayer != this->map_player.end())
    {
      std::cout << *itPlayer << std::endl;
      ++itPlayer;
    }
}

void			Map::updatePlayer(unsigned int const x, unsigned int const y)
{
  if (playerGetValueAt(x, y) == 1)
    playerSetValueAt(0, x, y);
}

char			Map::playerGetValueAt(int const x, int const y) const
{
  std::list<std::string>::const_iterator	itPlayer(this->map_player.begin());
  int						i(0);
  char						ret;

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ('Z');
  while (itPlayer != this->map_player.end())
    {
      if (i == y)
        {
          ret = (*itPlayer)[x];
          break;
        }
      ++i;
      ++itPlayer;
    }
  return (ret);
}

void			Map::playerSetValueAt(char const value, int const x, int const y)
{
  std::list<std::string>::iterator itPlayer(this->map_player.begin());
  int                              i(0);

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ;
  while (itPlayer != this->map_player.end())
    {
      if (i == y)
        {
          (*itPlayer)[x] = value;
          break;
        }
      ++i;
      ++itPlayer;
    }
}

/*	object	*/

void			Map::initObject()
{
  int			i(-1);
  std::string		str;

  while (++i < this->_width)
    str += "0";
  str += "\0";
  i = -1;
  while (++i < this->_height)
    this->map_object.push_back(str);
}

std::list<std::string> const &	Map::getObject() const
{
  return (this->map_object);
}

void			Map::ShowObject() const
{
  std::list<std::string>::const_iterator itObject(this->map_object.begin());
  while (itObject != this->map_object.end())
    {
      std::cout << *itObject << std::endl;
      ++itObject;
    }
}

void			Map::updateObject(unsigned int const x, unsigned int const y)
{
  if (objectGetValueAt(x, y) == 1)
    objectSetValueAt(0, x, y);
}

char			Map::objectGetValueAt(int const x, int const y) const
{
  std::list<std::string>::const_iterator	itObject(this->map_object.begin());
  int						i(0);
  char						ret;

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ('Z');
  while (itObject != this->map_object.end())
    {
      if (i == y)
        {
          ret = (*itObject)[x];
          break;
        }
      ++i;
      ++itObject;
    }
  return (ret);
}

void			Map::objectSetValueAt(char const value, int const x, int const y)
{
  std::list<std::string>::iterator	itObject(this->map_object.begin());
  int					i(0);

  if (x < 0 || x > this->_width || y < 0 || y > this->_height)
    return ;
  while (itObject != this->map_object.end())
    {
      if (i == y)
        {
          (*itObject)[x] = value;
          break;
        }
      ++i;
      ++itObject;
    }
}

int			Map::getWidth() const
{
  return (this->_width);
}

int			Map::getHeight() const
{
  return (this->_height);
}

int			Map::getMadness() const
{
  return (this->_madness);
}

char			Map::getName() const
{
  return (this->_name);
}

void			Map::setWidth(int const width)
{
  this->_width = width;
}

void			Map::setHeight(int const height)
{
  this->_height = height;
}

void			Map::setMadness(int const madness)
{
  this->_madness = madness;
}

void			Map::setName(char const name)
{
  this->_name = name;
}

void			Map::Reset()
{
  this->_width = 0;
  this->_height = 0;
  this->_madness = 0;
  this->_name = 'A';
  this->_time = 0;
  this->_x = 1;
  this->_y = 1;
  this->_coeff = 1;
  while (!this->map.empty())
    this->map.pop_back();
  while (!this->map_prediction.empty())
    this->map_prediction.pop_back();
  while (!this->map_object.empty())
    this->map_object.pop_back();
  while (!this->map_player.empty())
    this->map_player.pop_back();
  while (!this->Bombes.empty())
    {
      delete this->Bombes.back();
      this->Bombes.pop_back();
    }
}

void			Map::SetMapList(std::list<std::string> const& map,
					std::list<std::string> const& mapObj,
					std::list<std::string> const& mapPla)
{
  this->initPrediction();
  std::list<std::string>::const_iterator	itMap(map.begin()), itObj(mapObj.begin()), itPla(mapPla.begin());
  while (itMap != map.end())
    {
      this->map.push_back(*itMap);
      this->map_object.push_back(*itObj);
      this->map_player.push_back(*itPla);
      ++itMap;
      ++itObj;
      ++itPla;
    }
}
