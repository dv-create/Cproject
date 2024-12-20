// #include<iostream>
// #include<string>
// int main()
// {
//     using namespace std;
//     cout<<"단어 하나를 입력하십시오: ";
//     string word;    //word 선언
//     cin>>word;      //word에 문자열 대입

//     for(int i=word.size()-1; i>=0; i--)     //i의 값을 word의 크기에서 1뺀 값으로 설정하여 0까지 1씩 감소
//         cout<<word[i];      //거꾸로 출력
//         cout<<"\n종료.\n";  //모두 끝나면 종료 문구 출력
//         return 0;
// }

// #include<iostream>
// #include<cstring>
// int main()
// {
//     using namespace std;
//     char word[5]="?ate";    //word라는 문자열에 ?ate 대입

//     for (char ch='a'; strcmp(word, "mate"); ch++)   //ch라는 변수에 a를 대입후
//     {
//         cout<<word<<endl;   //word를 출력후
//         word[0]=ch;         //word의 첫 요소에 ch를 대입
//     }
//     cout<<"루프가 끝난 후에 단어는" << word<<"입니다.\n";
//     return 0;
// }

// #include<iostream>
// #include<string>
// int main()
// {
//     using namespace std;
//     string word="?ate";    //word라는 문자열에 ?ate 대입

//     for (char ch='a'; word!="mate"; ch++)   //ch라는 변수에 a를 대입후
//     {
//         cout<<word<<endl;   //word를 출력후
//         word[0]=ch;         //word의 첫 요소에 ch를 대입
//     }
//     cout<<"루프가 끝난 후에 단어는" << word<<"입니다.\n";
//     return 0;
// }

// #include<iostream>      //초 후 끝내기
// #include<ctime>
// int main()
// {
//     using namespace std;
//     cout<<"지연 시간을 초 단위로 입력하십시오: ";
//     float secs;
//     cin>>secs;
//     clock_t delay=secs*CLOCKS_PER_SEC;

//     cout<<"카운트를 시작합니다";
//     clock_t start=clock();
//     while(clock()-start<delay)
//         cout<<clock()-start<<endl;
//         ;
//     return 0;
// }

// #include<iostream>
// int main()
// {
//     using namespace std;
//     char ch;
//     int count=0;        //카운트 0으로 설정
//     cout<<"문자들을 입력하시오; 끝내려면 #을 입력하시오:\n";
//     cin>>ch;        //ch에 문자 대입
//     while(ch!='#')      //ch가 #이 아닐 때까지 실행, 즉 #을 만나면 멈춘다.
//     {
//         cout<<ch;   //ch 출력
//         ++count;    //count에 1을 더함(몇 글자인지 세기 위함)
//         cin>>ch;    //다시 ch에 다음 문자 대입
//     }
//     cout<<endl<<count<<"문자를 읽었습니다.\n";
//     return 0;
// }

// #include<iostream>
// const int Cities=5;
// const int Years=4;
// int main()
// {
//     using namespace std;
//     const char*cities[Cities]=
//     {
//         "Seoul",
//         "Jeju",
//         "Busan",
//         "Gangneung",
//         "Daegu"
//     };

//     int maxtemps[Years][Cities]=
//     {
//         {35, 32, 33, 36, 35},
//         {33, 32, 34, 35, 31},
//         {33, 34, 32, 35, 34},
//         {36, 35, 34, 37, 35}
//     };

//     cout<<"2009년부터 2012년까지의 연중 최고 온도\n\n";
//     for(int city=0; city<Cities; ++city)
//     {
//         cout<<cities[city]<<":\t";
//         for(int year=0; year<Years; ++year)
//             cout<<maxtemps[year][city]<<"\t";
//         cout<<endl;
//     }
//     return 0;
// }

// #include<iostream>          //스위치와 함수 사용하기
// using namespace std;
// void showmenu();
// void report();
// void comfort();
// int main()
// {
//     showmenu();
//     int choice;
//     cin>>choice;
//     while(choice!=5)
//     {
//         switch(choice)
//         {
//             case 1:     cout<<"\a\n";
//                 break;
//             case 2:     report();
//                 break;
//             case 3:     cout<<"사장님은 오늘 회사에 계셨습니다.\n";
//                 break;
//             case 4:     comfort();
//                 break;
//             default:    cout<<"그것은 선택할 수 없습니다.\n";
//         }
//         showmenu();
//         cin>>choice;
//     }
//     cout<<"프로그램을 종료합니다!\n";
//     return 0;
// }

