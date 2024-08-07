#include<bits/stdc++.h>
using namespace std;
queue<string>q;
string a,b;
map<string,string>m;
void yy(int i,string ss){//上下换
	string sss=ss;
	char c;
	c=ss[i];
	ss[i]=ss[i+4];
	ss[i+4]=c;
	if(m.count(ss)==0){
		q.push(ss);
		char aa=49+i/4,bb=49+i%4,cc=50+i/4,dd=49+i%4;//这里的横竖坐标都是从0开始的，存进去要加1
		m[ss]=m[sss]+aa+bb+cc+dd;
	}
	return;
}
void xx(int i,string ss){//左右换
	string sss=ss;
	char c;
	c=ss[i];
	ss[i]=ss[i+1];
	ss[i+1]=c;
	if(m.count(ss)==0){
		q.push(ss);
		char aa=49+i/4,bb=49+i%4,cc=49+i/4,dd=50+i%4;
		m[ss]=m[sss]+aa+bb+cc+dd;
	}
	return;
}
//考虑四个方向会重复，所以只需考虑两个方向，这里是右和下。
void bfs(){
	q.push(a);
	m[a]="";
	while(q.empty()==false){
		string ss=q.front();
		for(int i=0;i<16;i++){
			if(i<12){//不是最后一行就和下面换
				yy(i,ss);
			}
			if(i%4!=3){//不是最后一列就和右边换
				xx(i,ss);	
			}
		}
		if(m.count(b)!=0){//出现目标序列
			cout<<m[b].size()/4<<endl;
			for(int j=0;j<m[b].size();j++){
				cout<<m[b][j];
				if(j%4==3)cout<<endl;//每输出四个换一行
			}
			return;
		}
		q.pop();
	}
	return;
}
int main(){
	for(int i=0;i<16;i++){
		char c;
		cin>>c;
		a+=c;
	}
	for(int i=0;i<16;i++){
		char c;
		cin>>c;
		b+=c;
	}
	bfs();
	return 0;
}