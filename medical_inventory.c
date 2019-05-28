#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int id;
char name[30];
}SUPPLIER;

SUPPLIER s[30];
int sid=5;


typedef struct{
int id;
char name[30];
char cond[30];
char doc[30];
char med[100];
}CUSTOMER;


CUSTOMER c[100];
int cid=4;


typedef struct{
int id;
char name[30];
char mfg[10];
char exp[10];
float rate;
int qty;
}INVENTORY;

INVENTORY i[100];
int iid=10;

typedef struct{
int id;
int medid;
char name[30];
int qty;
float rate;
}CART;
CART cart[100];
int cartid=0;

void old_supplier(void);
void new_supplier(void);
void cust_rep(void);
void show_cust(void);
void inv_med(void);
void list_med(void);
void add_cart(int,int,char st[30],float,int);
void add_cust_med(char st[20],int);
void show_cart(void);


int main()
{
c[0].id=1;strcpy(c[0].name,"Vivek Hiremath");strcpy(c[0].cond,"Anxiety");strcpy(c[0].doc,"DR. Rajiv Patil");strcpy(c[0].med,"Avil,Levo Citrizine");
c[1].id=2;strcpy(c[1].name,"Nathan McGonall");strcpy(c[1].cond,"Glucoma");strcpy(c[1].doc,"DR. Ahmed Ansari");strcpy(c[1].med,"Norflox TZ");
c[2].id=3;strcpy(c[2].name,"Risabh Singh");strcpy(c[2].cond,"Diabetes");strcpy(c[2].doc,"DR. Ritesh Gupta");strcpy(c[2].med,"Mesospasm");
c[3].id=4;strcpy(c[3].name,"Aaron Paul");strcpy(c[3].cond,"High Blood Pressure");strcpy(c[3].doc,"DR. Sameer Jhadav");strcpy(c[3].med,"Mycobalmin");




s[0].id=1;strcpy(s[0].name,"Siddaram Sambhoji");
s[1].id=2;strcpy(s[1].name,"Rakesh Sinha");
s[2].id=3;strcpy(s[2].name,"Rajeev Singh");
s[3].id=4;strcpy(s[3].name,"Umesh Badnur");
s[4].id=5;strcpy(s[4].name,"Rishikesh Raj");


i[0].id=1;strcpy(i[0].name,"Levo Citrizine");strcpy(i[0].mfg,"10-05-2017");strcpy(i[0].exp,"10-05-2018");i[0].rate=30;i[0].qty=10;
i[1].id=2;strcpy(i[1].name,"Avil");strcpy(i[1].mfg,"10-05-2017");strcpy(i[1].exp,"10-05-2019");i[1].rate=130;i[1].qty=10;
i[2].id=3;strcpy(i[2].name,"Norflox TZ");strcpy(i[2].mfg,"10-05-2017");strcpy(i[2].exp,"10-05-2019");i[2].rate=60;i[2].qty=10;
i[3].id=4;strcpy(i[3].name,"Meterogyl");strcpy(i[3].mfg,"10-05-2017");strcpy(i[3].exp,"10-05-2018");i[3].rate=20;i[3].qty=10;
i[4].id=5;strcpy(i[4].name,"Mesospasm");strcpy(i[4].mfg,"10-05-2017");strcpy(i[4].exp,"10-05-2018");i[4].rate=240;i[4].qty=10;
i[5].id=6;strcpy(i[5].name,"Mycobalmin");strcpy(i[5].mfg,"10-05-2017");strcpy(i[5].exp,"10-05-2019");i[5].rate=210;i[5].qty=10;
i[6].id=7;strcpy(i[6].name,"Paracetamol");strcpy(i[6].mfg,"10-05-2017");strcpy(i[6].exp,"10-05-2018");i[6].rate=50;i[6].qty=10;
i[7].id=8;strcpy(i[7].name,"Suxxi");strcpy(i[7].mfg,"10-05-2017");strcpy(i[7].exp,"10-05-2020");i[7].rate=195;i[7].qty=10;
i[8].id=9;strcpy(i[8].name,"Zevit");strcpy(i[8].mfg,"10-05-2017");strcpy(i[8].exp,"10-05-2019");i[8].rate=245;i[8].qty=10;
i[9].id=10;strcpy(i[9].name,"Calcimax");strcpy(i[9].mfg,"10-05-2017");strcpy(i[9].exp,"10-05-2019");i[9].rate=304;i[9].qty=10;



    int ch,ch1,ch2;
    jump:
    do{
    printf("----------------------Medical Store Inventory--------------------\n");
    printf("|                 1.Supplier End                                 |\n");
    printf("|                 2.Customer End                                 |\n");
    printf("|                 3.Exit                                         |\n");
    printf("-----------------------------------------------------------------\n");

    printf("Enter Your Selection : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("------------------Supplier End-----------------\n");
           printf("|               1.Old Supplier                 |\n");
           printf("|               2.New Supplier                 |\n");
           printf("|               3.Previous Menu                |\n");
           printf("------------------------------------------------\n");
           printf("Enter Your Selection : ");
           scanf("%d",&ch1);
           switch(ch1)
           {
           case 1:old_supplier();
            break;
           case 2:new_supplier();
            break;
           case 3:goto jump;
            break;
                default:printf("Enter a Valid Selection : ");
           }

        break;
    case 2:
           label1:
           printf("------------------Customer End-----------------\n");
           printf("|               1.Customer Report               |\n");
           printf("|               2.All Customers                |\n");
           printf("|               3.Buy Medicine                 |\n");
           printf("|               4.Previous Menu                |\n");
           printf("------------------------------------------------\n");
           printf("Enter Your Selection : ");
           scanf("%d",&ch2);
           switch(ch2)
           {
               case 1:cust_rep();
               break;
               case 2:show_cust();
               break;
               case 3:inv_med();
               break;
               case 4: goto jump;
               default:printf("Enter a Valid Selection : ");
           }
        break;
    case 3:exit(0);
    default:printf("Enter a Valid Selection : ");

    }
    }while(ch!=3);

}


