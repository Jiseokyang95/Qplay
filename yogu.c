#include <stdio.h>
#define Web 0
#define C 1
#define Cpp 2
#define JAVA 3
int main() {
    int project[4][1000];
    char Project_Contents[4][1000][200];
    char Project_Title[4][1000][30];
    int N, K,i;
    int _W = 0, _C = 0, _Cpp = 0, _J = 0;
    while (1) {
        printf("프로젝트 종류를 선택하여 주세요. Web : 0, C : 1, C++ : 2, JAVA : 3\n");
        scanf("%d", &N);
        printf("1. 프로젝트 보기 2. 프로젝트 생성 3. 프로젝트 삭제\n");
        scanf("%d", &K);
        if (K == 1) {
            printf("프로젝트 보기 메뉴를 선택하셨습니다.\n");
            switch (N) {
            case 0:
                printf("Web을 선택하셨습니다.\n");
                for (i = 0; i < _W; i++) {
                    printf("프로젝트 제목[%d] : %s\n", i, Project_Title[0][i]);
                    printf("프로젝트 내용[%d] : %s\n", i, Project_Contents[0][i]);
                }
                break;
            case 1:
                printf("C를 선택하셨습니다.\n");
                for (i = 0; i < _C; i++) {
                    printf("프로젝트 제목[%d] : %s\n", i, Project_Title[1][i]);
                    printf("프로젝트 내용[%d] : %s\n", i, Project_Contents[1][i]);
                }
                break;
            case 2:
                printf("Cpp를 선택하셨습니다.\n");
                for (i = 0; i < _Cpp; i++) {
                    printf("프로젝트 제목[%d] : %s\n", i, Project_Title[2][i]);
                    printf("프로젝트 내용[%d] : %s\n", i, Project_Contents[2][i]);
                }
                break;
            case 3:
                printf("JAVA를 선택하셨습니다.\n");
                for (i = 0; i < _J; i++) {
                    printf("프로젝트 제목[%d] : %s\n", i, Project_Title[3][i]);
                    printf("프로젝트 내용[%d] : %s\n", i, Project_Contents[3][i]);
                }
                break;
            }
        }
        if (K == 2) {
            switch (N) {
            case 0:
                printf("Web을 선택하셨습니다.\n"); project[Web][_W] = 1;
                printf("프로젝트 제목을 입력해주세요(15자이내) : ");
                scanf(" %[^\n]s", Project_Title[Web][_W]);
                printf("프로젝트 내용을 입력해주세요(100자이내) : ");
                scanf(" %[^\n]s", Project_Contents[Web][_W++]);
                break;
            case 1:
                printf("C를 선택하셨습니다.\n"); project[C][_C] = 1;
                printf("프로젝트 제목을 입력해주세요(15자이내) : ");
                scanf(" %[^\n]s", Project_Title[C][_C]);
                printf("프로젝트 내용을 입력해주세요(100자이내) : ");
                scanf(" %[^\n]s", Project_Contents[C][_C++]);
                break;
            case 2:
                printf("Cpp를 선택하셨습니다.\n"); project[Cpp][_Cpp] = 1;
                printf("프로젝트 제목을 입력해주세요(15자이내) : ");
                scanf(" %[^\n]s", Project_Title[Cpp][_Cpp]);
                printf("프로젝트 내용을 입력해주세요(100자이내) : ");
                scanf(" %[^\n]s", Project_Contents[Cpp][_Cpp++]);
                break;
            case 3:
                printf("JAVA를 선택하셨습니다.\n"); project[JAVA][_J] = 1;
                printf("프로젝트 제목을 입력해주세요(15자이내) : ");
                scanf(" %[^\n]s", Project_Title[JAVA][_J]);
                printf("프로젝트 내용을 입력해주세요(100자이내) : ");
                scanf(" %[^\n]s", Project_Contents[JAVA][_J++]);
                break;
            default: printf("잘못된 프로젝트 종류를 입력하셨습니다. 다시 처음으로 돌아갑니다.\n");
                break;
            }
        }
    }
    return 0;
}