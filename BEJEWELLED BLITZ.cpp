#include<iostream>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
#include"Header.h"
#include<ctime>

using namespace std;

int rowl1;        //stores row# of 1st gem if 3 identical gems occur consecutively in a row
int coll1;        //stores column# of 1st gem if 3 identical gems occur consecutively in a row
int rowl2;        //stores row# of 1st gem if 3 identical gems occur consecutively in a column
int coll2;        //stores column# of 1st gem if 3 identical gems occur consecutively in a column

//cout << "BOOOOM!!!!!" << endl;
int rowl14;       //stores row# of 1st gem if 4 identical gems occur consecutively in a row
int coll14;       //stores column# of 1st gem if 4 identical gems occur consecutively in a row
int rowl24;       //stores row# of 1st gem if 4 identical gems occur consecutively in a column
int coll24;       //stores column# of 1st gem if 4 identical gems occur consecutively in a column
bool flagR = 0;   //Becomes true only when 3 identical gems occur consecutively in a row
bool flagR1 = 0;  //Becomes true only when 4 identical gems occur consecutively in a row
bool flagC = 0;   //Becomes true only when 3 identical gems occur consecutively in a column
bool flagC1 = 0;  //Becomes true only when 4 identical gems occur consecutively in a column
int c;
int Score =0;
int shape1;
int shape2;

void isCursorKeyPressed(int whichKey)   //whichKey passed as reference.... 
{

	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		//cout << " LEFT   " << endl;
		c = 11;
		return;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		//cout << " UP   " << endl;
		c = 12;
		return;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		//cout << " RIGHT   " << endl;
		c = 13;
		return;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		//cout << " DOWN   " << endl;
		c = 14;
		return;
	}
	key = GetAsyncKeyState('W');
	if (key == 1)
	{
		c = 100;
		return;
	}
	key = GetAsyncKeyState('A');
	if (key == 1)
	{
		c = 101;
		return;
	}
	key = GetAsyncKeyState('S');
	if (key == 1)
	{
		c = 102;
		return;
	}
	key = GetAsyncKeyState('D');
	if (key == 1)
	{
		c = 103;
		return;
	}
	return;
}


 
void dropbottom(int array[][8], int row, int col)        //drops gems from above
{

	for (int i = row - 1; i > 0; i--)
	{
		array[i][col - 1] = array[i - 1][col - 1];
	}
	array[0][col - 1] = rand() % 5;
}

