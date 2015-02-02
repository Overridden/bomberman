//
// Score.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sat May 17 16:43:16 2014 Noel DOVAN
// Last update Sun Jun 15 00:43:10 2014 theron
//

#include "Score.hh"

Score::Score()
{
}

Score::~Score()
{
  this->CleanList();
}

void			Score::AddScore(int const score, std::string const& name)
{
  this->File.open(SCORE_FILE, std::fstream::out | std::fstream::app);
  if (this->File.is_open())
    {
      this->File << score << ";" << name << std::endl;
      this->File.close();
    }
}

std::list<ScoreElem*>&	Score::GetScores()
{
  std::string		line, score, date;
  size_t		first;

  this->File.open(SCORE_FILE, std::fstream::in);
  this->CleanList();
  if (this->File.is_open())
    {
      while (std::getline(this->File, line))
	{
	  first = line.find(";");
	  if (first != std::string::npos && first > 1)
	    {
	      score = line.substr(0, first);
	      date = line.substr(score.size() + 1, line.size());
	      if (score.compare(";") != 0 && date.compare(";") != 0)
		this->scores.push_back(new ScoreElem(score, date));
	    }
	}
      this->File.close();
      this->scores.sort(ScoresSort());
    }
  return this->scores;
}

void			Score::CleanList()
{
  while (!this->scores.empty())
    {
      delete this->scores.back();
      this->scores.pop_back();
    }
}
