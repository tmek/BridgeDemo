/*
#pragma once

#define NETFLIX_AQUIRE_DELAY_IN_SECONDS 5
#define CAPTURE_SIZE 512

class NetflixWindow
{
public:
	NetflixWindow();
	~NetflixWindow();

	HWND CaptureHWND;

	void AquireNetflixWindow();

protected:
	HWND BrowserHWND;

	static BOOL CALLBACK EnumChildProcHandler(HWND hwnd, LPARAM lParam);

	void SetCaptureHWND(HWND hwnd);
};
*/