#pragma once
#include "Precompile.hpp"
#include "Engine.hpp"
#include "Backstory.hpp"
#include "Player.hpp"

void setWidthAndHeight(Texture2D& variable);

void gameStartup();

class Game
{
private:
    Player player;

    Texture2D map;

    //window width and height
    int width = 1920;
    int height = 1080;

    //fonts
    Font headerFont, textFont;

    Texture2D backstoryImg;

    string backstoryText = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. \nLorem Ipsum has been the industry's standard dummy text ever since the 1500s,\nwhen an unknown printer took a\ngalley of type and scrambled it to make a type specimen book.";

    //hover effect variables

    struct country {
        Texture2D country;
        float x, y;
    };

    vector<country> countriesV;
    vector<country> countriesHoveredV;

    Texture2D bulgaria, bulgariaHovered;
    Texture2D france, franceHovered;
    Texture2D germany, germanyHovered;
    Texture2D italy, italyHovered;
    Texture2D spain, spainHovered;
    Texture2D romania, romaniaHovered;

    Texture2D menuOptions;

    int money = 2000;

    bool enableClick = true;
    //vehicles
    //plane
    Texture2D planeLeft, planeRight;
    Vector2 planePoint;

    struct plane {
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

    Texture2D audioIsOn;

    Texture2D isClickedCheck;
    bool isTransportMenuOn = false;

    //vehicle audios
    Sound touranSound, planeSound, trainSound;

    Sound vehicleSound;

    vector <countryPosition> countryPositions;

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

    Vector2 circles[6] = { 320, 800 };

    int countryFly;
    bool isFlying;

    Vector2 backCircle;

    bool countries[6] = { 0, 0, 0, 0, 0 };
    int coutnryNumber;

    bool changeCircles[6] = { 0, 0, 0, 0, 0 };
    bool banCountry[6] = { 0, 0, 0, 0, 0 };

    bool options = 0;
    bool closeOptions = 0;

    Sound mapMusic;

    bool unloadBack = false;

    int counterPlane = 0;
    bool isFlipped = false;
    bool flyOneTime = true;

    bool helpIsClicked = false;

    bool audioIsClicked = true;
    int audioIsClickedCounter;

    bool planeToMove = false;
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
    Texture2D moneyBackground;
    int allMoney = 2000, allMoneyCopy, moneySpent;
    string printMoney, allMoneyCopyPrint, moneySpentPrint;
    Sound moneySound;

    //points mechanic
    int points;

    //dialogue mechanic
    Texture2D chadFr, chadFrTwo;
    
    Texture2D mainCharacterDialogue, chadDialogue;
    bool isDialogueTurn;
    int isDialogueStarted = 0;
    Color dialogueColor = {255, 255, 255 ,255};

	Texture2D dotsBubbleOne, dotsBubbleTwo, dotsBubblThree, dotsBubbleFour;
	vector<Texture2D> dotsBubble;
	int counterDotsBubble = 0;
	int changeDotsBubble = 0;

    string firstDialogue[3] = {"Ko staa manqk", "Da", "Tocho"};
    int firstDialogueCounter = 0;

    int counterPressed;

public:

    Game();

    void backstory();
    void hoverEffects(Texture2D& country, float posx, float posy, float posxTarget, float posyTarget);
    void moveAirplane(const countryPosition& countryPosition);
    void transportMenuF();
    void mapEurope();
    void dialogues(int dotsBubbleX, int dotsBubbleY, Texture2D& firstDialogue, Texture2D& secondDialogue, string characterDialogues[], int& dialogueCounter, int dialogueLength);
    void optionsMenu();
    void update();

    ~Game();
};
