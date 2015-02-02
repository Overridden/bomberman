/*
** AObject.cpp for AObject in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 20 17:34:37 2014 teddy fontaine
// Last update Sun Jun 15 19:13:38 2014 peyrot_m
*/

#include "AObject.hh"

AObject::AObject() : _position(0, 0, 0),
		     _rotation(0, 0, 0),
		     _scale(1, 1, 1)
{
}

AObject::~AObject()
{
}

/*
 * Initialize l'objet
 */
bool			AObject::initialize(__attribute__((unused))float x, __attribute__((unused))float y, __attribute__((unused))float z)
{
  return (true);
}

bool			AObject::initialize(__attribute__((unused))float x, __attribute__((unused))float y, __attribute__((unused))float z, __attribute__((unused))float size_x, __attribute__((unused))float size_y, __attribute__((unused))float size_z)
{
  return (true);
}

bool			AObject::initialize(__attribute__((unused))float x, __attribute__((unused))float y, __attribute__((unused))float z, __attribute__((unused))float size_x, __attribute__((unused))float size_y, __attribute__((unused))float size_z, __attribute__((unused))std::string const& texture_name)
{
  return (true);
}

/*
 * Gere le comportement de l'objet
 */
void			AObject::update(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
}

/*
 *
 */
std::vector<int>	AObject::getObjs() const
{
  return (std::vector<int>(false));
}

/*
 *
 */
void			AObject::setObjs(__attribute__((unused)) int objs)
{
}


/*
 * Translate l'objet
 */
void			AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

/*
 * Rotation de "angle" degres autour de "axis"
 */
void			AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

/*
 * Modifie la grandeur de l'objet
 */
void			AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

/*
 * Retourne le la matrice de transformatio
 */
glm::mat4		AObject::getTransformation()
{
  glm::mat4	transform;

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);

  return (transform);
}

/*
 * Return X
 */
float			AObject::getX() const
{
  return (_x);
}

/*
 * Return Y
 */
float			AObject::getY() const
{
  return (_y);
}

/*
 * Return z
 */
float			AObject::getZ() const
{
  return (_z);
}

/*
 * set X
 */
void			AObject::setX(float i)
{
  this->_x = i;
}

/*
 * set Y
 */
void			AObject::setY(float i)
{
  this->_y = i;
}

/*
 * set z
 */
void			AObject::setZ(float i)
{
  this->_z = i;
}

/*
 * set my_string
 */
void			AObject::setString(std::string const &i)
{
  this->my_string = i;
}

/*
 * get my_string
 */
std::string const&	AObject::getString() const
{
  return (this->my_string);
}