void old_supplier()
{
    int n,m,x,j,y,k,flag=0,nw=0;
    float ry;float sum=0;
    printf("------------------Old Supplier's Log-----------------\n");
    printf("Enter The Supplier id: ");
    scanf("%d",&n);
    for(k=0;k<sid;k++)
    {
        if(n==s[k].id)
        {
    printf("Supplier ID : %d\n",s[n].id);
    printf("Supplier Name : %s\n",s[n].name);
    printf("Enter the number Of medicine to be added :");
    scanf("%d",&m);
    while(m--)
    {
        printf("Enter the Medicine id: ");
        scanf("%d",&x);
        for(j=0;j<iid;j++)
        {
            if(x==i[j].id)
            {
                printf("Name: %s\n",i[j].name);
                printf("Enter Quantity: ");
                scanf("%d",&y);
                i[j].qty+=y;
                sum+=y*i[j].rate;
                flag++;
                nw++;
                break;
            }
        }

            if(nw!=m){
                for(;nw<=m;nw++)
            {
                i[j].id=++iid;
                printf("Enter Name : ");
                scanf("%s",i[j].name);
                printf("Enter Quantity: ");
                scanf("%d",&y);
                i[j].qty=y;
                printf("Enter Rate: ");
                scanf("%f",&ry);
                i[j].rate=ry;
                printf("Enter MFG Date(dd-mm-yyy) :   ");
                scanf("%s",i[j].mfg);
                printf("Enter EXP Date(dd-mm-yyy) :   ");
                scanf("%s",i[j].exp);
                sum+=y*ry;
                flag++;


            }}



    }
    printf("//-----Inventory Updated-----\\");
    printf("\nBill Amount For Supplier Id:%d = %.2f\n",n,sum);
        }
    }if(flag==0)
       printf("Enter Valid Supplier ID");


}


