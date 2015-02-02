//
// Thread.hh for bomberman in /home/dovan_n/bomberman/Includes
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sun Jun 15 12:14:43 2014 Noel DOVAN
// Last update Sun Jun 15 12:53:21 2014 Noel DOVAN
//

#ifndef		THREAD_HH_
# define	THREAD_HH_

# include <pthread.h>

class Thread
{

private:

  pthread_t		_thread;

public:

  Thread();
  virtual ~Thread() {};

  bool			StartUpdateMoves(void *context);

private:

  static void		*ThreadUpdateMoves(void *context);

};

#endif
