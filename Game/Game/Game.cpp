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

    //fonts
    headerFont = LoadFont("../Fonts/headerFont.ttf");
    textFont = LoadFont("../aFonts/textFont.ttf");

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
    circles[4].x = 1362;
    circles[4].y = 825;

    //romania
    circles[5].x = 1350;
    circles[5].y = 720;

    backCircle.x = 1800;
    backCircle.y = 785;

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
    race.LoadSprites();
    npc.LoadSprites();
    assassin.LoadSprites();

    plane.planeCurrentPosX = 1360;
    plane.planeCurrentPosY = 850;

    enableClick = true;
    money = 2000;
    allMoney = 2000;
    moneyColor = { 51, 171, 69, 255 };

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

    target.width -= 5;
    target.height -= 5;

    targetHover.width -= 5;
    targetHover.height -= 5;
    

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

    /*touranSound = LoadSound("../Audios/Touran.mp3");
    trainSound = LoadSound("../Audios/Train.mp3");
    planeSound = LoadSound("../Audios/Plane.mp3");
    moneySound = LoadSound("../Audios/Money.mp3");*/

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
    exampleItem = LoadTexture("../src/sprites/Menus and boards/heartIcon.png");

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
    isDialogueV.resize(25);
    questV.resize(25);
    isItemV.resize(25);
    counterPressed.resize(25);
    chadTextV.resize(25);

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

    salami.width = 150;
    salami.height = 150;

    cheese.width = 150;
    cheese.height = 150;

    mushroom.width = 150;
    mushroom.height = 150;

    pizzaIngredientsV = {
        { flour, 1500, 500 },
        { salami, 1500, 1000 },
        { cheese, 2000, 500 },
        { mushroom, 2000, 1000 },
    },
    
    baker = LoadTexture("../src/sprites/inner country elements/bulgaria/baker.png");
    pizza = LoadTexture("../src/sprites/inner country elements/bulgaria/pizza.png");

    pntng.painting = LoadTexture("../src/sprites/inner country elements/spain/painting.png");

    paintingV = {
        {pntng.painting, 1200, 800},
        {pntng.painting, 1500, 1000},
        {pntng.painting, 1600, 1000},
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
        {fox, 1000, 300},
        {chicken, 1000, 500},
        {seed, 1000, 700},
    };

    isLogicItemPicked.resize(3);
    otherLogicItemBlockPick.resize(3);

    itemPutDown = {
        {1500, 300},
        {1500, 500},
        {1500, 700},
    };
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
        //plane.planeT = touranLeft;
        vehicleSound = touranSound;
    }

    //backstory()

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
    
    if (isBulgariaEnd)
    {
        if (!hideCountries)
        {
            DrawTexture(target, circles[4].x - 20, circles[4].y - 5, WHITE);

            if (CheckCollisionPointCircle(mousePoint, circles[4], 30))
            {
                hoverEffects(countriesV[4].country, countriesV[4].x, countriesV[4].y, circles[4].x - 20, circles[4].y - 5);
            }
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
        //countries[coutnryNumber] = 1;
        for (int i = 0; i < 6; i++)
        {
            if (i != coutnryNumber)
                countries[i] = 0;
            else
            {
                countries[coutnryNumber] = 1;
            }
        }
    }

    //counterDotsBubble++;

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
                if (countries[i])
                {
                    switch (i)
                    {

                    case 0:
                        spainLevel();
                        npc.DrawNPCAnimation(player.XBg, player.YBg, i);
                        npc.DrawDotsAnimation(player.XBg, player.YBg, i);
                        break;

                    case 1:
                        franceLevel();
                        npc.DrawNPCAnimation(player.XBg, player.YBg, i);
                        npc.DrawDotsAnimation(player.XBg, player.YBg, i);
                        break;

                    case 2:
                        italyLevel();
                        npc.DrawNPCAnimation(player.XBg, player.YBg, i);
                        npc.DrawDotsAnimation(player.XBg, player.YBg, i);
                        break;

                    case 3:
                        germanyLevel();
                        npc.DrawNPCAnimation(player.XBg, player.YBg, i);
                        npc.DrawDotsAnimation(player.XBg, player.YBg, i);
                        break;

                    case 4:
                        bulgariaLevel();
                        assassin.CheckMiniGame(player.MoveBg, player.move);
                        assassin.Draw(player.XBg, player.YBg, player.MoveBg);
                        assassin.Update(player.playerCords, player.XBg, player.YBg, player.move, player.MoveBg);
                            
                        break;

                    case 5:
                        romaniaLevel();
                        npc.DrawNPCAnimation(player.XBg, player.YBg, i);
                        npc.DrawDotsAnimation(player.XBg, player.YBg, i);
                        break;

                    default:
                        break;
                    }
                }
               
                if (IsKeyDown(KEY_TAB))
                {
                    showInventory();
                }

                DrawCircleGradient(backCircle.x, backCircle.y, 30, GREEN, SKYBLUE);
            }
            else {
                DrawTexture(countriesHoveredV[i].country, countriesHoveredV[i].x, countriesHoveredV[i].y, WHITE);
                isTransportMenuOn = false;
            }

            if (isClicked() && CheckCollisionPointCircle(mousePoint, backCircle, 30))
            {
                enableClick = true;
                //countries[i] = 0;
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
}

