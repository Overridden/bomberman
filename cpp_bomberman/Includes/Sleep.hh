//
// Sleep.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Thu May 15 16:44:43 2014 Noel DOVAN
// Last update Thu May 15 16:54:02 2014 Noel DOVAN
//

#ifndef		SLEEP_HH_
# define	SLEEP_HH_

# include <unistd.h>
# include "MyException.hh"

class Sleep
{

public:

  Sleep();
  ~Sleep();

  void			xsleep(unsigned int const seconds) const;
  void			xusleep(useconds_t const usec) const;

};

#endif
