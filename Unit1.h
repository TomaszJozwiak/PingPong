//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TPingPongByTomasz : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *timer_ball;
        TImage *playerOnePaddle;
        TImage *playerTwoPaddle;
        TTimer *playerOneMoveUp;
        TTimer *playerOneMoveDown;
        TTimer *playerTwoMoveUp;
        TTimer *playerTwoMoveDown;
        TLabel *newGameLabel;
        TButton *newGameButton;
        TLabel *whoScored;
        TLabel *score;
        TLabel *numberOfBounces;
        TButton *nextRound;
        TButton *resetGame;
        void __fastcall timer_ballTimer(TObject *Sender);
        void __fastcall playerOneMoveUpTimer(TObject *Sender);
        void __fastcall playerOneMoveDownTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall playerTwoMoveUpTimer(TObject *Sender);
        void __fastcall playerTwoMoveDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall newGameButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
        void __fastcall resetGameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPingPongByTomasz(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPingPongByTomasz *PingPongByTomasz;
//---------------------------------------------------------------------------
#endif
