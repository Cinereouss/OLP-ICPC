#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        fstream fin;
        string str1,str2;
        getline(fin,str1);
        getline(fin,str2);
        fin.close();
        char ch1[str1.size()+1];
        char ch2[str2.size()+1];
        strcpy(ch1,str1.c_str());
        strcpy(ch2,str2.c_str());
        long long i=0;
        char buffer[1000];
        while(i>=0)
        {
            itoa(i,buffer,2);
            char *s1,*s2,*s3,*s4;
            string str="0"+string(buffer);
            char c[str.size()+1];
            strcpy(c,str.c_str());
            s1=strstr(ch1,buffer);
            s2=strstr(ch2,buffer);
            s3=strstr(ch1,c);
            s4=strstr(ch2,c);
            if(s1==NULL && s2==NULL)
            {
                 cout<<buffer;
                 break;
            }
            else if(s3==NULL && s4==NULL)
            {
                 cout<<c;
                 break;
            }
            i++;
        }
        return 0;
    }
