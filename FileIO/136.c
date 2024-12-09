#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main(){
    char bin[84] = {}, html[84] = {};
    scanf("%s%s", bin, html);
    FILE *fp = fopen(html, "w");
    fprintf(fp, "<table border=\"1\">\n<tbody>\n");
    FILE *fin = fopen(bin, "rb");
    Student s;
    while(fread(&s, sizeof(Student), 1, fin) == 1)
       fprintf(fp, "<tr>\n\
<td>%s</td>\n\
<td>%d</td>\n\
<td>%s</td>\n\
<td>%f, %f, %f, %f</td>\n\
<td>%d, %d, %d</td>\n\
</tr>\n",\
        s.name, s.id, s.phone, s.grade[0], s.grade[1], s.grade[2], s.grade[3], \
        s.birth_year, s.birth_month, s.birth_day);
    
    fprintf(fp, "</tbody>\n</table>");
    fclose(fp);
    fclose(fin);
}