#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAX_VERTEX_NUM 100


class User {
	static unsigned id_auto;
public :
	unsigned id;
	string username;
	string password;
	string duty;
	User(string &u,string &p,string &d);
	void displsy();
};
unsigned User::id_auto = 0;

User::User(string &u, string &p, string &d){
	if (u.length() == 0) throw runtime_error("u length error");
	if (p.length() == 0) throw runtime_error("p length error");
	if (d.length() == 0) throw runtime_error("d length error");
	username = u;
	password = p;
	duty = d;
	id = ++id_auto;
}


void User::displsy() {
	cout << "id=" << id<<" username="<<username<<" duty="<<duty<<endl;
}



typedef enum{DG,DN,UDG,UDN} GraphKind;

class AdjMatrix {   
	vector<User*> vexs;
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum,arcnum;
	GraphKind kind;
	friend class Operations;
public:
	AdjMatrix();
	int AddVex(User *vex);
	int AddArc(int i,int j);
	void display();
};

AdjMatrix::AdjMatrix() {
	vexnum = 0;
	arcnum = 0;
	for (int i = 0;i < MAX_VERTEX_NUM;i++)
	{
		kind = UDG;
		for (int j = 0;j < MAX_VERTEX_NUM;j++)
		{
			arcs[i][j] = 0;
		}
	//	arcs[i][i] = 1;
	}
}

int AdjMatrix::AddVex(User *vex){
	vexs.push_back(vex);
	vexnum++;
	return 0;
}

int AdjMatrix::AddArc(int i,int j){
	arcs[i][j] = arcs[j][i] = 1;
	arcnum++;
	return 0;
}

void AdjMatrix::display(){
	/*for (int i = 0;i < vexnum;i++)
	{
		for (int j = 0;j < vexnum;j++)
		{
			cout << arcs[i][j] << ' ';
		}
		cout << endl;
	}*/
	
	for (vector<User*>::iterator iter = vexs.begin();iter != vexs.end();++iter){
		(*iter)->displsy();
	}
}

class Operations {
	AdjMatrix *g;
public:
	User *currentUser;
	Operations(AdjMatrix *G):currentUser(NULL),g(G){}
	int Login();
	int Register();
	void Logout();
	void show_menu();
	void show_operations();
	void makeFriend();
	void showPeople();
	void myFriend();
	int userIsExist(string &user);
	int userIsMyFriendByID(int id);
	User *getUserByUsername(string &user);
};

int Operations::Login(){
	
	cout << "Login as:";
	string buffer;
	fflush(stdin);
	cin >> buffer;
	if(!userIsExist(buffer)) {
		cout << buffer << " isn't exist!" << endl;
		show_menu();
		return 0;
	}
	User *user = getUserByUsername(buffer);

	Again: 
	cout << "Password:";
	fflush(stdin);
	cin >> buffer;
	if (user->password != buffer)
	{
		cout << "Access Denied" << endl;
		goto Again;
	}
	currentUser = user;
	return 1;
}

int Operations::Register() {
	string username;
	string password;
	string cpassword;
	string duty;
	uAgain:
	cout << "Enter Username:";
	fflush(stdin);
	cin >> username;
	if(userIsExist(username)) {
		cout << username << " has existed!" << endl;
		goto uAgain;
	}
	cout << "Enter Password:";
	fflush(stdin);
	cin >> password;
	cAgain:
	cout << "Confirm Password:";
	fflush(stdin);
	cin >> cpassword;
	if (password != cpassword) {
		cout << "error - not the same!" << endl;
		goto cAgain;
	}
	cout << "Enter Duty:";
	fflush(stdin);
	cin >> duty;

	User *user = new User(username,password,duty);
	g->AddVex(user);
	return 1;
}

void Operations::Logout() {
	currentUser = NULL;
}

void Operations::makeFriend() {
	int id;
	cout << "ID of your friend who you want to make:";
	fflush (stdin);
	cin >> id;
	if (currentUser->id == id) {
		cout << "Never kiss your own ass!" << endl;
		return ;
	}
	if (userIsMyFriendByID(id)) {
		cout << "This guy had been your friend yet!" << endl;
		return ;
	}
	g->AddArc(currentUser->id-1,id-1);
	cout << "OK,you are friend now!" << endl;
}
void Operations::showPeople() {
	g->display();
}
void Operations::myFriend() {
	int id = currentUser->id;
	for (int i = 0;i < g->vexnum;i++)
	{
		if(g->arcs[id-1][i]) {
			g->vexs[i]->displsy();
		}
	}
}

int Operations::userIsExist(string &user) {
	for (vector<User*>::iterator iter = g->vexs.begin();iter != g->vexs.end();++iter){
		if (user == (*iter)->username) return 1;
	}
	return 0;
}

int Operations::userIsMyFriendByID(int id){
	int myid = currentUser->id;
	return g->arcs[myid-1][id-1];
}

User *Operations::getUserByUsername(string &user) {
	for (vector<User*>::iterator iter = g->vexs.begin();iter != g->vexs.end();++iter){
		if (user == (*iter)->username) return *iter;
	}
	return NULL;
}

void Operations::show_menu(){
	cout << "======================================================" << endl;
	cout << "==   1.Login     2.Register     3.Exit              ==" << endl;
	cout << "======================================================" << endl;
}

void Operations::show_operations() {
	cout << "=====================================================================" << endl;
	cout << "==  1.My friend   2.Show people  3.Make friend  4.Logout  5.Exit   ==" << endl;
	cout << "=====================================================================" << endl;
}

int main()
{
	AdjMatrix G;
	User *user[5];
	try {
		user[0] = new User(string("Obama"),string("111"),string("USA Present"));
		user[1] = new User(string("HuGe"),string("222"),string("China Chairman"));
		user[2] = new User(string("PuJing"),string("333"),string("Russia Present"));
		user[3] = new User(string("Hitler"),string("444"),string("Genmany Present"));
		user[4] = new User(string("LinKen"),string("555"),string("USA Old Present"));
	}catch(runtime_error e){
		cout << e.what() << endl;
	}

	for (int i = 0;i < 5;i++)
	{
		G.AddVex(user[i]);
	}
	G.AddArc(0,1);
	G.AddArc(0,2);
	G.AddArc(0,4);
	G.AddArc(1,3);
	G.AddArc(2,3);
	

	Operations op(&G);
	
	string buf = "";
	int ch;
	while(1) {
		if (buf.length() && op.currentUser) {
			op.show_operations();
			cout << buf;
			cin >> ch;
			switch (ch)
			{
			case 1:
				op.myFriend();
				break;
			case 2:
				op.showPeople();
				break;
			case 3:
				op.makeFriend();
				break;
			case 4:
				op.Logout();
				buf = "";
				break;
			case 5:
				exit(0);
				break;
			default:
				break;
			}
		}
		else {
			op.show_menu();
			cout << "Not Logged In:";
			cin >> ch;
			switch (ch)
			{
			case 1:
				if(op.Login()) buf = op.currentUser->username+":";
				break;
			case 2:
				op.Register();
				break;
			case 3:
				exit(0);
				break;
			default:
				break;
			}
		}
	}
	system("pause");
	return 0;
}
