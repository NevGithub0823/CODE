#include<bits/stdc++.h>
using namespace std;
int road[101][101];//��¼�Ƿ�ͨ· 
int n,k,m,s,t,ans=1000000;
int exc[101][101];//�Ļ�����ų��ϵ 
int cul[101];//��i�����е��Ļ����� 
bool ok[101];//�жϵ�ǰ���е��Ļ��Ƿ��Ѿ���ѧϰ 
void dfs(int x,int sum)//x��ʾ��㣬sum��ʾ����
{
	if(x==t)
	{
		ans=min(ans,sum);//������Сֵ 
		return;
	}
	ok[cul[x]]=1;
	for(int i=1;i<=n;i++)
	{
		if(!road[x][i]||exc[cul[i]][cul[x]]||ok[cul[i]]) continue;//���x��i֮��û��ͨ·��
        dfs(i,sum+road[x][i]);                                    //�����Ļ�i���Ļ��ų�x���Ļ���
	}                                                             //���ߵ�ǰ�����Ļ��Ѿ���ѧϰ������ 
	ok[cul[x]]=1;//���� 
}
int main()
{
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++) scanf("%d",&cul[i]);
	for(int i=1;i<=k;i++)
	   for(int j=1;j<=k;j++) scanf("%d",&exc[i][j]);	    
	for(int i=1;i<=m;i++)
	{
	    int gg,zz,xx;
		scanf("%d%d%d",&gg,&zz,&xx);
		road[gg][zz]=xx;
	} 
	dfs(s,0);
	if(ans==1000000) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}