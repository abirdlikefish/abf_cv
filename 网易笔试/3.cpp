// 超级大模拟，没啥算法难点但题目描述巨复杂只刷算法没工程经验的有福了，md题目看错了好几次卡了我好久，其他的没啥好说的

#include <ios>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int getNum(char a)
{
    if('0' <= a && a <= '9')
        return a - '0';
    else
        return a - 'A' + 10;
}

int getByte(char a,char b)
{
    int midNum = getNum(a) * 16 + getNum(b);
    return midNum;
}

int getNumFromStr(string& str , int &ptr)
{
    int num = getByte(str[ptr], str[ptr + 1]);
    ptr += 2;
    return num;
}
int getIntFromStr(string& str , int &ptr)
{
    int ret = 0;
    for(int i = 0 ; i < 4 ; i ++)
    {
        int num = getByte(str[ptr], str[ptr + 1]);
        ptr += 2;
        // num <<= (0 * 8);
        // ret += (num  <<  (i * 8));
        ret *= 256;
        ret += num;
    }
    
    // cout << "\n use ret =" << ret << ", ptr =" << ptr <<  endl;
    return ret;
}

string getStringFromStr(string& str , int &ptr , int strSize)
{
    string ret = "";
    for(int i = 0 ; i < strSize * 2 ; i ++)
    {
        // char midc = getNumFromStr(str, ptr);
        char midc = str[ptr];
        ptr ++;
        ret.push_back(midc);
    }
    // cout << "getStr " << strSize << " " << ret << endl;
    return ret;
}

class MyFunc
{
public:
    string name;
    string parm;
    int stringCnt;
    vector<int> strSize;
    void Init(string name , string parm)
    {
        this->name = name ;
        this->parm = parm;
        this -> stringCnt = 0;
        for(int i = 0 ; i < parm.size() ; i ++)
        {
            if(parm[i] == 's')
            {
                this -> stringCnt ++;
            }
        }
    }
    void use(string& str , int& ptr)
    {
        strSize.clear();
        cout << name << "(";
        
        for(int i = 0 ; i < stringCnt ; i ++)
        {
            int midSize = getNumFromStr(str , ptr);
            strSize.push_back(midSize);
            // cout << "\n stringSize" << midSize << ", ptr =" << ptr <<  endl;
        }
        int strSizePtr = 0;
        for(int i = 0 ; i < parm.size() ; i ++)
        {
            if(parm[i] == 'i')
            {
                int midNum = getIntFromStr(str , ptr);
                printf("%d" , midNum);
            // cout << "\n use" << "" << ", ptr =" << ptr <<  endl;
            }
            else 
            {
                string midStr = getStringFromStr(str , ptr , strSize[strSizePtr]);
                strSizePtr ++;
                cout << "\"" << midStr << "\"";
            // cout << "\n use" << "" << ", ptr =" << ptr <<  endl;
            }
            if(i == parm.size() - 1)
            {
                cout << ")" << endl;
            }
            else
            {
                cout << ",";
            }
        }
    }
};

unordered_map<int , MyFunc> myFunc;

int main() {
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i ++)
    {
        int index;
        string name , parm;
        cin >> index >> name >> parm;
        myFunc[index].Init(name , parm);
    }
    string str;
    cin >> str;
    int ptr = 0;
    while(ptr < str.size())
    {
        int funcIndex = getNumFromStr(str , ptr);
        // cout << "use func " << funcIndex << ", ptr =" << ptr <<  endl;
        myFunc[funcIndex].use(str , ptr);
    }
}
// 64 位输出请用 printf("%lld")