void currentBox(int x, int y)                            // Makes a golden box where the curser is 
{
	myLine1(x + 15, y + 15, x + 70, y + 15, 255, 215, 0);
	myLine1(x + 15, y + 15, x + 15, y + 70, 255, 215, 0);
	myLine1(x + 15, y + 70, x + 70, y + 70, 255, 215, 0);
	myLine1(x + 70, y + 15, x + 70, y + 70, 255, 215, 0);
}
void currentBoxb(int x, int y)                           //Makes a white box in location where current box was before
{
	/*myLine1(x + 15, y + 15, x + 115, y + 15, 255, 215, 255);
	myLine1(x + 15, y + 15, x + 15, y + 115, 255, 215, 255);
	myLine1(x + 15, y + 115, x + 115, y + 115, 255, 215, 255);
	myLine1(x + 115, y + 115, x + 115, y + 15, 255, 215, 255);*/
	myLine1(x + 15, y + 15, x + 70, y + 15, 255, 255, 255);
	myLine1(x + 15, y + 15, x + 15, y + 70, 255, 255, 255);
	myLine1(x + 15, y + 70, x + 70, y + 115, 255, 255, 255);
	myLine1(x + 70, y + 15, x + 70, y + 70, 255, 255, 255);
}
void same(int array[][8])                 //Searches for consecutive identical gems and changes values of flags accordingly
{
	flagR = 0;
	flagC = 0;
	flagR1 = 0;
	flagC1 = 0;
	for (int i = 8; i < 16; i++)
	{
		int count = 0;
		for (int j = 0; j < 6; j++)
		{
			//cout << "(" << i << "," << j << ")" << array[i][j] << "," << array[i][j + 1] << "," << array[i][j + 2] << endl;
			if (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2] && array[i][j] == array[i][j + 3])
			{
				flagR1 = 1;
				//cout << "BOOOOM!!!!!" << endl;
				rowl14 = i + 1;
				coll14 = j + 1;
				Score = Score + 100;
				shape1 = array[i][j]+5;
				
			}
			else if (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2] && flagR1==0)
			{
				flagR = 1;
				//cout << "BOOOOM!!!!!" << endl;
				rowl1 = i + 1;
				coll1 = j + 1;
				Score = Score + 50;
			}
		}
		//cout << "next ROW";
		//cout << endl;
	}
	//cout << "NOW FOR COLUMNS" << endl;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 8; i < 14; i++)
		{
			//cout << "(" << i << "," << j << ")" << array[i][j] << "," << array[i + 1][j] << "," << array[i + 2][j] << endl;
			if (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j] && array[i][j] == array[i + 3][j])
			{
				flagC1 = 1;
				rowl24 = i + 1;
				coll24 = j + 1;
				//cout << "BOOOOM!!!!!" << endl;
				Score = Score + 100;
				shape2 = array[i][j]+5;
				cout << shape2;
			}
			else if (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j] && flagC1==0)
			{
				flagC = 1;
				rowl2 = i + 1;
				coll2 = j + 1;
				//cout << "BOOOOM!!!!!" << endl;
				Score = Score + 50;
			}
		}
	}

}

void Triangle(int x, int y)//simple
{
	myLine1(x + 30, y + 50, x + 40, y + 30, 0,255,100);
	myLine1(x + 40, y + 30, x + 50, y + 50, 0,255,100);
	myLine1(x + 30, y + 50, x + 50, y + 50, 0,255,100);

}
void Triangle1(int x, int y) //special
{
	myLine1(x + 30, y + 50, x + 40, y + 30, 255, 255, 255);
	myLine1(x + 40, y + 30, x + 50, y + 50, 255, 255, 255);
	myLine1(x + 30, y + 50, x + 50, y + 50, 255, 255, 255);

}
void Diamond(int x, int y) //simple
{
	int x1 = 15;
	int y1;
	int x2 = 30;
	int y2 = x1 + 10;
	int x3 = 30;
	int y3 = x2;
	int x4 = 10;
	int y4 = x3;
	y1 = x4;
	myLine1(x + x1 + 10, y + y1 + 25, x + x2 + 25, y + y2 + 10, 0, 255, 100);
	myLine1(x + x2 + 25, y + y2 + 10, x + x3 + 10, y + y3 + 25, 0, 255, 100);         
	myLine1(x + x1 + 10, y + y1 + 25, x + x4 + 25, y + y4 + 10, 0, 255, 100);
	myLine1(x + x4 + 25, y + y4 + 10, x + x3 + 10, y + y3 + 25, 0, 255, 100); //do control z
	//myLine1(x + 30, y + 65, x + 65, y + 30, 255,0,0);
	//myLine1(x + 65, y + 30, x + 100, y + 65, 255,0,0);         
	//myLine1(x + 30, y + 65, x + 65, y + 100, 255,0,0);
	//myLine1(x + 65, y + 100, x + 100, y + 65, 255,0,0);
}
void Diamond1(int x, int y) //special
{
	int x1 = 15;
	int y1;
	int x2 = 30;
	int y2 = x1 + 10;
	int x3 = 30;
	int y3 = x2;
	int x4 = 10;
	int y4 = x3;
	y1 = x4;
	myLine1(x + x1 + 10, y + y1 + 25, x + x2 + 25, y + y2 + 10, 255,255,255);
	myLine1(x + x2 + 25, y + y2 + 10, x + x3 + 10, y + y3 + 25, 255,255,255);         //myRectangle(40, 40, 110, 110, 255, 255, 255);
	myLine1(x + x1 + 10, y + y1 + 25, x + x4 + 25, y + y4 + 10, 255,255,255);
	myLine1(x + x4 + 25, y + y4 + 10, x + x3 + 10, y + y3 + 25, 255,255,255);
}
void Hexagon(int x, int y) //simple
{
	myLine1(x + 20, y + 43, x + 30, y + 25, 255,0,255);
	myLine1(x + 20, y + 43, x + 30, y + 60, 255,0,255);
	myLine1(x + 30, y + 25, x + 50, y + 25, 255,0,255);
	myLine1(x + 30, y + 60, x + 50, y + 60, 255,0,255);
	myLine1(x + 50, y + 25, x + 60, y + 43, 255,0,255);
	myLine1(x + 50, y + 60, x + 60, y + 43, 255,0,255);

}
void Hexagon1(int x, int y) //special
{
	myLine1(x + 20, y + 43, x + 30, y + 25, 255, 255, 255);
	myLine1(x + 20, y + 43, x + 30, y + 60, 255, 255, 255);
	myLine1(x + 30, y + 25, x + 50, y + 25, 255, 255, 255);
	myLine1(x + 30, y + 60, x + 50, y + 60, 255, 255, 255);
	myLine1(x + 50, y + 25, x + 60, y + 43, 255, 255, 255);
	myLine1(x + 50, y + 60, x + 60, y + 43, 255, 255, 255);

}
void special(int x, int y) //special gem
{

	myRectangle(x + 15, y + 15, x + 115, y + 115, 255, 255, 255);
	myRectangle(x + 30, y + 30, x + 100, y + 100, 255, 0, 0);
	myEllipse(x + 30, y + 100, x + 100, y + 30, 255, 0, 0);
	//Triangle:-
	myLine(x + 40, y + 80, x + 65, y + 40, 255);
	myLine(x + 65, y + 40, x + 90, y + 80, 255);
	myLine(x + 40, y + 80, x + 90, y + 80, 255);

}

