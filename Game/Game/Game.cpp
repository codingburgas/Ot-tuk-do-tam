#include "Game.hpp"

namespace Utils {
    float toRadian(float angle)
    {
        return PI / 180 * angle;
    }
}

Game::Game() {
    SetTargetFPS(fps);
    srand(time(0));


    EnterOnce = 0;
    //fonts
    headerFont = LoadFont("../Fonts/headerFont.ttf");
    textFont = LoadFont("../Fonts/textFont.ttf");

    map = LoadTexture("../src/sprites/backgrounds/map.png");

    setWidthAndHeight(map);
    
    //spain
    circles[0].x = 320;
    circles[0].y = 760;

    //france
    circles[1].x = 550;
    circles[1].y = 630;

    //italy
    circles[2].x = 860;
    circles[2].y = 760;

    //germany
    circles[3].x = 860;
    circles[3].y = 550;

    //bulgaria
    circles[4].x = -1362;
    circles[4].y = -825;

    //romania
    circles[5].x = 1350;
    circles[5].y = 720;

    backCircle.x = 1800;
    backCircle.y = 785;

    Fader.x = 0;
    Fader.y = 0;
    Fader.width = 1920;
    Fader.height = 1080;


    rectangleQuit.x = 850;
    rectangleQuit.y = 780;
    rectangleQuit.width = 200;
    rectangleQuit.height = 85;

    backButton.x = 1800;
    backButton.y = 940;
    backButton.width = 125;
    backButton.height = 100;

    allPoints = 5000 + rand() % 1000;

    backButtonClean = LoadTexture("../src/sprites/menus and boards/mapIconClean.png");
    backButtonHover = LoadTexture("../src/sprites/menus and boards/mapIconHover.png");

    for (int i = 0; i < 3; i++)
    {
        choiceFromOptions[i].x = 1667.5f;
        choiceFromOptions[i].y = 130.5f + (i * 60);
        choiceFromOptions[i].width = 200;
        choiceFromOptions[i].height = 50;
    }

    confirmationT = LoadTexture("../src/sprites/Menus and boards/quitConfirmation.png");

    goldenTarget = LoadTexture("../src/sprites/Map images/goldenTarget.png");

    gameIsFinished = LoadTexture("../src/sprites/Map images/gameFinishedScreen.png");

    yesButton = LoadTexture("../src/sprites/Menus and boards/yesClean.png");
    yesButtonHover = LoadTexture("../src/sprites/Menus and boards/yesHover.png");
    noButton = LoadTexture("../src/sprites/Menus and boards/noClean.png");
    noButtonHover = LoadTexture("../src/sprites/Menus and boards/noHover.png");

    quitButtons = {
        yesButton,
        yesButtonHover,
        noButton,
        noButtonHover,
    };

    //backstoryImg = LoadTexture("../src/sprites/backgrounds/BackstoryFrame.png");

    //player
    player.LoadSprites(fps);
    race.LoadSprites();
    assassin.LoadSprites();
    npc.LoadSprites();
    bulls.LoadSprites();
    for (size_t i = 0; i < 6; i++)
    {
        npc.SetupSprites(i);
    }

    mainMenuDialogue = true;

    plane.planeCurrentPosX = 1360;
    plane.planeCurrentPosY = 850;

    enableClick = true;
    money = 2000;
    allMoney = 2000;
    moneyColor = { 51, 171, 69, 255 };

    //hover effect variables
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


    chadFr = LoadTexture("../src/sprites/NPC idles/frChad.png");
    chadBg = LoadTexture("../src/sprites/NPC idles/bgChad.png");
    scientist = LoadTexture("../src/sprites/NPC idles/bgScientist.png");
    addict = LoadTexture("../src/sprites/NPC idles/bgAddict.png");
    tourguideGreen = LoadTexture("../src/sprites/NPC idles/ekskurzovodGreen.png");
    tourguideYellow = LoadTexture("../src/sprites/NPC idles/ekskurzovodYellow.png");
    policeman = LoadTexture("../src/sprites/NPC idles/policeman.png");
    rival = LoadTexture("../src/sprites/NPC idles/bgRival.png");

    target = LoadTexture("../src/sprites/Map images/targetClean.png");
    targetHover = LoadTexture("../src/sprites/Map images/targetHover.png");

    target.width -= 5;
    target.height -= 5;

    targetHover.width -= 5;
    targetHover.height -= 5;
    goldenTarget.width = target.width;
    goldenTarget.height = target.height;
    countriesV = {
        {spain, 52.5, 705},
        { france, 330 , 570 },
        { italy, 682.5, 720 },
        { germany, 720 , 487.5 },
        { bulgaria, -200 , -810 },
        { romania, 1200 , 690 }
    };

    countriesHoveredV = {
        { spainHovered, 52.5, 705 },
        { franceHovered, 330 , 570 },
        { italyHovered, 682.5, 720 },
        { germanyHovered, 720 , 487.5 },
        { bulgariaHovered, -1267.5 , -810 },
        { romaniaHovered, 1200 , 690 }
    };


    
    optionImage = LoadTexture("../src/sprites/Map images/settingsButtonClean.png");
    optionImageHovered = LoadTexture("../src/sprites/Map images/settingsButtonHover.png");
    optionImageClicked = LoadTexture("../src/sprites/Map images/settingsButtonPressed.png");

    menuOptions = LoadTexture("../src/sprites/Map images/settingsMenu.png");
    audioIsOn = LoadTexture("../src/sprites/Map images/audioOn.png");

    for (int i = 0; i < 6; i++)
    {
        countryPositions.push_back({ circles[i].x - 15, circles[i].y - 15 });
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

    trainSound = LoadSound("../Audios/Train.mp3");
    planeSound = LoadSound("../Audios/Plane.mp3");
    moneySound = LoadSound("../Audios/Money.mp3");

    mapMusic = LoadSound("../Audios/mapMusic.mp3");

    moneyBackground = LoadTexture("../src/sprites/Menus and boards/moneyDisplay.png");

    SetSoundVolume(vehicleSound, 0.5);

    SetExitKey(-1);

    allMoneyCopy = allMoney;

    //dialogue mechanic
    dialogueBox = LoadTexture("../src/sprites/dialogues/dialogueBox.png");
    finishedDialogueArrow = LoadTexture("../src/sprites/dialogues/dialogueArrow.png");

    //quest board
    questBoardT = LoadTexture("../src/sprites/menus and boards/questMenu.png");

    acceptButton = LoadTexture("../src/sprites/menus and boards/acceptClean.png");
    acceptButtonHover = LoadTexture("../src/sprites/menus and boards/acceptHover.png");
    cancelButton = LoadTexture("../src/sprites/menus and boards/cancelClean.png");
    cancelButtonHover = LoadTexture("../src/sprites/menus and boards/cancelHover.png");

	afterClickedOptions = { 1665,115,250,330 };

    flyOneTime = true;

    audioIsClicked = true;

	darkerWindow = { 0,0,0,120 };

	backstoryText = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. \nLorem Ipsum has been the industry's standard dummy text ever since the 1500s,\nwhen an unknown printer took a\ngalley of type and scrambled it to make a type specimen book.";

    //pickup mechanic
    inventory = LoadTexture("../src/sprites/Menus and boards/inventory.png");
    barrel = LoadTexture("../src/sprites/inner country elements/france/barrel.png");
    barrel.width = 125;
    barrel.height = 125;

    textColor = { 54, 54, 54, 255 };

    horse = LoadTexture("../src/sprites/inner country elements/france/horse.png");
    gripper = LoadTexture("../src/sprites/inner country elements/spain/grippers.png");

    key = LoadTexture("../src/sprites/inner country elements/romania/key.png");
    metalPieces = LoadTexture("../src/sprites/inner country elements/romania/metal pieces.png");
    stone = LoadTexture("../src/sprites/inner country elements/romania/stone.png");

    ssgs.sausage = LoadTexture("../src/sprites/inner country elements/germany/sausage.png");
    ssgs.sausage.width = 150;
    ssgs.sausage.height = 150;

    sausagesV = {
        { ssgs.sausage, 1500, 500 },
        { ssgs.sausage, 1500, 1000 },
        { ssgs.sausage, 2000, 500 },
        { ssgs.sausage, 2000, 1000 },
        { ssgs.sausage, 2200, 560 },
    };

    //vector resizing
    isDialogueV.resize(30);
    questV.resize(30);
    isItemV.resize(30);
    counterPressed.resize(30);
    chadTextV.resize(30);

    //buy beer quest
    beer = LoadTexture("../src/sprites/inner country elements/germany/beer.png");
    beer.width = 200;
    beer.height = 200;

    //pizza quest
    flour = LoadTexture("../src/sprites/inner country elements/bulgaria/flour.png"); 
    salami = LoadTexture("../src/sprites/inner country elements/bulgaria/salami.png"); 
    cheese = LoadTexture("../src/sprites/inner country elements/bulgaria/cheese.png"); 
    mushroom = LoadTexture("../src/sprites/inner country elements/bulgaria/mushroom.png"); 
    
    flour.width = 150;
    flour.height = 150;

    cheese.width = 150;
    cheese.height = 150;

    mushroom.width = 150;
    mushroom.height = 150;

    pizzaIngredientsV = {
        { flour, 1000, 500 },
        { salami, 1000, 1000 },
        { cheese, 2000, 500 },
        { mushroom, 2000, 1000 },
    },
    
    pizza = LoadTexture("../src/sprites/inner country elements/bulgaria/pizza.png");

    pntng.painting = LoadTexture("../src/sprites/inner country elements/spain/painting.png");

    paintingV = {
        {pntng.painting, 1200, 800},
        {pntng.painting, 1500, 1000},
        {pntng.painting, 1600, 1300},
    };

    poison = LoadTexture("../src/sprites/inner country elements/germany/poison.png");
    poison.width = 150;
    poison.height = 200;

    poisonedBeer = LoadTexture("../src/sprites/inner country elements/germany/poisonedBeer.png");

    beer.width = 60;
    beer.height = 80;

    loop = LoadTexture("../src/sprites/inner country elements/romania/loop.png");

    fox = LoadTexture("../src/sprites/inner country elements/italy/fox.png");
    chicken = LoadTexture("../src/sprites/inner country elements/italy/chicken.png");
    seed = LoadTexture("../src/sprites/inner country elements/italy/seed.png");

    logicGameItemsV = {
        {fox, 860, 320},
        {chicken, 860, 520},
        {seed, 860, 720},
    };

    isLogicItemPicked.resize(3);
    itemGet.resize(3);
    itemOnOtherSide.resize(3);
    itemOnOtherSideCounter.resize(3);

    itemPutDown = {
        {2000, 320},
        {2000, 520},
        {2000, 720},
    };

    italyBackground = LoadTexture("../src/sprites/backgrounds/itBackground.png");
    boat = LoadTexture("../src/sprites/inner country elements/italy/boat.png");

    menu = LoadTexture("../src/sprites/backgrounds/mainMenuBackground.png"); 
    newGame = LoadTexture("../src/sprites/Menus and boards/newGameClean.png"); 
    newGameHover = LoadTexture("../src/sprites/Menus and boards/newGameHover.png"); 
    quit = LoadTexture("../src/sprites/Menus and boards/quitClean.png");
    quitHover = LoadTexture("../src/sprites/Menus and boards/quitHover.png");

    helpMenu = LoadTexture("../src/sprites/Map images/helpMenu.png");

    okButtonHorseRace = LoadTexture("../src/sprites/Map images/okCLean.png");
    okButtonHorseRaceHover = LoadTexture("../src/sprites/Map images/okHover.png");
    horseOptionMenu = LoadTexture("../src/sprites/inner country elements/france/horseBetMenu.png");

    fillCheck = LoadTexture("../src/sprites/Map images/check.png");

    suspectBetMenu = LoadTexture("../src/sprites/inner country elements/romania/killerMenu.png");

    //landmark

    //france
    eiffelTower = LoadTexture("../src/sprites/inner country elements/france/eifelTower.png"); 
    arcDeTriomphe = LoadTexture("../src/sprites/inner country elements/france/triumfalnaArka.png");
    //italy
    colliseum = LoadTexture("../src/sprites/inner country elements/italy/colliseum.png");
    pizzaTower = LoadTexture("../src/sprites/inner country elements/italy/pizza.png");

    colliseum.width *= 2;
    colliseum.height *= 2;

    pizzaTower.width *= 2;
    pizzaTower.height *= 2;
    //germany
    kiolnWall = LoadTexture("../src/sprites/inner country elements/germany/kionWall.png");
    germanyKingdom = LoadTexture("../src/sprites/inner country elements/germany/germanyKingdom.png");

    kiolnWall.width *= 2.5;
    kiolnWall.height *= 2.5;

    germanyKingdom.width *= 2;
    germanyKingdom.height *= 2;
    //spain
    spainKingdom = LoadTexture("../src/sprites/inner country elements/spain/spainKingdom.png");

    spainKingdom.width *= 3;
    spainKingdom.height *= 3;

    spainMonument = LoadTexture("../src/sprites/inner country elements/spain/spainMonument.png");

    spainMonument.width *= 2;
    spainMonument.height *= 2;

    //romania
    draculaCastle = LoadTexture("../src/sprites/inner country elements/romania/castle.png");
    parlament = LoadTexture("../src/sprites/inner country elements/romania/parlament.png");

    draculaCastle.width *= 3;
    draculaCastle.height *= 3;

    parlament.width *= 2.5;
    parlament.height *= 2.5;


    noodle1 = LoadTexture("../src/sprites/inner country elements/italy/noodles/noodles1.png");
    noodle2 = LoadTexture("../src/sprites/inner country elements/italy/noodles/noodles2.png");
    noodle3 = LoadTexture("../src/sprites/inner country elements/italy/noodles/noodles3.png");
    noodle4 = LoadTexture("../src/sprites/inner country elements/italy/noodles/noodles4.png");
    noodle5 = LoadTexture("../src/sprites/inner country elements/italy/noodles/noodles5.png");

    cheeseNoodles = LoadTexture("../src/sprites/inner country elements/italy/noodles/cheeseNoodles.png");

    noodlesV = {
        {noodle1, 300, 600},
        {noodle2, 500, 600},
        {noodle3, 700, 600},
        {noodle4, 2000, 600},
        {noodle5, 2100, 800},
        {cheeseNoodles, 2000, 900}
    };

    grBackground = LoadTexture("../src/sprites/backgrounds/grBackground.png");
    itBackground = LoadTexture("../src/sprites/backgrounds/itBackground.png");
    romBackground = LoadTexture("../src/sprites/backgrounds/roBackground.png"); 
    frBackground = LoadTexture("../src/sprites/backgrounds/frBackground.png");  
    spBackground = LoadTexture("../src/sprites/backgrounds/spBackground.png");

    chadTextV.at(1) = { "Pickup the heart", "Go to the heart and take it.", "Reward:           1000$" };
    chadTextV.at(3) = { "Get the key and combine it!", "Find other itema and go combine it", "Reward:           750$" };
    chadTextV.at(7) = { "Collect all the sausages!", "Collect all the sausages", "Reward:           1000$" };
    chadTextV.at(9) = { "Buy Chad a beer!", "Buy Chad a beer", "Reward:           750$" };
    chadTextV.at(14) = { "Make pizza!", "Collect all the ingedients,\n give them to\nthe baker and return the pizza", "Reward:           1000$" };
    chadTextV.at(17) = { "Collect the paintings!", "Collect the paintings.", "Reward:           750$" };
    chadTextV.at(24) = { "Collect the noodles!", "Collect the noodles.", "Reward:           750$" };

    tomato = LoadTexture("../src/sprites/inner country elements/spain/tomato.png");
    tomato.width = 100;
    tomato.height = 100;
}

void Game::backstory()
{
    setWidthAndHeight(backstoryImg);
    DrawTexture(backstoryImg, 0, 0, WHITE);
    DrawTexture(backstoryImg, 0, 0, WHITE);
    // backstoryTypewriteEffect(backstoryText);
}

void Game::hoverEffects(Texture2D& country, float posx, float posy, float posxTarget, float posyTarget)
{
    DrawTexture(country, posx, posy, WHITE);
    DrawTexture(targetHover, posxTarget, posyTarget, WHITE);
}

void Game::moveAirplane(const countryPosition& countryPosition)
{
    Vector2 difference = { countryPosition.x - plane.planeCurrentPosX,  countryPosition.y - plane.planeCurrentPosY };

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
        else if (vehicleChoice == 1)
            plane.planeT = trainRight;
        else {
            //plane.planeT = touranRight;
        }
    }
}

