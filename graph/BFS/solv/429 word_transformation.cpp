#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int BFS(string start,string dt,map< string,vector<string> >graph)
{

    map<string,int>visited;
    queue<string>Q;
    visited.clear();
    Q.push(start);
    while(Q.empty()==false)
    {
        string top=Q.front();
        Q.pop();
        int sz=graph[top].size();
        if(top==dt) return visited[top];

        for(int i=0;i<sz;i++)
        {
            if(!visited.count(graph[top][i]))
            {
                visited[graph[top][i]]=visited[top]+1;
                Q.push(graph[top][i]);
            }
        }
    }
    //cout<<"outer 2\n";
}



int main()
{
    int t;
    scanf("%d",&t);
    map<string,vector<string>>graph;
    while(t--)
    {
      //cin.ignore();
      string word,tmp;
      int sz1,sz2;
      cin>>word;
      while(word!="*")
      {
          graph[word];
          map<string,vector<string>>::const_iterator it;
          sz1=word.size();
          for(it=graph.begin();it!=graph.end();it++)
          {
              tmp=(*it).first;
              sz2=tmp.size();
              int df=0;
              if(sz1==sz2)
              {
                  for(int i=0;i<sz1;i++)
                  {
                      if(tmp[i]!=word[i]) df++;
                  }

                  if(df==1)
                  {
                      graph[word].push_back(tmp);
                      graph[tmp].push_back(word);
                  }
              }
          }

          cin>>word;
      }
      cin.ignore();
      string line;
      //getline(cin,line);
      while(getline(cin,line) and line!=""){
      size_t pos;
      pos=line.find(" ");
      string start,dt;
      start=line.substr(0,pos);
      dt=line.substr(pos+1,line.size());
      //cout<<start<<' '<<dt<<endl;
      int re=BFS(start,dt,graph);
      cout<<start<<' '<<dt<<' '<<re<<endl;
      }
      if(t!=0) cout<<endl;

    }
}

