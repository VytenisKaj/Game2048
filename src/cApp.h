#pragma once

#include"wx\wx.h"
#include"cMain.h"

class cApp : public wxApp
{
	friend cMain;

	public:
		cApp();
		~cApp();

	private:
		cMain* frame = NULL;

	public:
		virtual bool OnInit();
};

