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


int init_base_data();	//������ ���� 
void find_init_index(int type, int value, int index, int class_index);	//������ ���� ���� 
void print_data(CString findName, int findId); //������ ��� ��� 
void print_schadule();	//������ �ð�ǥ ���� ��� 
int add_fix_data(fix_data first);	//Ȯ���ο� �߰�
int delete_fix_data(fix_data first, CString deleteName);	//Ȯ���ο� ��� 
int print_fix_data(fix_data first);	//Ȯ���ο� ��� ��� 
int print_fix_schadule(fix_data first);	//Ȯ���ο� �ð�ǥ ��� 
void print_base_data(CStringArray& nameArray); //������ ��� ��� 
void hint(); //��Ʈ ��� 
void find_number_applicant(int num);
void clear();


static int last_data_index;