void new_supplier()
{
    int c=sid,m,x,y,j,nw;
    float ry,sum=0;
    printf("New Supplier id= %d",sid);
    s[c].id=++sid;
    printf("\nNew Supplier name=");
     scanf("%s",s[c].name);

    printf("\nEnter the number Of medicine to be added :");
    scanf("%d",&m);
    while(m--)
    {
        printf("\nEnter the Medicine id: ");
        scanf("%d",&x);
        for(j=0;j<100;j++)
        {
            if(x==i[j].id)
            {
                printf("\nName: %s",i[j].name);
                printf("\nEnter Quantity: ");
                scanf("%d",&y);
                i[j].qty+=y;
                sum+=y*i[j].rate;
                nw++;
            }
        }
             if(nw!=m){
                for(;nw<=m;nw++)
            {
                i[j].id=x;
                printf("\mEnter Name : ");
                scanf("%s",i[j].name);
                printf("Enter Quantity:");
                scanf("%d",&y);
                i[j].qty=y;
                printf("Enter Rate: ");
                scanf("%f",&ry);
                i[j].rate=ry;
                printf("Enter MFG Date(dd-mm-yyy) :  ");
                scanf("%s",i[j].mfg);
                printf("Enter EXP Date(dd-mm-yyy) :   ");
                scanf("%s",i[j].exp);
                sum+=y*ry;
                nw++;
            }
             }

    }
        printf("\n//-----Inventory Updated-----\\");
    printf("\nBill Amount For Supplier Id:%d = Rs.%.2f/-\n\n",sid,sum);

}


void cust_rep()
{
    int j,n,flag=0;
    printf("Enter the Customer Id: ");
    scanf("%d",&n);
    for(j=0;j<100;j++)
    {
        if(c[j].id==n)
        {
            printf("\n-----------------Customer Report----------------\n");
            printf("Customer ID : %d\n",c[j].id);
            printf("Customer Name : %s\n",c[j].name);
            printf("Customer's Condition : %s\n",c[j].cond);
            printf("Customer's Doctor : %s\n",c[j].doc);
            printf("All Medicine Purchased : %s\n",c[j].med);
            printf("-----------------Customer Report----------------\n\n");
            flag++;
        }
    }
    if(flag==0)
    {
        printf("Invalid Customer ID. Customer Not Found \n");
    }
}


void show_cust()
{
    int j;int ch;
    for(j=0;j<cid;j++)
    {
        printf("Customer ID  \t  Customer Name \n");
        printf("    %d               %s    \t\n",c[j].id,c[j].name);

    }
    printf("Options avail:\n");
    printf("1. Check Customer Report \n");
    printf("2. Bill Medicine to Customer \n");
    printf("3. Go Back\n");
    printf("Enter Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:cust_rep();
        break;
        case 2: inv_med();
        break;
        case 3:
        break;
        default: printf("Choose Correct Option \n");
    }


}


