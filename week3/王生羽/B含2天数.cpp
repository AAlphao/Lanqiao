#include <bits/stdc++.h>

using namespace std;

//�ж����y���Ƿ���2����1902��2221������2
bool isInclude2(int y){
    while(y){
        if((y%10) == 2) return(true);
        y /= 10;
    }
    return false;
}

//�ж�ĳ���Ƿ�Ϊ����
bool isLeap(int y){
    //������������400������Ϊ������Ϊƽ
    if((y%100==0) && (y%400==0)) return true;
    //��������������4������Ϊ������Ϊƽ
    if((y%100!=0) && (y%4==0)) return true;
    
    return false;
}

int main()
{
    int startYear = 1900;   //��ʼ���
    int endYear = 9999;     //�������
    int numOneYear = 0;     //��¼ĳ���к���2������
    int totals = 0;         //��¼�ܵĺ���2������
    int numTenMonths = 120; //1��3��4��5��6��7��8��9��10��11��10����
                            //һ������2�������ǹ̶��ģ���10*12�� = 120��
    int num12Month = 31;    //12�º��е�����

    for(int y=startYear; y<=endYear; y++){
        //�жϸ�����Ƿ���2
        if(isInclude2(y)) {
            //�ж������껹��ƽ��
            if(isLeap(y)) numOneYear = 366;
            else numOneYear = 365;
        }else {
            if(isLeap(y)){
                //��������2�·�Ϊ29��
                numOneYear = num12Month + numTenMonths + 29;
            }else{
                //��ƽ����2�·�Ϊ28��
                numOneYear = num12Month + numTenMonths + 28;
            }
        }
        totals += numOneYear;
    }

    cout << "totals = " << totals << endl;
    return 0;
}
//1994240 
