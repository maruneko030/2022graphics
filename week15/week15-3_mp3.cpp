#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("0530.mp3");
    mp3.Play();
    printf("現在正在播放罐頭笑聲\n");
    int N;
    scanf("%d",&N);
}
