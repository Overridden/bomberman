//
// Rand.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Thu May 15 16:26:42 2014 Noel DOVAN
// Last update Sun Jun  1 17:45:02 2014 Noel DOVAN
//

#ifndef		RAND_HH_
# define	RAND_HH_

# include <cstdlib>
# include "Time.hh"

class         Rand
{

private:

  Time		time;

public:

  Rand();
  ~Rand();

  int  randVal() const;
  int  randVal(unsigned const max) const;
  int  randVal(int const min, int const max) const;

};


#endif
