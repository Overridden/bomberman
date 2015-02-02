//
// Pokemon.hh for  in /home/peyrot_m/Restart_bomber/Includes
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Mon Jun  9 10:18:37 2014 peyrot_m
// Last update Sun Jun 15 18:08:19 2014 Noel DOVAN
//

#ifndef POKEMON_HH_
# define POKEMON_HH_

#include "AObject.hh"
#include <sstream>

class Pokemon : public AObject
{
private:

  gdl::Texture		_texture0;
  gdl::Geometry		_geometry;
  std::vector<int>	_objs;

public:
  Pokemon();
  virtual ~Pokemon();
  virtual bool	initialize(float x, float y, float z);
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z);
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z, std::string const& texture_name);
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  std::vector<int>	getObjs() const;
  void			setObjs(int const i);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !POKEMON_HH_ */
