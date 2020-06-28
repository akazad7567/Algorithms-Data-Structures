#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//map<string,string>d;
void BFS(string st,string dt,map<string,vector<string>>graph)
{
    map<string,bool>visited;
    queue<string>Q;
    map<string,int>d;
    map<string,string>p;
    visited.clear();
    d.clear();
    p.clear();

    visited[st]=true;
    Q.push(st);
    p[st]="?";

    while(Q.empty()==false)
    {
        string top=Q.front();
        // cout<<top<<"-> ";
        Q.pop();
        int sz=graph[top].size();

        for(int i=0; i<sz; i++)
        {
            //cout<<"check: "<<visited[graph[top][i]]<<endl;
            if(visited[graph[top][i]]==false)
            {
                visited[graph[top][i]]=true;
                d[graph[top][i]]=d[top]+1;
                p[graph[top][i]]=top;
                Q.push(graph[top][i]);
                //cout<<"d= "<<graph[top][i]<<' '<<d[graph[top][i]]<<endl;
                // cout<<graph[top][i]<<' ';
            }
        }
    }


    if(visited[dt]==false)
        cout<<"No route\n";
    else
    {
        string str;
        int sz=d[dt];
        string tmp=dt;
        for(int i=0; i<sz; i++)
        {
            //cout<<tmp<<' '<<p[tmp]<<endl;
            //str[j++]=tmp,str[j++]=p[tmp];
            str+=tmp+" "+p[tmp]+" ";
            tmp=p[tmp];

        }
        reverse(str.begin(),str.end());
        stringstream ss(str);
        int cnt=0;
        while(ss>>tmp)
        {
            reverse(tmp.begin(),tmp.end());
            cnt++;
            cout<<tmp;
            if(cnt &1)
                cout<<" ";
            else
                cout<<endl;


        }
    }
   // cout<<endl;
    graph.clear();



}

int main()
{
//    freopen("out.txt","w",stdout);
    int t;
    bool p=false;
    while(scanf("%d ",&t)!=EOF)
    {
        map<string,vector<string>>graph;
        graph.clear();
        while(t--)
        {
            string line;
            getline(cin,line);
            string prnt,cld,tmp;
            stringstream ss(line);
            ss>>tmp;
            prnt=tmp;
            ss>>tmp;
            cld=tmp;
            graph[prnt].push_back(cld);
            graph[cld].push_back(prnt);

        }

        string str;
        string st,dt,tmp;
        getline(cin,str);

        stringstream ss2(str);
        ss2>>tmp;
        st=tmp;
        ss2>>tmp;
        dt=tmp;
        if(p) printf ("\n");p = true;

        BFS(st,dt,graph);
        graph.clear();

    }
    return 0;
}
