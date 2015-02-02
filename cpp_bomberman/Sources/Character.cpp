//
// Character.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Wed May 14 13:00:39 2014 Noel DOVAN
// Last update Sun Jun 15 22:40:17 2014 Noel DOVAN
//

#include "Character.hh"
#include "SoundManager.hh"

Character::Character(int const id, Map& map, Rand& rand,
		     std::string const& name, int const type) : ID(id), Name(name), Life(1),
						Force(3), Speed(SPEED), Max(1),
						Used(0), OnBomb(false), BombX(0),
								BombY(0), cmp(0), _type(type), Frisbee(false)
{
  if (this->ID == 4)
    {
      SoundManager::shared()->playSound(BOSS);
      this->Life = 3;
      this->Force = 10;
      this->Speed = SPEED * 2;
      this->Max = 3;
    }
  this->InitCharacterPos(map, rand);
}

Character::Character(int const id, std::string const& name, int const life,
		     int const force, float const& speed, int const max,
		     int const used, int const x, int const y, float const& __x,
		     float const& __y, bool const frisbee, int const type) : ID(id), Name(name), Life(life),
									     Force(force), Speed(speed), Max(max),
									     Used(used), X(x), Y(y), _x(__x), _y(__y),
									     OnBomb(false), BombX(0), BombY(0), cmp(0),
									     _type(type), Frisbee(frisbee)
{
}

Character::~Character()
{
}

void			Character::InitCharacterPos(Map& map, Rand& rand)
{
  int			x;
  int			y;
  bool			ok = false;

  while (!ok)
    {
      x = rand.randVal(1, map.getWidth());
      y = rand.randVal(1, map.getHeight());
      if (map.mapGetValueAt(x, y) != '2' && (this->ID == 1 || this->ID == 2))
	{
	  this->_x = x;
	  this->_y = y;
	  this->X = x;
	  this->Y = y;
	  if (this->ID == 1)
	    map.playerSetValueAt('1', x, y);
	  else
	    map.playerSetValueAt('2', x, y);
	  map.mapSetValueAt('0', x, y);
	  if (map.mapGetValueAt(x + 1, y) != '2')
	    map.mapSetValueAt('0', x + 1, y);
	  if (map.mapGetValueAt(x - 1, y) != '2')
	    map.mapSetValueAt('0', x - 1, y);
	  if (map.mapGetValueAt(x, y + 1) != '2')
	    map.mapSetValueAt('0', x, y + 1);
	  if (map.mapGetValueAt(x, y - 1) != '2')
	    map.mapSetValueAt('0', x, y - 1);
	  ok = true;
	}
      else if (map.mapGetValueAt(x, y) != '2' && (this->ID == 3 || this->ID == 4))
	{
	  this->_x = x;
	  this->_y = y;
	  this->X = x;
	  this->Y = y;
	  if (this->ID == 3)
	    map.playerSetValueAt('3', x, y);
	  else
	    map.playerSetValueAt('4', x, y);
	  map.mapSetValueAt('0', x, y);
	  if (map.mapGetValueAt(x + 1, y) != '2')
	    map.mapSetValueAt('0', x + 1, y);
	  if (map.mapGetValueAt(x - 1, y) != '2')
	    map.mapSetValueAt('0', x - 1, y);
	  if (map.mapGetValueAt(x, y + 1) != '2')
	    map.mapSetValueAt('0', x, y + 1);
	  if (map.mapGetValueAt(x, y - 1) != '2')
	    map.mapSetValueAt('0', x, y - 1);
	  ok = true;
	}
    }
}

