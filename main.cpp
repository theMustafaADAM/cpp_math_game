#include <iostream>
#include <cstdlib>
#include "mathgame2.h";

using namespace std;
using namespace stringmath;
//using namespace numbersmath;

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

///Declaration for Function
stQuestion GenerateTheQuestion(enQuestionLevel, enOperatorsType);

void GenerateTheQuizz(stQuizz& Quizz)
{
    for(short question =0; question < Quizz.QustionNmbers; question++)
    {
        Quizz.QuestionList[question] = GenerateTheQuestion(Quizz.Question_Level, Quizz.Operators_Type);
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
    colormath::SetAnswerScreenColor(Quizz.QuestionList[QuestionNmber].TheAnswer);
}

void Checking_Answers(stQuizz& Quizz)
{
    for(short QNmbr =0; QNmbr < Quizz.QustionNmbers; QNmbr++)
    {
        PrintTheQuestion(Quizz, QNmbr);
        Quizz.QuestionList[QNmbr].PlayerAnswer = numbersmath::ReadPlayerAnswer();
        CheckCorrectAnswers(Quizz, QNmbr);
    }
    Quizz.TheResult = (Quizz.CrrectAnswers >= Quizz.Wrong_Answers);
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
    Quizz.QustionNmbers  = numbersmath::ReadHowMnyQustion();
    Quizz.Question_Level = numbersmath::ReadQuestionLevel();
    Quizz.Operators_Type = numbersmath::ReadOperatorsType();
    GenerateTheQuizz(Quizz);
    Checking_Answers(Quizz);
    PrintQuizzResults(Quizz);
}

void StartTheGame()
{
    char PlayAgain = 'Y';
    do
    {
        colormath::ResetMyScreen();
        PlayTheGame();
        cout <<myTAB(1)<< "Would You Like To Play Again? \n\t\tThe Options [Y/y] Yes [any key] No " << endl;
        cout <<myTAB(2);
        cin >> PlayAgain;
    }
    while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand(( unsigned ) time( NULL ));

    StartTheGame();

    return 0;
}

///The Defination of Function
stQuestion GenerateTheQuestion(enQuestionLevel Level, enOperatorsType Operators)
{
    stQuestion Question;
    if(Level == enQuestionLevel::Mixng)
    {
        Level = (enQuestionLevel) numbersmath::RandomNumbers(1,3);
    }
    if(Operators == enOperatorsType::Miix)
    {
        Operators = numbersmath::GetRandomOperatorsType();
    }
    Question.OperatorsType = Operators;

    switch(Level)
    {
    case enQuestionLevel::Eassy:
        Question.FrstNmbr = numbersmath::RandomNumbers(1,9);
        Question.ScndNmbr = numbersmath::RandomNumbers(10, 19);
        Question.CrrectAnswer =
        numbersmath::SimpleCalculator(Question.FrstNmbr, Question.ScndNmbr, Question.OperatorsType);
        Question.QuestionLevel = Level;
        return Question;

    case enQuestionLevel::Mdium:
        Question.FrstNmbr = numbersmath::RandomNumbers(10, 29);
        Question.ScndNmbr = numbersmath::RandomNumbers(20, 49);
        Question.CrrectAnswer =
        numbersmath::SimpleCalculator(Question.FrstNmbr, Question.ScndNmbr, Question.OperatorsType);
        Question.QuestionLevel = Level;
        return Question;

    case enQuestionLevel::Hardd:
        Question.FrstNmbr = numbersmath::RandomNumbers(-99,-10);
        Question.ScndNmbr = numbersmath::RandomNumbers(11, 99);
        Question.CrrectAnswer =
        numbersmath::SimpleCalculator(Question.FrstNmbr, Question.ScndNmbr, Question.OperatorsType);
        Question.QuestionLevel = Level;
        return Question;
    }
    return Question;
}

