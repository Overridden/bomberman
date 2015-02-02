//
// Timeval.hh for  in /home/theron_b/rendu/cpp_bomberman
//
// Made by theron
// Login   <theron_b@epitech.net>
//
// Started on  Mon May 19 10:22:13 2014 theron
// Last update Mon May 19 15:31:10 2014 theron
//

#ifndef TIME_VAL_HH_
# define  TIME_VAL_HH_

# include       <string>
# include       <stdexcept>
# include       <sys/time.h>

class         Timeval
{
public:
  Timeval();
  ~Timeval();

  time_t      getSec() const;
  suseconds_t getUSec() const;
  void                now();
  static const char*  strTime();

private:
  struct timeval      _tv;
};

#endif          // TIMEVAL_HH__
