int question(){
    int correct, fail; //맞은 수,틀린수 출력
    int select; //입력한 숫자
    correct=0; fail=0;
    while (1){ //1번 문제
    printf("1번 문제 우리 기수는 KOSTA 257기이다.\n");
    printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
    scanf("%d",&select);
    
    if (select==1){
        fail=++fail;
        printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct,fail);
        break;
    }
    else if (select==2)
    {
        correct=++correct;
        printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n",correct,fail);
        break;
    }
    else
    {
        printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
    }
    }

    while (1) //2번 문제
    {
        printf("2번 문제 !\n강사님 성함은 '한경일' 이다.\n");
        printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
        scanf("%d",&select);
        if (select==1){
        correct=++correct;
        printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct,fail);
        break;
        }
        else if (select==2)
        {
            fail=++fail;
            printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n",correct,fail);
            break;
        }
        else
        {
            printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
        }
    }
    
    while (1) //3번 문제
    {
        printf("3번문제\n 교육마지막 날짜는 7월 25일이다!\n");
        printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
        scanf("%d",&select);
        if (select==1)
        {
        correct=++correct;
        printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct,fail);
        break;
        }
         else if (select==2)
        {
            fail=++fail;
            printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n",correct,fail);
            break;
        }
        else
        {
            printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
        }
    }
    
    while (1) //4번 문제 
    {
        printf("4번 문제\n if 문의 구조는 'if (조건문);' 이다.");
        printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
        scanf("%d",&select);

        if (select==1)
        {
        fail=++fail;
        printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct,fail);
        break;
        }

        else if (select==2)
        {
        correct=++correct;
        printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n",correct,fail);
        break;
        }

        else
        {
            printf("잘못된 입력입니다  다시 입력해주세요! \n");
        }

    }

    while (1) //5번 문제
    {
        printf("5번 문제\n C언어의 'do while'문은 반드시 한번 이상 실행한다.");
        printf("맞으면 1번 틀리면 2번을 눌러주세요! \n");
        scanf("%d",&select);

        if (select==1)
        {
        correct=++correct;
        printf("정답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n", correct,fail);
        break;
        }
         else if (select==2)
        {
            fail=++fail;
            printf("오답입니다! \n현재 맞춘 문제: %d, 틀린 문제 %d\n\n\n",correct,fail);
            break;
        }
        else
        {
            printf("잘못된 입력입니다  다시 입력해주세요! \n\n\n");
        }
    }
}