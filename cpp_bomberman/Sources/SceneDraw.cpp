/*
**
** SceneDraw.cpp for SceneDraw in /home/sheol/my_git/gdl/src
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Wed May 21 11:27:28 2014 teddy fontaine
// Last update Sun Jun 15 21:59:32 2014 theron
*/

#include "GameEngine.hh"
#include <Model.hh>

/*
 * Draw la Scene
 */
bool		GameEngine::scene()
{
  AObject *cam = new Cam();
  AObject *menu = new Menu(_texture);
  AObject *intro = new Intro();
  AObject *pokemon = new Pokemon();

  if (!cam->initialize(1, 1, 5))
    return (false);
  if (!intro->initialize(0,0,0,9.2,6.89,0))
    return(false);
  if (!menu->initialize(0,0,0,9.2,6.89,0))
    return(false);
  if (!pokemon->initialize(0,0,0,9.2,6.89,0))
    return(false);
  _objects.push_back(cam);
  _objects.push_back(intro);
  _objects.push_back(menu);
  _objects.push_back(pokemon);
  return (true);
}

void		GameEngine::InitGeoOne()
{
  gdl::Geometry*		_cube = new gdl::Geometry();
  gdl::Geometry*		_floor = new gdl::Geometry();

  _floor->pushVertex(glm::vec3(0 + 0.5, 0 + -0.5, 0 + -0.5));
  _floor->pushVertex(glm::vec3(0 + 0.5, 0 + -0.5, 0 + 0.5));
  _floor->pushVertex(glm::vec3(0 + -0.5, 0 + -0.5, 0 + 0.5));
  _floor->pushVertex(glm::vec3(0 + -0.5, 0 + -0.5, 0 + -0.5));
  _floor->pushUv(glm::vec2(0.0f, 1.0f));
  _floor->pushUv(glm::vec2(0.0f, 0.0f));
  _floor->pushUv(glm::vec2(1.0f, 0.0f));
  _floor->pushUv(glm::vec2(1.0f, 1.0f));

  _floor->build();


  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + -0.5, 0 + 0.5));
  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + 0.5, 0 + 0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + 0.5, 0 + 0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + -0.5, 0 + 0.5));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));

  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + -0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + 0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + 0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + -0.5, 0 + -0.5));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));

  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + -0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + 0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + 0.5, 0 + 0.5));
  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + -0.5, 0 + 0.5));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));

  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + -0.5, 0 + 0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + 0.5, 0 + 0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + 0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + -0.5, 0 + -0.5));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));

  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + 0.5, 0 + 0.5));
  _cube->pushVertex(glm::vec3(0 + 0.5, 0 + 0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + 0.5, 0 + -0.5));
  _cube->pushVertex(glm::vec3(0 + -0.5, 0 + 0.5, 0 + 0.5));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));
  _cube->build();
  this->_geometry.push_back(_floor);
  this->_geometry.push_back(_cube);
}

void		GameEngine::InitModelOne()
{
  gdl::Model*		_mod = new gdl::Model();
  gdl::Model*		_mod1 = new gdl::Model();
  gdl::Model*		_mod2 = new gdl::Model();
  gdl::Model*		_mod3 = new gdl::Model();
  gdl::Model*		_mod4 = new gdl::Model();
  gdl::Model*		_mod5 = new gdl::Model();
  gdl::Model*		_mod6 = new gdl::Model();
  gdl::Model*		_mod7 = new gdl::Model();


  _mod->load("./Res/assets/marvin.fbx");
  _mod1->load("./Res/assets/boss.fbx");
  _mod2->load("./Res/assets/bomb.fbx");
  _mod3->load("./Res/assets/maure.fbx");
  _mod4->load("./Res/assets/botte.fbx");
  _mod5->load("./Res/assets/frisbee.fbx");
  _mod6->load("./Res/assets/quad.fbx");
  _mod7->load("./Res/assets/flappy.fbx");

  this->_model.push_back(_mod);
  this->_model.push_back(_mod1);
  this->_model.push_back(_mod2);
  this->_model.push_back(_mod3);
  this->_model.push_back(_mod4);
  this->_model.push_back(_mod5);
  this->_model.push_back(_mod6);
  this->_model.push_back(_mod7);
}

