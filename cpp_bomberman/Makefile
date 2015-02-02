##
## Makefile for bomberman in /home/dovan_n/bomberman
##
## Made by Noel DOVAN
## Login   <dovan_n@epitech.net>
##
## Started on  Wed May 28 17:42:04 2014 Noel DOVAN
## Last update Sun Jun 15 23:34:56 2014 Noel DOVAN
##

CC=	g++

RM=	rm -f

NAME=	bomberman

SRCS=			main.cpp			\
			Sources/AObject.cpp		\
			Sources/Carre.cpp		\
			Sources/Bonus.cpp		\
			Sources/Bombe.cpp		\
			Sources/Cube.cpp		\
			Sources/Character.cpp		\
			Sources/GameEngine.cpp		\
			Sources/Intro.cpp		\
			Sources/Joystick.cpp		\
			Sources/Pokemon.cpp		\
			Sources/Player.cpp		\
			Sources/Menu.cpp		\
			Sources/Map.cpp			\
			Sources/MyException.cpp		\
			Sources/Cam.cpp			\
			Sources/SceneDraw.cpp		\
			Sources/Rand.cpp		\
			Sources/Skybox.cpp		\
			Sources/Score.cpp		\
			Sources/Sleep.cpp		\
			Sources/ScoreElem.cpp		\
			Sources/Time.cpp		\
			Sources/Timeval.cpp		\
			Sources/Save.cpp		\
			Sources/GetSetForSave.cpp	\
			Sources/SoundManager.cpp	\
			Sources/Updateall.cpp		\

OBJS=	$(SRCS:.cpp=.o)

GDL=		-L./gdl/libs	\
		-lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread \
		-Wl,--rpath=./gdl/libs/ -Wl,--rpath=./Res/fmodex/lib -L./Res/fmodex/lib/

INCLUDES=	-I./Includes -I./gdl/includes -I./Res/fmodex/inc/

ERR_FLAGS=	-W -Wall -Werror -Wextra

CXXFLAGS+=	$(ERR_FLAGS)
CXXFLAGS+=	$(INCLUDES)

all:	$(NAME)

$(NAME):	$(OBJS)
	@ echo -e "Compilation of \033[31;1m$(NAME)\033[m starting...";
	$(CC) -o $(NAME) $(OBJS) $(GDL) -ldl -lfmodex64
	@ echo -e "\033[31;1mCompilation has finished sucessfully.\033[m";

clean:
	$(RM) $(OBJS)
	@ echo -e "\033[35;1mClean done.\033[m"

fclean:	clean
	$(RM) $(NAME)
	@ echo -e "\033[35mFclean $(NAME) done.\033[m"

.cpp.o:
		@ g++ -c -o $@ $< $(INCLUDES) $(ERR_FLAGS) \
		&& echo -e "File" "\"\033[36m"$<"\033[m\" to \"\033[33m"$@"\033[m\" with flags \"\033[32m"$(ERR_FLAGS)"\033[m\" => \033[31;1mOk.\033[m" || (echo -e "File" "\"\033[31m"$<"\033[m\" => \033[31mERROR\033[m." && exit 1)

re:	fclean all

.PHONY:	all clean fclean re
