	#include "p1renderer.h"

// Local includes:
#include "p1utils.h"

// Library includes:
#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include <assert.h>

//#define SCREENGRAB_EACH_UPDATE

const int kiDelayTime = 250;
const int kiDebugMessageWidth = (128 + 256);
const int kiFontSize = 20;
const int kiTextNewLineGapSize = 20;
#ifdef __APPLE__
const char pFontFilename[] = "test.ttf";
#else
const char pFontFilename[] = P1_RESOURCES"/test.ttf";
#endif //__APPLE__


/* The renderer */

void logErrorAndQuit(char* pMessage)
{
    printf("Error: %s \n", pMessage);
    
    SDL_Quit();
    exit(0);
}


P1Renderer* sm_pRenderer = 0;

void DestructedP1Renderer(P1Renderer* pThis)
{
    if (pThis->m_pShutdownCallback)
    {
        pThis->m_pShutdownCallback();
    }
    
    //Free surfaces
    free(pThis->m_ppBitmaps);
    pThis->m_ppBitmaps = 0;    
    pThis->m_state = RS_DEAD;
}

void checkForKeyPress(P1Renderer* pThis)
{
    if (RS_QUITTING != pThis->m_state)
    {
        bool timeToQuit = false;
        bool changeDelayTo1ms = false;
        bool changeDelayTo1000ms = false;
        bool toggleDebugMessages = false;
        bool doScreengrab = false;
        
        SDL_Event event;
    
        // Process all awaiting events...
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                //printf("1) Key Down %d \n", event.key.keysym.sym);

                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    timeToQuit = true;
                }
                else if (event.key.keysym.sym == SDLK_g)
                {
                    changeDelayTo1ms = true;
                }
                else if (event.key.keysym.sym == SDLK_t)
                {
                    changeDelayTo1000ms = true;
                }
                else if (event.key.keysym.sym == SDLK_d)// && event.key.repeat == 0)
                {
                    toggleDebugMessages = true;
                }
                else if (event.key.keysym.sym == SDLK_SPACE)
                {
                    doScreengrab = true;
                }
            }
        }
        
        // Action any changes...
        if (timeToQuit)
        {
            pThis->m_state = RS_QUITTING;
            drawDebugText(pThis, "*Program stopping early by user!");
            shutdown_renderer(pThis, true);
            logErrorAndQuit("*Program stopped early by user!");
        }
        
        if (changeDelayTo1ms)
        {
            setDelayTime(pThis, 1);
        }
        
        if (changeDelayTo1000ms)
        {
            setDelayTime(pThis, 1000);
        }
        
        if (toggleDebugMessages)
        {
            showDebugMessages(pThis, !pThis->m_bDebugMessages);
        }
        
        if (doScreengrab)
        {
            screengrab(pThis);
        }
    }
}

int shutdown_renderer(P1Renderer* pThis, bool quittingEarly)
{
    pThis->m_state = RS_QUITTING;
    
    if (false == quittingEarly && true == pThis->m_bInitialised)
    {
        pThis->m_pcStatusTip = "*End of Program! Press ESC to quit.";
        drawDebugText(pThis, "*End of Program! Press ESC to quit.");
        
        SDL_Event event;
    
        int quit = 0;
        while (quit == 0)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    quit = 1;
                }
                else
                {
                    if (event.key.type == SDL_KEYDOWN)
                    {
                        //printf("2) Key Down %d \n", event.key.keysym.sym);
                        
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            quit = 1;
                        }
                        else if (event.key.keysym.sym == SDLK_SPACE)
                        {
                            screengrab(pThis);
                        }
                        else if (event.key.keysym.sym == SDLK_d && event.key.repeat == 0)
                        {
                            showDebugMessages(pThis, !pThis->m_bDebugMessages);
                        }
                    }
                }
            }
            
            SDL_Delay(1);
        }
    }
    
    SDL_StopTextInput();
    
    SDL_Quit();
  
    free(pThis);

    sm_pRenderer = 0;
    
    return (0);
}

P1Renderer* P1RenderergetInstance()
{
    if (0 == sm_pRenderer)
    {
        sm_pRenderer = (P1Renderer*) malloc(sizeof(P1Renderer));
        createP1Renderer(sm_pRenderer);
    }
        
    return (sm_pRenderer);
}


void showDebugMessages(P1Renderer* pThis, bool b)
{
    pThis->m_bDebugMessages = b;

    if (pThis->m_bDebugMessages)
    {
        drawDebugText(pThis, "*Debug Messages On!");
    }
    else
    {
        drawDebugText(pThis, "*Debug Messages Off!");
    }
}

