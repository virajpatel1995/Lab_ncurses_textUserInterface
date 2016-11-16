#include "about.h"

CLab06::CLab06()
{
  m_strText = NULL;
}

// Read Text File
int CLab06::OpenFile(char *filename)
{
  FILE *fp = NULL;
  fp = fopen(filename, "rb");
  if (fp == NULL)
  {
    return 1;
  }
  
  // Get the Size of the File.
  fseek(fp, 0, SEEK_END);
  long int nSize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  
  // Allocate the Table
  m_strText = (char*) malloc(nSize + 1);
  
  // Initialize the String - Contents of the File.
  memset(m_strText, 0, nSize + 1);
  
  // Read the Text File
  nSize = fread(m_strText, 1, nSize, fp);
  if (nSize == 0)
  {
    return 2;
  }
  
  return 0;  
}

// Display the Text Contents
void CLab06::Display()
{
  printw(m_strText);
}

// Free the alloacted Memory
void CLab06::Unalloc()
{
  // if Not Allocate, then mustn't be free.
  if (m_strText == NULL)
    return;
  
  free(m_strText);
}

// Main Function
int main(int argc, char* argv[])
{
  initscr();			/* Start curses mode 		  */
  refresh();			/* Print it on to the real screen */
  
  CLab06 lab06;
    
  // If there is any command Line
  char str[1024] = "";
  if (argc == 2)
  {
    strcpy(str, argv[1]);
  }
  
  while (true)
  {
    // No command Line
    if (strcmp(str, "") == 0)
    {
      printw("Please Enter the File Path : ");
      getstr(str);
    }
    
    int nRet = lab06.OpenFile(str);
    if (nRet == 0)	// Successfully Read
    {
      lab06.Display();
      break;
    }
    else if (nRet == 1)	// No File
    {
      printw("File Not Found : ");
      printw(str);
      printw("\n");
      strcpy(str, "");
    }
    else if (nRet == 2)	// No Data
    {
      printw("Error Occured in Reading Data From : ");
      printw(str);
      printw("\n");
      break;
    }
  }  
  
  
  getch();  
  endwin();			/* End curses mode		  */

  return 0;
}

