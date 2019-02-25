//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
int x = -6;
int y = -6;
int playerOneScore = 0;
int playerTwoScore = 0;
int bounce = 0;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPongByTomasz *PingPongByTomasz;
//---------------------------------------------------------------------------
__fastcall TPingPongByTomasz::TPingPongByTomasz(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::timer_ballTimer(TObject *Sender)
{
   ball->Left += x;
   ball->Top += y;

   if(ball->Top <= background->Top) y = -y;
   if(ball->Top + ball->Height >= background->Height) y = -y;
   if(ball->Left <= playerOnePaddle->Left)
   {
      playerTwoScore++;
      whoScored->Caption = "Punkt dla gracza prawego >";
      timer_ball->Enabled = false;
      ball->Visible = false;
      timer_ball->Enabled = false;
      ball->Visible = false;
      whoScored->Visible = true;
      numberOfBounces->Visible = true;
      score->Caption = IntToStr(playerOneScore)+ ":" + IntToStr(playerTwoScore);
      score->Visible = true;
      numberOfBounces->Caption = "Iloœæ odbiæ: " + IntToStr(bounce);
      resetGame->Visible = true;
      nextRound->Visible = true;
   }
   else if(ball->Left + ball->Width >= playerTwoPaddle->Left + playerTwoPaddle->Width)
   {
      timer_ball->Enabled = false;
      ball->Visible = false;
      playerOneScore++;
      whoScored->Caption = "< Punkt dla gracza lewego";
      timer_ball->Enabled = false;
      ball->Visible = false;
      whoScored->Visible = true;
      numberOfBounces->Visible = true;
      score->Caption = IntToStr(playerOneScore)+ ":" + IntToStr(playerTwoScore);
      score->Visible = true;
      numberOfBounces->Caption = "Iloœæ odbiæ: " + IntToStr(bounce);
      resetGame->Visible = true;
      nextRound->Visible = true;
   }
   else if(ball->Top > playerOnePaddle->Top - ball->Height/2 &&
           ball->Top + ball->Height < playerOnePaddle->Top + playerOnePaddle->Height + ball->Height/2 &&
           ball->Left < playerOnePaddle->Left + playerOnePaddle->Width)
        {
           if (abs(x) != abs(y))
           {
              if (y < 0) x = y;
              else x = -y;
           }
           if (ball->Top > playerOnePaddle->Top + playerOnePaddle->Height*0.35 - ball->Height/2 &&
           ball->Top + ball->Height < playerOnePaddle->Top + playerOnePaddle->Height*0.70 + ball->Height/2)
              x = x * 1.5;
           if(x < 0)
              x = -x;

           bounce++;
           if (bounce % 3 == 0 && bounce <= 15)
           {
              x = x * 1.2;
              y = y * 1.2;
           }
        }
   else if(ball->Top > playerTwoPaddle->Top - ball->Height/2 &&
           ball->Top + ball->Height < playerTwoPaddle->Top + playerTwoPaddle->Height + ball->Height/2 &&
           ball->Left + ball->Width > playerTwoPaddle->Left)
        {
           if (abs(x) != abs(y))
           {
              if (y < 0) x = -y;
              else x = y;
           }
           if (ball->Top > playerTwoPaddle->Top + playerTwoPaddle->Height*0.35 - ball->Height/2 &&
           ball->Top + ball->Height < playerTwoPaddle->Top + playerTwoPaddle->Height*0.70 + ball->Height/2)
              x = x * 1.5;
           if(x > 0)
              x = -x;

           bounce++;
           if (bounce % 3 == 0 && bounce <= 15)
           {
              x = x * 1.2;
              y = y * 1.2;
           }
        }
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::playerOneMoveUpTimer(TObject *Sender)
{
   if (playerOnePaddle->Top > 0) playerOnePaddle->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::playerOneMoveDownTimer(TObject *Sender)
{
   if (playerOnePaddle->Top + playerOnePaddle->Height < background->Height) playerOnePaddle->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == 'A') playerOneMoveUp->Enabled = false;
   if (Key == 'Z') playerOneMoveDown->Enabled = false;
   if (Key == VK_UP) playerTwoMoveUp->Enabled = false;
   if (Key == VK_DOWN) playerTwoMoveDown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::playerTwoMoveUpTimer(TObject *Sender)
{
   if (playerTwoPaddle->Top > 0) playerTwoPaddle->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::playerTwoMoveDownTimer(TObject *Sender)
{
if (playerTwoPaddle->Top + playerTwoPaddle->Height < background->Height) playerTwoPaddle->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == 'A') playerOneMoveUp->Enabled = true;
   if (Key == 'Z') playerOneMoveDown->Enabled = true;
   if (Key == VK_UP) playerTwoMoveUp->Enabled = true;
   if (Key == VK_DOWN) playerTwoMoveDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TPingPongByTomasz::newGameButtonClick(TObject *Sender)
{
    timer_ball->Enabled = true;
    newGameLabel->Visible = false;
    newGameButton->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TPingPongByTomasz::FormCreate(TObject *Sender)
{
   ShowMessage("Witaj w grze PingPong.\n\n"
   "Lewy gracz steruje klawiszami A oraz Z.\n"
   "Prawy gracz steruje klawiszami strza³ek w górê oraz w dó³.\n\n"
   "Dla urozmaicenia zabawy:\n"
   "Kiedy odbijesz pi³kê na œrodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyœpieszy.\n"
   "Im d³u¿ej odbijasz, tym szybciej pi³ka przemieszcza siê.\n"
   "Mo¿esz dowolnie zmienia pole gry.\n\n"
   "Mi³ej zabawy!");
}
//---------------------------------------------------------------------------



void __fastcall TPingPongByTomasz::nextRoundClick(TObject *Sender)
{
   x = -6;
   y = -6;
   playerOnePaddle->Top = 160;
   playerTwoPaddle->Top = 160;
   ball->Top = 250;
   ball->Left = 500;
   ball->Visible = true;
   timer_ball->Enabled = true;
   whoScored->Visible = false;
   numberOfBounces->Visible = false;
   score->Visible = false;
   nextRound->Visible = false;
   resetGame->Visible = false;
   bounce = 0;
}
//---------------------------------------------------------------------------

void __fastcall TPingPongByTomasz::resetGameClick(TObject *Sender)
{
   if(Application->MessageBox(
   "Czy na pewno chcesz zacz¹æ od nowa?","PotwierdŸ",
   MB_YESNO |MB_ICONQUESTION) == IDYES)
   {
      x = -6;
      y = -6;
      playerOnePaddle->Top = 160;
      playerTwoPaddle->Top = 160;
      ball->Top = 250;
      ball->Left = 500;
      ball->Visible = true;
      timer_ball->Enabled = true;
      whoScored->Visible = false;
      numberOfBounces->Visible = false;
      score->Visible = false;
      nextRound->Visible = false;
      resetGame->Visible = false;
      playerOneScore = 0;
      playerTwoScore = 0;
      bounce = 0;
   }
}
//---------------------------------------------------------------------------

