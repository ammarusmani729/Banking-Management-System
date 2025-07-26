#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define Account_no 100

typedef struct account{
	char name[200];
	int pin;
	long int acc_number;
	float balance;
}account;

checkaccount(long int acc){
	account str;
	FILE *ptr = fopen("Accountdetail.txt", "r");

    
    if (ptr == NULL){
        return 0;
    }
    
	while (fread(&str, sizeof(str), 1, ptr)) {
        if (str.acc_number == acc) {
        	printf("Account Number is not available!\n");
            return 1;
		}
	}
	fclose(ptr);
	return 0;
}

void createAccount(){
	account str;
	int c;
	printf("Enter the Name:");
	fflush(stdin);
    fgets(str.name,sizeof(str.name),stdin);
	printf("Enter the pin:");
	scanf("%d", &str.pin);
	if(str.pin<0){
		printf("Invalid pin enter!\n");
		printf("Try Again!\n");
		printf("Enter Pin:");
		scanf("%d",&str.pin);
    }
	do
	{
	  str.acc_number=rand();
	  printf("this is your Account number:%ld\n",str.acc_number);
	  c = checkaccount(str.acc_number);
	}while(c!=0);
	printf("Enter the Balance:");
	scanf("%f", &str.balance);
	if(str.balance<0){
		printf("insufficient amount!\n");
		printf("Enter amount again:");
		scanf("%f",&str.balance);
	}
	printf("\n");
	FILE * ptr=fopen("Accountdetail.txt","a+");
	if (ptr == NULL){
        printf("File does not exist!\n");
        return;
    }
	fwrite(&str,sizeof(str),1,ptr);
	fclose(ptr);
	
	system("cls");
	printf("Your Account is successfully created!\n");
	
}
void deposit(){
	float amount;
	printf("Enter amount which you want to deposit:");
	scanf("%f",&amount);
	if(amount<0){
		printf("please enter valid amount!\n");
		printf("Enter amount again:");
		scanf("%f",&amount);
	}
	if(amount>655555){
		printf("\n");
		printf("Limit exceeds of deposit at one time!\n");
		printf("Enter amount again:");
		scanf("%f",&amount);
	}
	int pin;
	printf("enter pin:");
	scanf("%d",&pin);
	account str;
    FILE *ptr = fopen("Accountdetail.txt", "r");

    
    if (ptr == NULL){
        printf("File does not exist!\n");
        return;
    }
	FILE *ptr23 =fopen("Copy.txt","w"); 
    while (fread(&str, sizeof(str), 1, ptr)) {
        if (str.pin == pin) {
            str.balance+=amount;
            system("cls");
            printf("Your Amount is %.2f\n",str.balance);
		}else{
			printf("data is invalid!\n");
		}
		fwrite(&str,sizeof(str),1,ptr23);
	}
	printf("\n");
	fclose(ptr);
	fclose(ptr23);
	remove("Accountdetail.txt");
	rename("Copy.txt","Accountdetail.txt");
	return;
	
}

void withdraw(){
	float amount;
	printf("Enter the amount you want to withdraw:");
	scanf("%f",&amount);
	if(amount<0){
		printf("please enter valid amount!\n");
		printf("Enter amount again:");
		scanf("%f",&amount);
	}
	int pin;
	printf("enter pin:");
	scanf("%d",&pin);
	account str;
    FILE *ptr = fopen("Accountdetail.txt", "r");
    if (ptr == NULL){
        printf("File does not exist!\n");
        return;
    }
	FILE *ptr23 =fopen("Copy.txt","w"); 
    while (fread(&str, sizeof(str), 1, ptr)) {
        if (str.pin == pin) {
        	if(amount>str.balance){
        		printf("Cash cannot be withdraw because Your net balance is less than your withdrawing amount!\n");
			}else if(amount>0){
				str.balance-=amount;
                system("cls");
                printf("Your Amount after withdraw is %.2f",str.balance);
                printf("\n");
			}
		}
		fwrite(&str,sizeof(str),1,ptr23);
	}
	printf("\n");
	fclose(ptr);
	fclose(ptr23);
	remove("Accountdetail.txt");
	rename("Copy.txt","Accountdetail.txt");
	return;
	
}

