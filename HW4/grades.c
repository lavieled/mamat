//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"
#include "linked-list.h"

#define SUCCESS 0
#define FAILED -1
#define MAX_GRADE 100
#define MIN_GRADE 0


//the overall grades struct the user will use in our adt
struct grades{
    struct list *student_list;
};
//course struct for course name and grades
struct course{
    char *course_name;
    int grade;
};
//student struct to hold courses list, name, id, and average
struct student{
    char *student_name;
    int student_id;
    struct list *course_list;
    float avg;
    float num_courses;
};

//functions declaration
void print_student_aux(struct student *tmp_student);
int student_clone(void *element, void **output);
int course_clone(void *element, void **output);
void student_destroy(void *element);
void course_destroy(void *element);
struct course* course_init(const char *course_name, int grade);
struct student *student_init(const char *student_name, int id);

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
    char * clone = (char*)malloc(sizeof(char)*(strlen(str) + 1));
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

//**********course struct**********//

/*
 * @brief clones the "course" data-structure.
 * @param element a pointer to the course's name.
 * @param output a pointer to the struct's pointer.
 * @returns SUCCESS if the cloning succeeded, or FAILED in case it didn't.
 */

int course_clone(void *element, void **output) {
    //first we check the validity of the object we want to clone
    if (element == NULL) {
        return FAILED;
    }
    //if the object is valid we clone it, using casting
    struct course *new_course;
    new_course = (struct course *) element;
    //set the new struct's fields - name and id
    *output = course_init(new_course->course_name, new_course->grade);
    //we check that it was done successfully
    if (*output == NULL) {
        return FAILED;
    }
    return SUCCESS;
}

/*
 * @brief removes the "course" data-structure.
 * @param element a pointer to the course's name.
 */

void course_destroy(void *element) {
    //first we check the validity of the object we want to destroy
    if (element == NULL) {
        return;
    }
    //if the object is valid we destroy it, using casting
    struct course *new_course;
    new_course = (struct course *) element;
    //We free all the allocations that were done in the process
    free(new_course->course_name);
    free(new_course);
}

/*
 * @brief Initializes the "course" data-structure.
 * @param course_name pointer to the course's name.
 * @param grade the grade that the student received in the course.
 * @returns a pointer to the course struct, or NULL in case of an error.
 */
struct course* course_init(const char *course_name, int grade) {
    if (course_name == NULL || grade < MIN_GRADE || grade > MAX_GRADE) {
        return NULL;
    }
    struct course *new_course;
    new_course = (struct course *) malloc(sizeof(struct course));
    if (new_course == NULL) {
        return NULL;
    }
    /*check
    new_course->course_name =
     (char *) malloc(sizeof(char)*strlen(course_name)+1);
    if (new_course->course_name == NULL) {
        return NULL;
    }
    strcpy(new_course->course_name, course_name);
     */
    new_course->course_name = clone_str(course_name);
    new_course->grade = grade;
    return new_course;
}

//user functions for linked list adt

//**********student struct**********//

/*
 * @brief clones the "student" data-structure.
 * @param element a pointer to the student's name.
 * @param output a pointer to the struct's pointer.
 * @returns SUCCESS if the cloning succeeded, or FAILED in case it didn't.
 */

int student_clone(void *element, void **output) {
    //first we check the validity of the object we want to clone
    if (element == NULL) {
        return FAILED;
    }
    //if the object is valid we clone it, using casting
    struct student *new_student;
    new_student = (struct student *) element;
    //set the new struct's fields - name and id
    *output = student_init(new_student->student_name,
                           new_student->student_id);
    //we check that it was done successfully
    if (*output == NULL) {
        return FAILED;
    }
    return SUCCESS;
}

/*
 * @brief removes the "student" data-structure.
 * @param element a pointer to the student's name.
 */

void student_destroy(void *element) {
    //first we check the validity of the object we want to destroy
    if (element == NULL) {
        return;
    }
    //if the object is valid we destroy it, using casting
    struct student *new_student;
    new_student = (struct student *) element;
    //We free all the allocations that were done in the process
    free(new_student->student_name);
    list_destroy(new_student->course_list);
    free(new_student);
}

