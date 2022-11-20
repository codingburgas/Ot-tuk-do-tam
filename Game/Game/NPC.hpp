#pragma once
#include "Precompile.hpp"

class NPC {
protected: 
    vector<Rectangle> viewNPC;
    vector<int> counterDotsBubble;
    vector<Texture2D>NPCSprites;
    vector<int> counterNPCAnim;
    Texture2D dotsBubble;
    float limitFrameDots;
    Rectangle viewDots;
    //to this

public:
    
    vector<Texture2D> idles;

    int enemyPosX, enemyPosY;
    int enemyDistance;
    NPC();
    void LoadSprites();
    void SetupSprites(int country);
    void DrawDotsAnimation(int xbg, int ybg, int countryIndex, int posX, int posY);
    void DrawNPCAnimation(int xbg, int ybg,int countryIndex, Texture2D texture, int posX, int posY);
};