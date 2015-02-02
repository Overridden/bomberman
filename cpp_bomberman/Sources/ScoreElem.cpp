//
// ScoreElem.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Wed May 21 12:58:54 2014 Noel DOVAN
// Last update Sun Jun  1 17:43:01 2014 Noel DOVAN
//

#include "ScoreElem.hh"

ScoreElem::ScoreElem(std::string const& score, std::string const& date) : Score(score), Date(date)
{
  std::stringstream	ss;
  ss << score;
  ss >> this->ScoreInt;
}

ScoreElem::~ScoreElem()
{
}

int			ScoreElem::getScoreInt() const
{
  return this->ScoreInt;
}

std::string const&	ScoreElem::getScore() const
{
  return this->Score;
}

std::string const&	ScoreElem::getDate() const
{
  return this->Date;
}
