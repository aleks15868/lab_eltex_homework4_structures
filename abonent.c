#include <stdio.h>
#include <string.h> 
//---------------------------------------------------->Start struct abonent
struct abonent
{
        char name[10];
        char second_name[10];
        char tel[10];
};
//---------------------------------------------------->End struct abonent
//-------------------------------------------------------------------------------------------->Start Add_Abonent
void Add_Abonent(struct abonent *Abonent, int *Number)
{
    int Input;
    char Stop_Flag='n';
    printf("\nMenu Add:\n1)One subscriber\n2)Many subscriber\n3)Exit");                              
    printf("\nInput:");
    scanf("%d",&Input);
    switch(Input)
    {
	    case 1:
		    printf("Abonent name:");
		    scanf("%s",Abonent[*Number].name);
		    printf("Abonent surname:");
		    scanf("%s",Abonent[*Number].second_name);
		    printf("Abonent telephone:");
		    scanf("%s",Abonent[*Number].tel);
		    *Number+=1;
		    break;
	    case 2:
		    do{
			    if(*Number<100)
			    {
				    printf("Abonent name:");
				    scanf("%s",Abonent[*Number].name);
				    printf("Abonent surname:");
				    scanf("%s",Abonent[*Number].second_name);
				    printf("Abonent telephone:");
				    scanf("%s",Abonent[*Number].tel);
				    *Number+=1;
				    printf("Should I stop?(y/n):");
				    fflush(stdin);
				    scanf("%s",&Stop_Flag);
			    }
			    else
			    {
				    printf("Exceeding the list");
			    }
		}
		while((Stop_Flag!='Y') && (Stop_Flag!='y'));
            default:
               break;                                                                   
    }
}
//------------------------------------------------------------------------------------>End Add_Abonent
//------------------------------------------>Start Print_Table
void Print_Table(struct abonent *Abonent_List)
{	
	printf("┌──────────┬──────────┬──────────┬──────────┐\n");
        printf("│     №    │   Name   │ Surname  │Telephone │\n");
        printf("├──────────┼──────────┼──────────┼──────────┤\n");

	for (int Strock = 0; Strock < 100; Strock++) {
        printf("│%10d│%10s│%10s│%10s│\n",(Strock+1), Abonent_List[Strock].name,Abonent_List[Strock].second_name,Abonent_List[Strock].tel);
        if (Strock!= 99) {
                        printf("├──────────┼──────────┼──────────┼──────────┤\n");
                } else {
                        printf("└──────────┴──────────┴──────────┴──────────┘\n");
                }

    	}
}
//------------------------------------------>End Print_Table
//------------------------------------------>Start Find_Table
void Find_Table(struct abonent *Abonent_List)
{
	char Find_Name[10];
	printf("\nInput find name:");
	scanf("%s",Find_Name);
        printf("┌──────────┬──────────┬──────────┬──────────┐\n");
        printf("│     №    │   Name   │ Surname  │Telephone │\n");
        printf("├──────────┼──────────┼──────────┼──────────┤\n");

        for (int Strock = 0; Strock < 100; Strock++) {
	if ((strcmp (Find_Name, Abonent_List[Strock].name)==0))
	{
        	printf("│%10d│%10s│%10s│%10s│\n",(Strock+1), Abonent_List[Strock].name,Abonent_List[Strock].second_name,Abonent_List[Strock].tel);
        	if (Strock!= 99) {
                	printf("├──────────┼──────────┼──────────┼──────────┤\n");
        	} else {
                	printf("└──────────┴──────────┴──────────┴──────────┘\n");
		}
	}

        }
}
//------------------------------------------>End Find_Table
//------------------------------------------>Start Delete_Abonent
void Delete_Abonent(struct abonent *Abonent_List)
{
	int Number_Abonent;
	printf("Input number list abonents:");
	scanf("%d",&Number_Abonent);
	if ((Number_Abonent>=0) && (Number_Abonent<100))
	{
		strcpy(Abonent_List[Number_Abonent-1].name, "0");
		strcpy(Abonent_List[Number_Abonent-1].second_name, "0");
		strcpy(Abonent_List[Number_Abonent-1].tel, "0");
	}
	else
	{
		printf("No such number!!!");
	}
}
//------------------------------------------>End Delete_Abonent
int main(void)
{               
    int Choise=0;
    struct abonent Abonent_List[100]={0};
    int Last_Number_Add_Abonent=0;
    while(Choise<5)
    {
        switch(Choise)
        {
        case 1:
		if(Last_Number_Add_Abonent<100)
		{
			Add_Abonent(Abonent_List, &Last_Number_Add_Abonent);
		}
		else
		{
			printf("Exceeding the list");
		}
            break;
        case 2:
            Delete_Abonent(Abonent_List);
            break;                                                                                   
        case 3:
            Find_Table(Abonent_List);
            break;
        case 4:
            Print_Table(Abonent_List);
            break;                                                                                  
        default :
            break;
        }
        printf("Menu:\n1) Add a subscriber\n2) Delete the subscriber\n3) Search for a subscriber by name\n4) Output of all records\n5) Exit\n");
        printf("Input:");
        scanf("%d",&Choise);
    }
    return 0;
}
