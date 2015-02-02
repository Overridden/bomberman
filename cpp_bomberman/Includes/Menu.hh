//
// Menu.hh for  in /home/peyrot_m/Restart_bomber/Sources
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Fri Jun  6 00:52:38 2014 peyrot_m
// Last update Sun Jun 15 11:05:36 2014 peyrot_m
//
#ifndef MENU_HH_
# define MENU_HH_

#include <sstream>
#include "AObject.hh"
#include "MyException.hh"
#include "Carre.hh"
#include "Score.hh"
#include "Save.hh"
#include "Sleep.hh"

class Save;

class Menu : public AObject
{
private:

  glm::ivec2				pos;
  std::vector<gdl::Texture*>		_texture;
  std::string				name;
  gdl::Geometry				_geometry;
  std::vector<int>			_objs;
  bool					_play;
  bool					_credit;
  bool					_score;
  bool					_load;
  bool					_end;
  bool					_start;
  bool					takescore;
  Score					score;
  std::list<ScoreElem*>			Scores;
  Save					save;
  Time					time;
  bool					SaveGet;
  std::vector<std::string>		Saves;
  int					saveIndex;
  int					maxIndex;
  Sleep					sleep;
  bool					_delete;
  bool					_reset;

public:
  Menu(std::vector<gdl::Texture*> const &_text);
  virtual ~Menu();
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z);
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuMenu(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuPlay(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuScore(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuLoad(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuCredit(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuPause(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuWin(gdl::Clock const &clock, gdl::Input &input);
  virtual void	UpdateMenuLose(gdl::Clock const &clock, gdl::Input &input);

  std::vector<int>	getObjs() const;
  void			setObjs(int const i);

  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void	DrawMenuPlay(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void	DrawMenuScore(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void	DrawMenuLoad(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void	DrawMenuWin(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void	DrawNumber(gdl::AShader &shader,
			   gdl::Clock const &clock,
			   int nb, float x, float y);
  virtual void			DrawLetter(gdl::AShader &shader,
					   gdl::Clock const &clock,
					   char c, float x, float y);
  virtual void			DrawCursor(gdl::AShader &shader,
					   gdl::Clock const &clock);
  void				 DrawString(gdl::AShader &shader,
					    gdl::Clock const &clock,
					    std::string const& c,
					    float x, float y);
  bool				getCredit() const;
};

#endif /* !MENU_HH_ */
