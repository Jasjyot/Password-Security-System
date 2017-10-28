#include<stdio.h>
#include<string.h>//strcmp(),strcat()
#include<stdlib.h>//rand()

void signup(char *username, char *password);
int verifyPassword(int ,char *);
int verifyUsername(char *);
void generateSalt();
char getSalt(int sNo);
int main()
{
    int choice;
    char username[50],password[50];

    printf("1. Signin \n");
    printf("2. Signup (New User) \n");
    scanf("%d",&choice);

    if(choice==1)
    {   
        int sNo;
        printf("Username:\n");
        scanf("%s",username);
        sNo=verifyUsername(username);
        if(sNo)
        {
            printf("Username verified.\n");    
            printf("Password:\n");
            scanf("%s",password);

           if(verifyPassword(sNo,password))
            {
                printf("Login Successful\n");
            }
            else
            {
                printf("Wrong Password\n");
            }
        }
        else
        {
            printf("No such user exists.\n");
        }

    }

    else if(choice==2)
    {
        printf("Username:\n");
        scanf("%s",username);

        printf("Password:\n");
        scanf("%s",password);

        signup(username,password);
    }

    else 
    {
        printf("Invalid choice! Try again.");
    }
    return 0;
}

void signup(char *username,char *password)
{
    FILE *fp_user_directory;
    FILE *fp_pwd_directory;
   

    fp_user_directory=fopen("user_directory.txt","a");
    
    /*
    if(fp_user_directory==NULL)
    {
        puts("Cannot open file");
    }
    */

    fputs(username,fp_user_directory);
    fputs("\n",fp_user_directory);
    fclose(fp_user_directory);

    fp_pwd_directory=fopen("pwd_directory.txt","a");
    
    /*
    if(fp_user_directory==NULL)
    {
        puts("Cannot open file");
    }
    */
    fputs(password,fp_pwd_directory);
    fputs("\n",fp_pwd_directory);
    fclose(fp_pwd_directory);
    generateSalt();
}

int verifyUsername(char *user_query)
{
    int sNo=0;
    char db_username[50];
    FILE *fp_user_directory;
    fp_user_directory=fopen("user_directory.txt","r");

    /*
    if(fp_user_directory==NULL)
    {
        puts("Cannot open file");
    }
    */

    //while(fgets(db_username,49,fp_user_directory)!='\0')
    
    while(fscanf(fp_user_directory,"%s",db_username)!=EOF)
    {   
        sNo++;
        if(strcmp(db_username,user_query)==0)
        {   
            fclose(fp_user_directory);
            return sNo;
        }    
    }
    fclose(fp_user_directory);
    return 0;
}
int verifyPassword(int sNo,char *pwd_query)
{
    char db_pwd[50];
    FILE *fp_pwd_directory;
    fp_pwd_directory=fopen("pwd_directory.txt","r");

    //getSalt(sNo);


    for(int i=0;i<sNo;i++)
    {
        fscanf(fp_pwd_directory,"%s",db_pwd);
        if(strcmp(db_pwd,pwd_query)==0)
        {   
            fclose(fp_pwd_directory);
            return 1;
        }    
    }
    fclose(fp_pwd_directory);
    return 0;
}
void generateSalt()
{
    char salt[5];
    short index;
    FILE *fp_salt_directory;
    char arr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q'
    ,'r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    for (int i=0;i<4;i++)
    {
        index=rand()%63;
        salt[i]=arr[index];
    }
    salt[4]='\0';
    fp_salt_directory=fopen("salt_directory.txt","a");
    /*
    if(fp_user_directory==NULL)
    {
        puts("Cannot open file");
    }
    */
    fputs(salt,fp_salt_directory);
    fputs("\n",fp_salt_directory);
    fclose(fp_salt_directory);
}
char getSalt(int sNo)
{
    FILE *fp_salt_directory;
    fp_salt_directory=fopen("salt_directory.txt,"r");
    for(int i=0;i<;i++)
    {

    }
}
