//
// Score.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sat May 17 16:42:33 2014 Noel DOVAN
// Last update Wed Jun 11 16:32:04 2014 Noel DOVAN
//

#ifndef		SCORE_HH_
# define	SCORE_HH_

# define SCORE_FILE	"Res/Scores"

# include <iostream>
# include <fstream>
# include <list>
# include "Time.hh"
# include "ScoreElem.hh"

struct ScoresSort
{
  bool	operator()(ScoreElem* lhs, ScoreElem* rhs) const
  {
    return lhs->getScoreInt() > rhs->getScoreInt();
  }
};

class Score
{

private:

  std::list<ScoreElem*>		scores;
  std::fstream			File;

public:

  Score();
  ~Score();

  void				AddScore(int const score, std::string const& name);
  std::list<ScoreElem*>&	GetScores();

private:

  void				CleanList();

};

#endif
