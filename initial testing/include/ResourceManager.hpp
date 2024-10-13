//Resource Manager
//This is a singleton class
#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include<iostream>
#include<unordered_map>
#include"SDL2/SDL.h"

class ResourceManager {
    private:
        ResourceManager();
        ~ResourceManager();

        ResourceManager(const ResourceManager&) = delete;
        ResourceManager operator=(const ResourceManager&) = delete;
        
        std::unordered_map<std::string, SDL_Surface*> m_surfaces; // <key,obj>
        // ResourceManager m_obj;
        
    public:
        static ResourceManager& GetInstance();

        SDL_Surface* GetSurface(std::string filepath);

    
};

#endif