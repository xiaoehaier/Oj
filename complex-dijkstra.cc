/*#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>

using namespace std;

#define M 204

struct city{
    string name;
    unsigned hap;
    unsigned weight;
    bool passed;
    vector<vector<int> >info;
    
    city():hap(0), weight(UINT_MAX), passed(false){}
};

struct city cities[M];
unsigned edge[M][M];
std::map<string, int> id;

int main()
{
    int n, k;
    string c,cc;
    cities[0].weight = 0;
    cities[0].passed = true;
    cities[0].info = {{0, 0}};
    
    while(cin>>n>>k>>c){
        id.clear();
        id[c] = 0;
        cities[0].name = c;
        
        for(int i=1; i<n; ++i){
            cin >> cities[i].name >> cities[i].hap;
            id[cities[i].name] = i;
            cities[i].passed = false;
            cities[i].info.clear();
        }
            
        while(k--){
            int tmp;
            cin >> c >> cc >> tmp;
            edge[id[c]][id[cc]] = tmp;
        }

        cout << id.size() << endl;
        for(auto i : id)
            cout << i.first << "---" << i.second << endl;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                cout << edge[i][j] << " ";
            cout << endl;
        }

        int rom = id["ROM"];

        for(int i=0, j, least; !cities[rom].passed; i=least){
        	for(j=1, least=-1; j<n; ++j){
            	if(cities[j].passed)
                    continue;
                
                if(edge[i][j] || edge[j][i]){
            	    unsigned w = cities[i].weight+max(edge[i][j], edge[j][i]);
                    edge[i][j] = edge[j][i] = 0;
            
            	   if(cities[j].weight > w){
                        cities[j].info = cities[i].info;
                        cities[j].weight = w;
                    }else if(cities[j].weight == w)
                        for(auto k : cities[i].info)
                    	   cities[j].info.push_back(k);
                }
                    
                if(least == -1 || cities[j].weight < cities[least].weight)
                    least = j;  
        	}

            for(auto& k : cities[least].info){
                    k.push_back(least);
                    k[0] += cities[least].hap;
            }

            cities[least].passed = true;
        }
        
        
        vector<vector<int> >path = cities[rom].info;
        cout << path.size() << endl;
        
        if(path.size() > 1){
            vector<vector<int> > tmp;
            for(auto i : path)
                if(tmp.empty() || i[0] == tmp[0][0])
                	tmp.push_back(i);
                else if(i[0] > tmp[0][0]){
                	tmp.clear();
                	tmp.push_back(i);
            	}
            path = tmp;
        }
        cout << path.size() << endl;
        
        if(path.size() > 1){
            vector<vector<int> > tmp;
            for(auto i : path){
                if(tmp.empty()){
                    tmp.push_back(i);
                    continue;
                }
                unsigned a = i[0]/(i.size()-2), b = tmp[0][0]/(tmp[0].size()-2);
                if(a == b)
                	tmp.push_back(i);
                else if(a > b){
                	tmp.clear();
                	tmp.push_back(i);
                }
            }
            path = tmp;
        }
        cout << path.size() << endl;
        
        cout<<cities[rom].info.size()<<' '
            <<cities[rom].weight<<' '
            <<path[0][0]<<' '
            <<path[0][0]/(path[0].size()-2)<<endl;
        
        for(int i=1; i<path[0].size(); ++i)
            cout<<cities[path[0][i]].name<<(i == path[0].size()-1?"\n":"->");
        
    }
    return 0;    
}

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
using namespace std;
 
class Graphm {
    int n;
    vector<int> V;
    vector<vector<int>> E;
    vector<bool> visited;
    vector<int> path;
    vector<int> num;
    vector<int> happy;
    vector<int> bypass;
    vector<int> d;
    int cost_min;
    int happiness_max;
    vector<int> final_path;
 
     
public:
    vector<string> index;
    Graphm(int n):n(n),V(n),E(n),visited(n),num(n),happy(n),bypass(n),d(n),path(n){
        for (int i=0; i<n; i++) {
            vector<int> temp(n);
            E[i]=temp;
        }
    }
    bool addEdge(int v1,int v2,int cost){
        E[v1][v2]=cost;
        E[v2][v1]=cost;
        return true;
    }
    int& getV(int i){
        return V[i];
    }
    vector<int> getNear(int z){
        vector<int> near;
        //vector<int> near_cost;
        for (int i=0; i<n ; i++) {
            if (E[z][i]>0 && !visited[i]) {
                near.push_back(i);
                //near_cost.push_back(E[z][i]);
            }
        }
        return near;
    }
    void dijkstra(int begin,int end){
        for (int i=0; i<n; i++) {
            visited[i]=false;
            bypass[i] = d[i] = numeric_limits<int>::max();
            num[i] = happy[i] = 0;
            path[i] = -1;
        }
        d[begin]=0;
        visited[begin]=0;
        num[begin]=1;
        bypass[begin]=0;
        for (int i=0; i<n; i++) {
            int k=-1;
            for (int j=0; j<n; j++) {
                if (!visited[j] && (k<0 || d[j]<d[k])) {
                    k=j;
                }
            }
            visited[k]=true;
            for (int j=0; j<n; j++) {
                if (!visited[j] && E[k][j]>0) {
                    int cost = d[k]+E[k][j];
                    if (cost<d[j]) {
                        d[j]=cost;
                        num[j]=num[k];
                        path[j]=k;
                        happy[j]=happy[k]+V[j];
                        bypass[j]=bypass[k]+1;
                    }else if (cost == d[j]){
                        num[j]+=num[k];
                        if (happy[j]<happy[k]+V[j] ||
                            (happy[j]==happy[k]+V[j] && bypass[j]>bypass[k]+1)) {
                            d[j]=cost;
                            path[j]=k;
                            happy[j]=happy[k]+V[j];
                            bypass[j]=bypass[k]+1;
                        }
                    }
                }
            }
        }
    }
    void out(int i){
        cout<<num[i]<<' '
            <<d[i]<<' '
            <<happy[i]<<' '
            <<happy[i]/bypass[i]
            <<endl;
        print_path(i);
    }
    void print_path(int i){
        if (path[i]!=-1) {
            print_path(path[i]);
            cout<<"->";
        }
        cout<<index[i];
    }
 
};
 
int main(int argc,const char* argv[]){
    int N,M;
    cin>>N>>M;
    Graphm G(N);
    map<string, int> index;
    vector<string> dict;
    string city;
    int happiness;
    cin>>city;
    dict.push_back(city);
    index[city]=0;
    for (int i=1; i<N; i++) {
        cin>>city>>happiness;
        G.getV(i)=happiness;
        index[city]=i;
        dict.push_back(city);
    }
    string c1,c2;
    int cost;
    for (int i=0; i<M; i++) {
        cin>>c1>>c2>>cost;
        G.addEdge(index[c1],index[c2],cost);
    }
    G.index=dict;
    G.dijkstra(0, 1);
    G.out(index["ROM"]);
    cout<<endl;
    return 0;
}
