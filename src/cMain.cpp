#include "cMain.h"
#include"game2048.h"
#include<string>

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(NULL, wxID_ANY, "2048",wxPoint(10, 10),wxSize(300, 100) ){

	/*
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(6364);*/

	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	this->SetFont(font);

	game = new Game2048();

	panelTR = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 70));
	panelTL = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 70));

	panelBL = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 70));
	//panelBM = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 70));
	panelBR = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 70));
	
	wxColor defaultColor1(124, 124, 124);
	wxColor defaultColor2(196, 147, 83);
	

	scoreBox = new wxStaticText(this, wxID_ANY, "Score: " + std::to_string(game->getScore()), wxDefaultPosition, wxSize(50, 30));
	//scoreBox->SetBackgroundColour(defaultColor2);

	panelTR->SetBackgroundColour(defaultColor2);
	//boardPanel->SetBackgroundColour(wxColor(50, 50, 50));
	panelTL->SetBackgroundColour(defaultColor2);

	panelBL->SetBackgroundColour(defaultColor1);
	//panelBM->SetBackgroundColour(wxColor(100, 50, 50));
	panelBR->SetBackgroundColour(defaultColor1);

	mainS = new wxBoxSizer(wxVERTICAL);

	topSizer = new wxBoxSizer(wxVERTICAL);
	
	topHorSizer = new wxBoxSizer(wxHORIZONTAL);
	boardGrid = new wxGridSizer(BOARD_SIZE, 0, 0);
	scoreSizer = new wxBoxSizer(wxVERTICAL);
	topRightVerSizer = new wxBoxSizer(wxVERTICAL);

	bottomSizer = new wxBoxSizer(wxVERTICAL);
	bottomSizerH = new wxBoxSizer(wxHORIZONTAL);

	bottomLS = new wxBoxSizer(wxVERTICAL);
    bottomMS = new wxBoxSizer(wxHORIZONTAL);
	bottomRS = new wxBoxSizer(wxVERTICAL);


	// Images

	wxInitAllImageHandlers();

	wxBitmap arrowRight;
	arrowRight.LoadFile("arrow_right.png", wxBITMAP_TYPE_PNG);
	wxBitmap arrowLeft;
	arrowLeft.LoadFile("arrow_left.png", wxBITMAP_TYPE_PNG);
	wxBitmap arrowUp;
	arrowUp.LoadFile("arrow_up.png", wxBITMAP_TYPE_PNG);
	wxBitmap arrowDown;
	arrowDown.LoadFile("arrow_down.png", wxBITMAP_TYPE_PNG);


	// Control buttons
	upB = new wxBitmapButton(this, 10001, arrowUp, wxDefaultPosition, wxDefaultSize, 0);
	upB->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::onButtonClicked, this);

	downB = new wxBitmapButton(this, 10002, arrowDown, wxDefaultPosition, wxDefaultSize, 0);
	downB->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::onButtonClicked, this);

	//rightB = new wxButton(this, 10003, "RIGHT", wxDefaultPosition, wxDefaultSize);
	rightB = new wxBitmapButton(this, 10003, arrowRight, wxDefaultPosition, wxDefaultSize, 0);
	rightB->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::onButtonClicked, this);

	leftB = new wxBitmapButton(this, 10004, arrowLeft, wxDefaultPosition, wxDefaultSize, 0);
	leftB->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::onButtonClicked, this);

	


	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			boardElems[i][j] = new wxButton(this, wxID_ANY);
			boardElems[i][j]->SetLabel(game->board[i][j]->toString());
			boardElems[i][j]->SetBackgroundColour(getTileColor(game->board[i][j]->getValue()));
			boardGrid->Add(boardElems[i][j], 1, wxEXPAND | wxALL, 0);
		}
	}
	boardGrid->Layout();


	scoreSizer->Add(scoreBox, 1, wxEXPAND, 0);

	// Top right panel

	topRightVerSizer->Add(scoreSizer, 1,  wxEXPAND | wxALL, 0);
	topRightVerSizer->Add(panelTR, 10, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 0);

	//Top panel

	topSizer->Add(topHorSizer, 1, wxEXPAND | wxLEFT | wxTOP, 0);
	topHorSizer->Add(panelTL, 1, wxEXPAND | wxRIGHT | wxLEFT | wxTOP, 5);
	topHorSizer->Add(boardGrid, 2, wxEXPAND | wxTOP, 5);
	topHorSizer->Add(topRightVerSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 5);

	
	
	//Bottom panel

	bottomLS->Add(panelBL, 1, wxEXPAND | wxALL, 0);
	//bottomMS->Add(panelBM, 1, wxEXPAND | wxALL, 0);
	bottomMS->Add(leftB, 1, wxEXPAND | wxALL, 0);
	bottomMS->Add(downB, 1, wxEXPAND | wxALL, 0);
	bottomMS->Add(upB, 1, wxEXPAND | wxALL, 0);
	bottomMS->Add(rightB, 1, wxEXPAND | wxALL, 0);
	bottomRS->Add(panelBR, 1, wxEXPAND | wxALL, 0);

	bottomSizer->Add(bottomSizerH, 1, wxEXPAND | wxBOTTOM | wxTOP, 5);
	bottomSizerH->Add(bottomLS, 1, wxEXPAND | wxLEFT, 5);
	bottomSizerH->Add(bottomMS, 3, wxEXPAND | wxLEFT | wxRIGHT, 5);
	bottomSizerH->Add(bottomRS, 1, wxEXPAND | wxRIGHT, 5);
	

	mainS->Add(topSizer, 3, wxEXPAND | wxALL, 0);
	mainS->Add(bottomSizer, 1, wxEXPAND | wxALL, 0);

	this->SetSizerAndFit(mainS);
}

