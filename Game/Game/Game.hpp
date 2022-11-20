#pragma once
#include "Precompile.hpp"
#include "Engine.hpp"
#include "Backstory.hpp"
#include "Player.hpp"
#include "NPC.hpp"
#include "HorseRacing.hpp"
#include "Assassin.hpp"
#include "Bulls.hpp"

void setWidthAndHeight(Texture2D& variable);

void gameStartup();

class Game : public Player
{
protected:
    Player player;
    Racing race;
    NPC npc;
    Assassin assassin;
    Bulls bulls;
public:
    Texture2D map;
    bool EnterOnce;
    int fps = 60;

    Texture2D backButtonClean;
    Texture2D backButtonHover;

    Rectangle backButton;

    Texture2D chadFr, scientist, addict, tourguideGreen, tourguideYellow, policeman, rival;
    //fonts
    Font headerFont, textFont;

    Texture2D backstoryImg;

    string backstoryText;
    Texture2D chadBg;

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
    Texture2D romaniaHovered;

    //backgrounds
    Texture2D grBackground, itBackground, romBackground, frBackground, spBackground;

    Texture2D menuOptions;

    int money;
    Color moneyColor;

    bool enableClick;
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
    bool mainMenuDialogue;

    Texture2D audioIsOn;

    Texture2D isClickedCheck;
    bool isTransportMenuOn;

    //vehicle audios
    Sound touranSound, planeSound, trainSound;

    Sound vehicleSound;

    vector <countryPosition> countryPositions;

    int vehicleChoice;

    //map variables

    Rectangle choiceFromOptions[3];

    Texture2D target;
    Texture2D targetHover;

    Texture2D optionImage;
    Texture2D optionImageHovered;
    Texture2D optionImageClicked;

    int optionCounter;

    Rectangle afterClickedOptions;

    Vector2 mousePoint;

    Vector2 circles[6] = { 320, 800 };

    int countryFly;
    bool isFlying;

    Vector2 backCircle;

    bool countries[6];
    int coutnryNumber;

    bool changeCircles[6];
    bool banCountry[6];

    bool options;
    bool closeOptions;

    Sound mapMusic;

    bool unloadBack;

    int counterPlane;
    bool isFlipped;
    bool flyOneTime;

    bool audioIsClicked;
    int audioIsClickedCounter;

    bool planeToMove;
    int transportCheck;

    bool outsideCheck;
    int isCheckedOutside;

    bool playSound;

    //Exit confirmaiton table
    Color darkerWindow;
    bool isQuitting;
    Texture2D confirmationT;

    Texture2D yesButton, yesButtonHover, noButton, noButtonHover;

    vector<Texture2D> quitButtons;

    Rectangle Fader;

    Texture gameIsFinished;

    //money mechanic 
    Texture2D moneyBackground;
    int allMoney, allMoneyCopy, moneySpent;
    string printMoney, allMoneyCopyPrint, moneySpentPrint;
    Sound moneySound;

    //dialogue mechanic
    Texture2D dialogueBox, finishedDialogueArrow;

    Texture goldenTarget;

    struct isDialogue {
        bool isDialogueStarted;
        bool isDialogueContinued;
        bool isDialogueEntered;
    };
    
    vector<isDialogue> isDialogueV;

	Texture2D dotsBubbleOne, dotsBubbleTwo, dotsBubblThree, dotsBubbleFour;
	vector<Texture2D> dotsBubble;
	int counterDotsBubble;
	int changeDotsBubble;

    string barrelDialogue[5] = { "Hey bro can you find the barrel?", "Of course mate will you pay me?", "How much?", "Enough!", "" };
    string EiffelDialogue[5] = { "Hey  can i learn something for this!", "This is the most visited monument in the world! \n As France’s symbol in the world, and the showcase of Paris, today it welcomes almost 7 million visitors a year (around 75% of whom are foreigners), making it the most visited monument that you have to pay for in the world.", "Oh really?", "Yes!", "Okay thank you!!!" };
    string ArcDialogue[5] = { "Hey can you tell me something about this?", "Yes!", "The triumphal arch grew out of \n a tradition originating during the Roman Republic."};
    bool isTextEffectEnded;

