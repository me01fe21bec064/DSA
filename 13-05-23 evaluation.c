#include<stdio.h>
#include<stdlib.h>

FILE *fpa,*fpb,*fpc,*fpd,*fpe,*in;

int i,j,k;
main()
{
 int n,d,c,g;
 printf("enter the lenght of numbers\n");
 scanf("%d",&d);
 printf("enter range of numbers\n");
 scanf("%d",&n);
int s[100];
    fpa=fopen("rand.txt","w+");
    fpb=fopen("sta.txt","w+");
    fpc=fopen("pop.txt","w+");
    fpd=fopen("push.txt","w+");
    fpe=fopen("oper.txt","w+");
    int a[100];
    in=fpa;
    int top=i;
    for(i=0;i<d;i++)
    {
     a[i]=(rand()%(n+1));
     fprintf(fpa,"%d ",a[i]);
     printf("%d ",a[i]);
      printf("\n");
    }
    while(1)
    {
        printf("1-push\n");
        printf("2-pop\n");
        printf("3-completed\n");
        scanf("%d",&c);
        if(c==1) //push
        {

            if(k>d)
            {
                printf("stack is filled\n");

            }
            else
            {
                s[j]=a[k];
                fprintf(fpd,"%d ",a[k]);
                k++;
                j++;
                fprintf(fpe,"push " );

            }


        }
        else if(c==2)//pop
        {
            if(top==-1)
            {
                printf("stack is empty\n");
            }
            else
            {
               j--;
               fprintf(fpc,"%d ",s[j]);
               fprintf(fpe,"pop ");
            }

        }
        else if(c==3)
        {
            break;
        }
        else
        {
            printf("invalid\n");
        }

    }
     for(k=0;k<j;k++)
    {
     printf("%d ",s[k]);
     fprintf(fpb,"%d ",s[k]);
    }

    fclose(fpa);
    fclose(fpb);
    fclose(fpc);
    fclose(fpd);
    fclose(fpe);

}
