#include <stdio.h>
#include <stdbool.h>
#include "classroom_arrangement.h"
#define MAX_CLASSNUM 500
#define MAX_COURSENUM 1000

typedef struct {    
    int course_count;
    int course_list[MAX_COURSENUM+5];
} ListOfCourse;

bool is_overlap(struct Course course, struct Course oldCourse){
    if(course.day != oldCourse.day) return false;
    return !(course.end.hour < oldCourse.start.hour ||
            (course.end.hour == oldCourse.start.hour && course.end.minute < oldCourse.start.minute) ||
             oldCourse.end.hour < course.start.hour ||
            (oldCourse.end.hour == course.start.hour && oldCourse.end.minute < course.start.minute));
}

void class_arrangement(int classnum, int coursenum, struct Classroom classrooms[], struct Course courses[]){
    ListOfCourse courseList[MAX_CLASSNUM+5] = {};

    for(int i = 0; i < coursenum; i++){
        struct Course course = courses[i];
        for(int j = 0; j < classnum; j++){
            ListOfCourse *list = &courseList[j];
            bool overlapped = false;
            if(classrooms[j].capacity >= course.number_of_students){
                for(int k = 0; k < list->course_count; k++){
                    if(is_overlap(course, courses[list->course_list[k]])){
                        overlapped = true;
                        break;
                    }      
                }
                if(!overlapped){
                    list->course_list[list->course_count] = i;
                    list->course_count++;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < classnum; i++){
        ListOfCourse *list = &courseList[i];
        for(int j = list->course_count - 1; j > 0; j--){
            for(int k = 0; k < j; k++){
                struct Time t1 = courses[list->course_list[k]].start;
                struct Time t2 = courses[list->course_list[k+1]].start;
                if(courses[list->course_list[k]].day > courses[list->course_list[k+1]].day
                || ((courses[list->course_list[k]].day == courses[list->course_list[k+1]].day) && (t1.hour * 60 + t1.minute > t2.hour * 60 + t2.minute))){
                    int tmp = list->course_list[k];
                    list->course_list[k] = list->course_list[k+1];
                    list->course_list[k+1] = tmp;
                }
            }
        }
    }

    for(int i = 0; i < classnum; i++){
        printf("%s :", classrooms[i].name);
        ListOfCourse list = courseList[i];
        for(int j = 0; j < list.course_count; j++){
            printf(" %s", courses[list.course_list[j]].id);
        }
        printf("\n");
    }
}