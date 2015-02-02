//
// Botte.hh for  in /home/peyrot_m/rendu/cpp_bomberman/Includes
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Sun Jun 15 03:17:49 2014 peyrot_m
// Last update Sun Jun 15 12:44:47 2014 peyrot_m
//

#include <Model.hh>
#include "AObject.hh"

#ifndef BOTTE_HH_
# define BOTTE_HH_

class Botte : public AObject
{
public:
  Botte(std::vector<gdl::Model*>  _model);
  ~Botte();
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
  std::vector<gdl::Model*> _model;
  glm::mat4	_trans;
  std::vector<int> _objs;
};

#endif /* !BOTTE_HH_ */
