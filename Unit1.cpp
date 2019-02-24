//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
int x = -8;
int y = -8;
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
      timer_ball->Enabled = false;
      ball->Visible = false;
      playerTwoScore++;
   }
   else if(ball->Left + ball->Width >= playerTwoPaddle->Left + playerTwoPaddle->Width)
   {
      timer_ball->Enabled = false;
      ball->Visible = false;
      playerOneScore++;
   }
   else if(ball->Top > playerOnePaddle->Top - ball->Height/2 &&
           ball->Top + ball->Height < playerOnePaddle->Top + playerOnePaddle->Height - ball->Height/2 &&
           ball->Left > playerOnePaddle->Left + playerOnePaddle->Width)
        {
           if (x > 0) x = -x;
        }
   else if(ball->Top > playerTwoPaddle->Top - ball->Height/2 &&
           ball->Top + ball->Height < playerTwoPaddle->Top + playerTwoPaddle->Height - ball->Height/2 &&
           ball->Left + ball->Width > playerTwoPaddle->Left)
        {
           if (x > 0) x = -x;
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