#include <windows.h>
#include <stdio.h>
int main()
{
    printf("現在在playsound()前\n");
    PlaySound("0530.wav",NULL,SND_ASYNC);
    printf("現在在playsound()後\n");
    int N;
    scanf("%d",&N);
}