    //quest board 
    Texture2D questBoardT;
    Texture2D acceptButton, cancelButton;
    Texture2D acceptButtonHover, cancelButtonHover;
    bool openQuest;

    struct quest {
        bool openQuest;
        bool acceptQuest;
    };

    vector<quest> questV;

    string questDisplay[10];
    
    //picup system
    Texture2D inventory;

    struct isItem
    {
        bool isItemPicked;
        bool isDelivered;
    };

    vector<isItem> isItemV;
    
    Texture2D barrel;
    Texture2D tomato;
    vector<Texture2D> items;

    //quest texts
    Color textColor;

    struct chadText {
        string title;
        string description;
        string reward;
    };

    vector<chadText> chadTextV;

    vector<int> counterPressed;

    bool isBulgariaEnd;

    Rectangle rectangleQuit;

    string pointText;
    int points;
    int allPoints;

    Texture2D horse;

    //wallet pickup
    Texture2D gripper;
    bool isGripperPicked;
    bool isGripperInventory = true;

    string gripperFoundDialogue[3] = { "It seems that someone lost his/her wallet", "Let's try to bring it back", ""};

    string gripperReturnedDialogue[4] = { "It seems you found my wallet", "Yes.", "Ok that's a little reward from me!", ""};

    //item combination
    Texture2D key, metalPieces, stone;
    bool itemRequire[5];
    bool isStonePicked;

    string getKeyDialogue[5] = { "Brato nati toq kluch naprai kamuk", "Huu imash go", "Basi picha si",   "" },
        findStoneDialogue[5] = { "leleee basi qkiq kamuk", "Sigurno she mi trqq", "Dai da go zema", "" },
        itemCombinationDealDialogue[5] = { "Ae pich moe li da napraish item", "Nqqsh problem samo dai pari", "Huu nati", "Qko e da praim biznes ai chao", "" },
        finishKeyQuestDialogue[3] = { "Eto subrah gi sega dai kinti", "Jiv i zdrav eto", ""};

    //adict quest
    struct sausages {
       Texture2D sausage;
       int posX, posY;
    }ssgs;

    vector<sausages> sausagesV;

    bool showSausagesInventory;
    bool showSausages[6];

    string startQuestDialogue[2] = { "Picha suberi 5 domata", "Huu" },
           finishAddictDialogue[2] = { "Subrah gi", "Huu nati tiq pari" };

    //buy beer quest
    string getBeerQuestDialogue[4] = { "Ae pich sh mi kupish li bira", "Da e lud", "Huu shti platq"},
        buyBeerDialogue[4] = { "Iskam da kupq bira", "Struva 250$", "Dobre vzimam q" },
        bringBeerDialogue[4] = {"Eto ti birata", "Blagodarq lud. Na ti parite", "Blagodarq, priqten den!"};

    bool isBeerDialogueFinished[2];

    Texture2D beer;
    bool beerShowInventory;

    //pizza quest

    Texture2D flour, salami, cheese, mushroom, pizza, baker;

    struct pizzaIngredients {
        Texture2D texture;
        int posX, posY;
    };

    vector<pizzaIngredients> pizzaIngredientsV;

    string startPizzaCollectDialogue[2] = { "Ko staa manqk suberi sustavkite", "Dobre" },
        bakerCombineDialogue[3] = { "Kombinirai twa", "Dobre, samo che iskam 400$", "Dobre eto" },
        finishPizzaCollectDialogue[2] = { "Ei ti picata", "Blagodarq nati parite" };

    bool showIngredients;
    bool drawIngredients[4];
    bool finishBakerDialogue;

    //lost painting quest

    struct paintings {
        Texture2D painting;
        int posX, posY;
    }pntng;

    vector<paintings> paintingV;

    bool showPaintingInventory;
    bool showPaintings[3];

    string paintingCollectDialogue[2] = { "Picha zemi tiq kartini", "Huu praim go" },
           paintingCollectDialogueFinish[2] = { "Na ti kartinite", "Blagodarq!" };

    bool hideCountries;

    //germany mini game
    Texture2D poisonedBeer, poison;