void			Character::moveIA(Map &_map, gdl::Clock &clock)
{
  int			u = 0;
  int			d = 0;
  int			l = 0;
  int			r = 0;
  char			tmp;

  if ((tmp = _map.predictionGetValueAt(this->X, this->Y)) == '0')
  {
    u = this->checkMapValue(_map, u, this->X, this->Y - 1, 0);
    d = this->checkMapValue(_map, d, this->X, this->Y + 1, 0);
    l = this->checkMapValue(_map, l, this->X - 1, this->Y, 0);
    r = this->checkMapValue(_map, r, this->X + 1, this->Y, 0);

    u = this->checkPreValue(_map, u, this->X, this->Y - 1, 0);
    d = this->checkPreValue(_map, d, this->X, this->Y + 1, 0);
    l = this->checkPreValue(_map, l, this->X - 1, this->Y, 0);
    r = this->checkPreValue(_map, r, this->X + 1, this->Y, 0);

    u = this->checkObjValue(_map, u, this->X, this->Y - 1, 0);
    d = this->checkObjValue(_map, d, this->X, this->Y + 1, 0);
    l = this->checkObjValue(_map, l, this->X - 1, this->Y, 0);
    r = this->checkObjValue(_map, r, this->X + 1, this->Y, 0);

    u = this->checkPlaValue(_map, u, this->X, this->Y - 1, 0);
    d = this->checkPlaValue(_map, d, this->X, this->Y + 1, 0);
    l = this->checkPlaValue(_map, l, this->X - 1, this->Y, 0);
    r = this->checkPlaValue(_map, r, this->X + 1, this->Y, 0);
  }
  else if (tmp == '1' || _map.objectGetValueAt(this->X, this->Y) == '4'
	   || _map.objectGetValueAt(this->X, this->Y) == '7')
  {
    u = this->checkMapValue(_map, u, this->X, this->Y - 1, 1);
    d = this->checkMapValue(_map, d, this->X, this->Y + 1, 1);
    l = this->checkMapValue(_map, l, this->X - 1, this->Y, 1);
    r = this->checkMapValue(_map, r, this->X + 1, this->Y, 1);

    u = this->checkPreValue(_map, u, this->X, this->Y - 1, 1);
    d = this->checkPreValue(_map, d, this->X, this->Y + 1, 1);
    l = this->checkPreValue(_map, l, this->X - 1, this->Y, 1);
    r = this->checkPreValue(_map, r, this->X + 1, this->Y, 1);

    u = this->checkObjValue(_map, u, this->X, this->Y - 1, 1);
    d = this->checkObjValue(_map, d, this->X, this->Y + 1, 1);
    l = this->checkObjValue(_map, l, this->X - 1, this->Y, 1);
    r = this->checkObjValue(_map, r, this->X + 1, this->Y, 1);

    u = this->checkPlaValue(_map, u, this->X, this->Y - 1, 1);
    d = this->checkPlaValue(_map, d, this->X, this->Y + 1, 1);
    l = this->checkPlaValue(_map, l, this->X - 1, this->Y, 1);
    r = this->checkPlaValue(_map, r, this->X + 1, this->Y, 1);
  }
  this->chooseWhereToGo(_map, u, d, l, r, clock);
}

int			Character::checkMapValue(Map &_map, int i, int x, int y,
						 int state)
{
  char			tmp;

  if (i != -1)
  {
    if (state == 0)
    {
      if ((tmp = _map.mapGetValueAt(x, y)) == '2')
	i = -1;
      else if (tmp == '1')
	i += 10;
      else
	i += 2;
    }
    else if (state == 1)
    {
      if ((tmp = _map.mapGetValueAt(x, y)) == '2')
	i = -1;
      else if (tmp == '1')
	i += 0;
      else
	i += 10;
    }
  }
  return (i);
}

int			Character::checkPreValue(Map &_map, int i, int x, int y,
						 int state)
{
  char			tmp;

  if (i != -1)
  {
    if (state == 0)
    {
      if ((tmp = _map.predictionGetValueAt(x, y)) == '1')
	i = -1;
      else
	i += 0;
    }
    else if (state == 1)
    {
      if ((tmp = _map.predictionGetValueAt(x, y)) == '1')
	i += 0;
      else
	i += 10;
    }
  }
  return (i);
}

int			Character::checkObjValue(Map &_map, int i, int x, int y,
						 int state)
{
  char			tmp;

  if (i != -1)
  {
    if (state == 0)
    {
      if ((tmp = _map.objectGetValueAt(x, y)) == '4' || tmp == '5' ||
	  tmp == '7' || tmp == '8')
	i = -1;
      else if (tmp >= '1' || tmp <= '3' || tmp == '6')
	i += 10;
      else
	i += 0;
    }
    else if (state == '1')
    {
      if ((tmp = _map.objectGetValueAt(x, y)) == '4' || tmp == '5' ||
	  tmp == '7' || tmp == '8')
	i = -1;
      else if (tmp >= '1' || tmp <= '3' || tmp == '6')
	i += 2;
      else
	i += 10;
    }
  }
  return (i);
}

