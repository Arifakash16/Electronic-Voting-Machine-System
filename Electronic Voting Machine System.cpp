#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <cstdlib>

void welcome();
int user();
void admin_Activity();
void adminPasswordCheaker();
void voter_Activity();
void national_parliament_election();
void zilla_parishad_Election();
void upozilla_parishad_Election();
void union_parishad_Election();
int choice();
void voterlist();
int countvoterlist();


/// National parliament Election needed function prototype
void npesetcandidate();
void npeDisplayCandidate();
void npeDeleteCandidate();
void npeobtainedvote();
void npetotalcastingvote(int n);
int  npecompletedvote(int n);
void npeDeletevoter();

/// Zilla Election needed function prototype

void zillasetcandidate();
void zillaDisplayCandidate();
void zillaDeleteCandidate();
void zillaobtainedvote();
void zillatotalcastingvote(int n);
int zillacompletedvote(int n);
void zillaDeletevoter();

/// Upozilla Election needed function prototype

void upozillasetcandidate();
void upozillaDisplayCandidate();
void upozillaDeleteCandidate();
void upozillaobtainedvote();
void upozillatotalcastingvote(int n);
int  upozillacompletedvote(int n);
void upozillaDeletevoter();

/// Union Election needed function prototype

void unionsetcandidate();
void unionDisplayCandidate();
void unionDeleteCandidate();
void unionobtainedvote();
void uniontotalcastingvote(int n);
int  unioncompletedvote(int n);
void unionDeletevoter();


int starting_voting_process();
int Input_NID();
int nidInvoterlist(char str[]);
int continuing_voting_process();
void typesofElection(int n);
void npegivenvote();
void npeDisplayvote();
void npeDeletevote();

void zillagivenvote();
void zillaDisplayvote();
void zillaDeletevote();

void upozillagivenvote();
void upozillaDisplayvote();
void upozillaDeletevote();

void uniongivenvote();
void unionDisplayvote();
void unionDeletevote();

int n,nid[20000][4],none_vote;


struct npeCandidate
{
    int a;
    char name[200];
    int votecount;
} ;

struct zillaCandidate
{
    int a;
    char name[200];
    int votecount;
};

struct upozillaCandidate
{
    int a;
    char name[200];
    int votecount;
};

struct unionCandidate
{
    int a;
    char name[200];
    int votecount;
};


int main()
{
    welcome();
arif:
    int cc = user();
    if(cc==1)
    {
        admin_Activity();
        goto arif;
    }
    else  if(cc==2)
    {
        voter_Activity();
        goto arif;
    }

    return 0;
}


void welcome()
{
    printf("\n\n***Welcome To Election Commision, Bangladesh***\n\n");
}

int user()
{
    printf("\nUSER\n1. Admin");
    printf("\n2. Voter");
    printf("\n3. Exit\n");
    int x;
    printf("\nEnter your choice: ");
    scanf("%d",&x);
    return x;

}

void admin_Activity()
{
    adminPasswordCheaker();
arif:
    printf("\n1. National Parliament Election");
    printf("\n2. Zilla Parishad Election");
    printf("\n3. Upozilla Parishad Election");
    printf("\n4. Union Parishad Election");
    printf("\n5. Main menu");
    printf("\n\nEnter your choice: ");
    int x;
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        national_parliament_election();
        goto arif;
        break;
    case 2:
        zilla_parishad_Election();
        goto arif;
        break;
    case 3:
        upozilla_parishad_Election();
        goto arif;
        break;
    case 4:
        union_parishad_Election();
        goto arif;
        break;
    default:
        break;

    }
}


void adminPasswordCheaker()
{

    while(1)
    {
        printf("\nEnter your password: ");
        int pass;
        scanf("%d",&pass);
        if(pass==19022)
            break;
        else
            printf("Wrong password!\n");
    }

}


/// National parliament  part

void national_parliament_election()
{

here:

    int x = choice();
    switch(x)
    {
    case 1:
        npesetcandidate();
        printf("\nBack to previous menu\nPress any key\n");
        char x;
        getchar();
        scanf("%c",&x);
        goto here;
    case 2:
        npeDisplayCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 3:
        npeDeleteCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 4:
        npeobtainedvote();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 5:
        npetotalcastingvote(1);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 6:
        npetotalcastingvote(2);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 7:
        voterlist();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    }
}

