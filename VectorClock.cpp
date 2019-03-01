/**
 * @Author: tarun3k
 * @Date:   Feb 28, 2019 4:02 PM
 * @Last modified by:   tarun3k
 * @Last modified time: Mar 1, 2019 1:01 PM
 */
#include<bits/stdc++.h>
using namespace std;
typedef pair< pair<int,int>,pair<int,int >  > ppipi;
int main()
{
   int pn;
       cout<<"\nEnter the total number of processes:";cin>>pn;
       cout<<"\nEnter total events of each process::";
       vector<int> v(pn,0);
       int m=0;
       for(int i=0;i<pn;i++)
         {cin>>v[i];
           m=max(m,v[i]);}
           vector< ppipi > trans;
            char ch='y';
            int a,b,c,d;
           while(ch=='y')
           {cout<<"\nEnter Transition (p,e)->(p',e'):";
              cin>>a>>b>>c>>d;
              trans.push_back(make_pair(make_pair(a,b),make_pair(c,d)));
              cout<< "\nmore transition press (y):";cin>>ch;
           }
           sort(trans.begin(),trans.end(), [](ppipi a,ppipi b)->bool{return (a.second.second<=b.second.second && a.second.second<=b.first.second && a.first.first>b.first.first);});
          for(int i=0;i<trans.size();i++)
           {
             cout<<trans[i].first.first<<" "<<trans[i].first.second<<" "<<trans[i].second.first<<" "<<trans[i].second.second<<" "<<'\n';
           }

         vector< vector< vector<int> > > vec(pn,vector<vector<int > >(m,vector<int>(pn,0)));
         for(int i=0;i<pn;i++)
         {
           for(int j=0;j<v[i];j++)
           {
             vec[i][j][i]=j+1;

           }
         }
         int p1,e1,t1,p2,e2,t2;
          for(int x=0;x<trans.size();x++)
          {
            p1=trans[x].first.first-1;
            e1=trans[x].first.second-1;
            p2=trans[x].second.first-1;
            e2=trans[x].second.second-1;


            for(int i=0;i<pn;i++)
            {  if(i!=p2)
              vec[p2][e2][i]=max(vec[p2][e2][i],vec[p1][e1][i]);}
             e2++;

            while(e2<v[p2])
            {
              for(int i=0;i<pn;i++)
              {
                if(i!=p2)
                vec[p2][e2][i]=vec[p2][e2-1][i];

              }
              e2++;
            }

          }

         for(int i=0;i<pn;i++)
         {
           for(int j=0;j<v[i];j++)
           {  cout<<"( ";
             for(int k=0;k<pn-1;k++)
             {
               cout<<vec[i][j][k]<<" , ";
             }
             cout<<vec[i][j][pn-1]<<")\t";
           }
           cout<<'\n';
         }



  return 0;
}
