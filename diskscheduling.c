#include<stdio.h>
int absolute(int a,int b)
    {int c;
     c=a-b;
     if(c<0)
            return -c;
     else
         return c;
         }


int main()
  {
    int choice,m,n,x,start,i,j,pos,min,a[15],count,fcfs,sstf,scan,cscan,look;
    printf("\nEnter the number of cylinders :");
    scanf("%d",&m);
    printf("\nEnter the number of requests :");
    scanf("%d",&n);
    printf("\nEnter current position :");
    scanf("%d",&start);
    printf("\nEnter the request queue :");
    for(i=0;i<n;i++)
     {
      scanf("%d",&a[i]);
        if(a[i]>=m)
          {
            printf("\ninvalid input");
            scanf("%d",&a[i]);
          }
      }
     do
       {
        printf("\n\nDISK SCHEDULING ALGORITHMS\n1. FCFS\n2. SSTF\n3. SCAN\n4. C-SCAN\n5. LOOK\n6.COMPARE");
        printf("\nEnter choice :");
        scanf("%d",&choice);
        count=0;
        x=start;
        switch(choice)
          {
            case 1:printf("\nFCFS :\n");
              printf("Scheduling services the request in the order that follows:\n%d\t",start);
                for(i=0;i<n;i++)
                  {
                    x-=a[i];
                    if(x<0)
                    x=-x;
                    count+=x;
                    x=a[i];
                    printf("%d\t",x);
                  }
                  printf("\nTotal Head Movement :%d Cylinders",count);
                  break;
            case 2:printf("\nSSTF :\n");
              printf("Scheduling services the request in the order that follows:\n%d\t",start);
                for(i=0;i<n;i++)
                  {
                    min=absolute(a[i],x);
                    pos=i;
                    for(j=i;j<n;j++)
                      if(min>absolute(x,a[j]))
                        {
                          pos=j;
                          min=absolute(x,a[j]);
                        }
                          count+=absolute(x,a[pos]);
                          x=a[pos];
                          a[pos]=a[i];
                          a[i]=x;
                          printf("%d\t",x);
                          }
                  printf("\nTotal Head Movement: %d Cylinders",count);
                  break;
            case 3:printf("\nSCAN :\n");
                  printf("Scheduling services the request in the order that follows:\n");
                  count=0;
                  pos=0;
                  for(i=0;i<n;i++)
                    for(j=0;j<n-i-1;j++)
                      if(a[j]>a[j+1])
                        {
                          x=a[j];
                          a[j]=a[j+1];
                          a[j+1]=x;
                        }
                      for(i=0;i<n;i++)
                        if(a[i]<start)
                          pos++;
                            for(i=0;i<pos;i++)
                                for(j=0;j<pos-i-1;j++)
                                    if(a[j]<a[j+1])
                                      {
                                        x=a[j];
                                        a[j]=a[j+1];
                                        a[j+1]=x;
                                      }
                              x=start;
                              printf("%d\t",x);
                              for(i=0;i<pos;i++)
                                                {count+=absolute(a[i],x);
                                                 x=a[i];
                                                 printf("%d\t",x);
                                                 }
                              count+=absolute(x,0);
                              x=0;
                              printf("%d\t",x);
                              for(i=pos;i<n;i++)
                                                {count+=absolute(a[i],x);
                                                 x=a[i];
                                                 printf("%d\t",x);
                                                 }
                              /*for(i=0;i<n;i++)
                                              printf("%d\t",a[i]);*/
                              printf("\nTotal Head Movement: %d Cylinders",count);
                              break;              
            case 4: printf("\nC-SCAN :\n");
                    printf("Scheduling Services the request in the order that follows:\n%d\t",start);
                    count=0;
                    pos=0;
                    for(i=0;i<n;i++)
                      for(j=0;j<n-i-1;j++)
                        if(a[j]>a[j+1])
                         {
                           x=a[j];
                           a[j]=a[j+1];
                           a[j+1]=x;
                         }
                    for(i=0;i<n;i++)
                       if(a[i]<start)
                        pos++;
                    x=start;
                    for(i=pos;i<n;i++)
                     {
                       count+=absolute(x,a[i]);
                       x=a[i];
                       printf("%d\t",x);
                     }
                    count+=absolute(m-1,x);
                    x=0;
                    printf("%d\t%d\t",m-1,0);
                    for(i=0;i<pos;i++)
                     {
                       count+=absolute(x,a[i]);
                       x=a[i];
                       printf("%d\t",x);
                     }
                    printf("\nTotal Head movement: %d Cylinders",count);
                    break;                                 
            case 5: printf("\nLOOK :\n");
                    printf("\nScheduling services the request in the order as follows :\n%d\t",start);
                    count=0;
                    pos=0;
                    for(i=0;i<n;i++)
                      for(j=0;j<n-i-1;j++)
                        if(a[j]>a[j+1])
                          {
                            x=a[j];
                            a[j]=a[j+1];
                            a[j+1]=x;
                          }
                    for(i=0;i<n;i++)
                      if(a[i]<start)
                        pos++;
                    for(i=0;i<pos;i++)
                      for(j=0;j<pos-i-1;j++)
                        if(a[j]<a[j+1])
                          {
                            x=a[j];
                            a[j]=a[j+1];
                            a[j+1]=x;
                          }
                    x=start;
                    for(i=0;i<pos;i++)
                      {
                        count+=absolute(a[i],x);
                        x=a[i];
                        printf("%d\t",x);
                      }           
                    for(i=pos;i<n;i++)
                      {
                        count+=absolute(a[i],x);
                        x=a[i];
                        printf("%d\t",x);
                      }
                      printf("\nToal Head Movement: %d Cylinders",count);
                      break;
              case 6: printf("After comparison,\n");                  
              		  fcfs=0;
                      for(i=0;i<n;i++)// FCFS algorithm                
                    {
                      x-=a[i];
                      if(x<0)
                      x=-x;
                      count+=x;
                      x=a[i];
                    } 
                    fcfs=count;
                    sstf=0;
                    count=0;
                    for(i=0;i<n;i++)// SSTF algorithm
                    {
                    min=absolute(a[i],x);
                    pos=i;
                    for(j=i;j<n;j++)
                      if(min>absolute(x,a[j]))
                        {
                          pos=j;
                          min=absolute(x,a[j]);
                        }
                          count+=absolute(x,a[pos]);
                          x=a[pos];
                          a[pos]=a[i];
                          a[i]=x;
                        }
                        sstf=count;
                        scan=0;
                        count=0;  // SCAN algorithm
                      pos=0;
                      for(i=0;i<n;i++)
                      for(j=0;j<n-i-1;j++)
                      if(a[j]>a[j+1])
                        {
                          x=a[j];
                          a[j]=a[j+1];
                          a[j+1]=x;
                        }
                      for(i=0;i<n;i++)
                        if(a[i]<start)
                          pos++;
                            for(i=0;i<pos;i++)
                                for(j=0;j<pos-i-1;j++)
                                    if(a[j]<a[j+1])
                                      {
                                        x=a[j];
                                        a[j]=a[j+1];
                                        a[j+1]=x;
                                      }
                              x=start;
                              for(i=0;i<pos;i++)
                                {
                                  count+=absolute(a[i],x);
                                  x=a[i];
                                }
                              count+=absolute(x,0);
                              x=0;
                              for(i=pos;i<n;i++)
                                {
                                  count+=absolute(a[i],x);
                                  x=a[i];
                                }
                                scan=count;
                         cscan=0;
                         count=0;  // C-SCAN algorithm
                          pos=0;
                          for(i=0;i<n;i++)
                          for(j=0;j<n-i-1;j++)
                            if(a[j]>a[j+1])
                          {
                             x=a[j];
                             a[j]=a[j+1];
                             a[j+1]=x;
                          }
                    for(i=0;i<n;i++)
                       if(a[i]<start)
                        pos++;
                    x=start;
                    for(i=pos;i<n;i++)
                     {
                       count+=absolute(x,a[i]);
                       x=a[i];
                     }
                    count+=absolute(m-1,x);
                    x=0;
                    for(i=0;i<pos;i++)
                     {
                       count+=absolute(x,a[i]);
                       x=a[i];
                      }
                      cscan=count;
                    look=0;  
                    count=0; //LOOK algorithm
                    pos=0;
                    for(i=0;i<n;i++)
                      for(j=0;j<n-i-1;j++)
                        if(a[j]>a[j+1])
                          {
                            x=a[j];
                            a[j]=a[j+1];
                            a[j+1]=x;
                          }
                    for(i=0;i<n;i++)
                      if(a[i]<start)
                        pos++;
                    for(i=0;i<pos;i++)
                      for(j=0;j<pos-i-1;j++)
                        if(a[j]<a[j+1])
                          {
                            x=a[j];
                            a[j]=a[j+1];
                            a[j+1]=x;
                          }
                    x=start;
                    for(i=0;i<pos;i++)
                      {
                        count+=absolute(a[i],x);
                        x=a[i];
                      }           
                      for(i=pos;i<n;i++)
                      {
                        count+=absolute(a[i],x);
                        x=a[i];
                      }
                      look=count;
            if(fcfs==sstf && fcfs==scan && fcfs==cscan && fcfs==look)
            {
            	printf("Any of the algorithm will work all have the same head movements");
            }
            else if(fcfs==sstf && fcfs==scan && fcfs==cscan && fcfs<look)
            {
            	printf("FCFS SSTF SCAN and C-SCAN suits the best here with %d head movement",fcfs);
            }
            else if(fcfs==sstf && fcfs==scan && fcfs<cscan && fcfs<look)
            {
            	printf("FCFS SCAN and SSTF suits the best here with %d head movement",fcfs);
            }
            else if(fcfs==sstf && fcfs<scan && fcfs<cscan && fcfs<look)
            {
            	printf("FCFS SSTF suits the best here with %d head movement",fcfs);
            }
            else if (fcfs<sstf && fcfs<scan && fcfs<cscan && fcfs<look)
            {
                printf("FCFS is the best suited algorithm with %d head movement",fcfs);
            }
            else if(sstf==scan && sstf==cscan && sstf==look && sstf<fcfs)
            {
            	printf("SSTF SCAN C-SCAN and LOOK suits the best here with %d head movement",sstf);
            }
            else if(sstf==scan && sstf==cscan && sstf<look && sstf<fcfs)
            {
            	printf("SSTF SCAN and C-SCAN suits the best here with %d head movement",sstf);
            }
            else if(sstf==scan && sstf<cscan && sstf<look && sstf<fcfs)
            {
            	printf("SSTF and SCAN suits the best here with %d head movement",sstf);
            }
            else if (sstf<fcfs && sstf<scan && sstf<cscan && sstf<look)
            {
                printf("SSTF is the best suited algorithm with %d head movement",sstf);
            }
            else if(scan==cscan && scan==look && scan<fcfs && scan<sstf)
            {
            	printf("SCAN C-SCAN and LOOK suits the best here with %d head movement",scan);
            }
            else if(scan==cscan && scan<look && scan<fcfs && scan<sstf)
            {
            	printf("SCAN and C-SCAN suits the best here with %d head movement",scan);
            }
            else if (scan<sstf && scan<fcfs && scan<cscan && scan<look)
            {
                printf("SCAN is the best suited algorithm with %d head movement",scan);
            }
            else if(cscan==look && cscan<fcfs && cscan<sstf && cscan<scan)
            {
            	printf("C-SCAN and LOOK suits the best here with %d head movement",cscan);
            }
            else if (cscan<sstf && cscan<scan && cscan<fcfs && cscan<look)
            {
                printf("C-SCAN is the best suited algorithm with %d head movement",cscan);
            }
            else if (look<sstf && look<scan && look<cscan && look<fcfs)
            {
                printf("LOOK is the best suited algorithm with %d head movement",look);
            }
            break;
        }
        printf("\nDo you want to continue(1 to continue) :");
        scanf("%d",&choice);
        }while(choice==1);
     }                                

