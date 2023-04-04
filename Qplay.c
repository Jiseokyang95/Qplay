#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
	/*int life; // 라이프 생각하기 위해 추가
	life = 1;
	printf("게임을 시작합니다! \n게임의 순서는 아래와 같이 진행합니다. \n");
	printf(" 1 : 가위바위보\n 2 : 5지선다 문제\n 3 : 구구단\n 4 : 숫자야구\n 5 : Hangman\n 6 : UP&DOWN\n\n");
	printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
	getchar();*/
	int life = 10;
	int sub_life = life;
	int gold = 0;
	srand((unsigned)time(NULL));
	int givegold=0;
	system("clear");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                        ■\n");
	printf("■           수수께끼의 황금동굴          ■\n");
	printf("■                                        ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	sleep(3);
	system("clear");
	printf("\n\n\n\n당신은 인생역전을 할수 있다는 소문을 듣고 큰 꿈을 가지고 황금 동굴에 도착 했습니다\n");
	printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
	getchar();

	life = RSP(life);
	getchar();
	gold = gold1(gold, life, sub_life);
	sub_life = life;

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();

		life = question(life);
		gold = gold1(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();

		life = Multiplication(life);
		gold = gold1(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();

		life = number_baseball(life);
		gold = gold1(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();

		life = hangman(life);
			getchar();
		gold = gold1(gold, life, sub_life);
		givegold= rand()%10+1;
		gold = gold +givegold;
		printf("인질이 당신에게 고마움의 표시로 황금을 %d 개 주었습니다.\n", givegold);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();

		life = upanddown(life);
		getchar();
		gold = gold1(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");

		life = Timer(life);
		gold = gold1(gold, life, sub_life);
		sub_life = life;


		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("환한 빛이 당신에게 쏫아지는걸 느끼며 동굴의 출구가 보입니다 엔터를 눌러 동굴을 나가세요!\n\n");
		getchar();
	}

	system("clear");

	if (gold >= 50)
	{
		printf("당신은 %d개의 많은 황금을 얻었으며\n", gold);
	}
	else if (gold >= 30)
	{
		printf("당신은 %d개의 적당한 황금을 얻었으며\n", gold);
	}
	else
	{
		printf("당신은 굉장히 적은 %d개의 황금을 얻었으며\n", gold);
	}

	switch (life)
	{
	case 10:
	case 9:
	case 8:
		printf("몸까지 멀쩡합니다. 팔에 긁힌 자국이 남아 있지만 이 정도는 신경 쓸 필요도 없습니다. 당신은 건강하니까요.");
		break;

	case 7:
	case 6:
	case 5:
	case 4:
		printf("온갖 고통도 함께 얻었다. 셔츠는 피로 낭자하며 비가 오는 날엔 무릎이 시릴 것 입니다.");
		break;

	case 3:
	case 2:
	case 1:
		//
		if (gold > 7) // 많은 점수를 획득한 경우
		{
			printf("왼팔을 잃었지만 이 정도의 황금이라면 평생을 놀고 먹을수 있을 것이다. 의수 또한 가뿐히 맞추겠지 \n \"이왕이면 폼나는걸로\"");
		}
		//
		else if (gold > 5) // 적당한 점수를 획득한 경우
		{
			printf("왼팔을 잃었으며 발목이 시큰거린다 이 정도의 황금이라면 내 몸을 치료하고 소박하게 산다면 평생 놀 수 있지 않을까? \n후유증이 남겠지만 말이다");
		}

		else // 적은 점수를 획득한 경우
		{
			printf("왼팔을 잃었으며 온몸이 뻐근하다 당장이라도 쓰러질 것 같다 이 정도의 황금이라면 치료도 제대로 못 하겠지\n\"이곳에 오지 말아야 했는데\"");
		}
		break;
	}

	printf("\n\n\n게임 종료\n저희 게임을 플레이 해주셔서 감사합니다.\n최종일 , 양지석 ,박민혁 2023kosta프로젝트 완성본");

	if (life < 0)
	{
		printf("목숨이 없어서 게임이 끝났습니다...\n");
	}
}