// #include<iostream>
// #include<string>

// int main(void)
// {
//     using namespace std;
//     string str1;
//     getline(cin,str1);
//     cout<<str1;
// }


// #include<iostream>
// using namespace std;

// class SimpleClass
// {
// private:
//     int num1;
//     int num2;
// public:
//     SimpleClass()
//     {
//         num1=0;
//         num2=0;
//     }
//     SimpleClass(int n)
//     {
//         num1=n;
//         num2=0;
//     }
//     SimpleClass(int n1, int n2)
//     {
//         num1=n1;
//         num2=n2;
//     }

//     /*
//     SimpleClass(int n1=0, int n2=0)
//     {
//         num1=n1;
//         num2=n2;
//     }
//     */

//     void ShowData() const
//     {
//         cout<<num1<<' '<<num2<<endl;
//     }
// };

// int main(void)
// {
//     SimpleClass sc1;
//     sc1.ShowData();

//     SimpleClass sc2(100);
//     sc2.ShowData();

//     SimpleClass sc3(100, 200);
//     sc3.ShowData();
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
//     FruitSeller(int price, int num, int money)
//         : APPLE_PRICE(price), numOfApples(num), myMoney(money)
//     {
//     }
//     int SaleApples(int money)
//     {
//         int num=money/APPLE_PRICE;
//         numOfApples-=num;
//         myMoney+=money;
//         return num;
//     }
//     void ShowSalesResult() const
//     {
//         cout<<"남은 사과: "<<numOfApples<<endl;
//         cout<<"판매 수익: "<<myMoney<<endl<<endl;
//     }
// };

// class FruitBuyer
// {
// private:
//     int myMoney;
//     int numOfApples;

// public:
//     FruitBuyer(int money)
//         : myMoney(money), numOfApples(0)
//     {
//     }
//     void BuyApples(FruitSeller &seller, int money)
//     {
//         numOfApples+=seller.SaleApples(money);
//         myMoney-=money;
//     }
//     void ShowBuyResult() const
//     {
//         cout<<"현재 잔액: "<<myMoney<<endl;
//         cout<<"사과 개수: "<<numOfApples<<endl<<endl;
//     }
// };

// int main(void)
// {
//     FruitSeller seller(1000, 20, 0);
//     FruitBuyer buyer(5000);
//     buyer.BuyApples(seller, 2000);

//     cout<<"과일 판매자의 현황"<<endl;
//     seller.ShowSalesResult();
//     cout<<"과일 구매자의 현황"<<endl;
//     buyer.ShowBuyResult();
//     return 0;
// }


// #include<iostream>
// #include<cstring>
// using namespace std;

// class Person
// {
// private:
//     char* name;
//     int age;
// public:
//     Person(char* myname, int myage)
//     {
//         int len=strlen(myname)+1;
//         name=new char[len];
//         strcpy(name, myname);
//         age=myage;
//     }
//     void ShowPersonInfo()const
//     {
//         cout<<"이름: "<<name<<endl;
//         cout<<"나이: "<<age<<endl;
//     }
//     ~Person()
//     {
//         delete []name;
//         cout<<"called destructor!"<<endl;
//     }
// };

// int main(void)
// {
//     Person man1("Lee dong woo", 29);
//     Person man2("Jang dong gun", 41);
//     man1.ShowPersonInfo();
//     man2.ShowPersonInfo();
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// using namespace std;

// class Person
// {
// private:
//     char* name;
//     int age;
// public:
//     Person(char* myname, int myage)
//     {
//         int len=strlen(myname)+1;
//         name=new char[len];
//         strcpy(name, myname);
//         age=myage;
//     }
//     void ShowPersonInfo()const
//     {
//         cout<<"이름: "<<name<<endl;
//         cout<<"나이: "<<age<<endl;
//     }
//     ~Person()
//     {
//         delete []name;
//         cout<<"called destructor!"<<endl;
//     }
// };

// int main(void)
// {
//     Person* parr[3];
//     char namestr[100];
//     int age;

//     for(int i=0; i<3; i++)
//     {
//         cout<<"이름: ";
//         cin>>namestr;
//         cout<<"나이: ";
//         cin>>age;
//         parr[i]=new Person(namestr, age);
//     }

//     parr[0]->ShowPersonInfo();
//     parr[1]->ShowPersonInfo();
//     parr[2]->ShowPersonInfo();
//     delete parr[0];
//     delete parr[1];
//     delete parr[2];
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class SelfRef
// {
// private:
//     int num;
// public:
//     SelfRef(int n):num(n)
//     {
//         cout<<"객체생성"<<endl;
//     }
//     SelfRef& Adder(int n)
//     {
//         num+=n;
//         return* this;
//     }
//     SelfRef& ShowTwoNumber()
//     {
//         cout<<num<<endl;
//         return* this;
//     }
// };

// int main(void)
// {
//     SelfRef obj(3);
//     SelfRef &ref=obj.Adder(2);

//     obj.ShowTwoNumber();
//     ref.ShowTwoNumber();

//     ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class SoSimple
// {
// private:
//     int num1;
//     int num2;
// public:
//     SoSimple(int n1, int n2)
//         : num1(n1), num2(n2)
//     {

//     }
//     SoSimple(SoSimple &copy)
//         : num1(copy.num1), num2(copy.num2)
//     {
//         cout<<"Called SoSimple(SoSimple &copy)"<<endl;
//     }
//     void ShowSimpleData()
//     {
//         cout<<num1<<endl;
//         cout<<num2<<endl;
//     }
// };

// int main(void)
// {
//     SoSimple sim1(15, 30);
//     cout<<"생성 및 초기화 직전"<<endl;
//     SoSimple sim2=sim1;
//     cout<<"생성 및 초기화 직수"<<endl;
//     sim2.ShowSimpleData();
//     return 0;
// }

