#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
using namespace std;
void encrypt()
{
    char c[]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','"',',','.','/',':','+','-',' ','_','(',')','!','@','#','$','%','^','&','*','\'','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    int y=0,n[]={3,1,4,7,6,1,4,12,7};
    string s,inputfile,outputfile;
    cout<<"\nenter a text file to encrypt : ";
    cin>>inputfile;
    inputfile+=".txt";
    ifstream MyReadFile(inputfile.c_str());
    cout<<"\nenter text file name to save the encrypted file : ";
    cin>>outputfile;
    outputfile+=".txt";
    ofstream MyWriteFile(outputfile.c_str());
    if(!MyReadFile)
        cout<<"\n* input file \"DOESN'T\" exist *\n";
    else
            {
                while (getline (MyReadFile, s))
                {

                   int i,j;
                   for(i=0;i<s.size();i++)
                   {
                       int p = 0;
                       for(j=0;j<72;j++)
                       {
                           if(s[i]==c[j])
                           {
                               if(y==9)
                                    y=0;
                               int x;
                               if(j+n[y]>71)
                               {
                                   x=j+n[y]-72;
                                   y++;
                               }
                               else
                               {
                                   x=j+n[y];
                                   y++;
                               }
                               MyWriteFile<<c[x];
                               p = 1;
                               break;
                           }
                        }
                        if(p == 0)
                        {
                            MyWriteFile<<s[i];
                        }
                    }
                    MyWriteFile<<"\n";
                }
            }
            MyReadFile.close();
            MyWriteFile.close();
}
void decrypt()
{
    char c[]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','"',',','.','/',':','+','-',' ','_','(',')','!','@','#','$','%','^','&','*','\'','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
   int y=0,n[]={3,1,4,7,6,1,4,12,7};
   string s,inputfile,outputfile;
   cout<<"enter text to decrypt : ";
   cin>>inputfile;
   inputfile+=".txt";
   ifstream MyReadFile(inputfile.c_str());
   cout<<"enter file to save decrypted text : ";
   cin>>outputfile;
   outputfile+=".txt";
   ofstream MyWriteFile(outputfile.c_str());
   int i,j;
   if(!MyReadFile)
   {
       cout<<"\n* input file \"DOESN'T\" exist *\n";
   }
   else
   {
       while(getline(MyReadFile,s))
   {
        for(i=0;i<s.size();i++)
        {
           int p=0;
           for(j=0;j<72;j++)
           {
                if(s[i]==c[j])
               {
                   if(y==9)
                        y=0;
                   int x;
                   if(j-n[y]<0)
                   {
                       x=72+j-n[y];
                       y++;
                   }
                   else
                   {
                       x=j-n[y];
                       y++;
                   }
                   MyWriteFile<<c[x];
                   p =1;
                   break;
               }
           }
           if (p == 0)
           {
               MyWriteFile<<s[i];
           }
       }
    MyWriteFile<<"\n";
   }

   }
   MyReadFile.close();
   MyWriteFile.close();
}
int main()
{
    int choice;
    while(1)
    {
        cout<<"NOTE:\"PLEASE DO NOT ENTER .TXT JUST ENTER NAME OF THE FILE\"\n";
        cout<<"1. Encrypt\n2. Decrypt\n3. Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        case 3:
            return 0;;
        }

    }
}
