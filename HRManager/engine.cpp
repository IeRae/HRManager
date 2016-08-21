#include"stdafx.h"

#include"engine.h"

/*
int main() {

	fix_data head;
	char command[3];

	head = (fix_data)malloc(sizeof(node));
	head->next_data = NULL;

	init_base_data();
	hint();

	while (1) {
		printf("Type command> ");
		scanf("%s", command);
		if (0 == strcmp(command, "PA")) {
			printf("print all\n");
			print_base_data();
		}
		else if (0 == strcmp(command, "H")) {
			hint();
		}
		else if (0 == strcmp(command, "IN")) {
			printf("insert fixed list\n");
			add_fix_data(head);
		}
		else if (0 == strcmp(command, "DE")) {
			printf("delete fixed list\n");

			char name[50];
			scanf("%s", name);

			delete_fix_data(head, name);
		}
		else if (0 == strcmp(command, "PD")) {
			printf("print detail\n");

			int id;
			char name[50];
			scanf("%s %d", name, &id);

			print_data(name, id);
		}
		else if (0 == strcmp(command, "PFL")) {
			printf("print fixed list\n");
			print_fix_data(head);
		}
		else if (0 == strcmp(command, "PS")) {
			printf("print schadule\n");
			print_schadule();
		}
		else if (0 == strcmp(command, "PFS")) {
			printf("print fixed schadule\n");
			print_fix_schadule(head);
		}
		else if (0 == strcmp(command, "EX")) {
			//노드 지정 포인터(head) 메모리 해제
			//free(exit_node(head));
			break;
		}
		else if (0 == strcmp(command, "CL")) {
			clear();
		}
		else {
			printf("long command\n");
		}

	}

	return 0;
}
*/
void hint() {
	printf("PA = print all\n");
	printf("IN = insert fixed list\n");
	printf("DE = delete fixed list\n");
	printf("PD = print detail\n");
	printf("PFL = print fixed list\n");
	printf("PS = print schadule\n");
	printf("PFS = print fixed schadule\n");
	printf("H = hint\n");
	printf("EX = exit\n");
}

int init_base_data() {
	//printf("init\n");
	//데이터를 저장할 temp와 현재 노드의 위치를 알려줄 current 생성

	int index = 0;

	int indexOfChapel;
	int indexOfClass_1;
	int indexOfClass_2;
	int indexOfClass_3;
	int indexOfClass_4;
	int indexOfGrade;
	FILE* fp;
	fp = fopen("data.txt", "r");

	while (!feof(fp)) {

		data[index].name = "";
		data[index].chapel_available = impossible;
		data[index].class_available[0] = nope;
		data[index].class_available[1] = nope;
		data[index].class_available[2] = nope;
		data[index].class_available[3] = nope;

		//데이터를 입력 받음
		//데이터 순서
		//이름 접수번호 채플 등급 수업조교 시간표 
		//fscanf(fp,"%d",data[index].name);
		fscanf(fp, "%s %d %d %d %d %d %d %d", data[index].name, &data[index].id_no, &indexOfChapel, &indexOfGrade, &indexOfClass_1, &indexOfClass_2, &indexOfClass_3, &indexOfClass_4);

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				fscanf(fp, "%d", &data[index].timeTable[j][i]);
			}
		}


		find_init_index(1, indexOfChapel, index, 0);
		find_init_index(2, indexOfGrade, index, 0);
		find_init_index(3, indexOfClass_1, index, 0);
		find_init_index(3, indexOfClass_2, index, 1);
		find_init_index(3, indexOfClass_3, index, 2);
		find_init_index(3, indexOfClass_4, index, 3);

		index++;
	}

	last_data_index = index;

	fclose(fp);

	return last_data_index;

	//printf("init ok\n");

}

void find_init_index(int type, int value, int index, int class_index = 0) {
	switch (type) {
	case 1: //chapel
		switch (value) {
		case 0: data[index].chapel_available = possible;
			break;
		case 1: data[index].chapel_available = impossible;
			break;
		}
		break;
	case 2:	//grade
		switch (value) {
		case 0: data[index].grade = ap_grade;
			break;
		case 1: data[index].grade = a_grade;
			break;
		case 2: data[index].grade = am_grade;
			break;
		case 3: data[index].grade = bp_grade;
			break;
		case 4: data[index].grade = b_grade;
			break;
		case 5: data[index].grade = bm_grade;
			break;
		case 6: data[index].grade = cp_grade;
			break;
		default:
			data[index].grade = c_grade;
			break;
		}
		break;
	case 3:	//class
		switch (class_index) {
		case 0:
			if (value) data[index].class_available[class_index] = tus_first;
			else data[index].class_available[class_index] = nope;
			break;
		case 1:
			if (value) data[index].class_available[class_index] = tus_last;
			else data[index].class_available[class_index] = nope;
			break;
		case 2:
			if (value) data[index].class_available[class_index] = thu_first;
			else data[index].class_available[class_index] = nope;
			break;
		case 3:
			if (value) data[index].class_available[class_index] = thu_last;
			else data[index].class_available[class_index] = nope;
			break;
		}
		break;
	}
}

