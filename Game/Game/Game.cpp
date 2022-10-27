#include "Precompile.hpp"
#include "Engine.hpp"
#include "Backstory.hpp"
#include "Game.hpp"
#include "Player.hpp"
//bool isF;
namespace Utils {
    float toRadian(float angle)
    {
        return M_PI / 180 * angle;
    }
}

namespace variables {
    //window width and height
    int width = 1920;
    int height = 1080;

    //player obj
    Player player;

    Texture2D backstoryImg;

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

    //vehicles
    //plane
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

    //train
    Texture2D trainLeft, trainRight;

    //transport menu
    Texture2D transportMenu;
    Texture2D isClickedCheck;
    
    //vehicle audios
    Sound touranSound, planeSound, trainSound;


    Sound vehicleSound;

    vector <countryPosition> countryPositions (6);

    int vehicleChoice = 0;

    //map variables
    Rectangle lines_Decoration[3];

    Rectangle choiceFromOptions[3];

    Rectangle invisibleRec = {1800,20,90,90};

    Rectangle afterClickedOptions = { 1665,115,250,330 };

    Vector2 MousePoint;

    Vector2 circles[6] = {320, 800};

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

    bool helpIsClicked = false;

    bool planeToMove = false ;
    int transportCheck = 0;

    bool playSound = 0;
    int fps = 60;
};

using namespace variables;

void setupVars();
void setWidthAndHeight(Texture2D& variable);

