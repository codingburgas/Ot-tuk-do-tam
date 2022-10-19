#include "Precompile.hpp";
#include "Engine.hpp"

struct QA {
    string* questions;
    string* answers;
}questionnaire;

namespace variables {
    int randomizationForA[10];
    int randomizationForQ[10][4];

    int shuffleQA = 0, randomA = 0, randomQ = 0;
};


using namespace variables;
void setupVars()
{

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

    InitWindow(1800, 1000, "Quiz");
    SetTargetFPS(60);

    for (int i = 0; i < 10; i++)
    {
        int randomForA = rand() % 10;
        randomizationForA[i] = randomForA;

        int randomForQ = rand() % 4;
        //for (int j = 0; j < 4; j++)
            //vij twa shot nesh ne moga da gi vkaram i dvete promenlivi
            //randomizationForQ[i][j] = make_pair(randomForA, randomForQ);
    }
}

void deleteVars()
{
    delete[] questionnaire.questions;
    delete[] questionnaire.answers;
}

int main()
{
    questionnaire.questions[10];
    questionnaire.answers[10 * 4];

    srand(time(0));

    setupVars();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //shuffle the QA and randomise the answers position

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

        EndDrawing();
    }

    deleteVars();

    CloseWindow();
}