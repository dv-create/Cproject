// #include<iostream>      //같은 이름의 다른 함수 사용
// using namespace std;
// void MyFunc(void)
// {
//     std::cout<<"MyFunc(void) called"<<std::endl;
// }
// void MyFunc(char c)
// {
//     std::cout<<"MyFunc(char c) called"<<std::endl;
// }
// void MyFunc(int a, int b)
// {
//     std::cout<<"MyFunc(int a, int b) called"<<std::endl;
// }
// int main(void)
// {
//     MyFunc();
//     MyFunc('A');
//     MyFunc(12,13);
//     return 0;
// }

// #include<iostream>          //값 서로 바꾸는 함수 만들기
// using namespace std;
// void swap(int* num1, int* num2)
// {
//     int temp= *num1;
//     *num1=*num2;
//     *num2=temp;
// }

// void swap(char* ch1, char* ch2)
// {
//     char temp=*ch1;
//     *ch1=*ch2;
//     *ch2=temp;
// }

// void swap(double* dbl1, double* dbl2)
// {
//     double temp=*dbl1;
//     *dbl1=*dbl2;
//     *dbl2=temp;
// }

// int main(void)
// {
//     int num1=20, num2=30;
//     swap(&num1, &num2);
//     std::cout<<num1<<' '<<num2<<std::endl;

//     char ch1='A', ch2='Z';
//     swap(&ch1, &ch2);
//     std::cout<<ch1<<' '<<ch2<<std::endl;

//     double dbl1=1.111, dbl2=5.555;
//     swap(&dbl1, &dbl2);
//     std::cout<<dbl1<<' '<<dbl2<<std::endl;
//     return 0;
// }

// #include<iostream>      //디폴트값 사용해보기

// int Adder(int num1=1, int num2=2)       //Adder 함수의 디폴트 값으로 1과 2를 설정
// {
//     return num1+num2;
// }

// int main(void)
// {
//     std::cout<<Adder()<<std::endl;      //인자 전달 안하기
//     std::cout<<Adder(3)<<std::endl;     //num1에만 3 전달
//     std::cout<<Adder(3,5)<<std::endl;   //3, 5 전달
//     return 0;
// }

// #include<iostream>          //이름공간 알아보기

// namespace BestComImpl           //BestEomImpl이라는 이름의 공간 마련
// {
//     void SimpleFunc(void)       //그 공간에 SimpleFunc이라는 함수 정의
//     {
//         std::cout<<"BestCom이 정의한 함수"<<std::endl;      
//     }
// }

// namespace ProgComImpl           //ProgEomImpl이라는 이름의 공간 마련
// {
//     void SimpleFunc(void)       //그 공간에 SimpleFunc이라는 한수 정의
//     {
//         std::cout<<"ProgCom이 정의한 함수"<<std::endl;
//     }
// }

// int main(void)
// {
//     BestComImpl::SimpleFunc();  //이름공간 BestComImpl 내에 정의된 함수 SimpleFunc을 호출
//     ProgComImpl::SimpleFunc();  //이름공간 ProgComImpl 내에 정의된 함수 SimpleFunc을 호출
//     return 0;
// }

// #include<iostream>

// namespace BestComImpl       //BestComImpl이라는 이름공간 안에서 함수의 선언만 삽입
// {
//     void SimpleFunc(void);
// }

// namespace ProgComImpl       //ProgComImpl이라는 이름공간 안에서 함수의 선언만 삽입
// {
//     void SimpleFunc(void);
// }

// int main(void)              //함수 호출
// {
//     BestComImpl::SimpleFunc();
//     BestComImpl::SimpleFunc();
//     return 0;
// }

// void BestComImpl::SimpleFunc(void)      //함수 정의를 나중에 하기
// {
//     std::cout<<"BestCom이 정의한 함수"<<std::endl;
// }

// void ProgComImpl::SimpleFunc(void)
// {
//     std::cout<<"ProgCom이 정의한 함수"<<std::endl;
// }

// #include<iostream>
// #include<cstring>

// using namespace std;
// const int NAME_LEN=20;

// void ShowMenu(void);
// void MakeAccount(void);
// void DepositMoney(void);
// void WithdrawMoney(void);
// void ShowAllAccInfo(void);

// enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// typedef struct
// {
//     int accID;
//     int balance;
//     char cusName[NAME_LEN];
// }Account;

// Account accArr[100];
// int accNum=0;

// int main(void)
// {
//     int choice;

//     while(1)
//     {
//         ShowMenu();
//         cout<<"선택: ";
//         cin>>choice;
//         cout<<endl;

//         switch(choice)
//         {
//             case MAKE:
//                 MakeAccount();
//                 break;
//             case DEPOSIT:
//                 DepositMoney();
//                 break;
//             case WITHDRAW:
//                 WithdrawMoney();
//                 break;
//             case INQUIRE:
//                 ShowAllAccInfo();
//                 break;
//             case EXIT:
//                 return 0;
//             default:
//                 cout<<"Illegal selection.."<<endl;
//         }
//     }
//     return 0;
// }

