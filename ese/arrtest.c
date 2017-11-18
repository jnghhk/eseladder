#include <stdio.h>

void print2DArray(int (*arr)[20], int col, int row)   // 매개변수를 포인터로 만든 뒤 가로 크기 지정
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[j][i]);
        }

        printf("\n");
    }
}

int main()
{
    int line;
    scanf("%d",&line);
    int numArr[20][line];
    int i,j;
    for(i=0;i<line;i++)
    {
       for(j=0;j<20;j++)
       {
          numArr[j][i]=i+j;
       }
      
    }

    int col = sizeof(numArr[0]) / sizeof(int);      // 5: 2차원 배열의 가로 크기를 구할 때는 
                                                    // 가로 한 줄을 요소의 크기로 나눠줌

    int row = sizeof(numArr) / sizeof(numArr[0]);    // 2: 2차원 배열의 세로 크기를 구할 때는 
                                       // 배열이 차지하는 공간을 가로 한 줄의 크기로 나눠줌

    print2DArray(numArr, col, row);    // 2차원 배열과 가로, 세로 크기를 넣음

    return 0;
}


