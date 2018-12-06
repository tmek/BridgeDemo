/*
#include "WindowCapture.h"
#include "BridgeDemo.h"
#include "AllowWindowsPlatformTypes.h"

WindowCapture::WindowCapture(HWND hWnd, int captureWidth, int captureHeight)
{
	this->hWnd = hWnd;
	CaptureHeight = captureHeight;
	CaptureWidth = captureWidth;
	ImageBuffer = (UINT32*)malloc(captureWidth * captureHeight * sizeof(UINT32));

	hBitmap = NULL;

	windowDC = GetDC(hWnd);

	// create a DC that is compatible with the current window DC.
	compatibleDC = CreateCompatibleDC(windowDC);
	if (!compatibleDC) return;

	// create a bitmap with the appropriate dimensions
	hBitmap = CreateCompatibleBitmap(windowDC, CaptureWidth, CaptureHeight);
	if (!hBitmap) return;

	// select it into this device context
	SelectObject(compatibleDC, hBitmap);

	// Gets the "bits" from the bitmap and copies them into a buffer 
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = CaptureWidth;
	bi.biHeight = CaptureHeight;
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	ReleaseDC(hWnd, windowDC);
}


WindowCapture::~WindowCapture()
{
	free(ImageBuffer);

	DeleteObject(hBitmap);
	DeleteObject(compatibleDC);
	ReleaseDC(hWnd, windowDC);
}


bool WindowCapture::CaptureToBuffer()
{
	bool success = false;

	windowDC = GetDC(hWnd);

	// Bit block transfer into our compatible memory DC.
	if (!BitBlt(compatibleDC, 0, 0, CaptureWidth, CaptureHeight, windowDC, 0, 0, SRCCOPY)) {
		goto done;
	}

	GetDIBits(compatibleDC, hBitmap, 0, (UINT)CaptureHeight, ImageBuffer, (BITMAPINFO *)&bi, DIB_RGB_COLORS);

	success = true;

done:
	ReleaseDC(hWnd, windowDC);

	return success;
}

#include "HideWindowsPlatformTypes.h"
*/