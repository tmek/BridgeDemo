/*
// Copyright 2014. All Rights Reserved.

#include "NetflixWindow.h"
#include "BridgeDemo.h"


NetflixWindow::NetflixWindow()
{
	BrowserHWND = NULL;
	CaptureHWND = NULL;
}

NetflixWindow::~NetflixWindow()
{
}

void NetflixWindow::AquireNetflixWindow() {

	// TODO: add paths for firefox and IE.

	// Find browser window, try Google Chrome
	BrowserHWND = FindWindowEx(NULL, NULL, NULL, TEXT("Netflix - Google Chrome"));

	// try Firefox
	if (!BrowserHWND) {
		BrowserHWND = FindWindowEx(NULL, NULL, NULL, TEXT("Netflix - Mozilla Firefox"));
	}

	if (!BrowserHWND) return;

	// attempt to make sure browser is not maximized
	SetWindowPos(BrowserHWND, HWND_BOTTOM, 0, 0, CAPTURE_SIZE, CAPTURE_SIZE, SWP_NOACTIVATE | SWP_NOZORDER | SWP_DEFERERASE);
	
	//todo: firefox needs a delay after calling this to give the window time to resize.
	Sleep(100);

	// enumerate child windows to find capture window
	EnumChildWindows(BrowserHWND, NetflixWindow::EnumChildProcHandler, reinterpret_cast<LPARAM>(this));
}


void NetflixWindow::SetCaptureHWND(HWND hwnd) {

	CaptureHWND = hwnd;

	// resize browser window such that capture window is CAPTURE_SIZE by CAPTURE_SIZE
	RECT br, cr;
	GetWindowRect(BrowserHWND, &br);
	GetWindowRect(CaptureHWND, &cr);
	int newwidth = (br.right - br.left) - (cr.right - cr.left) + CAPTURE_SIZE; 
	int newheight = (br.bottom - br.top) - (cr.bottom - cr.top) + CAPTURE_SIZE;
	SetWindowPos(BrowserHWND, HWND_BOTTOM, 0, 0, newwidth, newheight, SWP_NOACTIVATE | SWP_NOZORDER | SWP_DEFERERASE);
}

BOOL CALLBACK NetflixWindow::EnumChildProcHandler(HWND hwnd, LPARAM lParam) {
	// TODO: add paths for firefox and IE.

	NetflixWindow* that = reinterpret_cast<NetflixWindow*>(lParam);

	// the first child window is the capture window for Google Chrome.
	that->SetCaptureHWND(hwnd);

	// no need to continue searching children
	return false;
}
*/