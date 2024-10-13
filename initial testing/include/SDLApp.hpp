//A class that will contain all SDL related code. 
#ifndef SDLAPP_HPP
#define SDLAPP_HPP

#include<iostream>
#include"SDL2/SDL.h"

class SDLApp{
    public:
        SDLApp(std::string title, int x, int y, int w, int h);
        ~SDLApp();

     

        void SetEventCallback(void (*func)());
        void SetRenderCalback(void (*func)());
        void SetUpdateCallback(void (*func)());

        void RunLoop();

        inline SDL_Renderer* GetRenderer() {
            return m_renderer;
        }

        inline int GetWindowWidth() {
            return m_width;
        }
        inline int GetWindowHeight() {
            return m_height;
        }

        inline void StopAppLoop() {
            m_gameIsRunning = false;
        }

        inline void SetFrameCap(int cap) { // takes gameloop itteration delay in ms
            m_framecap = cap;
        }

    private:
        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        bool m_gameIsRunning = true;

        void (*m_RenderCallback)();
        void (*m_EventCallback)();
        void (*m_UpdateCallback)();

        int m_width;
        int m_height;  

        int m_framecap;
};

#endif