void Game::transportMenuF()
{
    if (enableClick)
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

    printMoney = to_string(allMoneyCopy);

    if (allMoney != allMoneyCopy)
    {
        if (allMoney < allMoneyCopy)
        {
            allMoneyCopy -= 20;
        }
        else {
            allMoneyCopy += 20;
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
        vehicleSound = touranSound;
    }


    
    DrawTexture(map, 0, 0, WHITE);

    for (int i = 0; i < 6; i++)
    {
        if (!changeCircles[i] && !isTransportMenuOn && enableClick && i != 4 && !hideCountries)
        {
            DrawTexture(target, circles[i].x - 20, circles[i].y - 5, WHITE);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (!hideCountries && ((CheckCollisionPointCircle(mousePoint, circles[i], 30) || (changeCircles[i]) && !isTransportMenuOn && enableClick)) && i != 4)
        {
            hoverEffects(countriesV[i].country, countriesV[i].x, countriesV[i].y, circles[i].x - 20, circles[i].y - 5);
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
        for (int i = 0; i < 6; i++)
        {
            if (i != coutnryNumber)
                countries[i] = 0;
            else
            {
                countries[coutnryNumber] = 1;

                //change this switch to set up relative positions to hero in diff countries
                switch (coutnryNumber)
                {
                    case 1:
                        player.playerCords = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
                        break;
                    case 2:
                        player.playerCords = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
                        break;
                    case 3:
                        player.playerCords = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
                        break;
                    case 4:
                        player.playerCords = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
                        break;
                    case 5:
                        player.playerCords = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
                        break;
                }
            }
        }
    }

    for(int i = 0; i < 6; i++)
    {
        if (!banCountry[i])
        {
            if (isClicked())
            {
                if (CheckCollisionPointCircle(mousePoint, circles[i], 30))
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

                    hideCountries = true;
                }
            }
        }
    }

    if (isFlying && planeToMove)
    {

        if (playSound && audioIsClicked)
        {
            
            player.playerCords = Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
            PlaySound(vehicleSound);
        }

        moveAirplane(countryPositions.at(countryFly));

        playSound = 0;
    }

    if (banCountry[0] && banCountry[1] && banCountry[2] && banCountry[3] && banCountry[5])
    {
        isBulgariaEnd = true;
    }

    for (int i = 0; i < 6; i++)
    {
        if (countries[i] && !banCountry[i])
        {
            StopSound(vehicleSound);
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GRAY);
            
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
                {
                if (countries[i])
                    switch (i)
                    {

                    case 0:
                        
                        DrawTexture(spBackground, player.XBg, player.YBg, WHITE);
                        DrawTexturePro(player.playerSprite, player.view, player.move, Vector2{ 10, 10 }, 0, WHITE);

                        npc.DrawNPCAnimation(player.XBg, player.YBg, 0, tourguideGreen, 600, 600);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 2, tourguideYellow, 500, 1100);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 3, addict, 1600, 200);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 4, chadBg, 1600, 900);

                   
                        bulls.Update();
                        bulls.IfDisplayed(1);
                        bulls.CheckCollisionBulls(player.move, player.playerCords);
                        bulls.CheckCollisionBulls(player.move, player.playerCords);
                        bulls.Draw(player.XBg, player.YBg);
                        spainLevel();
                        break;

                    case 1:
                        DrawTexture(frBackground ,player.XBg, player.YBg, WHITE);
                        DrawTexturePro(player.playerSprite, player.view, player.move, Vector2{ 10, 10 }, 0, WHITE);

                        npc.DrawNPCAnimation(player.XBg, player.YBg, 5, tourguideGreen, 400, 400);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 6, tourguideYellow, 2070, 700);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 7, chadBg, 100, 1000);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 8, chadFr, 1000, 800);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 9, scientist, 1500, 300);

                        
                        race.DrawHorseAnimation(player.XBg, player.YBg);
                        franceLevel();                        
                        break;

                    case 2:
                        DrawTexture(itBackground, player.XBg, player.YBg, WHITE);
                        DrawTexturePro(player.playerSprite, player.view, player.move, Vector2{ 10, 10 }, 0, WHITE);

                        npc.DrawNPCAnimation(player.XBg, player.YBg, 10, tourguideGreen, 2300, 650);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 11, tourguideYellow, 360, 1000);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 12, addict, 200, 300);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 13, rival, 2400, 1200);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 14, chadBg, 700, 320);

                        italyLevel();                    
                        break;

                    case 3:
                        DrawTexture(grBackground, player.XBg, player.YBg, WHITE);
                        DrawTexturePro(player.playerSprite, player.view, player.move, Vector2{ 10, 10 }, 0, WHITE);

                        npc.DrawNPCAnimation(player.XBg, player.YBg, 15, tourguideGreen, 500, 500);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 16, tourguideYellow, 2000, 800);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 17, addict, 1800, 1200);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 18, scientist, 2000, 300);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 19, chadBg, 1000, 600);

                        
                        assassin.Draw(player.XBg, player.YBg, player.MoveBg);
                        assassin.Update(player.playerCords, player.XBg, player.YBg, player.move, player.MoveBg);
                        germanyLevel();                   
                        break;

                    case 5:
                        DrawTexture(romBackground, player.XBg, player.YBg, WHITE);
                        DrawTexturePro(player.playerSprite, player.view, player.move, Vector2{ 10, 10 }, 0, WHITE);

                        npc.DrawNPCAnimation(player.XBg, player.YBg, 20, tourguideGreen, 600, 630);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 21, tourguideYellow, 1900, 1100);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 22, policeman, 300, 800);
                        npc.DrawNPCAnimation(player.XBg, player.YBg, 23, chadBg, 1700, 500);

                        romaniaLevel();                  
                        break;

                    default:
                        break;
                    }
               
                }
               
                if (IsKeyDown(KEY_TAB))
                {
                    showInventory();
                }

                DrawTexture(backButtonClean, 1800, 940, WHITE);

                if (CheckCollisionPointRec(mousePoint, backButton) && !isClicked())
                {
                    DrawTexture(backButtonHover, 1800, 940, WHITE);
                }
            }
            else {
                DrawTexture(countriesHoveredV[i].country, countriesHoveredV[i].x, countriesHoveredV[i].y, WHITE);
                isTransportMenuOn = false;
            }

            if (isClicked() && CheckCollisionPointRec(mousePoint, backButton))
            {
                enableClick = true;
                unloadBack = true;
                banCountry[i] = true;

                hideCountries = false;
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
    DrawText(printMoney.c_str(), 85, 50, 50, moneyColor);

    dialogues("Narrator", "Vankata", menuDialogue, 1, 1000, 1000, 27, isDialogueV, counterPressed, true);

    if (counterPressed.at(27) >= 2 && counterPressed.at(27) <= 3)
    {
        mainMenuDialogue = false;

        counterPressed.at(27) = 4;
    }

    if (isBulgariaEnd)
    {
        DrawTexture(goldenTarget, circles[5].x, circles[5].y + 100, WHITE);
        DrawRectangleRec(Fader, Fade(BLACK, 0.7));
        DrawTexture(gameIsFinished, 400, 175, WHITE);

        if (points < allPoints)
        {
            points += 50;
        }

        pointText = to_string(points);

        DrawText(pointText.c_str(), 1015, 485, 70, BLACK);

        DrawText("Score: ", 725,475, 80,BLACK);

        DrawTexture(quit, 875, 780, WHITE);

        DrawRectangleRec(rectangleQuit, BLANK);

        if (CheckCollisionPointRec(mousePoint, rectangleQuit) && isClicked())
        {
            isQuitting = true;
        }
        else if (CheckCollisionPointRec(mousePoint, rectangleQuit) && !isClicked())
        {
            DrawTexture(quitHover,875,780, WHITE);
        }
    }
}

