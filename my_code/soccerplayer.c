/* 축구선수 관리프로그램 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Total_Player_num;
int User_input;

struct Worlds2020 {
	char player_team[30];
	char player_name[10];
	int  player_old;
	char player_position[20];
	int player_goal;
	int player_pass;
	int player_assist;
    
	double player_score;

};
typedef struct Worlds2020 Worlds;
int player_register(Worlds* worlds, int* player_num);
int player_search(Worlds* worlds, int* player_num);
int player_change(Worlds* worlds, int* player_num);
int File_Uproad(Worlds* worlds, int* total_player_num);
int File_open(Worlds* worlds, int* total_player_num);
int main() {
	int number = 0;
	Worlds* player_list;
	printf("======2020년 선수 정보입니다 =======\n\n\n" );  // 프로그램 제목
	
	printf("선수의 최대 등록 수를 적어주세요:");
	scanf("%d", &Total_Player_num);
	player_list = (Worlds*)malloc(sizeof(Worlds) * Total_Player_num);
	printf("\n\n\n");
	while (1) {
		printf("===========2020 Worlds 정보===========\n\n");
		printf("1. Player register(선수 등록)\n");
		printf("2. Player change(선수 정보변경)\n");
		printf("3. Player search(선수 검색)\n");
		printf("4. Worlds2020.txt 에 정보 입력\n");
		printf("5. Worlds2020.txt 에서 정보 호출 \n");
		printf("6. 프로그램 종료 \n");
		printf("\n\n");
		printf("실행할 항목을 골라주세요:");
		
		scanf("%d", &User_input);
		printf("======================================\n\n");
	
		if (User_input == 1) {
			player_register(player_list, &number); // 선수를 등록하는 함수
		}
		else if (User_input == 2) {
			player_change(player_list, &number); // 선수 정보를 변경하는 함수
		}
		else if (User_input == 3) {
			player_search(player_list, &number); //선수를 검색하는 함수
		}
		else if (User_input == 4) {
			File_Upload(player_list, &Total_Player_num); // "Wolrds2020.txt"에 파일 업로드
		}
		else if (User_input == 5) {
			File_open(player_list, &Total_Player_num); // "Worlds2020.txt"에서 파일 받기
		}
		else if (User_input == 6) {
			return 0;
		}
		
	}
	
	free(player_list);
	
	return 0;


}
int player_register(Worlds* worlds, int* player_num) {
	int Player_Number;
	int a;
	int b;
	int c;
	int d;
	double e;




	printf("%d 번째 선수의 정보 ------- \n\n", *player_num + 1);

	printf("팀명: ");
	scanf("%s", worlds[*player_num].player_team);

	printf("선수명: ");
	scanf("%s", worlds[*player_num].player_name);

	printf("선수포지션: ");
	scanf("%s", worlds[*player_num].player_position);

	printf("선수의 나이: ");
	scanf("%d", &worlds[*player_num].player_old);

	printf("선수의 goal: ");
	scanf("%d", &worlds[*player_num].player_goal);
	b = worlds[*player_num].player_goal;
		
	printf("선수의 assist: ");
	scanf("%d", &worlds[*player_num].player_assist);
	c = worlds[*player_num].player_assist;
	
	printf("선수의 pass: ");
	scanf("%d", &worlds[*player_num].player_pass);
	d = worlds[*player_num].player_pass;
	
	
	printf("선수의 평균 평점 : ");
	scanf("%lf", &worlds[*player_num].player_score);
	
	printf("선수 등록 완료 \n\n ");
	(*player_num)++;
		
		
	
	return 0;
}
int player_search(Worlds* worlds, int* player_num) {
	int input;
	int j;
	char user_search[30];

	printf("(1)팀 이름 \n");
	printf("(2)선수 이름 \n");
	printf("(3)선수 포지션 \n");
	printf(" 검색할 항목의 숫자를 입력해주세요:");
	scanf("%d", &input);
	printf("\n\n");
	if ((input != 1) && (input != 2) && (input != 3)) {
		printf("숫자입력오류! \n\n");
	}
	else {
		scanf("%s", user_search);
		printf("\n\n");
		printf("==========%s 검색결과=========\n\n", user_search);
		if (input == 1) {
			for (j = 0; j < *player_num; j++) {
				if (strcmp(worlds[j].player_team, user_search) == 0) {
					printf("선수 소속 : %s // 선수 이름: %s // 선수 포지션: %s // 선수 나이: %d // 선수 goal : %d // 선수 assist: %d // 선수 pass : %d // 선수 평균점수 : %2.1f \n",
						worlds[j].player_team, worlds[j].player_name, worlds[j].player_position, worlds[j].player_old, worlds[j].player_goal, worlds[j].player_assist, worlds[j].player_pass,
						 worlds[j].player_score);
				}
			}
			printf("\n\n");
		}
		else if (input == 2) {
			for (j = 0; j < *player_num; j++) {
				if (strcmp(worlds[j].player_name, user_search) == 0) {
					printf("선수 소속 : %s // 선수 이름: %s // 선수 포지션: %s // 선수 나이: %d // 선수 goal : %d // 선수 assist: %d // 선수 pass : %d // 선수 평균점수: %2.1f \n",
						worlds[j].player_team, worlds[j].player_name, worlds[j].player_position, worlds[j].player_old, worlds[j].player_goal, worlds[j].player_assist, worlds[j].player_pass,
						worlds[j].player_score);
				}
			}
			printf("\n\n");
		}
		else if (input == 3) {
			for (j = 0; j < *player_num; j++) {
				if (strcmp(worlds[j].player_position, user_search) == 0) {
					printf("선수 소속 : %s // 선수 이름: %s // 선수 포지션: %s // 선수 나이: %d // 선수 goal : %d // 선수 assist: %d // 선수 pass : %d // 선수 평균점수: %2.1f \n",
						worlds[j].player_team, worlds[j].player_name, worlds[j].player_position, worlds[j].player_old, worlds[j].player_goal, worlds[j].player_assist, worlds[j].player_pass,
						worlds[j].player_score);
				}
			}
			printf("\n\n");
		}
	}
	
	return 0;
	printf("\n\n");

}
int player_change(Worlds* world, int* player_num){
	char change_player[30];
	int k;
	printf("정보를 변경할 선수의 이름을 입력해주세요: ");
	scanf("%s", change_player);
	printf("\n\n");
	for (k = 0; k < *player_num; k++) {
		if (strcmp(world[k].player_name, change_player) == 0) {
			printf("변경할 선수의 이름 :");
			scanf("%s", world[k].player_name);
			printf("변경할 선수의 팀 :");
			scanf("%s", world[k].player_team);
			printf("변경할 선수의 포지션: ");
			scanf("%s", world[k].player_position);
			printf("변경할 선수의 나이: ");
			scanf("%d", &world[k].player_old);
			printf("변경할 선수의 goal: ");
			scanf("%d", &world[k].player_goal);
			printf("변경할 선수의 assist: ");
			scanf("%d", &world[k].player_assist);
			printf("변경할 선수의 pass: ");
			scanf("%d", &world[k].player_pass);
			printf("변경할 선수의 평균점수: ");
			scanf("%lf", &world[k].player_score);
			
			printf("\n\n");
			printf("=========선수 변경완료=========");
			printf("\n");

		}
	}
	return 0;
}
int File_Upload(Worlds* world, int* total_player_num) {
	char sentence[30];

	FILE* fp;
	fp = fopen("Worlds2020.txt", "w");
	if (fp == NULL) {
		printf("FILE WRITE ERROR! \n");
		return 0;
	}
	int g;
	fputs("2020 WORLDS========================================================================", fp);
	fputs("\n", fp);
	fputs(" 팀 // 이름 // 포지션 // 나이 // goal // assist // pass // 선수 평균점수 ",fp);
	fputs("\n", fp);
	for (g = 0; g < *total_player_num; g++) {
		fputs("\n", fp);
		fprintf(fp, " %s // %s // %s  // %d // %d // %d // %d // %f", world[g].player_team, world[g].player_name, world[g].player_position,
			world[g].player_old, world[g].player_goal, world[g].player_assist, world[g].player_pass, world[g].player_score);
	
		


	}
	printf("\n");
	printf("파일 업로드 완료! ");
	printf("\n");
	fclose(fp);
	return 0;
}
int File_open(Worlds* world, int* total_player_num) {
	int n;
	FILE *fbp;
	fbp = fopen("Worlds2020.txt", "r+");
	
	if (fbp == NULL) {
		printf("READ ERROR! \n");
		return 0;

	}
	
	printf("입력받은내용 -----------------------\n\n");
	printf("\n");
	for (n = 0; n < *total_player_num; n++) {
		
		printf("%s  //  %s  //  %s  //  %d  //  %d  //  %d  //  %d  //  %f \n", world[n].player_team, world[n].player_name, world[n].player_position, world[n].player_old,
			world[n].player_goal, world[n].player_assist, world[n].player_pass, world[n].player_score);
	}
	
	fclose(fbp);
}
