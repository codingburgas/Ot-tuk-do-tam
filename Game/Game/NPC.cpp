#include"NPC.hpp"
NPC::NPC()
{
    enemyPosX = 1000, enemyPosY = 1000;
    enemyDistance = 100;
    NPCPositions = { {1000, 1000},{2000, 1000}, {1500, 1000} };
    counterDotsBubble = { 0, 0, 0, 0, 0, 0 };
    counterNPCAnim = { 0, 0, 0, 0, 0, 0 };
}
void NPC::LoadSprites()
{
    chadFr = LoadTexture("../src/sprites/NPC idles/frChad.png");
    scientist = LoadTexture("../src/sprites/NPC idles/bgScientist.png");
    addict = LoadTexture("../src/sprites/NPC idles/bgAddict.png");
    tourguideGreen = LoadTexture("../src/sprites/NPC idles/ekskurzovodGreen.png");
    tourguideYellow = LoadTexture("../src/sprites/NPC idles/ekskurzovodYellow.png");
    policeman = LoadTexture("../src/sprites/NPC idles/policeman.png");
    rival = LoadTexture("../src/sprites/NPC idles/bgRival.png");

    NPCSprites = {
        chadFr,
        scientist,
        addict,
        tourguideGreen,
        tourguideYellow,
        policeman,
        rival,
    };
    
    for (size_t i = 0; i < NPCSprites.size(); i++)
    {
        NPCSprites.at(i).width = 225;
        NPCSprites.at(i).height = 143;
    }

    //dots
    dotsBubble = LoadTexture("../src/sprites/menus and boards/dotsBubble.png");

    //for dots
    limitFrameDots = (float)dotsBubble.width / 4;
    viewDots = { limitFrameDots, 0, (float)dotsBubble.width / 4, (float)dotsBubble.height };
    //for npc anim
    limitFrameNPC = (float)NPCSprites.at(0).width / 2;
    viewNPC = { limitFrameNPC, 0, limitFrameNPC, (float)NPCSprites.at(0).height};
    
}
void NPC::DrawDotsAnimation(int xbg, int ybg, int contryIndex)
{
    if (counterDotsBubble[contryIndex] >= 20)
    {
        viewDots.x += limitFrameDots;
        counterDotsBubble[contryIndex] = 0;
    }
    if (abs(viewDots.x) > dotsBubble.width)
    {
        viewDots.x = limitFrameDots;
    }
    counterDotsBubble[contryIndex]++;
    for (int i = 0; i < NPCPositions.size(); i++)
    {
        DrawTextureRec(dotsBubble, viewDots, Vector2{ NPCPositions[i].x - 10 + xbg, NPCPositions[i].y - 10 + ybg }, WHITE);
    }

}
void NPC::DrawNPCAnimation(int xbg, int ybg, int contryIndex, Texture2D& texture)
{
    if (counterNPCAnim[contryIndex] >= 20)
    {
        viewNPC.x += limitFrameNPC;
        counterNPCAnim[contryIndex] = 0;
    }
    if (abs(viewNPC.x) > texture.width)
    {
        viewNPC.x = limitFrameNPC;
    }
    counterNPCAnim[contryIndex]++;
    for (int i = 0; i < NPCPositions.size(); i++)
    {
        DrawTextureRec(texture, viewNPC, Vector2{ NPCPositions[i].x + xbg, NPCPositions[i].y + ybg }, WHITE);
    }
}