#include "Game.hpp"

namespace Utils {
    float toRadian(float angle)
    {
        return PI / 180 * angle;
    }
}
void setWidthAndHeight(Texture2D& variable);

Game::Game() {
    SetTargetFPS(fps);
    srand(time(0));

    //fonts
    //headerFont = LoadFont("../src/Fonts/headerFont");
   // textFont = LoadFont("../src/Fonts/textFont");

    map = LoadTexture("../src/sprites/backgrounds/map.png");

    setWidthAndHeight(map);

    //spain
    circles[0].x = 320;
    circles[0].y = 775;

    //france
    circles[1].x = 550;
    circles[1].y = 635;

    //italy
    circles[2].x = 860;
    circles[2].y = 775;

    //germany
    circles[3].x = 860;
    circles[3].y = 565;

    //bulgaria
    circles[4].x = 1360;
    circles[4].y = 835;

    //romania
    circles[5].x = 1350;
    circles[5].y = 735;

    backCircle.x = 1800;
    backCircle.y = 800;

    for (int i = 0; i < 3; i++)
    {
        choiceFromOptions[i].x = 1667.5f;
        choiceFromOptions[i].y = 130.5f + (i * 60);
        choiceFromOptions[i].width = 200;
        choiceFromOptions[i].height = 50;
    }

    confirmationT = LoadTexture("../src/sprites/Menus and boards/Confirmation.png");

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
    
    countriesV = { 
        {spain, 52.5, 705},
        { france, 330 , 570 },
        { italy, 682.5, 720 },
        {  germany, 720 , 487.5 },
        { bulgaria, 1267.5 , 810 },
        { romania, 1200 , 690 } 
    };

    countriesHoveredV = { 
        { spainHovered, 52.5, 705 },
        { franceHovered, 330 , 570 },
        { italyHovered, 682.5, 720 },
        { germanyHovered, 720 , 487.5 },
        { bulgariaHovered, 1267.5 , 810 },
        { romaniaHovered, 1200 , 690 } 
    };
    
    

    optionImage = LoadTexture("../src/sprites/Map images/settingsButtonClean.png");
    optionImageHovered = LoadTexture("../src/sprites/Map images/settingsButtonHover.png");
    optionImageClicked = LoadTexture("../src/sprites/Map images/settingsButtonPressed.png");
        
    menuOptions = LoadTexture("../src/sprites/Map images/settingsMenu.png");
    audioIsOn = LoadTexture("../src/sprites/Map images/audioOn.png");

    for (int i = 0; i < 6; i++)
    {
        countryPositions.push_back({circles[i].x - 15, circles[i].y - 15});
    }

    vehicleSpeed = 169;
    planeLeft = LoadTexture("../src/sprites/Map images/planeLeft.png");
    planeRight = LoadTexture("../src/sprites/Map images/planeRight.png");

    trainLeft = LoadTexture("../src/sprites/Map images/trainLeft.png");
    trainRight = LoadTexture("../src/sprites/Map images/trainRight.png");

    transportMenu = LoadTexture("../src/sprites/Map images/transportMenu.png");
    isClickedCheck = LoadTexture("../src/sprites/Map images/check.png");
    okCleanButtonTransportMenu = LoadTexture("../src/sprites/Map images/okCLean.png");
    okHoverButtonTransportMenu = LoadTexture("../src/sprites/Map images/okHover.png");

    touranSound = LoadSound("../Audios/Touran.mp3");
    trainSound = LoadSound("../Audios/Train.mp3");
    planeSound = LoadSound("../Audios/Plane.mp3");
    moneySound = LoadSound("../Audios/Money.mp3");

    moneyBackground = LoadTexture("../src/sprites/Menus and boards/moneyDisplay.png");

    SetSoundVolume(vehicleSound, 0.5);

    SetExitKey(-1);

    allMoneyCopy = allMoney;

    //dialogue mechanic
    chadFr = LoadTexture("../src/sprites/inner country elements/france/frChad1.png");
    chadFrTwo = LoadTexture("../src/sprites/inner country elements/france/frChad2.png");

    mainCharacterDialogue = LoadTexture("../src/sprites/dialogues/KurabirovDialogue.png");
    chadDialogue = LoadTexture("../src/sprites/dialogues/NestashevDialogue.png");

    dotsBubbleOne = LoadTexture("../src/sprites/menus and boards/dotsBubble1.png");
    dotsBubbleTwo = LoadTexture("../src/sprites/menus and boards/dotsBubble2.png");
    dotsBubblThree = LoadTexture("../src/sprites/menus and boards/dotsBubble3.png");
    dotsBubbleFour = LoadTexture("../src/sprites/menus and boards/dotsBubble4.png");
    dotsBubble = { dotsBubbleOne, dotsBubbleTwo, dotsBubblThree, dotsBubbleFour };
    
}

