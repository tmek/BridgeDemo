/*
#pragma once

class WindowCapture
{
public:
	WindowCapture(HWND hWnd, int captureWidth, int captureHeight);
	~WindowCapture();
	bool CaptureToBuffer();
	UINT32* ImageBuffer;
	int FramesPerSecond;

protected:
	HWND hWnd;
	int CaptureWidth;
	int CaptureHeight;

	HBITMAP hBitmap;
	HDC windowDC;
	HDC compatibleDC;
	BITMAPINFOHEADER bi;
};
*/