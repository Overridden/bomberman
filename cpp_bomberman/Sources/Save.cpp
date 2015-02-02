//
// Save.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Fri Jun  6 17:00:05 2014 Noel DOVAN
// Last update Sun Jun 15 22:31:52 2014 Noel DOVAN
//

#include "GameEngine.hh"
#include "Save.hh"

Save::Save() : Max(0)
{
}

Save::~Save()
{
  this->CleanVector();
}

void			Save::ToFile(std::ostream& os, GameEngine const& s) const
{
  os << s.getPlayer() << std::endl << s.getPlayerFix() << std::endl
     << s.getIA() << std::endl << s.getGameScore() << std::endl;
  this->ToFileMap(os, s);
  this->ToFilePlayers(os, s);
}

void			Save::ToFileMap(std::ostream& os, GameEngine const& s) const
{
  Map						m = s.getMap();
  std::list<std::string>			map = m.getMap();
  std::list<std::string>			mapObject = m.getObject();
  std::list<std::string>			mapPlayer = m.getPlayer();
  std::list<std::string>::const_iterator	itMap(map.begin());
  std::list<std::string>::const_iterator	itObj(mapObject.begin());
  std::list<std::string>::const_iterator	itPla(mapPlayer.begin());

  os << m.getWidth() << std::endl << m.getHeight() << std::endl << m.getMadness()
     << std::endl << "#" << std::endl;
  --itMap;
  --itObj;
  --itPla;
  while (++itMap != map.end())
    os << *itMap << std::endl;
  os << "#" << std::endl;
  while (++itObj != mapObject.end())
    os << *itObj << std::endl;
  os << "#" << std::endl;
  while (++itPla != mapPlayer.end())
    os << *itPla << std::endl;
}

void			Save::ToFilePlayers(std::ostream& os, GameEngine const& s) const
{
  std::list<Character*>				p = s.getPlayers();
  std::list<Character*>::const_iterator		itP(p.begin());

  --itP;
  while (++itP != p.end())
    os << "#" << std::endl << (*itP)->getID() << std::endl << (*itP)->getName()
       << std::endl << (*itP)->getLife() << std::endl << (*itP)->getForce()
       << std::endl << (*itP)->getSpeed() << std::endl << (*itP)->getMax()
       << std::endl << 0 << std::endl << (int)(*itP)->getX() << std::endl
       << (int)(*itP)->getY() << std::endl << (*itP)->getX() << std::endl
       << (*itP)->getY() << std::endl << (*itP)->getFrisbee() << std::endl
       << (*itP)->getType() << std::endl << "#" << std::endl;
}

void			Save::FromFile(std::istream& is, GameEngine& s) const
{
  int			player, playerFix, ia, gameScore;

  is >> player >> playerFix >> ia >> gameScore;
  s.setPlayer(player);
  s.setPlayerFix(playerFix);
  s.setIA(ia);
  s.setGameScore(gameScore);
  this->FromFileMap(is, s);
  this->FromFilePlayers(is, s);
}

void			Save::FromFileMap(std::istream& is, GameEngine& s) const
{
  s.createMap();
  s.getMap2().Reset();
  int			width, height, madness;
  std::string		check;

  is >> width >> height >> madness >> check;
  if (check.compare("#") != 0 || width < 10 || width > 1000 ||
      height < 10 || height > 1000)
    throw MyException("Incorrect loading file");
  check.clear();
  s.setWidth(width);
  s.setHeight(height);
  s.setMadness(madness);
  s.getMap2().setWidth(width);
  s.getMap2().setHeight(height);
  s.getMap2().setMadness(madness);
  this->FromFileMapList(is, s, width, height);
}

void			Save::FromFileMapList(std::istream& is, GameEngine& s,
					      int const width, int const height) const
{
  std::list<std::string>	map, mapObj, mapPla;
  std::string			line, check;
  int				i = -1;

  while (++i < height)
    {
      is >> line;
      if (line.size() != (unsigned int)width)
  	throw MyException("Incorrect loading file");
      map.push_back(line);
    }
  is >> check;
  if (check.compare("#") != 0)
    throw MyException("Incorrect loading file");
  check.clear();
  i = -1;
  while (++i < height)
    {
      is >> line;
      if (line.size() != (unsigned int)width)
  	throw MyException("Incorrect loading file");
      unsigned int		at = -1;
      while (++at < line.size())
  	if (line.at(at) == '4' || line.at(at) == '5')
  	  line[at] = '0';
      mapObj.push_back(line);
    }
  is >> check;
  if (check.compare("#") != 0)
    throw MyException("Incorrect loading file");
  check.clear();
  i = -1;
  while (++i < height)
    {
      is >> line;
      if (line.size() != (unsigned int)width)
  	throw MyException("Incorrect loading file");
      mapPla.push_back(line);
    }
  s.getMap2().SetMapList(map, mapObj, mapPla);
}

void			Save::FromFilePlayers(std::istream& is, GameEngine& s) const
{
  int			id, life, force, max, used, x, y, type;
  float			speed, _x, _y;
  bool			frisbee;
  std::string		_name, check;

  is >> check;
  while (check.compare("#") == 0)
    {
      check.clear();
      is >> id >> _name >> life >> force >> speed >> max >> used
  	 >> x >> y >> _x >> _y >> frisbee >> type >> check;
      if (check.compare("#") != 0)
      	throw MyException("Incorrect loading file");
      check.clear();
      s.AddPlayer(id, _name, life, force, speed, max, used, x, y, _x, _y, frisbee, type);
      is >> check;
    }
}

std::vector<std::string>&	Save::GetSaves()
{
  std::string			str;

  if (!(this->D = opendir("./Res/Saves")))
    throw MyException("opendir ./Res/Saves/ not found");
  this->CleanVector();
  while ((this->Dir = readdir(this->D)) != NULL)
    {
      str = this->Dir->d_name;
      if (str.compare(".") != 0 && str.compare("..") != 0)
	this->saves.push_back(str);
    }
  if (closedir(this->D) == -1)
    throw MyException("closedir failed");
  this->saves.push_back("end");
  std::sort(this->saves.begin(), this->saves.end());
  this->Max = -1;
  while (this->saves[++this->Max].compare("end") != 0)
    ;
  return this->saves;
}

void			Save::CleanVector()
{
  while (!this->saves.empty())
    this->saves.pop_back();
}

void                    Save::xUnlink(std::string const &path) const
{
  if (unlink(path.c_str()) == -1)
    std::cerr << "Cannot delete file" << std::endl;
}

int			Save::getMax() const
{
  return this->Max;
}
