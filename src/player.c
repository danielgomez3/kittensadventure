#include "./headers/player.h"

static SDL_Texture *pete[2];

void initPlayer(void)
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;
	
	pete[0] = loadTexture("gfx/nutty.png");
	pete[1] = loadTexture("gfx/nutty02.png");
	
	player->texture = pete[0];
	
	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
}

void doPlayer(void)
{
	player->dx = 0;
	
	if (app.keyboard[SDL_SCANCODE_A])
	{
		player->dx = -PLAYER_MOVE_SPEED;
		
		player->texture = pete[1];
	}
	
	if (app.keyboard[SDL_SCANCODE_D])
	{
		player->dx = PLAYER_MOVE_SPEED;
		
		player->texture = pete[0];
	}
	
	if (app.keyboard[SDL_SCANCODE_I] && player->isOnGround)
	{
		player->dy = -20;
	}
	
	if (app.keyboard[SDL_SCANCODE_SPACE])
	{
		player->x = player->y = 0;
		
		app.keyboard[SDL_SCANCODE_SPACE] = 0;
	}
}