void checkdata(){
	int pin;
	long int acc;
	printf("Enter account number:");
	scanf("%ld",&acc);
	printf("Enter pin:");
	scanf("%d",&pin);
	printf("\n");
	account str;
    FILE *ptr = fopen("Accountdetail.txt", "r");

    
    if (ptr == NULL) {
        printf("File does not exist!\n");
        return;
    }
    int found=0;
    while (fread(&str, sizeof(str), 1, ptr)) {
        if (str.acc_number == acc && str.pin == pin) {
        	found=1;
        	system("cls");
        	printf("Account Details: \n");
        	printf("\n");
            printf("Name: %s\n",str.name);
            printf("Account Number:%d\n",str.acc_number);
            printf("\n");
            printf("Account pin:%d\n",str.pin);
            printf("\n");
            printf("Balance:%.2f\n",str.balance);
            break;  
        }
    }if (!found) {
        printf("Sorry, record not found.\n");
    }
    fclose(ptr);
    printf("\n");
}
void credit(){
	int pin;
	printf("Enter your pin:");
	scanf("%d",&pin);
	account str;
    FILE *ptr = fopen("Accountdetail.txt", "r");

    
    if (ptr == NULL){
        printf("File does not exist!\n");
        return;
    }
    while (fread(&str, sizeof(str), 1, ptr)) {
        if (str.pin == pin) {
        	system("cls");
            printf("Your Credit Card will be given to you in three working days.\n");
            printf("Thanks for Applying.\n");
		}else{
			printf("Pin did not match!\n");
		}
	}
	printf("\n");
}

void update(){
	long int acc;
	int pin;
	printf("Enter Account number:");
	scanf("%ld",&acc);
	printf("Enter pin:");
	scanf("%d",&pin);
	system("cls");
	account str;
    FILE *ptr = fopen("Accountdetail.txt", "r");

    
    if (ptr == NULL){
        printf("File does not exist!\n");
        return;
    }
	FILE *ptr23 =fopen("Copy.txt","w"); 
    while (fread(&str, sizeof(str), 1, ptr)){
        if (str.acc_number==acc && str.pin == pin){
        	int oldpin,newpin;
        	printf("Enter old pin:");
        	scanf("%d",&oldpin);
        	printf("Enter new pin:");
        	scanf("%d",&newpin);
        	str.pin=newpin;
        	system("cls");
        	printf("your New Pin is %d\n",newpin);
       		printf("\n");
		}else{
			printf("invalid data!\n");
		}
		fwrite(&str,sizeof(str),1,ptr23);
	}
	fclose(ptr);
	fclose(ptr23);
    remove("Accountdetail.txt");
    rename("Copy.txt","Accountdetail.txt");

	return;
}

void delt(){
	system("cls");
	char name[200];
	long int acc;
	int pin;
	printf("Enter user name:");
	fflush(stdin);
    fgets(name,sizeof(name),stdin);
	printf("Enter account number:");
	scanf("%ld",&acc);
	printf("Enter user pin:");
	scanf("%d",&pin);
	system("cls");
	account str;
    FILE *ptr = fopen("Accountdetail.txt", "r");

    
    if (ptr == NULL){
        printf("File does not exist!\n");
        return;
    }
    int found=0;
	FILE *ptr23 =fopen("Copy.txt","w"); 
    while (fread(&str, sizeof(str), 1, ptr)) {
    	if(str.acc_number==acc && str.pin == pin){
    		found=1;
    		continue;
		}
		else{
			fwrite(&str,sizeof(str),1,ptr23);
		}
	}
    if(!found){
    	printf("user did not match!\n");
	}
	if(found==1){
		printf("\n");
	    system("cls");
	    printf("Account has been deleted!\n");
	    fclose(ptr);
	    fclose(ptr23);
	    remove("Accountdetail.txt");
	    rename("Copy.txt","Accountdetail.txt");
	}
	return;
}

