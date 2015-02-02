//
// main.cpp for bomberman in /home/dovan_n/bomberman
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Fri May  9 10:09:52 2014 Noel DOVAN
// Last update Mon Jun  9 02:13:16 2014 peyrot_m
//

#include "GameEngine.hh"

bool		envIsValid(char **env)
{
  int		cpt = -1;

  while ((env) && (env[++cpt]))
    if ((std::string(env[cpt]) == "DISPLAY=:0.0") ||
	(std::string(env[cpt]) == "DISPLAY=:0"))
      return (true);
  return (false);
}

int			main(__attribute__((unused))int ac,
			     __attribute__((unused))char **av, char **env)
{
  if (envIsValid(env) == false)
    {
      std::cerr << "Error : Invalid environment." << std::endl;
      return (-1);
    }
  try
    {
      GameEngine	*engine = new GameEngine();
      if (engine->initialize() == false)
	return 1;
      while (engine->update() == true)
	engine->draw();
      delete engine;
    }
  catch (MyException const& e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
    }
  return (0);
}
