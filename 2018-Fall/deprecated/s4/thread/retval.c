#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// student represents a collegian
struct student {
	int number;
	char* name;
};

// print_student is a function that is called by pthread within a new thread.
// this function prints student information.
void *print_student(void *input) {
	struct student *std = (struct student *)input;
	printf("Hello %s! Your student ID is %d\n", std->name, std->number);

	pthread_exit((void *)10l);
}

int main() {
  // defines a student
	struct student parham;
	parham.number = 9231058;
	parham.name = "Parham";

	pthread_t thread;

	pthread_create(&thread, NULL, print_student, (void *)&parham);

	void *retval;

	pthread_join(thread, &retval);
	printf("Exit: %ld\n", (long)retval);
}
