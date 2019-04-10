#include<iostream>
#include<string>
using namespace std;
string _weapon[3]={"sword","bomb","arrow"};
class soilder
{
public:
int hp;
std::string name;
int num;
soilder() {}
soilder(std::string _name, int _hp, int _num);
 virtual void _printf()=0;
~soilder() {}
};
soilder::soilder(std::string _name, int _hp, int _num) {
    name = _name; hp = _hp; num = _num;}
class dragon:public soilder{
public:
    string weapon;
    float morale;
    dragon(std::string _name, int _hp, int _num,float _ball,string _weapon)
        :soilder(_name,_hp,_num){
    weapon=_weapon;morale=_ball;}
    void _printf(){cout<<"It has a "<<weapon<<","<<"and it's morale is ";printf("%.2f\n",morale);}
    ~dragon(){}
};
class ninja:public soilder{
public:
    string weapon[2];
    ninja(std::string _name, int _hp, int _num,string _weapon1,string _weapon2)
        :soilder(_name,_hp,_num)
       { weapon[0]=_weapon1;weapon[1]=_weapon2; }
   void _printf(){cout<<"It has a "<<weapon[0]<<" and a "<<weapon[1]<<endl;}
    ~ninja(){}
};
class iceman:public soilder{
public:
    string weapon;
    iceman(std::string _name, int _hp, int _num,string _weapon)
       : soilder(_name,_hp,_num){weapon=_weapon;}
    void _printf(){cout<<"It has a "<<weapon<<endl;}
    ~iceman(){}
 };
class lion:public soilder{
public:
        int faith;
        lion(std::string _name, int _hp, int _num,int _faith)
                 :soilder(_name,_hp,_num){faith=_faith;}
       void _printf(){cout<<"It's loyalty is "<<faith<<endl;}
        ~lion(){}
 };
 class wolf:public soilder{
 public:
        wolf(std::string _name, int _hp, int _num)
            :soilder(_name,_hp,_num){}
       void _printf(){}
        ~wolf(){}
    };

 class headquarter
{
public:
float life;
string color;
string wname[5] = { "dragon","ninja","iceman","lion","wolf" };
int makecondition;
int whp[5];
int _warriors[5];
soilder *mysoilder[1000];
int wsum;
bool make;
bool _stop;
headquarter() {}
headquarter(int _life, int _wsum, string _color, int i, int _whp[5]);
int makeordre(int ordre[5]);
void ifmakesoilder(int ordre[5]);
void makesoilder(int _time);
void _cout(int _time);
void stopmaking(int _time);
void havestopped(int _time);
~headquarter() {}
};

headquarter::headquarter(int _life, int _wsum,string _color, int i, int
_whp[5]) {
life = _life; wsum = _wsum; color = _color;
makecondition = i; make = true;
for (int i = 0; i < 5; i++) { whp[i] = _whp[i]; _warriors[i] = 0; }
}
int headquarter::makeordre(int ordre[5]) {
int i;
for (i = 0; i < 5; i++)
if (makecondition == ordre[i])break;
if (i == 4)makecondition = ordre[0];
else makecondition = ordre[i + 1];
return makecondition;
}
void headquarter::ifmakesoilder(int ordre[5]) {
    if (life<whp[makecondition]){
        make = false;
       int searching=0;
       while(searching<5&&life<whp[makecondition])
       {searching++;
           makeordre(ordre);
       }
       if(searching<5)make=true;
    }
    else make=true;
}
void headquarter::makesoilder(int _time) {
if (make == true) {
    wsum++;_warriors[makecondition]++;
    life -= whp[makecondition];
    if(wname[makecondition]=="dragon"){
 mysoilder[wsum-1]=new dragon(wname[makecondition], whp[makecondition],
       wsum,life/(double)whp[0],_weapon[wsum%3]);
      _cout(_time);
mysoilder[wsum-1]->_printf();
    }
    if(wname[makecondition]=="ninja"){
       mysoilder[wsum-1]=new ninja(wname[makecondition], whp[makecondition],
              wsum,_weapon[wsum%3],_weapon[(wsum+1)%3]);
         _cout(_time);
        mysoilder[wsum-1]->_printf();
    }
    if(wname[makecondition]=="iceman"){
         mysoilder[wsum-1]=new iceman(wname[makecondition], whp[makecondition],
              wsum,_weapon[wsum%3]);
         _cout(_time);
        mysoilder[wsum-1]->_printf();}
    if(wname[makecondition]=="lion"){
       mysoilder[wsum-1]=new lion (wname[makecondition], whp[makecondition],
              wsum,life);
         _cout(_time);
        mysoilder[wsum-1]->_printf();
    }
    if(wname[makecondition]=="wolf"){
         mysoilder[wsum-1]=new wolf(wname[makecondition], whp[makecondition],
             wsum);
         _cout(_time);
        mysoilder[wsum-1]->_printf();
    }
 }
}
void headquarter::_cout(int _time)
{
    printf("%03d ", _time);
            std::cout << color << " " << wname[makecondition] << " " << wsum <<
            " born with strength "<< whp[makecondition] << "," << _warriors[makecondition]
            << " "<<wname[makecondition] << " in " << color << " headquarter" <<std::endl;
}
void headquarter::stopmaking(int _time)
{
if (make == false) {
printf("%03d ", _time);
std::cout << color << " headquarter stops making warriors" <<
std::endl;
}
}

int main() {
int redordre[5] = { 2,3,4,1,0 };
int blueordre[5] = { 3,0,1,2,4 };
int x;
cin >> x;
for (int i = 0; i < x; i++)
{
int _life; int _whp[5];
cin >> _life;
for (int j = 0; j < 5; j++)cin >> _whp[j];
headquarter red(_life, 0, "red", 2, _whp);
headquarter blue(_life, 0, "blue", 3, _whp);
cout << "Case:" << i + 1 << endl;int f1=1,f2=1;
for (int time = 0;; time++) {
   if(f1==1){
       red.ifmakesoilder(redordre);
       red.makesoilder(time);
       red.makeordre(redordre);
       if(red.make==false){red.stopmaking(time);f1=0;}}
   if(f2==1){
       blue.ifmakesoilder(blueordre);
       blue.makesoilder(time);
       blue.makeordre(blueordre);
       if(blue.make==false){blue.stopmaking(time);f2=0;}}
    if (f1==0&&f2==0)break;
}
}
return 0;
}