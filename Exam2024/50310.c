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
    int day;  // 1: Monday, 2: Tuesday, 3: Wednesday, 4: Thursday, 5: Friday
} Course;

typedef struct {    
    int course_count;
    int course_list[45];
} ListOfCourse;

bool is_overlap(Course *course, Course *oldCourse){
    return !(course->end.hour < oldCourse->start.hour ||
            (course->end.hour == oldCourse->start.hour && course->end.minute < oldCourse->start.minute) ||
             oldCourse->end.hour < course->start.hour ||
            (oldCourse->end.hour == course->start.hour && oldCourse->end.minute < course->start.minute));
}

int compute_time(Course *c){
    return ((c->end.hour*60+c->end.minute)-(c->start.hour*60+c->start.minute)+1);
}

bool check(int best[], ListOfCourse list[], int n){
    for(int i = 0; i < n; i++){
        if(best[i] == list[i].course_count) continue;
        return (best[i] < list[i].course_count);
    }
    return false;
}

void solve(int idx, int classrooms[], int n, Course courses[], int m, ListOfCourse list[], int nowtime, int remaining_time, int *maxtime, int best[]){
    if(idx == m){
        if(nowtime > *maxtime || (nowtime == *maxtime && check(best, list, n))){
            *maxtime = nowtime;
            for(int i = 0; i < n; i++) best[i] = list[i].course_count;
        }
        return;
    }

    int time = compute_time(&courses[idx]);
    for(int i = 0; i < n; i++){
        if(classrooms[i] >= courses[idx].number_of_students){
            ListOfCourse *cur_list = &list[i];
            bool overlapped = false;
            for(int j = 0; j < cur_list->course_count && !overlapped; j++)
                overlapped = is_overlap(&courses[idx], &courses[cur_list->course_list[j]]);
                
            if(!overlapped){
                cur_list->course_list[cur_list->course_count] = idx;
                cur_list->course_count++;
                if(nowtime + remaining_time >= *maxtime) solve(idx+1, classrooms, n, courses, m, list, nowtime+time, remaining_time-time, maxtime, best);
                cur_list->course_count--;
            }
        }
    }
    if(nowtime + remaining_time >= *maxtime) solve(idx+1, classrooms, n, courses, m, list, nowtime, remaining_time-time, maxtime, best);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int classrooms[8];
    Course courses[6][8];
    int coursenum[6] = {}, total_time[6] = {};;
    for(int i = 0; i < n; i++) scanf("%d", &classrooms[i]);
    for(int i = 0; i < m; i++){
        int a, b, c, d, e, f;
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        courses[f][coursenum[f]].start.hour = a;
        courses[f][coursenum[f]].start.minute = b;
        courses[f][coursenum[f]].end.hour = c;
        courses[f][coursenum[f]].end.minute = d;
        courses[f][coursenum[f]].number_of_students = e;
        total_time[f] += compute_time(&courses[f][coursenum[f]]);
        coursenum[f]++;
    }

    int best[8] = {};
    int maxtime = 0, best_sum = 0;
    for(int i = 1; i <= 5; i++){
        int maxtime_day = 0, best_day[8] = {};
        ListOfCourse list[8] = {};
        solve(0, classrooms, n, courses[i], coursenum[i], list, 0, total_time[i], &maxtime_day, best_day);
        maxtime += maxtime_day;
        for(int i = 0; i < n; i++){
            best[i] += best_day[i];
            best_sum += best_day[i];
        }
    }

    printf("%d\n%d\n", maxtime, best_sum);
    for(int i = 0; i < n; i++)
        printf("%d\n", best[i]);
}