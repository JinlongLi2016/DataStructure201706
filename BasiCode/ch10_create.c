
#define LEN sizeof(struct student)
struct student
{
	long number;
	char name[20];
	float gpa;
	struct student *pNext;
};

int count = 0;
struct student *create(void)
{
	struct student *pHead = NULL, *pNew, *pTail;
	pNew = pTail = (struct student*)malloc(LEN);

	printf("Please input idnum, name, gpa value:\n");
	do{
		scanf("%ld%s%f", &pNew->number, &pNew->name, &pNew->gpa);
		count++;
		if(count ==1)	pHead = pNew;
		else	
	}
}