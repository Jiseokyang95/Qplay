### Qplay
1. 게임 이름 : Qplay
2. 제작 기간 : 2023.03.30 ~ 2023.04.07
3. 게임 목적 : 여러가지 종합게임을 구현하고, 이를 Stage별 Clear하면서 Player의 순위를 기록, 비교하는 게임
4. 개발 환경 : C언어, Ubuntu, Github
5. Git hub : gh repo clone Jiseokyang95/Qplay
6. 작 성 자 : 최종일, 박민혁, 양지석

![image](https://user-images.githubusercontent.com/129154638/230526039-347e0584-632d-4704-991a-74a977590f18.png)

### 1) 구현 방안

1. 구조체를 이용하여 Player의 이름 및 점수를 LeaderBoard에 저장한다.
2. 사용자가 정답을 맞출시 랜덤 점수를 부여한다.
3. 사용자의 목숨을 제한하고 이를 이용해 플레이한다. → Story 추가
4. 게임은 Stage 별로 진행한다.( ex) Stage1 : 구구단 → Stage 2 : 넌센스)
5. 실행 프로그램을 이용 게임을 Play하고 system("clear")를 이용 가독성을 향상시켰다.
6. 파일 입출력 함수를 이용 Player의 순위를 기록하고, 선택 정렬을 통해 시스템을 구현했다.
7. 구현 시스템에 따라 헤더 및 소스파일을 분할하고, make파일을 통해 링크시 용이함을 지향했다.

### 2) 알고리즘

![image](https://user-images.githubusercontent.com/129154638/230552161-bacb5f64-95d0-4dfb-87d9-6c72b426ebc8.png)

### 3) 구현 목록

1. 가위/바위/보 - Random() / string
2. 객관식 퀴즈 - while()
3. 구구단 게임 - Random()
4. 숫자 야구 - Random() / 이중 for문 / string
5. 행맨 - Random() / string 
6. 업다운게임 - Random()
7. 순발력 게임 - clock_gettime() / sleep()

8. 랭크 시스템 - 파일 입출력 함수 / 구조체 함수 / 선택 정렬
9. 점수 부가 시스템 - Random() / Switch case()

** if(), getchar(), system() 함수를 통해 전체적인 게임 진행을 구현함.

### 4) 개선 사항

1. 잘못된 문자 입력시 오류 수정 요망.
   -> While 및 getchar 함수를 이용 개행문자 입력시 번복 가능.
2. Player의 점수(게임 속에서 황금)이 상시 표시 불가.
3. 반복되는 텍스트 함수 지정.
