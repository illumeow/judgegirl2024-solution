#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int capacity;
    int course_list[8];
    int course_count;
} Classroom;

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

bool is_overlap(Course *c1, Course *c2){
    return !(c1->end.hour < c2->start.hour ||
            (c1->end.hour == c2->start.hour && c1->end.minute < c2->start.minute) ||
             c2->end.hour < c1->start.hour ||
            (c2->end.hour == c1->start.hour && c2->end.minute < c1->start.minute));
}

int compute_time(Course *c){
    return ((c->end.hour*60+c->end.minute)-(c->start.hour*60+c->start.minute)+1);
}

bool check(int best[], Classroom classrooms[], int n){
    for(int i = 0; i < n; i++){
        if(best[i] == classrooms[i].course_count) continue;
        return (best[i] < classrooms[i].course_count);
    }
    return false;
}

void solve(int idx, Classroom classrooms[], int n, Course courses[], int m, int nowtime, int remaining_time, int *maxtime, int best[]){
    if(idx == m){
        if(nowtime > *maxtime || (nowtime == *maxtime && check(best, classrooms, n))){
            *maxtime = nowtime;
            for(int i = 0; i < n; i++) best[i] = classrooms[i].course_count;
        }
        return;
    }

    int time = compute_time(&courses[idx]);
    for(int i = 0; i < n; i++){
        if(classrooms[i].capacity >= courses[idx].number_of_students){
            bool overlapped = false;
            for(int j = 0; j < classrooms[i].course_count && !overlapped; j++)
                overlapped = is_overlap(&courses[idx], &courses[classrooms[i].course_list[j]]);
                
            if(!overlapped){
                classrooms[i].course_list[classrooms[i].course_count++] = idx;
                if(nowtime + remaining_time >= *maxtime) solve(idx+1, classrooms, n, courses, m, nowtime+time, remaining_time-time, maxtime, best);
                classrooms[i].course_count--;
            }
        }
    }
    if(nowtime + remaining_time >= *maxtime) solve(idx+1, classrooms, n, courses, m, nowtime, remaining_time-time, maxtime, best);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    Classroom classrooms[8];

    Course courses[6][8];
    int coursenum[6] = {}, total_time[6] = {};;
    for(int i = 0; i < n; i++) scanf("%d", &classrooms[i].capacity);
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
        for(int j = 0; j < n; j++) classrooms[j].course_count = 0;
        int maxtime_tmp = 0, best_tmp[8] = {};
        solve(0, classrooms, n, courses[i], coursenum[i], 0, total_time[i], &maxtime_tmp, best_tmp);
        maxtime += maxtime_tmp;
        for(int i = 0; i < n; i++){
            best[i] += best_tmp[i];
            best_sum += best_tmp[i];
        }
    }

    printf("%d\n%d\n", maxtime, best_sum);
    for(int i = 0; i < n; i++)
        printf("%d\n", best[i]);
}