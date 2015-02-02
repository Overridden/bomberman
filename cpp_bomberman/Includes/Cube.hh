/*
** Cube.hh for cube in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Tue May 20 10:45:19 2014 Alexandre NGUYEN
// Last update Sun Jun 15 20:03:52 2014 peyrot_m
*/

#ifndef CUBE_HH_
# define CUBE_HH_

#include "AObject.hh"

class Cube : public AObject
{
private:

  std::vector<gdl::Texture*>	_texture;
  glm::mat4			_trans;
  std::vector<gdl::Geometry*>	_geometry;
  float				_speed;
  std::vector<int>		_objs;

public:
  Cube(  std::vector<gdl::Texture*> const & _text,
	 std::vector<gdl::Geometry*> const & _geo);
  virtual ~Cube();
  virtual bool			initialize(float x, float y, float z);
  virtual void			update(gdl::Clock const &clock,
				       gdl::Input &input);
  virtual void			draw(gdl::AShader &shader,
				     gdl::Clock const &clock);
  std::vector<int>		getObjs() const;
  void				setObjs(int);
};

#endif /* !CUBE_HH_ */