int			Character::checkPlaValue(Map &_map, int i, int x, int y,
						 int state)
{
  if (i != -1)
  {
    if (state == 0)
    {
      if (_map.playerGetValueAt(x, y) > '0')
	i += 10;
      else
	i += 2;
    }
    else if (state == 1)
    {
      if (_map.playerGetValueAt(x, y) > '0')
	i += 0;
      else
	i += 10;
    }
  }
  return (i);
}

void			Character::chooseWhereToGo(Map &_map, int u, int d, int l,
						   int r, gdl::Clock &clock)
{
    int			res = 0;
  boost::rand48	gen(time(NULL));
  boost::uniform_int<> dist(1, 1000);
  boost::variate_generator<boost::rand48&, boost::uniform_int<> > doran(gen, dist);

  res = doran();
  if (res <= 250)
  {
    if (u >= d && u >= l && u >= r)
      this->doWhatIA(_map, 0, -1, clock);
    else if (d >= u && d >= l && d >= r)
      this->doWhatIA(_map, 0, 1, clock);
    else
    {
      if (l >= u && l >= d && l >= r)
	this->doWhatIA(_map, 1, -1, clock);
      else if (r >= u && r >= d && r >= l)
	this->doWhatIA(_map, 1, 1, clock);
    }
  }
  else if (res <= 500 && res > 250)
  {
    if (l >= u && l >= d && l >= r)
      this->doWhatIA(_map, 1, -1, clock);
    else if (r >= u && r >= d && r >= l)
      this->doWhatIA(_map, 1, 1, clock);
    else
    {
      if (u >= d && u >= l && u >= r)
	this->doWhatIA(_map, 0, -1, clock);
      else if (d >= u && d >= l && d >= r)
	this->doWhatIA(_map, 0, 1, clock);
    }
  }
  else
  {
    if (res <= 750 && res > 500)
    {
      if (d >= u && d >= l && d >= r)
	this->doWhatIA(_map, 0, 1, clock);
      else if (u >= d && u >= l && u >= r)
	this->doWhatIA(_map, 0, -1, clock);
      else
      {
	if (r >= u && r >= d && r >= l)
	  this->doWhatIA(_map, 1, 1, clock);
	else if (l >= u && l >= d && l >= r)
	  this->doWhatIA(_map, 1, -1, clock);
      }
    }
    else
    {
      if (r >= u && r >= d && r >= l)
	this->doWhatIA(_map, 1, 1, clock);
      else if (l >= u && l >= d && l >= r)
	this->doWhatIA(_map, 1, -1, clock);
      else
      {
	if (d >= u && d >= l && d >= r)
	  this->doWhatIA(_map, 0, 1, clock);
	else if (u >= d && u >= l && u >= r)
	  this->doWhatIA(_map, 0, -1, clock);
      }
    }
  }
}

void			Character::doWhatIA(Map &_map, int dir, int cas,
					    gdl::Clock &clock)
{
  if (this->cmp == 10)
  {
    if (dir == 0)
    {
      if ((_map.mapGetValueAt(this->X, this->Y + (cas)) == '1' ||
	   _map.playerGetValueAt(this->X, this->Y + (cas)) > '0') &&
	  _map.objectGetValueAt(this->X, this->Y) != '4')
	this->putBombIA(_map);
      else if ((_map.objectGetValueAt(this->X, this->Y + (cas)) >= '1' &&
		_map.objectGetValueAt(this->X, this->Y + (cas)) <= '3') ||
	       _map.mapGetValueAt(this->X, this->Y + (cas)) == '0')
	this->doMoveIA(_map, dir, cas, clock);
    }
    else
    {
      if ((_map.mapGetValueAt(this->X + (cas), this->Y) == '1' ||
	   _map.playerGetValueAt(this->X + (cas), this->Y) > '0') &&
	  _map.objectGetValueAt(this->X, this->Y) != '4')
	this->putBombIA(_map);
      else if ((_map.objectGetValueAt(this->X + (cas), this->Y) >= '1' &&

		_map.objectGetValueAt(this->X + (cas), this->Y) <= '3') ||
	       _map.mapGetValueAt(this->X + (cas), this->Y) == '0')
	this->doMoveIA(_map, dir, cas, clock);
    }
  }
  else
    this->cmp += 1;
}

