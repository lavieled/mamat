//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"

#define SUCCESS 0
#define FAIL -1
#define TRUE 1
#define FALSE 0
  
struct grades{
  struct list *student_list;
};
struct course{
  char *course_name;
  int grade;
};
struct student{
  char *student_name;
  int student_id;
  struct list *course_list;
  int avg;
  int num_courses;
};

//user functions for linked list adt

void student_init(){
  
}

int student_clone(void *element, void **output){
  //first we check the validity of the object we want to clone
  if (element == NULL){
    return FAIL;
  }
  //if the object is valid we clone it, using casting
  struct student* new_student;
  new_student = (struct student*) element;
  //set the new struct's fields - name and id
  *output = student_init(new_student->student_name, new_student->id);
  //we check that it was done successfully
  if (*output==NULL){
    return FAIL;
  }
  return SUCCESS;
}

void student_destroy(void *element){
  //first we check the validity of the object we want to destroy
  if (element == NULL){
    return FAIL;
  }
  //if the object is valid we destroy it, using casting
  struct student* new_student;
  new_student = (struct student*) element;
  //We free all the allocations that were done in the process
  free(student->student_name);
  list_destroy(student->course_list);
  free(student);
}

/*not sure if need
int grades_clone((void *elemnt, void **output){

}
*/


int course_clone((void *elemnt, void **output){

}

void course_destroy(void *element){

}

void course_init(){

}

//grades functions for operating
/*
 * @brief Initializes the "grades" data-structure.
 * @returns A pointer to the data-structure, of NULL in case of an error
 */
/*
*@brief initialize "grades" struct, allocate memory
*/
void grades_init(){
  
}
/**
 * @brief Destroys "grades", de-allocate all memory!
 */
void grades_destroy(struct grades *grades){

}
/**
 * @brief Adds a student with "name" and "id" to "grades"
 * @returns 0 on success
 * @note Failes if "grades" is invalid, or a student with 
 * the same "id" already exists in "grades"
 */
int grades_add_student(struct grades *grades, const char *name, int id){

}
/**
 * @brief Adds a course with "name" and "grade" to the student with "id"
 * @return 0 on success
 * @note Failes if "grades" is invalid, if a student with "id" does not exist
 * in "grades", if the student already has a course with "name", or if "grade"
 * is not between 0 to 100.
 */
int grades_add_grade(struct grades *grades,
                     const char *name,
                     int id,
                     int grade){

}

/**
 * @brief Calcs the average of the student with "id" in "grades".
 * @param[out] out This method sets the variable pointed by "out" to the
 * student's name. Needs to allocate memory. The user is responsible for
 * freeing the memory.
 * @returns The average, or -1 on error
 * @note Fails if "grades" is invalid, or if a student with "id" does not exist
 * in "grades".
 * @note If the student has no courses, the average is 0.
 * @note On error, sets "out" to NULL.
 */
float grades_calc_avg(struct grades *grades, int id, char **out){

}

/**
 * @brief Prints the courses of the student with "id" in the following format:
 * STUDENT-NAME STUDENT-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @returns 0 on success
 * @note Fails if "grades" is invalid, or if a student with "id" does not exist
 * in "grades".
 * @note The courses should be printed according to the order 
 * in which they were inserted into "grades"
 */
int grades_print_student(struct grades *grades, int id){

}

/**
 * @brief Prints all students in "grade", in the following format:
 * STUDENT-1-NAME STUDENT-1-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * STUDENT-2-NAME STUDENT-2-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @returns 0 on success
 * @note Fails if "grades" is invalid
 * @note The students should be printed according to the order 
 * in which they were inserted into "grades"
 * @note The courses should be printed according to the order 
 * in which they were inserted into "grades"
 */
int grades_print_all(struct grades *grades){

}