void activateScreengrabEachUpdate(P1Renderer* pThis)
{
    pThis->m_saveScreengrabForEachUpdate = 1;
}

void createP1Renderer(P1Renderer* pThis)
{
    pThis->m_ppBitmaps = 0;
    pThis->m_pWindow = 0 ;
    pThis->m_pRenderer = 0;
    pThis->m_width = 0;
    pThis->m_height = 0;
    pThis->m_pShutdownCallback = 0;
    pThis->m_bInitialised = 0;
    pThis->m_bRendering = 0;
    pThis->m_state = RS_NEWLY_CREATED;
    pThis->m_pFont = 0;
    pThis->m_fontTextureWidth = 0;
    pThis->m_fontTextureHeight = 0;
    pThis->m_bDebugMessages = 0;// (false)
    pThis->m_bRobotDebugMessagesAllowed = 1;
    pThis->m_delayTime = kiDelayTime;
    pThis->m_pHeadTextMessage = 0;
    pThis->m_saveScreengrabForEachUpdate = 0;

    pThis->m_state = RS_INITIALISING;

    pThis->m_bInitialised = true;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        pThis->m_bInitialised = false;
        logErrorAndQuit("Video init failed.");
    }

    SDL_DisplayMode displayMode;
    
    for(int i = 0; i < SDL_GetNumVideoDisplays(); ++i)
    {
        int shouldBeZero = SDL_GetCurrentDisplayMode(i, &displayMode);
        
        if (0 != shouldBeZero)
        {
            SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());
        }
        else
        {
            SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz. \n", i, displayMode.w, displayMode.h, displayMode.refresh_rate);
        }
    }
    
    pThis->m_width = displayMode.w;
    pThis->m_height = displayMode.h;

#ifdef __APPLE__
    pThis->m_width = 800;
    pThis->m_height = 600;
#endif // __APPLE__
    
    pThis->m_pWindow = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pThis->m_width, pThis->m_height, SDL_WINDOW_OPENGL);
    
    if (0 == pThis->m_pWindow)
    {
        pThis->m_bInitialised = false;
        logErrorAndQuit("Window init failed.");
    }
    
    pThis->m_pRenderer = SDL_CreateRenderer(pThis->m_pWindow, -1, SDL_RENDERER_SOFTWARE);
    if (pThis->m_pRenderer == 0)
    {
        pThis->m_bInitialised = false;
        logErrorAndQuit("Create renderer failed.");
    }
    
    pThis->m_pScreen = SDL_GetWindowSurface(pThis->m_pWindow);
    SDL_SetSurfaceBlendMode(pThis->m_pScreen, SDL_BLENDMODE_BLEND);
    pThis->m_bRendering = true;
    
    if (TTF_Init() != 0)
    {
        pThis->m_bInitialised = false;
        logErrorAndQuit("Font init failed.");
    }
    
    pThis->m_pFont = TTF_OpenFont(pFontFilename, kiFontSize);
    if (0 == pThis->m_pFont)
    {
        pThis->m_bInitialised = false;
        logErrorAndQuit("Font load failed.");
    }
    
    SDL_StartTextInput();
    
    pThis->m_pcStatusTip = " ";
    
    pThis->m_state = RS_IDLE;
       
    pThis->m_bInitialised = true;
    clear_frame_buffer(pThis);
    drawDebugText(pThis, "*Start of Program!");
}


void clear_frame_buffer(P1Renderer* pThis)
{
    assert(pThis->m_bInitialised);
    assert(pThis->m_bRendering);

    assert(pThis->m_pScreen);
    
    SDL_FillRect(pThis->m_pScreen, 0, 0xFFBBBBBB);
}

void present(P1Renderer* pThis)
{
    assert(pThis->m_bInitialised);
    assert(pThis->m_bRendering);
    
    SDL_FreeSurface(pThis->m_pScreen);
    
    SDL_UpdateWindowSurface(pThis->m_pWindow);
    
    pThis->m_bRendering = false;
    
    pThis->m_pScreen = SDL_GetWindowSurface(pThis->m_pWindow);
    SDL_SetSurfaceBlendMode(pThis->m_pScreen, SDL_BLENDMODE_BLEND);
    pThis->m_bRendering = true;
}


