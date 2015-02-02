/*
** cube.cpp for cube in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 13:35:02 2014 teddy fontaine
// Last update Sun Jun 15 21:51:24 2014 theron
*/

#include "Carre.hh"

Carre::Carre()
{
}

Carre::~Carre()
{
}

bool	Carre::initialize(float x, float y, float z)
{
  if (_texture.load("./Res/textures/play.tga") == false)
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

bool	Carre::initialize(float x, float y, float z,
			  float size_x, float size_y,
			  __attribute__((unused)) float size_z)
{
  if (_texture.load("./Res/textures/play.tga") == false)
  {
    std::cerr << "Cannot load the cube texture" << std::endl;
    return (false);
  }
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y +
				 -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.build();
  return (true);
}

bool	Carre::initialize(float x, float y, float z,
			  float size_x, float size_y, float size_z,
			  std::string const& texture_name)
{
  if (_texture.load(texture_name) == false)
  {
    std::cerr << "Cannot load the cube texture" << std::endl;
    return (false);
  }

  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + -size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y + size_y / 2, z + -size_z / 2));
  _geometry.pushVertex(glm::vec3(x + -size_x / 2, y +
				 -size_y / 2, z + -size_z / 2));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.build();
  return (true);
}

void	Carre::update(__attribute__((unused))gdl::Clock const &clock,
		      __attribute__((unused))gdl::Input &input)
{
  glm::ivec2	pos;

  pos = input.getMousePosition();
  if (input.getKey(SDL_BUTTON_LEFT))
    {
      std::cout << "SDL_BUTTON_LEFT" << std::endl;
      if (pos[0] > 829 && pos[0] < 1237 &&
	  pos[1] > 584 && pos[1] < 934)
	std::cout << "PLAY!!" << std::endl;
    }
}

/*
 * Dessine le cube
 */
void	Carre::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  glm::mat4	trans;

  trans = glm::rotate(glm::rotate(glm::translate(glm::mat4(1),glm::vec3(-3.6,4.45,0.01)),
				  0.0f,glm::vec3(1,0,0)),180.0f,glm::vec3(0,1,0));


  (void)clock;

  _texture.bind();
  _geometry.draw(shader, trans, GL_QUADS);
}
