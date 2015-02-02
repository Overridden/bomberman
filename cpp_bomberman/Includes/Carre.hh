/*
** Cube.hh for cube in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Tue May 20 10:45:19 2014 Alexandre NGUYEN
// Last update Sun Jun 15 18:06:23 2014 Noel DOVAN
*/

#ifndef CARRE_HH_
# define CARRE_HH_

#include "AObject.hh"

class Carre : public AObject
{
private:

  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public:
  Carre();
  virtual ~Carre();
  virtual bool	initialize(float x, float y, float z);
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z);
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z, std::string const& texture_name);
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !CARRE_HH_ */