void drawTextAt(P1Renderer* pThis, int x, int y, char* pcMessage)
{
    SDL_Color colour;
    colour.r = 0xFF;
    colour.g = 0xFF;
    colour.b = 0xFF;
    
    SDL_Surface* newSurface = TTF_RenderText_Solid(pThis->m_pFont, pcMessage, colour);
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(pThis->m_pRenderer, newSurface);
    
    SDL_FreeSurface(newSurface);
    
    // Copy texture to renderer:
    SDL_Rect srcRect;
    SDL_Rect destRect;

    int h = newSurface->h;
    int w = newSurface->w;
    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = w;
    srcRect.h = h;
    
    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;
    
    SDL_RenderCopy(pThis->m_pRenderer, newTexture, &srcRect, &destRect);
    
    SDL_DestroyTexture(newTexture);
}

void screengrab(P1Renderer* pThis)
{
    assert(pThis->m_bInitialised);
    
    static int screenshotCount = 1;
    
    char filename[128];
    sprintf(filename, "screenshot%d.png", screenshotCount);
    
    char message[128];
    sprintf(message, "Saving %s", filename);
    
    if (0 == pThis->m_saveScreengrabForEachUpdate)
    {
        drawDebugText(pThis, message);
    }
    
    ++screenshotCount;
    
    int w = 0;
    int h = 0;
    
    SDL_GetRendererOutputSize(pThis->m_pRenderer, &w, &h);
    
    SDL_Surface* pScreenShot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    
    SDL_RenderReadPixels(pThis->m_pRenderer, NULL, SDL_PIXELFORMAT_ARGB8888, pScreenShot->pixels, pScreenShot->pitch);
    
    IMG_SavePNG(pScreenShot, filename);
    
    SDL_FreeSurface(pScreenShot);
    
}

void setShutdownCallback(P1Renderer* pThis, P1RendererCallback pFunc)
{
    pThis->m_pShutdownCallback = pFunc;
}

void drawNextFrame(P1Renderer* pThis)
{
    if (false == pThis->m_bInitialised)
    {
        return;
    }
    
    
/*    if (RS_QUITTING == pThis->m_state)
    {
        return;
    }*/
    
//    clear_frame_buffer(pThis);;    
    
    // Draw debug messages:
    if (pThis->m_bDebugMessages)
    {
        SDL_Rect backgroundRect;
        
        backgroundRect.x = pThis->m_width - (kiDebugMessageWidth);
        backgroundRect.y = 0;
        backgroundRect.w = kiDebugMessageWidth;
        backgroundRect.h = pThis->m_height;
        
        SDL_FillRect(pThis->m_pScreen, &backgroundRect, 0xFF000000);

        int maxNumMessages = (pThis->m_height / kiTextNewLineGapSize);
        
        MessageTextAndColour* pCurrent = pThis->m_pHeadTextMessage;
        
        int countNumMessages = 0;
        while (pCurrent)
        {
            ++countNumMessages;
            
            pCurrent = pCurrent->m_pNextMessage;
        }
        
        //Must Clear out old messages...
        if (countNumMessages > maxNumMessages)
        {
            //FREE SOME!!!
            int numToFree = countNumMessages - maxNumMessages;
            
            for (int i = 0; i < numToFree; ++i)
            {
                pThis->m_pHeadTextMessage = pThis->m_pHeadTextMessage->m_pNextMessage; //LEAK!
            }
        }
        
        // Create texture from messages:
        MessageLine* pHeadMsgLineTextures = 0;
        
        MessageTextAndColour* pCurrentText = pThis->m_pHeadTextMessage;
        while (pCurrentText)
        {
            SDL_Color colour;
            colour.r = pCurrentText->m_r;
            colour.g = pCurrentText->m_g;
            colour.b = pCurrentText->m_b;
            
            SDL_Surface* newSurface = TTF_RenderText_Solid(pThis->m_pFont, pCurrentText->m_message, colour);
            SDL_Texture* newTexture = SDL_CreateTextureFromSurface(pThis->m_pRenderer, newSurface);
            
            MessageLine* pNewLine = malloc(sizeof(MessageLine)); //LEAK
            pNewLine->m_pTexture = newTexture;
            pNewLine->m_width = newSurface->w;
            pNewLine->m_height = newSurface->h;
            pNewLine->m_pNextLine = 0;
            
            if (pHeadMsgLineTextures == 0)
            {
                pHeadMsgLineTextures = pNewLine;
            }
            else
            {
                MessageLine* pCurrentLine = pHeadMsgLineTextures;
                
                while (pCurrentLine->m_pNextLine)
                {
                    pCurrentLine = pCurrentLine->m_pNextLine;
                }
                
                pCurrentLine->m_pNextLine = pNewLine;
            }
        
            SDL_FreeSurface(newSurface);
            
            pCurrentText = pCurrentText->m_pNextMessage;
        }
        
        // Copy texture to renderer:
        SDL_Rect srcRect;
        SDL_Rect destRect;
    
        int offset = 0;
        
        MessageLine* pCurrentLine = pHeadMsgLineTextures;
        
        while (pCurrentLine)
        {
            int h = pCurrentLine->m_height;// (*messageIter).m_height;
            int w = pCurrentLine->m_width;//(*messageIter).m_width;
        
            int x = backgroundRect.x;
            int y = offset;
        
            srcRect.x = 0;
            srcRect.y = 0;
            srcRect.w = w;
            srcRect.h = h;
        
            destRect.x = x;
            destRect.y = y;
            destRect.w = w;
            destRect.h = h;
        
            offset += kiTextNewLineGapSize;
        
            SDL_RenderCopy(pThis->m_pRenderer, pCurrentLine->m_pTexture, &srcRect, &destRect);
      
            SDL_DestroyTexture(pCurrentLine->m_pTexture);
        
            pCurrentLine = pCurrentLine->m_pNextLine;
        }
        
        //pThis->m_messageTextures.clear();*/
    }
    else
    {
/*        pThis->m_textMessages.clear();*/
    }
    
    if (pThis->m_state != RS_QUITTING)
    {
        if (false == pThis->m_bRobotDebugMessagesAllowed)
        {
            pThis->m_pcStatusTip = "Robot Debug Messages: NOT PREMITTED!";
        }
    }
    
    drawTextAt(pThis, 0, pThis->m_height - kiTextNewLineGapSize, pThis->m_pcStatusTip);
    
    present(pThis);

    //SCREENGRAB EACH UPDATE:
    if (pThis->m_saveScreengrabForEachUpdate)
    {
        screengrab(pThis);
    }
    
    // Sleep the simulation:
    SDL_Delay(pThis->m_delayTime);
    
    // Poll input:
    if (RS_QUITTING != pThis->m_state)
    {
        checkForKeyPress(pThis);
    }
}


