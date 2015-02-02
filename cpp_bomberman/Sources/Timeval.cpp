//
// Timeval.cpp for  in /home/theron_b/rendu/cpp_bomberman
//
// Made by theron
// Login   <theron_b@epitech.net>
//
// Started on  Mon May 19 10:25:27 2014 theron
// Last update Mon May 19 15:32:55 2014 theron
//

#include "MyException.hh"
#include "Timeval.hh"

Timeval::Timeval()
{
  this->now();
}

Timeval::~Timeval()
{}

time_t        Timeval::getSec() const
{
  return (this->_tv.tv_sec);
}

suseconds_t   Timeval::getUSec() const
{
  return (this->_tv.tv_usec);
}

void  Timeval::now()
{
  if (gettimeofday(&this->_tv, NULL) == -1)
    throw MyException("Timeval: gettimeofday");
}
