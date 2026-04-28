#include<bits/stdc++.h>
using namespace std;

unordered_map<int,string> hash12;
unordered_map<int,string> hash25;
int charToValue(char c){
    if(c==' ')  return 0;
    if(c>='0' && c<='9') return c-'0'+1;
    if(c>='A' && c<='Z') return c-'A'+11; 
    if(c=='_') return 37;
    return 0;
}

char valueToChar(int x){
    if(x==0) return ' ';
    if(x==37) return '_';
    if(x>=1 && x<=10) return char(x-1 + '0');
    if(x>=11 && x<=36) return char(x-11 + 'A');
    return ' ';
}

unsigned long long encodeNormal(string s){
    while(s.size()<11) s+=' ';
    unsigned long long sum = 0;
    for(char c:s){
        sum = sum*38 + charToValue(c);
    }
    return sum;
}

string decodeNormal(unsigned long long x){
    string s(11,' ');
    for(int i=10;i>=0;i--){
        int v = x%38;
        x/=38;
        s[i] = valueToChar(v);
    }
    while(!s.empty() && s.back()==' ')
        s.pop_back();
    //去除字符串空格

    return s;
}

string decodeTypical(unsigned long long value){
    unsigned long long x = value - (1ULL << 25);
    int c6,c5,c4,c3,c2,c1;
    c6 = x%26;x/=26;
    c5 = x%26;x/=26;
    c4 = x%26;x/=26;
    c3 = x%10;x/=10;
    c2 = x%36;x/=36;
    c1 = x;

    string s;
    if(c1!=0){
        if(c1>=1 && c1<=10) s += char('0'+c1-1);
        if(c1>=11 && c1<=36) s += char('A'+c1-11);
    }//在这里空格就被省略
    if(c2<10) s += char('0'+c2);
    else s+= char('A'+c2-10);
    s += char('0'+c3);
    s += char('A'+c4);
    s += char('A'+c5);
    s += char('A'+c6);

    return s;
}

int getHash(unsigned long long num,int bits){
    unsigned long long product = num * 47055833459ULL;
    unsigned long long mask = (1ULL << bits) - 1;
    return (product >> (64 - bits)) & mask;
}

void addCode(const string& code){
    unsigned long long num = encodeNormal(code);
    hash12[getHash(num,12)] = code;
    hash25[getHash(num,25)] = code;

}//加入已出现过的代码

unsigned long long getBits(const string& s,int l,int len){
    unsigned long long x = 0;
    for(int i=l;i<l+len;i++){
        x = x*2 + (s[i]-'0');
    }
    return x;
}

string decodeSimpleValue(unsigned long long value){
    if(value>=(1ULL<<25)){
        return decodeTypical(value);
    }
    if(hash25.count(value)){
        return "#" + hash25[value];
    }

    return "###";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s[0]=='0'){
            unsigned long long receiverValue = getBits(s,1,28);
            unsigned long long senderValue = getBits(s,29,28);
            unsigned long long position = getBits(s,57,15);

            string receiver = decodeSimpleValue(receiverValue);
            string sender = decodeSimpleValue(senderValue);

            if(position == 0){
                cout << receiver << ' ' << sender << '\n';
            }
            else{
                cout << receiver << ' ' << sender << ' ' << position << '\n';
            }
            if(receiverValue >= (1ULL << 25)){
                addCode(receiver);
            }
            if(senderValue >= (1ULL << 25)){
                addCode(sender);
            }

        }
        else if(s[0]=='1'){
            unsigned long long codeValue = getBits(s, 1, 58);
            unsigned long long hashValue = getBits(s, 59, 12);
            int flag = s[71] - '0';
            string fullCode = decodeNormal(codeValue);
            string otherCode;
            if(hash12.count(hashValue)){
                otherCode = "#" + hash12[hashValue];
            }
            else{
                otherCode = "###";
            }
            if(flag == 0){
                cout << otherCode << ' ' << fullCode << '\n';
            }
            else{
                cout << fullCode << ' ' << otherCode << '\n';
            }
            addCode(fullCode);
        }
    }
    return 0;
}