cMain::~cMain()
{
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			delete boardElems[i][j];
		}
	}
	delete game;
}

void cMain::updateBoard() {

	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			boardElems[i][j]->SetLabel(game->board[i][j]->toString());
			boardElems[i][j]->SetBackgroundColour(getTileColor(game->board[i][j]->getValue()));
		}
	}
	scoreBox->SetLabel("Score: " + std::to_string(game->getScore()));
}


void cMain::onButtonClicked(wxEvent& evt) {
	if (evt.GetId() == 10001) {
		game->moveUp();
	}
	if (evt.GetId() == 10002) {
		game->moveDown();
	}
	if (evt.GetId() == 10003) {
		game->moveRight();
	}
	if (evt.GetId() == 10004) {
		game->moveLeft();
	}
	evt.Skip();
	checkGameState();
	this->updateBoard();
}

void cMain::checkGameState() {
	if (!game->getIsActive()) {
		wxMessageBox("Game over, you lost");
		game->resetGame();
		game->resetScore();
	}
	if (game->getHighestTileValue() == 2048) {
		wxMessageBox("You won! You can continue or end the game");
		game->resetHighestTileValue();
	}
}

wxColor cMain::getTileColor(int tileValue) {

	switch (tileValue) {
		case 0:
			return wxColor(255, 255, 255);
		case 2:
			return wxColor(255, 255, 195);
		case 4:
			return wxColor(255, 255, 135);
		case 8:
			return wxColor(240, 176, 0);
		case 16:
			return wxColor(230, 138, 0);
		case 32:
			return wxColor(230, 90, 0);
		case 64:
			return wxColor(255, 76, 76);
		case 128:
			return wxColor(204, 0, 102);
		case 256:
			return wxColor(152, 60, 231);
		case 512:
			return wxColor(84, 84,233);
		case 1024:
			return wxColor(66, 223, 192);
		case 2048:
			return wxColor(56, 229, 56);
		default:
			return wxColor(153, 0, 0);
	}

}