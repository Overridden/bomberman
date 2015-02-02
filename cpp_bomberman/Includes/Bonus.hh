//
// Bonus.hh for  in /home/peyrot_m/rendu/cpp_bomberman
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Sun Jun 15 17:58:01 2014 peyrot_m
// Last update Sun Jun 15 17:59:08 2014 peyrot_m
//

#include <Model.hh>
#include "AObject.hh"

#ifndef BONUS_HH_
# define BONUS_HH_

class Bonus : public AObject
{
public:
  Bonus(std::vector<gdl::Model*> _model);
  ~Bonus();
  bool	initialize(float, float, float);
  void	update(gdl::Clock const &, gdl::Input &);
  void	draw(gdl::AShader &, gdl::Clock const &);
  void                    setObjs(int type);
  std::vector<int>                    getObjs() const;
private:
  float	_x;
  float	_y;
  float	_z;
  float	_angle;
  float	_speed;
  std::vector<gdl::Model*>	_model;
  glm::mat4	_trans;
  std::vector<int>      _objs;
};

#endif /* !BONUS_HH_ */
