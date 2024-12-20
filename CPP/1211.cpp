// #include<iostream>
// using namespace std;

// class SoSimple
// {
// private:
//     int num;
// public:
//     SoSimple(int n):num(n)
//     { }
//     SoSimple& AddNum(int n)
//     {
//         num+=n;
//         return *this;
//     }
//     void SimpleFunc()
//     {
//         cout<<"SimpleFunc: "<<num<<endl;
//     }
//     void SimpleFunc() const
//     {
//         cout<<"const SimpleFunc: "<<num<<endl;
//     }
// };

// void YourFunc(const SoSimple &obj)
// {
//     obj.SimpleFunc();
// }

// int main(void)
// {
//     SoSimple obj1(2);           //일반객체 생성
//     const SoSimple obj2(7);     //const 객체 생성

//     obj1.SimpleFunc();          //일반객체 대상으로 SimpleFunc 함수를 호출하면 16행의 일반 멤버 함수 호출
//     obj2.SimpleFunc();          //const 객체 대상으로 SimpleFunc 함수를 호출하면 20행의 const 멤버 함수 호출

//     YourFunc(obj1);
//     YourFunc(obj2);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class SoSimple
// {
// private:
//     static int simObjCnt;
// public:
//     SoSimple()
//     {
//         simObjCnt++;
//         cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
//     }
// };
// int SoSimple::simObjCnt=0;

// class SoComplex
// {
// private:
//     static int cmxObjCnt;
// public:
//     SoComplex()
//     {
//         cmxObjCnt++;
//         cout<<cmxObjCnt<<"번째 soComplex 객체"<<endl;
//     }
//     SoComplex(SoComplex &copy)
//     {
//         cmxObjCnt++;
//         cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
//     }
// };
// int SoComplex::cmxObjCnt=0;

// int main(void)
// {
//     SoSimple sim1;
//     SoSimple sim2;

//     SoComplex cmx1;
//     SoComplex cmx2=cmx1;
//     SoComplex();
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// using namespace std;

// class Person
// {
// private:
//     int age;
//     char name[50];
// public:
//     Person(int myage, char* myname):age(myage)
//     {
//         strcpy(name, myname);
//     }
//     void WhatYourName() const
//     {
//         cout<<"My name is "<<name<<endl;
//     }
//     void HowOldAreYou() const
//     {
//         cout<<"I'm "<<age<<" years old"<<endl;
//     }
// };

// class UnivStudent : public Person
// {
// private:
//     char major[50];
// public:
//     UnivStudent(char* myname, int myage, char* mymajor)
//         :Person(myage, myname)
//     {
//         strcpy(major, mymajor);
//     }
//     void WhoAreYou() const
//     {
//         WhatYourName();
//         HowOldAreYou();
//         cout<<"My mahor is "<<major<<endl<<endl;
//     }
// };

// int main(void)
// {
//     UnivStudent ustd1("Lee", 22, "Computer eng.");
//     ustd1.WhoAreYou();

//     UnivStudent ustd2("Yoon", 21, "Electronic eng.");
//     ustd2.WhoAreYou();
//     return 0;
// }
//자식클래스는 부모클래스의 멤버변수, 생성자등을 포함한다.

// #include<iostream>
// using namespace std;

// class SoBase
// {
// private:
//     int baseNum;
// public:
//     SoBase(int n):baseNum(n)
//     {
//         cout<<"SoBase():"<<baseNum<<endl;
//     }
//     ~SoBase()
//     {
//         cout<<"~SoBase():"<<baseNum<<endl;
//     }
// };

// class SoDerived:public SoBase
// {
// private:
//     int derivNum;
// public:
//     SoDerived(int n):SoBase(n), derivNum(n)
//     {
//         cout<<"SoDerived():"<<derivNum<<endl;
//     }
//     ~SoDerived()
//     {
//         cout<<"~SoDerived():"<<derivNum<<endl;
//     }
// };

// int main(void)
// {
//     SoDerived drv1(15);
//     SoDerived drv2(27);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Base
// {
// private:
//     int num1;
// protectd:
//     int num2;
// public:
//     int num3;

//     Base():num1(1), num2(2), num3(3)
//     { }
// };

// class Derived:protectd Base{ };

// int main(void)
// {
//     Derived drv;
//     cout<<drv.num3<<endl;
//     return 0;
// }
//Base 클래스를 protected로 상속했기 때문에 public 멤버변수인 num3는
//Derived 클래스에서 protected 멤버가 된다. 이로인해 외부에서 접근 불가능한 멤버가 됨

// #include<iostream>
// using namespace std;

// class Person
// {
// public:
//     void Sleep(){cout<<"Sleep"<<endl;}
// };

