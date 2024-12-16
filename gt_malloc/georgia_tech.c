#include "georgia_tech.h"

Course** courses;
int courses_size, courses_capacity;
/**
 * Initializes a list for members of a course using malloc
 * to allocate space in heap to store data.
 *
 * @param capacity the initial capacity of courses list
 *
 * @return ERROR upon malloc failure or other
 */
int init_courses(int capacity) {
  if (capacity < 1) {
    return ERROR;
  }

  // use malloc to create space in heap for data
  courses = (Course**)malloc(capacity * sizeof(Course*));

  // need to check for malloc failure
  if (courses == NULL) {
    return ERROR;
  }
  courses_size = 0;
  courses_capacity = capacity;
  return SUCCESS;
}

/**
 * Creates a course to add to the courses array.
 * 
 * @param name the name of the course
 * 
 * @return ERROR upon malloc failure or other
 */
int create_course(char* name) {
  // check for invalid arguments
  if (courses == NULL || name == NULL) {
    return ERROR;
  }

  // expand size in heap with realloc if needed
  if (courses_size >= courses_capacity) {
    Course* new_courses =
        (Course*)realloc(courses, (courses_capacity * 2) * sizeof(Course));
    if (new_courses == NULL) {
      return ERROR;
    }
    courses = new_courses;
    courses_capacity *= 2;
  }

  // create new course node
  Course* course = (Course*)malloc(sizeof(Course));
  if (course == NULL) {
    return ERROR;
  }

  // create new name in course 
  course->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
  if (course->name == NULL) {
    free(course);
    return ERROR;
  }

  // add data to course and course to courses
  strcpy(course->name, name);
  course->head = NULL;
  courses[courses_size] = course;
  courses_size++;
  return SUCCESS;
}

/**
 * Creates and adds profile to linked list in given course.
 * 
 * @param name the name of member
 * @param status the status of member
 * @param course the course to add member to
 * 
 * @return ERROR upon malloc failure or other
 */
int create_profile(char* name, Status status, Course* course) {
    // check for invalid arguments
    if (name == NULL || status == NULL || course == NULL) {
        return ERROR;
    }

    // create new profile node
    Profile* profile = (Profile*) malloc(sizeof(Profile));
    if (profile == NULL) {
        return ERROR;
    }

    // allocate space for name
    profile->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
    if (name == NULL) {
        free(profile);
        return ERROR;
    }

    // add profile to linked list in given course
    strcpy(profile->name, name);
    profile->status = status;
    Profile* current = course->head;
    if (course->head == NULL) {
        course->head = profile;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = profile;
    }
    return SUCCESS;
}

