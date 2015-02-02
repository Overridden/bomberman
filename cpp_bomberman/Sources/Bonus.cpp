//
// Bonus.cpp for  in /home/peyrot_m/rendu/cpp_bomberman
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Sun Jun 15 17:59:46 2014 peyrot_m
// Last update Sun Jun 15 21:49:28 2014 theron
//

#include "Bonus.hh"

Bonus::Bonus(std::vector<gdl::Model*> _mod)
{
  _model = _mod;
  this->_objs.push_back(2);
  this->_objs.push_back(0);
  this->_objs.push_back(0);
}

Bonus::~Bonus()
{
}

bool	Bonus::initialize(__attribute__((unused)) float x,
			  __attribute__((unused)) float y,
			  __attribute__((unused)) float z)
{
  _speed = 100.0f;
  _angle = 0.0f;
  _x = x;
  _y = y;
  _z = z;
  _trans = glm::scale(glm::rotate(glm::translate(
				       glm::mat4(1),
				       glm::vec3(_x, _y, _z)),
				  0.0f,
				  glm::vec3(0, 1, 0)),
		      glm::vec3(0.001f, 0.001f, 0.001f));
  return (true);
}

void	Bonus::update(__attribute__((unused)) gdl::Clock const &clock,
		      __attribute__((unused)) gdl::Input &input)
{
  _angle += clock.getElapsed() * _speed;
  if (_objs[1] == 2)
    _trans = glm::scale(glm::rotate(glm::translate(
						   glm::mat4(1),
						   glm::vec3(_x, _y, _z)),
				    _angle,
				    glm::vec3(0, 1, 0)),
			glm::vec3(0.006f, 0.006f, 0.006f));
  else if (_objs[1] == 4)
    _trans = glm::scale(glm::rotate(glm::translate(
						   glm::mat4(1),
						   glm::vec3(_x, _y, _z)),
				    _angle,
				    glm::vec3(0, 1, 0)),
			glm::vec3(0.3f, 0.3f, 0.3f));
  else if (_objs[1] == 5)
    _trans = glm::scale(glm::rotate(glm::translate(
						   glm::mat4(1),
						   glm::vec3(_x, _y, _z)),
				    _angle,
				    glm::vec3(0, 1, 0)),
			glm::vec3(0.1f, 0.1f, 0.1f));
  else if (_objs[1] == 6)
    _trans = glm::scale(glm::rotate(glm::translate(
						   glm::mat4(1),
						   glm::vec3(_x, _y, _z)),
				    _angle,
				    glm::vec3(0, 1, 0)),
			glm::vec3(0.002f, 0.002f, 0.002f));
  else
    _trans = glm::scale(glm::rotate(glm::translate(
						   glm::mat4(1),
						   glm::vec3(_x, _y, _z)),
				    _angle,
				    glm::vec3(0, 1, 0)),
			glm::vec3(0.003f, 0.003f, 0.003f));
}

void	Bonus::draw(__attribute__((unused)) gdl::AShader &shader,
		  __attribute__((unused)) gdl::Clock const &clock)
{
  if (_objs[1] > 1)
    {
      if (_objs[1] == 4)
	shader.setUniform("color", glm::vec4(0.8, 0.6, 0, 1));
      else if (_objs[1] == 5)
	shader.setUniform("color", glm::vec4(0.9, 0, 0.4, 1));
      else if (_objs[1] == 7)
	shader.setUniform("color", glm::vec4(1, 1, 0, 1));
      else
	shader.setUniform("color", glm::vec4(0, 0, 0, 1));
      _model[_objs[1]]->draw(shader, _trans, clock.getElapsed());
    }
}

std::vector<int>        Bonus::getObjs() const
{
  return (_objs);
}

void                    Bonus::setObjs(int type)
{
  if (type == 0)
    this->_objs[1] = 0;
  if (type == 1)
    this->_objs[1] = 2;
  if (type == 3)
    this->_objs[1] = 3;
  if (type == 5)
    this->_objs[1] = 4;
  if (type == 7)
    this->_objs[1] = 5;
  if (type == 9)
    this->_objs[1] = 6;
  if (type == 10)
    this->_objs[1] = 7;
  this->_objs[2] = type % 2;
}
