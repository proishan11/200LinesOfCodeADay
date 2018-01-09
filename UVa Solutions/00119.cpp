#include<bits/stdc++.h>
using namespace std;

char name[10][13];
int ammount[10];
char temp[15];


int find(int no_of_people){
	for(int i=0; i<no_of_people; ++i)
		if(!strcmp(temp,name[i])) return i;
}

int main(){
	int no_of_people,a,b,flag=1;
	while(scanf("%d",&no_of_people)!=EOF){
		for(int i=0; i<no_of_people; ++i){
			scanf("%s",&name[i]);
			ammount[i]=0;
		}
		/*for(int i=0; i<no_of_people; ++i)
			printf("%s\n", name[i]);
		*/
		for(int i=0; i<no_of_people; ++i){
			scanf("%s %d %d",&temp,&a,&b);
			int index1 = find(no_of_people);
			//Note the remainder(a%j) may not be <1;
			if(b==0) continue;
			ammount[index1]-= a-a%b;

			for(int j=0; j<b; ++j){
				scanf("%s",&temp);
				int index2 = find(no_of_people);
				ammount[index2]+=a/b;
			}
		}
		if(!flag) printf("\n");
		flag = 0;
		for(int i=0; i<no_of_people; ++i)
			printf("%s %d\n",name[i],ammount[i]);
	}

}