class Game
{
public:
    Game() {
        

        SetTargetFPS(fps);
        srand(time(0));

        //backstoryImg = LoadTexture("../src/sprites/backgrounds/BackstoryFrame.png");
       
        //player
        //player.LoadSprites(fps);
        
        setFullScreen(width, height);
               
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

        barrierPositionVct[0] = { barrier, 200, 815 };
        barrierPositionVct[1] = { barrier, 530, 650 };
        barrierPositionVct[2] = { barrier, 860, 800 };
        barrierPositionVct[3] = { barrier, 830, 550 };
        barrierPositionVct[4] = { barrier, 1330, 810 };
        barrierPositionVct[5] = { barrier, 1310, 710 };
    
        //mapMusic = LoadSound("../Audios/mapMusic.ogg");
        //SetSoundVolume(mapMusic, 0.6);

        countryPositions[0] = { circles[0].x - 15, circles[0].y - 15 };
        countryPositions[1] = { circles[1].x - 15, circles[1].y - 15 };
        countryPositions[2] = { circles[2].x - 15, circles[2].y - 15 };
        countryPositions[3] = { circles[3].x - 15, circles[3].y - 15 };
        countryPositions[4] = { circles[4].x - 15, circles[4].y - 15};
        countryPositions[5] = { circles[5].x - 15, circles[5].y - 15 };

        planeLeft = LoadTexture("../src/sprites/Map images/planeLeft.png");
        planeRight = LoadTexture("../src/sprites/Map images/planeRight.png");

        trainLeft = LoadTexture("../src/sprites/Map images/trainLeft.png");
        trainRight = LoadTexture("../src/sprites/Map images/trainRight.png");

        transportMenu = LoadTexture("../src/sprites/Map images/transportMenu.png");
        isClickedCheck = LoadTexture("../src/sprites/Map images/check.png");

        //touranLeft = LoadTexture("../src/sprites/Map images/touranLeft.png");
        //touranRight = LoadTexture("../src/sprites/Map images/touranRight.png");

        touranSound = LoadSound("../Audios/Touran.mp3");
        trainSound = LoadSound("../Audios/Train.mp3");
        planeSound = LoadSound("../Audios/Plane.mp3");

        SetSoundVolume(vehicleSound, 0.5);
    }
    void backstory()
    {
        setWidthAndHeight(backstoryImg);
        DrawTexture(backstoryImg, 0, 0, WHITE);
       // backstoryTypewriteEffect(backstoryText);
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
            if (vehicleChoice == 0)
                plane.planeT = planeLeft;
            else if(vehicleChoice == 1)
                plane.planeT = trainLeft;
            else {
                //plane.planeT = touranLeft;
            }
        }
        else {
            if (vehicleChoice == 0)
                plane.planeT = planeRight;
            else if(vehicleChoice == 1)
                plane.planeT = trainRight;
            else {
                //plane.planeT = touranRight;
            }
              
        }
    }

    void transportMenuF()
    {
        if (!planeToMove)
        {
            DrawTexture(transportMenu, 1450, 270, WHITE);
        }
        
        if (MousePoint.x >= 1795 && MousePoint.x <= 1820)
        {
            if (MousePoint.y >= 300 && MousePoint.y <= 325 && isClicked())
            {                           
                vehicleChoice = 0;

                transportCheck = 1;                  
            }
            else if (MousePoint.y >= 350 && MousePoint.y <= 375 && isClicked())
            {
                
                transportCheck = 2;
                    
                vehicleChoice = 1;
            }
        }

        if (transportCheck == 1)
        {
            DrawTexture(isClickedCheck, 1795, 315, WHITE);
            transportCheck = 0;
        }
        else if (transportCheck == 2)
        {
            DrawTexture(isClickedCheck, 1795, 365, WHITE);
            transportCheck = 0;
        }
            
        if ((MousePoint.x >= 1450 && MousePoint.x <= 1860) && (MousePoint.y >= 270 && MousePoint.y <= 435) && isClicked())
        {
            if (isClicked())
            {
                planeToMove = true;
            }          
        }
    }

    void mapEurope()
    {
        MousePoint = GetMousePosition();
        cout << MousePoint.x << " " << MousePoint.y << endl;

        if (vehicleChoice == 0)
        {
            plane.planeT = planeLeft;
            vehicleSound = planeSound;
        }
        else if (vehicleChoice == 1)
        {
            plane.planeT = trainLeft;
            vehicleSound = trainSound;
        }
        else {
            //plane.planeT = touranLeft;
            vehicleSound = touranSound;
        }
        
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

        if (plane.planeCurrentPosX < countryPositions.at(countryFly).x)
        {
            if (counterPlane != 0)
            {
                if (CheckCollisionPointCircle(planePoint, circles[coutnryNumber], 30))
                {
                    isFlipped = true;
                    planeToMove = false;
                }
               
                counterPlane = 0;
            }
        }
        else if (plane.planeCurrentPosX > countryPositions.at(countryFly).x) {
            if (isFlipped)
            {
                if (CheckCollisionPointCircle(planePoint, circles[coutnryNumber], 30))
                {
                    isFlipped = false;
                    planeToMove = false;
                }
                
            }
            
        }

        planePoint.x = plane.planeCurrentPosX;
        planePoint.y = plane.planeCurrentPosY;

        if (CheckCollisionPointCircle(planePoint, circles[coutnryNumber], 30))
        {
            StopSoundMulti();
            flyOneTime = true;
            countries[coutnryNumber] = 1;
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
                if (isClicked() && CheckCollisionPointCircle(MousePoint, circles[i], 30))
                {
                    if (flyOneTime)
                    {
                        countryFly = i;
                        flyOneTime = false;
                    }

                    isFlying = true;
                    playSound = true;
                    counterPlane++;
                    coutnryNumber = i;
                }
            }
        }

        if (isFlying && planeToMove)
        {
            //isF = true;

            if (playSound)
            {
                PlaySound(vehicleSound);
            }
            
            moveAirplane(countryPositions.at(countryFly));

            playSound = 0;
        }

        for (int i = 0; i < 6; i++)
        {
            if (countries[i] && !banCountry[i])
            {
                StopSound(vehicleSound);
                DrawRectangle(0,0,GetScreenWidth(), GetScreenHeight(), GRAY);
                //DrawTexture(images[i], 0, 0, WHITE);
                
                player.CheckDir();
                player.Movement();
                unloadBack = false;
                changeCircles[i] = true;
            }

            if (changeCircles[i])
            {

                if (!unloadBack)
                {
                    DrawCircleGradient(backCircle.x, backCircle.y, 30, GREEN, SKYBLUE);
                }

                if (isClicked() && CheckCollisionPointCircle(MousePoint, backCircle, 30))
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

        if (!flyOneTime)
        {
            transportMenuF();

            if (planeToMove)
            {
                DrawTexture(plane.planeT, plane.planeCurrentPosX, plane.planeCurrentPosY, WHITE);
            }
            
        }
    }

    void optionsMenu()
    {
		if (isClicked() && CheckCollisionPointRec(MousePoint, invisibleRec))
		{
			options = 1;
		}

		if (options)
		{
			DrawRectangleRec(afterClickedOptions, LIGHTGRAY);

			for (int i = 0; i < 3; i++)
			{
				DrawRectangleLinesEx(choiceFromOptions[i], 5, WHITE);
			}

			for (int i = 0; i < 3; i++)
			{
				if (isClicked() && CheckCollisionPointRec(MousePoint, choiceFromOptions[i]))
				{
					switch (i) {
					case 0:
						//settings happen here
						break;

					case 1:
                        helpIsClicked = true;
						break;

					case 2:
						exit(0);
						break;
					}
				}
			}

            DrawText("Settings", 1680, 150, 50, BLACK);

            DrawText("Help", 1680, 250, 50, BLACK);

            DrawText("Quit", 1680, 350, 50, BLACK);

            if (helpIsClicked)
            {
                DrawTexture(help, 0, 0, WHITE);

                DrawRectangleRec(invisibleRec, Fade(ORANGE, 0.5));
            }

			

			if (isClicked())
			{
				closeOptions = 1;
			}

			if (closeOptions)
			{
				if (isClicked() && CheckCollisionPointRec(MousePoint, invisibleRec))
				{
					options = 0;
					closeOptions = 0;
				}
			}
		}
    }

    void loop()
    {
        //PlaySound(mapMusic);       
        //if (isF) PlaySound(vehicleSound);
        //else if (flyOneTime) StopSound(vehicleSound);
        while (!WindowShouldClose())
        { 
            BeginDrawing();
            ClearBackground(WHITE);
            mapEurope();

            optionsMenu();

            EndDrawing();
        }
    };

    ~Game() {

        //IMPORTNAT UNLOADING TEXTURES
        UnloadTexture(backstoryImg);
        player.UnLoadTextures();
        CloseAudioDevice();
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

    for (int i = 0; i < 3; i++)
    {
        lines_Decoration[i].x = 1807.5f;
        lines_Decoration[i].y = 38.5f + (i * 20);
        lines_Decoration[i].width = 75;
        lines_Decoration[i].height = 15;
    }

    for (int i = 0; i < 3; i++)
    {
        choiceFromOptions[i].x = 1667.5f;
        choiceFromOptions[i].y = 142.5f + (i * 100);
        choiceFromOptions[i].width = 245;
        choiceFromOptions[i].height = 60;
    }
}

void gameStartup()
{
    InitWindow(width, height, "Ot tuk do tam");
    InitAudioDevice();
    setupVars();

    Game game;

    setIcon();

    game.loop();
}