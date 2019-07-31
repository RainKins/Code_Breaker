#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <windows.h>
using namespace std;

void PrintIntro() {
    //Game Intro Instructions
    cout << "\n"
            "     ,gggg,                              ,ggggggggggg,                                                                 \n"
            "   ,88\"\"\"Y8b,                   8I      dP\"\"\"88\"\"\"\"\"\"Y8,                                 ,dPYb,                        \n"
            "  d8\"     `Y8                   8I      Yb,  88      `8b                                 IP'`Yb                        \n"
            " d8'   8b  d8                   8I       `\"  88      ,8P                                 I8  8I                        \n"
            ",8I    \"Y88P'                   8I           88aaaad8P\"                                  I8  8bgg,                     \n"
            "I8'            ,ggggg,    ,gggg,8I   ,ggg,   88\"\"\"\"Y8ba   ,gggggg,   ,ggg,     ,gggg,gg  I8 dP\" \"8   ,ggg,    ,gggggg, \n"
            "d8            dP\"  \"Y8gggdP\"  \"Y8I  i8\" \"8i  88      `8b  dP\"\"\"\"8I  i8\" \"8i   dP\"  \"Y8I  I8d8bggP\"  i8\" \"8i   dP\"\"\"\"8I \n"
            "Y8,          i8'    ,8I i8'    ,8I  I8, ,8I  88      ,8P ,8'    8I  I8, ,8I  i8'    ,8I  I8P' \"Yb,  I8, ,8I  ,8'    8I \n"
            "`Yba,,_____,,d8,   ,d8',d8,   ,d8b, `YbadP'  88_____,d8',dP     Y8, `YbadP' ,d8,   ,d8b,,d8    `Yb, `YbadP' ,dP     Y8,\n"
            "  `\"Y8888888P\"Y8888P\"  P\"Y8888P\"`Y8888P\"Y88888888888P\"  8P      `Y8888P\"Y888P\"Y8888P\"`Y888P      Y8888P\"Y8888P      `Y8\n\n";
    cout << "Greetings, Agent Duchess. Your mission is to data mine a government black site.\n";
    cout << "Your current objective is to enter the correct combination to gain access to their mainframe...\n";

}

void PlayGame()
{
    // 3 number code
    int AlphaCode = rand() % 9 + 1;
    int BravoCode = rand() % 9 + 1;
    int CharlieCode = rand() % 9 + 1;

    // Print CodeSum & CodeProduct to the terminal
    int CodeSum = AlphaCode + BravoCode + CharlieCode;
    int CodeProduct = AlphaCode * BravoCode * CharlieCode;
    float TheCheck = CodeSum/3;

    if ((CodeSum % 3 == 0) && (TheCheck == AlphaCode || TheCheck == BravoCode || TheCheck == CharlieCode))
    {
        cout << endl; // or "\n"
//        cout << AlphaCode << BravoCode << CharlieCode << endl;
        cout << "INTEL: There are 3 numbers in the code" <<".\n";
        cout << "INTEL: The code adds up to " << CodeSum << ".\n";
        cout << "INTEL: The code product is " << CodeProduct << ".\n";

        // Accept guesses
        int GuessAlpha, GuessBravo, GuessCharlie;
        cout << "ENTER CODE:" << endl;
        cin >> GuessAlpha >> GuessBravo >> GuessCharlie;
        cout << endl;

        //Display GuessSum & GuessProduct
        int GuessSum = GuessAlpha + GuessBravo + GuessCharlie;
        int GuessProduct = GuessAlpha * GuessBravo * GuessCharlie;
//        cout << "GUESS SUM: " << GuessSum << endl;
//        cout << "GUESS PRODUCT: " << GuessProduct << endl;

        int StartOver;
        if (GuessSum == CodeSum && GuessProduct == CodeProduct)
        {
            cout << "ACCESS GRANTED. SITE UNLOCKED.\n\n";
            cout << "Well done, Agent Duchess. Insert the USB that was included in your dossier and your mission will be marked complete...";

            char a = 177, b = 219;
            cout << "\n\n\tUSB DETECTED. COMMENCING DATA COPY....";
            cout << "\n\n";
            cout << "\t";
            for (int  (i) = 0; (i) <= 37; (i)++)
            {
                cout << a;
                Sleep(150);
            }
//            cout << "\r";
            cout << "\t ";
            cout << endl;
            cout << endl;

            cout << "Your mission is complete. Return to headquarters to be debriefed.\n\n";
            cout << "Play Again? (1 = Yes / 2 = No):";
            cin >> StartOver;
            if  (StartOver == 1)
            {
                PlayGame();
            }
            else
            {
                cout << "LOGOFF SUCCESSFUL.";
            }
        }
        else
        {
            cout << "INCORRECT CODE. SECURE LOCK ENGAGED. WOMP, WOMP.\n\n";
            cout << "Thanks to your genius the code has most definitely changed. Want to try again? (1 = Yes / 2 = No):";
            cin >> StartOver;
            if  (StartOver == 1)
            {
                PlayGame();
            }
            else
            {
                cout << "LOGOFF SUCCESSFUL.";
            }
        }
    }
    else
    {
        PlayGame();
    }
}

int main()
{
    PrintIntro();
    PlayGame();

    return 0;
}