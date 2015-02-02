//
// ScoreElem.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Wed May 21 12:56:24 2014 Noel DOVAN
// Last update Fri Jun  6 16:29:45 2014 Noel DOVAN
//

#ifndef		SCOREELEM_HH_
# define	SCOREELEM_HH_

# include <iostream>
# include <sstream>
# include <time.h>

class ScoreElem
{

private:

  int			ScoreInt;
  std::string		Score;
  std::string		Date;

public:

  ScoreElem(std::string const& score, std::string const& date);
  ~ScoreElem();

  int			getScoreInt() const;
  std::string const&	getScore() const;
  std::string const&	getDate() const;

};

#endif
