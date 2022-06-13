#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int turn = 0;
int weekendturn = 0;
struct member
{
	char degree[6];
	char name[10];

};
void printform(int year, int month)//기본 형식
{
	printf("%d년\n", year);
	printf("%d월\n", month);
	printf("--------------------------------------------------------------------------------------\n");
	printf("일            월            화            수            목            금            토\n");
}
int leaf(int year)//윤년이면 1을 아니면 0을 출력
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)

				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}
int monthcheck(int year, int month)// 그 달이 몇일까지 있는지 확인
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (leaf(year) == 1)
			return 29;
		else
			return 28;
	}
}
int gone(int year, int month)//해당 달의 시작 요일 0이면 일요일 시작
{
	int result = 0;
	for (int i = 2022; i < year; i++)
	{
		if (leaf(year) == 1)
			result += 366;
		else
			result += 365;
	}
	for (int i = month - 1; i >= 1; i--)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			result += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			result += 30;
		else if (i == 2)
			result += 28;
	}
	return result;

}
int startday(int year, int month)//해당 달의 시작 요일 0이면 일요일 시작
{
	int result = 0;
	for (int i = 2022; i < year; i++)
	{
		if (leaf(year) == 1)
			result += 366;
		else
			result += 365;
	}
	for (int i = month - 1; i >= 1; i--)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			result += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			result += 30;
		else if (i == 2)
			result += 28;
	}
	return (result + 6) % 7;

}
void turncheck(int year, int month)
{
	char traincheck[20];
	FILE* tcheck;
	for (int i = 2022; i <= 2022; i++)
	{
		for (int j = 1; j < month; j++)
		{
			for (int k = 1; k < 32; k++)
			{
				sprintf(traincheck, "%d %d %d.txt", i, j, k);
				if (tcheck = fopen(traincheck, "r"))
				{
					turn--;
					fclose(tcheck);
				}
			}
		}
	}
}
int checkday = 1;
int weekendcheck(int year, int month)//주말 근무자 시작 순번 확인 함수
{
	int weekend = 0;
	char tname[20];
	FILE* end;
	for (int i = 2022; i <= 2022; i++)
	{
		for (int j = 1; j < month; j++)
		{
			weekend += ((monthcheck(i, j) - 7 + startday(i, j)) / 7) * 2;
			if (7 - startday(i, j) < 7)
			{
				weekend += 1;
			}
			else if (7 - startday(i, j) == 7)
				weekend += 2;
			if (((monthcheck(i, j) - 7 + startday(i, j)) % 7) > 0)//수정 필요
				weekend += 1;
		}
	}
	for (int i = 2022; i <= 2022; i++)
	{
		for (int j = 1; j < month; j++)
		{
			int target = (7 - startday(i, j));
			for (int k = 1; k < 10; k++)
			{
				char train[20];
				
				sprintf(train, "%d %d %d.txt", i, j, target);

				if (end = fopen(train, "r"))
				{
					weekend--;
					fclose(end);
				}
				target++;
				sprintf(train, "%d %d %d.txt", i, j, target);
				if (end = fopen(train, "r"))
				{
					weekend--;
					fclose(end);
				}
				target += 6;
			}
		}
	}
	
	return weekend;
}
void printworker(int year, int month, int day, struct member* worker, int nl)// 근무자 출력 nl은 주차를 뜻함
{
	char fn[10];
	char name[20];
	char tname[20];
	
	
	if (nl == 0)//첫주차는 달력에 맞춰 공백 출력
	{
		for (int i = 0; i < startday(year, month); i++)
		{
			printf("              ");
		}
	}

	for (int i = 0; i < day; i++)
	{
		char train[20];
		sprintf(train, "%d %d %d.txt", year, month, checkday);
		FILE* exist;
		if (day == 7)
		{
			if (exist = fopen(train, "r"))//훈련 출력
			{
				fgets(tname, 20, exist);
				printf("%s", tname);
				for (int k = 0; k < 14 - strlen(tname); k++)
					printf(" ");
				fclose(exist);

			}
			else if (i == 0 || i == 6)//주말 출력
			{
				sprintf(fn, "end%d.txt", weekendturn % 8);
				FILE* fp = fopen(fn, "r");
				fgets(name, 20, fp);
				printf("%s   ", name);
				fclose(fp);
				weekendturn++;
			}
			else//평일 출력
			{
				sprintf(fn, "week%d.txt", turn % 8);
				FILE* fp = fopen(fn, "r");
				fgets(name, 20, fp);
				printf("%s   ", name);
				fclose(fp);
				//printf("%s %s   ", worker[turn % 8].degree, worker[turn % 8].name);
				turn++;
			}
		}
		else if (day < 7 && nl == 0)// 첫주차
		{
			if (exist = fopen(train, "r"))//훈련 출력
			{
				fgets(tname, 20, exist);
				printf("%s", tname);
				fclose(exist);
				for (int k = 0; k < 14 - strlen(tname); k++)
					printf(" ");
			}
			else if (i == day - 1)//주말 출력
			{
				sprintf(fn, "end%d.txt", weekendturn % 8);
				FILE* fp = fopen(fn, "r");
				fgets(name, 20, fp);
				printf("%s   ", name);
				fclose(fp);
				weekendturn++;
			}
			else//평일 출력
			{
				sprintf(fn, "week%d.txt", turn % 8);
				FILE* fp = fopen(fn, "r");
				fgets(name, 20, fp);
				printf("%s   ", name);
				fclose(fp);
				turn++;
			}
		}
		else// 막주차
		{
			if (exist = fopen(train, "r"))//훈련 출력
			{
				fgets(tname, 20, exist);
				printf("%s", tname);
				fclose(exist);
				for (int k = 0; k < 14 - strlen(tname); k++)
					printf(" ");
			}
			else if (i == 0)//주말 출력
			{	
				sprintf(fn, "end%d.txt", weekendturn % 8);
				FILE* fp = fopen(fn, "r");
				fgets(name, 20, fp);
				printf("%s   ", name);
				fclose(fp);
				weekendturn++;
			}
			else//평일 출력
			{
				sprintf(fn, "week%d.txt", turn % 8);
				FILE* fp = fopen(fn, "r");
				fgets(name, 20, fp);
				printf("%s   ", name);
				fclose(fp);
				turn++;
			}
		}
		checkday++;
	}
	printf("\n\n");
}
void printday(int year, int month, struct member* worker)// 날짜 출력
{
	turn = gone(year, month) - weekendcheck(year, month);//달 별로 시작 근무자 조정
	weekendturn = weekendcheck(year, month);
	turncheck(year, month);
	int nl = 0;
	int k = 0;
	for (int i = 0; i < startday(year, month); i++)
	{
		printf("              ");
	}
	for (int i = 1; i <= monthcheck(year, month); i++)
	{
		if (i < 10)
		{
			printf("%d             ", i);//날짜 수에 따른 공백 출력
			k++;
			//printf("%s %s", worker[i % 8].degree, worker[i % 8].name);
		}
		else
		{
			printf("%d            ", i);
			k++;
			//printf("%s %s", worker[i % 8].degree, worker[i % 8].name);
		}
		if ((startday(year, month) + i) % 7 == 0 || i == monthcheck(year, month))
		{

			printf("\n");
			printworker(year, month, k, worker, nl);//근무차 출력 호출
			k = 0;
			nl++;
		}

	}
}
void menu()
{
	printf("1. 근무자 입력\n");
	printf("2. 근무표 출력\n");
	printf("3. 훈련 일정 입력\n");
	printf("0. 종료\n");
	checkday = 1;
}
int main()
{
	struct member worker[8];
	int n;
	int month;
	int year;
	int ty, tm, td;
	char tn[20];
	char fn[100];
	char wn[20];
	int term;
	while (1)
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("근무자 입력: 계급 이름\n");
			for (int i = 0; i < 8; i++)
			{
				scanf("%s %s", worker[i].degree, worker[i].name);
				sprintf(fn, "week%d.txt", i);
				FILE* fp = fopen(fn, "w");
				fprintf(fp, "%s %s", worker[i].degree, worker[i].name);
				fclose(fp);
				sprintf(wn, "end%d.txt", i);
				FILE* wp = fopen(wn, "w");
				fprintf(wp, "%s %s", worker[i].degree, worker[i].name);
				fclose(wp);
			}
			break;
		case 2:
			printf("년도: ");
			scanf("%d", &year);
			if (year < 2022)
			{
				printf("2022년도 이후를 입력해 주십시오.\n");
				break;
			}
			printf("월: ");
			scanf("%d", &month);
			if (month < 1 || month>12)
			{
				printf("잘못된 수가 입력되었습니다.\n");
				break;
			}
			printform(year, month);
			printday(year, month, worker);
			break;
		case 3:
			printf("년 월 일 훈련명: ");
			scanf("%d %d %d %s", &ty, &tm, &td, tn);
			printf("몇일간? ");
			scanf("%d", &term);
			FILE* fp = 0;
			for (int i = 0; i < term - 1; i++)
			{
				if (tm == 12 && td > 31)
				{
					ty++;
					tm = 1;
					td = 1;
				}
				else if (td > monthcheck(ty, tm))
				{
					tm++;
					td = 1;
				}
				sprintf(fn, "%d %d %d.txt", ty, tm, td++);
				fp = fopen(fn, "w");
				fprintf(fp, "%s", tn);
				fclose(fp);

			}
			fclose(fp);
			break;
		case 0:
			return 0;

		}
	}



	return 0;
}
/*
병장 김동은0
병장 정운희1
병장 부준형2
병장 이명환3
병장 정석영4
병장 문정욱5
상병 김준환6
상병 김종윤7
2022
4
*/