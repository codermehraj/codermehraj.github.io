#include <stdio.h>

#define MX_SIZE 100000

typedef struct student{
    int NumberOfProblemSolved, RegNumber;
    double cgpa;
};

// returns 1 if A < B else 0
int cmp(struct student A, struct student B){
    if(A.NumberOfProblemSolved == B.NumberOfProblemSolved){
        if(A.cgpa == B.cgpa){
            // registration number less is expected
            if(A.RegNumber > B.RegNumber) return 1;
            return 0;
        }
        // cgpa more is expected
        if(A.cgpa < B.cgpa) return 1;
        return 0;
    }
    // Number of Problem solved more is expected
    if(A.NumberOfProblemSolved < B.NumberOfProblemSolved) return 1;
    return 0;
}

void bubble_sort(struct student DATA[], int N)
{
    int PTR, K;
    struct student temp;
    for (K = 1; K < N; K++)
    {
        for (PTR = 0; PTR < (N - K); PTR++)
        {
            // comaprison
            if (cmp(DATA[PTR] , DATA[PTR + 1])==1)
            {
                // interchange
                temp = DATA[PTR];
                DATA[PTR] = DATA[PTR + 1];
                DATA[PTR + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i; // n = number of students
    int reg, prblmslved;
    double cg;

    printf("\n\n\tEnter the number of students : ");
    scanf("%d",&n);

    struct student ar[n];

    printf("\nEnter the information of %d students in following format: \n",n);
    printf("<Registration_Number>  <Number_of_solved_problems> <Cgpa>\n\n");

    for(i=0;i<n;i++){
        scanf("%d%d%lf",&reg,&prblmslved,&cg);
        ar[i].RegNumber = reg;
        ar[i].NumberOfProblemSolved = prblmslved;
        ar[i].cgpa = cg;
    }

    // using bubble sort to sort the dataset
    bubble_sort(ar, n);

    printf("\n After Sorting the list is as follows : \n\n");
    for(i=0;i<n;i++){
        printf("\t%d\t%d\t%lf\n",ar[i].RegNumber,ar[i].NumberOfProblemSolved,ar[i].cgpa);
    }
    return 0;
}
