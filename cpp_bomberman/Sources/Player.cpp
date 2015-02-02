/*
** Player.cpp for model in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:35:33 2014 teddy fontaine
// Last update Sun Jun 15 21:34:52 2014 theron
*/

#include "Player.hh"

Player::Player(int idJoy, int type, std::vector<gdl::Model*> _mod)
{
  _idJoy = idJoy;
  _type = type;
  _model = _mod;
  if (_type == 5 || _type == 3)
    TypeModel = 0;
  else if (_type == 4)
    TypeModel = 1;
}

Player::~Player()
{
  _objs.clear();
}

bool	Player::initialize(__attribute__((unused)) float x,
			   __attribute__((unused)) float y,
			   __attribute__((unused)) float z)
{
  _speed = 0.5f;
  _angle = 0.0f;
  _frame = 20;
  _anim = false;
  _x = x;
  _y = y;
  _z = z;
  _objs.push_back(_type);
  _objs.push_back(_idJoy);
  _objs.push_back(_joystick.joystickCheck());
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _trans = glm::scale(glm::rotate(glm::translate(
						 glm::mat4(1),
						 glm::vec3(_x, _y, _z)),
				  _angle,
				  glm::vec3(0, 1, 0)),
		      glm::vec3(0.002f, 0.002f, 0.002f));
  _model[TypeModel]->createSubAnim(0, "RESET", 0, 0);
  _model[TypeModel]->createSubAnim(0, "START", 20, 30);
  _model[TypeModel]->createSubAnim(0, "RUN", 37, 53);
  _model[TypeModel]->createSubAnim(0, "END", 54, 100);
  rezObjs();
  return (true);
}

void	Player::update(__attribute__((unused)) gdl::Clock const &clock,
		       __attribute__((unused)) gdl::Input &input)
{
  float	z;
  float	x;
  int	a;
  int	pause;

  _anim = false;
  if (((_idJoy < _joystick.joystickCheck()) || (_idJoy == 0)) || _type != 5)
  {
    if ((_joystick.joystickForGame(_idJoy) > 0) && _type == 5)
    {
      SDL_JoystickUpdate();
      x = SDL_JoystickGetAxis(_joystick.getJoy(), 0);
      z = SDL_JoystickGetAxis(_joystick.getJoy(), 1);
      a = SDL_JoystickGetButton(_joystick.getJoy(), 0);
      pause = SDL_JoystickGetButton(_joystick.getJoy(), 7);
    }
    if (((input.getKey(SDLK_UP) && _idJoy == 0) || z < -10000) || _objs[3] == (int)true)
    {
      _anim = true;
      _z -= clock.getElapsed() * _speed;
      _angle = 270.0f;
      setObjs(3);
    }
    if (((input.getKey(SDLK_DOWN) && _idJoy == 0) || z > 10000) || _objs[4] == (int)true)
    {
      _anim = true;
      _z += clock.getElapsed() * _speed;
      _angle = 90.0f;
      setObjs(4);
    }
    if (((input.getKey(SDLK_LEFT) && _idJoy == 0) || x < -10000) || _objs[6] == (int)true)
    {
      _anim = true;
      _x -= clock.getElapsed() * _speed;
      _angle = 0.0f;
      setObjs(6);
    }
    if (((input.getKey(SDLK_RIGHT) && _idJoy == 0) || x > 10000) || _objs[5] == (int)true)
    {
      _anim = true;
      _x += clock.getElapsed() * _speed;
      _angle = 180.0f;
      setObjs(5);
    }
    if (((input.getKey(SDLK_SPACE) && _idJoy == 0) || a > 0) || _objs[7] == (int)true)
      setObjs(7);
    if ((input.getKey(SDLK_m) || pause > 0) || _objs[8] == (int)true)
      setObjs(8);
    if (_type == 3 || _type == 5)
      _trans = glm::scale(glm::rotate(glm::translate(
						     glm::mat4(1),
						     glm::vec3(_x, _y, _z)),
				      _angle,
				      glm::vec3(0, 1, 0)),
			  glm::vec3(0.002f, 0.002f, 0.002f));
    else
      _trans = glm::scale(glm::rotate(glm::translate(
						     glm::mat4(1),
						     glm::vec3(_x, _y + 0.5, _z)),
				      _angle,
				      glm::vec3(0, 1, 0)),
			  glm::vec3(0.004f, 0.004f, 0.004f));
    // rezObjs();
  }
}

void	Player::draw(__attribute__((unused)) gdl::AShader &shader,
		     __attribute__((unused)) gdl::Clock const &clock)

{
  rezObjs();
  if (((_idJoy < _joystick.joystickCheck()) || (_idJoy == 0)) || _type == 3)
  {
    if (_anim == true)
    {
      if (_frame == 20 || _frame > 45)
      {
	if (_frame > 45)
	  _frame = 21;
	_model[TypeModel]->setCurrentSubAnim("START");
      }
      if (_frame == 30)
	_model[TypeModel]->setCurrentSubAnim("RUN");
      if (_frame == 45)
	_frame = 30;
      _frame += 1;
    }
    if (_anim == false)
    {
      if (_frame > 20 && _frame < 46)
      {
	_model[TypeModel]->setCurrentSubAnim("END");
	_frame = 46;
      }
      if (_frame >= 46 && _frame <= 93)
	_frame += 1;
      if (_frame >= 93)
      {
	_model[TypeModel]->setCurrentSubAnim("RESET");
	_frame = 20;
      }
      if (_frame != 20)
	_frame += 1;
    }
  }
  if (_type == 5)
    shader.setUniform("color", glm::vec4(_idJoy, _idJoy, 0, 1));
  if (_type == 4)
    shader.setUniform("color", glm::vec4(0.0f, 0.5f, 1.0f, 1));
  if (_type == 3)
    shader.setUniform("color", glm::vec4(1, 0, 0, 1));
  if (((_idJoy < _joystick.joystickCheck()) || (_idJoy == 0)) || _type == 3 || _type == 4)
    _model[TypeModel]->draw(shader, _trans, clock.getElapsed());
}

std::vector<int>	Player::getObjs() const
{
  return (_objs);
}

void			Player::setObjs(int type)
{
  size_t		i;

  i = -1;
  while (++i < _objs.size())
  {
    if (type == (int)i)
      {
	if (type == 1)
	  _objs[1] = 0;
	else
	  _objs[i] = !(_objs[i]);
      }
  }
}

void			Player::rezObjs()
{
  size_t		i;

  i = -1;
  while (++i < _objs.size())
  {
    if (i == 2)
      _objs[i] = _joystick.joystickCheck();
    else if (i != 0 && i != 1)
      _objs[i] = (int)false;
  }
}
