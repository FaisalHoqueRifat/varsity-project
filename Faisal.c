#include <stdio.h>
#include <string.h>
int pt_count;

struct pt_info
{
    int id;
    char name[100];
    double bill;
};

struct pt_info pt_data[10];

void show_menu()
{
    printf("\t\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t\t\t\t  Welcome to IIUC's Hospital\n");
    printf("\t\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n *** PATIENT INFO ***\n");
    printf("1: Input data\n");
    printf("2: Show all\n");
    printf("3: Search by ID\n");
    printf("4: Update\n");
    printf("5: Health Insurance\n");
    printf("6: Delete Data\n");
    printf("7: Add New Data\n");
    printf("8: Sorting\n");
    printf("0: Exit\n");
}
void write_data()
{
    int i;
    printf("Enter the Number of Patients: ");
    scanf("%d", &pt_count);
    for(i = 0; i < pt_count; i++)
    {
        printf("Enter data for PATIENT %d\n", i+1);
        printf("ID (integer): ");
        scanf("%d", &pt_data[i].id);
        printf("Patient Name (string): ");
        scanf("%s", pt_data[i].name);
        printf("Bill (real number): ");
        scanf("%lf", &pt_data[i].bill);
    }
    FILE *fp = fopen("project.txt", "w");
    fprintf(fp, "%d\n", pt_count);
    for(i = 0; i < pt_count; i++)
    {
        fprintf(fp, "%d\n", pt_data[i].id);
        fprintf(fp, "%s\n", pt_data[i].name);
        fprintf(fp, "%lf\n", pt_data[i].bill);
    }
    fclose(fp);
}
void read_data()
{
    FILE *fp = fopen("project.txt", "r");
    if(fp != NULL)
    {
        int i;
        fscanf(fp, "%d", &pt_count);
        for(i = 0; i < pt_count; i++)
        {
            fscanf(fp, "%d %s%lf", &pt_data[i].id, pt_data[i].name, &pt_data[i].bill);
        }
        fclose(fp);
    }
    else
    {
        write_data();
    }
}
void input_data()
{
    printf("Enter data for PATIENT %d\n", pt_count+1);
    printf("ID (integer): ");
    scanf("%d", &pt_data[pt_count].id);
    printf("Patient Name (string): ");
    scanf("%s", pt_data[pt_count].name);
    printf("Bill (real number): ");
    scanf("%lf", &pt_data[pt_count].bill);
    pt_count++;
}
void show_all()
{
    int i;
    if (0 == pt_count)
    {
        printf("No data found ...\n");
        return;
    }
    printf("Showing all patients data ...\n");
    for (i = 0; i < pt_count; i++)
    {
        printf("Patient %d data:\n", i+1);
        printf("ID = %d\n", pt_data[i].id);
        printf("Name = %s\n", pt_data[i].name);
        printf("Bill = %.2f tk\n", pt_data[i].bill);
    }
    printf("--------\n");
}

