// #include<iostream>      //구조체 활용하기
// struct inflatable       //구조체 선언
// {
//     char name[20];
//     float volume;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatable guest=       //구조체 값 대입하기
//     {
//         "Glorious Gloria",
//         1.88,
//         29.99
//     };
//     inflatable pal=
//     {
//         "Audacious Arthur",
//         3.12,
//         32.99
//     };
//     cout<<"지금 판매하고 있는 모형풍선은\n"<<guest.name;
//     cout<<"와 "<<pal.name<<"입니다.\n";
//     cout<<"두 제품을 $";
//     cout<<guest.price+pal.price<<"에 드리겠습니다!\n";
//     return 0;
// }

// #include<iostream>              //구조체 배열로 선언하기
// struct inflatable               //구조체를 이름, 부피, 가격 순으로 선언
// {
//     char name[20];
//     float volume;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatable guests[2]=            
//     {
//         {"bambi", 0.5, 21.99},
//         {"Godzilla", 2000, 565.99}
//     };
//     cout<<guests[0].name<<"와 "<< guests[1].name
//         <<"의 부피를 합하면\n"
//         <<guests[0].volume+guests[1].volume
//         <<"세제곱피트입니다.\n";
//     return 0;
// }

// #include<iostream>
// int main()
// {
//     using namespace std;
//     double*p3=new double[3];        //double형 데이터 3개를 저장할 수 있는 공간을 대입
//                                     //p3을 배열이름처럼 취급
//     p3[0]=0.2;
//     p3[1]=0.5;
//     p3[2]=0.6;
//     cout<<"p3[1]은 "<<p3[1]<<"입니다.\n";
//     p3=p3+1;                        //p3은 배열 취급하므로 포인터를 증가시켜 위치를 지시
//     cout<<"이제는 p3[0]이 "<< p3[0]<<"이고,";
//     cout<<"p3[1]이"<<p3[1]<<"입니다.\n";
//     p3=p3-1;                        //원위치
//     delete[]p3;                     //메모리 해제
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// int main()
// {
//     using namespace std;
//     char animal[20]= "bear";
//     const char* bird= "wren";
//     char*ps;

//     cout<<animal<<" and";
//     cout<<bird<<"\n";

//     cout<<"동물의 종류를 입력하십시오:";
//     cin>>animal;

//     ps=animal;
//     cout<<ps<<"s!\n";
//     cout<<"strcpy() 사용 전:\n";
//     cout<<(int *) animal<<": "<<animal<<endl;
//     cout<<(int *) ps<<": "<<ps<<endl;
    
//     ps=new char[strlen(animal)+1];
//     strcpy(ps, animal);
//     cout<<"strcpy() 사용 후:\n";
//     cout<<(int *) animal<<": "<<animal<<endl;
//     cout<<(int *) ps<<": "<<ps<<endl;
//     delete [] ps;
//     return 0;
// }

#include<iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable*ps=new inflatable;
    cout<<"모형풍선의 이름을 입력하십시오.";
    cin.get(ps->name, 20);
    cout<<"부피를 세제곱 피트 단위로 입력하십시오:";
    cin>>(*ps).volume;
    cout<<"가격을 달러 단위로 입력하십시오: $";
    cin>>ps->price;
    cout<<"이름:"<<(*ps).name<<endl;
    cout<<"부피:"<<(*ps).volume<<"cubic feet\n";
    cout<<"가격: $:"<<(*ps).price<<endl;
    delete ps;
    return 0;
}