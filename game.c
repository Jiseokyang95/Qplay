/*
<game.c>
1. 종합 게임 구현 함수
 - 가위,바위,보
 - 구구단
 - 5지선다 퀴즈
 - 순발력 게임
 - 행맨
 - 숫자야구
 - UP&DOWN
 2. 게임 패배시 main의 life 감소 구현
*/

#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>
#include <stdlib.h> // rand 함수 사용
#include <string.h>
#include <time.h> // 시간을 통해 랜덤 사용
#include <unistd.h>


/*
- gold1 함수 : 황금을 얻고 출력하는 함수
*/
int getgold(int gold, int life, int sub_life)
{
	int random;
	srand((unsigned)time(NULL));
	if (sub_life == life)
	{
		random = rand() % 7 + 2;
		gold = gold + random;
		printf("당신은 %d개의 황금을 얻었다.\n", random);
		return gold;
	}
	else if (sub_life == life - 1 || sub_life == life - 2)
	{
		random = rand() % 6 + 1;
		gold = gold + random;
		printf("당신은 %d개의 황금을 얻었다.\n", random);
		return gold;
	}
	else
	{
		random = rand() % 5 + 0;
		gold = gold + random;
		printf("당신은 %d개의 황금을 얻었다.\n", random);
		return gold;
	}
}
/*
- 가위바위보 게임
- 5판 게임 진행하여 이기면 황금을 얻고 다음게임으로 실행
*/
int RSP(int life)
{

	int com; // 컴퓨터가 낸 값을 저장합니다.

	int user; // 사용자가 낸 값을 저장합니다.

	int result[3] = {0}; // 게임의 결과를 저장합니다.  result 배열의 모든 요소를 0으로 초기화합니다.

	int cnt = 0; // 게임의 횟수를 저장합니다. 0으로 초기화합니다.

	srand((unsigned)time(NULL)); // rand 함수의 결과가 매번 다르도록 시드값을 지정합니다.

	printf("**************** 동굴인의 가위바위보 ****************\n\n");
	printf("동굴에 들어온 당신은 동굴인의 영역을 침범 했습니다.\n");
	printf("하지만 가위바위보를 무척 좋아하는 동굴인은 자신에게 가위바위보를 이긴다면 무사히 보내준다 합니다.\n");
	printf("가위바위보는 5판 진행 합니다.\n");
	printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
	getchar();

	while (1) // 사용자가 종료할 때 까지 반복합니다.

	{

		com = rand() % 3 + 1; // 1~3 값 중 하나를 저장합니다.

		printf("(1. 가위 _ 2. 바위 _ 3. 보 )\n\n");

		printf("입력해주세요 : ");

		scanf("%d", &user);

		if (user > 0 && user < 4) // 사용자가 1~3 값을 입력했을 경우입니다.

		{

			cnt++; // 정상적인 입력의 경우 게임 횟수를 증가시킵니다.

			// 컴퓨터, 사용자가 낸 값에 따라 가위, 바위, 보 중 출력할 값을 선택합니다.

			printf("\n동굴인 : %s\n", (com == 1 ? "가위" : com == 2 ? "바위"
												  : "보"));

			printf("사용자 : %s\n\n", (user == 1 ? "가위" : user == 2 ? "바위"
												    : "보"));

			if (com == user) // 컴퓨터의 값과 사용자의 값이 같으면 비기는 경우입니다.

			{

				printf("후.. 비겼습니다. \n\n");

				result[1]++; // 무승부 횟수를 증가시킵니다.

			} // 지는 경우의 수입니다.

			else if (((com == 1) && (user == 3)) || // 지는 조건

				   ((com == 2) && (user == 1)) ||

				   ((com == 3) && (user == 2)))

			{

				printf("졌습니다.ㅠㅠ\n\n");

				result[2]++; // 패배 횟수를 증가시킵니다.
			}

			else // 나머지는 이긴 경우입니다.

			{

				printf(" 축하합니다! 이겼습니다.\n\n");

				result[0]++; // 승리 횟수를 증가시킵니다.
			}

			printf("%d전 %d승 %d무 %d패\n\n", cnt, result[0], result[1], result[2]);
		}

		else // 사용자가 입력한 값이 1, 2, 3이 아닌 경우

		{

			printf("숫자를 제대로 입력해주세요\n\n");
		}
		if (cnt == 5 && result[0] > result[2])
		{
			printf("총 5판을 진행했습니다.\n");
			printf("%d전 %d승 %d무 %d패\n\n", cnt, result[0], result[1], result[2]);
			printf("오! 동굴인을 이기셨군요!\n");
			printf("\n위기를 넘기고 동굴 깊숙히 이동합니다 \n");
			return life;
		}
		else if (cnt == 5 && result[0] <= result[2] && life > 0)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("동굴인 한테 지셨네요 ㅋ\n");
			cnt = 0;
			life--; // 목숨 -1하도록하기
			printf("현재 당신의 목숨은 %d 입니다.\n", life);
			result[0] = 0;
			result[1] = 0;
			result[2] = 0;
		}

		else if (cnt == 5 && result[0] <= result[2] && life <= 0)
		{
			life--;
			printf("총 5판을 진행했습니다.\n");
			printf("목숨이 없네요... GG\n");
			return life;
		}
	}
	return 0;
}
/*
- 퀴즈 게임
- 5판 게임 진행하여 맞춘 문제가 틀린문제보다 많으면 다음게임을 실행
*/
int question(int life)
{
	int correct, fail; // 맞은 수,틀린수 출력
	int select;		 // 입력한 숫자
	correct = 0;
	fail = 0;

	printf("**************** 동굴의 수수께끼 ****************\n\n");
	printf("동굴을 계속 걷던 당신은 어디선가 들려오는 소리에 집중 합니다.\n");
	printf("\"동굴을 계속 나아가기 위해선 내 문제를 맞춰라\".\n");
	printf("당신은 5문제를 과반수 이상 맞춰야 합니다. 지금 바로 시작합니다! enter키를 눌러주세요~ \n");
	getchar();
	while (1)
	{
		while (1)
		{ // 1번 문제
			printf("1번 문제 우리 기수는 KOSTA 257기이다.\n");
			printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
			scanf("%d", &select);

			if (select == 1)
			{
				fail = ++fail;
				printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else if (select == 2)
			{
				correct = ++correct;
				printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else
			{
				printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
			}
		}

		while (1) // 2번 문제
		{
			printf("2번 문제 !\n강사님 성함은 '한경일' 이다.\n");
			printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
			scanf("%d", &select);
			if (select == 1)
			{
				correct = ++correct;
				printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else if (select == 2)
			{
				fail = ++fail;
				printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else
			{
				printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
			}
		}

		while (1) // 3번 문제
		{
			printf("3번문제\n 교육마지막 날짜는 7월 25일이다!\n");
			printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
			scanf("%d", &select);
			if (select == 1)
			{
				correct = ++correct;
				printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else if (select == 2)
			{
				fail = ++fail;
				printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else
			{
				printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
			}
		}

		while (1) // 4번 문제
		{
			printf("4번 문제\n if 문의 구조는 'if (조건문);' 이다.");
			printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
			scanf("%d", &select);

			if (select == 1)
			{
				fail = ++fail;
				printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}

			else if (select == 2)
			{
				correct = ++correct;
				printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}

			else
			{
				printf("잘못된 입력입니다  다시 입력해주세요! \n");
			}
		}

		while (1) // 5번 문제
		{
			printf("5번 문제\n C언어의 'do while'문은 반드시 한번 이상 실행한다.");
			printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
			scanf("%d", &select);

			if (select == 1)
			{
				correct = ++correct;
				printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else if (select == 2)
			{
				fail = ++fail;
				printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct, fail);
				break;
			}
			else
			{
				printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
			}
		}

		if (correct > fail)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("%d문제의 정답을 맞추셨습니다.\n", correct);
			printf("동굴을 계속 나아갑니다\n\n");
			getchar();
			return life;
		}
		else if (correct < fail && life > 0)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("당신은 과락입니다. 목숨을 잃습니다.\n\n");
			life--; // 목숨 -1하도록하기
			correct = 0;
			fail = 0;
		}

		else if (correct < fail && life <= 0)
		{
			life--;
			printf("총 5판을 진행했습니다.\n");
			printf("당신은 과락입니다.\n");
			return life;
		}
	}
}
/*
- 구구단 게임
- 5판 게임 진행하여 맞춘 문제가 틀린문제보다 많으면 다음게임을 실행
*/
int Multiplication(int life) // 3번 문제
{
	int firstnum, secondnum, answer, result;
	int count = 0;
	int correct = 0;
	int fail = 0;

	printf("**************** 똑똑한 고블린의 구구단****************\n\n");
	printf("갑자기 나타난 고블린이 당신의 목숨을 위협합니다.\n");
	printf("고블린\"나와의 구구단 승부에서 이긴다면 목숨만은 살려주지.\"\n");
	printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
	getchar();

	while (1)
	{
		while (1)
		{
			srand((unsigned)time(NULL));
			firstnum = rand() % 9 + 1;
			secondnum = rand() % 9 + 1;

			result = firstnum * secondnum;
			printf("%d * %d =", firstnum, secondnum);
			scanf("%d", &answer);

			if (answer == result)
			{
				count++;
				printf("%d번 정답을 맞추셨습니다.\n\n\n", count);
				correct++;
				break;
			}

			else
			{
				count++;
				printf("오답입니다.\n");
				printf("정답은 %d 입니다.\n\n", result);
				fail++;
				break;
			}
		}

		if (count == 5 && correct > fail)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("%d문제의 정답을 맞추셨습니다.\n", correct);
			printf("\n굶주린 똑똑한 고블린을 뒤로한 체 당신은 나아갑니다. \n\n");
			return life;
		}
		else if (count == 5 && correct < fail && life > 0)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("오늘은 고블린이 배가 부르겠군요. 목숨을 잃었습니다.\n다시 한번 해봅시다.\n\n");
			life--; // 목숨 -1하도록하기
			correct = 0;
			count = 0;
			fail = 0;
		}

		else if (count == 5 && correct < fail && life <= 0)
		{
			life--;
			printf("총 5판을 진행했습니다.\n");
			printf("당신은 죽었습니다.\n");
			return life;
		}
	}
	getchar();
	return 0;
}
/*
- 숫자야구 게임
- 9회안에 주어진 숫자를 맞추면 다음 게임으로 
*/
int number_baseball(int life)

{
quest:
	int computerBall[3]; // 컴퓨터의 볼을 저장할 int형 배열

	int i, j; // 반복을 위한 변수

	int temp; // 난수 중복 체크를 위한 변수

	int userBall[3]; // 사용자의 볼을 저장할 int형 배열

	int count = 1; // 회차를 확인할 변수 9회까지 가능

	int strike; // 스트라이크의 수를 세기 위한 변수

	int ball; // 볼의 수를 세기 위한 변수

	// 난수 생성 및 중복 체크

	srand((unsigned)time(NULL));

	for (i = 0; i < 3; i++)

	{

		temp = (rand() % 9) + 1; // temp변수에 현재 랜덤 값을 저장

		computerBall[i] = temp; // temp값을 컴퓨터의 볼에 저장

		for (j = 0; j < i; j++) // 현재 추가된 만큼 반복하며

			if (temp == computerBall[j] && i != j) // 만약 현재 temp값과 이전에 넣은 값 중 동일한 게 있다면

				i--; // i의 값을 줄여 다시 이전으로 돌아가도록
	}
	getchar();
	printf("**************** 피라냐 수족관 탈출 게임 ****************\n\n");
	printf("당신이 방에 들어서자 방안에 물이 차오르기 시작합니다.\n");
	printf("문의 암호를 맞춰 탈출 하세요.\n");
	printf("놀랍게도 암호문은 숫자 야구 게임으로 이루어져 있습니다!!!\n");
	printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
	getchar();

	while (1) // 숫자야구 게임 시작

	{

		printf("[%d회차 숫자야구]\n", count);

		while (1) // 정상적인 숫자만 입력받기 위한 반복

		{

			printf("1부터 9까지의 숫자를 한번씩 입력하세요 : \n");

			scanf("%d %d %d", &userBall[0], &userBall[1], &userBall[2]);

			if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9)

			{ // 입력한 숫자가 1 ~ 9 숫자가 아니면 다시 입력받도록

				printf("범위 외의 숫자를 입력하시면 안됩니다.\n");

				continue;
			}

			else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2])

			{ // 입력한 숫자 중에 중복된 게 있으면 다시 입력받도록

				printf("중복된 숫자를 입력하시면 안됩니다.\n");

				continue;
			}

			break; // 아무 문제 없을 경우 반복 종료
		}

		ball = 0;

		strike = 0;

		for (i = 0; i < 3; i++) // computerBall 1~3번째에 따라 각 userBall 1~3번째를 확인하기 위한 반복

			for (j = 0; j < 3; j++)

				if (computerBall[i] == userBall[j]) // computerBall과 userBall의 값이 같다면

					if (i == j) // 같은 위치일 경우

						strike++; // 스트라이크 개수 증가

					else // 다른 위치일 경우

						ball++; // 볼 개수 증가

		// 확인한 결과를 출력

		printf("[결과]스트라이크 : %d, 볼 : %d\n\n", strike, ball);

		if (strike == 3) // 만약 스트라이크 개수가 3개이면 승리

		{

			// printf("***** 승리했습니다. *****\n\n");
			printf("문을 열었습니다!!\n\n");
			return life;
		}

		else if (count == 9) // 만약 9회차인데도 승리하지 못하면 패배

		{

			printf("***** 실패했습니다.. 정답 : %d %d %d *****\n\n", computerBall[0], computerBall[1], computerBall[2]);
			life--;

			if (life >= 0)
			{
				goto quest;
			}
			else if (life < 0)
			{
				return life;
			}
		}

		count++;
	}

	getchar();
}

