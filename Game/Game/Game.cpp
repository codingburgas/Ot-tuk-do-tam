#include "Precompile.hpp"
#include "Engine.hpp"
#include "Backstory.hpp"
#include "Game.hpp"

namespace Utils {
    float toRadian(float angel)
    {
        return M_PI / 180 * angel;
    }
}

namespace variables {
    //window width and height
    int width = 1920;
    int height = 1080;

    Texture2D backstoryImg;

    int miliseconds = 200;
    string backstoryText = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. \nLorem Ipsum has been the industry's standard dummy text ever since the 1500s,\nwhen an unknown printer took a\ngalley of type and scrambled it to make a type specimen book.";

    //hover effect variables

    struct country{
        Texture2D country;
        float x, y;
    };

    vector<country> countriesV (6);

    Texture2D bulgaria;
    Texture2D france;
    Texture2D germany;
    Texture2D italy;
    Texture2D spain;
    Texture2D romania;

    Texture2D map;
    Texture2D bull;
    Texture2D bar;
    Texture2D cheese;
    Texture2D help;

    vector<Texture2D> images (6);

    int money = 2000;

    Texture2D planeLeft, planeRight;
    Vector2 planePoint;
    struct plane{
        Texture2D planeT;
        float planeCurrentPosX, planeCurrentPosY;
    } plane;

    struct countryPosition {
        float x;
        float y;
    };

    vector <countryPosition> countryPositions (6);

    //map variables
    Rectangle lines_Decoration[3];

    Rectangle choiceFromOptions[4];

    Rectangle invisibleRec;

    Rectangle afterClickedOptions = { 1665,115,250,450 };

    Vector2 MousePoint;

    Vector2 circles[6];

    Texture2D barrier;  

    struct barrierPosition {
        Texture2D barrierT;
        float x, y;
    };

    vector<barrierPosition> barrierPositionVct (6);

    int countryFly;
    bool isFlying;

    Vector2 backCircle;

    bool countries[6] = { 0, 0, 0, 0, 0 };
    int coutnryNumber;

    bool changeCircles[6] = { 0, 0, 0, 0, 0 };
    bool banCountry[6] = {0, 0, 0, 0, 0};

    bool options = 0;
    bool closeOptions = 0;

    Sound mapMusic;
    float renderScale = 7.5;

    bool unloadBack = false;

    int counterPlane = 0;
    bool isFlipped = false;
    bool flyOneTime = true;
};

using namespace variables;

void setupVars();
void setWidthAndHeight(Texture2D& variable);

class Game
{
public:
    Game() {
        InitWindow(width, height, "Ot tuk do tam");
        InitAudioDevice();

        SetTargetFPS(60);

        ClearBackground(WHITE);

        srand(time(0));

        //backstoryImg = LoadTexture("../src/sprites/backgrounds/BackstoryFrame.png");

        setFullScreen(width, height);

        planeLeft = LoadTexture("../src/sprites/Map images/planeLeft.png");
        planeRight = LoadTexture("../src/sprites/Map images/planeRight.png");
        plane.planeT = planeLeft;
        
        plane.planeCurrentPosX = 1360;
        plane.planeCurrentPosY = 850;

        //hover effect variables
        bulgaria = LoadTexture("../src/sprites/countries/Bulgaria.png");
        france = LoadTexture("../src/sprites/countries/France.png");
        germany = LoadTexture("../src/sprites/countries/Germany.png");
        italy = LoadTexture("../src/sprites/countries/Italy.png");
        spain = LoadTexture("../src/sprites/countries/Spain.png");
        romania = LoadTexture("../src/sprites/countries/Romania.png");


        map = LoadTexture("../src/sprites/backgrounds/map.png");
        bull = LoadTexture("../src/sprites/backgrounds/bull.png");
        bar = LoadTexture("../src/sprites/backgrounds/bar.png");
        cheese = LoadTexture("../src/sprites/backgrounds/cheddar.png");
        help = LoadTexture("../src/sprites/backgrounds/help.png");

        setWidthAndHeight(map);
        setWidthAndHeight(bull);
        setWidthAndHeight(cheese);
        setWidthAndHeight(help);

        images[0] = { bull };
        images[1] = { cheese };
        images[2] = { help };
        images[3] = { bar };
        images[4] = { bull };
        images[5] = { bar };
    
        countriesV[0] = { spain, 7 * renderScale , 94 * renderScale };
        countriesV[1] = { france, 44 * renderScale , 76 * renderScale };
        countriesV[2] = { italy, 91 * renderScale , 96 * renderScale };
        countriesV[3] = { germany, 96 * renderScale , 65 * renderScale };
        countriesV[4] = { bulgaria, 169 * renderScale , 108 * renderScale };
        countriesV[5] = { romania, 160 * renderScale , 92 * renderScale };
       
        barrier = LoadTexture("../src/sprites/Map images/Barrier.png");
        barrier.width = 80;
        barrier.height = 80;      

        barrierPositionVct[0] = { barrier, 320, 800 };
        barrierPositionVct[1] = { barrier, 550, 650 };
        barrierPositionVct[2] = { barrier, 860, 800 };
        barrierPositionVct[3] = { barrier, 860, 500 };
        barrierPositionVct[4] = { barrier, 1360, 850 };
        barrierPositionVct[5] = { barrier, 180 * renderScale, 100 * renderScale };
    
        mapMusic = LoadSound("../Audios/mapMusic.ogg");
        SetSoundVolume(mapMusic, 0.6);

        countryPositions[0] = { circles[0].x - 15, circles[0].y - 15 };
        countryPositions[1] = { circles[1].x - 15, circles[1].y - 15 };
        countryPositions[2] = { circles[2].x - 15, circles[2].y - 15 };
        countryPositions[3] = { circles[3].x - 15, circles[3].y - 15 };
        countryPositions[4] = { circles[4].x - 15, circles[4].y - 15};
        countryPositions[5] = { circles[5].x - 15, circles[5].y - 15 };
    }

