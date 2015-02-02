//
// MyException.hh for bomberman in /home/dovan_n/bomberman
//
// Made by Noel DOVAN
// Login   <dovan_n@epitech.net>
//
// Started on  Fri May  9 10:15:20 2014 Noel DOVAN
// Last update Fri May  9 10:16:42 2014 Noel DOVAN
//

#ifndef		MYEXCEPTION_HH_
# define	MYEXCEPTION_HH_

# include <iostream>
# include <exception>

class MyException : public std::exception
{

private:

  std::string const		Error;

public:

  MyException(std::string const& error) throw();
  ~MyException() throw();

  char const*			what() const throw();

};

#endif
