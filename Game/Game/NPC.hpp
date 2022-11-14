#pragma once
#include "Precompile.hpp"

class NPC {
protected:
    Texture2D chadFr;
    float limitFrameNPC;
    Rectangle viewNPC;
    vector<Vector2> NPCPositions;

    Texture2D dotsBubble;
    float limitFrameDots;
    Rectangle viewDots;
    //to this
    vector<int> counterDotsBubble;
    vector<int> counterNPCAnim;

public:

    int enemyPosX, enemyPosY;
    int enemyDistance;
    NPC();
    void LoadSprites();
    void DrawDotsAnimation(int xbg, int ybg, int contryIndex);
    void DrawNPCAnimation(int xbg, int ybg, int contryIndex);
};