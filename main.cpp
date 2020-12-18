#include<iostream>
using namespace std;
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<graphics.h>
#define city 5
#define INF 100000


void path(int c1,int c2){
	if((c1==0 &&c2==1 )||(c1==1 &&c2==0 ))
	{
		setcolor(8);		
		line(15,15,100,50);
	}
	else if((c1==1 &&c2==2 )||(c1==2 &&c2==1 ))
	{
		setcolor(8);		
		line(100,50,150,100);
	}
	else if((c1==0 &&c2==2 )||(c1==2 &&c2==0 ))
	{
		setcolor(8);		
		line(15,15,150,100);
	}
	else if((c1==2 &&c2==3 )||(c1==3 &&c2==2 ))
	{
		setcolor(8);		
		line(150,100,100,250);
	}
	else if((c1==2 &&c2==4 )||(c1==4 &&c2==2 ))
	{
		setcolor(8);		
		line(150,100,50,200);
	}
	else if((c1==0 &&c2==3 )||(c1==3 &&c2==0 ))
	{
		setcolor(8);		
		line(15,15,100,250);
	}
	else if((c1==3 &&c2==4 )||(c1==4 &&c2==3 ))
	{
		setcolor(8);		
		line(50,200,100,250);
	}
	else if((c1==0 &&c2==4 )||(c1==4 &&c2==0 ))
	{
		setcolor(8);		
		line(15,15,50,200);
	}
	
}
void dijk(int g[][city],int n,int start,int end){
	int dist[city],visited[city],pred[city];
	int i,j,count,mindist,nextnode;
	
	for(i=0;i<n;i++)
	{
		dist[i]=g[start][i];
		pred[i]=start;
		visited[i]=0;
		
	}
	
	dist[start]=0;
	visited[start]=1;
	count=1;
	while(count<n-1)
	{	mindist=INF;
		for(i=0;i<n;i++)
		{
			if(dist[i]<mindist&&!visited[i])
			{
				mindist=dist[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if((mindist+g[nextnode][i])<dist[i])
				{
					dist[i]=mindist+g[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
	vector<int> v;
		if(end!=start)
		{
			cout<<"Dist of node"<<end<<"is"<<dist[end]<<endl;
			cout<<"Path is"<<end;
			v.push_back(end);
		circle(150,100,15);
		
			j=end;
			do{
				j=pred[j];
				cout<<"<-"<<j;
				v.push_back(j);
			}while(j!=start);
		}
		else
		cout<<"invalid";
		cout<<endl;
		reverse(v.begin(),v.end());
		for(i =0;i<v.size();i++)
		cout<<v[i]<<" ";
		cout<<endl;
		for(i=0;i<v.size()-1;i++)
		{
			path(v[i],v[i+1]);
			delay(1000);
		}
	
}

int main()
{int flag;
do{
int gd = DETECT, gm;

initgraph(&gd, &gm,NULL);
//outtextxy(400,400,"Delhi");

	int i,n,j,start,end;
	cout<<"no of vertices\n";
	cin>>n;
	setcolor(4);
	circle(15,15,15);
	outtextxy(14,15,"A"); 
delay(1000);
	setcolor(5);
	circle(100,50,15);
	outtextxy(99,50,"B");
delay(1000);	
	setcolor(6);
	circle(150,100,15);
	outtextxy(149,100,"C"); 
delay(1000);

	setcolor(7);
	circle(100,250,15);
	outtextxy(99,250,"D");
delay(1000);	
	setcolor(8);
	circle(50,200,15);
	outtextxy(49,200,"E");
delay(1000);	
	
	//graph
	int graph[city][city]={{0,5,7,4,4},{5,0,3,INF,INF},{7,3,0,2,8},{4,INF,2,0,3},{4,INF,8,3,0}};
	cout<<"enter the start node and end node\n";
	cin>>start>>end;
outtextxy(15,15,"");
	
	switch(start)
	{
		case 0:
			outtextxy(15,15,"*");
			break;
		case 1:
			outtextxy(100,50,"*");
			break;
		case 2:
			outtextxy(150,100,"*");
			break;
		case 3:
			outtextxy(100,250,"*");
			break;
		case 4:
			outtextxy(50,200,"*");
			break;
			default:
				break;
	
	}
	
	dijk(graph,n,start,end);
	

cout<<"Run again(0/1) ";
cin>>flag;

/*
circle(10,10,15); 
circle(200,200,15);
circle(300,300,15); 
rectangle(150,150,450,450);	
circle(300,100,10); 
circle(500,100,15);
circle(700,100,15);
line(300,400,700,400);
*/
getch();
closegraph();
}while(flag!=1);
}