// class Student:public Person
// {
// public:
//     void Study(){cout<<"Study"<<endl;}
// };

// class PartTimeStudent:public Student
// {
// public:
//     void Work(){cout<<"Work"<<endl;}
// };

// int main(void)
// {
//     Person* ptr1=new Student();
//     Person* ptr2=new PartTimeStudent();
//     Person* ptr3=new PartTimeStudent();
//     ptr1->Sleep();
//     ptr2->Sleep();
//     ptr3->Study();
//     delete ptr1; delete ptr3; delete ptr3;
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// using namespace std;

// class Employee
// {
// private:
//     char name[100];
// public:
//     Employee(char* name)
//     {
//         strcpy(this->name, name);
//     }
//     void ShowYourName() const
//     {
//         cout<<"name: "<<name<<endl;
//     }
// };

// class PermanentWorker: public Employee
// {
// private:
//     int salary;
// public:
//     PermanentWorker(char* name, int money)
//         :Employee(name), salary(money)
//     { }
//     int GetPay() const
//     {
//         return salary;
//     }
//     void ShowSalaryInfo() const
//     {
//         ShowYourName();
//         cout<<"salary: "<<GetPay()<<endl<<endl;
//     }
// };

// class EmployeeHandler
// {
// private:
//     Employee* empList[50];
//     int empNum;
// public:
//     EmployeeHandler():empNum(0)
//     { }
//     void AddEmployee(Employee* emp)
//     {
//         empList[empNum++]=emp;
//     }
//     void ShowAllSalaryInfo() const
//     {

//     }
//     void ShowTotalSalary() const
//     {
//         int sum=0;
//     }
//     ~EmployeeHandler()
//     {
//         for(int i=0; i<empNum; i++)
//             delete empList[i];
//     }
// };

// int main(void)
// {
//     EmployeeHandler handler;
//     handler.AddEmployee(new PermanentWorker("KIM", 1000));
//     handler.AddEmployee(new PermanentWorker("LEE", 1500));
//     handler.AddEmployee(new PermanentWorker("JUN", 2000));

//     handler.ShowAllSalaryInfo();
//     handler.ShowTotalSalary();
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class First
// {
// public:
//     virtual void MyFunc() {cout<<"FirstFunc"<<endl;}    //버추얼로 선언
// };

// class Second: public First      //
// {
// public:
//     virtual void MyFunc() {cout<<"SecondFunc"<<endl;}   //굳이 버추얼 선언을 안해도 되지만
// };

// class Third: public Second
// {
// public:
//     virtual void MyFunc() {cout<<"ThridFunc"<<endl;}    //선언을 넣어 보여주기
// };

// int main(void)
// {
//     Third*tptr=new Third();
//     Second*sptr=tptr;
//     First*fptr=sptr;

//     fptr->MyFunc();
//     sptr->MyFunc();
//     tptr->MyFunc();
//     delete tptr;
//     return 0;
// }


#include<iostream>
using namespace std;

class TV
{
private:
    int onoff=0;
    int chn=0;
    int vol=0;

public:
    void on()
    {
        onoff+=1;
    }
    void chnup()
    {
        chn+=1;
    }
    void chndown()
    {
        chn-=1;
    }
    void volup()
    {
        vol+=1;
    }
    void voldown()
    {
        vol-=1;
    }
    void showmenu()
    {
        if(onoff%2==1)
            cout<<"TV켜짐"<<endl;
        else if(onoff%2==0)
            cout<<"TV꺼짐"<<endl;
        cout<<"현재 채널: "<<chn<<endl;
        cout<<"현재 볼륨: "<<vol<<endl<<endl<<endl;
    }
    void showkey()
    {
        cout<<"TV 끄기, 켜기: q"<<endl;
        // cout<<"TV 끄기: w"<<endl;
        cout<<"채널 올리기: e"<<endl;
        cout<<"채널 내리기: r"<<endl;
        cout<<"소리 올리기: t"<<endl;
        cout<<"소리 내리기: y"<<endl;
    }
};

int main(void)
{
    TV SAMSUNG;
    TV LG;
    char ch;
    while(1)
    {
        SAMSUNG.showmenu();
        SAMSUNG.showkey();
        cout<<"행동 입력";
        cin>>ch;
        switch(ch)
        {
            case 'q':
                SAMSUNG.on();
                break;
            case 'e':
                SAMSUNG.chnup();
                break;
            case 'r':
                SAMSUNG.chndown();
                break;
            case 't':
                SAMSUNG.volup();
                break;
            case 'y':
                SAMSUNG.voldown();
                break;
            default:
                cout<<"잘못된 입력"<<endl;
        }
        system("clear");
    }
}