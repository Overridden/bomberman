/*
** Joystick.cpp for  in /home/peyrot_m/rendu/cpp_bomberman/Sources
**
** Made by peyrot_m
** Login   <peyrot_m@epitech.net>
**
** Started on  Sat May 31 14:59:53 2014 peyrot_m
** Last update Thu Jun  5 23:12:49 2014 teddy fontaine
*/

#include "Joystick.hh"

Joystick::Joystick()
{
  if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0)
    std::cout << "Error JOYSTICK" << std::endl;
  _clickA = 0;
}

Joystick::~Joystick()
{
}

int			Joystick::joystickCheck()
{
  return (SDL_NumJoysticks());
}

int			Joystick::joystickForMenu(int idJoy, glm::ivec2 new_pos)
{
  _pos = new_pos;
  _clickA = 0;
  _clickB = 0;
  if (joystickCheck() == 0)
    return (0);
  else
  {
    if ((_joy = SDL_JoystickOpen(idJoy)) == NULL)
      return (false);
    return (joystickCheck());
  }
}

int			Joystick::joystickForGame(int idJoy)
{
  if (joystickCheck() == 0)
    return (0);
  else
  {
    if ((_joy = SDL_JoystickOpen(idJoy)) == NULL)
      return (false);
    return (joystickCheck());
  }
}

glm::ivec2		Joystick::joystickNewPos()
{
  SDL_JoystickUpdate();
  unsigned int a = 0;
  unsigned int b = 0;
  unsigned int a_p2 = 0;
  unsigned int b_p2 = 0;
  Sint16 x_move, y_move, rtrigger;

  rtrigger = SDL_JoystickGetAxis(_joy,5);
  x_move = SDL_JoystickGetAxis(_joy,0);
  y_move = SDL_JoystickGetAxis(_joy,1);
  a = SDL_JoystickGetButton (_joy, 0);
  b = SDL_JoystickGetButton (_joy, 1);
  _pos[1] +=  y_move/5000 * (1 + (rtrigger + 32768) / 8000);
  _pos[0] +=  x_move/5000 * (1 + (rtrigger + 32768) / 8000);
  if (a == 1 || a_p2 == 1)
    _clickA = 1;
  else
    _clickA = 0;
  if (b == 1 || b_p2 == 1)
    _clickB = 1;
  else
    _clickB = 0;
  return (_pos);
}

int		Joystick::getButtonClickA()
{
  return (_clickA);
}

int		Joystick::getButtonClickB()
{
  return (_clickB);
}

SDL_Joystick	*Joystick::getJoy()
{
  return (_joy);
}
