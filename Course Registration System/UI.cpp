#include "UI.h"
using namespace std;

void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void drawTable(int firstW, int firstH, int finalW, int finalH)
{
	SetBGColor(14);
	SetColor(13);
	for (int i = 0; i < firstW; ++i)
		for (int j = 0; j < firstH; ++j)
		{
			gotoxy(i + finalW, j + finalH);
			cout << " ";
		}
	SetBGColor(0);
	gotoxy(finalW - 1, finalH - 1);
	cout << '\xDA';
	gotoxy(firstW + finalW, finalH - 1);
	cout << '\xBF';
	gotoxy(finalW - 1, firstH + finalH);
	cout << '\xC0';
	gotoxy(firstW + finalW, firstH + finalH);
	cout << '\xD9';
	for (int i = 0; i < firstH; i++)
	{
		gotoxy(finalW - 1, i + finalH);
		cout << '\xB3';
		gotoxy(finalW + finalW, i + finalH);
		cout << '\xB3';
	}
	for (int j = 0; j < firstW; j++)
	{
		gotoxy(j + finalW, finalH - 1);
		cout << '\xC4';
		gotoxy(j + finalW, finalH + firstH);
		cout << '\xC4';
	}
}