/*
- 행맨 게임에서 그림 출력을 위해 사용
*/

void hangmanpicture(int a)
{
	if (a == 6)
	{
		printf("┌────┐\n");
		printf("│    │\n");
		printf("│     \n");
		printf("│     \n");
		printf("│     \n");
		printf("┴     \n");
	}
	else if (a == 5)
	{
		printf("┌────┐\n");
		printf("│    │\n");
		printf("│    o\n");
		printf("│     \n");
		printf("│     \n");
		printf("┴     \n");
	}
	else if (a == 4)
	{
		printf("┌────┐\n");
		printf("│    │\n");
		printf("│    o\n");
		printf("│    ┼\n");
		printf("│     \n");
		printf("┴     \n");
	}
	else if (a == 3)
	{
		printf("┌────┐\n");
		printf("│    │\n");
		printf("│    o\n");
		printf("│    ┼-\n");
		printf("│     \n");
		printf("┴     \n");
	}
	else if (a == 2)
	{
		printf("┌────┐\n");
		printf("│    │\n");
		printf("│    o\n");
		printf("│   -┼-\n");
		printf("│     \n");
		printf("┴     \n");
	}
	else if (a == 1)
	{
		printf("┌────┐\n");
		printf("│    │ ┌────────────┐\n");
		printf("│    o<   HELP!!!!! │\n");
		printf("│   -┼-└────────────┘\n");
		printf("│   ┘ \n");
		printf("┴     \n");
	}
	else if (a == 0)
	{
		printf("┌────┐\n");
		printf("│    │\n");
		printf("│    o\n");
		printf("│   -┼-\n");
		printf("│   ┘ └\n");
		printf("┴     \n");
	}
}

