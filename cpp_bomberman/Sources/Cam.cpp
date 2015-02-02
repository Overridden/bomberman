/*
** Cam.cpp for Cam in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 18:35:52 2014 teddy fontaine
// Last update Fri Jun 13 20:21:10 2014 peyrot_m
*/

#include "Cam.hh"

bool	Cam::initialize(__attribute__((unused)) float x,
			__attribute__((unused)) float y,
			__attribute__((unused)) float z)
{
  _speed = 5.0f;
  _x = x;
  _y = y;
  _z = z;
  _rX = x;
  _rY = y;
  _rZ = z;
  return (true);
}

void	Cam::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_r))
  {
    _y += _speed * clock.getElapsed();
    _rY += _speed * clock.getElapsed();
  }
  if (input.getKey(SDLK_c))
  {
    _y -= _speed * clock.getElapsed();
    _rY -= _speed * clock.getElapsed();
  }
  if (input.getKey(SDLK_q))
  {
    _x -= _speed * clock.getElapsed();
    _rX -= _speed * clock.getElapsed();
  }
  if (input.getKey(SDLK_d))
  {
    _x += _speed * clock.getElapsed();
    _rX += _speed * clock.getElapsed();
  }
  if (input.getKey(SDLK_z))
    _z -= _speed * clock.getElapsed();
  if (input.getKey(SDLK_s))
    _z += _speed * clock.getElapsed();
  if (input.getKey(SDLK_a))
    _rX -= _speed * clock.getElapsed();
  if (input.getKey(SDLK_e))
    _rX += _speed * clock.getElapsed();

/*  std::cout << "______________" << std::endl;
  std::cout << (int)_x << std::endl;
  std::cout << (int)_y << std::endl;
  std::cout << (int)_z << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << (int)_rX << std::endl;
  std::cout << (int)_rY << std::endl;
  std::cout << (int)_rZ << std::endl;
  std::cout << "______________" << std::endl;*/
}

void	Cam::draw(__attribute__((unused)) gdl::AShader &shader,
		  __attribute__((unused)) gdl::Clock const &clock)
{
  shader.setUniform("view", glm::lookAt(
		      glm::vec3(_x, _y, _z + 1),
		      glm::vec3(_rX, _rY, _rZ),
		      glm::vec3(0, 1, 0)));
}
float	Cam::getCamZ()
{
  return (_z);
}
