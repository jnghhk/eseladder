#ifndef START_H
#define START_H
void gotoxy(int x,int y);
void printColorString(int color ,char *str);
void printmap(int **MAP,int line);
void startprint(int l,int i,int j,int **MAP);
void start(int **MAP,int line);
#endif
