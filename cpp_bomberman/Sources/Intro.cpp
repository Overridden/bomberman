//
// Intro.cpp for  in /home/peyrot_m/Restart_bomber/Sources
//
// Made by peyrot_m
// Login   <peyrot_m@epitech.net>
//
// Started on  Mon Jun  9 04:32:24 2014 peyrot_m
// Last update Sun Jun 15 21:59:08 2014 theron
//

#include "Intro.hh"
#include "GameEngine.hh"
#include <Model.hh>

Intro::Intro()
{
  this->_objs.push_back(0);
  this->_objs.push_back(0);
  SoundManager::shared()->playSound(INTRO);
}

Intro::~Intro()
{
}


bool	Intro::initialize(float x, float y, float z,
			 float size_x, float size_y, __attribute__((unused)) float size_z)
{
  if ((_texture0.load("./Res/intro/intro0.tga") == false))
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

/*
 * gestion de l'intro
 */
void	Intro::update(__attribute__((unused))gdl::Clock const &clock,
		      __attribute__((unused))gdl::Input &input)
{
  std::string           image = "./Res/intro/intro.tga";
  std::stringstream     ss;
  _objs[0] += 1;
  if (_objs[0] <= 70)
    {
      ss << _objs[0];
      image.insert(image.size() - 4, ss.str());
      if (_texture0.load(image) == false)
 	throw ("Cannot load the Intre texture");
    }
  if (_objs[0] == 70)
    _objs[1] = 1;
}


/*
 * Affichage de l'intro
 */
void	Intro::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  glm::mat4	trans;

  trans = glm::rotate(glm::rotate( glm::translate( glm::mat4(1), glm::vec3(-3.6,4.45,0)),
				   180.0f, glm::vec3(1,0,0)),  180.0f, glm::vec3(0,1,0));

  (void)clock;
  _texture0.bind();
  shader.setUniform("color", glm::vec4(0, 0, 0, 1));
  _geometry.draw(shader, trans, GL_QUADS);
}

std::vector<int>	Intro::getObjs() const
{
  return (_objs);
}
