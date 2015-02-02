/*
** Skybox.hh for skybox in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Tue May 20 10:45:19 2014 Alexandre NGUYEN
// Last update Sun Jun 15 18:09:50 2014 Noel DOVAN
*/

#ifndef SKYBOX_HH_
# define SKYBOX_HH_

#include "AObject.hh"

class Skybox : public AObject
{
private:

  gdl::Texture	_texture;
  glm::mat4		_trans;
  gdl::Geometry	_geometry;
  float		_speed;
  std::vector<int>	_objs;

public:
  Skybox();
  virtual ~Skybox();
  virtual bool	initialize(float x, float y, float z);
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z);
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z, std::string const& texture_name);
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  std::vector<int>		getObjs() const;
  void			setObjs(int);
};

#endif /* !SKYBOX_HH_ */
