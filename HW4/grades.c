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
#define MAX_GRADE 100
#define MIN_GRADE 0

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

/*
 * @brief clones a string.
 * @param str a pointer to the string we want to clone.
 * @returns a pointer to the cloned string, or NULL in case of an error.
 */

char * clone_str(const char* str){
    //first we check that the string we received is not empty
    if (str == NULL){
      return NULL;
    }
    //if it is not empty then we want to clone it
    len=strlen(str)+1;
    char * clone = (char*)malloc(len*sizeof(char));
    //check that the allocation succeeded
    if (clone == NULL){
      //it failed
      return NULL;
    }
  else{
    //it succeded, we copy the string
    strcpy(clone, str);
  }
  return clone;
}

//user functions for linked list adt

//**********student struct**********//

/*
 * @brief Initializes the "student" data-structure.
 * @param student_name pointer to the name.
 * @param id id number of a student.
 * @returns a pointer to the student struct, or NULL in case of an error.
 */

struct student *student_init(const char* student_name, int id){
    //first we check that the id and the name are valid
    if (id < 0 || student_name == NULL){
      //the parameters are invalid
      return NULL;
    }
    //the parameters are valid, so we create the struct's parts
    struct student* new_student = 
                  (struct student*)malloc(sizeof(struct student));
    //we check that the allocation succeeded
    if (new_student == NULL){
      //the allocation didn't succeed
      return NULL;
    }
    struct list* course_list = list_init(course_clone, course_destroy);
     //we check that the a list was created
    if (course_list == NULL){
      //there was a problem, so we free the allocated space
      free(new_student)
      return NULL;
    }
    new_student->student_name=clone_str(student_name);
    //we check that it succeeded
    if ( new_student->student_name == NULL){
      //it failed, we want to free the allocated memory
      free(new_student);
      free(course_list);
      return NULL;
    }
    //it succeeded
    new_student->num_courses=0;
    new_student->avg=0;
    new_student->id=id;
    new_student->course_list=course_list;
  return new_student;
  }

/*
 * @brief clones the "student" data-structure.
 * @param element a pointer to the student's name.
 * @param output a pointer to the struct's pointer.
 * @returns SUCCESS if the cloning succeeded, or FAIL in case it didn't.
 */

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

/*
 * @brief removes the "student" data-structure.
 * @param element a pointer to the student's name.
 */

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

//**********course struct**********//

/*
 * @brief Initializes the "course" data-structure.
 * @param course_name pointer to the course's name.
 * @param grade the grade that the student received in the course.
 * @returns a pointer to the course struct, or NULL in case of an error.
 */

struct course* course_init(const char *course_name, int grade){
if(course_name == NULL || grade < MIN_GRADE || grade > MAX_GRADE){
  return NULL;
  struct course *new_course;
  new_course = (struct course*)malloc(sizeof(struct course));
  if(new_course == NULL){
    return NULL;
  }
  
  /*
  check if the strcpy works, or if need an aux func for copying course name
  */
  
  char* new_course->course_name = (char*)malloc(strlen(course_name));
  if(new_course->course_name == NULL){
    return NULL;
  }
  strcpy(new_course->course_name, course_name);
  new_course->grade = grade;
  return new_course;
}

/*
 * @brief clones the "course" data-structure.
 * @param element a pointer to the course's name.
 * @param output a pointer to the struct's pointer.
 * @returns SUCCESS if the cloning succeeded, or FAIL in case it didn't.
 */

int course_clone(void *element, void **output){
  //first we check the validity of the object we want to clone
    if (element == NULL){
      return FAIL;
    }
    //if the object is valid we clone it, using casting
    struct course* new_course;
    new_course = (struct course*) element;
    //set the new struct's fields - name and id
    *output = course_init(new_course->course_name, new_course->grade);
    //we check that it was done successfully
    if (*output==NULL){
      return FAIL;
    }
  return SUCCESS;
}

/*
 * @brief removes the "course" data-structure.
 * @param element a pointer to the course's name.
 */

void course_destroy(void *element){
  //first we check the validity of the object we want to destroy
      if (element == NULL){
        return FAIL;
      }
      //if the object is valid we destroy it, using casting
      struct course* new_course;
      new_course = (struct course*) element;
      //We free all the allocations that were done in the process
      free(course->course_name);
      free(student);
}

//grades functions for operating
/*
 * @brief Initializes the "grades" data-structure.
 * @returns A pointer to the data-structure, of NULL in case of an error
 */

/*
*@brief initialize "grades" struct, allocate memory
*/

struct grades* grades_init(){
  struct grades *new_grades;
  struct list *student_list ;
  new_grades = (struct grades*)malloc(sizeof(struct grades));
  if(new_grades == NULL) return NULL;
  student_list = list_init(int student_clone, void student_destroy);
  if(student_list == NULL) return NULL;
  new_grades->student_list = student_list;
  return new_grades;
}

/**
 * @brief Destroys "grades", de-allocate all memory!
 */

void grades_destroy(struct grades *grades){
  if(grades == NULL) return;
  list_destroy(grades->student_list);
  free(grades);
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