    string getPoisonDialogue[2] = { "Zemi otrovata i q sloji v na Rival pitieto", "Dobre" },
           finishMinigameDialogue[2] = {"Uspqh da otrovq na Rival birata", "Super bravo na teb"};

    bool showPoisonInventory, finishGetPoisonDialogue;
    bool swapBeers;


    bool getTomato;
    //murder mystery
    Texture2D loop;
    bool showLoop;

    string startMurderMysteryDialogue[4] = { "Iskash li da razsledvash", "Da", "Dobre zemi tazi lupa i razgledvai" },
           atTheCrimeSceneDialogue[3] = {"Qvno tova e mestoprestuplenieto", "Chakai kakwo e tova tam, parche plat", "Sigurno e na ubieca"},
           finishMurderMysteryDialogue[4] = {"Uspqh da otkriq parche plat", "Dobre i smqtash che e na jertvata?", "Da", "Dobre spored teb koi e ubieca"};

    bool isMurderMysteryDialoguesStarted[3];

    int quessSuspect;
    int correctSuspect = 3;
    Texture2D suspectBetMenu;

    //logic game
    Texture2D fox, chicken, seed;

    struct logicGameItems {
        Texture2D texture;
        int posX, posY;
    };

    vector<logicGameItems> logicGameItemsV;
    vector<bool> isLogicItemPicked;
    
    vector<Vector2> itemPutDown;

    Texture2D italyBackground, boat;

    bool changeBoatPos;
    int changeBoatPosCounter;

    Texture2D itemInBoat;
    vector<bool> itemGet;

    bool lockBoat;
    vector<bool> itemOnOtherSide;
    vector<int> itemOnOtherSideCounter;

    Texture2D emptyTexture;
    bool isLogicGameFinished;

    //main menu
    Texture2D menu, newGame, newGameHover, quit, quitHover;

    Texture2D helpMenu;
    int counterHelpMenuClicked;

    bool isGameStarted;
    
    //horse race
    Texture2D okButtonHorseRace, okButtonHorseRaceHover, horseOptionMenu;
    int ePressedCounter;

    Texture2D fillCheck;
    int horseBet;

    Texture2D romania;

    //landmarks

    //france
    Texture2D eiffelTower, arcDeTriomphe;
    //italy
    Texture2D colliseum, pizzaTower;
    //germany
    Texture2D kiolnWall, germanyKingdom;
    //spain
    Texture2D spainKingdom, spainMonument;
    //romania
    Texture2D draculaCastle, parlament;

    //noodle quest
    Texture2D noodle1, noodle2, noodle3, noodle4, noodle5;

    struct noodles {
        Texture2D texture;
        int posX, posY;
    };

    vector<noodles> noodlesV;
    int pickNoodleCounter;

    Texture2D cheeseNoodles;

    string startNoodleQuestDialogue[3] = { "suberi nudalite sireneto i mi gi donesi za da napravq makaroni", "Dobre imash go", "plashtam dvoino" },
            finishNoodleQuestDialogue[3] = { "Subra li gi", "da", "huu na ti pari" };

    bool showNoodleInventory;
    bool showNoodles[6];

    string menuDialogue[2] = { "Hello here you can visit different countries and learn new stuff and having fun \n at the same time with playing minigames and complete quests", "Okay I can't wait let's go!" };
    bool newGameClicked;
public:

    Game();

    void backstory();
    void hoverEffects(Texture2D& country, float posx, float posy, float posxTarget, float posyTarget);
    void moveAirplane(const countryPosition& countryPosition);
    void transportMenuF();
    void mapEurope();
    void dialogues(string firstName, string secondName, string characterDialogues[], int dialogueLength, int chadCordsX, int chadCordsY, int index, vector<isDialogue>& isDialogue, vector<int>& counterPressed, bool ePressed);
    void quest(vector<chadText> text, int index);
    void itemPicked(int itemX, int itemY, bool& itemPicked);
    void returnItem(int reward, int posX, int posY, int index, vector<isItem> isItem);
    void showInventory();
    void optionsMenu();
    
    //contry levels
    void spainLevel();
    void franceLevel();
    void italyLevel();
    void germanyLevel();
    void bulgariaLevel();
    void romaniaLevel();

    void mainMenu();

    void update();

    ~Game();
};