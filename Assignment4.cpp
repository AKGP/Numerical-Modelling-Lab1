#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct boreHole {
	double x,y,z;
	vector<boreHole> pairs;
}boreHole;

double findDist(double x1,double y1,double x2,double y2){
	return sqrt(pow(x1-x2,2)+(y1-y2,2));
}
vector <boreHole> findPairs(boreHole mat[][6], double x, double y,int row,int col,int n, int m,double h, double distance,double degree){
	vector<boreHole> v;
	if(degree==0){
		for(int i =col+1;i<m;i++){
			double dis;
			dis = findDist(x,y,mat[row][i].x,mat[row][i].y);
			if(dis>=distance-h&&dis<=distance+h&&mat[row][i].z!=-1){
				v.push_back(mat[row][i]);
			}
		}
		return v;
	}
	// else if(degree==90){
	// 	for(int i =row-1;i>=0;i--){
	// 		double dis=0;
	// 		dis = findDist(x,y,mat[i][col].x,mat[i][col].y);
	// 		if(dis>=distance-h&&dis<=distance+h&&mat[i][col].z!=-1){
	// 			v.push_back(mat[i][col]);
	// 		}
	// 	}
	// 	return v;
	// }
	
}
int main(){
	int n,m;
	cin>>n>>m;
	boreHole mat[6][6];
	for(int i =n-1;i>=0;i--){
		for(int j =0;j<m;j++){
			cin>>mat[i][j].x>>mat[i][j].y>>mat[i][j].z;
			cout<<mat[i][j].z<<" \n";
		}
	}
	double gamma[4]={0,0,0,0};
	double distance[4] = {50,100,150,200};
	double h = 5;
	int c = 0;
	for(int k=0;k<4;k++){
		int size = 0;
		for(int i =n-1;i>=0;i--){
			for(int j=0;j<m;j++){
				mat[i][j].pairs = findPairs(mat,mat[i][j].x,mat[i][j].y,i,j,n,m,h,distance[k],0);				
				for(vector<boreHole>::iterator it=mat[i][j].pairs.begin();it!=mat[i][j].pairs.end();it++){
					gamma[k]+=(pow((mat[i][j].z - (*it).z),2));
					size++;
				}			
			}
	}
gamma[k] = gamma[k]/(2*size);
}

for(int i =0;i<4;i++){
	cout<<gamma[i]<<" ";
}
return 0;
}
