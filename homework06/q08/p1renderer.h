
#pragma once

#ifndef __P1RENDERER_H__
#define __P1RENDERER_H__

// Libraries:
#include <stdbool.h>

// Prototypes:
struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct _TTF_Font;


// Renderer stuff


typedef void (*P1RendererCallback)(void);


typedef struct tagMessageTextureLine
{
    struct SDL_Texture* m_pTexture;
    int m_width;
    int m_height;
    struct tagMessageTextureLine* m_pNextLine;
} MessageLine;

typedef struct tagMessageTextAndColour
{
    char* m_message;
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
    struct tagMessageTextAndColour* m_pNextMessage;
} MessageTextAndColour;

enum P1RendererState
{
    RS_NEWLY_CREATED,
    RS_INITIALISING,
    RS_IDLE,
    RS_RENDERERING,
    RS_QUITTING,
    RS_DEAD
};


typedef struct tagP1Renderer
{
    struct SDL_Window* m_pWindow;
    struct SDL_Surface* m_pScreen;
    struct SDL_Renderer* m_pRenderer;
    
    struct SDL_Surface** m_ppBitmaps;
    
    struct _TTF_Font* m_pFont;
        
    int m_width;
    int m_height;
    int m_delayTime;
    
    enum P1RendererState m_state;
    
    int m_bInitialised;
    int m_bRendering;
    int m_bDebugMessages;
    int m_bRobotDebugMessagesAllowed;
    int m_saveScreengrabForEachUpdate;

    int m_fontTextureWidth;
    int m_fontTextureHeight;
    
    P1RendererCallback m_pShutdownCallback;
    
    //CHANGE
    MessageTextAndColour* m_pHeadTextMessage;
    
    char* m_pcStatusTip;
} P1Renderer;

// Public Methods:
P1Renderer* P1RenderergetInstance();

void createP1Renderer(P1Renderer* pThis);
void DestructorP1Renderer(P1Renderer* pThis);

int shutdown_renderer(P1Renderer* pThis, bool quittingEarly);

void activateScreengrabEachUpdate(P1Renderer* pThis);

int getScreenWidth(P1Renderer* pThis);
int getScreenHeight(P1Renderer* pThis);
    
int getCenterX(P1Renderer* pThis);
int getCenterY(P1Renderer* pThis);
    
void showDebugMessages(P1Renderer* pThis, bool b);

void drawDebugText(P1Renderer* pThis, char* pcMessage);
void drawRobotDebugText(P1Renderer* pThis, char* pcMessage, unsigned char r, unsigned char g, unsigned char b);

void drawNextFrame(P1Renderer* pThis);
    
// Drawing between Clear / Present:
void drawLine(P1Renderer* pThis,
              int sx, int sy, int ex, int ey, int width,
              unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        
void drawTextAt(P1Renderer* pThis, int x, int y, char* pcMessage);
// End of Drawing between Clear / Present.

void screengrab(P1Renderer* pThis);
    
void setDelayTime(P1Renderer* pThis, int ms);

void setShutdownCallback(P1Renderer* pThis, P1RendererCallback pFunc);

bool isDebugMessagesOn(P1Renderer* pThis);
int getDebugMessagesWidth(P1Renderer* pThis);
    
void allowRobotDebugMessages(P1Renderer* pThis, bool messagesAllowed);
    
void ConstructorP1Renderer(P1Renderer* pThis);
    
void checkForKeyPress(P1Renderer* pThis);

void clear_frame_buffer(P1Renderer* pThis);
void present(P1Renderer* pThis);

#endif /* __P1RENDERER_H__ */