void loginAccount() {
    long int acc;
    int pin;
    printf("Enter the Account number: ");
    scanf("%ld", &acc);
    printf("Enter the pin: ");
    scanf("%d", &pin);

    account str;
    FILE *ptr = fopen("Accountdetail.txt", "r");

    
    if (ptr == NULL) {
        printf("File does not exist!\n");
        return;
    }
    int found = 0; 
    while (fread(&str, sizeof(str), 1, ptr)) {
        if (str.acc_number == acc && str.pin == pin) {
            found = 1;
            break;  
        }
    }
    if (!found) {
        printf("Sorry, record not found.\n");
    }
    fclose(ptr);
    printf("------>Bank Management System<------\n");
    printf("\n");
    if(found==1){
    	system("cls");
    	printf("You have the account in my bank!\n");
        printf("Account has been logged in!\n");
        printf("\n");
        while(1){
         	printf("1.Deposit:\n");
            printf("2.withdraw:\n");
            printf("3.Check Data:\n");
            printf("4.Apply for Credit Card:\n");
            printf("5.update your account:\n");
            printf("6.Delete your Account:\n");
            printf("7.Exit:\n");
            int option;
            printf("\n");
            printf("->Select From Them:");
            scanf("%d",&option);
            switch(option){
   	            case 1:
    		       deposit();
    		       break;
    	        case 2:
		           withdraw();
			       break;
		        case 3:	
		           checkdata();
			       break;
			    case 4:
			       credit();
				   break;    
		        case 5:
		           update();
		           return;
			       break;	
			    case 6:
			       delt();
			       return;
				   break;    
		        case 7:
			       system("cls");
		           printf("Returning to first interface!\n");
			       return ;	
		        default:
		           printf("Invalid Input!");		
	        } 	
        }
	}
}
void Admin(){
	int adminpass = 1313;
	int pass;
	printf("Enter Admin Password:");
	scanf("%d",&pass);
	if(adminpass == pass){
		system("cls");
		while(1){
			int select;
     	    printf("1.See All Data:\n");
	        printf("2.delete any account:\n");
	        printf("3.Exit:\n");
	        printf("\n");
	        printf("->Select from them:");
	        scanf("%d",&select);
	        account str;
	        FILE *ptr = fopen("Accountdetail.txt", "r");
            if (ptr == NULL) {
               printf("File does not exist!\n");
               return;
            }
            switch(select){
	     	    case 1:
			        while (fread(&str, sizeof(str), 1, ptr)){
    	                printf("Account holder name is %s\n",str.name);
                        printf("Account number:%d\n",str.acc_number);
                        printf("\n");
                        printf("Account pin:%d\n",str.pin);
                        printf("\n");
                        printf("Balance:%.2f\n",str.balance);
                        printf("\n");
                    }
			        break;	
		        case 2:
		        	fclose(ptr);
		            delt();
			        return;
		        case 3:
		        	fclose(ptr);
		            return;
		        default:
		            printf("invalid input!\n");			
	        }

            fclose(ptr);
            printf("\n");	
		}
    }else{
     	printf("Invalid Admin Password!\n");
     	return;
	}
}

int main(){
	srand(time(NULL));
	system("COLOR 7d");
	account accounts;
	int choice;
	printf("\t\t\t\t--------->Bank Management System<---------\n");
	while(1){
	
		printf("\n");
		printf("1.Create an Account:\n");
		printf("2.Login to account:\n");
		printf("3.Admin:\n");
		printf("4.Exit:\n");            
		printf("\n");
		printf("->Enter your choice:");
		scanf("%d",&choice);           
		
		switch(choice){
		case 1:
				createAccount();
				break;
		case 2:
				loginAccount();
				break;	
		case 3:
		        Admin();
				break;		
		case 4:
			    system("cls");
		        printf("System is shutting down!\n");
				return 0;
		default:
		       printf("Invalid input!\n");		
	    }
    }
    return 0;
}