// #include<iostream>
// int main()
// {
//     using namespace std;                      //정의 가시화(?)

//     int num;

//     num=25;
//     cout<<"C++의 세계로 오십시오.";            //출력
//     cout<<endl;                               //줄 바꿈
//     cout<<num;                                //변수 값 출력
//     cout<<"살 입니다.";                         //출력
//     cout<<endl;                                 //줄 바꿈
//     num=num +1;                               //변수 값 변경
//     cout<<"내년에는"<<num<<"살 입니다.";
//     cout<<endl;                               //줄 바꿈
//     cout<<"후회하지 않으실 겁니다!"<<endl;     //출력
//     return 0;                                 //함수 종료
// }


// #include<iostream>

// int main()
// {
//     using namespace std;

//     int carrots;            //변수 설정

//     cout<<"당근을 몇 개나 가지고 있니?"<<endl;      //출력 후 줄 바꿈
//     cin>>carrots;                          //사용자의 입력값을 carrots에 대입(scanf와 비슷)
//     cout<<"여기 두개 더 있다.";             //출력
//     carrots=carrots+2;                    //변수에 2 더하기
//     cout<<"이제 당근은 모두 "<<carrots<<"개이다."<<endl;    //출력문과 변수를 연결하여 출력
//     return 0;
// }

// #include<iostream>      //변수의 크기 알아보기
// #include<climits>

// int main()
// {
//     using namespace std;
//     int n_int=INT_MAX;                  //n_int를 int형의 최대값으로 초기화
//     short n_short=SHRT_MAX;             //limits.h 파일에 정의된 기호상수
//     long n_long=LONG_MAX;
//     long long n_llong=LLONG_MAX;

//     //sizeof는 데이터형이나 변수의 크기를 알아냄
//     cout<<"int는" << sizeof(int)<<"바이트이다."<<endl;
//     cout<<"short는" << sizeof n_short<<"바이트이다."<<endl;
//     cout<<"long는" << sizeof n_long<<"바이트이다."<<endl<<endl;
//     cout<<"long long는" << sizeof n_llong<<"바이트이다."<<endl;
//     cout<<endl;

//     cout<<"최댓값:"<<endl;
//     cout<<"int:"<<n_int<<endl;
//     cout<<"short:"<<n_short<<endl;
//     cout<<"long:"<<n_long<<endl<<endl;
//     cout<<"long long:"<<n_llong<<endl<<endl;
//     cout<<"int의 최솟값 = "<<INT_MIN<<endl;
//     cout<<"바이트 당 비트 수 = "<<CHAR_BIT<<endl;
//     return 0;
// }

// #include<iostream>
// int main()
// {
//     using namespace std;
//     char ch='M';            //문자형 변수 ch에 M을 대입
//     int i=ch;               //정수형 변수 i에 ch를 대입
//     cout<<ch<<"의 ASCII 코드는"<<i<<"입니다."<<endl;    //ch는 M을 출력, i는 77을 출력

//     cout<<"이 문자 코드에 1을 더해 보겠습니다."<<endl;
//     ch=ch+1;            //ch에 1을 더한 후
//     i=ch;               //i에 ch를 대입
//     cout<<ch<<"의 ASCII 코드는"<<i<<"입니다."<<endl;   //각각 N, 78을 출력

//     cout<<"cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
//     cout.put(ch);       //char 전용 출력

//     cout.put('!');

//     cout<<endl<<"종료"<<endl;
//     return 0;
// }

// #include<iostream>          //배열 알아보기
// int main()
// {
//     using namespace std;
//     int yams[3];        //3개의 원소를 가진 배열 선언
//     yams[0]=7;
//     yams[1]=8;
//     yams[2]=6;          //배열에 원소 대입

//     int yamcosts[3]={200, 300, 50};     //3개의 원소를 가진 배열 선언, 초기화

//     cout<<"고구마 합계 = ";
//     cout<<yams[0]+yams[1]+yams[2]<<endl;        //yams배열에 있는 값들 더하기
//     cout<<yams[1]<<"개가 들어 있는 포장은 ";        //2번째 요소값
//     cout<<"개당"<<yamcosts[1]<<"원씩입니다.\n";     //300 출력
//     int total=yams[0]*yamcosts[0]+yams[1]*yamcosts[1];
//     total=total+yams[2]*yamcosts[2];        //total에 개수에 가격을 곱하여 더한 값을 대입
//     cout<<"세 포장의 총 가격은"<<total<<"원입니다.\n";  //total 출력
//     cout<<"\nyams 배열의 크기는 "<<sizeof yams;         //yams의 크기 구하기
//     cout<<"바이트입니다.\n";
//     cout<<"원소 하나의 크기는 "<<sizeof yams[0];        //yams의 하나의 요소의 크기 구하기
//     cout<<"바이트입니다.\n";
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// int main()
// {
//     using namespace std;
//     const int Size=15;
//     char name1[Size];               //길이가 15인 배열 선언
//     char name2[Size]="C++owboy";    //길이가 15인 배열 선언과 초기화

