#include"ResourceManager.hpp"

ResourceManager::ResourceManager(){}
ResourceManager::~ResourceManager(){}

ResourceManager& ResourceManager::GetInstance(){
    static ResourceManager* instance = new ResourceManager();
    return *instance;
}

SDL_Surface* ResourceManager::GetSurface(std::string filepath) {
    auto search = m_surfaces.find(filepath.c_str());
    if(search != m_surfaces.end()) {
        return m_surfaces[filepath.c_str()];
    } else {
        SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
        if(!surface) {
            std::cerr << "Surface not loaded in Resource manager\n";
        }
        m_surfaces.insert(std::make_pair(filepath,surface)); //make a pair of obj and key

        return m_surfaces[filepath.c_str()];
    }
}