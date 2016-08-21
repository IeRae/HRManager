#pragma once

#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define enumstr(a) (#a) 


typedef enum {
	possible, impossible
} chapel_type;

typedef enum {
	tus_first,
	tus_last,
	thu_first,
	thu_last,
	nope
}class_type;

typedef enum {
	ap_grade,
	a_grade,
	am_grade,
	bp_grade,
	b_grade,
	bm_grade,
	cp_grade,
	c_grade
} grade_type;

typedef struct base_data {
	CString name;
	int id_no;
	chapel_type chapel_available;
	class_type class_available[4];
	grade_type grade;
	int timeTable[5][7];
} base_data;

typedef struct node* fix_data;
typedef struct node {
	int index;
	fix_data next_data;
}node;


int init_base_data();	//지원자 접수 
void find_init_index(int type, int value, int index, int class_index);	//지원자 정보 갱신 
void print_data(CString findName, int findId); //지원자 상새 출력 
void print_schadule();	//지원자 시간표 종합 출력 
int add_fix_data(fix_data first);	//확정인원 추가
int delete_fix_data(fix_data first, CString deleteName);	//확정인원 취소 
int print_fix_data(fix_data first);	//확정인원 목록 출력 
int print_fix_schadule(fix_data first);	//확정인원 시간표 출력 
void print_base_data(CStringArray& nameArray); //지원자 목록 출력 
void hint(); //힌트 출력 
void find_number_applicant(int num);
void clear();


static int last_data_index;