void inv_med()
{
    int ch,ch1,n,j=0,x,r,m,flag=0,w,del,temp,temp2;
    float amt=0,amt1=0;
    char st[30];

    printf("----------------Welcome To XYZ Medicine Store-----------------\n");
    printf("|                      1.Medicine Shop                        |\n");
    printf("|                      2.Exit                                 |\n");
    printf("--------------------------------------------------------------\n\n");
    printf("Enter Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        do{
        printf("\n--------------Medicine Shop-----------\n");
        printf("|           1.Show Medicines         |\n");
        printf("|           2.Buy Medicines          |\n");
        printf("|           3.Show Cart              |\n");
        printf("|           4.Delete From Cart       |\n");
        printf("|           5.CheckOut               |\n");
        printf("|           6.Exit                   |\n");
        printf("--------------------------------------\n\n");
        printf("Enter Choice: ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:list_med();
                   break;
            case 2:x=0;
                   printf("\nEnter the Medicine ID: ");
                   scanf("%d",&n);
                   for(j=0;j<100;j++)
                   {
                       if(i[j].id==n)
                       {
                           printf("Medicine Name :%s\n",i[j].name);
                           printf("Medicine rate :%.2f\n",i[j].rate);
                           printf("Enter The Quantity to be purchased: ");
                           scanf("%d",&x);
                           r=i[j].rate;
                           strcpy(st,i[j].name);
                           add_cart(cartid,n,st,r,x);
                           cartid++;
                           i[j].qty-=x;

                           break;
                        }
                   }break;
            case 3:
                   printf("\nThe Medicine Shop Shopping Cart\n");
                   printf("Cart id\tMedicine Id\tName\tQuantity\tRate\tamount\n ");
                   for(j=0;j<cartid;j++)
                   {
                       amt1=(cart[j].qty*cart[j].rate);
                       printf("     %d\t   %d\t     %s\t    %d\t    %.2f\t    %.2f \n",cart[j].id,cart[j].medid,cart[j].name,cart[j].qty,cart[j].rate,amt1);
                       amt+=amt+(cart[j].qty*cart[j].rate);

                   }
                   break;
            case 4:

                   printf("\n Delete From Cart:");
                   show_cart();
                   printf("\nPlease Enter an CARTID from cart to Delete:  " );
                   scanf("%d",&del);
                  for(j=0;j<=cartid;j++)
                   {
                       if(del==j)
                       {
                           temp2=del+1;
                           temp=del;
                           for(;temp<=cartid;temp++)
                           {

                           cart[temp2].id=cart[temp].id;
                           cart[temp].medid=cart[temp2].medid;
                           strcpy(cart[temp].name,cart[temp2].name);
                           cart[temp].qty=cart[temp2].qty;
                           cart[temp].rate=cart[temp2].rate;
                           temp2++;

                           }

                       }
                   }
                   cartid--;
                   break;
            case 5:

                   printf("\n-----------Billing-------------\n");
                   printf("Enter Customer Id: ");
                   scanf("%d",&m);
                   for(j=0;j<cid;j++)
                   {
                       if(m==c[j].id)
                       {
                   printf("Customer Name: %s\n",c[j].name);
                   printf("Customer Condition: %s\n",c[j].cond);
                   printf("Customer's Doctor: %s\n",c[j].doc);
                        flag++;
                       }
                   }
                   if(flag==0)
                   {
                    w=cid;
                    ++cid;

                   printf("Enter New Customer:");
                   gets(c[w].name);
                   gets(c[w].name);
                   printf("Enter Customer Condition:");
                   gets(c[w].cond);
                   printf("Enter Customer's Doctor:");
                   gets(c[w].doc);
                   c[w].id=cid;
                   printf("Customer ID: %d\n",c[w].id);
                   printf("Customer Name: %s\n",c[w].name);
                   printf("Customer Condition: %s\n",c[w].cond);
                   printf("Customer's Doctor: %s\n",c[w].doc);
                   }

                   amt+=(amt*18)/100;
                   printf("The Total Amount = %.2f\n",amt);
                   printf("Thanks for Coming.. Get Well Soon\n\n");

            case 6: exit(0);
               break;
        }
        }while(ch1!=5);
        break;
    case 2:exit(0);
        break;
        default:printf("Enter a Valid Choice: ");


    }


}

void list_med()
{
    int j;
    printf("-----------Inventory----------\n");
    printf("The Available Medicines Are: \n");
    printf("\tID\tName\tQuantity\tRate\t\n");
    for(j=0;j<iid;j++)
    {
        printf("   %d   \t   %s   \t   %d   \t   %.2f   \t\n",i[j].id,i[j].name,i[j].qty,i[j].rate);

    }
}

void add_cart(int y,int n,char st[30],float r,int x)
{

        cart[y].id=y;;
        cart[y].medid=n;
        strcpy(cart[y].name,st);
        cart[y].rate=r;
        cart[y].qty=x;

}

void add_cust_med(char st[20],int x)
{   int j;
    for(j=0;j<100;j++)
    {
        if(x==c[j].id)
        strcpy(c[j].med,strcat(strcat(c[j].med,','),st));
    }
}

void show_cart()
{                  int j;float amt1;
                   printf("\nThe Medicine Shop Shopping Cart\n");
                   printf("CartID\tMedicine Id\tName\tQuantity\tRate\tamount\n ");
                   for(j=0;j<cartid;j++)
                   {
                       amt1=(cart[j].qty*cart[j].rate);
                       printf("     %d\t   %d\t     %s \t    %d\t    %.2f\t    %.2f \n",cart[j].id,cart[j].medid,cart[j].name,cart[j].qty,cart[j].rate,amt1);


                   }
}
