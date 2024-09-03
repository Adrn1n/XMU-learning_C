#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    //int c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,t=0;
    for(int a=1; a<=1000; a++)
    {
        int c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,t=0;
        for(int b=1; b<a; b++)
        {
            //if(a%b==0)
            if(!(a%b))
            {
                t++;
                //if(c==0)
                if(!c)
                    c=b;
                //else if(d==0)
                else if(!d)
                    d=b;
                //else if(e==0)
                else if(!e)
                    e=b;
                //else if(f==0)
                else if(!f)
                    f=b;
                //else if(g==0)
                else if(!g)
                    g=b;
                //else if(h==0)
                else if(!h)
                    h=b;
                //else if(i==0)
                else if(!i)
                    i=b;
                //else if(j==0)
                else if(!j)
                    j=b;
                else
                    k=b;
            }
        }
        if(c+d+e+f+g+h+i+j+k==a)
        {
            printf("%d its factors are ",a);
            switch(t)
            {
            case 2:
                printf("%d,%d\n",c,d);
                break;
            case 3:
                printf("%d,%d,%d\n",c,d,e);
                break;
            case 4:
                printf("%d,%d,%d,%d\n",c,d,e,f);
                break;
            case 5:
                printf("%d,%d,%d,%d,%d\n",c,d,e,f,g);
                break;
            case 6:
                printf("%d,%d,%d,%d,%d,%d\n",c,d,e,f,g,h);
                break;
            case 7:
                printf("%d,%d,%d,%d,%d,%d,%d\n",c,d,e,f,g,h,i);
                break;
            case 8:
                printf("%d,%d,%d,%d,%d,%d,%d,%d\n",c,d,e,f,g,h,i,j);
                break;
            case 9:
                printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",c,d,e,f,g,h,i,j,k);
                break;
            }
        }
        //c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,t=0;
    }
    */
    for(int n=1; n<=1000; n++)
    {
        int s=0;
        for(int a=1; a<n; a++)
        {
            if(!(n%a))
                s+=a;
        }
        if(n==s)
        {
            printf("%d its factors are 1",n);
            for(int a=2; a<n; a++)
            {
                if(!(n%a))
                    printf(",%d",a);
            }
            printf("\n");
        }
    }
    return 0;
}
