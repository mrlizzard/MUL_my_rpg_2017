/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** draw header
*/

#ifndef _DRAW_H
#define _DRAW_H

#undef SPRITE_HEIGHT
#define SPRITE_HEIGHT 32

#undef SPRITE_WIDTH
#define SPRITE_WIDTH 32

#undef SPRITESHEET_HEIGHT
#define SPRITESHEET_HEIGHT 4

#undef SPRITESHEET_WIDTH
#define SPRITESHEET_WIDTH 4

typedef enum {
	LEFT,
	RIGHT,
	UP,
	DOWN
} direction_t;

typedef enum {
	STATIC_1,
	WALK_1,
	STATIC_2,
	WALK_2
} state_t;

typedef struct {
	void *draw_item;
	void (*draw)(void *self, sfRenderWindow *window);
	void (*del)(void *self);
} draw_interface_t;

typedef struct {
	sfSprite *map;
	uint8_t id;
	u_int64_t height;
	u_int64_t width;
	tileset_t *tileset;
	sfVertex *layer1;
	sfVertex *layer2;
	uint8_t hidden_layer;
	uint16_t connection_layer;
} map_t;

typedef struct {
	direction_t direction;
	state_t state;
	sfSprite *sprite;
	sfIntRect rect;
} sprite_t;

typedef struct {
	void *anim_item;
	uint8_t delay;
	uint8_t time_0;
	void (*anim)(void *self);
	void (*del)(void *self);
} anim_t;

//interface
draw_interface_t *init_draw_interface(void *draw_item, void (*set_method)(draw_interface_t *draw_interface));
void del_draw_interface(void *self);
//map
map_t *init_map(char const *path);
void draw_map(void *self, sfRenderWindow *window);
void del_map(void *self);
void set_method_sprite(draw_interface_t *draw_interface);
//sprite
sprite_t *init_sprite(char const *path);
void draw_sprite(void *self, sfRenderWindow *window);
void del_sprite(void *self);
void set_method_sprite(draw_interface_t *draw_interface);
void sprite_walk(void *sprite);
void set_method_sprite_anim(anim_t *anim);
//anim
anim_t *init_anim(void *anim_item, u_int32_t delay, void (*set_method)(anim_t *anim));

#endif