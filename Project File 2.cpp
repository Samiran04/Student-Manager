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
		map<string,map<string,pair<string,string> > >rn;string name,roll,sub,Class;
	public:
		RNCtab(ifstream &fin){
			while(true)
			{
				if(fin.eof())
				break;
			fin>>roll>>name>>sub>>Class;
			rn[roll][name].first=sub;
			rn[roll][name].second=Class;
		}
		}
		void Info(string roll){
			if(rn.count(roll)==0)
			cout<<endl<<"Not Found."<<endl<<endl;
			else{
			map<string,pair<string,string> >::iterator itr=rn[roll].begin();
			cout<<endl<<"Registration Number:"<<roll<<ends<<ends<<"Name:"<<itr->first<<ends<<ends<<"Branch:"<<itr->second.first<<ends<<ends<<"Section:"<<itr->second.second<<endl<<endl<<endl;
		}
		}
};
class RNAtab{
	private:
		map<string,map<string,int> >rna,rna2;string name,roll;int attendence,total,total2,Roll;char command;
	public:
		RNAtab(ifstream &fin,ifstream &fin2){
			Roll=1;
			fin>>total;
			while(true){
				if(fin.eof())
				break;
				fin>>roll>>name>>attendence;
				rna[roll][name]=attendence;
			}
			fin2>>total2;
			while(true){
			   if(fin2.eof())
				break;
				fin2>>roll>>name>>attendence;
				rna2[roll][name]=attendence;	
			}
		}
		void ShowAttendence(){
			map<string,map<string,int> >::iterator itr=rna.begin();
			while(itr!=rna.end())
			{
				map<string,int>::iterator it=itr->second.begin();
				cout<<endl<<itr->first<<ends<<it->first<<ends<<((float)it->second/total)*100<<endl;
				itr++;
			}
		}
		void ShowAttendence2(){
			map<string,map<string,int> >::iterator itr=rna2.begin();
			while(itr!=rna2.end())
			{
				map<string,int>::iterator it=itr->second.begin();
				cout<<endl<<itr->first<<ends<<it->first<<ends<<((float)it->second/total)*100<<endl;
				itr++;
			}
		}
		void E1808(){
			map<string,map<string,int> >::iterator itr=rna.begin();
			ofstream fout;
			fout.open("E1808.txt",ios::out);
			fout<<total+1<<endl;
			cout<<endl<<"Section E1808"<<endl;
			while(true)
			{
				map<string,int>::iterator it=itr->second.begin();
				if(itr==rna.end())
				break;
				cout<<"Roll Number "<<Roll<<":";
				cin>>command;
				if(command!='a'&&command!='p'){
				cout<<"Invalid key"<<endl;
				continue;
			}
				fout<<itr->first<<ends<<it->first<<ends;
				if(command=='p')
				fout<<it->second+1<<endl;
				else if(command=='a')
				fout<<it->second<<endl;
				Roll++;
				itr++;
			}
			Roll=1;
			fout.close();
		}
			void E1806(){
			map<string,map<string,int> >::iterator itr=rna2.begin();
			ofstream fout;
			fout.open("E1806.txt",ios::out);
			fout<<total2+1<<endl;
			cout<<endl<<"Section E1806"<<endl;
			while(true)
			{
				map<string,int>::iterator it=itr->second.begin();
				if(itr==rna2.end())
				break;
				cout<<"Roll Number "<<Roll<<":";
				cin>>command;
				if(command!='a'&&command!='p'){
				cout<<"Invalid key"<<endl;
				continue;
			}
				fout<<itr->first<<ends<<it->first<<ends;
				if(command=='p')
				fout<<it->second+1<<endl;
				else if(command=='a')
				fout<<it->second<<endl;
				Roll++;
				itr++;
			}
			Roll=1;
			fout.close();
		}
};
class RSMtab{
	private:
		map<string,map<string,float> >focus;
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
				if(marks<40)
				focus[roll][sub]=marks;
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
		void rankavg(){
			average();
			sort(ar.begin(),ar.end());
			reverse(ar.begin(),ar.end());
		}
		void getrank(string roll){
			int i=0;
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
		void NeedFocus(){
			if(focus.empty())
			{
				cout<<endl<<"No Student Need focus"<<endl<<endl;
				return;
			}
			map<string,map<string,float> >::iterator itr=focus.begin();
			while(itr!=focus.end())
			{
				map<string,float>::iterator it=itr->second.begin();
				cout<<endl<<itr->first<<ends;
				while(it!=itr->second.end()){
				cout<<it->first<<ends<<it->second<<endl;
				cout<<setw(8);
				it++;
			}
				itr++;
			}
			cout<<endl<<endl;
		}
};
int main()
{
	ofstream fout,fout2;
	fout.open("Student.txt",ios::app);
	fout2.open("Marks.txt",ios::app);
	ifstream fin,fin2,fin3,fin4;
	fin.open("Student.txt",ios::in);
	fin2.open("Marks.txt",ios::in);
	fin3.open("E1808.txt",ios::in);
	fin4.open("E1806.txt",ios::in);
	RNCtab rnc(fin);
	RSMtab rsm(fin2);
	RNAtab rna(fin3,fin4);
	rsm.rankavg();
	string roll,name,course,subject,Class;int command;float marks;
	cout<<"\t\t\t\t\t\t"<<"Welome to Student Data Base"<<endl<<endl<<endl;
	while(true){
		cout<<"\t\t\t\t\t\t1.Student Information"<<endl<<"\t\t\t\t\t\t2.Marks"<<endl<<"\t\t\t\t\t\t3.Rank"<<endl<<"\t\t\t\t\t\t4.Attendence"<<endl<<"\t\t\t\t\t\t5.EXIT"<<endl<<endl;
		cout<<"\t\t\t\t\t\tPlease Enter Your Choise:";
		cin>>command;
		cout<<endl<<endl;
		if(command==5)
		break;
		else if(command==1)
		{
			while(true){
			cout<<"\t\t\t\t\t\t1.Search Student"<<endl<<"\t\t\t\t\t\t2.Enter Student Information"<<endl<<"\t\t\t\t\t\t3.Students Need Focus"<<endl<<"\t\t\t\t\t\t4.Exit"<<endl<<endl;
			cout<<"\t\t\t\t\t\tPlease Enter Your Choise:";
			cin>>command;
			if(command==4)
			break;
			else if(command==1){
			cout<<"\t\t\t\t\t\tEnter Registration number:";
			cin>>roll;
			rnc.Info(roll);
		}
		    else if(command==2)
		    {
		    	cout<<"\t\t\t\t\t\tEnter Registration number:";cin>>roll;fout<<endl<<roll<<ends;
		    	cout<<"\t\t\t\t\t\tEnter name of student:";cin>>name;fout<<name<<ends;
		    	cout<<"\t\t\t\t\t\tEnter Branch:";cin>>course;fout<<course<<ends;
		    	cout<<"\t\t\t\t\t\tEnter Section:";cin>>Class;fout<<Class;
			}
			else if(command==3)
				rsm.NeedFocus();
				else
				cout<<endl<<"\t\t\t\t\t\tInvalid Key."<<endl<<endl;
	     	}
     	}
			
			    else if(command==2)
			    {
			    	while(true){
		    		cout<<"\t\t\t\t\t\t1.View marks"<<endl<<"\t\t\t\t\t\t2.Enter marks"<<endl<<"\t\t\t\t\t\t3.Exit"<<endl<<endl;
		    		cout<<"\t\t\t\t\t\tPlease Enter Your Choise:";
		    		cin>>command;
		    		if(command==3)
		    		break;
		    		else if(command==1){
		        	cout<<"\t\t\t\t\t\tEnter Registration number:";
			        cin>>roll;
			        rsm.mark(roll);
		            }
		            else if(command==2){
			    	cout<<"\t\t\t\t\t\tEnter Resistration number:";
			    	cin>>roll;fout2<<endl<<roll<<ends;
			    	cout<<"\t\t\t\t\t\tEnter subject:";
			    	cin>>subject;fout2<<subject<<ends;
			    	cout<<"\t\t\t\t\t\tEnter Marks:";
			    	cin>>marks;fout2<<marks;
			    }
			    else
				cout<<endl<<"\t\t\t\t\t\tInvalid Key."<<endl<<endl;
				}
		}
		else if(command==3)
		{
			cout<<"\t\t\t\t\t\tEnter Registration number:";
			cin>>roll;
			rsm.getrank(roll);
		}
		else if(command==4)
		{
			while(true){
				cout<<"\t\t\t\t\t\t1.E1806"<<endl<<"\t\t\t\t\t\t2.E1808"<<endl<<"\t\t\t\t\t\t3.Exit"<<endl<<endl;
				cout<<"\t\t\t\t\t\tPlease Enter Your Choise:";
				cin>>command;
				if(command==3)
				break;
				else if(command==1){
						while(true){
						cout<<"1.View Class Attendence List"<<endl<<"2.Take Attendence"<<endl<<"3.Exit"<<endl<<endl;
						cin>>command;
						if(command==3)
						break;
			            else if(command==1)
			            rna.ShowAttendence2();
			            else if(command==2)
			            rna.E1806();
			            else
				cout<<endl<<"\t\t\t\t\t\tInvalid Key."<<endl<<endl;
		}
				}
				else if(command==2){
					while(true){
						cout<<"\t\t\t\t\t\t1.View Class Attendence List"<<endl<<"\t\t\t\t\t\t2.Take Attendence"<<endl<<"\t\t\t\t\t\t3.Exit"<<endl<<endl;
						cout<<"\t\t\t\t\t\tPlease Enter Your Choise:";
						cin>>command;
						if(command==3)
						break;
			            else if(command==1)
			            rna.ShowAttendence();
			            else if(command==2)
			            rna.E1808();
			            else
				cout<<endl<<"\t\t\t\t\t\tInvalid Key."<<endl<<endl;
		}
		}
		else
				cout<<endl<<"\t\t\t\t\t\tInvalid Key."<<endl<<endl;
		}
		}
		else
		cout<<endl<<"\t\t\t\t\t\tInvalid option."<<endl<<endl;
	}
	fin.close();
	fin2.close();
	fin3.close();
	fin4.close();
	fout.close();
	fout2.close();
	return 0;
}
