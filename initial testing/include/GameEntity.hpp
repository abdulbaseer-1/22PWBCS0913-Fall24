#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

#include<iostream>
#include<vector>

#include"SDL2/SDL.h"
#include"TexturedRectangle.hpp"
#include"BoxCollider2D.hpp"

class GameEntity {
    public:
        GameEntity(SDL_Renderer* renderer) {
            m_renderer = renderer;
        }
        GameEntity() { //copy contructor 
        }
        ~GameEntity() { 
        for(int i = 0; i < m_Boxcolliders.size(); i++) {
            if(m_Boxcolliders[i] != nullptr) {
            delete m_Boxcolliders[i];
        }
        }
        
        if(m_sprite != nullptr) {
            delete m_sprite;
        }
        }

        void AddTexturedRectangleComponent(std::string filepath) {
            m_sprite = new TexturedRectangle(m_renderer,filepath.c_str());
        }
        void AddTexturedRectangleComponent(std::string filepath, int RedColourKey, int GreenColourKey, int BlueColourKey) {
            m_sprite = new TexturedRectangle(m_renderer,filepath.c_str(), RedColourKey, GreenColourKey, BlueColourKey);
        }

        void AddBoxCollider2Dcomponent() {
            m_Boxcolliders.push_back(new BoxCollider2D());
        }

        TexturedRectangle& GetTexturedRectangle() {
            return *m_sprite;
        }

        BoxCollider2D& GetBoxCollider2D(size_t index) {
            return *m_Boxcolliders[index];
        }

        void Render() {
            if(m_sprite != nullptr) {
                m_sprite->DrawRect(m_renderer);
            }
        }

        void Update() { //may be used later

        }

    private:
        TexturedRectangle* m_sprite = nullptr;
        std::vector<BoxCollider2D*> m_Boxcolliders;

        SDL_Renderer* m_renderer = nullptr;
};

#endif