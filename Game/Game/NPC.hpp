#pragma once
#include "Precompile.hpp"

class NPC {
protected:
    Texture2D chadFr;
    float limitFrameNPC;
    Rectangle viewNPC;
    int counterNPCAnim;
    vector<Vector2> NPCPositions;

    Texture2D dotsBubble;
    float limitFrameDots;
    Rectangle viewDots;
    //to this
    int counterDotsBubble;

public:

    int enemyPosX, enemyPosY;
    int enemyDistance;
    NPC();
    void LoadSprites();
    void DrawDotsAnimation(int xbg, int ybg);
    void DrawNPCAnimation(int xbg, int ybg);
};