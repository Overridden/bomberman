//
// Thread.cpp for bomberman in /home/dovan_n/bomberman/Sources
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Sun Jun 15 12:21:32 2014 Noel DOVAN
// Last update Sun Jun 15 12:53:16 2014 Noel DOVAN
//

#include "GameEngine.hh"
#include "Thread.hh"

Thread::Thread()
{
}

bool			Thread::StartUpdateMoves(void *context)
{
  return (pthread_create(&this->_thread, NULL, &Thread::ThreadUpdateMoves,
			 context) == 0);
}

void			*Thread::ThreadUpdateMoves(void *context)
{
  ((GameEngine*)context)->UpdateMoves(context);
  return NULL;
}
