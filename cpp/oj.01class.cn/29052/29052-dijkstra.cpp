// not my code
#include<bits/stdc++.h>
using namespace std;
const long long inf=2147483647;
int N,K,M,S,T;
int c[105];
int a[105][105];
struct edge{
	int v,next,val;
}e[20005];
int cnt;
int head[105];
void add(int u,int v,int val){
	++cnt;
	e[cnt].v=v;
	e[cnt].val=val;
	e[cnt].next=head[u]; 
	head[u]=cnt;
}
int dis[110];
bool vis[110];
bool pan(int x){
	int jk[105],l=0;
	for(int i=1;i<=N;i++)
	if(vis[c[i]])
	jk[++l]=c[i];
	for(int i=1;i<=l;i++)
	if(a[c[x]][jk[i]])
	return 1;
	return 0;
}
void dijsktra(){
	int minn,u;
	for(int j=1;j<=N;j++){
		dis[j]=inf;
		vis[j]=0;
	}
	dis[S]=0;
	for(int i=1;i<N;i++){
		minn=inf;
		u=S;
		for(int j=1;j<=N;j++){
			if(!vis[c[j]]&&minn>dis[j]&&!pan(j)){
				minn=dis[j];
				u=j;
			}
		}
		vis[c[u]]=1;
		dis[u]=minn;
		for(int j=head[u];j;j=e[j].next){
			int v=e[j].v;
			if(!vis[c[v]]&&dis[u]+e[j].val<dis[v]&&!pan(v))
			dis[v]=dis[u]+e[j].val;
		}
	}
}
void Read(){
	scanf("%d %d %d %d %d",&N,&K,&M,&S,&T);
	for(int i=1;i<=N;i++)
	scanf("%d",&c[i]);
	for(int i=1;i<=K;i++)
	for(int j=1;j<=K;j++)
	scanf("%d",&a[i][j]);
	int aa,b,c;
	for(int i=1;i<=M;i++){
		scanf("%d %d %d",&aa,&b,&c);
		add(aa,b,c);
		add(b,aa,c);
	}
}
void Solve(){
	if(c[S]==c[T]||a[c[T]][c[S]]){
		printf("-1");
		return;
	}
	dijsktra();
	if(dis[T]==inf)
	printf("-1");
	else 
	printf("%d",dis[T]);
}
int main(){
	//freopen("culture.in","r",stdin);
	//freopen("culture.out","w",stdout);
	Read();
	Solve();
	return 0;
}