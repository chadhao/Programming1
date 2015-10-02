
#include "p1image.h"
#include "p1renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


/* Framework Functions: */

void turn_on_debug_output()
{
    showDebugMessages(P1RenderergetInstance(), true);
}
    
void turn_off_debug_output()
{
    showDebugMessages(P1RenderergetInstance(), false);
}

void set_delay_time(int milliseconds)
{
    setDelayTime(P1RenderergetInstance(), milliseconds);
}

void print_stub(char* pMessage)
{
    drawDebugText(P1RenderergetInstance(), pMessage);
}

int p1world_shutdown()
{
    return (shutdown_renderer(P1RenderergetInstance(), 0));
}

/* Utils */


int get_random(int low, int high)
{
    int range = (high - low) + 1;
    
    int randomDelta = rand() % range;
    
    int randomNumber = randomDelta + low;
    
    return (randomNumber);
}



// Internal vector of images, only increases in size

SDL_Surface** surfaces = 0;
int surface_count = 1;		// 0 is the screen surface
size_t surface_capacity = 0;


void create_image_world()
{
	P1RenderergetInstance();
	surfaces = malloc(sizeof(SDL_Surface*));
	int flags = 0; //IMG_INIT_PNG;
/*	if (! ( IMG_Init(flags) & flags ))
	{
		drawDebugText(P1RenderergetInstance(), "Failed to IMG_Init()");
		char err_message[1024];
		sprintf(err_message, "%s", IMG_GetError());
		fprintf(stderr, "%s\n", err_message);
		drawDebugText(P1RenderergetInstance(), err_message);		
	}*/
	drawDebugText(P1RenderergetInstance(), "Created image world");
}

int add_surface(SDL_Surface* surface) 
{
	if (surface_count >= surface_capacity)
	{
		surface_capacity = surface_count + 1 + (surface_count / 2);
		surfaces = realloc(surfaces, surface_capacity * sizeof(SDL_Surface*));
	}
	surfaces[surface_count] = surface;
	return surface_count++;
}


// 'Public' interface

int get_screen_image()
{
	return 0;
}

int create_image(int width, int height)
{
	SDL_Surface* surface = 	SDL_CreateRGBSurface(0, width, height, 32, 
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_FillRect(surface, 0, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
	SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_BLEND);	
	char message[128];
	sprintf(message, "Create image %d with dimensions width %d, height %d", 
		surface_count, width, height);
	drawDebugText(P1RenderergetInstance(), message);
	return add_surface(surface);
}

int grab_image(int x, int y, int width, int height)
{
	SDL_Rect rect = { x, y, width, height };
	SDL_Surface* grabbed = SDL_CreateRGBSurface(0, width, height, 32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(P1RenderergetInstance()->m_pRenderer, &rect, 
		SDL_PIXELFORMAT_ARGB8888, grabbed->pixels, grabbed->pitch);
	SDL_SetSurfaceBlendMode(grabbed, SDL_BLENDMODE_BLEND);
	char message[128];
	sprintf(message, "Grabbed image %d from (%d, %d), (%d, %d)", 
		surface_count, x, y, x + width - 1, y + height - 1);
	drawDebugText(P1RenderergetInstance(), message);
	return add_surface(grabbed);
}

int load_bmp(char* filename)
{
	SDL_Surface* image;
	SDL_RWops* rwops;
	rwops = SDL_RWFromFile(filename, "rb");
	char message[128];
	if(!rwops)
	{
		sprintf(message, "Failed open image file %s,", filename);
		drawDebugText(P1RenderergetInstance(), message);
		return -1;
	}
	else
	{
		image = IMG_LoadBMP_RW(rwops);
		if(!image)
		{
			char err_message[1024];
			sprintf(err_message, "%s", IMG_GetError());
			sprintf(message, "Failed to load image from %s", filename);
			drawDebugText(P1RenderergetInstance(), message);
			drawDebugText(P1RenderergetInstance(), err_message);
			return -1;
		}
		else
		{
			SDL_Surface* converted = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_ARGB8888, 0);
			SDL_FreeSurface(image);
			SDL_SetSurfaceBlendMode(converted, SDL_BLENDMODE_BLEND);
			sprintf(message, "Loaded image %d from %s", surface_count, filename);
			drawDebugText(P1RenderergetInstance(), message);
			return add_surface(converted);
		}
	}
}

int load_gif(char* filename)
{
	SDL_Surface* image;
	SDL_RWops* rwops;
	rwops = SDL_RWFromFile(filename, "rb");
	char message[128];
	if(!rwops)
	{
		sprintf(message, "Failed open image file %s,", filename);
		drawDebugText(P1RenderergetInstance(), message);
		return -1;
	}
	else
	{
		image = IMG_LoadGIF_RW(rwops);
		if(!image)
		{
			char err_message[1024];
			sprintf(err_message, "%s", IMG_GetError());
			sprintf(message, "Failed to load image from %s", filename);
			drawDebugText(P1RenderergetInstance(), message);
			drawDebugText(P1RenderergetInstance(), err_message);
			return -1;
		}
		else
		{
			SDL_SetSurfaceBlendMode(image, SDL_BLENDMODE_BLEND);
			sprintf(message, "Loaded image %d from %s", surface_count, filename);
			drawDebugText(P1RenderergetInstance(), message);
			return add_surface(image);
		}
	}
}


int save_jpg(int handle, char* filename)
{
	surfaces[0] = P1RenderergetInstance()->m_pScreen;
	char message[128];
	int result = IMG_SavePNG(surfaces[handle], filename);
	if(result)
	{
		char err_message[1024];
		sprintf(err_message, "%s", IMG_GetError());
		sprintf(message, "Failed to save image to %s", filename);
		drawDebugText(P1RenderergetInstance(), message);
		drawDebugText(P1RenderergetInstance(), err_message);
	}
	else
	{
		sprintf(message, "Save image %d to %s", handle, filename);
		drawDebugText(P1RenderergetInstance(), message);
	}
	return result;
}

int get_image_width(int handle)
{
	surfaces[0] = P1RenderergetInstance()->m_pScreen;
	return surfaces[handle]->w;
}

int get_image_height(int handle)
{
	surfaces[0] = P1RenderergetInstance()->m_pScreen;
	return surfaces[handle]->h;
}

int get_screen_width()
{
	return get_image_width(0);
}

int get_screen_height()
{
	return get_image_height(0);
}

void put_image(int handle, int x, int y)
{
	surfaces[0] = P1RenderergetInstance()->m_pScreen;
	SDL_Rect src_rect = { 0, 0, surfaces[handle]->w, surfaces[handle]->h };
	SDL_Rect dest_rect = { x, y, surfaces[handle]->w, surfaces[handle]->h };
	SDL_BlitSurface(surfaces[handle], &src_rect, surfaces[0], &dest_rect);

	char message[128];
	sprintf(message, "Rendered image %d at (%d, %d)", handle, x, y);
	drawDebugText(P1RenderergetInstance(), message);
}

unsigned char* get_pixel_bytes(int handle)
{
	surfaces[0] = P1RenderergetInstance()->m_pScreen;
	return (unsigned char *)surfaces[handle]->pixels;
}

void free_image(int handle)
{
	surfaces[0] = P1RenderergetInstance()->m_pScreen;
	SDL_FreeSurface(surfaces[handle]);
	surfaces[handle] = 0;
}

