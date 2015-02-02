//
// MyException.cpp for bomberman in /home/dovan_n/bomberman
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Fri May  9 10:16:53 2014 Noel DOVAN
// Last update Thu May 15 08:20:55 2014 theron
//

#include "MyException.hh"

MyException::MyException(std::string const& error) throw() : Error(error)
{
}

MyException::~MyException() throw()
{
}

char const*		MyException::what() const throw()
{
  return (this->Error.c_str());
}
