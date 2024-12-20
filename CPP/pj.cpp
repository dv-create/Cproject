#include<iostream>
#include<string>
using namespace std;

enum{on, off, up1, down1, up2, down2, mode};        //리모컨 버튼(모드는 제품 등록 및 해제)
enum{tv_l=1, tv_s, air_l, air_s, fresh_l, light_l, light_b, light_p, light_t, clock_l, clock_b};



// string tv_L[2]={"L사 TV", "거실"};                //가전제품 회사, 종류, 위치의 정보를 저장하는 배열
// string tv_S[2]={"S사 TV", "안방"};
// string air_L[2]={"L사 에어컨", "거실"};
// string air_S[2]={"S사 에어컨", "안방"};
// string fresh_L[2]={"L사 공기청정기", "거실"};
// string light_L[2]={"거실 전등", "거실"};
// string light_B[2]={"안방 전등", "안방"};
// string light_P[2]={"현관 전등", "현관"};
// string light_T[2]={"화장실 전등", "화장실"};
// string clock_L[2]={"거실 시계", "거실"};
// string clock_B[2]={"안방 시계", "안방"};

void selectmenu(string remote[10]);
void showmainmenu();



class HOMEWARE                   //전등 상속시키기
{
private:
    int on=0;               //켜기
    int off=1;              //끄기

public:

    void ON()
    {
        off=0;
        on=1;
    }
    void OFF()
    {
        on=0;
        off=1;
    }
};

class HOMEHOMEWARE : public HOMEWARE       //티비, 에어컨, 공청, 시계
{
private:
    

public:
    int hour=0;             //취침시간,            알람설정 시
    int min=0;              //취침분,              알람설정 분

    int putpow=1;           //에어컨바람세기,    공청 바람세기,    티비 볼륨
    int option=1;           //에어컨 온도,       공청 바람방향,    티비 채널


    virtual void PUTPOWUP()     //오버라이딩으로 에어컨 세기, 공청 세기, 티비 볼륨
    {
        putpow+=1;
        if(putpow==4)
        {
            cout<<"바람세기가 최대입니다."<<endl;
            putpow-1;
        }
    }
    virtual void PUTPOWDOWN()     //오버라이딩으로 에어컨 세기, 공청 세기, 티비 볼륨
    {
        putpow-=1;
        if(putpow==0)
        {
            cout<<"바람세기가 최소입니다."<<endl;
            putpow+1;
        }
    }
    virtual void OPTIONUP()     //오버라이딩으로 에어컨 온도, 공청 방향, 티비 채널
    {
        option+=1;
        if(option==4)
        {
            cout<<"바람 방향이 최소 높이입니다."<<endl;
            option-1;
        }
    }
    virtual void OPTIONDOWN()     //오버라이딩으로 에어컨 온도, 공청 방향, 티비 채널
    {
        option-=1;
        if(option==0)
        {
            cout<<"바람 방향이 최저 높이입니다."<<endl;
            option+1;
        }
    }
    virtual void HOURUP()
    {
        hour+=1;
        if(hour==24)
        {
            hour=0;        //23에서 올리면 0시가 되도록
        }
    }
    virtual void HOURDOWN()
    {
        hour-=1;
        if(hour==-1)
        {
            hour=23;        //0에서 내리면 23이 되도록
        }
    }
    virtual void MINUP()
    {
        min+=1;
        if(min+1==60)
        {
            min=0;
            hour+=1;
            if(hour==24)
            {
                hour=0;        //24시 00분이 되면
                min=0;         //00시 00분이 되도록
            }
        }
    }
    virtual void MINDOWN()
    {
        min-=1;
        if(min-1==-1)
        {
            min=0;
            hour-=1;
            if(hour==-1)
            {
                hour=23;         //-1이 되면
                min=59;          //23시 59분이 되도록
            }
        }
    }
};

class TV : public HOMEHOMEWARE           //TV 클래스
{

public:
    virtual void PUTPOWUP()
    {
        putpow+=1;
        if(putpow==100)
        {
            cout<<"티비볼륨이 최대입니다."<<endl;
            putpow-1;
        }
    }
    virtual void PUTPOWDOWN()
    {
        putpow-=1;
        if(putpow==0)
        {
            cout<<"티비볼륨이 최소입니다."<<endl;
            putpow+1;
        }
    }
    virtual void OPTIONUP()     //오버라이딩으로 티비 채널로 변경
    {
        option+=1;
        if(option==101)
        {
            option=1;
        }
    }
    virtual void OPTIONDOWN()     //오버라이딩으로 티비 채널로 변경
    {
        option-=1;
        if(option==-1)
        {
            option=100;
        }
    }
    
};