/**
 * @brief Search if id already exists in students list
 * @param student_list students list to search at
 * @param id id to search for at the list
 * @returns the student struct if found, NULL otherwise
 */
struct student *check_student(struct list *student_list, int id) {
    //check if list is empty or illegal id
    if (student_list == NULL || id < 0) {
        return NULL;
    }
    struct iterator *it;
    it = list_begin(student_list);
    //loop to look for the student in the list
    while (it) {
        struct student *student = list_get(it);
        if (student->student_id == id) return student;
        it = list_next(it);
    }
//student not in list
    return NULL;
}
/*
 * @brief Initializes the "student" data-structure.
 * @param student_name pointer to the name.
 * @param id number of a student.
 * @returns a pointer to the student struct, or NULL in case of an error.
 */

struct student *student_init(const char *student_name, int id) {
    //first we check that the id and the name are valid
    if (id < 0 || student_name == NULL) {
        //the parameters are invalid
        return NULL;
    }
    //the parameters are valid, so we create the struct's parts
    struct student *new_student =
            (struct student *) malloc(sizeof(struct student));
    //we check that the allocation succeeded
    if (new_student == NULL) {
        //the allocation didn't succeed
        return NULL;
    }
    //We initialize the course list of the new student.
    new_student->course_list = list_init(course_clone, course_destroy);
    //We check that the list was created
    if (new_student->course_list == NULL) {
        //there was a problem, so we free the allocated space
        free(new_student);
        return NULL;
    }
    new_student->student_name = clone_str(student_name);
    //we check that it succeeded
    if (new_student->student_name == NULL) {
        //it failed, we want to free the allocated memory
        list_destroy(new_student->course_list);
        free(new_student);

        return NULL;
    }
    //it succeeded
    new_student->num_courses = 0;
    new_student->avg = 0;
    new_student->student_id = id;
    return new_student;
}

/*
 * @brief checks if a course with the same name already exists.
 * @param course_list pointer to a student's course list.
 * @param course_name the name of the course we want to check.
 * @returns a pointer to the course struct if it exists,
 * or NULL in case there is no such course, or the name is invalid.
 */

struct course *check_course(struct list *course_list,const char *course_name) {
    if (course_list == NULL || course_name == NULL) {
        //The list doesn't exist, or the name is invalid.
        return NULL;
    }
    //The course and the list are valid - we want to search the list
    //and see if it exists.
    struct iterator *it;
    it = list_begin(course_list);
    while (it) {
        struct course *tmp_course = list_get(it);
        if (tmp_course->course_name == course_name) {
            return tmp_course;
        }
        it = list_next(it);
    }
    //There is no such course in the list.
    return NULL;
}

//grades functions for operating
/*
 * @brief Initializes the "grades" data-structure.
 * @returns A pointer to the data-structure, of NULL in case of an error
 */

/*
*@brief initialize "grades" struct, allocate memory
*/

struct grades *grades_init() {
    struct grades *new_grades;
    struct list *student_list;
    new_grades = (struct grades *) malloc(sizeof(struct grades));
    if (new_grades == NULL) return NULL;
    student_list = list_init(student_clone, student_destroy);
    if (student_list == NULL) return NULL;
    new_grades->student_list = student_list;
    return new_grades;
}

/**
 * @brief Destroys "grades", de-allocate all memory!
 */

void grades_destroy(struct grades *grades) {
    if (grades == NULL) return;
    list_destroy(grades->student_list);
    free(grades);
}

/**
 * @brief Adds a student with "name" and "id" to "grades"
 * @returns 0 on success
 * @note Failes if "grades" is invalid, or a student with
 * the same "id" already exists in "grades"
 */

