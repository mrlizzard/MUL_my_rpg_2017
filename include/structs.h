/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** structs header file
*/

# ifndef STRUCT_RPG_H
# define STRUCT_RPG_H

# include <SFML/Audio.h>
# include <SFML/Config.h>
# include <SFML/Graphics.h>
# include <SFML/Network.h>
# include <SFML/OpenGL.h>
# include <SFML/System.h>
# include <SFML/Window.h>
# include <SFML/System.h>

# include <time.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <dirent.h>

// Struct prototypes
struct 	texture_t;
struct 	button_t;
struct 	slider_t;
struct 	assets_t;
struct 	options_t;
struct 	rpg_t;
struct	battle_t;

// Enumerations declarations
typedef enum state_e {
	gameUnknown,
	gameWait,
	gameRun,
	gameEnd,
	gamePause,
	gameOnSettings,
	gameOnCredits,
	gameHistory,
	gameBattle,
	gameSelect,
	gameQuitWSave
}	state_e;

// Structs declarations
typedef struct texture_t {
	char 		*name;
	char 		*file;
	sfTexture 	*texture;
	sfSprite 	*sp;
} 	texture_t;

typedef struct button_t {
	char		*name;
	sfVector2f	pos;
	void 		(*onClick)(struct rpg_t *, struct button_t *);
	void 		(*onHover)(struct rpg_t *, struct button_t *);
	void 		(*onStart)(struct rpg_t *, struct button_t *);
	state_e 	state;
	sfSprite 	*sprite;
	sfIntRect 	rect;
	sfIntRect 	normal_rect;
	bool		pressed;
	bool		hovered;
	struct button_t *next;
} 	button_t;

typedef struct slider_t {
	char 		*name;
	sfVector2f	range;
	sfText		*text;
	int 		mid_axis;
	void 		(*onSlide)(struct rpg_t *, struct slider_t *);
	state_e 	state;
	button_t 	*btn;
	struct slider_t *next;
} 	slider_t;

typedef struct assets_t {
	char 		*name;
	char 		*file;
	sfTexture 	*texture;
	sfSprite 	*sp;
	sfIntRect 	rec;
	struct assets_t *next;
} 	assets_t;

typedef struct sound_t {
	char 		*name;
	char 		*file;
	sfSoundBuffer	*buffer;
	sfSound 	*sound;
	struct sound_t 	*next;
}	sound_t;

typedef struct options_t {
	float 		sound_vol;
	float 		music_vol;
} 	options_t;

// BEGIN BATTLE STRUCTS
typedef struct enemy {
	sfIntRect rec;
	sfSprite *form;
	sfRectangleShape *frame;
	sfTexture *img;
	sfVector2f pos;
	bool alive;
	bool played;
	int hp;
	int dmg;
	int armor;
} enemy_t;

typedef struct fight {
	sfRectangleShape **map;
	sfVector2f pos;
	int number_enemy;
	enemy_t **enemy;
	bool enemy_turn;
} fight_t;

typedef struct hero {
	sfIntRect rec;
	sfSprite *form;
	sfTexture *img;
	sfVector2f pos;
	sfVector2f new;
	bool alive;
	bool select;
	bool played;
	bool move;
	bool attack;
	int target;
	int hp;
	int dmg;
	int armor;
} hero_t;

typedef struct battle {
	bool run;
	sfVector2f mouse;
	int id;
	int **map;
	int number_fight;
	hero_t *hero;
	fight_t **fight;
	sfRectangleShape *icone;
	sfRectangleShape *background;
	sfTexture **texture;
	sfText *text;
	sfTime time;
	sfClock *clock;
} battle_t;
// END BATTLE STRUCT

typedef struct rpg_t {
	sfRenderWindow	*win;
	sfFont		*font;
	state_e		state;
	sfSprite	*capture;
	state_e		last_st;
	sfClock		*clock;
	sound_t		*sounds;
	options_t	options;
	assets_t	*assets;
	button_t	*btn;
	slider_t	*slides;
	battle_t	*battle;
}	rpg_t;

# endif