void Game::backstory()
{
    setWidthAndHeight(backstoryImg);
    DrawTexture(backstoryImg, 0, 0, WHITE);
    // backstoryTypewriteEffect(backstoryText);
}

void Game::hoverEffects(Texture2D& country, float posx, float posy ,float posxTarget, float posyTarget)
{
    
    DrawTexture(country, posx, posy, WHITE);
    DrawTexture(targetHover, posxTarget, posyTarget, WHITE);
    
}

void Game::moveAirplane(const countryPosition& countryPosition)
{
    Vector2 difference = { countryPosition.x - plane.planeCurrentPosX,  countryPosition.y - plane.planeCurrentPosY };

    //cout << difference.x << " " << difference.y << endl;

    float rotation = atan2(difference.y, difference.x) * 180 / PI;

    plane.planeCurrentPosX += cos(Utils::toRadian(rotation)) * vehicleSpeed * GetFrameTime();
    plane.planeCurrentPosY += sin(Utils::toRadian(rotation)) * vehicleSpeed * GetFrameTime();

    if (difference.x < 0)
    {
        if (vehicleChoice == 0)
        {
            vehicleSpeed = 169;
            plane.planeT = planeLeft;

        }
        else if (vehicleChoice == 1)
        {
            vehicleSpeed = 169;
            plane.planeT = trainLeft;
        }         
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

void Game::transportMenuF()
{     
    if(enableClick)
    { 
        if (!planeToMove)
        {
            DrawRectangle(0, 0, 1920, 1080, darkerWindow);
            DrawTexture(okCleanButtonTransportMenu, 1728, 420, WHITE);
            DrawTexture(transportMenu, 1450, 270, WHITE);
        }
        
        if (isCheckedOutside == 1)
        {
            isTransportMenuOn = false;
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
            DrawTexture(okHoverButtonTransportMenu, 1728, 420, WHITE);

            if (isClicked())
            {
                planeToMove = true;            

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
            //isCheckedOutside++;
        }
    }
}

void Game::mapEurope()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        isQuitting = true;
        enableClick = false;
        isTransportMenuOn = true;
    }

    mousePoint = GetMousePosition();
    //cout << mousePoint.x << " " << mousePoint.y << endl;

    printMoney = to_string(allMoneyCopy);
        
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
        if (!changeCircles[i] && !isTransportMenuOn && enableClick)
        {
            DrawTexture(target, circles[i].x-20, circles[i].y-40, WHITE);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if ((CheckCollisionPointCircle(mousePoint, circles[i], 30) || changeCircles[i]) && !isTransportMenuOn && enableClick)
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

    if (CheckCollisionPointCircle(planePoint, circles[coutnryNumber], 30) && enableClick)
    {
        
        StopSoundMulti();
        flyOneTime = true;
        countries[coutnryNumber] = 1;
    }

    //egg
    //egg??
    DrawTexture(optionImage, 1840, 30, WHITE);

    counterDotsBubble++;

    for (int i = 0; i < 6; i++)
    {
        if (!banCountry[i])
        {
            if (isClicked() && CheckCollisionPointCircle(mousePoint, circles[i], 30))
            {
                if (audioIsClicked && enableClick)
                {
                    PlaySound(moneySound);
                }                

                isTransportMenuOn = true;

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

        if (playSound && audioIsClicked)
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
                
            enableClick = false;
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
                Game::dialogues(chadFr, 800, 500, 850, 480, mainCharacterDialogue, chadDialogue, firstDialogue, firstDialogueCounter, 3);
            }
            else {
                DrawTexture(countriesHoveredV[i].country, countriesHoveredV[i].x, countriesHoveredV[i].y, WHITE);
                isTransportMenuOn = false;
            }

            if (isClicked() && CheckCollisionPointCircle(mousePoint, backCircle, 30) )
            {
                enableClick = true;
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

    DrawTexture(moneyBackground, 7, 30, WHITE);
    DrawText(printMoney.c_str(), 85, 50, 50, DARKGREEN);
}

void Game::dialogues(Texture2D& character, int characterPosX, int characterPosY, int dotsBubbleX, int dotsBubbleY, Texture2D& firstDialogue, Texture2D& secondDialogue, string characterDialogues[], int& dialogueCounter, int dialogueLength)
{
    DrawTexture(character, characterPosX, characterPosY, WHITE);

    //cout << counterDotsBubble << " ";
    if (counterDotsBubble >= 180)
    {
        changeDotsBubble++;
        //DrawTexture(dotsBubble.at(changeDotsBubble), dotsBubbleX, dotsBubbleY, WHITE);
        counterDotsBubble = 0;

        if (changeDotsBubble == 4)
        {
            changeDotsBubble = 0;
        }
    }

    if (IsKeyPressed(KEY_E))
    {
        isDialogueStarted = true;
    }

    if (isDialogueStarted)
    {
        DrawTexture(firstDialogue, 0, 0, WHITE);
        DrawText(characterDialogues[dialogueCounter].c_str(), 20, 900, 24, dialogueColor);
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        counterPressed++;
        isDialogueStarted = false;

        if (dialogueCounter <= dialogueLength)
        {
            if (counterPressed % 2 == 0 && counterPressed > 0)
            {
                DrawTexture(secondDialogue, 0, 0, WHITE);

            }
            else {
                DrawTexture(firstDialogue, 0, 0, WHITE);
            }

            DrawText(characterDialogues[dialogueCounter].c_str(), 20, 900, 24, dialogueColor);
            dialogueCounter++;
        }
    }
}

void Game::optionsMenu()
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
        DrawTexture(menuOptions, 1635, 100, WHITE);

		for (int i = 0; i < 3; i++)
		{
			if (isClicked() && CheckCollisionPointRec(mousePoint, choiceFromOptions[i]))
			{
				switch (i) {
				case 0:
                    helpIsClicked = true;
					break;

				case 1:
                    audioIsClicked = true;
                    audioIsClickedCounter++;
					break;

				case 2:
                    isQuitting = true;
                    enableClick = false;
                    isTransportMenuOn = true;
					break;
				}
			}
		}

        if (helpIsClicked)
        {
            //idk what will happen here Deivid :)
            //mislish li che az znam sh ima nesh sig
            //ok yani shte misli 
            //stava
        }
         
        if (audioIsClicked)
        {
            DrawTexture(audioIsOn, 1857.5, 190.5, WHITE);

            if (IsMouseButtonUp && isClicked() && CheckCollisionPointRec(mousePoint, choiceFromOptions[1]) && audioIsClickedCounter == 2)
            {
                audioIsClicked = false;
                audioIsClickedCounter = 0;                 
            }
        }
	}

    if ((mousePoint.x >= 1845 && mousePoint.x <= 1900) && (mousePoint.y >= 20 && mousePoint.y <= 70) && isClicked() && optionCounter == 2)
    {
        options = 0;
        optionCounter = 0;
    }
}

void Game::update()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapEurope();

        optionsMenu();

        isUserQuitting(isQuitting,enableClick, mousePoint, confirmationT, darkerWindow, isTransportMenuOn);

        EndDrawing();
    }
}
  

Game::~Game() {

    //IMPORTNAT UNLOADING TEXTURES
    UnloadTexture(backstoryImg);
    player.UnLoadTextures();
    CloseAudioDevice();
    CloseWindow();
}

void setWidthAndHeight(Texture2D& variable)
{
    variable.width = 1920;
    variable.height = 1080;
}

void gameStartup()
{
    InitWindow(1920, 1080, "Ot tuk do tam");
    InitAudioDevice();

    Game game;

    setIcon();

    game.update();
}