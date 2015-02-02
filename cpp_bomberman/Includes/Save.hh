//
// Save.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Fri Jun  6 16:59:37 2014 Noel DOVAN
// Last update Sun Jun 15 00:35:28 2014 theron
//

#ifndef		SAVE_HH_
# define	SAVE_HH_

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <dirent.h>
# include <cstdlib>
# include "MyException.hh"
# include "Map.hh"
# include "Character.hh"

class GameEngine;
class Menu;

class Save
{

private:

  std::vector<std::string>	saves;
  DIR*				D;
  struct dirent*		Dir;
  int				Max;

public:

  Save();
  ~Save();

  void				ToFile(std::ostream& os, GameEngine const& s) const;
  void				FromFile(std::istream& is, GameEngine& s) const;

  std::vector<std::string>&	GetSaves();
  int				getMax() const;
  void				xUnlink(std::string const &path) const;

private:

  void				ToFileMap(std::ostream& os, GameEngine const& s) const;
  void				ToFilePlayers(std::ostream& os, GameEngine const& s) const;
  void				FromFileMap(std::istream& is, GameEngine& s) const;
  void				FromFileMapList(std::istream& is, GameEngine& s,
						int const width, int const height) const;
  void				FromFilePlayers(std::istream& is, GameEngine& s) const;

  void				CleanVector();

};

#endif