/*
- 행맨 게임
- 6번의 기회안에 주어진 단어를 맞추면 다음단계로 이동
*/


int hangman(int life)
{

	while (1)
	{
		getchar();
		printf("**************** 식인종의 Hangman ****************\n\n");
		printf("식인종-\"내가 생각하는 과일을 맞춘다면 인질을 풀어줄 것이고 실패한다면 넌 죽을 것 이다.\"\n");
		printf("단어를 맞춰 인질을 구출하세요.\n");
		printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
		getchar();

		char blind[] = "______";
		char input;
		int try; // 횟수
		int key;
		int j; // j==글자수
		int chance = 6;
		int result = 0;

		srand(time(NULL));

		char word[5][7] = {"grapes", "citron", "cherry", "orange", "banana"};

		char *answer = word[rand() % 5];

		while (1)
		{
			try = 0;
			key = 0;

			printf("%s : \n", blind);
			printf("알파벳을 한글자씩 입력해주세요.\n");
			scanf(" %c", &input);

			// 입력 단어가 정답 문장에 있는지 확인
			for (int i = 0; i < 6; i++)
			{
				if (input == blind[i])
				{
					key = 1;
					printf("이미 등록한 문자입니다!! 재입력하세요!! \n");
					hangmanpicture(chance);
					break;
				}
				else if (input == answer[i])
				{
					blind[i] = input;
					try++;
				}
			}

			// 이미 등록한 문자라면 재입력 받아주기
			if (key == 1)
			{
				continue;
			}

			if (try == 0)
			{
				chance--;
				printf("기회가 %d번 남았습니다\n", chance);
				hangmanpicture(chance);
				if (chance == 0)
				{
					printf("실패\n");
					result = 0;
					break;
				}
			}

			// 모든 단어를 다 맞췄다면 정답을 출력하고 종료
			if (strcmp(blind, answer) == 0)
			{
				printf("%s\n", blind);
				printf("정답\n\n");
				result = 1;
				break;
			}
		}
		if (result == 1)
		{
			printf("인질을 무사히 구해내셨군요.\n\n");
			return life;
		}
		else if (result == 0 && life > 0)
		{
			printf("당신의 죽음을 인질또한 함께 할 것 입니다.\n");
			printf("게임을 다시 시작합니다. ㅋ\n\n");
			getchar();
			chance = 6;
			life--; // 목숨 -1하도록하기
		}

		else if (result == 0 && life <= 0)
		{
			life--;
			printf("당신은 죽었습니다.\n");
			return life;
		}
	}
	getchar();
}
/*
- 업앤다운 게임
- 10번의 기회안에 주어진 숫자를 맞추면 승리하는 게임
*/
int upanddown(int life)
{
	int rand_num = 0; // 랜덤값저장
	int input;
	int chance = 10;
	int result = 0;

	while (1)
	{
		printf("**************** 100개의 출구 UP&DOWN ****************\n\n");
		printf("동굴을 걷던 당신에게 100개의 출구가 나타났습니다.\n 진짜 출구는 1개 입니다.\n");
		printf("10번의 기회를 가지고 알맞은 출구로 탈출 해야합니다.\n");
		printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
		getchar();

		srand((unsigned int)time(NULL));
		rand_num = rand() % 100 + 1; // 0~100

		while (1)
		{
			if (chance == 0)
			{
				printf("실패\n");
				printf("정답은 %d 입니다.\n", rand_num);
				result = 0;
				break;
			}
			printf("숫자를 입력하세요(0~100)\n남은 기회 %d회\n", chance);
			scanf("%d", &input);

			if (input < 0 || input > 100)
			{
				printf("범위에 벗어난 숫자 입니다\n");
				// continue;
			}
			else if (input == rand_num)
			{
				printf("정답입니다.\n");
				result = 1;
				break;
			}
			else if (input > rand_num)
			{
				printf("\nDOWN 남은 기회 %d번 \n", chance);
				chance--;
			}
			else if (input < rand_num && input > 0 && input < 100)
			{
				printf("\nUP 남은 기회 %d번 \n", chance);
				chance--;
			}
			else
			{
				printf("숫자가 아닙니다");
			}
		}
		if (result == 1)
		{
			printf("당신은 %d 번째 통로로 유유히 빠져나갑니다.\n", rand_num);
			return life;
		}
		else if (result == 0 && life > 0)
		{
			printf("출구를 찾지 못해 당신의 목숨이 1 감소하였습니다.\n");
			printf("게임을 다시 시작하시려면 enter키를 눌러주세요. ㅋ\n\n");
			chance = 10;
			life--; // 목숨 -1하도록하기
		}

		else if (result == 0 && life <= 0)
		{
			life--;
			printf("당신은 죽었습니다.\n");
			return life;
		}
	}
	getchar();
}

