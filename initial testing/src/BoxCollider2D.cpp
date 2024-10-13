#include"BoxCollider2D.hpp"

BoxCollider2D::BoxCollider2D() {
            m_BoundingBox = new SDL_Rect;
            m_BoundingBox->x = 0;
            m_BoundingBox->y = 0;
            m_BoundingBox->w = 0;
            m_BoundingBox->h = 0;

            m_NoCollisionState = new SDL_Rect;
    }
    BoxCollider2D::~BoxCollider2D(){
        delete m_BoundingBox;
        delete m_NoCollisionState;
    }
 
    bool BoxCollider2D::IsColliding(BoxCollider2D& collider) {
        if(this->m_BoundingBox == nullptr) {
            return SDL_FALSE;
        }

        SDL_Rect* ThisRect = &collider.GetColliderBoundingBox();
        if(ThisRect == nullptr) {
            return SDL_FALSE;
        }
        
        if(SDL_HasIntersection(this->m_BoundingBox, ThisRect)) {
            return true;
        } 
        else {
            m_NoCollisionState->x = m_BoundingBox->x;
            m_NoCollisionState->y = m_BoundingBox->y;
            m_NoCollisionState->w = m_BoundingBox->h;
            m_NoCollisionState->h = m_BoundingBox->w;
            
            return false;
        }
    }

    SDL_Rect& BoxCollider2D::GetColliderBoundingBox() {
        return *m_BoundingBox;
    }

    void BoxCollider2D::SetColliderPosition(int x, int y) {
        m_BoundingBox->x = x;
        m_BoundingBox->y = y;
    }

    void BoxCollider2D::SetColliderDimension(int w, int h) {
        m_BoundingBox->w = w;
        m_BoundingBox->h = h;
    }

    void BoxCollider2D::DrawCollider(SDL_Renderer* renderer) {
        SDL_RenderDrawRect(renderer, this->m_BoundingBox);
    }