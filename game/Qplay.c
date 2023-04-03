#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand 함수 사용
#include <time.h>	  // 시간을 통해 랜덤 사용

int RSP(int life)
{

	int com; // 컴퓨터가 낸 값을 저장합니다.

	int user; // 사용자가 낸 값을 저장합니다.

	int result[3] = {
	    0,
	}; // 게임의 결과를 저장합니다.  result 배열의 모든 요소를 0으로 초기화합니다.

	int cnt = 0; // 게임의 횟수를 저장합니다. 0으로 초기화합니다.

	srand((unsigned)time(NULL)); // rand 함수의 결과가 매번 다르도록 시드값을 지정합니다.
	printf("**************** 가위 바위 보 게임 ****************\n\n");
	printf("총 5판을 진행하고 승리가 더 많아야 다음게임으로 이동이 가능합니다 ㅎㅎㅎㅎ\n\n");
	printf("컴퓨터한테 지는 바보는 없겠죠 ㅎㅎ?? \n");
	printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
	printf("%d", life);
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

			printf("\n컴퓨터 : %s\n", (com == 1 ? "가위" : com == 2 ? "바위"
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
			printf("\n게임하시느라 고생많았습니다. 다음게임으로 이동합니다 \n");
			return life;
		}
		else if (cnt == 5 && result[0] <= result[2] && life > 0)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("컴퓨터한테 지셨네요 ㅋ\n");
			cnt = 0;
			life--; // 목숨 -1하도록하기
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

int question(int life)
{
	int correct, fail; // 맞은 수,틀린수 출력
	int select;		 // 입력한 숫자
	correct = 0;
	fail = 0;

	printf("**************** 5지선다 Quiz ****************\n\n");
	printf("현재 당신의 목숨은 %d입니다.\n", life);
	printf("총 5판을 진행하고 맞춘 문제가 더 많아야 다음게임으로 이동이 가능합니다 ㅎㅎㅎㅎ\n\n");
	printf("이걸 틀리는 바보는 없겠죠 ㅎㅎ?? \n");
	printf("지금 바로 시작합니다! enter키를 눌러주세요~ \n");
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
			printf("%d문제의 정답을 맞추셨습니다.\n");
			printf("\n게임하시느라 고생많았습니다. 다음게임으로 이동합니다 \n");
			return life;
		}
		else if (correct < fail && life > 0)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("당신은 과락입니다. ㅋ\n");
			life--; // 목숨 -1하도록하기
			correct = 0;
			fail = 0;
		}

		else if (correct < fail && life <= 0)
		{
			life--;
			printf("총 5판을 진행했습니다.\n");
			printf("당신은 과락입니다. ㅋ\n");
			return life;
		}
	}
}

int Multiplication(int life) // 3번 문제
{
	int firstnum, secondnum, answer, result;
	int count = 0;
	int correct = 0;
	int fail = 0;

	printf("**************** 구구단 게임 ****************\n\n");
	printf("현재 당신의 목숨은 %d입니다.\n", life);
	printf("총 5판을 진행하고 맞춘 문제가 더 많아야 다음게임으로 이동이 가능합니다 ㅎㅎㅎㅎ\n\n");
	printf("이걸 틀리는 바보는 없겠죠 ㅎㅎ?? \n");
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
			printf("\n게임하시느라 고생많았습니다. 다음게임으로 이동합니다 \n");
			return life;
		}
		else if (count == 5 && correct < fail && life > 0)
		{
			printf("총 5판을 진행했습니다.\n");
			printf("당신은 과락입니다. ㅋ\n\n");
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
}

int number_baseball(int life)

{

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

	printf("**************** 숫자야구 게임 ****************\n\n");
	printf("현재 당신의 목숨은 %d입니다.\n", life);
	printf("3자리의 숫자를 9회 안에 모두 맞추셔야합니다.\n\n");
	printf("이걸 못하지는 않겠죠 ㅎㅎ?? \n");
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

			printf("***** 승리했습니다. *****\n\n");

			break;
		}

		else if (count == 9) // 만약 9회차인데도 승리하지 못하면 패배

		{

			printf("***** 패배했습니다.. 정답 : %d %d %d *****\n\n", computerBall[0], computerBall[1], computerBall[2]);

			break;
		}

		count++;
	}

	return 0;
}

int hangman()
{
	srand(time(NULL));

	char word[5][7] = {"grapes", "citron", "cherry", "orange", "banana"};

	char *answer = word[rand() % 5];
	char blind[] = "______";
	char input;
	int try; // 횟수
	int key;

	int j; // j==글자수
	int chance = 12;

	while (1)
	{
		try = 0;
		key = 0;

		printf("%s : \n", blind);
		printf("Hint: 과일\n");
		scanf(" %c", &input);

		// 입력 단어가 정답 문장에 있는지 확인
		for (int i = 0; i < 6; i++)
		{
			if (input == blind[i])
			{
				key = 1;
				printf("이미 등록한 문자입니다!! 재입력하세요!! \n");
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

		// 하나도 없으면 목숨 1개 잃음. 3개 잃으면 게임 오버
		if (try == 0)
		{
			chance--;
			printf("기회가 %d번 남았습니다\n", chance);
			if (chance == 0)
			{
				printf("실패\n");
				break;
			}
		}

		// 모든 단어를 다 맞췄다면 정답을 출력하고 종료
		if (strcmp(blind, answer) == 0)
		{
			printf("%s\n", blind);
			printf("정답");
			break;
		}
	}
}

int upanddown()
{
	int rand_num = 0; // 랜덤값저장
	int input;
	int chance = 10;

	srand((unsigned int)time(NULL));
	rand_num = rand() % 100 + 1; // 0~100

	while (1)
	{
		if (chance == 0)
		{
			printf("실패\n");
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
			break;
		}
		else if (input > rand_num)
		{
			printf("DOWN\n");
			chance--;
		}
		else if (input < rand_num && input > 0 && input < 100)
		{
			printf("UP\n");
			chance--;
		}
		else
		{
			printf("숫자가 아닙니다");
		}
	}
}

int main()
{
	int life; // 라이프 생각하기 위해 추가
	life = 1;
	printf("게임을 시작합니다! \n게임의 순서는 \n");
	printf("1 : 가위바위보 2: 객관식 문제 3: 구구단 4:숫자야구 5:단어맞추기 6:업앤다운 으로 진행합니다\n");
	printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
	getchar();

	// life = RSP(life);

	// printf("현재 당신의 목숨은 : %d입니다.\n", life);
	// printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
	// getchar();

	/*if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		life = question(life);
	}*/

	/*if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		life = Multiplication(life);
	}*/

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		life = number_baseball(life);
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		life = hangman(life);
	}

	if (life >= 0)
	{
		printf("현재 당신의 목숨은 : %d입니다.\n", life);
		printf("준비가 되었다면 enter키를 눌러주세요!\n\n");
		getchar();
		life = upanddown(life);
	}

	if (life < 0)
	{
		printf("목숨이 없어서 게임이 끝났습니다...");
	}
}
