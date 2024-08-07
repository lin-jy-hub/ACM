#include<bits/stdc++.h>		//万能头文件
using namespace std;
string a,b;					//字符串A与字符串B
string sa[8],sb[8];			//存放6种转换方式
map<string,int> map1;		//用map存放已经宽搜过的字符串，用来判重剪枝（否则会超时）
int l;						//有l种转换方式
queue<string> q;			//存放转换出来的字符串
queue<int> bb;				//存放当前转换出来的字符串已经使用的步数
int bfs()
{
	int i,j,k,m,n;
	string s,ss;
	while (q.empty()==0&&q.front()!=b&&bb.front()<=10)		//当还能继续转换且没转换出字符串B且步数也没有超出10步时进行宽搜
	{
		if (map1[q.front()]==1) 		//剪枝：如果当前字符串已经宽搜过了,就弹出,进入下一次循环.
		{
			q.pop();
			bb.pop();
			continue;
		}
		map1[q.front()]=1;				//记录下该字符串
		for (i=1;i<=l;i++)				//循环出每一种转换方式
		{	
			s=q.front();				//将S赋值为当前要操作的字符串
			while (1)					//找出子串sa[i]的所有位置
			{	
				m=s.find(sa[i]);		//在S里查找子串sa[i]的第一次出现位置
				if (m==-1) break;		//如果全找出来(找不到)了,就结束循环
				ss=q.front();			//将SS赋值为当前要操作的字符串
				ss.replace(m,sa[i].size(),sb[i]);	//在SS中用子串sb[i]替换掉S里第一次出现的子串sa[i]
				q.push(ss);				//将转换后的SS压入队列
				bb.push(bb.front()+1);	//将转换后的SS已经使用的步数压入队列
				s[m]='~';				//将S里子串sa[i]的第一次出现位置随便换成另一种无关的字符,这样就可以查找到S里子串sa[i]的下一个出现位置
			}
			
			
		}
		q.pop();						//将操作过的字符串弹出队列
		bb.pop();						//操作过的字符串已经用过的步数一块弹出
	}
	if (q.empty()==1||bb.front()>10) return -1;//没法再进行宽搜,或者超出步数,就返回-1
		else return bb.front();					//否则,就是找到了,便返回最少使用步数
}
int main()
{
	int i,j,k,m,n;
	cin>>a>>b;							//读入字符串A与字符串B
	l=1;
	while (cin>>sa[l]>>sb[l]) l++;		//读入转换方式
	l--;								//l初始值为1,所以要减1,才能表示转换方式的数量
	if (l==0&&a!=b)						//若果没有转换方式且A也不等于B,直接输出"NO ANSWER!"(其实这步可以不要)
	{
		cout<<"NO ANSWER!";
		return 0;
	}
	q.push(a);							//将字符串A压入队列
	bb.push(0);							//将初始步数0压入队列
	k=bfs();							//宽搜
	if (k==-1)							//返回-1说明NO ANSWER!
	{
		cout<<"NO ANSWER!";
		return 0;
	}
	cout<<k;							//输出最小步数
}