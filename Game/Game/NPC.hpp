#pragma once
#include "Precompile.hpp"

class NPC {
protected: 
    vector<Rectangle>viewNPC;
    vector<vector<Vector2>>NPCPositions;
    vector<int> counterDotsBubble;
    vector<Texture2D> NPCSprites;
    vector<int> counterNPCAnim;
    float limitFrameNPC;

    Texture2D dotsBubble;
    float limitFrameDots;
    Rectangle viewDots;
    //to this

public:
    Texture2D chadFr, scientist, addict, tourguideGreen, tourguideYellow, policeman, rival;
    vector<Texture2D> idles;

    int enemyPosX, enemyPosY;
    int enemyDistance;
    NPC();
    void LoadSprites();
    void SetupSprites(int country);
    void DrawDotsAnimation(int xbg, int ybg, int contryIndex);
    void DrawNPCAnimation(int xbg, int ybg, int contryIndex);
};