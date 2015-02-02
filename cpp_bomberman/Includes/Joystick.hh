/*
** Joystick.hh for  in /home/peyrot_m/rendu/cpp_bomberman/Sources
**
** Made by peyrot_m
** Login   <peyrot_m@epitech.net>
**
** Started on  Sat May 31 15:02:00 2014 peyrot_m
** Last update Thu Jun  5 19:54:47 2014 teddy fontaine
*/

#ifndef		JOYSTICK_HH_
# define	JOYSTICK_HH_

#include <SdlContext.hh>
#include <sstream>
#include <iostream>

class		Joystick
{
  private:
    SDL_Joystick*	_joy;
    glm::ivec2		_pos;
    int			_clickA;
    int			_clickB;

  public:
    Joystick();
    ~Joystick();
    int			joystickCheck();
    int			joystickForMenu(int, glm::ivec2 new_pos);
    int			joystickForGame(int);
    glm::ivec2		joystickNewPos();
    int			getButtonClickA();
    int			getButtonClickB();
    SDL_Joystick		*getJoy();
};

#endif /* !JOYSTICK_HH_ */
