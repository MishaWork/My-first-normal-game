
#include "TXLib.h"

void Track();

void Car1 (HDC Track, HDC car1, HDC car2);

int main()
    {

    txCreateWindow (1900, 1080);

    Track ();

    return 0;
    }

void Track ()
    {
    HDC Track = txLoadImage ("Track.bmp");
    if (Track == NULL) txMessageBox ("Not Found");

    HDC car1 = txLoadImage ("CaR1.bmp");
    if (car1 == NULL) txMessageBox ("Not Found");

    HDC car2 = txLoadImage ("Car222.bmp");
    if (car2 == NULL) txMessageBox ("Not Found");

    Car1 (Track, car1, car2);

    }

void Car1 (HDC Track, HDC car1, HDC car2)
    {

    int x1 = 900;
    int y1 = 10;

    int x2 = 900;
    int y2 = 90;

    int xSource1 = 0;

    int xSource2 = 0;

    int car  = txGetExtentX (car1) / 4;

    int carX = txGetExtentX (car2) / 64;

    while (1 < 2)
        {

        txBitBlt (txDC (), 216, 0, 0, 0, Track);

        if (txGetAsyncKeyState  (VK_LEFT)) xSource1 = 370, x1 = x1 - 10;
        if (txGetAsyncKeyState (VK_RIGHT)) xSource1 =   0, x1 = x1 + 10;
        if (txGetAsyncKeyState  (VK_DOWN)) xSource1 = 185, y1 = y1 + 10;
        if (txGetAsyncKeyState    (VK_UP)) xSource1 = 555, y1 = y1 - 10;
        if (txGetAsyncKeyState      ('A')) xSource2 += 176; //x2 = x2 - 10;
        if (txGetAsyncKeyState      ('D')) xSource2 -= 176; //x2 = x2 + 10;
        if (txGetAsyncKeyState      ('S')) xSource2 = 176, y2 = y2 + 10;
        if (txGetAsyncKeyState      ('W')) xSource2 = 528, y2 = y2 - 10;

        printf ("� ���� ����� %d, ", xSource2);

        if (xSource2 > 11264 - 176) xSource2 = 0, printf ("�� ������ ���� ����� %d, ", xSource2);
        if (xSource2 < 0) xSource2 = 11264 - 176, printf ("c��� ����� ��� ����� %d, ", xSource2);

        printf ("� ���� ���������� %d\n", xSource2);

        txAlphaBlend (txDC (), x1, y1,  car, 0, car1, xSource1);

        txAlphaBlend (txDC (), x2, y2, carX, 0, car2, xSource2);

        txSleep (100);

        }
    }


