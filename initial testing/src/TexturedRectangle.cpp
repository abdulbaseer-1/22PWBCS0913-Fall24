#include"TexturedRectangle.hpp"

        TexturedRectangle::TexturedRectangle(SDL_Renderer* renderer, std::string filepath) {
            m_surface = ResourceManager::GetInstance().GetSurface(filepath);
            if(m_surface == nullptr) {
                std::cerr << "Error could not load surfacein textured rectangle!\n";
            }

            m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
            if(m_texture == nullptr) {
                std::cerr << "Could not load texture in textured rectangle\n";
            }

            m_dstrect.x = 0;
            m_dstrect.y = 0;
            m_dstrect.w = 0;
            m_dstrect.h = 0;

        }
        TexturedRectangle::TexturedRectangle(SDL_Renderer* renderer, std::string filepath, int RedColourKey, int GreenColourKey, int BlueColourKey) {
            m_surface = ResourceManager::GetInstance().GetSurface(filepath);
            if(m_surface == nullptr) {
                std::cerr << "Error could not load surfacein textured rectangle!\n";
            }

            SDL_SetColorKey(m_surface, SDL_TRUE, SDL_MapRGB(m_surface->format, RedColourKey, GreenColourKey, BlueColourKey));

            m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
            if(m_texture == nullptr) {
                std::cerr << "Could not load texture in textured rectangle\n";
            }

            m_dstrect.x = 0;
            m_dstrect.y = 0;
            m_dstrect.w = 0;
            m_dstrect.h = 0;

        }
        TexturedRectangle::~TexturedRectangle() {
            SDL_DestroyTexture(m_texture);
        }

        void TexturedRectangle::SetSrcRectPosition(int x, int y) {
            m_srcrect.x = x; 
            m_srcrect.y = y;
        }
        void TexturedRectangle::SetSrcRectDimension(int w, int h) {
            m_srcrect.w = w;
            m_srcrect.h = h;
        }

        void TexturedRectangle::SetDstRectPosition(int x, int y) {
            m_dstrect.x = x; 
            m_dstrect.y = y;
        }
        void TexturedRectangle::SetDstRectDimension(int w, int h) {
            m_dstrect.w = w;
            m_dstrect.h = h;
        }

        void TexturedRectangle::DrawRect(SDL_Renderer* renderer) { // can use srcRect later
            SDL_RenderCopy(renderer, m_texture, NULL, &m_dstrect);
        }