void		GameEngine::InitLoadOne()
{
  gdl::Texture		*_textu = new gdl::Texture();
  gdl::Texture		*_textu0 = new gdl::Texture();
  gdl::Texture		*_textu1 = new gdl::Texture();
  gdl::Texture		*_textu2 = new gdl::Texture();
  gdl::Texture		*_textu3 = new gdl::Texture();
  gdl::Texture		*_textu4 = new gdl::Texture();
  gdl::Texture		*_textu5 = new gdl::Texture();
  gdl::Texture		*_textu6 = new gdl::Texture();
  gdl::Texture		*_textu7 = new gdl::Texture();
  gdl::Texture		*_textu8 = new gdl::Texture();
  gdl::Texture		*_textu9 = new gdl::Texture();
  gdl::Texture		*_textu10 = new gdl::Texture();
  gdl::Texture		*_textu11 = new gdl::Texture();
  gdl::Texture		*_textu12 = new gdl::Texture();
  gdl::Texture		*_textu13 = new gdl::Texture();
  gdl::Texture		*_textu14 = new gdl::Texture();
  gdl::Texture		*_textu15 = new gdl::Texture();
  gdl::Texture		*_textu16 = new gdl::Texture();
  gdl::Texture		*_textu17 = new gdl::Texture();
  gdl::Texture		*_textu18 = new gdl::Texture();

  if ((_textu->load("./Res/textures/menu.tga") == false))
    throw MyException("initialize menu");
  this->_texture.push_back(_textu);
  if ((_textu0->load("./Res/textures/play.tga") == false))
    throw MyException("initialize play");
  this->_texture.push_back(_textu0);
  if ((_textu1->load("./Res/textures/load.tga") == false))
    throw MyException("initialize load");
  this->_texture.push_back(_textu1);
  if ((_textu2->load("./Res/textures/score.tga") == false))
    throw MyException("initialize score");
  this->_texture.push_back(_textu2);
  if ((_textu3->load("./Res/textures/credit.tga") == false))
    throw MyException("initialize credit");
  this->_texture.push_back(_textu3);
  if ((_textu4->load("./Res/textures/pause.tga") == false))
    throw MyException("initialize pause");
  this->_texture.push_back(_textu4);
  if ((_textu5->load("./Res/textures/loose.tga") == false))
    throw MyException("initialize loose");
  this->_texture.push_back(_textu5);
  if ((_textu6->load("./Res/textures/win.tga") == false))
    throw MyException("initialize win");
  this->_texture.push_back(_textu6);
  if (_textu7->load("./Res/textures/grass.tga") == false)
    throw MyException("initialize grass");
  this->_texture.push_back(_textu7);
  if (_textu8->load("./Res/textures/briquevide.tga") == false)
    throw MyException("initialize briquevide");
  this->_texture.push_back(_textu8);
  if (_textu9->load("./Res/textures/brique.tga") == false)
    throw MyException("initialize brique");
  this->_texture.push_back(_textu9);
  if (_textu10->load("./Res/textures/stone.tga") == false)
    throw MyException("initialize stone");
  this->_texture.push_back(_textu10);
  if (_textu11->load("./Res/textures/bombe.tga") == false)
    throw MyException("initialize bombe");
  this->_texture.push_back(_textu11);
  if (_textu12->load("./Res/textures/bonus_bomb.tga") == false)
    throw MyException("initialize bombe bonus");
  this->_texture.push_back(_textu12);
  if (_textu13->load("./Res/textures/bonus_flame.tga") == false)
    throw MyException("initialize bonus flame");
  this->_texture.push_back(_textu13);
  if (_textu14->load("./Res/textures/bonus_speed.tga") == false)
    throw MyException("initialize bonus speed");
  this->_texture.push_back(_textu14);
  if (_textu15->load("./Res/textures/fire.tga") == false)
    throw MyException("initialize fire");
  this->_texture.push_back(_textu15);
  if (_textu16->load("./Res/textures/bonus_frisbee.tga") == false)
    throw MyException("initialize bonus frisbee");
  this->_texture.push_back(_textu16);
  if (_textu17->load("./Res/textures/frisbee.tga") == false)
    throw MyException("initialize  frisbee");
  this->_texture.push_back(_textu17);
  if (_textu18->load("./Res/textures/fire2.tga") == false)
    throw MyException("initialize bonus frisbee");
  this->_texture.push_back(_textu18);
}

