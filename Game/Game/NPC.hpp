#pragma once
#include "Precompile.hpp"

class NPC {
protected: 
    float limitFrameNPC;
    Rectangle viewNPC;
    vector<Vector2> NPCPositions;

    Texture2D dotsBubble;
    float limitFrameDots;
    Rectangle viewDots;
    //to this
    vector<int> counterDotsBubble;
    vector<Texture2D> NPCSprites;
    vector<int> counterNPCAnim;

public:
    Texture2D chadFr, scientist, addict, tourguideGreen, tourguideYellow, policeman, rival;
    vector<Texture2D> idles;

    int enemyPosX, enemyPosY;
    int enemyDistance;
    NPC();
    void LoadSprites();
    void DrawDotsAnimation(int xbg, int ybg, int contryIndex);
    void DrawNPCAnimation(int xbg, int ybg, int contryIndex, Texture2D& texture);
};