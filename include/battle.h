/*
** EPITECH PROJECT, 2018
** battle
** File description:
** rpg
*/

#ifndef BATTLE
#define BATTLE

#define MAP_X 225
#define MAP_Y 180
#define B_X 114
#define B_Y 72

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
	sfFont *font;
	sfText *text;
	sfTime time;
	sfClock *clock;
} battle_t;

void battle_management(rpg_t *rpg, battle_t *battle);

/* FREE */
void free_all(rpg_t *rpg);

/* DISPLAY */
void display_map(rpg_t *rpg, battle_t *battle, int id);
void display_interface(rpg_t *rpg, battle_t *battle);
void display_enemy_stats(rpg_t *rpg, sfVector2f coord);
void display_current_target(battle_t *battle);
void fill_map_state(battle_t *battle, int id);
void draw_all(rpg_t *rpg);
void display_hero(rpg_t *rpg, battle_t *battle);
void display_enemy(rpg_t *rpg, battle_t *battle);

/* HERO */
void check_deplacement(battle_t *battle);
void check_attack(battle_t *battle);
void hero_deplacement(rpg_t *rpg, battle_t *battle);
void hero_attack(rpg_t *rpg, battle_t *battle);
void set_color(battle_t *battle, int nb, sfColor color);

/* AI_ENEMY */
void enemy_turn(rpg_t *rpg, battle_t *battle);
bool check_enemy_attack(rpg_t * rpg, battle_t *battle, int x, sfVector2f pos);
void enemy_attack_anim(rpg_t * rpg, battle_t *battle, sfVector2f pos);
bool enemy_go_left(rpg_t * rpg, battle_t *battle, int x, sfVector2f pos);
bool enemy_go_right(rpg_t * rpg, battle_t *battle, int x, sfVector2f pos);
bool enemy_go_up(rpg_t * rpg, battle_t *battle, int x, sfVector2f pos);
bool enemy_go_down(rpg_t * rpg, battle_t *battle, int x, sfVector2f pos);

/* EVENT */
void battle_event_management(rpg_t *rpg, battle_t *battle);
void reset_map_state(battle_t *battle);
void change_turn(battle_t *battle);

/*EVENT->INTERACTION*/
void interaction(battle_t *battle, sfEvent event);
void select_or_unselect(battle_t *battle, int i);

/*EVENT->DEPLACEMENT->HERO*/
void deplacement(battle_t *battle);

/*EVENT->ATTACK*/
void attack(battle_t *battle);

/* INIT */
void configure_battle(rpg_t *rpg);
void init_fight(battle_t *battle);
void init_hero(battle_t *battle);

sfText *create_text(sfFont *font, char *str, sfVector2f pos, sfColor color);
char *my_itoa(int n);

#endif
