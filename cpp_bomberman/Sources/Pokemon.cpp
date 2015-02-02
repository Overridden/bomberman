//
// Pokemon.cpp for  in /home/peyrot_m/Restart_bomber/Sources
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Mon Jun  9 10:14:56 2014 peyrot_m
// Last update Sun Jun 15 21:54:56 2014 theron
//

#include "Pokemon.hh"

Pokemon::Pokemon()
{
  this->_objs.push_back(0);
  this->_objs.push_back(2);
}

Pokemon::~Pokemon()
{
}

bool	Pokemon::initialize(float x, float y, float z)
{
  if (_texture0.load("./Res/battle/battle0.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }

  _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
  _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.build();
  return (true);
}

bool	Pokemon::initialize(float x, float y, float z,
			    float size_x, float size_y,
			    __attribute__((unused)) float size_z)
{
  if ((_texture0.load("./Res/battle/battle0.tga") == false))
    {
      std::cerr << "Cannot load the intro texture" << std::endl;
      return (false);
    }
  _geometry.pushVertex(glm::vec3(x, y, z));
  _geometry.pushVertex(glm::vec3(x, y + size_y, z));
  _geometry.pushVertex(glm::vec3(x + -size_x, y + size_y, z));
  _geometry.pushVertex(glm::vec3(x + -size_x, y, z));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  return (true);
}

bool	Pokemon::initialize(float x, float y, float z,
			    float size_x, float size_y, float size_z,
			    std::string const& texture_name)
{
  if (_texture0.load(texture_name) == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }

  _geometry.pushVertex(glm::vec3(x + size_x / 4, y + -size_y / 4, z + -size_z / 4));
  _geometry.pushVertex(glm::vec3(x + size_x / 4, y + size_y / 4, z + -size_z / 4));
  _geometry.pushVertex(glm::vec3(x + -size_x / 4, y + size_y / 4, z + -size_z / 4));
  _geometry.pushVertex(glm::vec3(x + -size_x / 4, y + -size_y / 4, z + -size_z / 4));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.build();
  return (true);
}

void	Pokemon::update(__attribute__((unused))gdl::Clock const &clock,
			__attribute__((unused))gdl::Input &input)
{
  std::string           image = "./Res/battle/battle.tga";
  std::stringstream     ss;
  _objs[0] += 1;
  if (_objs[0] <= 41)
    {
      ss << _objs[0];
      image.insert(image.size() - 4, ss.str());
      if (_texture0.load(image) == false)
	throw ("Cannot load the Intre texture");
    }
  if (_objs[0] == 41)
    _objs[1] = 3;
}


/*
 * Dessine le cube
 */
void	Pokemon::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  glm::mat4	trans;

  trans = glm::rotate(glm::rotate( glm::translate( glm::mat4(1), glm::vec3(-3.6,4.45,0)),
				   180.0f, glm::vec3(1,0,0)),  180.0f, glm::vec3(0,1,0));

  (void)clock;
  _texture0.bind();
  shader.setUniform("color", glm::vec4(0, 0, 0, 1));
  _geometry.draw(shader, trans, GL_QUADS);
}

std::vector<int>	Pokemon::getObjs() const
{
  return (_objs);
}

void			Pokemon::setObjs(int const i)
{
  (void)i;
  _objs[0] = 0;
  _objs[1] = 2;
}