    void backstory()
    {
        setWidthAndHeight(backstoryImg);
        DrawTexture(backstoryImg, 0, 0, WHITE);
        backstoryTypewriteEffect(miliseconds, backstoryText);
    }

    void hoverEffects(Texture2D& country, float posx, float posy)
    {
        DrawTexture(country, posx, posy, WHITE);
    }

    void moveAirplane(const countryPosition& countryPosition)
    {
        Vector2 difference = { countryPosition.x - plane.planeCurrentPosX,  countryPosition.y - plane.planeCurrentPosY };

        float rotation = atan2(difference.y, difference.x) * 180 / M_PI;

        plane.planeCurrentPosX += cos(Utils::toRadian(rotation)) * 4.0f;
        plane.planeCurrentPosY += sin(Utils::toRadian(rotation)) * 4.0f;

        if (difference.x < 0)
        {
            plane.planeT = planeLeft;
        }
        else {
            plane.planeT = planeRight;
        }
    }

    void loop()
    {
        PlaySound(mapMusic);       

        while (!WindowShouldClose())
        {
            BeginDrawing();

            MousePoint = GetMousePosition();

            //backstory()

            DrawTexture(map, 0, 0, WHITE);

            for (int i = 0; i < 6; i++)
            {
                if (!changeCircles[i])
                {
                    DrawCircleGradient(circles[i].x, circles[i].y, 30, GREEN, SKYBLUE);
                }
            }

            for (int i = 0; i < 6; i++)
            {
                if ((CheckCollisionPointCircle(MousePoint, circles[i], 30)) || changeCircles[i])
                {
                    hoverEffects(countriesV[i].country, countriesV[i].x, countriesV[i].y);
                }
            }
            
            if (plane.planeCurrentPosX <= countryPositions.at(countryFly).x - 20)
            {
                if (counterPlane != 0)
                {                
                    if (CheckCollisionPointCircle(planePoint, circles[coutnryNumber], 30))
                    {
                        isFlipped = true;
                    }

                    counterPlane = 0;
                }
            }
            else if (plane.planeCurrentPosX >= countryPositions.at(countryFly).x + 20) {
                if (isFlipped)
                {                  
                    if (CheckCollisionPointCircle(planePoint, circles[coutnryNumber], 30))
                    {
                        isFlipped = false;
                    }               
                }
            }

            planePoint.x = plane.planeCurrentPosX;
            planePoint.y = plane.planeCurrentPosY;

            if (CheckCollisionPointCircle(planePoint, circles[coutnryNumber], 30))
            {
                flyOneTime = true;
                countries[coutnryNumber] = 1;
            }                     

            if (!flyOneTime)
            {
                DrawTexture(plane.planeT, plane.planeCurrentPosX, plane.planeCurrentPosY, WHITE);
            }
                                   
            DrawRectangleRec(invisibleRec, BLANK);

            DrawRectangleGradientH(invisibleRec.x, invisibleRec.y, invisibleRec.width, invisibleRec.height, GOLD, Fade(MAROON, 0.9444444));

            for (int i = 0; i < 3; i++)
            {
                DrawRectangleRec(lines_Decoration[i], Fade(WHITE, 0.85));
            }
         
            for (int i = 0; i < 6; i++)
            {
                if (!banCountry[i])
                {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, circles[i], 30))
                    {                  
                        if (flyOneTime)
                        {
                           countryFly = i;
                           flyOneTime = false;
                        }
                        
                        isFlying = true;
                        counterPlane++;
                        coutnryNumber = i;
                    }
                }      
            }      

