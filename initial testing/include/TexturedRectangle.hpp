#ifndef TEXTUREDRECTANGLE_HPP
#define TEXTUREDRECTANGLE_HPP

#include<iostream>
#include"SDL2/SDL.h"
#include"ResourceManager.hpp"

class TexturedRectangle {
    public:
        TexturedRectangle(SDL_Renderer* renderer, std::string filepath);
        TexturedRectangle(SDL_Renderer* renderer, std::string filepath, int RedColourKey, int GreenColourKey, int BlueColourKey);
        ~TexturedRectangle();

        void SetSrcRectPosition(int x, int y);
        void SetSrcRectDimension(int w, int h);

        void SetDstRectPosition(int x, int y);
        void SetDstRectDimension(int w, int h);

        void SetColourKeys(int RedColourKey, int GreenColourKey, int BlueColourKey) {
            m_RedColourKey = RedColourKey;
            m_GreenColourKey = GreenColourKey;
            m_BlueColourKey = BlueColourKey;
        }

        inline SDL_Rect& GetDstRect() {
            return m_dstrect;
        }

        inline int GetDstPosX() {
            return m_dstrect.x;
        }
        inline int GetDstPosY() {
            return m_dstrect.y;
        }
        inline int GetDstWidth() {
            return m_dstrect.w;
        }
        inline int GetDstHeight() {
            return m_dstrect.h;
        }

        void DrawRect(SDL_Renderer* renderer);

    private:
        SDL_Surface* m_surface = nullptr;
        SDL_Texture* m_texture = nullptr;

        SDL_Rect m_srcrect;
        SDL_Rect m_dstrect;

        int m_RedColourKey;
        int m_GreenColourKey;
        int m_BlueColourKey;
};

#endif