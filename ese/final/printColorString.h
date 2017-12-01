#ifndef PRINTCOLORSTRING_H
#define PRINTCOLORSTRING_H
#include<stdio.h>
void printColorString(int color, char * str) 
{
	printf("\033[%dm%s\033[0m", color, str);
	/*
	0 : 모든 색과 스타일 초기화
1 : 굵게(bold) / 밝게
3 : 이탤릭체(italic)
4 : 밑줄(underline)
7 : 반전(글자색/배경색을 거꾸로)
9 : 가로줄 치기
22 : 굵게(bold) 제거
23 : 이탤릭체(italic)제거
24 : 밑줄(underline)제거
27 : 반전 제거
29 : 가로줄 제거
30 : 글자색:검정
31 : 글자색:빨강
32 : 글자색:초록
33 : 글자색:노랑
34 : 글자색:파랑
35 : 글자색:마젠트(분홍)
36 : 글자색:시안(청록)
37 : 글자색:백색
39 : 글자색으로 기본값으로
40 : 바탕색:흑색
41 : 바탕색:적색
42 : 바탕색:녹색
43 : 바탕색:황색
44 : 바탕색:청색
45 : 바탕색:분홍색
46 : 바탕색:청록색
47 : 바탕색:흰색
49 : 바탕색을 기본값으로
*/
}
#endif