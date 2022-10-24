// Had_2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lod.h"


HANDLE  hConsoleOut;                   /* Handle ke konzolovemu oknu */
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;   /* informace o konzolovem okne */


void PrintXY(int x,int y,char *str) {
 COORD coord;
 DWORD written;

	coord.X=x;
	coord.Y=y;

	WriteConsoleOutputCharacter(hConsoleOut,str,(DWORD)strlen(str),coord,&written);

}

// *** smaze konzolovou obrazovku
void ClearScreen( void )
{
    DWORD    dummy;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacter( hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy );
}


int _tmain(int argc, _TCHAR* argv[])
{
    /* Otevreme konzolove okno a ziskame informace o jejich parametrech.*/
    hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );

	ClearScreen();

	CLod lod;
	bool konec=false;
    
    
	do {
		konec = lod.Pohni();
		lod.Zobraz();
	} while(konec==false);




   printf("Stiskni cokoliv pro ukonceni aplikace ...\n");
   while( !_kbhit() );


   return 0;
}