void Game::dialogues(string firstName, string secondName, string characterDialogues[], int dialogueLength, int chadCordsX, int chadCordsY, int index, vector<isDialogue>& isDialogue, vector<int>& counterPressed, bool ePressed)
{
    if(findDistance(player, chadCordsX, chadCordsY))
    {
        if ((IsKeyDown(KEY_E) || ePressed) && !isDialogue.at(index).isDialogueEntered)
        {
            isDialogue.at(index).isDialogueStarted = true;
            isDialogue.at(index).isDialogueContinued = false;
            isDialogue.at(index).isDialogueEntered = true;
        }

        if (isDialogue.at(index).isDialogueStarted && !isDialogue.at(index).isDialogueContinued)
        {
            DrawTexture(dialogueBox, 0, 715, WHITE);

            DrawTextEx(headerFont, firstName.c_str(), { 50, 750 }, 24, 5, textColor);

            DrawText(characterDialogues[counterPressed.at(index)].c_str(), 40, 900, 24, textColor);

            DrawTexture(finishedDialogueArrow, 1290, 965, WHITE);   
        }

        if (IsKeyPressed(KEY_ENTER) && isDialogue.at(index).isDialogueEntered)
        {
            counterPressed.at(index)++;

            isDialogue.at(index).isDialogueStarted = false;
            isDialogue.at(index).isDialogueContinued = true;
        }
        
        if (isDialogue.at(index).isDialogueContinued && !isDialogue.at(index).isDialogueStarted && counterPressed.at(index) <= dialogueLength)
        {
            DrawTexture(dialogueBox, 0, 715, WHITE);

            if (counterPressed.at(index) % 2 == 0 && counterPressed.at(index) > 0)
            {
                DrawTextEx(headerFont, secondName.c_str(), { 50, 750 }, 24, 5, textColor);
            }
            else {
                DrawTextEx(headerFont, firstName.c_str(), { 50, 750 }, 24, 5, textColor);
            }
       
            DrawText(characterDialogues[counterPressed.at(index)].c_str(), 40, 900, 24, textColor);

            DrawTexture(finishedDialogueArrow, 1290, 965, WHITE);          
        }
    }
}

void Game::showInventory()
{
    DrawTexture(inventory, 505, 223, WHITE);

    if (isItemV.at(1).isItemPicked)
        DrawTexture(exampleItem, 1000, 500, WHITE);

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

        isUserQuitting(isQuitting, enableClick, mousePoint, confirmationT, darkerWindow, isTransportMenuOn);

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
    dialogues("Vankata Smetacha", "Mitio guluba", getBeerQuestDialogue, 2, 1000, 1000, 9, isDialogueV, counterPressed, false);

    if (counterPressed.at(9) >= 3 && counterPressed.at(9) <= 4)
    {
        isBeerDialogueFinished[0] = true;

        counterPressed.at(9) = 5;
    }

    if (isBeerDialogueFinished[0])
    {
        if (!questV.at(9).openQuest)
            quest(chadTextV, 9);

        if(questV.at(9).acceptQuest)
            dialogues("Vankata Smetacha", "Gubarq", buyBeerDialogue, 2, 2000, 1000, 10, isDialogueV, counterPressed, false);
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

        dialogues("Vankata Smetacha", "Gubarq", bringBeerDialogue, 2, 1500, 1000, 11, isDialogueV, counterPressed, false);
    }

    if (counterPressed.at(11) >= 3 && counterPressed.at(11) <= 4)
    {
        allMoney += 700;
        beerShowInventory = false;
        isBeerDialogueFinished[1] = false;

        counterPressed.at(11) = 5;
    }
}

