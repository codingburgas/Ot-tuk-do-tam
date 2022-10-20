#include "Precompile.hpp";
#include "Engine.hpp"
#include "Backstory.hpp"

struct QA {
    string* questions;
    string* answers;
}questionnaire;

namespace variables {
    int randomizationForA[10];
    int randomizationForQ[10][4];

    int shuffleQA = 0, randomA = 0, randomQ = 0;

    int miliseconds;
    string backstoryText;

    int* milisecondsPtr;
    string* backstoryTextPtr;

};


using namespace variables;

void setupVars();

class Game
{
public:
    Game(){
        InitWindow(2000, 1025, "Ot tuk do tam");
        SetTargetFPS(60);
    }
    void loop()
    {
        Texture2D map = LoadTexture("../src/sprites/overworld/map.png");
        Texture2D bull = LoadTexture("../src/sprites/overworld/bull.png");
        Texture2D bar = LoadTexture("../src/sprites/overworld/bar.png");
        Texture2D cheese = LoadTexture("../src/sprites/overworld/cheddar.png");
        Texture2D help = LoadTexture("../src/sprites/overworld/help.png");

        map.width = 2000;
        map.height = 1025;

        bull.width = 2000;
        bull.height = 1025;

        bar.width = 2000;
        bar.height = 1025;

        cheese.width = 2000;
        cheese.height = 1025;

        help.width = 2000;
        help.height = 1025;

        Vector2 MousePoint;

        Vector2 circles[4];

        bool countries[4] = { 0,0,0,0 };

        while (!WindowShouldClose())
        {
            BeginDrawing();

            


            MousePoint = GetMousePosition();

            //shuffle the QA and randomise the answers position
            /*
            for (int i = 0; i < 10; i++)
            {
                randomA = randomizationForA[i];

                const char* questionText = questionnaire.questions[randomA].c_str();

                const char* answerText[1][4];
                for (int j = 0; j < 4; j++)
                    answerText[0][j] = questionnaire.answers[randomA * randomQ].c_str();


                DrawText(questionText, 1, i * 100, 30, BLUE);

                //DrawText(questionText, 1, 1, 50, BLUE);

                for (int j = 0; j < 4; j++)
                {
                    //draw the 4 answers
                    DrawText(answerText[0][j], i * 100, 400, 50, GREEN);
                }
            }
            */
            DrawTexture(map,0,0,WHITE);
            circles[0].x = 320;
            circles[0].y = 800;
            DrawCircleGradient(circles[0].x, circles[0].y, 30, GREEN, SKYBLUE);

            circles[1].x = 550;
            circles[1].y = 650;
            DrawCircleGradient(circles[1].x, circles[1].y, 30, PURPLE, BLUE);

            circles[2].x = 380;
            circles[2].y = 80;
            DrawCircleGradient(circles[2].x, circles[2].y, 30, LIME, DARKBLUE);

            circles[3].x = 860;
            circles[3].y = 580;
            DrawCircleGradient(circles[3].x, circles[3].y, 30, RED, PINK);

            if (CheckCollisionPointCircle(MousePoint, circles[0], 30))
            {
                DrawText("Spain",125,725,60,RED);
            }
            if (CheckCollisionPointCircle(MousePoint, circles[1], 30))
            {
                DrawText("France", 425, 650, 60, DARKPURPLE);
            }
            if (CheckCollisionPointCircle(MousePoint, circles[2], 30))
            {
                DrawText("Iceland", 200, 150, 60, BLUE);
            }
            if (CheckCollisionPointCircle(MousePoint, circles[3], 30))
            {
                DrawText("Germany", 650, 474, 60, YELLOW);
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
                DrawTexture(help , 0, 0, WHITE);
            }
            
            EndDrawing();
        }
    };
    ~Game(){
        delete[] questionnaire.questions;
        delete[] questionnaire.answers;
        CloseWindow();
    }

};

void setupVars()
{
    
    /*

    string questionsar[10]
    {
        {"a"},
        {"b"},
        {"c"},
        {"d"},
        {"d"},
        {"f"},
        {"g"},
        {"h"},
        {"i"},
        {"j"},
    };

    //space-a e check za vernite otgovori twa e nai - lesniq variant za check det se sehtam
    string answersar[10][5]
    {
        {"00", "01", "02", "03"},
        {"10", "11", "12", "13"},
        {"20", "21", "22", "23"},
        {"30", "31", "32", "33"},
        {"40", "41", "42", "43"},
        {"50", "51", "52", "53"},
        {"60", "61", "62", "63"},
        {"70", "71", "72", "73"},
        {"80", "81", "82", "83"},
        {"90", "91", "92", "93"},
        
        
        
    };

    questionnaire.questions = new string[10];
    questionnaire.answers = new string[10 * 5];
    for (int i = 0; i < 10; i++)
    {
        *(questionnaire.questions + i) = questionsar[i];
    }for (int i = 0; i < 10; i++)
    {
        for (int j = 0; i < 5; i++)
        {
            *(questionnaire.answers + i * 5 + j) = answersar[i][j];
        }
    }

    
    for (int i = 0; i < 10; i++)
    {
        int randomForA = rand() % 10;
        randomizationForA[i] = randomForA;

        int randomForQ = rand() % 4;
        //for (int j = 0; j < 4; j++)
            //randomizationForQ[i][j] = make_pair(randomForA, randomForQ);
    }

    //backstory variables
    miliseconds = 100;
    backstoryText = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap";

    milisecondsPtr = &miliseconds;
    backstoryTextPtr = &backstoryText;
    */
}



int main()
{
    questionnaire.questions[10];
    questionnaire.answers[10 * 4];

    srand(time(0));

    setupVars();

    //backstory(*milisecondsPtr, *backstoryTextPtr);
    //delete milisecondsPtr;
    //delete backstoryTextPtr;

    Game* game = new Game();
    game->loop();
}