            if (isFlying)
            {
                moveAirplane(countryPositions.at(countryFly));    
            }       

            for (int i = 0; i < 6; i++)
            {
                if (countries[i] && !banCountry[i])
                {            
                    StopSound(mapMusic);

                    DrawTexture(images[i], 0, 0, WHITE);

                    unloadBack = false;
                    changeCircles[i] = true;
                }

                if (changeCircles[i])
                {                 
                    
                    if (!unloadBack)
                    {
                        DrawCircleGradient(backCircle.x, backCircle.y, 30, GREEN, SKYBLUE);
                    }
                                   
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, backCircle, 30))
                    {
                        countries[i] = 0;    
                        unloadBack = true;
                        banCountry[i] = true;
                    }                   

                    if (unloadBack)
                    {
                        DrawTexture(barrierPositionVct[i].barrierT, barrierPositionVct[i].x, barrierPositionVct[i].y, WHITE);
                    }                                           
                }

            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(MousePoint, invisibleRec))
            {
                options = 1;
            }

            if (options)
            {
                DrawRectangleRec(afterClickedOptions, LIGHTGRAY);

                for (int i = 0; i < 4; i++)
                {
                    DrawRectangleLinesEx(choiceFromOptions[i], 5, WHITE);
                }

                for (int i = 0; i < 4; i++)
                {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(MousePoint, choiceFromOptions[i]))
                    {
                        switch (i) {
                        case 0:
                            //settings happen here
                            break;

                        case 1:
                            //settings happen here
                            break;

                        case 2:
                            //settings happen here
                            break;

                        case 3:
                            //settings happen here
                            break;
                        }
                    }
                }

                DrawText("Settings", 1680, 150, 50, BLACK);

                DrawText("Help", 1680, 250, 50, BLACK);

                DrawText("Music", 1680, 350, 50, BLACK);

                DrawText("Quit", 1680, 450, 50, BLACK);
                
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    closeOptions = 1;
                }

                if (closeOptions)
                {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(MousePoint, invisibleRec))
                    {
                        options = 0;
                        closeOptions = 0;
                    }
                }
            }

            EndDrawing();
        }
    };
    ~Game() {

        //IMPORTNAT UNLOADING TEXTURES
        UnloadTexture(backstoryImg);

        CloseWindow();
    }

};

void setWidthAndHeight(Texture2D& variable)
{
    variable.width = width;
    variable.height = height;
}

void setupVars()
{
    //spain
    circles[0].x = 320;
    circles[0].y = 800;

    //france
    circles[1].x = 550;
    circles[1].y = 650;

    //italy
    circles[2].x = 860;
    circles[2].y = 800;

    //germany
    circles[3].x = 860;
    circles[3].y = 580;

    //bulgaria
    circles[4].x = 1360;
    circles[4].y = 850;

    //romania
    circles[5].x = 180 * renderScale;
    circles[5].y = 100 * renderScale;

    backCircle.x = 1800;
    backCircle.y = 800;

    invisibleRec.x = 1800;
    invisibleRec.y = 20;

    invisibleRec.width = 90;
    invisibleRec.height = 90;

    for (int i = 0; i < 3; i++)
    {
        lines_Decoration[i].x = 1807.5;
        lines_Decoration[i].y = 38.5 + (i * 20);
        lines_Decoration[i].width = 75;
        lines_Decoration[i].height = 15;
    }

    for (int i = 0; i < 4; i++)
    {
        choiceFromOptions[i].x = 1667.5;
        choiceFromOptions[i].y = 142.5 + (i * 100);
        choiceFromOptions[i].width = 245;
        choiceFromOptions[i].height = 60;
    }
}

void gameStartup()
{
    setupVars();

    Game game;

    setIcon();

    game.loop();
}