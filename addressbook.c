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
	PersonInfo* persons;//改成指针的形式,通过动态内存管理来实现
	//通过size表示persons数组中实际有效的元素
	//[0,size)范围的元素是有效元素
	int size;
	int capacity;
	//capacity表示当前persons对应的空间最大容量
}AddressBook;
extern void save(AddressBook* addressBook);
extern void load(AddressBook* addressBook);
void init(AddressBook* addressBook) { 
	//memset(addressBook->persons, 0, sizeof(addressBook->persons));

	//addressBook->size = 0;
	//显式的申请内存空间
	addressBook->size = 0;
	addressBook->capacity = 200;
	addressBook->persons = (PersonInfo*)malloc(addressBook->capacity * sizeof(PersonInfo));
	//如果不被初始化,VS的debug模式下会被初始化为"屯屯屯" 
	//memset(addressBook->persons, 0, sizeof(PersonInfo) * addressBook->capacity);
}
int menu(){
	printf("====================\n");
	printf("欢迎使用通讯录程序\n");
	printf("1. 查看所有联系人\n");
	printf("2. 新增联系人\n");
	printf("3. 根据名字查找联系人\n");
	printf("4. 删除联系人\n");
	printf("5. 修改联系人信息\n");
	printf("0. 退出\n");
	printf("====================\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void showPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	//只需要把每个联系人信息打印出来即可
	printf("查看所有联系人...\n\n");
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		printf("[%d]%s\t%s\n",i, p->name, p->phone);
	}
	printf("\n共显示了%d条数据\n", addressBook->size);
}
void addPersonInfo(AddressBook* addressBook) {
	//把新联系人的信息放在下标为size位置的元素上
	printf("新增联系人...\n\n");
	if (addressBook->size >= addressBook->capacity) {
		//联系人已经满了
		//printf("新增失败！联系人已满！\n");
		//进行动态扩容
		addressBook->capacity += 100;
		//重新申请内存空间
		//addressBook->persons = realloc(addressBook->persons, addressBook->capacity * sizeof(PersonInfo));
		//直接使用realloc比较简单方便
		//也可以使用malloc手动实现
		PersonInfo* old = addressBook->persons;
		addressBook->persons = (PersonInfo*)malloc(addressBook->capacity * sizeof(PersonInfo));
		//把旧的数据拷贝到新的内存空间上
		memcpy(addressBook->persons, old, sizeof(PersonInfo) * addressBook->size);
		//释放旧空间
		free(old);
		//return;
	}
	PersonInfo* p = &addressBook->persons[addressBook->size];
	printf("请输入新联系人的姓名:\n");
	scanf("%s",p->name );
	printf("请输入新联系人的电话:\n");
	scanf("%s", p->phone);
	//自增size
	addressBook->size++;
	//保存数据到磁盘
	save(addressBook);
	printf("\n新增联系人成功!\n\n");
}
void findPersonInfo(AddressBook* addressBook) {
	//根据姓名找电话
	assert(addressBook != NULL);
	printf("根据姓名查找联系人!\n\n");
	printf("请输入要查找的姓名:");
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		if (strcmp(p->name, name) == 0) {
			//有重名的情况,所以不能加break,要都打印出来
			printf("[%d]%s\t\t%s\n", i, p->name, p->phone); 
			count++;
		}
	}
	printf("\n查找完成!共查找到%d条记录\n\n",count);
}
void deletePersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	printf("删除联系人!\n\n");
	printf("请输入要删除联系人的序号:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressBook->size) {
		printf("您输入的id有误!删除联系人失败!\n");
		return;
	}
	if (id == addressBook->size - 1) {
		//此时要删最后一个元素
		addressBook->size--;
		printf("\n删除成功!\n\n");
		return;
	}
	//删除中间元素,把最后的元素给拷贝到中间元素位置上
	addressBook->persons[id] =addressBook->persons[addressBook->size - 1];
	//删除末尾元素
	addressBook->size--;

	save(addressBook);
	printf("\n删除成功!\n\n");
}
void updatePersonInfo(AddressBook* addressBook) {
	//修改联系人.根据用户输入的序号来决定修改哪个记录
	assert(addressBook != NULL);
	printf("请修改联系人信息!\n\n");
	printf("请输入要修改的联系人序号:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressBook->size) {
		printf("您输入的id有误!修改联系人失败!\n");
		return;
	}
	//先取出联系人的结构体变量
	PersonInfo* p = &addressBook->persons[id];
	printf("如果需要保持不变,请直接输入*");
	printf("请输入新的联系人的姓名:");
	char name[1024] = { 0 };
	//我们发现使用scanf不太行,直接输入回车,scanf无法返回
	//我们可以使用gets替代
	scanf("%s", &name);
	//gets(name);
	if (strcmp(name, "*") != 0) {
		//如果用户输入的不是回车,把name拷贝到结构体中
		strcpy(p->name, name);
	}
	printf("请输入新的联系人电话:");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	//gets(phone);
	if (strcmp(name, "*") != 0) {
		strcpy(p->phone, phone);
	}

	save(addressBook);
	printf("修改联系人完成!\n");
}
//void quit(AddressBook* addressBook) {
//	printf("googbye\n");
//	//完全相当于main函数中的return 0.
//	//本质上就是结束当前进程.
//	exit(0);
//	return;
//}
typedef void(*Func)(AddressBook*);
///////////////////////////////////////////
//创建一组函数完成保存到文件抑菌剂从文件加载数据
///////////////////////////////////////////
void save(AddressBook* addressBook) {
	//把通讯录的内容保存到文件中
	//打开文件
	FILE* f = fopen("d:/AddressBook.txt", "w");
	if (f == NULL) {
		perror("文件打开失败");
		return;
	}
	//写入内容
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		fwrite(p, sizeof(PersonInfo), 1, f);
	}
	fclose(f);
}
void load(AddressBook* addressBook) {
	//从文件加载通讯录的内容
	//打开文件
	FILE* f = fopen("d:/AddressBook.txt", "r");
	if (f == NULL) {
		printf("当前文件尚未创建!\n");
		return;
	}
	while (1) {
		PersonInfo personInfo = { 0 };
		size_t len = fread(&personInfo, sizeof(PersonInfo), 1, f);
		if (len == 0) {
			printf("读取完毕\n");
			break;
		}
		//把personInfo这个变量给加到结构体的数组里面去
		if (addressBook->size >= addressBook->capacity) {
			//先扩容
			PersonInfo* old = addressBook->persons;
			addressBook->capacity += 100;
			addressBook->persons = (PersonInfo*)malloc(addressBook->capacity * sizeof(PersonInfo));
			memcpy(addressBook->persons, old, addressBook->size * sizeof(PersonInfo));
			free(old);
				
		}
		//赋值数据   
		addressBook->persons[addressBook->size] = personInfo;
		addressBook->size++;

	}
	//关闭文件
	fclose(f);
}
AddressBook addressBook;
int main() {
	//先创建结构体变量
	
	init(&addressBook);
	//加上从文件加载数据的逻辑
	load(&addressBook);
	//创建一个函数指针数组
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
			printf("非法的choice!\n");
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