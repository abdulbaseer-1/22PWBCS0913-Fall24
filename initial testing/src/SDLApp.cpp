#include"SDLApp.hpp"

SDLApp::SDLApp(std::string title, int x, int y, int w, int h) {
    if(SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cerr <<  "Error Could not initialize SDL\n";
    } else {
        std::cout << "SDL video system is good to go\n";
    }
    m_window = SDL_CreateWindow("Simple Audio Api", x, y, w, h , SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1 , SDL_RENDERER_ACCELERATED);

    m_width = w;
    m_height = h;

    m_framecap = 5;       
}
SDLApp::~SDLApp() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void SDLApp::SetEventCallback(void (*func)()) {
    m_EventCallback = func;
}

void SDLApp::SetRenderCalback(void (*func)()) {
    m_RenderCallback = func;
}

void SDLApp::SetUpdateCallback(void (*func)()) {
    m_UpdateCallback = func;
}

void SDLApp::RunLoop() {
    while(m_gameIsRunning){
        Uint32 startTime = SDL_GetTicks();
        m_EventCallback();

        m_UpdateCallback();

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(m_renderer);

        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        m_RenderCallback();

        SDL_RenderPresent(m_renderer);

        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if(elapsedTime < m_framecap) {
            SDL_Delay(m_framecap - elapsedTime);
        }
    }
}