/*
** cube.cpp for cube in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 13:35:02 2014 teddy fontaine
// Last update Sun Jun 15 21:50:54 2014 theron
*/

#include "Cube.hh"

Cube::Cube(std::vector<gdl::Texture*> const &_text,
	   std::vector<gdl::Geometry*> const &_geo)
{
  _geometry = _geo;
  _texture = _text;
  this->_objs.push_back(1);
  this->_objs.push_back(0);
}

Cube::~Cube()
{
}

bool	Cube::initialize(float x, float y, float z)
{
  _speed = 10.0f;
  (void)x;
  (void)y;
  (void)z;
  return (true);
}

void	Cube::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Cube::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  if (this->_objs[1] > 0)
    {
      if (this->_objs[1] == 1)
  	_texture[10]->bind();
      if (this->_objs[1] == 2)
  	_texture[11]->bind();
      if (this->_objs[1] == 3)
  	_texture[12]->bind();
      if (this->_objs[1] == 4)
  	 _texture[13]->bind();
      if (this->_objs[1] == 5)
  	_texture[14]->bind();
      if (this->_objs[1] == 6)
  	_texture[15]->bind();
      if (this->_objs[1] == 7)
  	_texture[16]->bind();
      if (this->_objs[1] == 8)
  	_texture[17]->bind();
      if (this->_objs[1] == 9)
  	_texture[18]->bind();
      if (this->_objs[1] == 10)
  	_texture[19]->bind();
      _trans = glm::scale(glm::rotate(glm::translate(
						     glm::mat4(1),
						     glm::vec3(_x, _y, _z)),
				      0.0f,
				      glm::vec3(0, 1, 0)),
			  glm::vec3(1.0f, 1.0f, 1.0f));

      shader.setUniform("color", glm::vec4(0, 0, 0, 1));
      _geometry[1]->draw(shader, _trans, GL_QUADS);
    }
  else if (this->_objs[1] == 0)
    {
      	_texture[8]->bind();
      _trans = glm::scale(glm::rotate(glm::translate(
						     glm::mat4(1),
						     glm::vec3(_x, _y, _z)),
				      0.0f,
				      glm::vec3(0, 1, 0)),
			  glm::vec3(1.0f, 1.0f, 1.0f));

      shader.setUniform("color", glm::vec4(0, 0, 0, 1));
      _geometry[0]->draw(shader, _trans, GL_QUADS);
    }
}

std::vector<int>	Cube::getObjs() const
{

  return (_objs);
}

void			Cube::setObjs(int type)
{
  this->_objs[1] = type;
}
