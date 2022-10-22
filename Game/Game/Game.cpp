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

    int randomizationForA[10];
    int randomizationForQ[10][4];

    int shuffleQA = 0, randomA = 0, randomQ = 0;
    int miliseconds = 200;
    string backstoryText = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. \nLorem Ipsum has been the industry's standard dummy text ever since the 1500s,\nwhen an unknown printer took a\ngalley of type and scrambled it to make a type specimen book.";

    Texture2D bulgaria;
    Texture2D france;
   

    //map variables
    Rectangle lines_Decoration[3];

    Rectangle invisibleRec;

    Rectangle afterClickedOptions;

    Vector2 MousePoint;

    Vector2 circles[10];

    bool countries[5] = {0, 0, 0, 0, 0};

    bool options = 0;

    Music mapMusic;
};

using namespace variables;

void setupVars();
void setWidthAndHeight(Texture2D& variable);

class Game
{
public:
    Game(){
        InitWindow(width, height, "Ot tuk do tam");
        SetTargetFPS(60);
        ClearBackground(WHITE);
        backstoryImg = LoadTexture("../src/sprites/backgrounds/BackstoryFrame.png");
        setFullScreen(width, height);

        //hover effect variables
        bulgaria = LoadTexture("../src/sprites/countries/Bulgaria.png");
        france = LoadTexture("../src/sprites/countries/France.png");

        mapMusic = LoadMusicStream("../Audios/Main.mp3");
    }
    
    void backstory()
    {
        setWidthAndHeight(backstoryImg);
        DrawTexture(backstoryImg, 0, 0, WHITE);
        backstoryTypewriteEffect(miliseconds, backstoryText);
    }

    void hoverEffects(Texture2D& country, int posx, int posy)
    {
        DrawTexture(country, posx, posy, WHITE);
    }

    void loop()
    {
        Texture2D map = LoadTexture("../src/sprites/backgrounds/map.png");
        Texture2D bull = LoadTexture("../src/sprites/backgrounds/bull.png");
        Texture2D bar = LoadTexture("../src/sprites/backgrounds/bar.png");
        Texture2D cheese = LoadTexture("../src/sprites/backgrounds/cheddar.png");
        Texture2D help = LoadTexture("../src/sprites/backgrounds/help.png");

        setWidthAndHeight(map);
        setWidthAndHeight(bull);
        setWidthAndHeight(cheese);
        setWidthAndHeight(help);

        while (!WindowShouldClose())
        {
            BeginDrawing();

            MousePoint = GetMousePosition();

            //backstory();
            //SetMusicPitch(mapMusic, 1);
            //UnloadMusicStream(mapMusic);

            DrawTexture(map, 0, 0, WHITE);
            
            DrawCircleGradient(circles[0].x, circles[0].y, 30, GREEN, SKYBLUE);

            
            DrawCircleGradient(circles[1].x, circles[1].y, 30, PURPLE, BLUE);

            
            DrawCircleGradient(circles[2].x, circles[2].y, 30, LIME, DARKBLUE);

           
            DrawCircleGradient(circles[3].x, circles[3].y, 30, RED, PINK);

			DrawCircleGradient(circles[4].x, circles[4].y, 30, BLACK, DARKPURPLE);


            DrawRectangleRec(invisibleRec, BLANK);

            DrawRectangleGradientH(invisibleRec.x, invisibleRec.y, invisibleRec.width, invisibleRec.height, GOLD, Fade(MAROON, 0.9444444));

            for (int i = 0; i < 3; i++)
            {

                DrawRectangleRec(lines_Decoration[i], Fade(WHITE, 0.85));
            }

            if (CheckCollisionPointCircle(MousePoint, circles[0], 30))
            {
                DrawText("Spain", 125, 725, 60, RED);
            }
            if (CheckCollisionPointCircle(MousePoint, circles[1], 30))
            {
                hoverEffects(france, 329, 570);
            }
            if (CheckCollisionPointCircle(MousePoint, circles[2], 30))
            {
                DrawText("Iceland", 200, 150, 60, BLUE);
            }
            if (CheckCollisionPointCircle(MousePoint, circles[3], 30))
            {
                DrawText("Germany", 650, 474, 60, YELLOW);
            }
			if (CheckCollisionPointCircle(MousePoint, circles[4], 30))
			{
				hoverEffects(bulgaria, 1550, 800);
			}

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, circles[0], 30))
            {
                countries[0] = 1;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, circles[1], 30))
            {
                countries[1] = 1;
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, circles[2], 30))
            {
                countries[2] = 1;
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(MousePoint, circles[3], 30))
            {
                countries[3] = 1;
            }

            if (countries[0])
            {
                DrawTexture(bull, 0, 0, WHITE);
            }
            if (countries[1])
            {
                DrawTexture(cheese, 0, 0, WHITE);
            }
            if (countries[3])
            {
                DrawTexture(bar, 0, 0, WHITE);
            }
            if (countries[2])
            {
                DrawTexture(help, 0, 0, WHITE);
            }
			if(countries[4])
			{
				DrawTexture(bull, 0, 0, WHITE);
			}

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(MousePoint, invisibleRec))
            {
                options = 1;
            }

            if (options)
            {
                DrawTexture(help, 0, 0, WHITE);
            }
            EndDrawing();
        }
    };
    ~Game(){
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
	circles[0].x = 320;
	circles[0].y = 800;

	circles[1].x = 550;
	circles[1].y = 650;

	circles[2].x = 380;
	circles[2].y = 80;

	circles[3].x = 860;
	circles[3].y = 580;

	circles[4].x = 1160;
	circles[4].y = 850;

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
}

void gameStartup()
{
    srand(time(0));

    setupVars();

    Game game;

    setIcon();

    game.loop();
}