void Game::dialogues(string firstName, string secondName, string characterDialogues[], int dialogueLength, int chadCordsX, int chadCordsY, int index, vector<isDialogue>& isDialogue, vector<int>& counterPressed, bool ePressed)
{
    if(findDistance(player, chadCordsX, chadCordsY) || mainMenuDialogue)
    {
        if ((IsKeyDown(KEY_E) || ePressed) && !isDialogue.at(index).isDialogueEntered)
        {
            isDialogue.at(index).isDialogueStarted = true;
            isDialogue.at(index).isDialogueContinued = false;
            isDialogue.at(index).isDialogueEntered = true;
        }

        if (isDialogue.at(index).isDialogueStarted && !isDialogue.at(index).isDialogueContinued)
        {
            DrawTexture(dialogueBox, 278, 715, WHITE);

            DrawTextEx(headerFont, firstName.c_str(), { 328, 750 }, 24, 5, textColor);

            DrawText(characterDialogues[counterPressed.at(index)].c_str(), 368, 900, 24, textColor);

            DrawTexture(finishedDialogueArrow, 1518, 965, WHITE);   
        }

        if (IsKeyPressed(KEY_ENTER) && isDialogue.at(index).isDialogueEntered)
        {
            counterPressed.at(index)++;

            isDialogue.at(index).isDialogueStarted = false;
            isDialogue.at(index).isDialogueContinued = true;
        }
        
        if (isDialogue.at(index).isDialogueContinued && !isDialogue.at(index).isDialogueStarted && counterPressed.at(index) <= dialogueLength)
        {
            DrawTexture(dialogueBox, 278, 715, WHITE);

            if (counterPressed.at(index) % 2 == 0 && counterPressed.at(index) > 0)
            {
                DrawTextEx(headerFont, secondName.c_str(), { 328, 750 }, 24, 5, textColor);
            }
            else {
                DrawTextEx(headerFont, firstName.c_str(), { 328, 750 }, 24, 5, textColor);
            }
       
            DrawText(characterDialogues[counterPressed.at(index)].c_str(), 328, 900, 24, textColor);

            DrawTexture(finishedDialogueArrow, 1518, 965, WHITE);          
        }
    }
}