int grades_add_student(struct grades *grades, const char *name, int id) {
    //First we check that the struct, the name and id are valid
    if (grades == NULL || name == NULL || id < 0) {
        //the struct, name or id is invalid
        return FAILED;
    }
    if (check_student(grades->student_list, id) != NULL) {
        //The student already exists, so we don't add him.
        return FAILED;
    }
    //The student doesn't exist, so we create a temporary struct
    //and add him to the list under the name tmp_student,
    //and check the validity of the push.
    struct student *tmp_student = student_init(name, id);
    if (tmp_student == NULL) {
        //The creation wasn't successful.
        return FAILED;
    }
    int tmp = list_push_back(grades->student_list, tmp_student);
    //Check that the student was added succesfully
    if (tmp != SUCCESS) {
        student_destroy(tmp_student);
        //The push didn't succeed.
        return FAILED;
    }
    student_destroy(tmp_student);
    return SUCCESS;
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
                     int grade) {
    //check if grades is empty or illegal id, empty name, illegal grade
    if (grades == NULL || id < 0 || name == NULL
        || grade > MAX_GRADE || grade < MIN_GRADE) {
        return FAILED;
    }
    struct student *student = check_student(grades->student_list, id);
    //check if student exists
    if (student == NULL) {
        return FAILED;
    }
    //check if course already exists
    if (check_course(student->course_list, name)) {
        return FAILED;
    }
    struct course *new_course;
    new_course = course_init(name, grade);
    //check course was created
    if (new_course == NULL) {
        return FAILED;
    }
    //add new course to list, check if fails
    int result = list_push_back(student->course_list, new_course);
    if (result != SUCCESS) {
        course_destroy(new_course);
        return FAILED;
    }
    course_destroy(new_course);
    //update new avg based on old avg, num of courses taken and new grade
    float sum_tot = (((float) student->num_courses * student->avg) + (float) grade);
    student->num_courses++;
    student->avg = sum_tot / student->num_courses;
    return SUCCESS;
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
float grades_calc_avg(struct grades *grades, int id, char **out) {
    if (grades == NULL) {
        *out = NULL;
        return FAILED;
    }
    struct student *student;
    student = check_student(grades->student_list, id);
    //check if student exists
    if (student == NULL) {
        *out = NULL;
        return FAILED;
    }
    char *name = (char *) malloc(strlen
            (student->student_name)* sizeof(char));
    if (name == NULL) {
        *out = NULL;
        return FAILED;
    }
    name = clone_str(student->student_name);
    *out = name;
    return (student->avg);
}
//prints the student
void print_student_aux(struct student *tmp_student){
    //At the beginning we print the student's name and id
    printf("%s %d:", tmp_student->student_name,
           tmp_student->student_id);
    //incase of no courses, down line and countinue
    if(tmp_student->num_courses == 0){
        printf("\n");
        return;
    }
    //We create an iterator that begins at the head of the list "runs"
    //on the student's courses.
    struct iterator *it;
    it = list_begin(tmp_student->course_list);
    //check if iterator is on list
    if (it == NULL) {
        return;
    }
    //As long as we didn't get to the end of the list, we print the info.
    //create a pointer to print courses
    struct course *tmp_course;
    tmp_course = list_get(it);
    for(float i = 1; i < tmp_student->num_courses; i++){
        printf(" %s %d,", tmp_course->course_name,
               tmp_course->grade);
        it = list_next(it);
        tmp_course = list_get(it);
    }
    printf(" %s %d\n", tmp_course->course_name,
           tmp_course->grade);
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

int grades_print_student(struct grades *grades, int id) {
    //First we check that the struct and id are valid
    if (grades == NULL || id < 0) {
        //The struct or id is invalid
        return FAILED;
    }
    //We make a temp student struct to work with
    struct student *tmp_student;
    tmp_student = check_student(grades->student_list, id);
    //check if student exists
    if (tmp_student == NULL) {
        return FAILED;
    }
    print_student_aux(tmp_student);
    return SUCCESS;
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

int grades_print_all(struct grades *grades) {
    if (grades == NULL) {
        return FAILED;
    }
    struct iterator *it;
    struct student *tmp_student;
    it = list_begin(grades->student_list);
    while (it) {
        tmp_student = list_get(it);
        print_student_aux(tmp_student);
        it = list_next(it);
    }
    return SUCCESS;
}
