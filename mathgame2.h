#ifndef MATHGAME2_H_INCLUDED
#define MATHGAME2_H_INCLUDED
#include <iostream>

using namespace std;

enum enOperatorsType{Addd  =1, Mult  =2, Subt  =3, Divi  =4, Miix =5};

enum enQuestionLevel{Eassy =1, Mdium =2, Hardd =3, Mixng =4};

namespace stringmath
{
    string myTAB(short NmbrOfTab)
    {
        string t="";
        for (short tab = 0; tab < NmbrOfTab; tab++)
            t= t+"\t"; cout << t;
        return t;
    }

    string GetOperatorsTypeSymple(enOperatorsType Operator)
    {
        switch(Operator)
        {
            case enOperatorsType::Addd: return " + "; break;
            case enOperatorsType::Mult: return " * "; break;
            case enOperatorsType::Subt: return " - "; break;
            case enOperatorsType::Divi: return " / "; break;
            default:                    return " Mix ";
        }
    }

    string GetFinalResult(bool Results)
    {
        if(Results)
        {
            return " PASS !! ** Congrats ** ";
        }
        else
        {
            return " FAIL !! ^^ Good Luck ^^ ";
        }
    }

    string GetQuestionLevel(enQuestionLevel Level)
    {
        string QuestionLevel[4] = {"Easy", "Medium", "Hard", "Mix"};
        return QuestionLevel[Level -1];
    }
}

namespace numbersmath
{
    using namespace stringmath;

    short RandomNumbers(short From, short To)
    {
        short RNmber =0;
        RNmber = rand() % (To - From + 1) + From;
        return RNmber;
    }

    short SimpleCalculator(short FrstNmbr, short ScndNmbr, enOperatorsType OperatorsType)
    {
        switch(OperatorsType)
        {
            case enOperatorsType::Addd: return FrstNmbr + ScndNmbr; break;
            case enOperatorsType::Mult: return FrstNmbr * ScndNmbr; break;
            case enOperatorsType::Subt: return FrstNmbr - ScndNmbr; break;
            case enOperatorsType::Divi: return FrstNmbr / ScndNmbr; break;
            default:                    return FrstNmbr + ScndNmbr;
        }
    }

    enOperatorsType GetRandomOperatorsType()
    {
        short Operator = RandomNumbers(1,4);
        return (enOperatorsType) Operator;
    }

    short ReadHowMnyQustion()
    {
        short HowMnyQustion =0;
        do
        {
            cout <<myTAB(1)<< "How Many Question To Play? \n\t\tThe Options From [1] To [10] " << endl;
            cout << myTAB(2); cin >> HowMnyQustion; cout << endl;
        }
        while (HowMnyQustion <1 || HowMnyQustion >10);
        return HowMnyQustion;
    }

    short ReadPlayerAnswer()
    {
        short PlayerAnswer = 0; cout << myTAB(1); cin >> PlayerAnswer; cout << endl; return PlayerAnswer;
    }

    enQuestionLevel ReadQuestionLevel()
    {
        short QuestionLevel =0;
        do
        {
            cout <<myTAB(1)<< "How Hard Level Want Play? \n\tThe Options [1] Easy [2] Medium [3] Hard [4] Mix " << endl;
            cout <<myTAB(2); cin >> QuestionLevel; cout << endl;
        }
        while (QuestionLevel <1 || QuestionLevel >4);
        return(enQuestionLevel) QuestionLevel;
    }

    enOperatorsType ReadOperatorsType()
    {
        short OperatorsType =0;
        do
        {
            cout <<myTAB(1)<< "Choose Your Favorite Operation Type? \n\tThe Options [1] Add [2] Multiply [3] Subtract [4] Divide [5] Mix " << endl;
            cout <<myTAB(2); cin >> OperatorsType; cout << endl;
        }
        while (OperatorsType <1 || OperatorsType >5);
        return(enOperatorsType) OperatorsType;
    }
}

namespace colormath
{
    void SetAnswerScreenColor(bool CorrectAnswer)
    {
        if(CorrectAnswer)
        {
            system("color 2F"); ///Green Color
        }
        else
        {
            system("color 4F"); cout << "\a"; ///Red Color
        }
    }

    void ResetMyScreen()
    {
        system("clear");
        system("Color F2");
    }
}

#endif // MATHGAME2_H_INCLUDED
