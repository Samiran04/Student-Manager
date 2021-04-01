#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class RNCtab{
	private:
		map<string,map<string,string> >rn;string name,roll,sub;
	public:
		RNCtab(ifstream &fin){
			while(true)
			{
				if(fin.eof())
				break;
			fin>>roll>>name>>sub;
			rn[roll][name]=sub;
		}
		}
		void Info(string roll){
			if(rn.count(roll)==0)
			cout<<endl<<"Not Found."<<endl<<endl;
			else{
			map<string,string>::iterator itr=rn[roll].begin();
			cout<<endl<<"Registration Number:"<<roll<<ends<<ends<<"Name:"<<itr->first<<ends<<ends<<"Branch:"<<itr->second<<endl<<endl<<endl;
		}
		}
};
class RSMtab{
	private:
		map<string,map<string,float> >rsm;string roll,sub;
		vector<pair<float,string> >ar;
		float marks;
	public:
		RSMtab(ifstream &fin){
			while(true){
				if(fin.eof())
				break;
				fin>>roll>>sub>>marks;
				rsm[roll][sub]=marks;
			}
		}
		void mark(string roll){
			if(rsm.count(roll)==0){
			cout<<endl<<"Not Found."<<endl<<endl;
			return;
		}
			map<string,float>::iterator itr=rsm[roll].begin();
			cout<<endl<<roll<<ends;
			while(itr!=rsm[roll].end())
			{
				cout<<itr->first<<ends<<itr->second<<endl;
				cout<<setw(12);
			    itr++;
			}
			cout<<endl<<endl;
		}
		void average(){
			float avg=0;int subcount=0;
			map<string,map<string,float> >::iterator itr=rsm.begin();
			while(itr!=rsm.end()){
				map<string,float>::iterator itra=itr->second.begin();
				while(itra!=itr->second.end())
				{
					avg=itra->second+avg;
					itra++;subcount++;
				}
				ar.push_back(make_pair(avg/subcount,itr->first));
				avg=0;subcount=0;
				itr++;
			}
		}
		bool compare(pair<float,string>&p1,pair<float,string>&p2){
			if(p1.first<p2.first)
			return true;
			return false;
		}
		void rankavg(string roll){
			average();
			int i=0;
			sort(ar.begin(),ar.end());
			reverse(ar.begin(),ar.end());
			while(i<ar.size()){
				if(ar[i].second==roll)
				break;
				i++;
			}
			if(i==ar.size())
			cout<<endl<<"Not Found."<<endl<<endl;
			else
			cout<<endl<<"Rank:"<<i+1<<endl<<"Average:"<<ar[i].first<<endl<<endl;
		}
};
int main()
{
	ofstream fout,fout2;
	fout.open("Student.txt",ios::app);
	fout2.open("Marks.txt",ios::app);
	ifstream fin,fin2;
	fin.open("Student.txt",ios::in);
	fin2.open("Marks.txt",ios::in);
	RNCtab rnc(fin);
	RSMtab rsm(fin2);
	string roll,name,course,subject;int command;float marks;
	while(true){
		cout<<"1.Student Information"<<endl<<"2.Marks"<<endl<<"3.Rank"<<endl<<"4.EXIT"<<endl;
		cin>>command;
		if(command==4)
		break;
		else if(command==1)
		{
			while(true){
			cout<<"1.Search Student"<<endl<<"2.Enter Student Information"<<endl<<"3.Exit"<<endl;
			cin>>command;
			if(command==3)
			break;
			else if(command==1){
			cout<<"Enter Registration number:";
			cin>>roll;
			rnc.Info(roll);
		}
		    else if(command==2)
		    {
		    	cout<<"Enter Registration number:";cin>>roll;fout<<endl<<roll<<ends;
		    	cout<<"Enter name of student:";cin>>name;fout<<name<<ends;
		    	cout<<"Enter Branch:";cin>>course;fout<<course;
			}
	     	}
     	}
			
			    else if(command==2)
			    {
			    	while(true){
		    		cout<<"1.View marks"<<endl<<"2.Enter marks"<<endl<<"3.Exit"<<endl;
		    		cin>>command;
		    		if(command==3)
		    		break;
		    		else if(command==1){
		        	cout<<"Enter Registration number:";
			        cin>>roll;
			        rsm.mark(roll);
		            }
		            else if(command==2){
			    	cout<<"Enter Resistration number:";
			    	cin>>roll;fout2<<endl<<roll<<ends;
			    	cout<<"Enter subject:";
			    	cin>>subject;fout2<<subject<<ends;
			    	cout<<"Enter Marks:";
			    	cin>>marks;fout2<<marks;
			    }
				}
		}
		else if(command==3)
		{
			cout<<"Enter Registration number:";
			cin>>roll;
			rsm.rankavg(roll);
		}
		else
		cout<<"Invalid option."<<endl;
	}
	fin.close();
	fin2.close();
	fout.close();
	fout2.close();
	return 0;
}

