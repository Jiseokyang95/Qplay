#include <stdio.h>
#include  <stdlib.h>// rand 함수 사용
#include <time.h> // 시간을 통해 랜덤 사용

int RSP(){

    int com; // 컴퓨터가 낸 값을 저장합니다. 

    int user; // 사용자가 낸 값을 저장합니다. 

    int result[3] = {0, }; // 게임의 결과를 저장합니다.  result 배열의 모든 요소를 0으로 초기화합니다. 


    int cnt = 0; // 게임의 횟수를 저장합니다. 0으로 초기화합니다. 

    srand((unsigned)time(NULL)); // rand 함수의 결과가 매번 다르도록 시드값을 지정합니다. 

while(1) // 사용자가 종료할 때 까지 반복합니다. 

{ 

com = rand()%3+1; // 1~3 값 중 하나를 저장합니다. 

printf("**************** 가위 바위 보 게임 ****************\n"); 

printf("(1. 가위 _ 2. 바위 _ 3. 보 _ 0. 종료)\n\n"); 

printf("입력해주세요 : "); 

scanf("%d",&user); 

    if(user > 0 && user < 4) // 사용자가 1~3 값을 입력했을 경우입니다. 

    { 

    cnt++; // 정상적인 입력의 경우 게임 횟수를 증가시킵니다. 

    // 컴퓨터, 사용자가 낸 값에 따라 가위, 바위, 보 중 출력할 값을 선택합니다. 

    printf("\n컴퓨터 : %s\n", (com  == 1 ? "가위" : com  == 2 ? "바위" : "보")); 

    printf("사용자 : %s\n\n", (user == 1 ? "가위" : user == 2 ? "바위" : "보")); 

        if(com == user) // 컴퓨터의 값과 사용자의 값이 같으면 비기는 경우입니다. 

        { 

            printf("후.. 비겼습니다. \n\n");

            result[1]++; // 무승부 횟수를 증가시킵니다.

        }// 지는 경우의 수입니다. 

        else if(((com == 1) && (user == 3)) ||  //지는 조건

        ((com == 2) && (user == 1)) || 

        ((com == 3) && (user == 2))) 

        { 

            printf("졌습니다.ㅠㅠ\n\n"); 

            result[2]++; // 패배 횟수를 증가시킵니다. 

        } 

        else // 나머지는 이긴 경우입니다. 

        { 

            printf("ㅋㅋㅋ이겼습니다.\n\n"); 

            result[0]++; // 승리 횟수를 증가시킵니다. 

        } 

    printf("%d전 %d승 %d무 %d패\n\n", cnt, result[0], result[1], result[2]); 

    }


    else // 사용자가 입력한 값이 1, 2, 3이 아닌 경우 

    { 

        if(user == 0) // 사용자가 입력한 값이 0이면 종료합니다. 

        { 

        printf("게임을 종료합니다.\n");

        break; // 종료

        } // 그 외에는 예외처리 메세지 출력 

    printf("숫자를 제대로 입력해주세요\n\n"); 

    } 

system("pause"); // 일시정지 아무키나 누르면 진행됩니다. 

system("cls"); // 화면 내용을 모두 지웁니다. 

} 

return 0; 

} 

int main(){
    int number;
    printf("가위바위보 하고싶으면 1을 입력해주세요");
    scanf("%d",&number);
    if (number==1){
    RSP();    
    }
    
}

