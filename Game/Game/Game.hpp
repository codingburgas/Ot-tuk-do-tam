#pragma once
#include "Precompile.hpp"
#include "Engine.hpp"
#include "Backstory.hpp"
#include "Player.hpp"
#include "NPC.hpp"
#include "HorseRacing.hpp"
void setWidthAndHeight(Texture2D& variable);

void gameStartup();

class Game : public Player
{
public:
    Player player;
    Racing race;
    NPC npc;
    Texture2D map;

    int fps = 60;

    //fonts
    Font headerFont, textFont;

    Texture2D backstoryImg;

    string backstoryText;

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

    //ne se pipa ne znaem kakvo pravi :( )    
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

    bool helpIsClicked;

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

    //money mechanic 
    Texture2D moneyBackground;
    int allMoney, allMoneyCopy, moneySpent;
    string printMoney, allMoneyCopyPrint, moneySpentPrint;
    Sound moneySound;

    //points mechanic
    int points;

    //dialogue mechanic
    Texture2D dialogueBox, finishedDialogueArrow;

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

    string firstDialogue[5] = { "Ko staa manqk", "Da", "Tocho", "Tos puk", "" };
    string secondDialogue[5] = { "Ko staa manqk", "Zemi twa i razslevai", "Dobre", "Sh ti dam pari", "" };
    bool isTextEffectEnded;

    //quest board 
    Texture2D questBoardT;
    Texture2D acceptButton, cancelButton;
    Texture2D acceptButtonHover, cancelButtonHover;
    bool openQuest;
    vector<bool> acceptQuest;

    string questDisplay[10];
    
    //picup system
    Texture2D inventory;

    struct isItem
    {
        bool isItemPicked;
        bool isDelivered;
    };

    vector<isItem> isItemV;
    
    Texture2D exampleItem;

    vector<Texture2D> items;

    //quest texts
    Color textColor;

    struct chadText {
        string title;
        string description;
        string reward;
    };

    vector<chadText> chadTextV = 
    { 
        {"", "", ""}, 
        {"Pickup the heard!", "Go to the heart and take it.", "Reward:           1000$"},
        {"Return the gripper!", "Find the man/woman who lost\nhis gripper and return it", "Reward:           500$"},
        {"", "", ""},
        {"Get the key and combine it!", "Find other itema and go combine it", "Reward:           750$"},
        {"", "", ""},
        {"", "", ""},
        {"Collect all the sausages!", "Collect all the tomatoes", "Reward:           1000$"},
        {"", "", ""},
        {"Buy Chad a beer!", "Buy Chad a beer", "Reward:           750$"},
        {"", "", ""},
        {"", "", ""},
        {"", "", ""},
        {"", "", ""},
        {"", "", ""},
        {"", "", ""},
        {"", "", ""},
    };

    vector<int> counterPressed;

    bool isBulgariaEnd;

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
    struct tomatoes {
       Texture2D tomato;
       int posX, posY;
    }tmts;

    vector<tomatoes> tomatoV;

    bool showTomatoInventory;
    bool showTomatoes[6];

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
public:

    Game();

    void backstory();
    void hoverEffects(Texture2D& country, float posx, float posy, float posxTarget, float posyTarget);
    void moveAirplane(const countryPosition& countryPosition);
    void transportMenuF();
    void mapEurope();
    void dialogues(string firstName, string secondName, string characterDialogues[], int dialogueLength, int chadCordsX, int chadCordsY, vector<chadText> text, int index, bool isQuest, vector<isDialogue>& isDialogue, vector<int>& counterPressed, bool ePressed);
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

    void update();

    ~Game();
};