/*
** mod.hh for mod in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:37:28 2014 teddy fontaine
// Last update Sun Jun 15 12:03:15 2014 peyrot_m
*/

#include <Model.hh>
#include "AObject.hh"
#include "Joystick.hh"

#ifndef PLAYER_HH_
# define PLAYER_HH_

class Player : public AObject
{
  public:
  Player(int, int, std::vector<gdl::Model*> _model);
    ~Player();
    bool			initialize(float, float, float);
    void			update(gdl::Clock const &, gdl::Input &);
    void			draw(gdl::AShader &, gdl::Clock const &);

    std::vector<int>		getObjs() const;
    void			setObjs(int);

private:
  std::vector<int>	_objs;
  int			_type;
  float		_angle;
  int			_idJoy;
  int			_frame;
  int			TypeModel;
  bool		_anim;
  std::string		_modelPath;
  float		_speed;
  std::vector<gdl::Model*>	_model;
  Joystick		_joystick;
  glm::mat4		_trans;
  void		updateObjs(int);
  void		rezObjs();
};

#endif /* !PLAYER_HH_ */
