/*
** Cam.hh for Cam in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 18:35:08 2014 teddy fontaine
** Last update Tue Jun  3 12:43:20 2014 teddy fontaine
*/

#ifndef CAM_HH_
# define CAM_HH_

#include "AObject.hh"

class Cam : public AObject
{
  public:
    bool	initialize(float, float, float);
    void	update(gdl::Clock const &, gdl::Input &);
    void	draw(gdl::AShader &, gdl::Clock const &);
    float	getCamZ();
  private:
    float	_speed;
    float	_x;
    float	_y;
    float	_z;
    float	_rX;
    float	_rY;
    float	_rZ;
};

#endif /* !CAM_HH_ */