void addDebugMessage(P1Renderer* pThis, char* pcMessage, unsigned char r, unsigned char g, unsigned char b)
{
    MessageTextAndColour* newmtc = malloc(sizeof(MessageTextAndColour)); //LEAK
    
    long len = strlen(pcMessage);
    
    newmtc->m_message = malloc((sizeof(char) * len) + 1); //LEAK?
    
    strcpy(newmtc->m_message, pcMessage);
    
    newmtc->m_r = r;
    newmtc->m_g = g;
    newmtc->m_b = b;
    newmtc->m_pNextMessage = 0;
    
    MessageTextAndColour* pCurrent = pThis->m_pHeadTextMessage;
    if (pCurrent == 0)
    {
        pThis->m_pHeadTextMessage = newmtc;
    }
    else
    {
        while (pCurrent->m_pNextMessage)
        {
            pCurrent = pCurrent->m_pNextMessage;
        }
        
        pCurrent->m_pNextMessage = newmtc;
    }
}

void drawDebugText(P1Renderer* pThis, char* pcMessage)
{
    addDebugMessage(pThis, pcMessage, 0xFF, 0xFF, 0xFF);
    
    drawNextFrame(pThis);
}

void drawRobotDebugText(P1Renderer* pThis, char* pcMessage, unsigned char r, unsigned char g, unsigned char b)
{
    if (pThis->m_bRobotDebugMessagesAllowed)
    {
        addDebugMessage(pThis, pcMessage, r, g, b);
    }

    drawNextFrame(pThis);
}


void setDelayTime(P1Renderer* pThis, int ms)
{
    if (ms > 0)
    {
        pThis->m_delayTime = ms;
        
        char message[128];
        sprintf(message, "*Delay time set to: %i ms", ms);
        
        drawDebugText(pThis, message);
    }
}

int getScreenWidth(P1Renderer* pThis)
{
    return (pThis->m_width);
}

int getScreenHeight(P1Renderer* pThis)
{
    return (pThis->m_height);
}

int getCenterX(P1Renderer* pThis)
{
    return (getScreenWidth(pThis) / 2);
}

int getCenterY(P1Renderer* pThis)
{
    return (getScreenHeight(pThis) / 2);
}

bool isDebugMessagesOn(P1Renderer* pThis)
{
    return (pThis->m_bDebugMessages);
}

int getDebugMessagesWidth(P1Renderer* pThis)
{
    return (kiDebugMessageWidth);
}

void allowRobotDebugMessages(P1Renderer* pThis, bool messagesAllowed)
{
    pThis->m_bRobotDebugMessagesAllowed = messagesAllowed;
    
    if (false == pThis->m_bRobotDebugMessagesAllowed)
    {
        drawDebugText(pThis, "*Robot Debug Messages: NOT PREMITTED!");
    }
}

