/*
게임 이름 : Qplay
제작 기간 : 2023.03.30 ~ 2023.04.07
게임 목적 : 여러가지 종합게임을 구현하고, 이를 Stage별 Clear하면서 Player의 순위를 기록, 비교하는 게임
개발 환경 : C언어, Ubuntu
Git hub : gh repo clone Jiseokyang95/Qplay
작 성 자 : 최종일, 박민혁, 양지석
*/

/*
<Qplay.c - Main.c>
1. 게임 Background 설정
2. Player data 기록
3. 제한 Life 생성
4. 게임 순서 구현
*/
#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include "rank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
	int life = 10;
	int sub_life = life;
	int gold = 0;
	srand((unsigned)time(NULL));
	int givegold = 0;
	char name[MAX_NAME_LENGTH];
	int score;

	Leaderboard leaderboard = {0};
	ntmp ntmp = {0};

	system("clear");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                        ■\n");
	printf("■           수수께끼의 황금동굴          ■\n");
	printf("■                                        ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	sleep(3);
	system("clear");

	load_leaderboard(&leaderboard);
	printf("수수께기 황금 동굴을 들어가려는 당신의 이름은 : ");
	scanf("%s", name);
	system("clear");

	printf("\n\n\n\n당신은 인생역전을 할수 있다는 소문을 듣고 큰 꿈을 가지고 황금 동굴에 도착 했습니다\n");
	printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
	getchar();

	life = RSP(life);
	getchar();
	gold = getgold(gold, life, sub_life);
	sub_life = life;
	system("clear");

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		system("clear");

		life = question(life);
		gold = getgold(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		system("clear");

		life = Multiplication(life);
		gold = getgold(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		system("clear");

		life = number_baseball(life);
		gold = getgold(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		system("clear");

		life = hangman(life);
		getchar();
		gold = getgold(gold, life, sub_life);
		givegold = rand() % 10 + 1;
		gold = gold + givegold;
		printf("인질이 당신에게 고마움의 표시로 황금을 %d 개 주었습니다.\n", givegold);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		system("clear");

		life = upanddown(life);
		getchar();
		gold = getgold(gold, life, sub_life);
		sub_life = life;
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("현재 당신의 황금은 : %d입니다.\n", gold);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");

		life = Timer(life);
		gold = getgold(gold, life, sub_life);
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

	if (life < 0)
	{
		printf("목숨이 없어서 게임이 끝났습니다...\n");
	}

	printf("\n게임 종료\n");

	score = gold;

	add_player(&leaderboard, name, score);

	save_leaderboard(leaderboard);

	int i = 0, j = 0, nLeast = 0;

	for (i = 0; i < MAX_PLAYERS; ++i) // 선택 배열의 왼쪽부터 자리 정렬
	{
		nLeast = i;
		for (j = i + 1; j < MAX_PLAYERS; ++j) // 왼쪽 한자리 정렬을 완료하기 위한 내부 반복문
		{
			if (leaderboard.players[nLeast].score < leaderboard.players[j].score) // 큰수부터 저장을 위해선 (<) 로 변경
				nLeast = j;
		}

		ntmp.ntmp_players[i] = leaderboard.players[i];		// 교환 전 변수값 임시저장
		leaderboard.players[i] = leaderboard.players[nLeast]; // 변수값 교환
		leaderboard.players[nLeast] = ntmp.ntmp_players[i];
	}
	printf("\n순위표:\n");
	print_leaderboard(leaderboard);

	printf("\n저희 게임을 플레이 해주셔서 감사합니다.\n최종일 , 양지석 ,박민혁\n 2023kosta프로젝트 완성본");

	return 0;
}