void			Character::putBombIA(Map &_map)
{
  this->DoBombe(_map);
}

void			Character::doMoveIA(Map &_map, int dir, int cas,
					    gdl::Clock &clock)
{
  if (dir == 0)
  {
    if (cas < 0)
      this->setPos(this->_x, this->_y - (this->Speed * clock.getElapsed() * 33), this->_x, this->_y - (this->Speed * clock.getElapsed() * 33) - 0.4, _map);
    else
      this->setPos(this->_x, this->_y + (this->Speed * clock.getElapsed() * 33), this->_x, this->_y + (this->Speed * clock.getElapsed() * 33) + 0.4, _map);
  }
  else
  {
    if (cas < 0)
      this->setPos(this->_x - (this->Speed * clock.getElapsed() * 33), this->_y, this->_x - (this->Speed * clock.getElapsed() * 33) - 0.4, this->_y, _map);
    else
      this->setPos(this->_x + (this->Speed * clock.getElapsed() * 33), this->_y, this->_x + (this->Speed * clock.getElapsed() * 33) + 0.4, this->_y, _map);
  }
}

int			Character::getID() const
{
  return this->ID;
}

std::string const&	Character::getName() const
{
  return this->Name;
}

int			Character::getLife() const
{
  return this->Life;
}

int			Character::getForce() const
{
  return this->Force;
}

float			Character::getSpeed() const
{
  return this->Speed;
}

int			Character::getMax() const
{
  return this->Max;
}

int			Character::getUsed() const
{
  return this->Used;
}

float			Character::getX() const
{
  return this->_x;
}

float			Character::getY() const
{
  return this->_y;
}

bool                    Character::getFrisbee() const
{
  return this->Frisbee;
}

int			Character::getType() const
{
  return this->_type;
}

void			Character::setType(int const type)
{
  this->_type = type;
}

void			Character::setPos(float const x, float const y,
					  float const x2, float const y2, Map& map)
{
  bool			move = false;
  char			bonus;
  char			b;

  if (map.mapGetValueAt(static_cast<int>(x2), static_cast<int>(y2)) == '0' &&
      (((b = map.objectGetValueAt(static_cast<int>(x2), static_cast<int>(y2))) != '4' &&
        b != '7') ||
       (this->OnBomb && static_cast<int>(x2) == this->BombX &&
        static_cast<int>(y2) == this->BombY)))
    {
      if (this->X != static_cast<int>(x) || this->Y != static_cast<int>(y))
        move = true;
      if (move)
        {
          map.playerSetValueAt('0', static_cast<int>(this->X), static_cast<int>(this->Y));
          if (((bonus = map.objectGetValueAt(static_cast<int>(x2), static_cast<int>(y2))) >= '1'
               && bonus <= '3') || bonus == '6')
            {
	      SoundManager::shared()->playSound(BONUS);
              if (bonus == '1')
                ++this->Max;
              else if (bonus == '2')
                ++this->Force;
              else if (bonus == '6')
                this->Frisbee = true;
              else
                if (this->Speed < SPEED*2-SPEED/5)
                  this->Speed += (SPEED/5);
              map.objectSetValueAt('0', static_cast<int>(x2), static_cast<int>(y2));
            }
        }
      this->_x = x;
      this->_y = y;
      this->X = this->_x;
      this->Y = this->_y;
      if (move)
        map.playerSetValueAt(this->ID + '0', this->X, this->Y);
      if (this->OnBomb &&
          (static_cast<int>(x2) != this->BombX || static_cast<int>(y2) != this->BombY))
        this->OnBomb = false;
    }
}

void			Character::DoBombe(Map& map)
{
  char			val;

  if (((val = map.objectGetValueAt(this->X, this->Y)) != '4' &&
       val != '7') && this->Used < this->Max)
    {
      map.AddBombe(this->Force, this->X, this->Y, this->Name, this->Frisbee);
      this->OnBomb = true;
      this->BombX = this->X;
      this->BombY = this->Y;
      ++this->Used;
    }
}

void			Character::RemoveBombe()
{
  --this->Used;
}

void			Character::RemoveLife()
{
  --this->Life;
}