void npesetcandidate()
{
    struct npeCandidate *s;
    FILE *fp;
    fp = fopen("npeCandidate.txt","a");

    printf("How many candidate adding here: ");
    int n;
    scanf("%d",&n);
    s = (npeCandidate*)calloc(n,sizeof(npeCandidate));
    for(int i=0; i<n; i++)
    {
        if(i==0)
            printf("Enter the %dst candidate name: ",i+1);
        else if(i==1)
            printf("Enter the %dnd candidate name: ",i+1);
        else if(i==2)
            printf("Enter the %drd candidate name: ",i+1);
        else
            printf("Enter the %dth candidate name: ",i+1);

        getchar();
        scanf("%[^\n]s",&s[i].name);
        fwrite(&s[i],sizeof(npeCandidate),1,fp);

    }
    fclose(fp);
    //npeDisplayCandidate();
    //npeSearchCandidate();
    //npeDeleteCandidate();

}

void npeDisplayCandidate()
{
    struct npeCandidate s;
    FILE *fp;
    fp = fopen("npeCandidate.txt","r");
    int cnt=1;
    while(fread(&s,sizeof(npeCandidate),1,fp))
    {
        printf("%d. %s\n",cnt,s.name);
        cnt++;
    }
    fclose(fp);

}


void npeobtainedvote()
{
    struct npeCandidate s;
    FILE *fp;
    fp = fopen("npeCandidate.txt","r");
    int i=1;
    while(fread(&s,sizeof(npeCandidate),1,fp))
    {
        int cnt = 0;
        struct npeCandidate ss;
        FILE *fpp;
        fpp = fopen("npevotecount.txt","r");
        while(fread(&ss,sizeof(npeCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        printf("%s : %d\n",s.name,cnt);
        i++;

    }
    fclose(fp);
}

void npetotalcastingvote(int n)
{
    struct npeCandidate s;
    FILE *fp;
    fp = fopen("npeCandidate.txt","r");
    int i=1;
    int ans=0;
    while(fread(&s,sizeof(npeCandidate),1,fp))
    {
        struct npeCandidate ss;
        FILE *fpp;
        fpp = fopen("npevotecount.txt","r");
        int cnt = 0;
        while(fread(&ss,sizeof(npeCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        //printf("%s : %d\n",s.name,cnt);
        i++;
        ans+=cnt;

    }
    fclose(fp);
    if(n==1)
        printf("Total Casting Vote is: %d\n",ans);
    else if(n==2)
    {
        double a = 1.0*ans;
        int b = countvoterlist();
        //printf("Total voter: %d\n",b);
        double c = 1.0*(b-2);
        a = (a*100)/c;
        printf("Percentage of casting vote is: %0.2lf\%%\n",a);

    }
}


void npeDeleteCandidate()
{
    struct npeCandidate s;
    FILE *fp,*fp1;
    fp = fopen("npeCandidate.txt","r");
    fp1 = fopen("npeCandidate.txt","w");

    //printf("Enter your deleted Candidate: ");
    char str[]="akash";
    bool ok=true;
    while(fread(&s,sizeof(npeCandidate),1,fp))
    {

        for(int i=0; i<strlen(str); i++)
        {
            if(str[i]!=s.name[i])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(npeCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("npecandidate.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(npeCandidate),1,fp1))
        {
            fwrite(&s,sizeof(npeCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    npeDeletevote();
    npeDeletevoter();
}

///National parliament close



/// Zilla part
void zilla_parishad_Election()
{
here:

    int x = choice();
    switch(x)
    {
    case 1:
        zillasetcandidate();
        printf("\nBack to previous menu\nPress any key\n");
        char x;
        getchar();
        scanf("%c",&x);
        goto here;
    case 2:
        zillaDisplayCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 3:
        zillaDeleteCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 4:
        zillaobtainedvote();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 5:
        zillatotalcastingvote(1);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 6:
        zillatotalcastingvote(2);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 7:
        voterlist();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    }
}

void zillasetcandidate()
{
    struct zillaCandidate *s;
    FILE *fp;
    fp = fopen("zillaCandidate.txt","a");

    printf("How many candidate adding here: ");
    int n;
    scanf("%d",&n);
    s = (zillaCandidate*)calloc(n,sizeof(zillaCandidate));
    for(int i=0; i<n; i++)
    {
        if(i==0)
            printf("Enter the %dst candidate name: ",i+1);
        else if(i==1)
            printf("Enter the %dnd candidate name: ",i+1);
        else if(i==2)
            printf("Enter the %drd candidate name: ",i+1);
        else
            printf("Enter the %dth candidate name: ",i+1);

        getchar();
        scanf("%[^\n]s",&s[i].name);
        fwrite(&s[i],sizeof(zillaCandidate),1,fp);

    }
    fclose(fp);
    //zillaDisplayCandidate();
    //zillaSearchCandidate();
    //zillaDeleteCandidate();

}

void zillaDisplayCandidate()
{
    struct zillaCandidate s;
    FILE *fp;
    fp = fopen("zillaCandidate.txt","r");
    int cnt=1;
    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {
        //printf("akash");
        printf("%d. %s\n",cnt,s.name);
        cnt++;
    }
    fclose(fp);

}


void zillaobtainedvote()
{
    struct zillaCandidate s;
    FILE *fp;
    fp = fopen("zillaCandidate.txt","r");
    int i=1;
    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {
        int cnt = 0;
        struct zillaCandidate ss;
        FILE *fpp;
        fpp = fopen("zillavotecount.txt","r");
        while(fread(&ss,sizeof(zillaCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        printf("%s : %d\n",s.name,cnt);
        i++;

    }
    fclose(fp);
}


void zillatotalcastingvote(int n)
{
    struct zillaCandidate s;
    FILE *fp;
    fp = fopen("zillaCandidate.txt","r");
    int i=1;
    int ans=0;
    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {
        struct zillaCandidate ss;
        FILE *fpp;
        fpp = fopen("zillavotecount.txt","r");
        int cnt = 0;
        while(fread(&ss,sizeof(zillaCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        //printf("%s : %d\n",s.name,cnt);
        i++;
        ans+=cnt;

    }
    fclose(fp);
    if(n==1)
        printf("Total Casting Vote is: %d\n",ans);
    else if(n==2)
    {
        double a = 1.0*ans;
        int b = countvoterlist();
        //printf("Total voter: %d\n",b);
        double c = 1.0*(b-2);
        a = (a*100)/c;
        printf("Percentage of casting vote is: %0.2lf\%%\n",a);
    }
}


void zillaDeleteCandidate()
{
    struct zillaCandidate s;
    FILE *fp,*fp1;
    fp = fopen("zillaCandidate.txt","r");
    fp1 = fopen("zillaCandidate.txt","w");

    //printf("Enter your deleted Candidate: ");
    char str[]="akash";
    bool ok=true;
    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {

        for(int i=0; i<strlen(str); i++)
        {
            if(str[i]!=s.name[i])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(zillaCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("zillacandidate.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(zillaCandidate),1,fp1))
        {
            fwrite(&s,sizeof(zillaCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    zillaDeletevote();
}

/// Zilla part close



/// Upozilla part

void upozilla_parishad_Election()
{
here:

    int x = choice();
    switch(x)
    {
    case 1:
        upozillasetcandidate();
        printf("\nBack to previous menu\nPress any key\n");
        char x;
        getchar();
        scanf("%c",&x);
        goto here;
    case 2:
        upozillaDisplayCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 3:
        upozillaDeleteCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 4:
        upozillaobtainedvote();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 5:
        upozillatotalcastingvote(1);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 6:
        upozillatotalcastingvote(2);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 7:
        voterlist();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    }
}


void upozillasetcandidate()
{
    struct upozillaCandidate *s;
    FILE *fp;
    fp = fopen("upozillaCandidate.txt","a");

    printf("How many candidate adding here: ");
    int n;
    scanf("%d",&n);
    s = (upozillaCandidate*)calloc(n,sizeof(upozillaCandidate));
    for(int i=0; i<n; i++)
    {
        if(i==0)
            printf("Enter the %dst candidate name: ",i+1);
        else if(i==1)
            printf("Enter the %dnd candidate name: ",i+1);
        else if(i==2)
            printf("Enter the %drd candidate name: ",i+1);
        else
            printf("Enter the %dth candidate name: ",i+1);

        getchar();
        scanf("%[^\n]s",&s[i].name);
        fwrite(&s[i],sizeof(upozillaCandidate),1,fp);

    }
    fclose(fp);
    //upozillaDisplayCandidate();
    //upozillaSearchCandidate();
    //upozillaDeleteCandidate();

}

void upozillaDisplayCandidate()
{
    struct upozillaCandidate s;
    FILE *fp;
    fp = fopen("upozillaCandidate.txt","r");
    int cnt=1;
    while(fread(&s,sizeof(upozillaCandidate),1,fp))
    {
        //printf("akash");
        printf("%d. %s\n",cnt,s.name);
        cnt++;
    }
    fclose(fp);

}

void upozillaobtainedvote()
{
    struct upozillaCandidate s;
    FILE *fp;
    fp = fopen("upozillaCandidate.txt","r");
    int i=1;
    while(fread(&s,sizeof(upozillaCandidate),1,fp))
    {
        int cnt = 0;
        struct upozillaCandidate ss;
        FILE *fpp;
        fpp = fopen("upozillavotecount.txt","r");
        while(fread(&ss,sizeof(upozillaCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        printf("%s : %d\n",s.name,cnt);
        i++;

    }
    fclose(fp);
}


void upozillatotalcastingvote(int n)
{
    struct upozillaCandidate s;
    FILE *fp;
    fp = fopen("upozillaCandidate.txt","r");
    int i=1;
    int ans=0;
    while(fread(&s,sizeof(upozillaCandidate),1,fp))
    {
        struct upozillaCandidate ss;
        FILE *fpp;
        fpp = fopen("upozillavotecount.txt","r");
        int cnt = 0;
        while(fread(&ss,sizeof(upozillaCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        //printf("%s : %d\n",s.name,cnt);
        i++;
        ans+=cnt;

    }
    fclose(fp);
    if(n==1)
        printf("Total Casting Vote is: %d\n",ans);
    else if(n==2)
    {
        double a = 1.0*ans;
        int b = countvoterlist();
        //printf("Total voter: %d\n",b);
        double c = 1.0*(b-2);
        a = (a*100)/c;
        printf("Percentage of casting vote is: %0.2lf\%%\n",a);
    }
}


void upozillaDeleteCandidate()
{
    struct zillaCandidate s;
    FILE *fp,*fp1;
    fp = fopen("upozillaCandidate.txt","r");
    fp1 = fopen("upozillaCandidate.txt","w");

    // printf("Enter your deleted Candidate: ");
    char str[]="akash";

    bool ok=true;
    while(fread(&s,sizeof(upozillaCandidate),1,fp))
    {

        for(int i=0; i<strlen(str); i++)
        {
            if(str[i]!=s.name[i])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(upozillaCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("upozillacandidate.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(upozillaCandidate),1,fp1))
        {
            fwrite(&s,sizeof(upozillaCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    upozillaDeletevote();
}

/// Upozilla part close



/// Union part

void union_parishad_Election()
{
here:

    int x = choice();
    switch(x)
    {
    case 1:
        unionsetcandidate();
        printf("\nBack to previous menu\nPress any key\n");
        char x;
        getchar();
        scanf("%c",&x);
        goto here;
    case 2:
        unionDisplayCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 3:
        unionDeleteCandidate();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 4:
        unionobtainedvote();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 5:
        uniontotalcastingvote(1);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    case 6:
        uniontotalcastingvote(2);
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;
    case 7:
        voterlist();
        printf("\nBack to previous menu\nPress any key\n");
        getchar();
        scanf("%c",&x);
        goto here;

    }
}


void unionsetcandidate()
{
    struct unionCandidate *s;
    FILE *fp;
    fp = fopen("unionCandidate.txt","a");

    printf("How many candidate adding here: ");
    int n;
    scanf("%d",&n);
    s = (unionCandidate*)calloc(n,sizeof(unionCandidate));
    for(int i=0; i<n; i++)
    {
        if(i==0)
            printf("Enter the %dst candidate name: ",i+1);
        else if(i==1)
            printf("Enter the %dnd candidate name: ",i+1);
        else if(i==2)
            printf("Enter the %drd candidate name: ",i+1);
        else
            printf("Enter the %dth candidate name: ",i+1);

        getchar();
        scanf("%[^\n]s",&s[i].name);
        fwrite(&s[i],sizeof(unionCandidate),1,fp);

    }
    fclose(fp);
    //unionDisplayCandidate();
    //unionSearchCandidate();
    //unionDeleteCandidate();

}

void unionDisplayCandidate()
{
    struct upozillaCandidate s;
    FILE *fp;
    fp = fopen("unionCandidate.txt","r");
    int cnt = 1;
    while(fread(&s,sizeof(unionCandidate),1,fp))
    {
        //printf("akash");
        printf("%d. %s\n",cnt,s.name);
        cnt++;
    }
    fclose(fp);

}

void unionobtainedvote()
{
    struct unionCandidate s;
    FILE *fp;
    fp = fopen("unionCandidate.txt","r");
    int i=1;
    while(fread(&s,sizeof(unionCandidate),1,fp))
    {
        int cnt = 0;
        struct unionCandidate ss;
        FILE *fpp;
        fpp = fopen("unionvotecount.txt","r");
        while(fread(&ss,sizeof(unionCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        printf("%s : %d\n",s.name,cnt);
        i++;

    }
    fclose(fp);
}


void uniontotalcastingvote(int n)
{
    struct unionCandidate s;
    FILE *fp;
    fp = fopen("unionCandidate.txt","r");
    int i=1;
    int ans=0;
    while(fread(&s,sizeof(unionCandidate),1,fp))
    {
        struct unionCandidate ss;
        FILE *fpp;
        fpp = fopen("unionvotecount.txt","r");
        int cnt = 0;
        while(fread(&ss,sizeof(unionCandidate),1,fpp))
        {
            if(i==ss.votecount)
                cnt++;
        }
        //printf("%s : %d\n",s.name,cnt);
        i++;
        ans+=cnt;

    }
    fclose(fp);
    if(n==1)
        printf("Total Casting Vote is: %d\n",ans);
    else if(n==2)
    {
        double a = 1.0*ans;
        int b = countvoterlist();
        //printf("Total voter: %d\n",b);
        double c = 1.0*(b-2);
        a = (a*100)/c;
        printf("Percentage of casting vote is: %0.2lf\%%\n",a);
    }
}


void unionDeleteCandidate()
{
    struct unionCandidate s;
    FILE *fp,*fp1;
    fp = fopen("unionCandidate.txt","r");
    fp1 = fopen("unionCandidate.txt","w");

    // printf("Enter your deleted Candidate: ");
    char str[]="akash";

    bool ok=true;
    while(fread(&s,sizeof(unionCandidate),1,fp))
    {

        for(int i=0; i<strlen(str); i++)
        {
            if(str[i]!=s.name[i])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(unionCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("unioncandidate.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(unionCandidate),1,fp1))
        {
            fwrite(&s,sizeof(unionCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    unionDeletevote();
}

/// Union part close



int choice()
{

    int x;
    printf("\n\n1. Set the Candidate");
    printf("\n2. Show the Candidate");
    printf("\n3. Delete the Candidates");
    printf("\n4. Obtained vote of each Candidate");
    printf("\n5. Total casting vote");
    printf("\n6. Percentage of casting vote");
    printf("\n7. See voter list");
    printf("\n8. Back to previous menu\n\n");

    printf("Enter your choice: ");
    scanf("%d",&x);

    return x;
}





void voterlist()
{
    // char *filename = "voter.txt";
    FILE *fp = fopen("voter.txt", "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", "voter.txt");
    }
    else
    {
        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];

        while (fgets(buffer, MAX_LENGTH, fp))
        {
            printf("%s", buffer);
        }
    }

    fclose(fp);

}


int countvoterlist()
{
    // char *filename = "voter.txt";
    FILE *fp = fopen("voter.txt", "r");
    int cnt=0;
    if (fp == NULL)
    {
        printf("Error: could not open file %s", "voter.txt");
    }
    else
    {
        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];

        while (fgets(buffer, MAX_LENGTH, fp))
        {
            cnt++;
            //printf("%s", buffer);
        }
    }

    fclose(fp);
    return cnt;

}



void voter_Activity()
{
    while(1)  /// This loop start the voting process
    {
        if(starting_voting_process()==1)
            break;
        else
        {
            printf("You press wrong key!\n");
        }
    }


    while(1)
    {
        int x = Input_NID();

        typesofElection(x);

        if(continuing_voting_process()==1)
            continue;
        else
            break;

    }

}

void typesofElection(int n)
{

ariful:
    printf("\n1. National Parliament Election");
    printf("\n2. Zilla Parishad Election");
    printf("\n3. Upozilla Parishad Election");
    printf("\n4. Union Parishad Election");
    printf("\n5. Back to previous menu");
    printf("\n\nEnter your choice: ");
    int x;
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        if(npecompletedvote(n)==1)
        {
            printf("Your vote is already done.\n\n");
        }
        else
        {
            npeDisplayCandidate();
            npegivenvote();
        }
        printf("Back to previous option\npress any key\n");
        char ch;
        getchar();
        scanf("%c",&ch);
        goto ariful;
        break;
    case 2:
        if(zillacompletedvote(n)==1)
        {
            printf("Your vote is already done.\n\n");
        }
        else
        {
            zillaDisplayCandidate();
            zillagivenvote();
        }
        printf("Back to previous option\npress any key\n");
        getchar();
        scanf("%c",&ch);
        goto ariful;
        break;
    case 3:
        if(upozillacompletedvote(n)==1)
        {
            printf("Your vote is already done.\n\n");
        }
        else
        {
            upozillaDisplayCandidate();
            upozillagivenvote();
        }
        printf("Back to previous option\npress any key\n");
        getchar();
        scanf("%c",&ch);
        goto ariful;
        break;
    case 4:
        if(unioncompletedvote(n)==1)
        {
            printf("Your vote is already done.\n\n");
        }
        else
        {
            unionDisplayCandidate();
            uniongivenvote();
        }
        printf("Back to previous option\npress any key\n");
        getchar();
        scanf("%c",&ch);
        goto ariful;
        break;

    }
}


int npecompletedvote(int n)
{

    FILE *fptr;

    fptr = fopen("npecompletevote.txt", "r");
    int num;
    bool ok = true;
    while ( (num = getw(fptr)) != EOF )
    {
        if(num==n)
        {
            ok=false;
            break;
        }
    }

    fclose(fptr);
    if(ok==false)
        return 1;
    else
    {
        fptr = fopen("npecompletevote.txt", "w");
        putw(n, fptr);
        fclose(fptr);
        return 2;
    }


}


int zillacompletedvote(int n)
{

    FILE *fptr;

    fptr = fopen("zillacompletevote.txt", "r");
    int num;
    bool ok = true;
    while ( (num = getw(fptr)) != EOF )
    {
        if(num==n)
        {
            ok=false;
            break;
        }
    }

    fclose(fptr);
    if(ok==false)
        return 1;
    else
    {
        fptr = fopen("zillacompletevote.txt", "w");
        putw(n, fptr);
        fclose(fptr);
        return 2;
    }


}


int upozillacompletedvote(int n)
{

    FILE *fptr;

    fptr = fopen("upozillacompletevote.txt", "r");
    int num;
    bool ok = true;
    while ( (num = getw(fptr)) != EOF )
    {
        if(num==n)
        {
            ok=false;
            break;
        }
    }

    fclose(fptr);
    if(ok==false)
        return 1;
    else
    {
        fptr = fopen("upozillacompletevote.txt", "w");
        putw(n, fptr);
        fclose(fptr);
        return 2;
    }


}


int unioncompletedvote(int n)
{

    FILE *fptr;

    fptr = fopen("unioncompletevote.txt", "r");
    int num;
    bool ok = true;
    while ( (num = getw(fptr)) != EOF )
    {
        if(num==n)
        {
            ok=false;
            break;
        }
    }

    fclose(fptr);
    if(ok==false)
        return 1;
    else
    {
        fptr = fopen("unioncompletevote.txt", "w");
        putw(n, fptr);
        fclose(fptr);
        return 2;
    }


}





void npegivenvote()
{
    struct npeCandidate *s;
    FILE *fp;
    fp = fopen("npevotecount.txt","a");
    s = (npeCandidate*)calloc(1,sizeof(npeCandidate));
    printf("Enter your vote: ");
    getchar();
    scanf("%d",&s[0].votecount);
    fwrite(&s[0],sizeof(npeCandidate),1,fp);
    fclose(fp);
    printf("*done*\n");
    //npeDisplayvote();
    //npeDeletevote();

}

void npeDisplayvote()
{
    struct npeCandidate s;
    FILE *fp;
    fp = fopen("npevotecount.txt","r");

    while(fread(&s,sizeof(npeCandidate),1,fp))
    {
        //printf("akash");
        printf("%d\n",s.votecount);
    }
    fclose(fp);

}

void npeDeletevote()
{
    struct npeCandidate s;
    FILE *fp,*fp1;
    fp = fopen("npevotecount.txt","r");
    fp1 = fopen("npevotecount.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(npeCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(npeCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("npevotecount.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(npeCandidate),1,fp1))
        {
            fwrite(&s,sizeof(npeCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}


void zillagivenvote()
{
    struct zillaCandidate *s;
    FILE *fp;
    fp = fopen("zillavotecount.txt","a");
    s = (zillaCandidate*)calloc(1,sizeof(zillaCandidate));
    printf("Enter your vote: ");
    getchar();
    scanf("%d",&s[0].votecount);
    fwrite(&s[0],sizeof(zillaCandidate),1,fp);
    fclose(fp);
    printf("*done*\n");
    //zillaDisplayvote();
    //zillaDeletevote();

}

void zillaDisplayvote()
{
    struct zillaCandidate s;
    FILE *fp;
    fp = fopen("zillavotecount.txt","r");

    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {
        //printf("akash");
        printf("%d\n",s.votecount);
    }
    fclose(fp);

}

void zillaDeletevote()
{
    struct zillaCandidate s;
    FILE *fp,*fp1;
    fp = fopen("zillavotecount.txt","r");
    fp1 = fopen("zillavotecount.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(zillaCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("zillavotecount.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(zillaCandidate),1,fp1))
        {
            fwrite(&s,sizeof(zillaCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}



void upozillagivenvote()
{
    struct upozillaCandidate *s;
    FILE *fp;
    fp = fopen("upozillavotecount.txt","a");
    s = (upozillaCandidate*)calloc(1,sizeof(upozillaCandidate));
    printf("Enter your vote: ");
    getchar();
    scanf("%d",&s[0].votecount);
    fwrite(&s[0],sizeof(upozillaCandidate),1,fp);
    fclose(fp);
    printf("*done*\n");
    //upozillaDisplayvote();
    //upozillaDeletevote();

}

void upozillaDisplayvote()
{
    struct upozillaCandidate s;
    FILE *fp;
    fp = fopen("upozillavotecount.txt","r");

    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {
        //printf("akash");
        printf("%d\n",s.votecount);
    }
    fclose(fp);

}

void upozillaDeletevote()
{
    struct upozillaCandidate s;
    FILE *fp,*fp1;
    fp = fopen("upozillavotecount.txt","r");
    fp1 = fopen("upozillavotecount.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(upozillaCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(upozillaCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("upozillavotecount.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(upozillaCandidate),1,fp1))
        {
            fwrite(&s,sizeof(upozillaCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}

void uniongivenvote()
{
    struct unionCandidate *s;
    FILE *fp;
    fp = fopen("unionvotecount.txt","a");
    s = (unionCandidate*)calloc(1,sizeof(unionCandidate));
    printf("Enter your vote: ");
    getchar();
    scanf("%d",&s[0].votecount);
    fwrite(&s[0],sizeof(unionCandidate),1,fp);
    fclose(fp);
    printf("*done*\n");
    //unionDisplayvote();
    //unionDeletevote();

}

void unionDisplayvote()
{
    struct unionCandidate s;
    FILE *fp;
    fp = fopen("unionvotecount.txt","r");

    while(fread(&s,sizeof(unionCandidate),1,fp))
    {
        //printf("akash");
        printf("%d\n",s.votecount);
    }
    fclose(fp);

}

void unionDeletevote()
{
    struct unionCandidate s;
    FILE *fp,*fp1;
    fp = fopen("unionvotecount.txt","r");
    fp1 = fopen("unionvotecount.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(unionCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(unionCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("unionvotecount.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(unionCandidate),1,fp1))
        {
            fwrite(&s,sizeof(unionCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}


void npeDeletevoter()
{
    struct npeCandidate s;
    FILE *fp,*fp1;
    fp = fopen("npecompletevote.txt","r");
    fp1 = fopen("npecompletevote.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(npeCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(npeCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("npecompletevote.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(npeCandidate),1,fp1))
        {
            fwrite(&s,sizeof(npeCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}


void zillaDeletevoter()
{
    struct zillaCandidate s;
    FILE *fp,*fp1;
    fp = fopen("zillacompletevote.txt","r");
    fp1 = fopen("zillacompletevote.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(zillaCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(zillaCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("zillacompletevote.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(zillaCandidate),1,fp1))
        {
            fwrite(&s,sizeof(zillaCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}


void upozillaDeletevoter()
{
    struct upozillaCandidate s;
    FILE *fp,*fp1;
    fp = fopen("upozillacompletevote.txt","r");
    fp1 = fopen("upozillacompletevote.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(upozillaCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(upozillaCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("upozillacompletevote.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(upozillaCandidate),1,fp1))
        {
            fwrite(&s,sizeof(upozillaCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}


void unionDeletevoter()
{
    struct upozillaCandidate s;
    FILE *fp,*fp1;
    fp = fopen("unioncompletevote.txt","r");
    fp1 = fopen("unioncompletevote.txt","w");

    // printf("Enter your deleted Candidate: ");
    int str=100000000;

    bool ok=true;
    while(fread(&s,sizeof(unionCandidate),1,fp))
    {

        if(ok)
        {
            break;
        }
        else
            fwrite(&s,sizeof(unionCandidate),1,fp1);

    }

    fclose(fp);
    fclose(fp1);
    if(ok)
    {

        fp = fopen("unioncompletevote.txt","w");
        fp1 = fopen("delete record.txt","r");
        while(fread(&s,sizeof(unionCandidate),1,fp1))
        {
            fwrite(&s,sizeof(unionCandidate),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}



int Input_NID()
{
ariful:

    char str[15];
    printf("\nEnter your 6 digit nid number: ");
    scanf("%s",str);
    if(strlen(str)!=6)
    {
        printf("Wrong NID!\n");
        goto ariful;
    }
    if(nidInvoterlist(str)!=1)
    {
        printf("Your NID not found in the Voter list.\n");
        goto ariful;
    }
    int a=0;
    for(int i=0; i<6; i++)
    {
        a=a*10+str[i]-48;
    }
    return a;
}

int starting_voting_process()
{

    printf("\nStart the voting process.....\n");
    printf("Please, Enter 1\n");
    int x;
    scanf("%d",&x);
    if(x==1)
        return 1;
    else
        return 0;
}

int nidInvoterlist(char str[])
{
    //char *filename = "voter.txt";
    FILE *fp = fopen("voter.txt", "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", "voter.txt");
        return 1;
    }
    const unsigned MAX_LEN = 256;
    char buffer[MAX_LEN];
    int ok;
    while (fgets(buffer, MAX_LEN, fp))
    {

        ok = 1;
        for(int i=0; i<strlen(str); i++)
        {
            if(str[i]!=buffer[i])
            {
                ok=0;
                break;
            }
        }
        if(ok)
            break;
        //printf("%s", buffer);
    }

    // close the file
    fclose(fp);
    if(ok)
        return 1;
    else
        return 2;

}

int continuing_voting_process()
{

    printf("1. Continuing voting process....\n");
    printf("2. End the voting process.\n");
    printf("\nEnter your choice: ");
    int x;
    scanf("%d",&x);
    if(x==1)
        return 1;
    else
        return 2;
}



