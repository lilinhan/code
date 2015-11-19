#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define WORD_LENGTH 130 // 单词最大长度
#define WORD_OF_PROGRAM 1000 //最大单词数

char prog[WORD_OF_PROGRAM*WORD_LENGTH],token[WORD_LENGTH];
char ch;
int syn,p,m=0,n,row;
double sum =0;   //类型为整数或者小数的时候，用于保存源数据
int syn_of_rwtab; //遍历关键字数组
int locate_line; //单词在行中的位置
char *rwtab[18]={"program","const","var","integer",
        "decimal","string","procedure","begin",
        "end ","if","then","else","while","do",
        "call","read","write","not"}; //保存关键字

void getToken(){
    /*
     这里一共有7类，每一类都有一个if判断
    */
    for(n=0;n<WORD_LENGTH;n++) token[n]=NULL;
    ch=prog[p++];
//****************第6类 分隔符***********************************//
    if(ch==' '||ch==';'||
       ch=='{'||ch=='}'||
       ch=='('||ch==')'||
       ch=='\t'||ch==','){
            syn = 6;
        token[0] = ch;
    }
//***************2 标识符 1 关键字*********************************//
    else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='_')  //可能是标示符或者变量名
    {
        m=0;
        while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='_')
        {
            token[m++]=ch;
            ch=prog[p++];
        }
        token[m++]='\0';
        p--;
        syn=2;
        for(n=0;n<18;n++)  //将识别出来的字符和已定义的标示符作比较，
            if(strcmp(token,rwtab[n])==0)
            {
                syn=1;
                syn_of_rwtab=n;
                break;
            }
    }
//*****************3 整数 4小数********************************//
    else if((ch>='0'&&ch<='9'))
    {

            bool flag = false; //是否是小数
            sum=0;

            while((ch>='0'&&ch<='9'))
            {
                sum=sum*10+ch-'0';
                ch=prog[p++];
            }
            if(ch=='.'){
                flag = true;
                ch=prog[p++];
                double tag = 0.1; //记录小数的位数
                while((ch>='0' && ch<='9')){
                    sum+=(ch-'0')*tag;
                    tag=tag*0.1;
                    ch=prog[p++];
                }
            }//if
        p--;
        if(flag) syn = 4;
        else syn = 3;
        if(sum>32767)
            syn=-1;
    }
//********************5 判断是不是字符串****************************//
    else if(ch=='\"'){
        syn = 5;
        m=0;
        token[m++] = ch;
        while((ch=prog[p++])!='\"')
            token[m++] = ch;
        token[m] = ch;
       // p--;
    }
//*******************7 运算符*******************//
    else switch(ch)
    {
        case'<':
            m=0;
            token[m++]=ch;
            ch=prog[p++];
            if(ch=='>')
            {
                syn=7;
                token[m++]=ch;
            }
            else if(ch=='=')
            {
                syn=7;
                token[m++]=ch;
            }
            else
            {
                syn=7;
                p--;
            }
            break;
        case'>':
            m=0;
            token[m++]=ch;
            ch=prog[p++];
            if(ch=='=')
            {
                syn=7;
                token[m++]=ch;
            }
            else
            {
                syn=7;
                p--;
            }
            break;
        case':':
            m=0;token[m++]=ch;
            ch=prog[p++];
            if(ch=='=')
            {
                syn=7;
                token[m++]=ch;
            }
            else
            {
                syn=7;
                p--;
            }
            break;
        case'*':syn=7;token[0]=ch;break;
        case'/':syn=7;token[0]=ch;break;
        case'+':syn=7;token[0]=ch;break;
        case'-':syn=7;token[0]=ch;break;
        case'=':syn=7;token[0]=ch;break;
        case'#':syn=0;token[0]=ch;break;
        case'\n':syn=-2;locate_line=0;break;
        default: syn=-1;break;
    }
}

int main()
{
    p=0;
    row=1;
    cout<<"Please input string:"<<endl;
    do
    {
        cin.get(ch);
        prog[p++]=ch;
    }
    while(ch!='#');
    int temp = 0; //不区分大小写，全部转换成小写。
    while(prog[temp]!='#'){
        if(prog[temp]<='Z' && prog[temp]>='A')
            prog[temp]+='a'-'A';
        temp++;
    }
    p=0;
    do
    {
        getToken();
        locate_line++;
        switch(syn)
        {
        case 1: cout<<row<<" "<<locate_line<<" "<<"("<<syn<<","<<rwtab[syn_of_rwtab]<<")"<<endl;break;
        case 2: cout<<row<<" "<<locate_line<<" "<<"("<<syn<<","<<token<<")"<<endl; break;
        case 5: cout<<row<<" "<<locate_line<<" "<<"("<<syn<<","<<token<<")"<<endl; break;
        case 6: cout<<row<<" "<<locate_line<<" "<<"("<<syn<<","<<token[0]<<")"<<endl; break;
        case 3: cout<<row<<" "<<locate_line<<" "<<"("<<syn<<","<<sum<<")"<<endl; break;
        case 4: cout<<row<<" "<<locate_line<<" "<<"("<<syn<<","<<sum<<")"<<endl; break;
        case -1: cout<<"Error in row "<<row<<"!"<<endl; break;
        case -2: row=row++;break;
        }
    }
    while (syn!=0);
}
