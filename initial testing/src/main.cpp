#include<iostream>
#include<SDL2/SDL.h>

#include"TexturedRectangle.hpp"
#include"BoxCollider2D.hpp"
#include"SDLApp.hpp"
#include"GameEntity.hpp"

SDLApp* app;

GameEntity* sprite1;
GameEntity* sprite2;

void EventCallback() {
    SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                app->StopAppLoop();
            }
            if(event.type == SDL_KEYDOWN) {
                std:: cout << "Keydown\n";
            }
            if(event.type == SDL_MOUSEBUTTONDOWN) {
                if(event.button.button == SDL_BUTTON_LEFT) {
                    if(sprite1->GetBoxCollider2D(0).IsColliding(sprite2->GetBoxCollider2D(0))) {
                        std::cout << "Is colliding box 1\n";
                    } else {
                        std::cout << "Is not colliding box 1\n";
                    }
                    if(sprite1->GetBoxCollider2D(0).IsColliding(sprite2->GetBoxCollider2D(1))) {
                        std::cout << "Is colliding box 2\n";
                    } else {
                        std::cout << "Is not colliding box 2\n";
                    }
                }
            }
        }
}

void UpdateCallback() {
    // mouse tracking logic for sprite1
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //updating position of sprite 1 and setting collider component 
    sprite1->GetTexturedRectangle().SetDstRectPosition(mouseX,mouseY);
    sprite1->GetBoxCollider2D(0).SetColliderPosition(sprite1->GetTexturedRectangle().GetDstPosX(),sprite1->GetTexturedRectangle().GetDstPosY());
    sprite1->GetBoxCollider2D(0).SetColliderDimension(100,100);

    // moving logic for sprite 2
    static int x = 0; // ints ned to be static so they dont reset after each loop
    static int y = 0;
    static int xDir = 1; // +1 or -1
    static int yDir = 1;

    x += xDir;
    y += yDir;

    if(x <= 0 || x >= 800 - 100) { // ive adjusted for padding here.
        xDir = -xDir;
    }
    if(y <= 0 || y >= 600 - 80) {
        yDir = -yDir; 
    }
    //updating position of sprite 2  and setting collider component
    sprite2->GetTexturedRectangle().SetDstRectPosition(x,y);
    sprite2->GetBoxCollider2D(0).SetColliderPosition(sprite2->GetTexturedRectangle().GetDstPosX(),sprite2->GetTexturedRectangle().GetDstPosY());
    sprite2->GetBoxCollider2D(0).SetColliderDimension(100,50);
    sprite2->GetBoxCollider2D(1).SetColliderPosition(sprite2->GetTexturedRectangle().GetDstPosX(),sprite2->GetTexturedRectangle().GetDstPosY()+50);
    sprite2->GetBoxCollider2D(1).SetColliderDimension(100,50);
    //very basic and crude collision system for the sprites
    if(sprite1->GetBoxCollider2D(0).IsColliding(sprite2->GetBoxCollider2D(0))) {
        yDir = -yDir;
    }
    if(sprite1->GetBoxCollider2D(0).IsColliding(sprite2->GetBoxCollider2D(1))) {
        yDir = -yDir;
    }
    if(sprite1->GetBoxCollider2D(0).IsColliding(sprite2->GetBoxCollider2D(0)) &&
       sprite1->GetBoxCollider2D(0).IsColliding(sprite2->GetBoxCollider2D(1))) {
        xDir = -xDir;
        yDir = -yDir;
       }
}

void RenderCallback() {

    sprite1->GetTexturedRectangle().SetDstRectDimension(100,100);
    sprite1->GetTexturedRectangle().DrawRect(app->GetRenderer());
    sprite1->GetBoxCollider2D(0).DrawCollider(app->GetRenderer());

    sprite2->GetTexturedRectangle().SetDstRectDimension(100,100);
    sprite2->GetTexturedRectangle().DrawRect(app->GetRenderer());
    sprite2->GetBoxCollider2D(0).DrawCollider(app->GetRenderer());
    sprite2->GetBoxCollider2D(1).DrawCollider(app->GetRenderer());
}

int main(int argc, char* argv[]) {
    app = new SDLApp("Simple Audio Api", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
    
    sprite1 = new GameEntity(app->GetRenderer());
    sprite1->AddTexturedRectangleComponent("../Assets/donkeykong.bmp", 255, 0, 255);
    sprite1->AddBoxCollider2Dcomponent();

    sprite2 = new GameEntity(app->GetRenderer());
    sprite2->AddTexturedRectangleComponent("../Assets/donkeykong.bmp", 255, 0, 255);
    sprite2->AddBoxCollider2Dcomponent();
    sprite2->AddBoxCollider2Dcomponent();

    app->SetEventCallback(EventCallback);
    app->SetUpdateCallback(UpdateCallback);
    app->SetRenderCalback(RenderCallback);

    app->SetFrameCap(7);
    app->RunLoop();

    return 0;
}