class CLOCK : public HOMEHOMEWARE            //시계 클래스(알람은 이미 됐으므로 현재 시 분 변경 함수 제작)
{
private:

public:
    void preHOURUP()
    {
        hour+=1;
        if(hour+1==24)
        {
            hour=0;
        }
    }
    void preHOURDOWN()
    {
        hour-=1;
        if(hour-1==-1)
        {
            hour=23;
        }
    }
    void preMINUP()
    {
        min+=1;
        if(min+1==60)
        {
            min=0;
            hour+=1;
            if(hour==24)
                hour=0;
        }
    }
    void preMINDOWN()
    {
        min-=1;
        if(min-1==-1)
        {
            min=0;
            hour-=1;
            if(hour-1==-1)
                hour=23;
        }
    }
};

class LIGHT : public HOMEWARE            //전등 클래스
{

};

class FRESH : public HOMEHOMEWARE           //공청 클래스
{
    
};

class AIR : public HOMEHOMEWARE             //에어컨
{
public:
    virtual void OPTIONUP()     //오버라이딩으로 에어컨 온도, 공청 방향, 티비 채널
    {
        option+=1;
        if(option==31)
        {
            cout<<"최고 온도입니다."<<endl;
            option-1;
        }
    }
    virtual void OPTIONDOWN()     //오버라이딩으로 에어컨 온도, 공청 방향, 티비 채널
    {
        option-=1;
        if(option==17)
        {
            cout<<"최저 온도입니다."<<endl;
            option+1;
        }
    }
};

class REGIST                                        //등록 클래스
{
public:
    string remote[10][2];
    string tv_L={"L사 TV", "거실"};                //가전제품 회사, 종류, 위치의 정보를 저장하는 배열
    string tv_S={"S사 TV", "안방"};
    string air_L={"L사 에어컨", "거실"};
    string air_S={"S사 에어컨", "안방"};
    string fresh_L={"L사 공기청정기", "거실"};
    string light_L={"거실 전등", "거실"};
    string light_B={"안방 전등", "안방"};
    string light_P={"현관 전등", "현관"};
    string light_T={"화장실 전등", "화장실"};
    string clock_L={"거실 시계", "거실"};
    string clock_B={"안방 시계", "안방"};

    int num;

    virtual void ctrl()
    {
        cout<<"번호입력"<<endl;
        cin>>num;
        switch(num)
        {
            case tv_l:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=tv_L[0];
                        remote[i][1]=tv_L[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case tv_s:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=tv_S[0];
                        remote[i][1]=tv_S[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case air_l:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=air_L[0];
                        remote[i][1]=air_L[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case air_s:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=air_S[0];
                        remote[i][1]=air_S[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case fresh_l:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=fresh_L[0];
                        remote[i][1]=fresh_L[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case light_l:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=light_L[0];
                        remote[i][1]=light_L[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case light_b:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=light_B[0];
                        remote[i][1]=light_B[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case light_p:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=light_P[0];
                        remote[i][1]=light_P[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case light_t:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=light_T[0];
                        remote[i][1]=light_T[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case clock_l:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=clock_L[0];
                        remote[i][1]=clock_L[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            case clock_b:
                for(int i=0; i<9; i++)
                {
                    if(remote[i][0]!="")
                    {
                        remote[i][0]=clock_B[0];
                        remote[i][1]=clock_B[1];
                        cout<<remote[i][1]<<"에 있는 "<<remote[i][0]<<"등록 완료"<<endl;
                    }
                }
                break;
            default:
                cout<<"없는 번호"<<endl;
        }
    }
};

class CLEAR : public REGIST             //등록해제 클래스
{
public:
    virtual void ctrl()
    {
        cin>>num;
        switch(num)
        {

            case 0:
                remote[num][0]="";
                break;
            case 1:
                remote[num][0]="";
                break;
            case 2:
                remote[num][0]="";
                break;
            case 3:
                remote[num][0]="";
                break;
            case 4:
                remote[num][0]="";
                break;
            case 5:
                remote[num][0]="";
                break;
            case 6:
                remote[num][0]="";
                break;
            case 7:
                remote[num][0]="";
                break;
            case 8:
                remote[num][0]="";
                break;
            case 9:
                remote[num][0]="";
                break;
            default:
                cout<<"없는 번호"<<endl;
        }
    }
};

int main()
{
    TV SAMSUNG_T;
    TV LG_T;
    AIR SAMSUNG_A;
    AIR LG_A;
    FRESH LG_F;
    LIGHT LIVING_L;
    LIGHT BED_L;
    LIGHT PORCH_L;
    LIGHT TOILET_L;
    CLOCK LIVING1_C;
    CLOCK BED_C;
    int select;
    int button;
    REGIST PI;

    while(1)
    {
        for(int i=0; i<10; i++)
        {
            cout<<i<<". "<<PI.remote[i][0]<<endl;
        }
        cin>>select;

    }
}


void showmainmenu()
{
    cout<<"\n메뉴 선택"<<endl;
    cout<<"1. on\t\t2. off\t\t3. up1\t\t4. down1"<<endl;
    cout<<"5. up2\t\t6. down2\t\t7. mode"<<endl;
}