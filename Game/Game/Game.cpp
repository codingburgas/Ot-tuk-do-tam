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
    Texture2D map;

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
    vector<country> countriesHoveredV(6);

    Texture2D bulgaria, bulgariaHovered;
    Texture2D france, franceHovered;
    Texture2D germany, germanyHovered;
    Texture2D italy, italyHovered;
    Texture2D spain, spainHovered;
    Texture2D romania, romaniaHovered;

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

    int vehicleSpeed;

    //train
    Texture2D trainLeft, trainRight;

    //transport menu
    Texture2D transportMenu;
    Texture2D okCleanButtonTransportMenu;
    Texture2D okHoverButtonTransportMenu;

    Texture2D isClickedCheck;
    
    //vehicle audios
    Sound touranSound, planeSound, trainSound;


    Sound vehicleSound;

    vector <countryPosition> countryPositions (6);

    int vehicleChoice = 0;

    //map variables

    Rectangle choiceFromOptions[3];

    Texture2D target;
    Texture2D targetHover;

    Texture2D optionImage;
    Texture2D optionImageHovered;
    Texture2D optionImageClicked;
    int optionCounter;

    Rectangle afterClickedOptions = { 1665,115,250,330 };

    Vector2 mousePoint;

    Vector2 circles[6] = {320, 800};

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

    bool outsideCheck;
    int isCheckedOutside = 0;

    bool playSound = 0;
    int fps = 60;

    //Exit confirmaiton table
    Color darkerWindow = { 0,0,0,120 };
    bool isQuitting = false;
    Texture2D confirmationT;

    //money mechanic 
    int allMoney = 2000, allMoneyCopy, moneySpent;
    string printMoney, allMoneyCopyPrint, moneySpentPrint;
    Sound moneySound;

    //points mechanic
    int points;
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

        map = LoadTexture("../src/sprites/backgrounds/map.png");
        setWidthAndHeight(map);

        //backstoryImg = LoadTexture("../src/sprites/backgrounds/BackstoryFrame.png");
       
        //player
        player.LoadSprites(fps);
        
        setFullScreen(width, height);
               
        plane.planeCurrentPosX = 1360;
        plane.planeCurrentPosY = 850;

        //hover effect variables
        bulgaria = LoadTexture("../src/sprites/countries/Bulgaria.png");
        france = LoadTexture("../src/sprites/countries/France.png");
        germany = LoadTexture("../src/sprites/countries/Germany.png");
        italy = LoadTexture("../src/sprites/countries/Italy.png");
        spain = LoadTexture("../src/sprites/countries/Spain.png");
        spain = LoadTexture("../src/sprites/countries/Spain.png");
        romania = LoadTexture("../src/sprites/countries/Romania.png");

        bulgariaHovered = LoadTexture("../src/sprites/countries/BulgariaDark.png");
        franceHovered = LoadTexture("../src/sprites/countries/FranceDark.png");
        germanyHovered = LoadTexture("../src/sprites/countries/GermanyDark.png");
        italyHovered = LoadTexture("../src/sprites/countries/ItalyDark.png");
        spainHovered = LoadTexture("../src/sprites/countries/SpainDark.png");
        romaniaHovered = LoadTexture("../src/sprites/countries/RomaniaDark.png");

        target = LoadTexture("../src/sprites/Map images/targetClean.png");
        targetHover = LoadTexture("../src/sprites/Map images/targetHover.png");
    
        countriesV[0] = { spain, 52.5 , 705 };
        countriesV[1] = { france, 330 , 570 };
        countriesV[2] = { italy, 682.5, 720 };
        countriesV[3] = { germany, 720 , 487.5 };
        countriesV[4] = { bulgaria, 1267.5 , 810 };
        countriesV[5] = { romania, 1200 , 690 };

        countriesHoveredV[0] = { spainHovered, 52.5 , 705 };
        countriesHoveredV[1] = { franceHovered, 330 , 570 };
        countriesHoveredV[2] = { italyHovered, 682.5, 720 };
        countriesHoveredV[3] = { germanyHovered, 720 , 487.5 };
        countriesHoveredV[4] = { bulgariaHovered, 1267.5 , 810 };
        countriesHoveredV[5] = { romaniaHovered, 1200 , 690 };     
    
        //mapMusic = LoadSound("../Audios/mapMusic.ogg");
        //SetSoundVolume(mapMusic, 0.6);

        optionImage = LoadTexture("../src/sprites/Map images/settingsButtonClean.png");
        optionImageHovered = LoadTexture("../src/sprites/Map images/settingsButtonHover.png");
        optionImageClicked = LoadTexture("../src/sprites/Map images/settingsButtonPressed.png");

        for (int i = 0; i < 6; i++)
        {
            countryPositions[i] = { circles[i].x - 15, circles[i].y - 15 };
        }

        vehicleSpeed = 4.0f;
        planeLeft = LoadTexture("../src/sprites/Map images/planeLeft.png");
        planeRight = LoadTexture("../src/sprites/Map images/planeRight.png");

        trainLeft = LoadTexture("../src/sprites/Map images/trainLeft.png");
        trainRight = LoadTexture("../src/sprites/Map images/trainRight.png");

        transportMenu = LoadTexture("../src/sprites/Map images/transportMenu.png");
        isClickedCheck = LoadTexture("../src/sprites/Map images/check.png");
        okCleanButtonTransportMenu = LoadTexture("../src/sprites/Map images/okCLean.png");
        okHoverButtonTransportMenu = LoadTexture("../src/sprites/Map images/okHover.png");


        //touranLeft = LoadTexture("../src/sprites/Map images/touranLeft.png");
        //touranRight = LoadTexture("../src/sprites/Map images/touranRight.png");

        touranSound = LoadSound("../Audios/Touran.mp3");
        trainSound = LoadSound("../Audios/Train.mp3");
        planeSound = LoadSound("../Audios/Plane.mp3");
        moneySound = LoadSound("../Audios/Money.mp3");

        SetSoundVolume(vehicleSound, 0.5);

        SetExitKey(-1);

        allMoneyCopy = allMoney;
    }

    void backstory()
    {
        setWidthAndHeight(backstoryImg);
        DrawTexture(backstoryImg, 0, 0, WHITE);
       // backstoryTypewriteEffect(backstoryText);
    }

    void hoverEffects(Texture2D& country, float posx, float posy ,float posxTarget, float posyTarget)
    {
        DrawTexture(country, posx, posy, WHITE);
        DrawTexture(targetHover, posxTarget, posyTarget, WHITE);
    }

    void moveAirplane(const countryPosition& countryPosition)
    {
        Vector2 difference = { countryPosition.x - plane.planeCurrentPosX,  countryPosition.y - plane.planeCurrentPosY };

        float rotation = atan2(difference.y, difference.x) * 180 / M_PI;

        plane.planeCurrentPosX += cos(Utils::toRadian(rotation)) * vehicleSpeed;
        plane.planeCurrentPosY += sin(Utils::toRadian(rotation)) * vehicleSpeed;

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
            DrawRectangle(0, 0, 1920, 1080, darkerWindow);
            DrawTexture(okCleanButtonTransportMenu, 1725, 420, WHITE);
            DrawTexture(transportMenu, 1450, 270, WHITE);

        }
        
        if (mousePoint.x >= 1795 && mousePoint.x <= 1820)
        {
            if (mousePoint.y >= 300 && mousePoint.y <= 325 && isClicked())
            {                           
                vehicleChoice = 0;

                transportCheck = 1;            
            }
            else if (mousePoint.y >= 350 && mousePoint.y <= 375 && isClicked())
            {
                transportCheck = 2;
                    
                vehicleChoice = 1;
            }
        }

        if (transportCheck == 1)
        {
            DrawTexture(isClickedCheck, 1795, 315, WHITE);
        }
        else if (transportCheck == 2)
        {
            DrawTexture(isClickedCheck, 1795, 365, WHITE);
        }

        if ((mousePoint.x >= 1725 && mousePoint.x <= 1825) && transportCheck != 0 && (mousePoint.y >= 400 && mousePoint.y <= 450))
        {

            DrawTexture(okHoverButtonTransportMenu, 1725, 420, WHITE);
            if (isClicked())
            {
                planeToMove = true;

                PlaySound(moneySound);

                if (transportCheck == 1)
                {
                    allMoney -= 1000;
                }
                else if (transportCheck == 2)
                {
                    allMoney -= 500;
                }

                transportCheck = 0;
            }
        }

        if ((mousePoint.x <= 1450 || mousePoint.x >= 1865 || mousePoint.y <= 250 || mousePoint.y >= 475) && isClicked())
        {
            isCheckedOutside++;
            cout << isCheckedOutside;
        }
    }

    void mapEurope()
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            isQuitting = true;
        }

        mousePoint = GetMousePosition();
        //cout << mousePoint.x << " " << mousePoint.y << endl;

        printMoney = to_string(allMoneyCopy) + "$";
        
        if (allMoney != allMoneyCopy)
        {
            if (allMoney < allMoneyCopy)
            {
                allMoneyCopy -= 5;
            }
            else {
                allMoneyCopy += 5;
            }
        }

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
                DrawTexture(target, circles[i].x-20, circles[i].y-40, WHITE);
            }
        }

        for (int i = 0; i < 6; i++)
        {
            if ((CheckCollisionPointCircle(mousePoint, circles[i], 30)) || changeCircles[i])
            {
                hoverEffects(countriesV[i].country, countriesV[i].x, countriesV[i].y, circles[i].x -20, circles[i].y - 40);
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

        DrawTexture(optionImage, 1840, 30, WHITE);

        for (int i = 0; i < 6; i++)
        {
            if (!banCountry[i])
            {
                if (isClicked() && CheckCollisionPointCircle(mousePoint, circles[i], 30))
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
                else {
                    DrawTexture(countriesHoveredV[i].country, countriesHoveredV[i].x, countriesHoveredV[i].y, WHITE);
                }

                if (isClicked() && CheckCollisionPointCircle(mousePoint, backCircle, 30))
                {
                    countries[i] = 0;
                    unloadBack = true;
                    banCountry[i] = true;
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

        DrawText(printMoney.c_str(), 500, 50, 50, BROWN);
    }

    void optionsMenu()
    {
		if ((mousePoint.x >= 1845 && mousePoint.x <= 1900) && (mousePoint.y >= 20 && mousePoint.y <= 70))
		{
            DrawTexture(optionImageHovered, 1840, 30, WHITE);

            if(isClicked())
            {
                DrawTexture(optionImageClicked, 1840, 30, WHITE);
                options = 1;
                optionCounter++;
            }	
		}

		if (options)
		{
			DrawRectangleRec(afterClickedOptions, LIGHTGRAY);

			for (int i = 0; i < 3; i++)
			{
				if (isClicked() && CheckCollisionPointRec(mousePoint, choiceFromOptions[i]))
				{
					switch (i) {
					case 0:
						//settings happen here
						break;

					case 1:
                        helpIsClicked = true;
						break;

					case 2:
                        isQuitting = true;
						break;
					}
				}
			}

            DrawText("Settings", 1680, 150, 50, BLACK);

            DrawText("Help", 1680, 250, 50, BLACK);

            DrawText("Quit", 1680, 350, 50, BLACK);

            if (helpIsClicked)
            {
                //DrawTexture(help, 0, 0, WHITE);
            }
   
		}

        if ((mousePoint.x >= 1845 && mousePoint.x <= 1900) && (mousePoint.y >= 20 && mousePoint.y <= 70) && isClicked() && optionCounter == 2)
        {
            options = 0;
            optionCounter = 0;
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

            isUserQuitting(isQuitting, mousePoint, confirmationT, darkerWindow);

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

    target.width = 100;
    target.height = 100;

    targetHover.width = 100;
    targetHover.height = 100;

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
        choiceFromOptions[i].x = 1667.5f;
        choiceFromOptions[i].y = 142.5f + (i * 100);
        choiceFromOptions[i].width = 245;
        choiceFromOptions[i].height = 60;
    }

    confirmationT = LoadTexture("../src/sprites/Menus and boards/Confirmation.png");
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