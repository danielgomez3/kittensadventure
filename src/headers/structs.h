typedef struct Texture Texture;
typedef struct Entity Entity;

typedef struct {
	void (*logic)(void);
	void (*draw)(void);
} Delegate;

struct Texture {
	char name[MAX_NAME_LENGTH];
	SDL_Texture *texture;
	Texture *next;
};

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	Delegate delegate;
	int keyboard[MAX_KEYBOARD_KEYS];
	Texture textureHead, *textureTail;
} App;

struct Entity {
	float x;
	float y;
	int w;
	int h;
	float dx;
	float dy;
	int isOnGround;
	SDL_Texture *texture;
	long flags;
	Entity *next;
};

typedef struct {
	SDL_Point camera;
	int map[MAP_WIDTH][MAP_HEIGHT];
	Entity entityHead, *entityTail;
} Stage;
