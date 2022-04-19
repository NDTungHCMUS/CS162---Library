#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h> 
#include <fstream>
#include <algorithm>

void SetBGColor(WORD color);
void SetColor(WORD color);
void gotoxy(short x, short y);
void drawTable(int firstW, int firstH, int finalW, int finalH);