// void ShowMenu(void)     //메뉴 출력
// {
//     cout<<"-----Menu-----"<<endl;
//     cout<<"1. 계좌개설"<<endl;
//     cout<<"2. 입 금"<<endl;
//     cout<<"3. 출 금"<<endl;
//     cout<<"4. 계좌정보 전체 출력"<<endl;
//     cout<<"5. 프로그램 종료"<<endl;
// }

// void MakeAccount(void)      //계좌개설
// {
//     int id;
//     char name[NAME_LEN];
//     int balance;

//     cout<<"[계좌개설]"<<endl;
//     cout<<"계좌ID: "; cin>>id;
//     cout<<"이 름: "; cin>>name;
//     cout<<"입금액: "; cin>>balance;
//     cout<<endl;

//     accArr[accNum].accID=id;
//     accArr[accNum].balance=balance;
//     strcpy(accArr[accNum].cusName, name);
//     accNum++;
// }

// void DepositMoney(void)     //입금
// {
//     int money;
//     int id;
//     cout<<"[입 금]"<<endl;
//     cout<<"계좌ID: "; cin>>id;
//     cout<<"입금액: "; cin>>money;

//     for(int i=0; i<accNum; i++)
//     {
//         if(accArr[i].accID==id)
//         {
//             accArr[i].balance+=money;
//             cout<<"입금완료"<<endl<<endl;
//             return;
//         }
//     }
//     cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
// }

// void WithdrawMoney(void)        //출금
// {
//     int money;
//     int id;
//     cout<<"[출   금]"<<endl;
//     cout<<"계좌ID: "; cin>>id;
//     cout<<"계좌ID: "; cin>>id;
//     cout<<"출금액: "; cin>>money;

//     for(int i=0; i<accNum; i++)
//     {
//         if(accArr[i].accID==id)
//         {
//             if(accArr[i].balance<money)
//             {
//                 cout<<"잔액부족"<<endl<<endl;
//                 return;
//             }

//             accArr[i].balance-=money;
//             cout<<"출금완료"<<endl<<endl;
//             return;
//         }
//     }
//     cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
// }

// void ShowAllAccInfo(void)       //잔액조회
// {
//     for(int i=0; i<accNum; i++)
//     {
//         cout<<"계좌ID: "<<accArr[i].accID<<endl;
//         cout<<"이 름: "<<accArr[i].cusName<<endl;
//         cout<<"잔 액: "<<accArr[i].balance<<endl<<endl;
//     }
// }

// #include<iostream>      //참조자 알아보기(자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름)
// using namespace std;

// int main(void)
// {
//     int num1=1020;
//     int &num2=num1;     //num1에 대한 참조자 num2를 선언, num1과 num2가 동일한 메모리 공간 참조

//     num2=3047;
//     cout<<"VAL: "<<num1<<endl;      //num1값 출력
//     cout<<"REF: "<<num2<<endl;      //num2값 출력

//     cout<<"VAL: "<<&num1<<endl;      //num1의 주소값 출력
//     cout<<"REF: "<<&num2<<endl;      //num2의 주소값 출력

//     return 0;
// }

//참조자의 선언 가능범위:변수
//불가능: 상수, 선언후 참조, NULL

// #include<iostream>
// using namespace std;

// int main(void)
// {
//     int arr[3]={1, 3, 5};
//     int &ref1=arr[0];    //배열의 요소는 변수로 간주됨
//     int &ref2=arr[1];
//     int &ref3=arr[2];

//     cout<<ref1<<endl;
//     cout<<ref2<<endl;
//     cout<<ref3<<endl;

//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main(void)
// {
//     int num=12;
//     int* ptr=&num;
//     int** dptr=&ptr;

//     int &ref=num;           //num의 주소값을 &ref에 대입
//     int *(&pref)=ptr;       //
//     int **(&dpref)=dptr;

//     cout<<ref<<endl;
//     cout<<*pref<<endl;
//     cout<<**dpref<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// void SwapByRef2(int &ref1, int &ref2)
// {
//     int temp=ref1;
//     ref1=ref2;
//     ref2=temp;
// }

// int main(void)
// {
//     int val1=10;
//     int val2=20;

//     SwapByRef2(val1, val2);     //매개변수로 참조자가 선언되었으니, 참조의 대상이 될 변수를 인자로 전달
//     cout<<"val1: "<<val1<<endl;
//     cout<<"val2: "<<val2<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int& RefRetFuncOne(int &ref)    //참조자를 전달받음
// {
//     ref++;          //참조자 1증가
//     return ref;
// }

// int main(void)
// {
//     int num1=1;
//     int &num2=RefRetFuncOne(num1);  //함수가 참조가를 반환한 값을 다시 참조자에 저장

//     num1++;     //num1 1증가
//     num2++;     //num1의 참조자 num2 1증가
//     cout<<"num1: "<<num1<<endl;
//     cout<<"num2: "<<num2<<endl;
//     return 0;
// }

// #include<iostream>
// #include<string.h>
// using namespace std;

// char* MakeStrAdr(int len)
// {
//     char* str=new char[len];
//     return str;
// }