void print_data(CString findName, int findId) {

	int index;

	for (int i = 0; i < last_data_index; i++) {
		if ((data[i].id_no == findId) && (data[i].name == findName))
			index = i;
		else
			printf("wrong data\n");
	}

	//이름 접수 번호 출력 
	printf("id : %d\tname : %s", data[index].id_no, data[index].name);
	printf("\t");

	//평가등급 출력 
	switch (data[index].grade) {
	case ap_grade:	printf("grade : a+"); break;
	case a_grade:	printf("grade : a"); break;
	case am_grade:	printf("grade : a-"); break;
	case bp_grade:	printf("grade : b+"); break;
	case b_grade:	printf("grade : b"); break;
	case bm_grade:	printf("grade : b-"); break;
	case cp_grade:	printf("grade : c+"); break;
	case c_grade:	printf("grade : c"); break;
	}
	printf("\t");

	//채플 가능 여부 출력 
	if (data[index].chapel_available) printf("chapel : possible");
	else printf("chapel : impossible");
	printf("\t");

	//수업조교 여부 출력 
	for (int i = 0; i < 4; i++) {
		if ((i == 0) && (data[index].class_available[i] != nope)) printf("화요일 오전근무");
		else if ((i == 1) && (data[index].class_available[i] != nope)) printf("화요일 오후근무");
		else if ((i == 2) && (data[index].class_available[i] != nope)) printf("목요일 오전근무");
		else if ((i == 3) && (data[index].class_available[i] != nope)) printf("목요일 오후근무");
		else printf("근무 불가능");
		printf("\t");
	}


	//수업 시간표 출력 
	printf("\n");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			printf(" %d ", data[index].timeTable[j][i]);
		}
		printf("\n");
	}

	printf("\n");
}

void print_base_data(CStringArray& nameArray) {
	
	for (int index = 0; index < last_data_index; index++) {
		CString msg;
		msg.Format(_T("%s"), data[index].name);
//		nameArray[index].Format
		AfxMessageBox(msg);
	}
}

void find_number_applicant(int num) {
	num = last_data_index;
}

void print_schadule() {

	printf("Mon\tThu\tWed\tThu\tFri\n");
	printf("\n-------------------------------------------------------\n");
	for (int i = 0; i < 7; i++) {
		for (int index = 0; index < last_data_index; index++) {
			for (int j = 0; j < 5; j++) {
				if (data[index].timeTable[j][i]) printf("%s\t", data[index].name);
				else printf("\t");
			}
			printf("\n");

		}
		printf("\n-------------------------------------------------------\n");
	}
}


int add_fix_data(fix_data first) {

	//데이터를 저장할 temp와 현재 노드의 위치를 알려줄 current 생성
	fix_data temp;
	fix_data current;
	char name[50];
	int id;

	temp = (fix_data)malloc(sizeof(node));


	//포인터 형을 넘겨 받기 때문에 first가 가리키는 노드와는 상관 없이 새로운 노드 추가 가능
	current = first->next_data;

	//데이터를 입력 받음
	scanf("%s %d", name, &id);

	int flag = 0;

	for (int i = 0; i < last_data_index; i++) {
		if ((id == data[i].id_no) && (data[i].name == name)) {
			temp->index = i;
			flag = 1;
			break;
		}
	}

	if (flag == 0) { printf("worng data\n"); return 0; }

	//현재 입력 받은 데이터는 가장 마지막에 삽입 할 것임
	temp->next_data = NULL;

	//노드의 위치를 찾아냄 어디 인지 찾아냄
	while (1) {
		if (first->next_data == NULL) {
			printf("마지막 노드에 추가\n");
			first->next_data = temp;
			break;
		}
		else {
			//still moving
			if (current->next_data == NULL) {
				current->next_data = temp;
				break;
			}
			else {
				current = current->next_data;
			}
		}
	}


	return 0;
}

int delete_fix_data(fix_data first, CString deleteName) {

	fix_data temp;
	fix_data preNode;

	int flag = 0;

	temp = (fix_data)malloc(sizeof(node));
	preNode = (fix_data)malloc(sizeof(node));

	temp = first->next_data;
	preNode = NULL;

	if (data[temp->index].name == deleteName)
	{
		first->next_data = temp->next_data;
		free(temp);
	}
	else
	{
		while (temp != NULL)
		{
			if (data[temp->index].name == deleteName)
			{
				preNode->next_data = temp->next_data;
				free(temp);
				flag = 1;
				break;
			}
			else {
				preNode = temp;
				temp = temp->next_data;
			}

		}

		if (flag == 0) printf("wrong name");
	}

	return 0;


}

int print_fix_data(fix_data first) {

	if (first->next_data == NULL) {
		printf("error : node is empty\n");
		return 0;
	}

	fix_data current;
	current = (fix_data)malloc(sizeof(node));
	current = first->next_data;
	//마지막 노드가 나타날떄까지 head 노드의 다음 노드부터 출력
	while (current->next_data != NULL) {
		printf("id : %d\tname : %s\n", data[current->index].id_no, data[current->index].name);
		current = current->next_data;
	}

	printf("id : %d\tname : %s\n", data[current->index].id_no, data[current->index].name);

	return 0;
}

int print_fix_schadule(fix_data first) {

	if (first->next_data == NULL) {
		printf("error : node is empty\n");
		return 0;
	}

	fix_data current;
	current = (fix_data)malloc(sizeof(node));


	printf("Mon\tThu\tWed\tThu\tFri\n");
	printf("\n-------------------------------------------------------\n");
	for (int i = 0; i < 7; i++) {
		for (current = first->next_data; current->next_data != NULL; current = current->next_data) {
			for (int j = 0; j < 5; j++) {
				if (data[current->index].timeTable[j][i]) printf("%s\t", data[current->index].name);
				else printf("\t");
			}
			printf("\n");

		}
		for (int j = 0; j < 5; j++) {
			if (data[current->index].timeTable[j][i]) printf("%s\t", data[current->index].name);
			else printf("\t");
		}
		printf("\n");

		printf("\n-------------------------------------------------------\n");
	}

	return 0;
}

void clear() {
	system("cls");
}