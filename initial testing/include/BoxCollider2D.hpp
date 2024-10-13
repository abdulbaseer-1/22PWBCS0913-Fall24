#ifndef BOXCOLLIDER2D_HPP
#define BOXCOLLIDER2D_HPP

#include<iostream>
#include<SDL2/SDL.h>

#include"Collider2D.hpp"

class BoxCollider2D:Collider2D {
    public:
    BoxCollider2D();
    ~BoxCollider2D();
 
    bool IsColliding(BoxCollider2D& collider);

    SDL_Rect& GetColliderBoundingBox();

    void SetColliderPosition(int x, int y);

    void SetColliderDimension(int w, int h);

    void DrawCollider(SDL_Renderer* renderer);

    private:
    SDL_Rect* m_BoundingBox;
    SDL_Rect* m_NoCollisionState;
};

#endif