void Game::showInventory()
{
    DrawTexture(inventory, 505, 223, WHITE);

    if (isItemV.at(1).isItemPicked)
        DrawTexture(barrel, 1000, 500, WHITE);

    if (!isGripperInventory)
        DrawTexture(gripper, 1300, 500, WHITE);

    if (itemRequire[0])
        DrawTexture(key, 1000, 500, WHITE);

    if (itemRequire[1])
        DrawTexture(stone, 1200, 500, WHITE);

    if(itemRequire[2])
        DrawTexture(metalPieces, 1200, 500, WHITE);

    if(beerShowInventory)
        DrawTexture(beer, 900, 500, WHITE);

    if (finishBakerDialogue)
        DrawTexture(pizza, 950, 500, WHITE);

    if(showPoisonInventory)
        DrawTexture(poison, 950, 500, WHITE);

    if (showLoop)
    {
        DrawTexture(loop, 950, 500, WHITE);
    }
}

void Game::quest(vector<chadText> text, int index)
{
    if (!openQuest)
    {
        DrawTexture(questBoardT, 581, 233, WHITE);
        DrawTexture(cancelButton, 610, 758, WHITE);
        DrawTexture(acceptButton, 1090, 758, WHITE);

        DrawTextEx(headerFont, text.at(index).title.c_str(), { 635, 265 }, 48, 5, textColor);
        DrawTextEx(textFont, text.at(index).description.c_str(), { 635, 400 }, 32, 5, textColor);
        DrawTextEx(textFont, text.at(index).reward.c_str(), { 635, 640 }, 32, 5, textColor);

        if (mousePoint.y >= 758 && mousePoint.y <= 834)
        {
            if (mousePoint.x >= 610 && mousePoint.x <= 835 && !openQuest)
            {
                DrawTexture(cancelButtonHover, 610, 758, WHITE);

                if (isClicked())
                {
                    questV.at(index).openQuest = true;
                    questV.at(index).acceptQuest = false;
                }
            }
            else if (mousePoint.x >= 1090 && mousePoint.x <= 1308 && !openQuest)
            {
                DrawTexture(acceptButtonHover, 1090, 758, WHITE);

                if (isClicked())
                {
                    questV.at(index).openQuest = true;
                    questV.at(index).acceptQuest = true;
                }
            }
        }
    }
}