// int main(void)
// {
//     char* str=MakeStrAdr(20);
//     strcpy(str, "I am so happy~");
//     cout<<str<<endl;
//     delete []str;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// #define ID_LEN 20
// #define MAX_SPD 200
// #define FUEL_STEP 2
// #define ACC_STEP 10
// #define BRK_STEP 10

// struct Car
// {
//     char gamerID[ID_LEN];
//     int fuelGauge;
//     int curSpeed;
// };

// void ShowCarState(const Car &car)
// {
//     cout<<"소유자ID: "<<car.gamerID<<endl;
//     cout<<"연료량: "<<car.fuelGauge<<"%"<<endl;
//     cout<<"현재속도: "<<car.curSpeed<<"km/s"<<endl<<endl;
// }

// void Accel(Car &car)
// {
//     if(car.fuelGauge<=0)
//         return;
//     else
//         car.fuelGauge-=FUEL_STEP;
    
//     if(car.curSpeed+ACC_STEP>=MAX_SPD)
//     {
//         car.curSpeed=MAX_SPD;
//         return;
//     }

//     car.curSpeed+=ACC_STEP;
// }

// void Break(Car &car)
// {
//     if(car.curSpeed<BRK_STEP)
//     {
//         car.curSpeed=0;
//         return;
//     }

//     car.curSpeed-=BRK_STEP;
// }

// int main(void)
// {
//     Car run99={"run99", 100, 0};
//     Accel(run99);
//     Accel(run99);
//     ShowCarState(run99);
//     Break(run99);
//     ShowCarState(run99);

//     Car sped77={"sped77", 100, 0};
//     Accel(sped77);
//     Break(sped77);
//     ShowCarState(sped77);
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// using namespace std;

// namespace CAR_CONST
// {
//     enum
//     {
//         ID_LEN=20, MAX_SPD=200, FUEL_STEP=2,
//         ACC_STEP=10, BRK_STEP=10
//     };
// }

// class Car
// {
// private:
//     char gamerID[CAR_CONST::ID_LEN];
//     int fuelGauge;
//     int curSpeed;
// public:
//     void InitMembers(char* ID, int fuel);
//     void ShowCarState();
//     void Accel();
//     void Break();
// };

// void Car::InitMembers(char* ID, int fuel)
// {
//     strcpy(gamerID, ID);
//     fuelGauge=fuel;
//     curSpeed=0;
// }
// void Car::ShowCarState()
// {
//     cout<<"소유자ID: "<<gamerID<<endl;
//     cout<<"연료량: "<<fuelGauge<<"%"<<endl;
//     cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
// }

// void Car::Accel()
// {
//     if(fuelGauge<=0)
//         return;
//     else
//         fuelGauge=CAR_CONST::FUEL_STEP;

//     if((curSpeed+CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD)
//     {
//         curSpeed=CAR_CONST::MAX_SPD;
//         return;
//     }
//     curSpeed+=CAR_CONST::ACC_STEP;
// }

// void Car::Break()
// {
//     if(curSpeed<CAR_CONST::BRK_STEP)
//     {
//         curSpeed=0;
//         return;
//     }
//     curSpeed-=CAR_CONST::BRK_STEP;
// }

// int main(void)
// {
//     Car run99;
//     run99.InitMembers("run99", 100);
//     run99.Accel();
//     run99.Accel();
//     run99.Accel();
//     run99.ShowCarState();
//     run99.Break();
//     run99.ShowCarstate();
//     return 0;

// }

// #include<iostream>
// using namespace std;

// class FruitSeller
// {
// private:
//     int APPLE_PRICE;
//     int numOfApples;
//     int myMoney;

// public:
//     void InitMembers(int price, int num, int money)
//     {
//         APPLE_PRICE=price;
//         numOfApples=num;
//         myMoney=money;
//     }
//     int SaleApples(int money)
//     {
        // int num=money/APPLE_PRICE;
        // numOfApples-=num;
        // myMoney+=money;
        // return num;
//     }
//     void ShowSalesResult()
//     {
        // cout<<"남은 사과: "<<numOfApples<<endl;
        // cout<<"판매 수익: "<<myMoney<<endl<<endl;
//     }
// };

// class FruitBuyer
// {
//     int myMoney;
//     int numOfApples;

// public:
//     void InitMembers(int money)
//     {
//         myMoney=money;
//         numOfApples=0;
//     }
//     void BuyApples(FruitSeller &seller, int money)
//     {
        // numOfApples+=seller.SaleApples(money);
        // myMoney-=money;
//     }
//     void ShowBuyResult()
//     {
        // cout<<"현재 잔액: "<<myMoney<<endl;
        // cout<<"사과 개수: "<<numOfApples<<endl<<endl;
//     }
// };

// int main(void)
// {
//     FruitSeller seller;
//     seller.InitMembers(1000, 20, 0);
//     FruitBuyer buyer;
//     buyer.InitMembers(5000);
//     buyer.BuyApples(seller, 2000);

//     cout<<"과일 판매자의 현황"<<endl;
//     seller.ShowSalesResult();
//     cout<<"과일 구매자의 현황"<<endl;
//     buyer.ShowBuyResult();
//     return 0;
// }


#