void Game::franceLevel()
{
    //race.DrawHorseAnimation();

    dialogues("Vankata Smetacha", "Mitio guluba", firstDialogue, 3, 1000, 1000, 1, isDialogueV, counterPressed, false);

    dialogues("Mitio pishtova", "Gosho rendeto", secondDialogue, 3, 2000, 1000, 0, isDialogueV, counterPressed, false);

    if (!isItemV.at(1).isItemPicked && !isItemV.at(1).isDelivered && counterPressed.at(1) >= 4 && counterPressed.at(1) <= 5)
    {
        if (!questV.at(1).openQuest)
            quest(chadTextV, 1);

        if(questV.at(1).acceptQuest)
            DrawTexture(exampleItem, 1000 + player.XBg, 500 + player.YBg, WHITE);
    }

    itemPicked(1000, 500, isItemV.at(1).isItemPicked);

    if (counterPressed.at(1) >= 4 && counterPressed.at(1) <= 5 && findDistance(player, 1000, 1000) && IsKeyPressed(KEY_Q))
    {
        allMoney += 1000;
        counterPressed.at(1) = 6;
    }
}

void Game::italyLevel()
{
    if (IsKeyPressed(KEY_Q) && findDistance(player, 2000, 500))
    {
        isGripperPicked = true;
        isGripperInventory = false;
    }
        
    if (isGripperPicked)
    {
        dialogues("Vankata Smetacha", "Vankata Smetacha", gripperFoundDialogue, 1, 2000, 500, 2, isDialogueV, counterPressed, true);

        //fix na dialozite tuk
        dialogues("Vankata Smetacha", "Gabarq", gripperReturnedDialogue, 2, 1000, 1000, 3, isDialogueV, counterPressed, false);

        if (counterPressed.at(3) >= 3 && counterPressed.at(3) <= 4)
        {
            allMoney += 500;

            counterPressed.at(3) = 5;

            isGripperInventory = true;
        }
    }
    else 
        DrawTexture(gripper, 2000 + player.XBg, 500 + player.YBg, WHITE);

    //logic game

    for (int i = 0; i < 3; i++)
    {
        if (!isLogicItemPicked.at(i))     
            DrawTexture(logicGameItemsV.at(i).texture, logicGameItemsV.at(i).posX + player.XBg, logicGameItemsV.at(i).posY + player.YBg, WHITE);     
        else 
            DrawTexture(logicGameItemsV.at(i).texture, itemPutDown.at(i).x + player.XBg, itemPutDown.at(i).y + player.YBg, WHITE);     
    }

    for (int i = 0; i < 3; i++)
    {
        if (findDistance(player, logicGameItemsV.at(i).posX, logicGameItemsV.at(i).posY) && IsKeyPressed(KEY_Q))
        {
            otherLogicItemBlockPick.at(i) = true;

            if(otherLogicItemBlockPick.at(i))
                isLogicItemPicked.at(i) = true;
        }     
    }

    for (int i = 0; i < 3; i++) 
    {
        if (findDistance(player, itemPutDown.at(i).x, itemPutDown.at(i).y) && IsKeyPressed(KEY_Q))
        {
            isLogicItemPicked.at(i) = false;
        }
    }

    if (otherLogicItemBlockPick.at(0))
    {
        otherLogicItemBlockPick.at(1) = false;
        otherLogicItemBlockPick.at(2) = false;
    }
    else if (otherLogicItemBlockPick.at(1))
    {
        otherLogicItemBlockPick.at(0) = false;
        otherLogicItemBlockPick.at(2) = false;
    }
    else if (otherLogicItemBlockPick.at(2))
    {
        otherLogicItemBlockPick.at(0) = false;
        otherLogicItemBlockPick.at(1) = false;
    }
}

void Game::germanyLevel()
{
    /*
    dialogues("Vankata Smetacha", "Mitio guluba", startQuestDialogue, 1, 1000, 1000, 7, isDialogueV, counterPressed, false);

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
        dialogues("Vankata Smetacha", "Mitio guluba", finishAddictDialogue, 1, 1000, 1000, 8, isDialogueV, counterPressed, false);

        if (counterPressed.at(8) >= 2 && counterPressed.at(8) <= 3)
        {
            allMoney += 1000;

            counterPressed.at(8) = 4;
        }
    }*/

    dialogues("Vankata Smetacha", "Mitio guluba", paintingCollectDialogue, 1, 1000, 1000, 17, isDialogueV, counterPressed, false);

    if (counterPressed.at(17) >= 2 && counterPressed.at(17) <= 3)
    {
        showPaintingInventory = true;

        counterPressed.at(17) = 4;
    }

    if (showPaintingInventory)
    {
        if(!questV.at(17).openQuest)
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
        dialogues("Vankata Smetacha", "Mitio guluba", paintingCollectDialogueFinish, 1, 1000, 1000, 18, isDialogueV, counterPressed, false);

        if (counterPressed.at(18) >= 2 && counterPressed.at(18) <= 3)
        {
            allMoney += 900;

            counterPressed.at(18) = 4;
        }
    }

    //minigame
    dialogues("Vankata Smetacha", "Scientist", getPoisonDialogue, 1, 2000, 1000, 19, isDialogueV, counterPressed, false);

    if (counterPressed.at(19) >= 2 && counterPressed.at(19) <= 3)
    {
        showPoisonInventory = true; 

        finishGetPoisonDialogue = true;

        counterPressed.at(19) = 4;
    }

    if(!swapBeers)
        DrawTexture(beer, 1200 + player.XBg, 1000 + player.YBg, WHITE);
    else
        DrawTexture(poisonedBeer, 1200 + player.XBg, 1000 + player.YBg, WHITE);

    if (finishGetPoisonDialogue)
    {
        if (IsKeyPressed(KEY_Q) && findDistance(player, 1200, 1000))
        {
            swapBeers = true;
            showPoisonInventory = false;
        }
    }

    if (swapBeers)
    {
        dialogues("Vankata Smetacha", "Scientist", finishMinigameDialogue, 1, 2000, 1000, 20, isDialogueV, counterPressed, false);
    }

    if (counterPressed.at(20) >= 2 && counterPressed.at(20) <= 3)
    {
        //nesh sh staa
        counterPressed.at(20) = 4;
    }
}

