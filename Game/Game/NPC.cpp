#include"NPC.hpp"
NPC::NPC()
{
    enemyPosX = 1000, enemyPosY = 1000;
    enemyDistance = 100;
    counterDotsBubble = { 0, 0, 0, 0, 0, 0 };
    counterNPCAnim = { 0, 0, 0, 0, 0, 0 };
    NPCPositions = { 
        { {1000, 1000},{1500, 1000}, {100, 1000} },
        { {1000, 1000},{1500, 1000}, {100, 1000} },
        { {1000, 1000},{1500, 1000}, {100, 1000} },
        { {1000, 1000},{1500, 1000}, {100, 1000} },
        { {1000, 1000},{1500, 1000}, {100, 1000} },
    };
    viewNPC.resize(6);
}
void NPC::SetupSprites(int country)
{

    //for npc anim
    limitFrameNPC = (float)NPCSprites.at(country).width / 2;
    viewNPC[country] = { limitFrameNPC, 0, limitFrameNPC, (float)NPCSprites.at(country).height };

    //dots

    //for dots
    limitFrameDots = (float)dotsBubble.width / 4;
    viewDots = { limitFrameDots, 0, (float)dotsBubble.width / 4, (float)dotsBubble.height };
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

    dotsBubble = LoadTexture("../src/sprites/menus and boards/dotsBubble.png");

    NPCSprites = {
        chadFr,
        scientist,
        addict,
        tourguideGreen,
        tourguideYellow,
        policeman,
        rival,
    };
    
}
void NPC::DrawDotsAnimation(int xbg, int ybg, int countryIndex)
{
    if (counterDotsBubble[countryIndex] >= 20)
    {
        viewDots.x += limitFrameDots;
        counterDotsBubble[countryIndex] = 0;
    }
    if (abs(viewDots.x) > dotsBubble.width)
    {
        viewDots.x = limitFrameDots;
    }
    counterDotsBubble[countryIndex]++;
    for (int i = 0; i < NPCPositions[countryIndex].size(); i++)
    {
        DrawTextureRec(dotsBubble, viewDots, Vector2{ NPCPositions[countryIndex][i].x - 10 + xbg, NPCPositions[countryIndex][i].y - 10 + ybg }, WHITE);
    }

}
void NPC::DrawNPCAnimation(int xbg, int ybg, int countryIndex)
{
   // cout << abs(viewNPC[countryIndex].x) << " " << NPCSprites[countryIndex].width << endl;
    if (counterNPCAnim[countryIndex] >= 20)
    {
        viewNPC[countryIndex].x += viewNPC[countryIndex].width;
        counterNPCAnim[countryIndex] = 0;
    }
    if (abs(viewNPC[countryIndex].x) > NPCSprites[countryIndex].width)
    {
        viewNPC[countryIndex].x = viewNPC[countryIndex].width;
    }
    counterNPCAnim[countryIndex]++;
    for (int i = 0; i < NPCPositions[countryIndex].size(); i++)
    {
        DrawTextureRec(NPCSprites[countryIndex], viewNPC[countryIndex], Vector2{NPCPositions[countryIndex][i].x + xbg, NPCPositions[countryIndex][i].y + ybg}, WHITE);
    }
}