void search_by_ID()
{
    int i, ID;
    printf("Enter the ID of the patient: ");
    scanf("%d", &ID);
    for (i = 0; i < pt_count; i++)
    {
        if(ID == pt_data[i].id)
            break;
    }
    if (i < pt_count)
    {
        printf("patient %d data:\n", i+1);
        printf("ID = %d\n", pt_data[i].id);
        printf("Name = %s\n", pt_data[i].name);
        printf("Bill = %.2f tk\n", pt_data[i].bill);
    }
    else
    {
        printf("ID %d not found\n", ID);
    }
}
void update()
{
    int i, ID;
    double up_bill;
    printf("Enter the ID of the patient: ");
    scanf("%d", &ID);
    printf("Enter the Updated Bill of the patient: ");
    scanf("%lf", &up_bill);
    for (i = 0; i < pt_count; i++)
    {
        if(ID == pt_data[i].id)
            break;
    }
    pt_data[i].bill = up_bill;

    FILE *fp = fopen("project.txt", "w");
    fprintf(fp, "%d\n", pt_count);
    for(i = 0; i < pt_count; i++)
    {
        fprintf(fp, "%d\n", pt_data[i].id);
        fprintf(fp, "%s\n", pt_data[i].name);
        fprintf(fp, "%lf\n", pt_data[i].bill);
    }
    fclose(fp);
}
void health_insurance()
{
    int i, ID, per;
    printf("Enter the ID of the patient: ");
    scanf("%d", &ID);
    printf("Enter the Percentage of the Health Insurance: ");
    scanf("%d", &per);
    for (i = 0; i < pt_count; i++)
    {
        if(ID == pt_data[i].id)
            break;
    }
    pt_data[i].bill = pt_data[i].bill - (pt_data[i].bill * per)/100;

    FILE *fp = fopen("project.txt", "w");
    fprintf(fp, "%d\n", pt_count);
    for(i = 0; i < pt_count; i++)
    {
        fprintf(fp, "%d\n", pt_data[i].id);
        fprintf(fp, "%s\n", pt_data[i].name);
        fprintf(fp, "%lf\n", pt_data[i].bill);
    }
    fclose(fp);
}
void Delete()
{
    int i, j, ID;
    printf("Enter the ID of the patient: ");
    scanf("%d", &ID);
    for (i = 0; i < pt_count; i++)
    {
        if(ID == pt_data[i].id)
            break;
    }
    for (j = i; j < pt_count-1; j++)
    {
        pt_data[j] = pt_data[j+1];
    }
    pt_count--;

    FILE *fp = fopen("project.txt", "w");
    fprintf(fp, "%d\n", pt_count);
    for(i = 0; i < pt_count; i++)
    {
        fprintf(fp, "%d\n", pt_data[i].id);
        fprintf(fp, "%s\n", pt_data[i].name);
        fprintf(fp, "%lf\n", pt_data[i].bill);
    }
    fclose(fp);
}
void add()
{
    input_data();
    FILE *fp = fopen("project.txt", "w");
    fprintf(fp, "%d\n", pt_count);
    for(int i = 0; i < pt_count; i++)
    {
        fprintf(fp, "%d\n", pt_data[i].id);
        fprintf(fp, "%s\n", pt_data[i].name);
        fprintf(fp, "%lf\n", pt_data[i].bill);
    }
    fclose(fp);
}
void sorting()
{
    struct pt_info temp;
    int str, i, j;
    printf("\n *** Sorting INFO ***\n");
    printf("1: Sorting By Id\n");
    printf("2: Sorting By Bill\n");
    printf("3: Sorting by Name\n");
    scanf("%d", &str);
    if(str == 1)
    {
        read_data();
        for(i = 0; i<pt_count; i++)
        {
            for(j = i+1; j<pt_count; j++)
            {
                if(pt_data[i].id > pt_data[j].id)
                {
                    temp = pt_data[i];
                    pt_data[i] = pt_data[j];
                    pt_data[j] = temp;
                }
            }
        }
        FILE *fp = fopen("project.txt", "w");
        fprintf(fp, "%d\n", pt_count);
        for(i = 0; i < pt_count; i++)
        {
            fprintf(fp, "%d\n", pt_data[i].id);
            fprintf(fp, "%s\n", pt_data[i].name);
            fprintf(fp, "%lf\n", pt_data[i].bill);
        }
        fclose(fp);
    }
    else if(str == 2)
    {
        read_data();
        for(i = 0; i<pt_count; i++)
        {
            for(j = i+1; j<pt_count; j++)
            {
                if(pt_data[i].bill > pt_data[j].bill)
                {
                    temp = pt_data[i];
                    pt_data[i] = pt_data[j];
                    pt_data[j] = temp;
                }
            }
        }
        FILE *fp = fopen("project.txt", "w");
        fprintf(fp, "%d\n", pt_count);
        for(i = 0; i < pt_count; i++)
        {
            fprintf(fp, "%d\n", pt_data[i].id);
            fprintf(fp, "%s\n", pt_data[i].name);
            fprintf(fp, "%lf\n", pt_data[i].bill);
        }
        fclose(fp);
    }
    else if(str == 3)
        {
            read_data();
            for(i = 0; i<pt_count; i++)
            {
                for(j = i+1; j<pt_count; j++)
                {
                    if(strcmp(pt_data[i].name , pt_data[j].name) > 0)
                    {
                        temp = pt_data[i];
                        pt_data[i] = pt_data[j];
                        pt_data[j] = temp;
                    }
                }
            }
            FILE *fp = fopen("project.txt", "w");
            fprintf(fp, "%d\n", pt_count);
            for(i = 0; i < pt_count; i++)
            {
                fprintf(fp, "%d\n", pt_data[i].id);
                fprintf(fp, "%s\n", pt_data[i].name);
                fprintf(fp, "%lf\n", pt_data[i].bill);
            }
            fclose(fp);
        }

}
int main()
{
    int choice = 1;
    pt_count = 0;
    while (choice)
    {
        show_menu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                read_data();
                break;
            case 2:
                show_all();
                break;
            case 3:
                search_by_ID();
                break;
            case 4:
                update();
                break;
            case 5:
                health_insurance();
                break;
            case 6:
                Delete();
                break;
            case 7:
                add();
                break;
            case 8:
                sorting();
                break;
            case 0:
                break;
        }
    }
    return 0;
}
