#include"NPC.hpp"
NPC::NPC()
{
    enemyPosX = 1000, enemyPosY = 1000;
    enemyDistance = 100;
    counterDotsBubble = { 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 };
    counterNPCAnim = { 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 };
    viewNPC = {
        { 0, 0, 0, 0 },{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 },
        { 0, 0, 0, 0 },{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 },
        { 0, 0, 0, 0 },{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 },
        { 0, 0, 0, 0 },{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 },
        { 0, 0, 0, 0 },{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 } ,{ 0, 0, 0, 0 }
    
    };
}
void NPC::SetupSprites(int country)
{

    //dots

    //for dots
    limitFrameDots = (float)dotsBubble.width / 4;
    viewDots = { limitFrameDots, 0, (float)dotsBubble.width / 4, (float)dotsBubble.height };
}
void NPC::LoadSprites()
{
    
    dotsBubble = LoadTexture("../src/sprites/menus and boards/dotsBubble.png");

    
}
void NPC::DrawDotsAnimation(int xbg, int ybg, int countryIndex, int posX, int posY)
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
    
    DrawTextureRec(dotsBubble, viewDots, Vector2{(float)posX + xbg, (float)posY + ybg}, WHITE);
}

void NPC::DrawNPCAnimation(int xbgNPC, int ybgNPC, int countryIndexNPC, Texture2D texture, int posXNPC, int posYNPC)
{
    viewNPC[countryIndexNPC].width = texture.width / 2;
    viewNPC[countryIndexNPC].height = texture.height;
    if (counterNPCAnim[countryIndexNPC] >= 20)
    {
        viewNPC[countryIndexNPC].x += viewNPC[countryIndexNPC].width;
        //cout << viewNPC[countryIndexNPC].x;
        counterNPCAnim[countryIndexNPC] = 0;
    }
    if (abs(viewNPC[countryIndexNPC].x) > viewNPC[countryIndexNPC].width)
    {
        viewNPC[countryIndexNPC].x = 0;
    }
    counterNPCAnim[countryIndexNPC]++;

    DrawTextureRec(texture, viewNPC[countryIndexNPC], Vector2{(float)posXNPC + xbgNPC, (float)posYNPC + ybgNPC}, WHITE);
    DrawDotsAnimation(xbgNPC, ybgNPC, countryIndexNPC, posXNPC, posYNPC);
}