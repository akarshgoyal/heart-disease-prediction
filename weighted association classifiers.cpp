#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<process.h>


using namespace std;



int main()
{
    //Generating a random data-base for records of 5 patients
   int rec[10][4];
   int i, j,x=1, y;
   srand(time(NULL));
   int r;

   for(i=0;i<=9;i++)
   {
       for(j=0;j<=3;j++)
       {

           r=rand();
           rec[i][j]=r%2;
       }
   }

   int flag=1;
   int t=0;




   for(i=0;i<=9;i++)
   {
       //cout<<"\ncheck for patient no.:"<<i;
       flag=1;
       while(flag==1)
      {

        for(j=0;j<=3;j++)
       {
            t=t+rec[i][j];
       }

        if(t==0)
        {
            //cout<<"\nif condition satisfied for patient:"<<i;
            for(j=0; j<=3; j++)
            {
                r=rand();
                rec[i][j]=r%2;
            }
        }

        else
        {
            //cout<<"\nelse condition satisfied for patient:"<<i<<"\n\n";
            flag=0;
        }
      }
      t=0;
   }


   //Printing the data-base
   cout<<"\t\t\t\tHOSPITAL DATA\n\n\n";
   cout<<"\t\tSmoking\t\tDrinking\tHyper-tension\tHeart-patient";
   cout<<"\t\t\t-------------------------------------------------------------";
   for(i=0; i<=9; i++)
   {
       cout<<"\n\n";
       cout<<"PATIENT "<<i<<"\t";
       for(j=0; j<=3; j++)
       {
           if(rec[i][j]==1)
            cout<<"yes";

           else
            cout<<"no";
           //cout<<rec[i][j];
           cout<<"\t\t";
       }
   }

   //Printing weights of each attribute and record weights


   float w[4], w_r[10], w_r_n[10]={0,0,0,0,0,0,0,0,0,0}, w_r_d[10]={0,0,0,0,0,0,0,0,0,0};

   t=0;

   w[0]=0.3; //weight of smoking
   w[1]=0.5; //weight of drinking
   w[2]=0.7; //weight of hyper-tension
   w[3]=1;   //weight of heart-problem

   //Printing weight of the attributes

   cout<<"\n\nWEIGHTS OF THE ATTRIBUTES";
   cout<<"\nweight of smoking= "<<w[0];
   cout<<"\nweight of drinking= "<<w[1];
   cout<<"\nweight of hyper-tension= "<<w[2];
   cout<<"\nweight of heart-problem= "<<w[3];

   //Generating record weights
   /*FORMULA
     record weight(w_r)=average of all the attributes shown by the patient
   */
   for(i=0; i<=9; i++)
   {
       for(j=0; j<=3; j++)
       {
           w_r_n[i]=w_r_n[i]+rec[i][j]*w[j];
           w_r_d[i]=w_r_d[i]+rec[i][j];

       }
       w_r[i]=w_r_n[i]/w_r_d[i];
   }

   cout<<"\n\n\n\n\n";

   //Printing record weights
   cout<<"RECORD WEIGHTS\n\n";

    for(i=0; i<=9; i++)
       {
           cout<<"PATIENT "<<i<<":  ";
           cout<<w_r[i];
           cout<<"\n";
       }

     //Total weight

     float total_w=0;
     for(i=0; i<=9; i++)
     {
         total_w=total_w+w_r[i];
     }

     cout<<"\n\n\nTOTAL WEIGHT = "<<total_w;

    //Weighted Support

    float w_s[4], w_s_n[4]={0,0,0,0};

    for(i=0;i<=3;i++)
    {
         for(j=0; j<=4; j++)
         {
             w_s_n[i]=w_s_n[i]+(w_r[j]*rec[j][i]);
         }

         w_s[i]=w_s_n[i]/total_w;
    }

   cout<<"\n\n\n\n";
   cout<<"WEIGHTED SUPPORT WSP\n\n";

   string wsp_attr[4]={"WSP(smoking)", "WSP(drinking)", "WSP(hyper-tension)", "WSP(heart patient)"};

    for(i=0; i<=3; i++)
       {
           cout<<wsp_attr[i]<<": ";
           cout<<w_s[i];
           cout<<"\n";
       }



    /////////////////////////////////////////////////////////
    float age, smoking=0, drinking=0, ht=0;
    string name, sex, cp,po,pc;




    //Form
    cout<<"\n\n\n\nPlease fill the survey form\n\n\n."<<endl;
    cout<<"            ***SURVEY***\n";

    cout<<"\nNAME:";
    cin>>name;

     cout<<"\nAGE:";
    cin>>age;

    cout<<"\nSMOKING :";
    cin>>cp;

    cout<<"\nDRINKING :";
    cin>>pc;

    cout<<"\nHYPER-TENSION :";
    cin>>po;

    
    if((cp=="yes")&&(pc=="yes")&&(po=="yes"))
    {
         if((w_s[0]+w_s[1]+w_s[2])>0.3)
         {cout<<"You are a heart patient";
          exit(0);
         }
         else
         {cout<<"you are not a heart patient";
         exit(0);
         }
         }
	if((cp=="yes")&&(pc=="yes"))
    {
         if((w_s[0]+w_s[1])>0.3)
         {cout<<"You are a heart patient";
         exit(0);
         }
         else
         {cout<<"you are not a heart patient";
         exit(0);
         }
         }
         if((pc=="yes")&&(po=="yes"))
    {
         if((w_s[1]+w_s[2])>0.35)
         {cout<<"You are a heart patient";
         exit(0);
         }
         else
         {cout<<"you are not a heart patient";
         exit(0);
         }
         }
         if((cp=="yes")&&(po=="yes"))
    {
         if((w_s[0]+w_s[2])>0.3)
         {cout<<"You are a heart patient";
         exit(0);
         }
         else
         {cout<<"you are not a heart patient";
         exit(0);
         }
         }
         
	if(cp=="yes")
    {
         if(w_s[0]>0.3)
         {cout<<"You are a heart patient";
         exit(0);
         }
         else
         {cout<<"you are not a heart patient";
         exit(0);
         }
         }
     if(pc=="yes")
    {
     if(w_s[1]>0.35)
         {cout<<"You are a heart patient";
         exit(0);
         }
		 else
         {cout<<"you are not a heart patient";
         exit(0);
         }    
         
    }
    if(po=="yes")
    {
       if(w_s[2]>0.4)
         {cout<<"You are a heart patient";
         exit(0);
         }
		 else
         {cout<<"you are not a heart patient";
         exit(0);
         }   
    }
    else
    {cout<<"you are not a heart patient";
         exit(0);
    }   
    
    

    getch();
}