void Game::itemPicked(int itemX, int itemY, bool& itemPicked)
{
    if (findDistance(player, itemX, itemY) && IsKeyPressed(KEY_Q))
    {
        itemPicked = true;
    }
}

void Game::returnItem(int reward, int posX, int posY, int index, vector<isItem> isItem)
{
    if (isItem.at(index).isItemPicked && findDistance(player, posX, posY) && IsKeyPressed(KEY_Q))
    {
        isItem.at(index).isDelivered = true;
        isItem.at(index).isItemPicked = false;
        allMoney += reward;
    }
}

void Game::optionsMenu()
{
    DrawTexture(optionImage, 1840, 30, WHITE);

    if ((mousePoint.x >= 1845 && mousePoint.x <= 1900) && (mousePoint.y >= 20 && mousePoint.y <= 70))
    {
        DrawTexture(optionImageHovered, 1840, 30, WHITE);

        if (isClicked())
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
                    counterHelpMenuClicked++;
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

        if (counterHelpMenuClicked % 2 != 0)
        {
            DrawTexture(helpMenu, 1110, 8, WHITE);
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

        mainMenu();

        optionsMenu();

        isUserQuitting(isQuitting, enableClick, mousePoint, confirmationT, darkerWindow, isTransportMenuOn, quitButtons);

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

void Game::spainLevel()
{
    DrawTexture(spainKingdom, 100 + player.XBg, 100 + player.YBg, WHITE);
    DrawTexture(spainMonument, 100 + player.XBg, 1050 + player.YBg, WHITE);
    
    dialogues("Vankata ", "Chad", paintingCollectDialogue, 1, 1600, 200, 17, isDialogueV, counterPressed, false);

    if (!getTomato)
    {
        DrawTexture(tomato, 2725 + player.XBg, 650 + player.YBg, WHITE);
    }

    if(findDistance(player, 2725, 650) && IsKeyPressed(KEY_Q))
        getTomato = true;

    if (getTomato && findDistance(player, 1600, 900) && IsKeyPressed(KEY_Q))
    {
        allMoney += 500;
    }

    if (counterPressed.at(17) >= 2 && counterPressed.at(17) <= 3)
    {
        showPaintingInventory = true;

        counterPressed.at(17) = 4;
    }

    if (showPaintingInventory)
    {
        if (!questV.at(17).openQuest)
            quest(chadTextV, 17);

        for (int i = 0; i < 3; i++)
        {
            if (!showPaintings[i] && questV.at(17).acceptQuest)
                DrawTexture(paintingV.at(i).painting, paintingV.at(i).posX + player.XBg, paintingV.at(i).posY + player.YBg, WHITE);
        }

        for (int i = 0; i < 3; i++) {
            if (IsKeyPressed(KEY_Q) && findDistance(player, paintingV.at(i).posX, paintingV.at(i).posY))
            {
                showPaintings[i] = true;
            }
        }
    }

    if (showPaintings[0] && showPaintings[1] && showPaintings[2])
    {
        dialogues("Vankata ", "Chad", paintingCollectDialogueFinish, 1, 1600, 200, 18, isDialogueV, counterPressed, false);

        if (counterPressed.at(18) >= 2 && counterPressed.at(18) <= 3)
        {
            allMoney += 500;

            counterPressed.at(18) = 4;
        }
    }
}

void Game::franceLevel()
{
    DrawTexture(eiffelTower, 0 + player.XBg, 0 + player.YBg, WHITE);
    DrawTexture(arcDeTriomphe, 0 + player.XBg, 0 + player.YBg, WHITE);

    //return item
    dialogues("Vankata", "Chad", barrelDialogue, 3, 1000, 800, 1, isDialogueV, counterPressed, false);

    dialogues("Vankata", "Chad", EiffelDialogue, 3, 400, 400, 0, isDialogueV, counterPressed, false);

    dialogues("Vankata", "Chad", ArcDialogue, 3, 2070, 700, 29, isDialogueV, counterPressed, false);

    if (!isItemV.at(1).isItemPicked && !isItemV.at(1).isDelivered && counterPressed.at(1) >= 4 && counterPressed.at(1) <= 5)
    {
        if (!questV.at(1).openQuest)
            quest(chadTextV, 1);

        if(questV.at(1).acceptQuest)
            DrawTexture(barrel, 1000 + player.XBg, 500 + player.YBg, WHITE);
    }

    itemPicked(1000, 500, isItemV.at(1).isItemPicked);

    if (counterPressed.at(1) >= 4 && counterPressed.at(1) <= 5 && findDistance(player, 1000, 800) && IsKeyPressed(KEY_Q))
    {
        allMoney += 1000;
        counterPressed.at(1) = 6;
    }

    if (IsKeyPressed(KEY_E))
    {
        ePressedCounter = 1;
    }

    if (findDistance(player, 100, 1000) && ePressedCounter == 1)
    {
        DrawTexture(horseOptionMenu, 698, 353, WHITE);
        DrawTexture(okButtonHorseRace, 1090, 655, WHITE);
        
        if (mousePoint.y >= 580 && mousePoint.y <= 600)
        {
            if (mousePoint.x >= 770 && mousePoint.x <= 800 && isClicked())  
                horseBet = 1;
            else if (mousePoint.x >= 890 && mousePoint.x <= 920 && isClicked())
                horseBet = 2;       
            else if (mousePoint.x >= 1005 && mousePoint.x <= 1035 && isClicked())
                horseBet = 3;         
            else if (mousePoint.x >= 1130 && mousePoint.x <= 1160 && isClicked())     
                horseBet = 4; 
        }

        if (horseBet == 1)
            DrawTexture(fillCheck, 770, 600, WHITE);
        else if (horseBet == 2)
            DrawTexture(fillCheck, 890, 600, WHITE);
        else if (horseBet == 3)
            DrawTexture(fillCheck, 1005, 600, WHITE);
        else if (horseBet == 4)
            DrawTexture(fillCheck, 1130, 600, WHITE);

        if (mousePoint.y >= 630 && mousePoint.y <= 690 && mousePoint.x >= 1090 && mousePoint.x <= 1190)
        {
            DrawTexture(okButtonHorseRaceHover, 1090, 655, WHITE);

            if (isClicked())
            {
                race.IfHorseRun(1, 1); // <-For Actual Implementing after dialogue (fir arg is for horse running or not and sec arg is for drawing horses or not)

                if(horseBet == race.HorseIndex[3])
                {
                    allMoney += 500;
                }
            }
        }
    }
       
}

void Game::italyLevel()
{
    DrawTexture(colliseum, 100 + player.XBg, 1000 + player.YBg, WHITE);
    DrawTexture(pizzaTower, 2300 + player.XBg, 200 + player.YBg, WHITE);

    dialogues("Vankata ", "Chad", startNoodleQuestDialogue, 2, 200, 300, 24, isDialogueV, counterPressed, false);

    if (counterPressed.at(24) >= 3 && counterPressed.at(24) <= 4)
    {
        showNoodleInventory = true;

        counterPressed.at(24) = 5;
    }

    if (showNoodleInventory)
    {
        if (!questV.at(24).openQuest)
            quest(chadTextV, 24);

        for (int i = 0; i < 6; i++)
        {
            if (!showNoodles[i] && questV.at(24).acceptQuest)
                DrawTexture(noodlesV.at(i).texture, noodlesV.at(i).posX + player.XBg, noodlesV.at(i).posY + player.YBg, WHITE);
        }


        for (int i = 0; i < 6; i++) {
            if (IsKeyPressed(KEY_Q) && findDistance(player, noodlesV.at(i).posX, noodlesV.at(i).posY))
            {
                showNoodles[i] = true;
            }
        }
    }

    if (showNoodles[0] && showNoodles[1] && showNoodles[2] && showNoodles[3] && showNoodles[4] && showNoodles[5])
    {
        dialogues("Vankata ", "Chad", finishNoodleQuestDialogue, 2, 200, 300, 25, isDialogueV, counterPressed, false);

        if (counterPressed.at(25) >= 3 && counterPressed.at(25) <= 4)
        {
            allMoney += 500;

            counterPressed.at(25) = 5;
        }
    }

    //logic game
    if (!isLogicGameFinished)
    {
        for (int i = 0; i < 3; i++)
        {
            if (!isLogicItemPicked.at(i) && !itemGet.at(i) && !itemOnOtherSide.at(i))
            {
                DrawTexture(logicGameItemsV.at(i).texture, logicGameItemsV.at(i).posX + player.XBg, logicGameItemsV.at(i).posY + player.YBg, WHITE);
            }

            if (itemGet.at(i) && !changeBoatPos && !itemOnOtherSide.at(i))
            {
                DrawTexture(itemInBoat, 1250 + player.XBg, 400 + player.YBg, WHITE);
            }

            if ((itemGet.at(i) || itemOnOtherSideCounter.at(i) == 2) && changeBoatPos && !itemOnOtherSide.at(i))
            {
                DrawTexture(itemInBoat, 1770 + player.XBg, 400 + player.YBg, WHITE);
            }

            if (itemOnOtherSide.at(i))
            {
                DrawTexture(logicGameItemsV.at(i).texture, itemPutDown.at(i).x + player.XBg, itemPutDown.at(i).y + player.YBg, WHITE);
            }
        }

        if (!changeBoatPos)
            DrawTexture(boat, 1220 + player.XBg, 520 + player.YBg, WHITE);

        if (findDistance(player, 990, 520) && !lockBoat)
        {
            if (IsKeyPressed(KEY_Q))
                changeBoatPosCounter++;
            //lockBoat = true;


            if (itemGet.at(0))
            {
                itemGet.at(1) = false;
                itemGet.at(2) = false;
            }
            else if (itemGet.at(1))
            {
                itemGet.at(0) = false;
                itemGet.at(2) = false;
            }
            else if (itemGet.at(2))
            {
                itemGet.at(0) = false;
                itemGet.at(1) = false;
            }
        }

        if (changeBoatPos && !lockBoat)
        {
            DrawTexture(boat, 1740 + player.XBg, 520 + player.YBg, WHITE);

            if (IsKeyPressed(KEY_Q) && !findDistance(player, 990, 520))
                changeBoatPosCounter++;

            //lockBoat = true;
        }

        if (mousePoint.x >= 465 && mousePoint.x <= 580 && !changeBoatPos && findDistance(player, 990, 520))
        {
            lockBoat = false;

            if (mousePoint.y >= 190 && mousePoint.y <= 290 && isClicked() && !itemOnOtherSide.at(0))
            {
                itemInBoat = logicGameItemsV.at(0).texture;

                itemGet.at(0) = true;
            }
            else if (mousePoint.y >= 380 && mousePoint.y <= 490 && isClicked() && !itemOnOtherSide.at(1))
            {
                itemInBoat = logicGameItemsV.at(1).texture;

                itemGet.at(1) = true;
            }
            else if (mousePoint.y >= 555 && mousePoint.y <= 715 && isClicked() && !itemOnOtherSide.at(2))
            {
                itemInBoat = logicGameItemsV.at(2).texture;

                itemGet.at(2) = true;
            }
        }
        else if (mousePoint.x >= 1170 && mousePoint.x <= 1415 && changeBoatPos)
        {
            lockBoat = false;

            if (mousePoint.y >= 190 && mousePoint.y <= 290 && isClicked())
            {
                itemOnOtherSideCounter.at(0)++;
            }
            else if (mousePoint.y >= 380 && mousePoint.y <= 490 && isClicked())
            {
                itemOnOtherSideCounter.at(1)++;
            }
            else if (mousePoint.y >= 555 && mousePoint.y <= 715 && isClicked())
            {
                itemOnOtherSideCounter.at(2)++;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (itemOnOtherSideCounter.at(i) % 2 != 0)
            {
                itemOnOtherSide.at(i) = false;
                itemGet.at(i) = true;

                itemInBoat = logicGameItemsV.at(i).texture;
            }
            else if (itemOnOtherSideCounter.at(i) % 2 == 0 && itemOnOtherSideCounter.at(i) > 0)
            {
                itemOnOtherSide.at(i) = true;
                itemGet.at(i) = false;
            }
        }

        if (changeBoatPosCounter == 1)
            changeBoatPos = true;
        else if (changeBoatPosCounter == 2)
        {
            changeBoatPos = false;
            changeBoatPosCounter = 0;
        }

        if ((itemOnOtherSide.at(0) && !itemOnOtherSide.at(1) && !itemOnOtherSide.at(2)))
        {
            for (int i = 0; i < 3; i++)
            {
                itemOnOtherSide.at(i) = false;
                itemGet.at(i) = false;
                itemInBoat = emptyTexture;
                itemOnOtherSideCounter.at(i) = 0;
            }
        }

        if (itemOnOtherSide.at(0) && itemOnOtherSide.at(1) && itemOnOtherSide.at(2))
        {
            allMoney += 1000;
            isLogicGameFinished = true;
        }
    }

    //pizza quest
    dialogues("Vankata ", "Chad", startPizzaCollectDialogue, 1, 2400, 1200, 14, isDialogueV, counterPressed, false);

    if (counterPressed.at(14) >= 2 && counterPressed.at(14) <= 3)
    {
        showIngredients = true;

        counterPressed.at(14) = 4;
    }

    if (showIngredients)
    {
        if (!questV.at(14).openQuest)
            quest(chadTextV, 14);

        for (int i = 0; i < 4; i++)
        {
            if (!drawIngredients[i])
            {
                if (questV.at(14).acceptQuest)
                    DrawTexture(pizzaIngredientsV.at(i).texture, pizzaIngredientsV.at(i).posX + player.XBg, pizzaIngredientsV.at(i).posY + player.YBg, WHITE);
            }
        }

        for (int i = 0; i < 4; i++) {
            if (IsKeyPressed(KEY_Q) && findDistance(player, pizzaIngredientsV.at(i).posX, pizzaIngredientsV.at(i).posY))
            {
                drawIngredients[i] = true;
            }
        }
    }

    if (drawIngredients[0] && drawIngredients[1] && drawIngredients[2] && drawIngredients[3])
    {
        dialogues("Vankata ", "Chad", bakerCombineDialogue, 2, 700, 320, 15, isDialogueV, counterPressed, false);

        if (counterPressed.at(15) >= 3 && counterPressed.at(15) <= 4)
        {
            allMoney -= 400;

            counterPressed.at(15) = 5;

            finishBakerDialogue = true;
        }
    }

    if (finishBakerDialogue)
    {
        dialogues("Vankata ", "Chad", finishPizzaCollectDialogue, 1, 2400, 1200, 16, isDialogueV, counterPressed, false);

        if (counterPressed.at(16) >= 2 && counterPressed.at(16) <= 3)
        {
            allMoney += 1000;

            counterPressed.at(16) = 4;

            finishBakerDialogue = false;
        }
    }
}

void Game::germanyLevel()
{
    DrawTexture(kiolnWall, 200 + player.XBg, 215 + player.YBg, WHITE);
    DrawTexture(germanyKingdom, 2200 + player.XBg, 600 + player.YBg, WHITE);

    //saussages collect
    dialogues("Vankata ", "Chad", startQuestDialogue, 1, 1800, 1200, 7, isDialogueV, counterPressed, false);

    if (counterPressed.at(7) >= 2 && counterPressed.at(7) <= 3)
    {
        showSausagesInventory = true;

        counterPressed.at(7) = 4;
    }

    if (showSausagesInventory)
    {
        if(!questV.at(7).openQuest)
            quest(chadTextV, 7);

        for (int i = 0; i < 5; i++)
        {
            if(!showSausages[i])
            {
                if(questV.at(7).acceptQuest)
                    DrawTexture(sausagesV.at(i).sausage, sausagesV.at(i).posX + player.XBg, sausagesV.at(i).posY + player.YBg, WHITE);
            }
        }

        for (int i = 0; i < 5; i++) {
            if (IsKeyPressed(KEY_Q) && findDistance(player, sausagesV.at(i).posX, sausagesV.at(i).posY))
            {
                showSausages[i] = true;
            }
        }
    }

    if (showSausages[0] && showSausages[1] && showSausages[2] && showSausages[3] && showSausages[4])
    {
        dialogues("Vankata ", "Chad", finishAddictDialogue, 1, 1800, 1200, 8, isDialogueV, counterPressed, false);

        if (counterPressed.at(8) >= 2 && counterPressed.at(8) <= 3)
        {
            allMoney += 1000;

            counterPressed.at(8) = 4;
        }
    }

    dialogues("Vankata ", "Chad", getBeerQuestDialogue, 2, 1000, 1000, 9, isDialogueV, counterPressed, false);

    if (counterPressed.at(9) >= 3 && counterPressed.at(9) <= 4)
    {
        isBeerDialogueFinished[0] = true;

        counterPressed.at(9) = 5;
    }

    if (isBeerDialogueFinished[0])
    {
        if (!questV.at(9).openQuest)
            quest(chadTextV, 9);

        if (questV.at(9).acceptQuest)
            dialogues("Vankata ", "Gubarq", buyBeerDialogue, 2, 2000, 1000, 10, isDialogueV, counterPressed, false);
    }


    if (counterPressed.at(10) >= 3 && counterPressed.at(10) <= 4)
    {
        isBeerDialogueFinished[0] = false;
        isBeerDialogueFinished[1] = true;

        allMoney -= 300;

        counterPressed.at(10) = 5;
    }

    if (isBeerDialogueFinished[1])
    {
        beerShowInventory = true;

        dialogues("Vankata ", "Gubarq", bringBeerDialogue, 2, 1500, 1000, 11, isDialogueV, counterPressed, false);
    }

    if (counterPressed.at(11) >= 3 && counterPressed.at(11) <= 4)
    {
        allMoney += 700;
        beerShowInventory = false;
        isBeerDialogueFinished[1] = false;

        counterPressed.at(11) = 5;
    }

    //minigame
    dialogues("Vankata ", "Scientist", getPoisonDialogue, 1, 2000, 300, 19, isDialogueV, counterPressed, false);

    if (counterPressed.at(19) >= 2 && counterPressed.at(19) <= 3)
    {
        showPoisonInventory = true;

        finishGetPoisonDialogue = true;
        assassin.CheckMiniGame(player.MoveBg, player.move, finishGetPoisonDialogue);
        counterPressed.at(19) = 4;
    }

    if (!swapBeers)
        DrawTexture(beer, 950 + player.XBg, 1400 + player.YBg, WHITE);
    else
        DrawTexture(poisonedBeer, 950 + player.XBg, 1400 + player.YBg, WHITE);

    if (finishGetPoisonDialogue)
    {
        if (IsKeyPressed(KEY_Q) && findDistance(player, 950, 1400))
        {
            swapBeers = true;
            showPoisonInventory = false;
        }
    }

    if (swapBeers)
    {
        dialogues("Vankata ", "Scientist", finishMinigameDialogue, 1, 2000, 300, 20, isDialogueV, counterPressed, false);
    }

    if (counterPressed.at(20) >= 2 && counterPressed.at(20) <= 3)
    {
        allMoney += 500;

        counterPressed.at(20) = 4;
    }
}


void Game::romaniaLevel()
{
    DrawTexture(parlament, 200 + player.XBg, 215 + player.YBg, WHITE);
    DrawTexture(draculaCastle, 2000 + player.XBg, 800 + player.YBg, WHITE);

    //find gripper
    if (IsKeyPressed(KEY_Q) && findDistance(player, 1300, 1000))
    {
        isGripperPicked = true;
        isGripperInventory = false;
    }

    if (isGripperPicked)
    {
        dialogues("Vankata ", "Vankata ", gripperFoundDialogue, 1, 1300, 1000, 2, isDialogueV, counterPressed, true);

        dialogues("Vankata ", "Mitaka", gripperReturnedDialogue, 2, 1700, 500, 3, isDialogueV, counterPressed, false);

        if (counterPressed.at(3) >= 3 && counterPressed.at(3) <= 4)
        {
            allMoney += 500;

            counterPressed.at(3) = 5;

            isGripperInventory = true;
        }
    }
    else
        DrawTexture(gripper, 1300 + player.XBg, 1000 + player.YBg, WHITE);

    /*dialogues("Vankata ", "Chad", getKeyDialogue, 2, 1000, 1000, 4, isDialogueV, counterPressed, false);

    if (counterPressed.at(4) >= 3 && counterPressed.at(4) <= 4)
    {
        itemRequire[0] = true;

        counterPressed.at(4) = 5;
    }
        

    if (IsKeyPressed(KEY_Q) && findDistance(player, 1500, 500))
    {
        itemRequire[1] = true;
    }

    if (itemRequire[1])
    {
        dialogues("Vankata ", "Vankata ", findStoneDialogue, 2, 1500, 500, 5, isDialogueV, counterPressed, true);

        if (itemRequire[0])
        {
            dialogues("Vankata ", "Jabata", itemCombinationDealDialogue, 3, 1500, 1000, 6, isDialogueV, counterPressed, false);

            if (counterPressed.at(6) >= 4 && counterPressed.at(6) <= 5)
            {
                itemRequire[0] = false;
                itemRequire[1] = false;
                itemRequire[2] = true;

                isStonePicked = true;

                counterPressed.at(6) = 6;

                allMoney -= 300;
            }
        }
    }
    else if(!isStonePicked)
        DrawTexture(stone, 1500 + player.XBg, 500 + player.YBg, WHITE);

    if (itemRequire[2])
    {
        dialogues("Vankata ", "Jabata", finishKeyQuestDialogue, 1, 1000, 1000, 12, isDialogueV, counterPressed, false);

        if (counterPressed.at(12) >= 2 && counterPressed.at(12) <= 3)
        {
            itemRequire[2] = false;

            allMoney += 800;

            counterPressed.at(12) = 4;
        }
    }*/

    //myrder mystery

    dialogues("Vankata ", "Policeman", startMurderMysteryDialogue, 2, 300, 800, 21, isDialogueV, counterPressed, false);

    if (counterPressed.at(21) >= 3 && counterPressed.at(21) <= 4)
    {
        showLoop = true;
        isMurderMysteryDialoguesStarted[0] = true;

        counterPressed.at(21) = 5;
    }

    if (isMurderMysteryDialoguesStarted[0])
    {
        dialogues("Vankata ", "Vankata ", atTheCrimeSceneDialogue, 2, 1463, 903, 22, isDialogueV, counterPressed, true);

        if (counterPressed.at(22) >= 3 && counterPressed.at(22) <= 4)
        {
            isMurderMysteryDialoguesStarted[0] = false;
            isMurderMysteryDialoguesStarted[1] = true;

            counterPressed.at(22) = 5;
        }
    }

    if (isMurderMysteryDialoguesStarted[1])
    {
        dialogues("Vankata", "Policeman", finishMurderMysteryDialogue, 3, 300, 800, 23, isDialogueV, counterPressed, false);

        if (counterPressed.at(23) >= 4 && counterPressed.at(23) <= 5)
        {
            isMurderMysteryDialoguesStarted[1] = false;
            isMurderMysteryDialoguesStarted[2] = true;

            counterPressed.at(23) = 6;
        }
    }

    if (isMurderMysteryDialoguesStarted[2])
    {
        if (findDistance(player, 300, 800))
        {
            DrawTexture(suspectBetMenu, 698, 353, WHITE);
            DrawTexture(okButtonHorseRace, 1090, 650, WHITE);

            if (mousePoint.y >= 580 && mousePoint.y <= 600)
            {
                if (mousePoint.x >= 770 && mousePoint.x <= 800 && isClicked())
                    quessSuspect = 1;
                else if (mousePoint.x >= 890 && mousePoint.x <= 920 && isClicked())
                    quessSuspect = 2;
                else if (mousePoint.x >= 1005 && mousePoint.x <= 1035 && isClicked())
                    quessSuspect = 3;
                else if (mousePoint.x >= 1130 && mousePoint.x <= 1160 && isClicked())
                    quessSuspect = 4;
            }

            if (quessSuspect == 1)
                DrawTexture(fillCheck, 770, 600, WHITE);
            else if (quessSuspect == 2)
                DrawTexture(fillCheck, 890, 600, WHITE);
            else if (quessSuspect == 3)
                DrawTexture(fillCheck, 1005, 600, WHITE);
            else if (quessSuspect == 4)
                DrawTexture(fillCheck, 1130, 600, WHITE);

            if (mousePoint.y >= 630 && mousePoint.y <= 690 && mousePoint.x >= 1090 && mousePoint.x <= 1190)
            {
                DrawTexture(okButtonHorseRaceHover, 1090, 650, WHITE);

                if (isClicked())
                {
                    isMurderMysteryDialoguesStarted[2] = false;

                    if (quessSuspect == correctSuspect)
                    {
                        allMoney += 500;    
                    }
                }
            }
        }
        showLoop = false;
    }
}

void Game::mainMenu()
{
    mousePoint = GetMousePosition();
    if (!isGameStarted)
    {
        if (audioIsClicked)
        {
            PlaySound(mapMusic);
        }

        DrawTexture(menu, 0, 0, WHITE);
        DrawTexture(newGame, 809, 650, WHITE);
        DrawTexture(quit, 878, 800, WHITE);

        if (mousePoint.x >= 815 && mousePoint.x <= 1127 && mousePoint.y >= 640 && mousePoint.y <= 705)
        {   
            DrawTexture(newGameHover, 809, 650, WHITE);

            if (isClicked())
            {
                isGameStarted = true;
                StopSound(mapMusic);
            }    
        }

        if (mousePoint.x >= 878 && mousePoint.x <= 1043 && mousePoint.y >= 790 && mousePoint.y <= 863)
        {
            DrawTexture(quitHover, 878, 800, WHITE);

            if (isClicked())
            {
                isQuitting = true;
                StopSound(mapMusic);
            }         
        }
    }     
    else
        mapEurope();   
}