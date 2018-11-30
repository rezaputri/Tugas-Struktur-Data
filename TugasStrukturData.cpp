#include <iostream>
#include <string>

using namespace std;

#define MAX_CAP 3

typedef struct{
	int no;
	char nama[30];
	char posisi[15];
} pemain;

typedef struct{
	int tos;
	pemain stack_array[MAX_CAP];
} StackRecord;

typedef StackRecord Stack;

void initStack(Stack &s){
	s.tos = - 1;
}

int isEmpty(Stack s){
	return s.tos == -1;
}

int isFull(Stack s){
	return s.tos == MAX_CAP -1;
}

void push(Stack &s, pemain val){
	if(isFull(s)){
		cout<<"-----------------------------"<<endl;
		cout<<"Stack Overflow ....."<<endl;
		cout<<"-----------------------------"<<endl;
	} else {
		s.tos++;
		s.stack_array[s.tos] = val;
	}
}

pemain pop(Stack &s){
	pemain temp;

	if(isEmpty(s)){
		cout<<"-----------------------------"<<endl;
		cout<<"Stack Underflow ....."<<endl;
		cout<<"-----------------------------"<<endl;
	} else {
		temp = s.stack_array[s.tos];
		s.tos--;
		cout<<"-----------------------------"<<endl;
		cout<<"Data Sudah dihapus"<<endl;
		cout<<"-----------------------------"<<endl;
		return temp;
	}
}

void ShowStackElements(Stack s){
	pemain temp;

	if(isEmpty(s)){
		cout<<"-----------------------------"<<endl;
		cout<<"\nStack Masih Kosong"<<endl;
		cout<<"-----------------------------"<<endl;
	} else {
		cout<<"---------------------------"<<endl;
		cout<<"         Data Pemain       "<<endl;
		cout<<"---------------------------"<<endl;
		while(!isEmpty(s)){
			temp = s.stack_array[s.tos];
			s.tos--;
			cout<<"\n";
			cout<<"\nNo Punggung : "<<temp.no;
			cout<<"\nNama Pemain : "<<temp.nama;
			cout<<"\nPosisi      : "<<temp.posisi<<endl;
		}
	}
}

int main(){
	Stack data;
	pemain pmn;
	initStack(data);
	int pilih;

do{
	cout<<endl;
	cout<<"-----------------------------\n";
	cout<<"1. Push Pemain"<<endl;
	cout<<"2. Pop Pemain"<<endl;
	cout<<"3. Tampil Pemain"<<endl;
	cout<<"4. Keluar Perogram"<<endl<<endl;
	cout<<"-----------------------------\n";
	cout<<"Pilih Menu : "; cin>>pilih;
	cout<<"-----------------------------"<<endl;

	switch(pilih){
	case 1 :
		cout<<"-----------------------------"<<endl;
		cout<<"      Input Data Pemain      "<<endl;		
		cout<<"Nomor Punggung : "; cin>> pmn.no;
		cout<<"Nama Pemain    : "; cin>> pmn.nama;
		cout<<"Posisi Pemain  : "; cin>> pmn.posisi;
		push(data, pmn);
		system("CLS");
		break;
	case 2 :
		system("CLS");
		pop(data);
		break;
		system("CLS");
	case 3 : 
		system("CLS");
		ShowStackElements(data);	
		break;
	default :
		exit(0);
		break;
		}
	} while(pilih!=4);
}
