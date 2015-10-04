#include<stdio.h>
#include<stdlib.h>

typedef struct Student{
	int age;
	char name[10];
	void (* printA)(int , struct Student *);
	char * chars;
}Student;

void setAge(int a, Student * stuPtr){
	stuPtr->age = a;
}

int main(){
	Student student;
	student.chars = (char *)malloc(10 * sizeof(char));
	student.printA = setAge;
	student.printA(100, &student);
	printf("%d\n", student.age);
	printf("%ld\n", sizeof(student.chars));
	return 0;
}