int main()
{
	

	int array[16][8];
	int x = 0;
	int y = 10;
	int x1 = 0;
	int y1 = 10;
	int i = 8;
	int i2 = 8;
	int j2 = 0;
	int j = 0;
	int temp;
	for (int i1 = 0; i1 < 16; i1++)
	{
		for (int j1 = 0; j1 < 8; j1++)
		{
			array[i1][j1] = rand() % 5;
		}
	}




	for (i = 8; i < 16; i++)             //Storing values of gems in array
	{

		x = 0;
		for (j = 0; j < 8; j++)
		{

			myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
			if (array[i][j] % 5 == 0)
				myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
			else if (array[i][j] % 5 == 1)
				myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
			else if (array[i][j] % 5 == 2)
				Diamond(x, y);
			else if (array[i][j] % 5 == 3)
				Triangle(x, y);
			else if (array[i][j] % 5 == 4)
				Hexagon(x, y);
			else if ((array[i][j] % 5)+1 == 5)
				myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 255, 255);
			else if ((array[i][j] % 5)+2 == 6)
				myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 255, 255);
			else if ((array[i][j] % 5)+3 == 7)
				Diamond1(x, y);
			else if ((array[i][j] % 5)+4 == 8)
				Triangle1(x, y);
			else if ((array[i][j] % 5)+5 == 9)
				Hexagon1(x, y);

			x = x + 55;
		}
		y = y + 55;
	}
	y = 10;
	int timer = 0;
	 
	while (timer<59)          //timer introduced for 1 minute
	{
		gotoxy(105, 0);
		timer = clock() / 1000;
		cout << timer<<"sec";
		currentBox(x1, y1);
		c = _getch();

		isCursorKeyPressed(c);
		int val = c;         //value for curser
		bool flag3 = 1;      //flag to check any same gems at the start of the game
		while (flag3)
		{
			Sleep(1);
			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;
			same(array);
			if (flagR1 == 1)
			{
				coll14 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl14, coll14);
					coll14++;
				}
				array[rowl14][coll14] = shape1;
			}
			else if (flagR == 1 && flagR1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl1, coll1);
					coll1++;
				}
			}
			else
			{
				flagR == 0;
				flagR1 == 0;
			}
			//for column
			if (flagC1 == 1)
			{
				rowl24 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl24, coll24);
					rowl24++;
				}
				array[rowl24][coll24] = shape2;
			}
			else if (flagC == 1 && flagC1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl2, coll2);
					rowl2++;
				}
			}
			else
			{
				flagC == 0;
				flagC1 == 0;
			}
			if (flagR == 0 && flagC == 0 && flagR1==0 && flagC1==0)
				flag3 = 0;
		}
		if (val == 13 && i2 >= 8 && j2 < 7) 
		{
			//cout << "VALUE OF val :" << val << " ";
			currentBoxb(x1, y1);
			j2++;
			x1 = x1 + 55;
			currentBox(x1, y1);

		}
		else if (val == 12 && i2 > 8) // && i2 > 8
		{
			//cout << "VALUE OF val :" << val << " ";
			currentBoxb(x1, y1);
			i2--;
			y1 = y1 - 55;
			currentBox(x1, y1);
		}
		else if (val == 11 && j2 > 0) //&& j2 < 0
		{
			//cout << "VaLUE OF val :" << val << " ";
			currentBoxb(x1, y1);
			j2--;
			x1 = x1 - 55;
			currentBox(x1, y1);
		}
		else if (val == 14 && i2 < 15) //&& i2 < 15
		{
			//cout << "VaLUE OF val :" << val << " ";
			currentBoxb(x1, y1);
			i2++;
			y1 = y1 + 55;
			currentBox(x1, y1);
		}
		else if (val == 100 && i2 > 8)         //Swapping with gem at top
		{
			//cout << "VaLUE :" << "W";

			temp = array[i2][j2];
			array[i2][j2] = array[i2 - 1][j2];
			array[i2 - 1][j2] = temp;

			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;

			same(array);  //Checks if smae gems appear in a row or column and then acts accordingly
			if (flagR1 == 1)
			{
				coll14 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl14, coll14);
					coll14++;
				}
				array[rowl14][coll14] = shape1;
			}
			else if (flagR == 1 && flagR1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl1, coll1);
					coll1++;
				}
			}
			//for column
			if (flagC1 == 1)
			{	
				rowl24 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl24, coll24);
					rowl24++;
				}
				array[rowl24][coll24] = shape2;
			}
			else if (flagC == 1 && flagC1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl2, coll2);
					rowl2++;
				}
			}
			
			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;
			if (flagR == 0 && flagC == 0 && flagR1==0 && flagC1==0)    //If all flags are false, undo the swap and reprints board
			{
				Sleep(1);
				temp = array[i2][j2];
				array[i2][j2] = array[i2 - 1][j2];
				array[i2 - 1][j2] = temp;
				for (i = 8; i < 16; i++)
				{

					x = 0;
					for (j = 0; j < 8; j++)
					{

						myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
						if (array[i][j] % 5 == 0)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
						else if (array[i][j] % 5 == 1)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
						else if (array[i][j] % 5 == 2)
							Diamond(x, y);
						else if (array[i][j] % 5 == 3)
							Triangle(x, y);
						else if (array[i][j] % 5 == 4)
							Hexagon(x, y);
						else if ((array[i][j] % 5) + 1 == 5)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
						else if ((array[i][j] % 5) + 2 == 6)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
						else if ((array[i][j] % 5) + 3 == 7)
							Diamond1(x, y);
						else if ((array[i][j] % 5) + 4 == 8)
							Triangle1(x, y);
						else if ((array[i][j] % 5) + 5 == 9)
							Hexagon1(x, y);

						x = x + 55;
					}
					y = y + 55;
				}
				y = 10;
			}
		}
		else if (val == 101 && j2 > 0)          //Swapping with gem on left
		{
			//cout << "VaLUE :" << "A";              

			temp = array[i2][j2];
			array[i2][j2] = array[i2][j2 - 1];
			array[i2][j2 - 1] = temp;

			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;
			same(array);
			if (flagR1 == 1)
			{
				coll14 = 0;
				for (int n = 0; n < 8; n++)
				{
					
					dropbottom(array, rowl14, coll14);
					coll14++;
				}
				array[rowl14][coll14] = shape1;
			}
			else if (flagR == 1 && flagR1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl1, coll1);
					coll1++;
				}
			}
			//for column
			if (flagC1 == 1)
			{
				rowl24 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl24, coll24);
					rowl24++;
				}
				array[rowl24][coll24] = shape2;
			}
			else if (flagC == 1 && flagC1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl2, coll2);
					rowl2++;
				}
			}
			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;

			if (flagR == 0 && flagC == 0 && flagR1==0 && flagC1==0)
			{
				Sleep(1);
				temp = array[i2][j2];
				array[i2][j2] = array[i2][j2 - 1];
				array[i2][j2 - 1] = temp;
				for (i = 8; i < 16; i++)
				{

					x = 0;
					for (j = 0; j < 8; j++)
					{

						myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
						if (array[i][j] % 5 == 0)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
						else if (array[i][j] % 5 == 1)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
						else if (array[i][j] % 5 == 2)
							Diamond(x, y);
						else if (array[i][j] % 5 == 3)
							Triangle(x, y);
						else if (array[i][j] % 5 == 4)
							Hexagon(x, y);
						else if ((array[i][j] % 5) + 1 == 5)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
						else if ((array[i][j] % 5) + 2 == 6)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
						else if ((array[i][j] % 5) + 3 == 7)
							Diamond1(x, y);
						else if ((array[i][j] % 5) + 4 == 8)
							Triangle1(x, y);
						else if ((array[i][j] % 5) + 5 == 9)
							Hexagon1(x, y);

						x = x + 55;
					}
					y = y + 55;
				}
				y = 10;
			}
		}
		else if (val == 102 && i2 < 15)        //Swapping with gem at bottom
		{
			//cout << "VaLUE :" << "S";       

			temp = array[i2][j2];
			array[i2][j2] = array[i2 + 1][j2];
			array[i2 + 1][j2] = temp;

			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;

			same(array);
			if (flagR1 == 1)
			{
				coll14 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl14, coll14);
					coll14++;
				}
				array[rowl14-3][coll14-1] = shape1;

			}
			else if (flagR == 1 && flagR1==0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl1, coll1);
					coll1++;
				}
			}

			//for column
			if (flagC1 == 1)
			{
				rowl24 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl24, coll24);
					rowl24++;
				}
				array[rowl24][coll24] = shape2;
			}
			else if (flagC == 1 && flagC1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl2, coll2);
					rowl2++;
				}
			}
			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;
			if (flagR == 0 && flagC == 0 && flagR1==0 && flagC1==0)
			{
				Sleep(1);
				temp = array[i2][j2];
				array[i2][j2] = array[i2 + 1][j2];
				array[i2 + 1][j2] = temp;
				for (i = 8; i < 16; i++)
				{

					x = 0;
					for (j = 0; j < 8; j++)
					{

						myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
						if (array[i][j] % 5 == 0)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
						else if (array[i][j] % 5 == 1)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
						else if (array[i][j] % 5 == 2)
							Diamond(x, y);
						else if (array[i][j] % 5 == 3)
							Triangle(x, y);
						else if (array[i][j] % 5 == 4)
							Hexagon(x, y);
						else if ((array[i][j] % 5) + 1 == 5)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
						else if ((array[i][j] % 5) + 2 == 6)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
						else if ((array[i][j] % 5) + 3 == 7)
							Diamond1(x, y);
						else if ((array[i][j] % 5) + 4 == 8)
							Triangle1(x, y);
						else if ((array[i][j] % 5) + 5 == 9)
							Hexagon1(x, y);

						x = x + 55;
					}
					y = y + 55;
				}
				y = 10;
			}
		}
		else if (val == 103 && j2 < 7)             //Swapping with gem on right
		{
			//cout << "VALUE :" << "D";              

			temp = array[i2][j2];
			array[i2][j2] = array[i2][j2 + 1];
			array[i2][j2 + 1] = temp;

			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;
			same(array);
			if (flagR1 == 1)
			{
				coll14 = 0;
				for (int n = 0; n < 8; n++)
				{
					dropbottom(array, rowl14, coll14);
					coll14++;
				}
				array[rowl14][coll14] = shape1;
			}
			else if (flagR == 1 && flagR1 == 0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl1, coll1);
					coll1++;
				}
			}
			//for column
			if (flagC1 == 1)
			{
				rowl24 = 0;
				for (int n = 0; n <8 ; n++)
				{
					dropbottom(array, rowl24, coll24);
					rowl24++;
				}
				
			}
			else if (flagC == 1 && flagC1==0)
			{
				for (int n = 0; n < 3; n++)
				{
					dropbottom(array, rowl2, coll2);
					rowl2++;
				}
			}
			for (i = 8; i < 16; i++)
			{

				x = 0;
				for (j = 0; j < 8; j++)
				{

					myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
					if (array[i][j] % 5 == 0)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
					else if (array[i][j] % 5 == 1)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
					else if (array[i][j] % 5 == 2)
						Diamond(x, y);
					else if (array[i][j] % 5 == 3)
						Triangle(x, y);
					else if (array[i][j] % 5 == 4)
						Hexagon(x, y);
					else if ((array[i][j] % 5) + 1 == 5)
						myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
					else if ((array[i][j] % 5) + 2 == 6)
						myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
					else if ((array[i][j] % 5) + 3 == 7)
						Diamond1(x, y);
					else if ((array[i][j] % 5) + 4 == 8)
						Triangle1(x, y);
					else if ((array[i][j] % 5) + 5 == 9)
						Hexagon1(x, y);

					x = x + 55;
				}
				y = y + 55;
			}
			y = 10;
			if (flagR == 0 && flagC == 0 && flagR1==0 && flagC1==0)
			{
				Sleep(1);
				temp = array[i2][j2];
				array[i2][j2] = array[i2][j2 + 1];
				array[i2][j2 + 1] = temp;
				for (i = 8; i < 16; i++)
				{

					x = 0;
					for (j = 0; j < 8; j++)
					{

						myRectangle(x + 15, y + 15, x + 70, y + 70, 255, 255, 255);
						if (array[i][j] % 5 == 0)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 0, 0);
						else if (array[i][j] % 5 == 1)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 0, 0);
						else if (array[i][j] % 5 == 2)
							Diamond(x, y);
						else if (array[i][j] % 5 == 3)
							Triangle(x, y);
						else if (array[i][j] % 5 == 4)
							Hexagon(x, y);
						else if ((array[i][j] % 5) + 1 == 5)
							myRectangle(x + 30, y + 30, x + 50, y + 50, 255, 87, 51);
						else if ((array[i][j] % 5) + 2 == 6)
							myEllipse(x + 30, y + 50, x + 50, y + 30, 255, 87, 51);
						else if ((array[i][j] % 5) + 3 == 7)
							Diamond1(x, y);
						else if ((array[i][j] % 5) + 4 == 8)
							Triangle1(x, y);
						else if ((array[i][j] % 5) + 5 == 9)
							Hexagon1(x, y);

						x = x + 55;
					}
					y = y + 55;
				}
				y = 10;
			}
		}

		gotoxy(105, 1);
		cout << "SCORE = " << Score << "\r";         

	}
	system("CLS");
	cout << "YOUR SCORE IS:" << Score<<endl;
	cout << "Thank You for playing";

	_getch();
	system("pause");
	return 0;


}