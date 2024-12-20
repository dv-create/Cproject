// #include<iostream>      //함수와 구조체
// struct travel_time
// {
//     int hours;
//     int mins;
// };
// const int Mins_per_hr=60;

// travel_time sum(travel_time t1, travel_time t2);
// void show_time(travel_time t);


// int main()
// {
//     using namespace std;
//     travel_time day1={5,45};
//     travel_time day2={4,55};

//     travel_time trip=sum(day1, day2);
//     cout<<"이틀간 소요시간:";
//     show_time(trip);        //함수 호출

//     travel_time day3={4,32};
//     cout<<"사흘간 소요시간: ";
//     show_time(sum(trip, day3));     //함수 호출

//     return 0;
// }

// travel_time sum(travel_time t1, travel_time t2)
// {
//     travel_time total;

//     total.mins=(t1.mins+t2.mins)%Mins_per_hr;       //전달받을땐 .사용
//     total.hours=t1.mins+t2.mins+(t1.mins+t2.mins)/Mins_per_hr;

//     return total;
// }

// void show_time(travel_time t)
// {
//     using namespace std;
//     cout<<t.hours<<"시간"
//         <<t.mins<<"분\n";
// }

// #include<iostream>      //구조체 매개변수를 사용하는 함수
// #include<cmath>

// struct polar
// {
//     double distance;        //원점으로부터의 거리
//     double angle;           //수평축으로부터의 각도
// };
// struct rect{
//     double x;               //원점으로부터의 수평거리
//     double y;               //원점으로부터의 수직거리
// };

// polar rect_to_polar(rect xypos);
// void show_polar(polar dapos);

// int main()
// {
//     using namespace std;
//     rect rplace;
//     polar pplace;

//     cout<<"x값과 y값을 입력하십시오:";
//     while(cin>>rplace.x>>rplace.y)      //cin이 while 조건(값을 성공적으로 받으면 실행)
//     {
//         pplace=rect_to_polar(rplace);
//         show_polar(pplace);
//         cout<<"x값과 y값을 입력하십시오(끝내려면 q를 입력): ";
//     }
//     cout<<"프로그램을 종료합니다.\n";
//     return 0;
// }

// polar rect_to_polar(rect xypos)
// {
//     using namespace std;
//     polar answer;

//     answer.distance=
//         sqrt(xypos.x*xypos.x+xypos.y+xypos.y);
//     answer.angle=atan2(xypos.y, xypos.x);
//     return answer;
// }

// void show_polar(polar dapos)
// {
//     using namespace std;
//     const double Rad_to_deg=57.29577951;

//     cout<<"거리="<<dapos.distance;
//     cout<<", 각도="<<dapos.angle*Rad_to_deg;
//     cout<<"도\n";
// }

// #include<iostream>
// #include<string>
// using namespace std;
// const int SIZE =5;
// void display(const string sa[], int n);
// int main()
// {
//     string list[SIZE];
//     cout <<"좋아하는 밤하늘의 광경을"<<SIZE<<"개 입력하시오:\n";
//     for(int i=0; i<SIZE; i++)
//     {
//         cout<<i+1<<": ";
//         getline(cin, list[i]);
//     }

//     cout<<"입력하신 내용은 다음과 같습니다:\n";
//     display(list,SIZE);

//     return 0;
// }

// void display(const string sa[], int n)
// {
//     for(int i=0; i<n; i++)
//         cout<<i+1<<": "<<sa[i]<<endl;
// }