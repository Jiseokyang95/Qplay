#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

int main()
{
    float reaction_time;
    clock_t start_time, end_time;

    srand(time(NULL));

    printf("순발력 게임을 시작합니다. 알림이 보이시면 엔터 키를 눌러주세요.\n");

    // 랜덤한 딜레이 시간 설정 (1~3초)
    int delay = rand() % 5 + 1;
    sleep(delay);

    printf("지금 바로 엔터 키를 누르세요!\n");
    start_time = clock();

    // 엔터 키 입력 대기
    getchar();

    end_time = clock();

    // 반응 속도 계산 (초 단위)
    reaction_time = (float)(end_time - start_time);

    // 오차 범위 설정
    double error_range = 0.2;
    printf("%ld\n %ld\n",start_time,end_time);
    printf("%f",reaction_time);



    if(reaction_time > 0.7)
    {
        printf("시간 초과! 반응 속도: %.2f초\n", reaction_time);
    }
    else
    {
        printf("성공! 반응 속도: %.2f초\n", reaction_time);
    }

    return 0;
}