bool		GameEngine::scene_for_game()
{

  int		i = 0;
  int		j = 0;

  AObject *mure = new Skybox();

  if (!mure->initialize((this->_width > this->_height ? this->_width/2 : this->_height/2),
  		       (this->_width > this->_height ? this->_width/2 : this->_height/2) - (this->_width > this->_height ? this->_width/2 : this->_height/2) * .2,
  		       (this->_width > this->_height ? this->_width/2 : this->_height/2),
  		       (this->_width > this->_height ? this->_width + 15 : this->_height + 15),
  		       (this->_width > this->_height ? this->_width + 15 : this->_height + 15),
  		       (this->_width > this->_height ? this->_width + 15 : this->_height + 15)))
    return(false);
  if (!mure->initialize(0 ,13,0 ,this->_width,20,this->_height))
    return(false);
  j++;
  _objects.push_back(mure);
  i = 0;
  j = 0;
  while (i < this->_width)
    {
      while (j < this->_height)
  	{
	  AObject *mur = new Cube(_texture, _geometry);
	  if (!mur->initialize(i ,0, j))
	    return(false);
    	  if (this->map->mapGetValueAt(i,j) == '0')
  	    mur->setObjs(0);
  	  if (this->map->mapGetValueAt(i,j) == '1')
  	    mur->setObjs(1);
  	  if (this->map->mapGetValueAt(i,j) == '2')
  	    mur->setObjs(2);
	  mur->setX(i);
	  mur->setY(0);
	  mur->setZ(j);
  	  j++;
  	  _objects.push_back(mur);
  	}
      j = 0;
      i++;
    }
  i = 0;
  j = 0;
  while (i < this->_width)
    {
      while (j < this->_height)
  	{
	  AObject *maure = new Bonus(_model);

	  if (!maure->initialize(i ,0, j))
	    return(false);
  	  maure->setObjs(0);
  	  maure->setX(i);
  	  maure->setZ(j);
  	  _objects.push_back(maure);
  	  j++;
  	}
      j = 0;
      i++;
    }
  std::list<Character*>::const_iterator it(Players.begin());
  while (it != Players.end())
    {
      int	type;

      if ((*it)->getID() == 1)
	type = 5;
      if ((*it)->getID() == 3)
	type = 3;
      if ((*it)->getID() == 4)
	type = 4;
      AObject *player = new Player((*it)->getType(),type, _model);
      if (player->initialize((*it)->getX() ,
  			     -0.5,(*it)->getY() ) == false)
  	throw MyException("player");
      _objects.push_back(player);
      ++it;
    }
  return (true);
}

bool		GameEngine::Init_map()
{
  if (this->_map == 4)
    this->map = new Map(this->_width, this->_height, this->_madness);
  else if (this->_map == 3)
    this->map = new Map('C');
  else if (this->_map == 2)
    this->map = new Map('B');
  else if (this->_map == 1)
    this->map = new Map('A');
  this->_width = this->map->GetMapWidth();
  this->_height = this->map->GetMapHeight();
  if (this->Initplayer(*this->map) == false)
    return(false);
  return (true);
}


 bool		GameEngine::Initplayer(Map &tmap)
{
  std::stringstream     ss;
  std::string           ia = "ia";
  std::string           playeur = "player";

  int		i;
  int		x;
  i = 0;

  this->_joueurFix = this->_joueur;
  while (i < this->_joueur)
    {
      ss << playeur  << i + 1;
      this->Players.push_back(new Character(1, tmap, this->rand, ss.str(), i));
      ss.str("");
      i++;
    }
  x = i;
  i = 0;
  while (i < this->_ia)
    {
      ss << ia  << i + 1;
      this->Players.push_back(new Character
			      (3, tmap, this->rand, ss.str(), i + x));
      ss.str("");
      i++;
    }
  return (true);
}
