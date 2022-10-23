#include "Precompile.hpp"
#include "Engine.hpp"
#include "Backstory.hpp"
#include "Game.hpp"

struct QA {
    string* questions;
    string* answers;
}questionnaire;

namespace variables {
    //window width and height
    int width = 1920;
    int height = 1080;

    Texture2D backstoryImg;

    int miliseconds = 200;
    string backstoryText = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. \nLorem Ipsum has been the industry's standard dummy text ever since the 1500s,\nwhen an unknown printer took a\ngalley of type and scrambled it to make a type specimen book.";

    //hover effect variables
    Texture2D bulgaria;
    Texture2D france;
    Texture2D germany;
    Texture2D italy;
    Texture2D spain;

    Texture2D map;
    Texture2D bull;
    Texture2D bar;
    Texture2D cheese;
    Texture2D help;

    //map variables
    Rectangle lines_Decoration[3];

    Rectangle choiceFromOptions[4];

    Rectangle invisibleRec;

    Rectangle afterClickedOptions = { 1665,115,250,450 };

    Vector2 MousePoint;

    Vector2 circles[5];
    Texture2D barrier;

    Vector2 backCircle;

    bool countries[5] = { 0, 0, 0, 0, 0 };
    bool changeCircles[5] = { 0, 0, 0, 0, 0 };
    bool banCountry[5] = {0, 0, 0, 0, 0};

    bool options = 0;

    bool closeOptions = 0;

    Sound mapMusic;
    float renderScale = 7.5;

    bool unloadBack = false;
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

        //hover effect variables
        bulgaria = LoadTexture("../src/sprites/countries/Bulgaria.png");
        france = LoadTexture("../src/sprites/countries/France.png");
        germany = LoadTexture("../src/sprites/countries/Germany.png");
        italy = LoadTexture("../src/sprites/countries/Italy.png");
        spain = LoadTexture("../src/sprites/countries/Spain.png");

        map = LoadTexture("../src/sprites/backgrounds/map.png");
        bull = LoadTexture("../src/sprites/backgrounds/bull.png");
        bar = LoadTexture("../src/sprites/backgrounds/bar.png");
        cheese = LoadTexture("../src/sprites/backgrounds/cheddar.png");
        help = LoadTexture("../src/sprites/backgrounds/help.png");

        setWidthAndHeight(map);
        setWidthAndHeight(bull);
        setWidthAndHeight(cheese);
        setWidthAndHeight(help);

       
        barrier = LoadTexture("../src/sprites/Barrier.png");
        barrier.width = 60;
        barrier.height = 60;

        mapMusic = LoadSound("../Audios/Main.mp3");
        SetSoundVolume(mapMusic, 0.6);
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

    void loop()
    {
        PlaySound(mapMusic);

        while (!WindowShouldClose())
        {
            BeginDrawing();

            MousePoint = GetMousePosition();

            //backstory()

            DrawTexture(map, 0, 0, WHITE);

            for (int i = 0; i < 5; i++)
            {
                if (!changeCircles[i])
                {
                    DrawCircleGradient(circles[i].x, circles[i].y, 30, GREEN, SKYBLUE);
                }
            }

            DrawRectangleRec(invisibleRec, BLANK);

            DrawRectangleGradientH(invisibleRec.x, invisibleRec.y, invisibleRec.width, invisibleRec.height, GOLD, Fade(MAROON, 0.9444444));

            for (int i = 0; i < 3; i++)
            {
                DrawRectangleRec(lines_Decoration[i], Fade(WHITE, 0.85));
            }

            for (int i = 0; i < 5; i++)
            {
                if ((CheckCollisionPointCircle(MousePoint, circles[i], 30)) || changeCircles[i])
                {
                    switch (i) {
                    case 0:
                        hoverEffects(spain, 7 * renderScale, 94 * renderScale);
                        break;

                    case 1:
                        hoverEffects(france, 44 * renderScale, 76 * renderScale);
                        break;

                    case 2:
                        hoverEffects(italy, 91 * renderScale, 96 * renderScale);
                        break;

                    case 3:
                        hoverEffects(germany, 96 * renderScale, 65 * renderScale);
                        break;

                    case 4:
                        hoverEffects(bulgaria, 169 * renderScale, 108 * renderScale);
                        break;

                    default:
                        break;
                    }
                }
            }

            for (int i = 0; i < 5; i++)
            {
                if (!banCountry[i])
                {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, circles[i], 30))
                    {
                        countries[i] = 1;
                    }

                }      
            }

            for (int i = 0; i < 5; i++)
            {
                if (countries[i] && !banCountry[i])
                {            
                    StopSound(mapMusic);

                    switch (i)
                    {
                    case 0:
                        DrawTexture(bull, 0, 0, WHITE);
                        break;

                    case 1:
                        DrawTexture(cheese, 0, 0, WHITE);
                        break;

                    case 2:
                        DrawTexture(help, 0, 0, WHITE);
                        break;

                    case 3:
                        DrawTexture(bar, 0, 0, WHITE);
                        break;

                    case 4:
                        DrawTexture(bull, 0, 0, WHITE);
                        break;

                    default:
                        break;
                    }

                    unloadBack = false;
                    changeCircles[i] = true;
                }

                if (changeCircles[i])
                {                 
                    
                    DrawCircleGradient(backCircle.x, backCircle.y, 30, GREEN, SKYBLUE);
                    
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, backCircle, 30))
                    {
                        countries[i] = 0;    
                        unloadBack = true;
                        banCountry[i] = true;
                    }                   

                    if (!countries[i] && unloadBack)
                    {
                        switch (i)
                        {
                        case 0:
                            DrawTexture(barrier, 320, 800, WHITE);
                            break;

                        case 1:
                            DrawTexture(barrier, 550, 650, WHITE);
                            break;

                        case 2:
                            DrawTexture(barrier, 860, 800, WHITE);
                            break;

                        case 3:
                            DrawTexture(barrier, 860, 580, WHITE);
                            break;

                        case 4:
                            DrawTexture(barrier, 1360, 850, WHITE);
                            break;

                        default:
                            break;
                        }                     
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
        delete[] questionnaire.questions;
        delete[] questionnaire.answers;

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