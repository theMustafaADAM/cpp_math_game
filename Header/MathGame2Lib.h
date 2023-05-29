#ifndef MATHGAME2LIB_INCLUDED
#define MATHGAME2LIB_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;



namespace readNmbr
{
    short RandomNumbers(short From, short To)
    {
        short RNmber =0;
        RNmber = rand() % (To - From + 1) + From;
        return RNmber;
    }

}

namespace stringmath
{
    string myTAB(short NmbrOfTab)
    {
        string t="";
        for (short tab = 0; tab < NmbrOfTab; tab++)
            t= t+"\t"; cout << t;
        return t;
    }



}

enum enOperatorsType{Addd  =1, Mult  =2, Subt  =3, Divi  =4, Miix =5};
enum enQuestionLevel{Eassy =1, Mdium =2, Hardd =3, Mixng =4};

struct stQuestion
{
    short FrstNmbr =0; short CrrectAnswer =0;
    short ScndNmbr =0; short PlayerAnswer =0;
    bool TheAnswer = false;
    enOperatorsType OperatorsType;
    enQuestionLevel QuestionLevel;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    enOperatorsType Operators_Type;
    enQuestionLevel Question_Level;
    bool TheResult = false;
    short QustionNmbers =0;
    short CrrectAnswers =0;
    short Wrong_Answers =0;
};



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

short ReadPlayerAnswer()
{
    short PlayerAnswer = 0; cout << myTAB(1); cin >> PlayerAnswer; cout << endl; return PlayerAnswer;
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

stQuestion GenerateTheQuestion(enQuestionLevel Level, enOperatorsType Operators)
{
    stQuestion Question;
    if(Level == enQuestionLevel::Mixng)
    {
        Level = (enQuestionLevel) RandomNumbers(1,3);
    }
    if(Operators == enOperatorsType::Miix)
    {
        Operators = GetRandomOperatorsType();
    }
    Question.OperatorsType = Operators;
    switch(Level)
    {
    case enQuestionLevel::Eassy:
        Question.FrstNmbr = RandomNumbers(1,9); Question.ScndNmbr = RandomNumbers(10, 19);
        Question.CrrectAnswer =
        SimpleCalculator(Question.FrstNmbr, Question.ScndNmbr, Question.OperatorsType);
        Question.QuestionLevel = Level;
        return Question;
    case enQuestionLevel::Mdium:
        Question.FrstNmbr = RandomNumbers(10, 29); Question.ScndNmbr = RandomNumbers(20, 49);
        Question.CrrectAnswer =
        SimpleCalculator(Question.FrstNmbr, Question.ScndNmbr, Question.OperatorsType);
        Question.QuestionLevel = Level;
        return Question;
    case enQuestionLevel::Hardd:
        Question.FrstNmbr = RandomNumbers(-99,-10); Question.ScndNmbr = RandomNumbers(11, 99);
        Question.CrrectAnswer =
        SimpleCalculator(Question.FrstNmbr, Question.ScndNmbr, Question.OperatorsType);
        Question.QuestionLevel = Level;
        return Question;
    }
    return Question;
}

void GenerateTheQuizz(stQuizz& Quizz)
{
    for(short question =0; question < Quizz.QustionNmbers; question++)
    {
        Quizz.QuestionList[question] = GenerateTheQuestion(Quizz.Question_Level, Quizz.Operators_Type);
    }
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

void PrintTheQuestion(stQuizz& Quizz, short QustionNmbers)
{
    cout << endl;
    cout <<myTAB(1)<< "Question [ " << QustionNmbers +1 << " / " << Quizz.QustionNmbers << " ]\n" <<endl;
    cout <<myTAB(1)<< Quizz.QuestionList[QustionNmbers].FrstNmbr << " ";
    cout << GetOperatorsTypeSymple(Quizz.QuestionList[QustionNmbers].OperatorsType);
    cout << " " << Quizz.QuestionList[QustionNmbers].ScndNmbr << endl;
    cout <<myTAB(1)<< "_______________" << endl;
}

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

void CheckCorrectAnswers(stQuizz& Quizz, short QuestionNmber)
{
    if(Quizz.QuestionList[QuestionNmber].PlayerAnswer != Quizz.QuestionList[QuestionNmber].CrrectAnswer)
    {
        Quizz.QuestionList[QuestionNmber].TheAnswer = false;
        Quizz.Wrong_Answers++;
        cout <<myTAB(1)<< "This Answer is Wrong :-( \n" << endl;
        cout <<myTAB(1)<< "The Correct Answer is " << Quizz.QuestionList[QuestionNmber].CrrectAnswer << endl;
    }
    else
    {
        Quizz.QuestionList[QuestionNmber].TheAnswer = true;
        Quizz.CrrectAnswers++;
        cout <<myTAB(1)<< "This Answer is Correct :-) \n" << endl;
    }
    cout << endl;
    SetAnswerScreenColor(Quizz.QuestionList[QuestionNmber].TheAnswer);
}

void Checking_Answers(stQuizz& Quizz)
{
    for(short QNmbr =0; QNmbr < Quizz.QustionNmbers; QNmbr++)
    {
        PrintTheQuestion(Quizz, QNmbr);
        Quizz.QuestionList[QNmbr].PlayerAnswer = ReadPlayerAnswer();
        CheckCorrectAnswers(Quizz, QNmbr);
    }
    Quizz.TheResult = (Quizz.CrrectAnswers >= Quizz.Wrong_Answers);
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

void PrintQuizzResults(stQuizz Quizz)
{
    cout << endl;
    cout <<myTAB(1)<<"________________________________________\n" << endl;
    cout <<myTAB(1)<< "Final Results is ";
    cout << GetFinalResult(Quizz.TheResult) << endl;
    cout <<myTAB(1)<<"________________________________________\n" << endl;
    cout << endl;
    cout <<myTAB(1)<< "ALL Questions   :  " << Quizz.QustionNmbers << endl;
    cout <<myTAB(1)<< "Chosen Level    :  " << GetQuestionLevel(Quizz.Question_Level) << endl;
    cout <<myTAB(1)<< "Chosen Operator : " << GetOperatorsTypeSymple(Quizz.Operators_Type) << endl;
    cout <<myTAB(1)<< "Correct Answers :  " << Quizz.CrrectAnswers << endl;
    cout <<myTAB(1)<< "Wrong Answers   :  " << Quizz.Wrong_Answers << endl;
    cout << endl;
    cout <<myTAB(1)<<"________________________________________\n" << endl;
}

void PlayTheGame()
{
    stQuizz Quizz;
    Quizz.QustionNmbers  = ReadHowMnyQustion();
    Quizz.Question_Level = ReadQuestionLevel();
    Quizz.Operators_Type = ReadOperatorsType();
    GenerateTheQuizz(Quizz);
    Checking_Answers(Quizz);
    PrintQuizzResults(Quizz);
}

void ResetMyScreen()
{
    system("clear");
    system("Color F2");
}

void StartTheGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetMyScreen();
        PlayTheGame();
        cout <<myTAB(1)<< "Would You Like To Play Again? \n\t\tThe Options [Y/y] Yes [any] No " << endl;
        cout << myTAB(2);
        cin >> PlayAgain;
    }
    while (PlayAgain == 'Y' || PlayAgain == 'y');



#endif // MATHGAME2LIB_INCLUDED
