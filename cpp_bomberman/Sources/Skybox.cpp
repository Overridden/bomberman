/*
** skybox.cpp for skybox in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 13:35:02 2014 teddy fontaine
// Last update Sun Jun 15 22:02:18 2014 theron
*/

#include "Skybox.hh"

Skybox::Skybox()
{
  this->_objs.push_back(1);
  this->_objs.push_back(0);
}

Skybox::~Skybox()
{
}

bool	Skybox::initialize(float x, float y, float z)
{
  _speed = 10.0f;

  if (_texture.load("./Res/textures/skybox.tga") == false)
    throw ("erreur load texture");
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + -35 / 2, z + 35 / 2));

  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + 35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + 35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + -35 / 2, z + 35 / 2));
  _geometry.pushUv(glm::vec2(0.33f, 0.5f));
  _geometry.pushUv(glm::vec2(0.33f, 0.75f));
  _geometry.pushUv(glm::vec2(0.66f, 0.75f));
  _geometry.pushUv(glm::vec2(0.66f, 0.5f));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + -35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + 35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + 35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + -35 / 2, z + -35 / 2));
  _geometry.pushUv(glm::vec2(0.34f, 0.25f));
  _geometry.pushUv(glm::vec2(0.34f, 0.0f));
  _geometry.pushUv(glm::vec2(0.665f, 0.0f));
  _geometry.pushUv(glm::vec2(0.665f, 0.25f));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + -35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + 35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + 35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + -35 / 2, z + 35 / 2));
  _geometry.pushUv(glm::vec2(0.0f, 0.5f));
  _geometry.pushUv(glm::vec2(0.0f, 0.75f));
  _geometry.pushUv(glm::vec2(0.33f, 0.75f));
  _geometry.pushUv(glm::vec2(0.33f, 0.5f));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + -35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + 35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + 35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + -35 / 2, z + -35 / 2));
  _geometry.pushUv(glm::vec2(0.66f, 0.5f));
  _geometry.pushUv(glm::vec2(0.66f, 0.75f));
  _geometry.pushUv(glm::vec2(1.0f, 0.75f));
  _geometry.pushUv(glm::vec2(1.0f, 0.5f));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + 35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + 35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + 35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + 35 / 2, z + 35 / 2));
  _geometry.pushUv(glm::vec2(0.33f, 0.75f));
  _geometry.pushUv(glm::vec2(0.33f, 0.95f));
  _geometry.pushUv(glm::vec2(0.665f, 0.95f));
  _geometry.pushUv(glm::vec2(0.665f, 0.75f));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + -35 / 2, z + -35 / 2));
  _geometry.pushVertex(glm::vec3(x + 35 / 2, y + -35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + -35 / 2, z + 35 / 2));
  _geometry.pushVertex(glm::vec3(x + -35 / 2, y + -35 / 2, z + -35 / 2));
  _geometry.pushUv(glm::vec2(0.34f, 0.25f));
  _geometry.pushUv(glm::vec2(0.34f, 0.5f));
  _geometry.pushUv(glm::vec2(0.665f, 0.5f));
  _geometry.pushUv(glm::vec2(0.665f, 0.25f));
  _geometry.build();
  return (true);
}

bool	Skybox::initialize(float x, float y, float z, float size_x, float size_y, float size_z)
{
  _speed = 10.0f;

  if (_texture.load("./Res/textures/skybox.tga") == false)
    throw ("erreur load texture");

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.33f, 0.5f));
  _geometry.pushUv(glm::vec2(0.33f, 0.75f));
  _geometry.pushUv(glm::vec2(0.66f, 0.75f));
  _geometry.pushUv(glm::vec2(0.66f, 0.5f));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.34f, 0.25f));
  _geometry.pushUv(glm::vec2(0.34f, 0.0f));
  _geometry.pushUv(glm::vec2(0.665f, 0.0f));
  _geometry.pushUv(glm::vec2(0.665f, 0.25f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 0.5f));
  _geometry.pushUv(glm::vec2(0.0f, 0.75f));
  _geometry.pushUv(glm::vec2(0.33f, 0.75f));
  _geometry.pushUv(glm::vec2(0.33f, 0.5f));

  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.66f, 0.5f));
  _geometry.pushUv(glm::vec2(0.66f, 0.75f));
  _geometry.pushUv(glm::vec2(1.0f, 0.75f));
  _geometry.pushUv(glm::vec2(1.0f, 0.5f));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.34f, 0.25f));
  _geometry.pushUv(glm::vec2(0.34f, 0.5f));
  _geometry.pushUv(glm::vec2(0.665f, 0.5f));
  _geometry.pushUv(glm::vec2(0.665f, 0.25f));

  _geometry.build();
  return (true);
}

bool	Skybox::initialize(float x, float y, float z, float size_x, float size_y, float size_z, std::string const& texture_name)
{
  _speed = 10.0f;

  if (_texture.load(texture_name) == false)
  {
    std::cerr << "Cannot load the skybox texture" << std::endl;
    return (false);
  }

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));

  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  return (true);
}

void	Skybox::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Skybox::draw(gdl::AShader &shader, gdl::Clock const &clock)
{

  (void)clock;
    _texture.bind();
    shader.setUniform("color", glm::vec4(0, 0, 0, 1));
    _geometry.draw(shader,getTransformation(), GL_QUADS);
}

std::vector<int>	Skybox::getObjs() const
{

  return (_objs);
}

void			Skybox::setObjs(int type)
{
  this->_objs[1] = type;
}
