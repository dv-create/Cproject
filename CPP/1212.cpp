// #include<iostream>
// #include<cstring>

// using namespace std;
// const int NAME_LEN=20;

// //프로그램 사용자의 선택 메뉴
// enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// //신용등급
// enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

// //계좌의 종류
// enum {NORMAL=1, CREDIT=2};

// class Account
// {
// private:
//     int accID;
//     int balance;
//     char* cusName;

// public:
//     Account(int ID, int money, char* name);
//     Account(const Account &ref);

//     int GetAccID() const;
//     virtual void Deposit (int money);
//     int Withdraw(int money);
//     void ShowAccInfo() const;
//     ~Account();
// };

// Account::Account(int ID, int money, char* name)
//     : accID(ID), balance(money)
// {
//     cusName=new char[strlen(name)+1];
//     strcpy(cusName, name);
// }

// Account::Account(const Account &ref)
//     : accID(ref.accID), balance(ref.balance)
// {
//     cusName=new char[strlen(ref.cusName)+1];
//     strcpy(cusName, ref.cusName);
// }

// int Account::GetAccID() const {return accID;}

// void Account::Deposit(int money)
// {
//     balance+=money;
// }

// int Account::Withdraw(int money)
// {
//     if(balance<money)
//         return 0;

//     balance-=money;
//     return money;
// }

// void Account::ShowAccInfo() const{
//     cout<<"계좌IC: "<<accID<<endl;
//     cout<<"이 름: "<<cusName<<endl;
//     cout<<"잔 액: "<<balance<<endl;
// }

// Account::~Account()
// {
//     delete []cusName;
// }

// class NormalAccount:public Account      //Account클래스를 상속받는 자식클래스
// {
// private:
//     int interRate;      //이자율 %
// public:
//     NormalAccount(int ID, int money, char* name, int rate)
//         :Account(ID, money, name), interRate(rate)
//     { }

//     virtual void Deposit(int money)
//     {
//         Account::Deposit(money);
//         Account::Deposit(money*(interRate/100.0));
//     }
// };

// class HighCreditAccount:public NormalAccount        //NormalAccount클래스 상속
// {
// private:
//     int specialRate;        //특별이자
// public:
//     HighCreditAccount(int ID, int money, char* name, int rate, int special)
//         :NormalAccount(ID, money, name, rate), specialRate(special)
//     { }

//     virtual void Deposit(int money)
//     {
//         NormalAccount::Deposit(money);      //원금과 이자 추가
//         Account::Deposit(money*(specialRate/100.0));        //특별이자 추가
//     }
// };

// class AccountHandler
// {
// private:
//     Account* accArr[100];
//     int accNum;

// public:
//     AccountHandler();
//     void ShowMenu(void) const;
//     void MakeAccount(void);
//     void DepositMoney(void);
//     void WithdrawMoney(void);
//     void ShowAllAccInfo(void) const;
//     ~AccountHandler();

// protected:      //??
//     void MakeNormalAccount(void);
//     void MakeCreditAccount(void);
// };

// void AccountHandler::ShowMenu(void) const
// {
//     cout<<"-----Menu-----"<<endl;
//     cout<<"1. 계좌개설"<<endl;
//     cout<<"2. 입 금"<<endl;
//     cout<<"3. 출 금"<<endl;
//     cout<<"4. 계좌정보 전체 출력"<<endl;
//     cout<<"5. 프로그램 종료"<<endl;
// }

// void AccountHandler::MakeAccount(void)      //리모콘 등록할때 쓸지도...?
// {
//     int sel;
//     cout<<"[계좌종류선택]"<<endl;
//     cout<<"1.보통예금계좌";
//     cout<<"2.신용신뢰계좌"<<endl;
//     cout<<"선택: ";
//     cin>>sel;

//     if(sel==NORMAL)     //열거형으로 NORMAL에는 1값이 저장되어있음. 1이라면
//         MakeNormalAccount();    //보통 계좌 함수 호출
//     else                //1이 아니라면
//         MakeCreditAccount();    //신용 계좌 함수 호출
// }

// void AccountHandler::MakeNormalAccount(void)        //보통예금계좌 개설용 함수
// {
//     int id;
//     char name[NAME_LEN];
//     int balance;
//     int interRate;

//     cout<<"[보통예금계좌 개설]"<<endl;
//     cout<<"계좌ID: "; cin>>id;
//     cout<<"이 름: "; cin>>name;
//     cout<<"입금액: "; cin>>balance;
//     cout<<"이자율: "; cin>>interRate;
//     cout<<endl;

//     accArr[accNum++]=new NormalAccount(id, balance, name, interRate);
// }

// void AccountHandler::MakeCreditAccount(void)        //신용신뢰계좌 개설용 함수
// {
//     int id;
//     char name[NAME_LEN];
//     int balance;
//     int interRate;
//     int creditLevel;        //신용신뢰 계좌이므로 신용등급 변수를 새로 추가

//     cout<<"[신용신뢰계좌 개설]"<<endl;
//     cout<<"계좌ID: "; cin>>id;
//     cout<<"이 름: "; cin>>name;
//     cout<<"입금액: "; cin>>balance;
//     cout<<"이자율: "; cin>>interRate;
//     cout<<"신용등급(1toA, 2toB, 3toC): "; cin>>creditLevel;
//     cout<<endl;

//     switch(creditLevel)
//     {
//     case 1:
//         accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_A);  //7
//         break;
//     case 2:
//         accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_B);  //4
//         break;
//     case 3:
//         accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_C);  //2
//         break;
//     }
// }

// void AccountHandler::DepositMoney(void)
// {
//     int money;
//     int id;
//     cout<<"[입   금]"<<endl;
//     cout<<"계좌ID: "; cin>>id;
//     cout<<"입급액 ";cin>>money;

//     for(int i=0; i<accNum; i++)
//     {
//         if(accArr[i]->GetAccID()==id)
//         {
//             accArr[i]->Deposit(money);
//             cout<<"입금완료"<<endl<<endl;
//             return;
//         }
//     }
//     cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
// }

//버추얼 선언했을 때 맨 아래 있는게 실행

#include<iostream>
using namespace std;

class AAA
{
private:
    int num1;
public:
    virtual void Func1(){cout<<"Func1"<<endl;}  //가상함수로 선언
    virtual void Func2(){cout<<"Func2"<<endl;}  //가상함수로 선언
};

class BBB:public AAA        //상속클래스
{
private:
    int num2;
public:
    virtual void Func1() {cout<<"BBB::Func1"<<endl;}    //오버라이딩을 통해 출력값 바꿈
    void Func3(){cout<<"Func3"<<endl;}                  //Func3이라는 함수를 새로 선언
};

int main(void)
{
    AAA* aptr=new AAA();        //aptr을 AAA클래스 자료형으로 선언
    aptr->Func1();
    //aptr이 가리키는 Func1을 호출(오버라이딩 무관하게 AAA에서 선언된 내용) 

    BBB* bptr=new BBB();
    bptr->Func1();

    return 0;
}       //가상함수를 써야 오버라이딩이 정상작동 하나보다.