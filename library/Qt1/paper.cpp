#include "paper.h"

paper::paper()
{

}
void paper::addpaper(char *nam,char *writ,char * publish,char *tim)
{
       strcpy(p_name,nam);
       strcpy(writer,writ);
       num=++p_sum;
       strcpy(publisher,publish);
       strcpy(time,tim);
       position="D://library//nam.txt";
}

paper::~paper()
{

}

