#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Multiplication()
{
      int firstnum, secondnum, answer, result;
      int count = 0;

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
                  printf("%d번 정답을 맞추셨습니다.\n\n\n", count+1);
                  ++count;
            }

            else
            {
                  printf("오답입니다.\n");
                  printf("정답은 %d 입니다.\n\n", result);
            }

            if (count == 5)
            {
                  printf("5문제 모두 맞추셨습니다. 축하합니다!\n\n\n");
                  break;
            }
      }
}

int main()
{
      int gamenum = 0;
      printf("구구단 게임을 하고싶으면 3을 입력해주세요. :");
      scanf("%d", &gamenum);

      if (gamenum == 3)
      {
            Multiplication();
      }
}
