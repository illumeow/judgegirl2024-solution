#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int hour;
  int minute;
} Time;

typedef struct {
    Time start;
    Time end;
    int number_of_students;
    int day; // 1: Monday, 2: Tuesday, 3: Wednesday, 4: Thursday, 5: Friday
} Course;

typedef struct {    
    int course_count;
    int course_list[45];
} ListOfCourse;

bool is_overlap(Course course, Course oldCourse){
    if(course.day != oldCourse.day) return false;
    return !(course.end.hour < oldCourse.start.hour ||
            (course.end.hour == oldCourse.start.hour && course.end.minute < oldCourse.start.minute) ||
             oldCourse.end.hour < course.start.hour ||
            (oldCourse.end.hour == course.start.hour && oldCourse.end.minute < course.start.minute));
}

int compute_time(Course c){
    return ((c.end.hour*60+c.end.minute)-(c.start.hour*60+c.start.minute)+1);
}

void solve(int idx, int classrooms[], int n, Course courses[], int m, ListOfCourse list[], int nowtime, int remaining_time, int *maxtime, int best[], int *best_sum){
    // printf("%d\n", idx);
    if(nowtime + remaining_time < *maxtime) return;
    if(idx == m){
        if(nowtime > *maxtime){
            *maxtime = nowtime;
            *best_sum = 0;
            for(int i = 0; i < n; i++){
                best[i] = list[i].course_count;
                *best_sum += list[i].course_count;
            }
                
            #ifdef DEBUG
            for(int i = 0; i < n; i++){
                printf("%d : ", i);
                ListOfCourse *cur_list = &list[i];
                for(int j = 0; j < cur_list->course_count; j++){
                    printf("%d ", cur_list->course_list[j]);
                }
                printf("\n");
            }
            printf("max : %d\n", nowtime);
            #endif
        }
        return;
    }

    int time = compute_time(courses[idx]);
    for(int i = 0; i < n; i++){
        if(classrooms[i] >= courses[idx].number_of_students){
            ListOfCourse *cur_list = &list[i];
            bool overlapped = false;
            for(int j = 0; j < cur_list->course_count && !overlapped; j++)
                if(is_overlap(courses[idx], courses[cur_list->course_list[j]]))
                    overlapped = true;
                
            if(!overlapped){
                cur_list->course_list[cur_list->course_count] = idx;
                cur_list->course_count++;
                solve(idx+1, classrooms, n, courses, m, list, nowtime+time, remaining_time-time, maxtime, best, best_sum);
                cur_list->course_list[cur_list->course_count] = -1;
                cur_list->course_count--;
            }
        }
    }
    solve(idx+1, classrooms, n, courses, m, list, nowtime, remaining_time-time, maxtime, best, best_sum);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int classrooms[8];
    Course courses[40];
    for(int i = 0; i < n; i++) scanf("%d", &classrooms[i]);
    for(int i = 0; i < m; i++) scanf("%d %d %d %d %d %d", &courses[i].start.hour, &courses[i].start.minute, &courses[i].end.hour, &courses[i].end.minute, &courses[i].number_of_students, &courses[i].day);
    
    int total_time = 0;
    for(int i = 0; i < m; i++){
        #ifdef DEBUG
        printf("%d : %d\n", i, compute_time(courses[i]));
        #endif
        total_time += compute_time(courses[i]);
    }
    

    ListOfCourse list[8] = {};
    int best[8] = {};
    int maxtime = 0, best_sum = 0;
    solve(0, classrooms, n, courses, m, list, 0, total_time, &maxtime, best, &best_sum);
    printf("%d\n", maxtime);
    printf("%d\n", best_sum);
    for(int i = 0; i < n; i++)
        printf("%d\n", best[i]);
}