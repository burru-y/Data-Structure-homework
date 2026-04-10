#include<iostream>
#include<string>
using namespace std;

// 联系人结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

// 链表节点结构体
struct Node {
	Person person;
	Node* next;
};

// 通讯录结构体
struct Addressbooks {
	Node* head;      // 头指针
	int m_Size;      // 联系人数量
};

// 显示菜单
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

// 添加联系人
void addPerson(Addressbooks* abs)
{
	// 创建新节点
	Node* newNode = new Node;

	// 姓名
	string name;
	cout << "请输入姓名：" << endl;
	cin >> name;
	newNode->person.m_Name = name;

	// 性别
	cout << "请输入性别：" << endl;
	cout << "1---男" << endl;
	cout << "2---女" << endl;
	int sex = 0;
	cin >> sex;
	while (true) {
		if (sex == 1 || sex == 2) {
			newNode->person.m_Sex = sex;
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
			cin >> sex;
		}
	}

	// 年龄
	cout << "请输入年龄：" << endl;
	int age = 0;
	cin >> age;
	newNode->person.m_Age = age;

	// 电话
	cout << "请输入联系电话：" << endl;
	string phone;
	cin >> phone;
	newNode->person.m_Phone = phone;

	// 住址
	cout << "请输入家庭住址：" << endl;
	string address;
	cin >> address;
	newNode->person.m_Addr = address;

	// 将新节点插入链表尾部
	newNode->next = nullptr;
	if (abs->head == nullptr) {
		// 链表为空，新节点作为头节点
		abs->head = newNode;
	}
	else {
		// 找到链表尾部
		Node* temp = abs->head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	abs->m_Size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

// 显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		Node* temp = abs->head;
		int index = 1;
		while (temp != nullptr) {
			cout << index << ":";
			cout << "姓名：" << temp->person.m_Name << "  ";
			cout << "性别：" << (temp->person.m_Sex == 1 ? "男" : "女") << "  ";
			cout << "年龄：" << temp->person.m_Age << "  ";
			cout << "电话：" << temp->person.m_Phone << "  ";
			cout << "住址：" << temp->person.m_Addr << endl;
			temp = temp->next;
			index++;
		}
	}
	system("pause");
	system("cls");
}

// 检测联系人是否存在，返回节点指针，不存在返回nullptr
Node* isExist(Addressbooks* abs, string name)
{
	Node* temp = abs->head;
	while (temp != nullptr) {
		if (temp->person.m_Name == name) {
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}

// 删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人：" << endl;
	string name;
	cin >> name;

	if (abs->head == nullptr) {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
		return;
	}

	if (abs->head->person.m_Name == name) {
		Node* temp = abs->head;
		abs->head = abs->head->next;
		delete temp;
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		Node* prev = abs->head;
		Node* curr = abs->head->next;
		while (curr != nullptr) {
			if (curr->person.m_Name == name) {
				prev->next = curr->next;
				delete curr;
				abs->m_Size--;
				cout << "删除成功" << endl;
				system("pause");
				system("cls");
				return;
			}
			prev = curr;
			curr = curr->next;
		}
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

// 查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	Node* result = isExist(abs, name);
	if (result != nullptr) {
		cout << "姓名：" << result->person.m_Name << "  ";
		cout << "性别：" << (result->person.m_Sex == 1 ? "男" : "女") << "  ";
		cout << "年龄：" << result->person.m_Age << "  ";
		cout << "电话：" << result->person.m_Phone << "  ";
		cout << "住址：" << result->person.m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

// 修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	Node* result = isExist(abs, name);
	if (result != nullptr) {
		// 姓名
		string newName;
		cout << "请输入姓名：" << endl;
		cin >> newName;
		result->person.m_Name = newName;

		// 性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		string sex = "0";
		cin >> sex;
		while (true) {
			if (sex == "1" || sex == "2") {
				result->person.m_Sex = sex[0] - '0';
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
			cin >> sex;
		}

		// 年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		result->person.m_Age = age;

		// 电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		result->person.m_Phone = phone;

		// 住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		result->person.m_Addr = address;

		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
}

// 清空联系人
void cleanPerson(Addressbooks* abs)
{
	int sure = 0;
	cout << "确定清空(是--1  否--2)：" << endl;
	cin >> sure;
	while (sure != 1 && sure != 2) {
		cout << "输入错误" << endl;
		system("pause");
		system("cls");
		showMenu();
		cout << "确定清空(是--1  否--2)：" << endl;
		cin >> sure;
	}
	if (sure == 1) {
		// 释放所有节点
		Node* temp = abs->head;
		while (temp != nullptr) {
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
		abs->head = nullptr;
		abs->m_Size = 0;
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

int main() {
	Addressbooks abs;
	abs.head = nullptr;
	abs.m_Size = 0;

	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1: // 1、添加联系人
			addPerson(&abs);
			break;
		case 2: // 2、显示联系人
			showPerson(&abs);
			break;
		case 3: // 3、删除联系人
			deletePerson(&abs);
			break;
		case 4: // 4、查找联系人
			findPerson(&abs);
			break;
		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			// 退出前释放所有内存
			{
				Node* temp = abs.head;
				while (temp != nullptr) {
					Node* next = temp->next;
					delete temp;
					temp = next;
				}
			}
			return 0;
			break;
		}
	}

	return 0;
}
