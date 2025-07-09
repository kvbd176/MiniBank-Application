#include<bits/stdc++.h>
using namespace std;

//Account class:(base class)

class account{

protected:
int accno;
string holdername;
double balance;

public:

account(int accountno,string hname,double b){
accno=accountno;
holdername=hname;
balance=b;
}

virtual void deposit(double amount){
balance+=amount;
cout<<"Deposit successful! Balance in account: "<<balance<<endl;
}

virtual void withdraw(double amount)=0;

virtual void displaydetail(){
cout<<"Account No: "<<accno<<endl;
cout<<"Holder Name: "<<holdername<<endl;
cout<<"Balance: "<<balance<<endl;
}

int getaccountno(){
return accno;
}

virtual ~account() {}
};

//Savings account class:(derived class)

class savings:public account{
double interestrate;
public:
savings(int accountno,string hname,double b,double rate=0.03): account(accountno,hname,b){
interestrate=rate;
}

void withdraw(double amount) override{
if(amount>balance) cout<<"Insufficient balance. Withdraw canceled!\n";
else{
balance-=amount;
cout<<"Remaining balance: "<<balance<<endl;
}
}


void displaydetail() override{
cout<<"*****Savings Account*****"<<endl;
account::displaydetail();
cout<<"Interest Rate: "<<(interestrate*100)<<"%"<<endl;
}
};

//Current account class:(derived class)

class current:public account{
double overdraftlimit;
public:
current(int accountno,string hname,double b,double overdraft=1000): account(accountno,hname,b){
overdraftlimit=overdraft;
}

void withdraw(double amount)override{
if(amount>balance+overdraftlimit) cout<<"Overdraft limit exceeded. Withdraw canceled!"<<endl;
else{
balance-=amount;
cout<<"Remaining balance: "<<balance<<endl;
}
}

void displaydetail() override{
cout<<"*****Current Account*****"<<endl;
account::displaydetail();
cout<<"Overdraft limit: "<<overdraftlimit<<endl;
}

};

//Bank system controller class

class banksystem{
vector<savings> savingaccount;
vector<current> currentaccount;
public:

void createaccount(){
int type,accnumber;
while (true){
accnumber=rand()%900000+100000; // range 100000–999999
bool exists=false;
for(auto &s:savingaccount){
if(s.getaccountno()==accnumber){
exists=true;
break;
}
}
if(!exists){
for(auto &c:currentaccount){
if(c.getaccountno()==accnumber){
exists=true;
break;
}
}
}
if(!exists) break; // Found a unique account number
}

string name;
double deposit;
cout<<"Choose Account Type (1.Savings | 2.Current): ";
cin>>type;
cout<<"Enter Holder Name: ";
cin.ignore();
getline(cin,name);
cout<<"Enter Initial Deposit: ";
cin>>deposit;
if(type==1){
savings s(accnumber,name,deposit);
s.displaydetail();
savingaccount.push_back(s);
}
else{
current c(accnumber,name,deposit);
c.displaydetail();
currentaccount.push_back(c);
}
cout<<"Account created successfully. Your Account Number is:"<<accnumber<<endl;
}

account* findaccount(int accnumber){
for(auto &s:savingaccount){
if(s.getaccountno()==accnumber) return &s;
}
for(auto &c:currentaccount){
if(c.getaccountno()==accnumber) return &c;
}
return nullptr;
}

void performdeposit(){
int accnumber;
double amount;
cout<<"Enter Account Number: "<<endl;
cin>>accnumber;
cout<<"Enter Deposit Amount: "<<endl;
cin>>amount;
account* a=findaccount(accnumber);
if(a) a->deposit(amount);
else cout<<"Account not found!"<<endl;
}

void performwithdrawl(){
int accnumber;
double amount;
cout<<"Enter Account Number: ";
cin>>accnumber;
cout<<"Enter Withdrawl Amount: ";
cin>>amount;
account *a=findaccount(accnumber);
if(a) a->withdraw(amount);
else cout<<"Account not found."<<endl;
}

void displayallaccounts(){
if(savingaccount.empty() && currentaccount.empty()){
cout<<"No accounts exist!"<<endl;
return;
}
for(auto &s:savingaccount) s.displaydetail();
cout<<endl;
for(auto &c:currentaccount) c.displaydetail();
cout<<endl;
}

void deleteaccount(){
int type,accnumber;
cout<<"Enter Account Number to delete: ";
cin>>accnumber;
cout<<"Enter Account Type (1.Savings | 2.Current): ";
cin>>type;
if(type==1){
int flag=0;
for(auto s=savingaccount.begin();s!=savingaccount.end();s++){
if(s->getaccountno()==accnumber){
savingaccount.erase(s);
cout<<"Savings Account Deleted Successfully!"<<endl;
flag=1;
break;
}
}
if(flag==0) cout<<"Savings account not found."<<endl;
}
else if(type==2){
int flag=0;
for(auto c=currentaccount.begin();c!=currentaccount.end();c++){
if(c->getaccountno()==accnumber){
currentaccount.erase(c);
cout<<"Current Account Deleted Successfully!"<<endl;
flag=1;
break;
}
}
if(flag==0) cout<<"Current account not found."<<endl;
}
else cout<<"Invalid account type entered. Try Again!"<<endl;
}

};

//Main section

int main(){
banksystem bank;
int c;
while(true){
cout<<"\n*****BANK MENU*****\n";
cout<<"1. Create Account\n";
cout<<"2. Deposit\n";
cout<<"3. Withdraw\n";
cout<<"4. View All Accounts\n";
cout<<"5. Delete Account\n";
cout<<"6. Exit\n";
cin>>c;
switch(c){
case 1: bank.createaccount(); break;
case 2: bank.performdeposit(); break;
case 3: bank.performwithdrawl(); break;
case 4: bank.displayallaccounts(); break;
case 5: bank.deleteaccount(); break;
case 6: cout<<"Thank you for using our Bank!\n"; return 0;
default: cout<<"Invalid Choice. Try Again!\n";
}
}
return 0;
}
