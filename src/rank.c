/*
<rank.c>
1. LeaderBoard 파일 생성 및 저장
2. LeaderBoard 파일 출력
*/

#include <stdio.h>
#include "rank.h"
#include <stdlib.h>
#include <string.h>

// 순위 파일에서 정보를 읽어와 순위 구조체에 저장하는 함수
void load_leaderboard(Leaderboard *leaderboard)
{
    FILE *fp;
    fp = fopen("leaderboard.txt", "r");

    if (fp == NULL)
    {
        printf("순위 파일을 열 수 없습니다.\n");
        return;
    }

    fscanf(fp, "%d", &leaderboard->num_players);

    for (int i = 0; i < leaderboard->num_players; i++)
    {
        fscanf(fp, "%s %d", leaderboard->players[i].name, &leaderboard->players[i].score);
    }

    fclose(fp);
}

// 순위 구조체의 정보를 파일에 저장하는 함수
void save_leaderboard(Leaderboard leaderboard)
{
    FILE *fp;
    fp = fopen("leaderboard.txt", "w");

    if (fp == NULL)
    {
        printf("순위 파일을 열 수 없습니다.\n");
        return;
    }

    fprintf(fp, "%d\n", leaderboard.num_players);

    for (int i = 0; i < leaderboard.num_players; i++)
    {
        fprintf(fp, "%s %d\n", leaderboard.players[i].name, leaderboard.players[i].score);
    }

    fclose(fp);
}

// 새로운 플레이어를 순위 구조체에 추가하는 함수
void add_player(Leaderboard *leaderboard, char *name, int score)
{
    if (leaderboard->num_players >= MAX_PLAYERS)
    {
        printf("더 이상 플레이어를 추가할 수 없습니다.\n");
        return;
    }

    strcpy(leaderboard->players[leaderboard->num_players].name, name);
    leaderboard->players[leaderboard->num_players].score = score;
    leaderboard->num_players++;
}

// 순위 구조체를 출력하는 함수
void print_leaderboard(Leaderboard leaderboard)
{
    printf("순위\t이름\t점수\n");

    for (int i = 0; i < leaderboard.num_players; i++)
    {
        printf("%d\t%s\t%d\n", i + 1, leaderboard.players[i].name, leaderboard.players[i].score);
    }
}