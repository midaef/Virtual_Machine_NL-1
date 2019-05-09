
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int F(unsigned int m)
{
    m=(m<<28)|
      (m<<20&0x0F000000)|
      (m<<12&0x00F00000)|
      (m<<4&0x000F0000)|
      (m>>4&0x0000F000)|
      (m>>12&0x00000F00)|
      (m>>20&0x000000F0)|
      (m>>28);
    while((m&0x0F)==0)
        m=m>>4;
    return m;
}


char * strreverse(char* s)
{
    char *h,*t,ch;
    for (h=s,t=s+strlen(s)-1;h<t;++h,--t)
    {
        ch=*h;
        *h=*t;
        *t=ch;
    }
    return s;
}
 
unsigned int hexreverse(unsigned n)
{
    static char buf[16];
    sprintf(buf,"%x",n);
    sscanf(strreverse(buf),"%x",&n);
 
    return n;
}