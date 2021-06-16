// Created by Vytenis Kajackas 2021-06-09
// header of main GUI frame 

#pragma once

#include"wx\wx.h"
#include"game2048.h"

class cMain : public wxFrame
{
	private:

		// Top
		wxPanel* panelTR;
		wxPanel* panelTL;

		// Bottom
		wxPanel* panelBL;
		wxPanel* panelBM;
		wxPanel* panelBR;

		wxStaticText* scoreBox;

		// Main sizer
		wxBoxSizer* mainS;

		// Top
		wxBoxSizer* topSizer;
		wxBoxSizer* topHorSizer;
		wxBoxSizer* scoreSizer;
		wxBoxSizer* topRightVerSizer;
		
		// Board
		wxGridSizer* boardGrid;

		// Bottom
		wxBoxSizer* bottomSizer;
		wxBoxSizer* bottomSizerH;
		wxBoxSizer* bottomLS;
		wxBoxSizer* bottomMS;
		wxBoxSizer* bottomRS;
		
		// Buttons
		wxBitmapButton* rightB;
		wxBitmapButton* leftB;
		wxBitmapButton* upB;
		wxBitmapButton* downB;

		// Board elements
		wxButton* boardElems[BOARD_SIZE][BOARD_SIZE];
		
		Game2048* game;

	
	public:
		cMain();
		~cMain();

	private:

		// Updates boards of GUI
		void updateBoard();

		// Returns game state
		void checkGameState();

		// Detects mouse inputs
		void onButtonClicked(wxEvent& evt);

		// Returns color of a tile
		wxColor getTileColor(int tileValue);


		wxDECLARE_EVENT_TABLE();
	

};