// void showmenu()
// {
//     cout<<"1, 2, 3, 4, 5번 중에서 하나를 선택하십시오:\n"
//         "1) 경고음          2)보고서\n"
//         "3) 알리바이        4)격려사\n"
//         "5) 종료\n";
// }

// void report()
// {
//     cout<<"이번 분기는 경영 실적이 아주 좋습니다.\n"
//           "판매량은 120% 늘어났고, 비용은 35% 줄었습니다.\n";
// }

// void comfort()
// {
//     cout<<"사원들은 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n";
//     cout<<"이사회도 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n";
// }

// #include<iostream>      //파일 생성, 정보 저장
// #include<fstream>
// int main()
// {
//     using namespace std;

//     char automobile[50];
//     int year;
//     double a_price;
//     double d_price;

//     ofstream outFile;                   //파일 생성
//     outFile.open("carinfo.txt");        //파일과 연결

//     cout<<"자동차 메이커와 차종을 입력하시오: ";
//     cin.getline(automobile, 50);
//     cout<<"연식을 입력하시오:";
//     cin>>year;
//     cout<<"구입 가격을 입력하시오: ";
//     cin>>a_price;
//     d_price=0.913*a_price;

//     cout<<fixed;
//     cout.precision(2);
//     cout.setf(ios_base::showpoint);
//     cout<<"메이커와 차종: "<<automobile<<endl;
//     cout<<"연식:"<<year<<endl;
//     cout<<"구입 가격 $"<<a_price<<endl;
//     cout<<"현재 가격 $"<<d_price<<endl;

//     outFile<<fixed;
//     outFile.precision(2);
//     outFile.setf(ios_base::showpoint);
//     outFile<<"메이커와 차종: "<<automobile<<endl;
//     outFile<<"연식:"<<year<<endl;
//     outFile<<"구입 가격 $"<<a_price<<endl;
//     outFile<<"현재 가격 $"<<d_price<<endl;

//     outFile.close();
//     return 0;
// }

// #include<iostream>
// #include<fstream>
// #include<cstdlib>
// const int SIZE=60;
// int main()
// {
//     using namespace std;
//     char filename[SIZE];
//     ifstream inFile;
//     cout<<"데이터 파일의 이름을 입력하시오: ";
//     cin.getline(filename, SIZE);
//     inFile.open(filename);
//     if(!inFile.is_open())
//     {
//         cout<<filename<<"파일을 열 수 없습니다."<<endl;
//         cout<<"프로그램을 종료합니다.\n";
//         exit(EXIT_FAILURE);
//     }
//     double value;
//     double sum=0.0;
//     int count=0;

//     inFile>>value;
//     while(inFile.good())
//     {
//         ++count;
//         sum+=value;
//         inFile>>value;
//     }
//     if(inFile.eof())
//         cout<<"파일 끝에 도달했습니다.\n";
//     else if(inFile.fail())
//         cout<<"데이터 불일치로 입력이 종료되었습니다.\n";
//     else
//         cout<<"알 수 없는 이유로 입력이 종료되었습니다.\n";
//     if(count==0)
//         cout<<"데이터가 없습니다.\n";
//     else
//     {
//         cout<<"읽은 항목의 개수:"<<count<<endl;
//         cout<<"합계:"<<sum<<endl;
//         cout<<"평균:"<<sum/count<<endl;
//     }
//     inFile.close();
//     return 0;
// }


// #include<iostream>
// const int ArSize=8;
// int sum_arr(const int*begin, const int*end);
// int main()
// {
//     using namespace std;
//     int cookies[ArSize]={1,2,4,8,16,32,64,128};

//     int sum=sum_arr(cookies, cookies+ArSize);
//     cout<<"벅은 과자 수 합계:"<<sum<<endl;
//     sum=sum_arr(cookies,cookies+3);
//     cout<<"처음 세 사람은 과자"<<sum<<"개를 먹었습니다.\n";
//     sum=sum_arr(cookies+4, cookies+8);
//     cout<<"마지막 네 사람은 과자"<<sum<<"개를 먹었습니다.\n";
//     return 0;
// }

// int sum_arr(const int*begin, const int*end)
// {
//     const int*pt;
//     int total=0;

//     for(pt=begin; pt!=end; pt++)
//         total=total+*pt;
//     return total;
// }