int Timer(int life)
{

	clock_t start_time, end_time;
	struct timespec begin, end;
	long int reaction_time = 0;

	while (1)
	{
		getchar();
		printf("동굴 저 멀리 출구가 보입니다\n");
		printf("그 순간 발 밑의 딸깍거리는 소리와 함께 당신은 함정을 밟았다는걸 직감 합니다.\n");
		printf("알람이 표시된 후 0.7초 내 반응하세요.\n\n");
		printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
		getchar();
		srand(time(NULL));

		// 랜덤한 딜레이 시간 설정 (1~3초)
		int delay = rand() % 3 + 1;

		sleep(delay);

		clock_gettime(CLOCK_MONOTONIC, &begin);

		printf("지금 바로 엔터 키를 누르세요! 화살이 날라옵니다.\n");
		// 엔터 키 입력 대기
		getchar();

		clock_gettime(CLOCK_MONOTONIC, &end);

		// 반응 속도 계산 (초 단위)
		float time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

		if (time > 0.7 && life > 0)
		{
			printf("시간 초과! 반응 속도: %lf초\n", (double)time);
			printf("\"윽\" 화살에 맞았습니다. 당신의 목숨이 1 감소하였습니다.\n");
			printf("게임을 다시 시작하시려면 enter키를 눌러주세요. ㅋ\n\n");
			life--; // 목숨 -1하도록하기
		}
		else if (time <= 0.7)
		{
			printf("성공! 반응 속도: %lf초\n", (double)time);
			return life;
		}
		else if (time > 0.7 && life <= 0)
		{
			life--;
			printf("당신은 죽었습니다.\n");
			return life;
		}
	}
}