void Game::bulgariaLevel()
{
    dialogues("Vankata Smetacha", "Mitio guluba", startPizzaCollectDialogue, 1, 1000, 1000, 14, isDialogueV, counterPressed, false);

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
                if(questV.at(14).acceptQuest)
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
        dialogues("Vankata Smetacha", "Mitio guluba", bakerCombineDialogue, 2, 1500, 1000, 15, isDialogueV, counterPressed, false);

        if (counterPressed.at(15) >= 3 && counterPressed.at(15) <= 4)
        {
            allMoney -= 400;

            counterPressed.at(15) = 5;

            finishBakerDialogue = true;
        }
    }

    if (finishBakerDialogue)
    {
        dialogues("Vankata Smetacha", "Mitio guluba", finishPizzaCollectDialogue, 1, 1000, 1000, 16, isDialogueV, counterPressed, false);

        if (counterPressed.at(16) >= 2 && counterPressed.at(16) <= 3)
        {
            allMoney += 1000;

            counterPressed.at(16) = 4;

            finishBakerDialogue = false;
        }     
    }
}

void Game::romaniaLevel()
{
    dialogues("Vankata Smetacha", "Mitio guluba", getKeyDialogue, 2, 1000, 1000, 4, isDialogueV, counterPressed, false);

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
        dialogues("Vankata Smetacha", "Vankata Smetacha", findStoneDialogue, 2, 1500, 500, 5, isDialogueV, counterPressed, true);

        if (itemRequire[0])
        {
            dialogues("Vankata Smetacha", "Jabata", itemCombinationDealDialogue, 3, 1500, 1000, 6, isDialogueV, counterPressed, false);

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
        dialogues("Vankata Smetacha", "Jabata", finishKeyQuestDialogue, 1, 1000, 1000, 12, isDialogueV, counterPressed, false);

        if (counterPressed.at(12) >= 2 && counterPressed.at(12) <= 3)
        {
            itemRequire[2] = false;

            allMoney += 800;

            counterPressed.at(12) = 4;
        }
    }

    //myrder mystery

    dialogues("Vankata Smetacha", "Policeman", startMurderMysteryDialogue, 2, 2000, 1000, 21, isDialogueV, counterPressed, false);

    if (counterPressed.at(21) >= 3 && counterPressed.at(21) <= 4)
    {
        showLoop = true;
        isMurderMysteryDialoguesStarted[0] = true;

        counterPressed.at(21) = 5;
    }

    if (isMurderMysteryDialoguesStarted[0])
    {
        dialogues("Vankata Smetacha", "Vankata Smetacha", atTheCrimeSceneDialogue, 2, 2000, 500, 22, isDialogueV, counterPressed, true);

        if (counterPressed.at(22) >= 3 && counterPressed.at(22) <= 4)
        {
            isMurderMysteryDialoguesStarted[0] = false;
            isMurderMysteryDialoguesStarted[1] = true;

            counterPressed.at(22) = 5;
        }
    }

    if (isMurderMysteryDialoguesStarted[1])
    {
        dialogues("Vankata Smetacha", "Policeman", finishMurderMysteryDialogue, 3, 2000, 1000, 23, isDialogueV, counterPressed, false);

        if (counterPressed.at(23) >= 4 && counterPressed.at(23) <= 5)
        {
            isMurderMysteryDialoguesStarted[1] = false;
            isMurderMysteryDialoguesStarted[2] = true;

            counterPressed.at(23) = 6;
        }
    }

    if (isMurderMysteryDialoguesStarted[2])
    {
        //tuk sh ima tabloto za quessvane

        if (quessSuspect == correctSuspect)
        {
            allMoney += 500;
            isMurderMysteryDialoguesStarted[2] = false;
        }

        showLoop = false;
    }
}