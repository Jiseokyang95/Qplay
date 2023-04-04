#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
int main()
{

    clock_t start_time, end_time;
	struct timespec  begin, end;
	long int reaction_time = 0;

    srand(time(NULL));

    printf("순발력 게임을 시작합니다. 알림이 보이시면 엔터 키를 눌러주세요.\n");

    // 랜덤한 딜레이 시간 설정 (1~3초)
    int delay = rand() % 5 + 1;


	
    sleep(delay);

	clock_gettime(CLOCK_MONOTONIC, &begin);


    printf("지금 바로 엔터 키를 누르세요!\n");
    // 엔터 키 입력 대기
    getchar();

    clock_gettime(CLOCK_MONOTONIC, &end);

    // 반응 속도 계산 (초 단위)
	float time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;



    if(time > 0.7)
    {
        printf("시간 초과! 반응 속도: %lf초\n", (double)time);
    }
    else
    {
        printf("성공! 반응 속도: %lf초\n", (double)time);
    }

    return 0;
}
