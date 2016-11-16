
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Error Control Defines
#define NO_ERROR	0
#define FILE_NOT_FOUND	1
#define READING_ERROR	2

#define MAX_PATH_LEN	1024


class CLab06
{
private:
  char*	m_strText;
  
public:
  CLab06();
  int 	OpenFile(char *filename);
  void 	Display();
  void 	Unalloc();
};