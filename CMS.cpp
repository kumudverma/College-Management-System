#include<bits/stdc++.h>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<fstream>
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
char un[20];
class Admin
{
    char name[20];
    int totalsub;
    char subject[10][10],mobile[15],mail[50],fname[20],passwd[20],rpasswd[20];
    public:
    char  rollno[15];
    //this function is used to get the student data entey from the ADMIN portal... 
    //all the records entries are made by this method
    void getstdata()
    {
        cout<<"\nEnter the Student Name : ";
        cin.ignore();
        cin.getline(name,20);
        cout<<"\nEnter the Student ID/Roll No. : ";
        cin.getline(rollno,20);
        cout<<"\nEnter the Student Father Name : ";
        cin.getline(fname,20);
        cout<<"\nEnter the Mobile Number : ";
        cin.clear();
        cin.getline(mobile,20);
        cout<<"\nEnter the Email ID : ";
        cin.clear();
        cin.getline(mail,50);
        cout<<"\nEnter the Total Subjects : ";
        cin>>totalsub;
        cin.ignore();
        for(int i=0;i<totalsub;i++)
        {
            cout<<"\nEnter the Subject "<<i+1<<" Name : ";
            cin.clear();
        cin.getline(subject[i],20);
        }
        cout<<"\nCreate Your Login Password : ";
        cin.getline(passwd,20);
        cout<<"\nEnter the Unique Keyword to Recover Password : ";
        cin.getline(rpasswd,20);
        cout<<"\n\nPlease Note Your UserName is ID/Roll no.\n";
    }
    //this function aunthicates the login of both the student & faculties.
    //With their reference to their unique ID/PASSWORD login is provided
    int login()
    {
        if((strcmp(::un,rollno))==0)
        {
            cout<<"\nEnter the Login Password : ";
            int len=0;
            len=strlen(passwd);
            char inputpasswd[20],p[20];
            memset(inputpasswd, '\0', sizeof(inputpasswd));
            int i;
            for(i=0;i<len;i++)
            {
                p[i]=getch();
                cout<<"#";
            }
            for(i=0;i<len;i++)
            {
                inputpasswd[i]=p[i];
            }
            //cout<<"\nThe Entered Password is "<<inputpasswd;
            if((strcmp(::un,rollno)==0)&&(strcmp(passwd,inputpasswd)==0))
                return 1;
            else
                return 0; 
        }
        else 
            return 0;
    }
    //this function help both students and faculties to recover the password with the help 
    //of unique  keyword provided by the admin
    int recover()
    {
        //cout<<"The Input Username is "<<::un;
        char key[20];
        if(strcmp(::un,rollno)==0)
        {
            cout<<"\nEnter the Unique Keyword (Provided by Admin ) : ";
            char p[20];
            memset(key, '\0', sizeof(key));
            int i,len=strlen(rpasswd);
            for(i=0;i<len;i++)
            {
                p[i]=getch();
                cout<<"#";
            }
            for(i=0;i<len;i++)
            {
                key[i]=p[i];
            }
            if((strcmp(key,rpasswd)==0))
            {
                cout<<"\nYou are a Valid user. ";
                cout<<"\nYour Password is "<<passwd;
                cout<<"\nPlease Exit To Login Again ";
                return 1;
            }
        }
        else 
            return 0;
    }
    //this function is to displays the faculty profile to the faculty at their respective portals
    int faprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nFaculty Name          : "<<name;
            cout<<"\nFaculty Father's Name : "<<fname;
            cout<<"\nFaculty Mobile No.    : "<<mobile;
            cout<<"\nFaculty Email ID      : "<<mail;
            return 1;
        }
        else 
            return 0;
    }
    //this function display the diffrent enrolled subjects of respective facuilty
    //...according to their profile.
    int knowfasub() 
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nFaculity Total Subjects :- "<<totalsub;
            for(int i=0;i<totalsub;i++)
            {
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }
        else 
            return 0;
        
    }
    //this function  helps a facuilty to add a subject in their module 
    void addfasub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totalsub];
            totalsub++;
            cout<<"\n\nNew subject Added Successfully....";
        }
    }
    //this function help faculty  to delete a subject from their respective module
    void delfasub()
    {
        knowfasub();
        int de=0;
        if((strcmp(::un,rollno)==0))
        {
            if(totalsub==0||totalsub<0)
            {
                totalsub=0;
                cout<<"\nNone subject Exist...";
                getch();
                exit(0);
            }
            cout<<"\nEnter the Subject No.to be Deleted : ";
            cin>>de;
            cin.ignore();
            if(de==totalsub)
            {
                totalsub--;
            }
            else if(totalsub==1)
            {
                totalsub--;
                strcpy(subject[totalsub]," ");
            }
            else 
            {
                de--;
                strcpy(subject[totalsub]," ");
                for(int p=de;p<totalsub;p++)
                {
                    strcpy(subject[p],subject[p+1]);
                }
                totalsub--;
            }
            cout<<"\n Record Updated Successfully...";
        }
    }
    //this function help a facuilty to modify his personal profile
    void modfaprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nThe profile Details are : ";
            cout<<"\n 1. Faculty E-mail : "<<mail;
            cout<<"\n 2. Faculty Mobile : "<<mobile;
            int g=-1;
            cout<<"\n\nEnter the Details No. to br Modified : ";
            cin>>g;
            cin.ignore();
            if(g==1)
            {
                char nmail[50];
                cout<<"\nEnter the New Mail Address : ";
                cin.getline(nmail,50);
                strcpy(mail,nmail);
                cout<<"\nRecord Updated Successfully...";
            }
            else if(g==2)
            {
                char nmobile[15];
                cout<<"\nEnter the New Mobile No. : ";
                cin.getline(nmobile,20);
                strcpy(mobile,nmobile);
                cout<<"\nRecord Updated Successfully...";
            }
            else 
                cout<<"\nInvalid Input Provided....";
        }
    }
    //this function display the diffrent enrolled subjects of respective students
    //...according to their profile.
    int knowstsub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nStudent Total Subject :-"<<totalsub;
            for(int i=0;i<totalsub;i++)
            {
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }
        else 
            return 0;
    }
    //this function allows the student to add a subjects in total subjects of the student profile....
    void addstsub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totalsub];
            totalsub++;
            cout<<"\n\nNew subject Added Successfully....";
        }
    }
    //this function allows the student to delete a subjects in total subjects of the student profile....
    void delstsub()
    {
        knowstsub();
        int de=0;
        if((strcmp(::un,rollno)==0))
        {
            if(totalsub==0||totalsub<0)
            {
                totalsub=0;
                cout<<"\nNone subject Exist...";
                getch();
                exit(0);
            }
            cout<<"\nEnter the Subject No.to be Deleted : ";
            cin>>de;
            cin.ignore();
            if(de==totalsub)
            {
                totalsub--;
            }
            else if(totalsub==1)
            {
                totalsub--;
                strcpy(subject[totalsub]," ");
            }
            else 
            {
                de--;
                strcpy(subject[totalsub]," ");
                for(int p=de;p<totalsub;p++)
                {
                    strcpy(subject[p],subject[p+1]);
                }
                totalsub--;
            }
            cout<<"\n Record Updated Successfully...";
        }
    }
    //this function allows student to modify their personal profile details at hr student portal 
    void modstprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nThe profile Details are : ";
            cout<<"\n 1. Student E-mail : "<<mail;
            cout<<"\n 2. Student Mobile : "<<mobile;
            int g=-1;
            cout<<"\n\nEnter the Details No. to br Modified : ";
            cin>>g;
            cin.ignore();
            if(g==1)
            {
                char nmail[50];
                cout<<"\nEnter the New Mail Address : ";
                cin.getline(nmail,50);
                strcpy(mail,nmail);
                cout<<"\nRecord Updated Successfully...";
            }
            else if(g==2)
            {
                char nmobile[15];
                cout<<"\nEnter the New Mobile No. : ";
                cin.getline(nmobile,20);
                strcpy(mobile,nmobile);
                cout<<"\nRecord Updated Successfully...";
            }
            else 
                cout<<"\nInvalid Input Provided....";
        }
    }
    //this funnction displays the student profile at the student portals
    int stprofile()
    {
    if((strcmp(::un,rollno)==0))
    {
        cout<<"\nStudent Name          : "<<name;
        cout<<"\nStudent Father's Name : "<<fname;
        cout<<"\nStudent Mobile No.    : "<<mobile;
        cout<<"\nStudent Email ID      : "<<mail;
        return 1;
    }
    else 
        return 0;
    }


    //this function allows the admin to make a new Record Entry for the different new faculties
    //...new facuilty records are updated with the help of this function 
    void getfadata()
    {
        cout<<"\nEnter the Facuilty Name : ";
        cin.ignore();
        cin.getline(name,20);
        cout<<"\nEnter the Facuilty ID/Roll No. : ";
        cin.getline(rollno,20);
        cout<<"\nEnter the Facuilty Father Name : ";
        cin.getline(fname,20);
        cout<<"\nEnter the Mobile Number : ";
        cin.clear();
        cin.getline(mobile,20);
        cout<<"\nEnter the Email ID : ";
        cin.clear();
        cin.getline(mail,50);
        cout<<"\nEnter the Total Subjects : ";
        cin>>totalsub;
        cin.ignore();
        for(int i=0;i<totalsub;i++)
        {
            cout<<"\nEnter the Subject "<<i+1<<" Name : ";
            cin.clear();
        cin.getline(subject[i],20);
        }
        cout<<"\nCreate Your Login Password : ";
        cin.getline(passwd,20);
        cout<<"\nEnter the Unique Keyword to Recover Password : ";
        cin.getline(rpasswd,20);
        cout<<"\n\nPlease Note Your UserName is ID/Roll no.\n";
    }
    //This function dispaly all the relevant information to the admin related 
    //to the Students at the Admin portals
    void stdisplay()
    {
        cout<<"\nStudent Name          : "<<name;
        cout<<"\nStudent ID/Roll No.   : "<<rollno;
        cout<<"\nStudent Father's Name : "<<fname;
        cout<<"\nStudent Mobile No.    : "<<mobile;
        cout<<"\nStudent E-Mail ID     : "<<mail;
        cout<<"\nStudent Subjects      : "<<totalsub;
        for(int i=0;i<totalsub;i++)
        {
            cout<<"\n     Subject "<<i+1<<" : "<<subject[i];
        }
        if(totalsub==0)
            cout<<"( None Subject Specified...) ";
    }
    //This function dispaly all the relevant information to the admin related 
    //to the Faculty at the Admin portals
    void fadisplay()
    {
        cout<<"\nFaculty Name          : "<<name;
        cout<<"\nFaculty ID/Roll No.   : "<<rollno;
        cout<<"\nFaculty Father's Name : "<<fname;
        cout<<"\nFaculty Mobile No.    : "<<mobile;
        cout<<"\nFaculty E-Mail ID     : "<<mail;
        cout<<"\nFaculty Subjects      : "<<totalsub;
        for(int i=0;i<totalsub;i++)
        {
            cout<<"\n     Subject "<<i+1<<" : "<<subject[i];
        }
        if(totalsub==0)
            cout<<"( None Subject Specified...) ";
    }
};
Admin a,f;
// a & f are the objects of class Admin
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int ch;
    cout<<"\n\n\n\t\t\tWelcome to DAV Database Portal ";
    cout<<"\n\n\n\t\t\tEnter to continue ";
    getch();
    cout<<"\n\n\n\t\tPress 1 for Admin Portal ";
    cout<<"\n\t\tPress 2 for Faculty Portal ";
    cout<<"\n\t\tPress 3 for Student Portal ";
    cout<<"\n\n\n\t\t\tEnter your Choice  ";
    cin>>ch;
    if(ch==1)
    {
        char adminusers[20],adminpass[20],p[20];
        cout<<"\n\t\t\tWelcome To Admin Login Portal ";
        cout<<"\n\nEnter the UserName : ";
        cin.ignore();
        cin.getline(adminusers,20);
        cout<<"\nEnter the password : ";
        int i;
        for(int i=0;i<8;i++)
        {
            p[i]=getch();
            cout<<"*";
        }
        getch();
        memset(adminpass, '\0', sizeof(adminpass));
        for(int i=0;i<8;i++)
        {
            adminpass[i]=p[i];
        }
        
        if((strcmp(adminusers,"admin")==0)&&(strcmp(adminpass,"password")==0))
        {
    
        }
        else
        {
            cout<<"\n\n\t\t\t Invalid Access to portal ";
            cout<<"\n\n\t\t\tSorry !!!";
            getch();
            exit(0);
        }
        
    
        char opera ='y';
        do
        {
            int temp;
            cout<<"\n\t\t\tWelcome To Admin Panel ";
            cout<<"\nPress 1 to Add a Faculty Record ";
            cout<<"\nPress 2 to Add Multiple Record of Faculty ";
            cout<<"\nPress 3 to View All Records of  Faculty ";
            cout<<"\nPress 4 to Delete a Faculty Record ";
            cout<<"\nPress 5 to Add a Student Record ";
            cout<<"\nPress 6 to Add Multiple Record of Students";
            cout<<"\nPress 7 to View All Records of  Students ";
            cout<<"\nPress 8 to Delete a Student Record ";
            cout<<"\nPress 9 tp Exit. ";
            cout<<"\n\n\tEnter Your Choice : ";
            cin>>temp;
            cin.clear();
            cin.ignore();
            if(temp==1)//for inserting single facuilty record
            {
                cout<<"\nEnter the Details :";
                fstream fs;
                fs.open("faDAV.txt",ios::in|ios::out|ios::ate);
                a.getfadata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully..."; 
            }
            if(temp==2)//for inserting nultiple faculty records
            {
                int m=1;
                fstream fs;
                fs.open("faDAV.txt",ios::in|ios::out|ios::ate);
                do
                {
                    cout<<"\nEnter the Details : ";
                    a.getfadata();
                    fs.write((char*)&a,sizeof(Admin));
                    cout<<"\nPress 1 if you want to Enter More Records : ";
                    cin>>m;
                    cin.ignore();
                } while (m==1);
                fs.close();
                cout<<"\nRecord Entered Successfully...";
            }
            if(temp==3)//for view all faculty records
            {
                fstream fs;
                fs.open("faDAV.txt",ios::in);
                fs.seekg(0);
                while(fs.read((char*)&a,sizeof(Admin)))
                {
                    a.fadisplay();
                }
                fs.close();
            }
            if(temp==4)//for deleting a facuilty record
            {
                char tmpfaid[15];
                int de=0,result=-1;
                cout<<"\nEnter the Faculty ID/Rollno. :-";
                cin>>tmpfaid;
                fstream fs;
                fs.open("faDAV.txt",ios::in);
                fstream fs1;
                fs1.open("fatempDAV.txt",ios::out|ios::ate);
                while(fs.read((char*)&a,sizeof(Admin)))
                {
                    result=strcmp(tmpfaid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                    fs1.write((char*)&a,sizeof(Admin));
                }
                if(de==1)
                {
                    cout<<"\nRecord Delete Successfully....";
                }
                else
                {
                    cout<<"\nRecord not found.... ";
                }
                fs.close();
                fs1.close();
                remove("faDAV.txt");
                rename("fatempDAV.txt","faDAV.txt"); 
            }
            if(temp==5) //Adding single student data
            {
                cout<<"\nEnter the details :- ";
                fstream fs;
                fs.open("stDAV.txt",ios::in|ios::out|ios::ate);
                a.getstdata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully..."; 
            }
            if(temp==6)//for adding multiple student record
            {
                int m=1;
                fstream fs;
                fs.open("stDAV.txt",ios::in|ios::out|ios::ate);
                do
                {
                    cout<<"\nEnter the Details :- ";
                    a.getstdata();
                    fs.write((char*)&a,sizeof(Admin));
                    cout<<"\nPress 1 if you want to Enter More Records : ";
                    cin>>m;
                    cin.ignore();
                } while (m==1);
                fs.close();
                cout<<"\nRecord Entered Successfully...";
            }
            if(temp==7) //For view all records of student
            {
                fstream fs;
                fs.open("stDAV.txt",ios::in);
                fs.seekg(0);
                while(fs.read((char*)&a,sizeof(Admin)))
                {
                    a.stdisplay();
                }
                fs.close();
            }
            if(temp==8)  //Deleting student record
            {
                char tmpstid[15];
                int de=0,result=-1;
                cout<<"\nEnter the Student ID/Rollno. :-";
                cin>>tmpstid;
                fstream fs;
                fs.open("stDAV.txt",ios::in);
                fstream fs1;
                fs1.open("sttempDAV.txt",ios::out|ios::ate);
                while(fs.read((char*)&a,sizeof(Admin)))
                {
                    result=strcmp(tmpstid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                    fs1.write((char*)&a,sizeof(Admin));
                }
                if(de==1)
                {
                    cout<<"\nRecord Delete Successfully....";
                }
                else
                {
                    cout<<"\nRecord not found.... ";
                }
                fs.close();
                fs1.close();
                remove("stDAV.txt");
                rename("sttempDAV.txt","stDAV.txt"); 
            }
            if(temp==9) //for exit
            {
                cout<<"\n\n\n\n\t\t\t\tThank You !!!";
                getch();
                exit(0);
            }
            if(temp<1||temp>9)  // for invalid input amoung choice of operation
            {
        
                cout<<"\n\n\n\t\t\tInvalid Input.....";
            }
            getch();
            cout<<"\n\nPress Y or y ; for More Operations otherwise n or N : ";
            cin>>opera;
             if(opera!='y'||opera!='Y')
            {
                if(opera!='n'||opera!='N')
                  cout<<"Invalid Input\n";
                cout<<"\n\n\n\n\n\t\t\t\tThank You !!!";
                getch();
            }
        } while (opera=='y'||opera=='Y'); 
    }
    if(ch==2) //being Faculty View Portal
    {

        int val,s=0;
        cout<<"\n\t\t\tWelcome to Faculty Login Page";
        cout<<"\n\nEnter the UserName : ";
        cin>>::un;
        fstream fs;
        fs.open("faDAV.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(fs.read((char*)&f,sizeof(Admin)))
        {
            val=-1;
            val=f.login();
            if(val==1)
            {
                s=1;
                break;
            }
        }
        fs.close();
        if(s==1) //if first login is valid
        {
    
        }
        if(s!=1)  //if first login is invalid
        {
    
            int ho=0;
            cout<<"\n\n\t\tYour Login Credentials are In-Correct";
            cout<<"\nThe UserName is Your ID/Rollno.";
            cout<<"\nThe Password is Case-Sensitive.";
            cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
            cout<<"\nEnter the Choice : ";
            cin>>ho;
            if(ho==1)//recover password
            {
                cout<<"Enter The UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("faDAV.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    re=-1;
                    re=f.recover();
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1)
                {
                    getch();
            
                    cout<<"\n\n\n\n\t\t\tThank You !!!";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are Invalid User.";
                    getch();
                    exit(0);
                }
                
            }
            if(ho==2)  //re-attempt of login
            {
                cout<<"\n\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("faDAV.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1,valu;  //valu for storing login() return value suc for success login
                 while(fs.read((char*)&f,sizeof(Admin)))
                {
                    valu=-1;
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                if(suc==1)
                {
            
                }
                else
                {
                    getch();
                    cout<<"\nYou are Invalid User....";
                    cout<<"\n\n\n\n\t\t\tThank You !!!";
                    getch();
                    exit(0);
                }
                
            }
            if(ho!=1&&ho!=2)
            {
                cout<<"\nInvalid Input!!!";
                cout<<"\n\n\n\n\t\t\tThank You !!!";
                getch();
                exit(0);
            }
        } //CLOSING of first invalif login(forget password & recover password being)
        //Being of Faculty
        char con ='y';
        do
        {
    
            cout<<"\n\n\t\t\tWelcome to Faculty Panel ";
            cout<<"\n\n\t\t\t\t\t\t   Your UserId is : "<<::un;
            cout<<"\n\nPress 1 to view Your Profile. ";
            cout<<"\nPress 2 to know Your Subjects. ";
            cout<<"\nPress 3 to Add a Subject. ";
            cout<<"\nPress 4 to delete a subject. ";
            cout<<"\nPress 5 to modifiy Your Profile.";
            int choice;
            cout<<"\nEnter Your Choice : ";
            cin>>choice;
            cin.clear();
            cin.ignore();
            if(choice==1) //View of faculty profile
            {
                fstream fs;
                fs.open("faDAV.txt",ios::in);
                fs.seekg(0);
                int x;
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    x=0;
                    x=f.faprofile();
                    if(x==1)
                        break;
                }
                fs.close();
            }//closing  of choic 1
            if(choice==2)  //Knowing subject
            {
                fstream fs;
                fs.open("faDAV.txt",ios::in);
                fs.seekg(0);
                int y;
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    y=0;
                    y=f.knowfasub();
                    if(y==1)
                        break;
                }
                fs.close();
            } //closing choice 2
            if(choice==3)
            {
                fstream fs1,fs;
                fs.open("faDAV.txt",ios::in|ios::binary);
                fs1.open("fatempDAV.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    f.addfasub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("faDAV.txt");
                rename("fatempDAV.txt","faDAV.txt");
            }//closing of choice 3
            if(choice==4) //Deleting  a subject
            {
                fstream fs,fs1;
                fs.open("faDAV.txt",ios::in|ios::binary);
                fs1.open("fatempDAV.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    f.delfasub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("faDAV.txt");
                rename("fatempDAV.txt","faDAV.txt");
            } //closing of choice 4
            if(choice==5) //to modifie profile
            {
                fstream fs,fs1;
                fs.open("faDAV.txt",ios::in|ios::binary);
                fs1.open("fatempDAV.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    f.modfaprofile();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("faDAV.txt");
                rename("fatempDAV,txt","faDAV.txt");
            }
            if(choice<1||choice>5)  // for invalid input amoung choice of operation
            {
        
                cout<<"\n\t\tInvalid Input Provided!!! ";
            }
            getch();
            cout<<"\n\nPress Y or y ; for More Operations otherwise n or N : ";
            cin>>con;
            if(con!='y'&&con!='Y')
            {
                if(con!='n'&&con!='N')
                  cout<<"Invalid Input\n";
                cout<<"\n\n\n\n\n\t\t\t\tThank You !!!";
                getch();
            }
        } while (con=='y'||con=='Y');
    }//closing of facuilty view
    if(ch==3)//beh=gin of student view
    {

        //char un[20];
        int value,s1=0;
        cout<<"\n\t\t\tWelcome to Student Login Page";
        cout<<"\nEnter the Username";
        cin>>::un;
        fstream fs;
        fs.open("stDAV.txt",ios::in|ios::binary);
        while(fs.read((char*)&f,sizeof(Admin)))
        {
            value=-1;
            value=f.login();
            if(value==1)
            {
                s1=1;
                break;
            }
        }
        fs.close();
        if(s1==1) //if first login is valid
        {
    
            //cout<<"\n\n\t\t\tWelcome to Student Page ";
        }
        if(s1!=1)  //if first login is invalid
        {
    
            int sho=0;
            cout<<"\n\n\t\tYour Login Credentials are In-Correct";
            cout<<"\nThe UserName is Your ID/Rollno.";
            cout<<"\nThe Password is Case-Sensitive.";
            cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
            cout<<"\nEnter the Choice : ";
            cin>>sho;
            cin.clear();
            cin.ignore();
            if(sho==1)//recover password
            {
                cout<<"Enter The UserName : -";
                cin>>::un;
                fstream fs;
                fs.open("stDAV.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    re=-1;
                    re=f.recover();
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1)
                {
                    getch();
            
                    cout<<"\n\n\n\n\t\t\tThank You !!!";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are Invalid User.";
                    getch();
                    exit(0);
                }
                
            }//recover password end
            if(sho==2)  //re-attempt of login
            {
                cout<<"\n\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("stDAV.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1,valu;  //valu for storing login() return value suc for success login
                 while(fs.read((char*)&f,sizeof(Admin)))
                {
                    valu=-1;
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                if(suc==1)
                {
            
                }
                else
                {
                    getch();
                    cout<<"\nYou are Invalid User....";
                    cout<<"\n\n\n\n\t\t\tThank You !!!";
                    getch();
                    exit(0);
                }
                
            }
            if(sho!=1&&sho!=2)
            {
                cout<<"\nInvalid Input !!!";
                cout<<"\n\n\n\n\t\t\tThank You !!!";
                getch();
                exit(0);
            }
        } //CLOSING of first invalid login(forget password & recover password being)
        //Being of Student Panel 
        char moreop ='y';
        do
        {
            cout<<"\n\n\t\t\tWelcome to Student Panel ";
            cout<<"\n\n\t\t\t\t\t\t   Your UserId is : "<<::un;
            cout<<"\n\nPress 1 to view Your Profile. ";
            cout<<"\nPress 2 to know Your Subjects. ";
            cout<<"\nPress 3 to Add a Subject. ";
            cout<<"\nPress 4 to delete a subject. ";
            cout<<"\nPress 5 to modifiy Your Profile.";
            int inchoice;
            cout<<"\nEnter Your Choice : ";
            cin>>inchoice;
            cin.clear();
            cin.ignore();
            if(inchoice==1) //View of faculty profile
            {
                fstream fs;
                fs.open("stDAV.txt",ios::in);
                fs.seekg(0);
                int x;
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    x=0;
                    x=f.stprofile();
                    if(x==1)
                        break;
                }
                fs.close();
            }//closing  of choic 1
            if(inchoice==2)  //Knowing subject
            {
                fstream fs;
                fs.open("stDAV.txt",ios::in);
                fs.seekg(0);
                int y;
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    y=0;
                    y=f.knowstsub();
                    if(y==1)
                        break;
                }
                fs.close();
            } //closing choice 2
            if(inchoice==3)
            {
                fstream fs1,fs;
                fs.open("stDAV.txt",ios::in|ios::binary);
                fs1.open("sttempDAV.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    f.addstsub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stDAV.txt");
                rename("sttempDAV.txt","stDAV.txt");
            }//closing of choice 3
            if(inchoice==4) //Deleting  a subject
            {
                fstream fs,fs1;
                fs.open("stDAV.txt",ios::in|ios::binary);
                fs1.open("sttempDAV.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    f.delstsub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stDAV.txt");
                rename("sttempDAV.txt","stDAV.txt");
            } //closing of choice 4
            if(inchoice==5)
            {
                fstream fs,fs1;
                fs.open("stDAV.txt",ios::in|ios::binary);
                fs1.open("sttempDAV.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(fs.read((char*)&f,sizeof(Admin)))
                {
                    f.modstprofile();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stDAV.txt");
                rename("sttempDAV.txt","stDAV.txt");
            }
            if(inchoice<1||inchoice>5)  // for invalid input amoung choice of operation
            {
        
                cout<<"\n\t\tInvalid Input Provided!!! ";
            }
            getch();
            cout<<"\n\nPress Y or y ; for More Operations otherwise n or N: ";
            cin>>moreop;
            if(moreop!='y'&&moreop!='Y')
            {
                if(moreop!='n'&&moreop!='N')
                  cout<<"Invalid Input\n";
                cout<<"\n\n\n\n\n\t\t\t\tThank You !!!";
                getch();
            }
        } while (moreop=='y'||moreop=='Y');
    }//closing of student view
    if(ch<1||ch>3)
    {
        cout<<"\nInvalid Input Provided !!! ";
        getch();

        cout<<"\n\n\n\t\t\tThank You";
    }
    return 0;
}