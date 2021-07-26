#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>
typedef struct PersonInfo {
	char name[1024];
	char phone[1024];
}PersonInfo;
#define MAX_PERSON_INFO_SIZE 1000
typedef struct AddressBook {
	//PersonInfo persons[MAX_PERSON_INFO_SIZE];
	PersonInfo* persons;//�ĳ�ָ�����ʽ,ͨ����̬�ڴ������ʵ��
	//ͨ��size��ʾpersons������ʵ����Ч��Ԫ��
	//[0,size)��Χ��Ԫ������ЧԪ��
	int size;
	int capacity;
	//capacity��ʾ��ǰpersons��Ӧ�Ŀռ��������
}AddressBook;
extern void save(AddressBook* addressBook);
extern void load(AddressBook* addressBook);
void init(AddressBook* addressBook) { 
	//memset(addressBook->persons, 0, sizeof(addressBook->persons));

	//addressBook->size = 0;
	//��ʽ�������ڴ�ռ�
	addressBook->size = 0;
	addressBook->capacity = 200;
	addressBook->persons = (PersonInfo*)malloc(addressBook->capacity * sizeof(PersonInfo));
	//���������ʼ��,VS��debugģʽ�»ᱻ��ʼ��Ϊ"������" 
	//memset(addressBook->persons, 0, sizeof(PersonInfo) * addressBook->capacity);
}
int menu(){
	printf("====================\n");
	printf("��ӭʹ��ͨѶ¼����\n");
	printf("1. �鿴������ϵ��\n");
	printf("2. ������ϵ��\n");
	printf("3. �������ֲ�����ϵ��\n");
	printf("4. ɾ����ϵ��\n");
	printf("5. �޸���ϵ����Ϣ\n");
	printf("0. �˳�\n");
	printf("====================\n");
	printf("����������ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void showPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	//ֻ��Ҫ��ÿ����ϵ����Ϣ��ӡ��������
	printf("�鿴������ϵ��...\n\n");
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		printf("[%d]%s\t%s\n",i, p->name, p->phone);
	}
	printf("\n����ʾ��%d������\n", addressBook->size);
}
void addPersonInfo(AddressBook* addressBook) {
	//������ϵ�˵���Ϣ�����±�Ϊsizeλ�õ�Ԫ����
	printf("������ϵ��...\n\n");
	if (addressBook->size >= addressBook->capacity) {
		//��ϵ���Ѿ�����
		//printf("����ʧ�ܣ���ϵ��������\n");
		//���ж�̬����
		addressBook->capacity += 100;
		//���������ڴ�ռ�
		//addressBook->persons = realloc(addressBook->persons, addressBook->capacity * sizeof(PersonInfo));
		//ֱ��ʹ��realloc�Ƚϼ򵥷���
		//Ҳ����ʹ��malloc�ֶ�ʵ��
		PersonInfo* old = addressBook->persons;
		addressBook->persons = (PersonInfo*)malloc(addressBook->capacity * sizeof(PersonInfo));
		//�Ѿɵ����ݿ������µ��ڴ�ռ���
		memcpy(addressBook->persons, old, sizeof(PersonInfo) * addressBook->size);
		//�ͷžɿռ�
		free(old);
		//return;
	}
	PersonInfo* p = &addressBook->persons[addressBook->size];
	printf("����������ϵ�˵�����:\n");
	scanf("%s",p->name );
	printf("����������ϵ�˵ĵ绰:\n");
	scanf("%s", p->phone);
	//����size
	addressBook->size++;
	//�������ݵ�����
	save(addressBook);
	printf("\n������ϵ�˳ɹ�!\n\n");
}
void findPersonInfo(AddressBook* addressBook) {
	//���������ҵ绰
	assert(addressBook != NULL);
	printf("��������������ϵ��!\n\n");
	printf("������Ҫ���ҵ�����:");
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		if (strcmp(p->name, name) == 0) {
			//�����������,���Բ��ܼ�break,Ҫ����ӡ����
			printf("[%d]%s\t\t%s\n", i, p->name, p->phone); 
			count++;
		}
	}
	printf("\n�������!�����ҵ�%d����¼\n\n",count);
}
void deletePersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	printf("ɾ����ϵ��!\n\n");
	printf("������Ҫɾ����ϵ�˵����:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressBook->size) {
		printf("�������id����!ɾ����ϵ��ʧ��!\n");
		return;
	}
	if (id == addressBook->size - 1) {
		//��ʱҪɾ���һ��Ԫ��
		addressBook->size--;
		printf("\nɾ���ɹ�!\n\n");
		return;
	}
	//ɾ���м�Ԫ��,������Ԫ�ظ��������м�Ԫ��λ����
	addressBook->persons[id] =addressBook->persons[addressBook->size - 1];
	//ɾ��ĩβԪ��
	addressBook->size--;

	save(addressBook);
	printf("\nɾ���ɹ�!\n\n");
}
void updatePersonInfo(AddressBook* addressBook) {
	//�޸���ϵ��.�����û����������������޸��ĸ���¼
	assert(addressBook != NULL);
	printf("���޸���ϵ����Ϣ!\n\n");
	printf("������Ҫ�޸ĵ���ϵ�����:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressBook->size) {
		printf("�������id����!�޸���ϵ��ʧ��!\n");
		return;
	}
	//��ȡ����ϵ�˵Ľṹ�����
	PersonInfo* p = &addressBook->persons[id];
	printf("�����Ҫ���ֲ���,��ֱ������*");
	printf("�������µ���ϵ�˵�����:");
	char name[1024] = { 0 };
	//���Ƿ���ʹ��scanf��̫��,ֱ������س�,scanf�޷�����
	//���ǿ���ʹ��gets���
	scanf("%s", &name);
	//gets(name);
	if (strcmp(name, "*") != 0) {
		//����û�����Ĳ��ǻس�,��name�������ṹ����
		strcpy(p->name, name);
	}
	printf("�������µ���ϵ�˵绰:");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	//gets(phone);
	if (strcmp(name, "*") != 0) {
		strcpy(p->phone, phone);
	}

	save(addressBook);
	printf("�޸���ϵ�����!\n");
}
//void quit(AddressBook* addressBook) {
//	printf("googbye\n");
//	//��ȫ�൱��main�����е�return 0.
//	//�����Ͼ��ǽ�����ǰ����.
//	exit(0);
//	return;
//}
typedef void(*Func)(AddressBook*);
///////////////////////////////////////////
//����һ�麯����ɱ��浽�ļ��־������ļ���������
///////////////////////////////////////////
void save(AddressBook* addressBook) {
	//��ͨѶ¼�����ݱ��浽�ļ���
	//���ļ�
	FILE* f = fopen("d:/AddressBook.txt", "w");
	if (f == NULL) {
		perror("�ļ���ʧ��");
		return;
	}
	//д������
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		fwrite(p, sizeof(PersonInfo), 1, f);
	}
	fclose(f);
}
void load(AddressBook* addressBook) {
	//���ļ�����ͨѶ¼������
	//���ļ�
	FILE* f = fopen("d:/AddressBook.txt", "r");
	if (f == NULL) {
		printf("��ǰ�ļ���δ����!\n");
		return;
	}
	while (1) {
		PersonInfo personInfo = { 0 };
		size_t len = fread(&personInfo, sizeof(PersonInfo), 1, f);
		if (len == 0) {
			printf("��ȡ���\n");
			break;
		}
		//��personInfo����������ӵ��ṹ�����������ȥ
		if (addressBook->size >= addressBook->capacity) {
			//������
			PersonInfo* old = addressBook->persons;
			addressBook->capacity += 100;
			addressBook->persons = (PersonInfo*)malloc(addressBook->capacity * sizeof(PersonInfo));
			memcpy(addressBook->persons, old, addressBook->size * sizeof(PersonInfo));
			free(old);
				
		}
		//��ֵ����   
		addressBook->persons[addressBook->size] = personInfo;
		addressBook->size++;

	}
	//�ر��ļ�
	fclose(f);
}
AddressBook addressBook;
int main() {
	//�ȴ����ṹ�����
	
	init(&addressBook);
	//���ϴ��ļ��������ݵ��߼�
	load(&addressBook);
	//����һ������ָ������
	Func arr[] = {
		NULL,
		showPersonInfo,
		addPersonInfo,
		findPersonInfo,
		deletePersonInfo,
		updatePersonInfo
	};
	while (1) {
		int choice = menu();
		if (choice < 0 || choice >= sizeof(arr)/sizeof(arr[0])) {
			printf("�Ƿ���choice!\n");
			continue; 
		}
		if (choice == 0) {
			printf("boodbye\n");
			break;
		}
		arr[choice](&addressBook);
	}
	return 0;
}