//     cout<<"안녕하세요! 저는"<<name2;        //배열 name2를 출력
//     cout<<"입니다! 실례지만 성함이?\n";     
//     cin>>name1;                             //사용자 입력받아 name1에 대입
//     cout<<"아,"<<name1<<"씨! 당신의 이름은";    //name1 출력
//     cout<<strlen(name1)<<"자입니다만\n";        //strlen을 사용하여 배열의 길이 출력
//     cout<<sizeof(name1)<<"바이트 크기의 배열에 저장되었습니다.\n";      //배열의 크기 출력
//     cout<<"이름이"<<name1[0]<<"자로 시작하는군요.\n";       //name1의 첫 원소 출력
//     name2[3]='\0';              //name2의 4번째 요소에 널 문자 대입
//     cout<<"제 이름의 처음 세 문자는 다음과 같습니다.: ";
//     cout<<name2<<endl;          //name2를 출력(널 물자에서 출력을 멈추므로 3번째에서 끊김)
//     return 0;
// }


// #include<iostream>          //getline 사용하기 (화이트 스페이스 무시)
// int main()
// {
//     using namespace std;
//     const int ArSize=20;
//     char name[ArSize];
//     char dessert[ArSize];

//     cout<<"이름을 입력하십시오:\n";
//     cin.getline(name, ArSize);
//     cout<<"좋아하는 디저트를 입력하십시오:\n";
//     cin.getline(dessert, ArSize);
//     cout<<"맛있는"<<dessert;
//     cout<<"디저트를 준비하겠습니다."<<name<<" 님!\n";
//     return 0;
// }

// #include<iostream>
// #include<string>
// int main()
// {
//     using namespace std;
//     string s1="penguin";
//     string s2, s3;

//     cout<<"string 객체를 string 객체에 대입할 수 있다: s2= s1\n";
//     s2=s1;          //string을 string에 대입
//     cout<<"s1: " <<s1<<", s2:"<<s2<<endl;
//     cout<<"string 객체에 C스타일 문자열을 대입할 수 있다.\n";
//     cout<<"s2=\"buzzard\"\n";
//     s2="buzzard";   //string 초기화
//     cout<<"s2: "<<s2<<endl;
//     cout<<"string 객체들을 결합 할 수 있다: s3=s1+s2\n";
//     s3=s1+s2;       //s3에 s1과 s2의 결합한 객체를 대입
//     cout<<"s3: "<<s3<<endl;
//     cout<<"string 객체들을 추가할 수 있다.\n";
//     s1+=s2;
//     cout<<"s1+=s2-->s1="<<s1<<endl;
//     s2+="for a day";
//     cout<<"s2 += \"for a day\"--> s2="<<s2<<endl;

//     return 0;
// }

#include<iostream>
#include<string>
#include<cstring>
int main()
{
    using namespace std;
    char charr[20];
    string str;

    cout<<"입력 이전에 charr에 있는 문자열의 길이: "
        <<strlen(charr)<<endl;      //널 문자의 위치는 랜덤이라 20보다 크거나 작을 수 있음
    cout<<"입력 이전에 str에 있는 문자열의 길이: "
        <<str.size()<<endl;         //string객체는 초기화 하지 않을 시 자동으로 0
    cout<<"택스트 한 행을 입력하시오:\n";
    cin.getline(charr, 20);         //charr에 최대길이가 20인 문자열 입력 및 대입
    cout<<"입력한 텍스트:"<<charr<<endl;
    cout<<"또 다른 텍스트 한 행을 입력하시오:\n";
    getline(cin,str);
    cout<<"입력한 텍스트 "<<str<<endl;
    cout<<"입력 이후에 charr에 있는 문자열의 길이: "
        <<strlen(charr)<<endl;
    cout<<"입력 이후에 str에 있는 문자열의 길이: "
        <<str.size()<<endl;

    return 0;
}