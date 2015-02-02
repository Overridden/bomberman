//
// Intro.hh for  in /home/peyrot_m/Restart_bomber/Includes
// 
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
// 
// Started on  Mon Jun  9 04:51:13 2014 peyrot_m
// Last update Fri Jun 13 09:30:07 2014 peyrot_m
//

#ifndef INTRO_HH_
# define INTRO_HH_

#include "AObject.hh"
#include <sstream>

class Intro : public AObject
{
private:

  gdl::Texture		_texture0;
  gdl::Geometry		_geometry;
  std::vector<int>	_objs;
  
public:
  Intro();
  virtual ~Intro();
  virtual bool	initialize(float x, float y, float z, float size_x, float size_y, float size_z);
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  std::vector<int>	getObjs() const;
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !INTRO_HH_ */
